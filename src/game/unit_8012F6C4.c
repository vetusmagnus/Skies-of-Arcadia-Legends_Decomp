#include <dolphin/types.h>
#include "types.h"
#include "game/stat_8030B4D4.h"
#include "game/gamedata.h"
#include "game/text.h"
#include "game/save_8030B7F4.h"
#include <string.h>
#include "game/util.h"
typedef struct {
    u8 pad0[4];
    f32 f4;
    u8 pad8[4];
    f32 fc;
    u8 pad10[4];
    u32 x14;
} Fx;
typedef struct {
    u8 pad0[4];
    Fx *x4;
    s32 x8;
    u8 padc[0x14 - 0xc];
    f32 f14;
    f32 f18;
} Obj;
typedef struct {
    s8 x0;
    u8 x1;
    u8 pad2[2];
    s32 x4;
    s8 x8;
    u8 pad9[0x2c - 9];
    s32 a2c[8];         /* 0x2C */
    f32 a4c[8];         /* 0x4C */
    f32 a6c[8];         /* 0x6C */
    f32 x8c;
    f32 x90;
    s8 x94;
    u8 pad_95[3];
    f32 x98;
    f32 x9c;
    f32 xa0;
    s16 xa4;
    u8 pad_a6[2];
    s32 dst[0x8];       /* 0xA8 */
    s32 src[0x8];
} Sys_8012FF48;
typedef struct {
    u8 pad[0x24];
    Sys_8012FF48 *x24;
    Obj **x28;          /* sprites */
} Holder_8012FF48;
typedef struct {
    s8 x0;
    s8 x1;
    s8 x2;
    s8 x3;
    s8 v0;
    u8 pad_5[0x3];
    s32 v1;
    s32 v2;
    s32 v3;
    s32 v4;
    char* msg;
    s32 kind[3];
} Sys_8013360C;
typedef struct {
    u8 pad[0x24];
    Sys_8013360C *x24;
    Obj **x28;
} Holder_8013360C;
extern Holder_8012FF48 *lbl_80346F40;
extern Holder_8013360C *lbl_80346F58;
extern void* lbl_80346F50;
extern void* lbl_803475A8;
s32 fn_80136A28(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
s32 fn_801365D8(s32 a, s32 b, s32 c, s32 d, s32 e);
void *fn_802268E8(void *a, void *);
void *fn_801E1C7C(u32 n);
typedef struct {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
} Task_801303D0;
extern void *lbl_80305FA0[2][4];
extern void fn_80131254(void);
void fn_801303D0(Task_801303D0 *t);
struct Mgr;
void fn_80131734(struct Mgr *s);
typedef struct {
    u8 pad0[0x20];
    s32 x20;
} Inner_80132458;
typedef struct {
    u8 pad0[4];
    Inner_80132458 *x4;
} Sys_80132458;
typedef struct {
    s8 b0;
    u8 pad1;
    u8 b2;
    u8 b3;
    s8 b4;
    u8 pad5[3];
    f32 f8;
    s32 wc;
    s32 w10;
    u8 pad14[4];
    s32 w18;
    s32 w1c;
    u8 pad20[8];
    s32 w28;
    s32 w2c;
    u8 pad30[4];
    s32 w34;
    s32 w38;
    s32 w3c;
    u8 b40;
    u8 pad41[3];
    s32 w44;
    s32 w48;
    u8 pad4c[4];
    s32 w50;
    s32 w54;
    u8 pad58[8];
    s32 w60;
    s32 w64;
    u8 pad68[4];
    s32 w6c;
    s32 w70;
} Data_80132458;
typedef struct {
    u8 pad0[0x24];
    Data_80132458 *x24;
    s32 *x28;
} Obj_80132458;
extern void *lbl_80346F00;
extern Sys_80132458 *lbl_80346EF8;
extern void FieldPartyStatusDraw(void);
void fn_80132458(Task_801303D0 *t);
void fn_801331AC(Task_801303D0 *t);
typedef struct Fn80130040Inner {
    u8 pad0[0xa8];
    s32 dst[8];
    s32 src[8];
} Fn80130040Inner;
typedef struct Fn80130040Mgr {
    u8 pad0[0x24];
    Fn80130040Inner *inner;
} Fn80130040Mgr;
extern void fn_80130C6C(void);
extern void fn_80130D30(void);
extern s32 fn_801305E4(void);
typedef struct Fn80130264Inner {
    u8 pad0[0xc];
    s32 dst[8];
} Fn80130264Inner;
typedef struct Fn80130264Mgr {
    u8 pad0[0x24];
    Fn80130264Inner *inner;
} Fn80130264Mgr;
extern void fn_80130B64(void);
typedef struct Fn80130C6CInner {
    u8 pad0[0xc];
    s32 in[8];
    s32 out[8];
} Fn80130C6CInner;
typedef struct Fn80130C6CMgr {
    u8 pad0[0x24];
    Fn80130C6CInner *inner;
} Fn80130C6CMgr;
typedef struct Fn80131500Holder {
    s32 a;
    s32 b;
} Fn80131500Holder;
typedef struct Fn80131500Inner {
    u8 pad0[0xae];
    u8 f_ae;
} Fn80131500Inner;
typedef struct Fn80131500Mgr {
    u8 pad0[0x24];
    Fn80131500Inner *inner;
    Fn80131500Holder *holder;
} Fn80131500Mgr;
extern void *lbl_80346F04;
extern void *lbl_80346F08;
extern void* fn_801D68C4(void* a, u32 n);
typedef struct {
    Obj *obj;
    f32 f4;
    f32 f8;
    s32 c;
    s32 d;
    f32 e;
    f32 g;
} Args;
extern void* lbl_80346EFC;
extern void fn_8012A954(Args *a);
extern void fn_8012A9A8(Args *a);
extern s32 lbl_80347620;
/* fn_80133BE0's number record: a value drawn at (x, y). */
typedef struct {
    s16 x;
    s16 y;
    s32 v;
    f32 z;
    f32 scale;
    u32 col;
} NumDraw;
extern void fn_80133BE0(NumDraw *n, s32 digits);
/* A party member's battle-menu view, filled from the save record by fn_80135290. */
typedef struct {
    char name[0xb];
    s8 id;
    u8 c;          /* SaveChar.xb */
    u8 d;          /* SaveChar.mpMax */
    u8 e;          /* SaveChar.mp */
    u8 stat[8];
    u8 pad17;
    s16 s18;
    s16 s1a;
} Item;
/* A party slot (0x22): the name, then the id and stats copied from the character or cannon data. */
typedef struct {
    char name[0x11];
    u8 pad11;
    s16 id;     /* 0x12 */
    s8 b14;
    s8 b15;
    s16 s16;
    s16 s18;
    s16 s1a;
    s16 s1c;
    s8 b1e;
    s8 b1f;
    s8 b20;
    u8 pad21;
} Member;
typedef struct {
    char name[0x11];
    s8 b11;
    u8 pad12[2];
    s32 x14;
    s32 x18;
    s16 h1c, h1e, h20, h22, h24, h26;
    s16 h28[6];
    s16 h34[6];
    s16 h40, h42, h44, h46, h48, h4a, h4c, h4e, h50, h52, h54, h56;
    u32 flags; /* 0x58 */
    s32 x5c;
    Member mem[5];
} Party;
extern Party lbl_80305FC0[];
/* lbl_803063F0: the battle menu's system record (fn_80135598). */
typedef struct {
    s8 order[4];
    u8 pad4[0x1c6 - 0x4];
    Item items[4];
    u8 pad236[2];
    Party party; /* 0x238 */
} Big;
extern Big lbl_803063F0;
extern void fn_80134754(Big *b);
void fn_8013506C(Big *b);
void fn_80134E7C(Party *party);
void fn_80135290(Item *v, s32 slot, s32 add);
s32 fn_8021A1C4(s8 *out);
s32 fn_8021A83C(Save1568 *ship, void *crew);
extern Big *fn_80135598(void);
/* fn_80131658's record: grid[x][y][a] = b, sel[x][y] = c. */
typedef struct {
    s8 x;
    s8 y;
    s8 a;
    s8 b;
    s8 c;
} Cell;
void fn_80131658(Cell *cell);
void fn_8013160C(s8 a, s8 b, u8 v);
typedef struct {
    u8 pad0[4];
    u32 x4;
    u8 pad8[0x14 - 8];
    u32 x14;
} Spr;
typedef struct {
    u8 pad0[4];
    Spr* spr;
} Holder0C;
typedef struct {
    u8 pad0[2];
    s8 kind;
} Sys;
typedef struct {
    u8 pad[0x24];
    Sys* x24;
    void** x28;
} Holder;
/* lbl_80346F38's work: eight label slots (fn_8012F958 draws them). */
typedef struct {
    s8 b0;
    u8 b1;
    s8 b2[8];      /* 0x02: 0 = slot shown */
    s8 ba[8];      /* 0x0A: icon kind, -1 = none */
    u8 pad12[2];
    s32 w14[8];    /* 0x14: count drawn when the kind has no icon */
    char *str[8];  /* 0x34 */
} Data_8012F75C;
typedef struct {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    Data_8012F75C *x24;
    Obj **x28;
} Obj_8012F75C;
extern Obj_8012F75C *lbl_80346F38;
extern void *fn_802268E8(void *a, void *);
extern void *fn_801E1C7C(u32 n);
void fn_8012F958(Obj_8012F75C *o);
void fn_8012FB10(s8 slot);
extern void fn_8012FE2C(s8 i);
/* lbl_80308E90: 8 records of 5 bytes, indexed by i + 4 for i in [-4, 4);
 * -1 marks an empty field (fn_8013D400's unit tests +0x14 == -1). */
typedef struct Rec5 {
    s8 a[5];
} Rec5;
extern Rec5 lbl_80308E90[8];
typedef struct Inner {
    s8 x0;              /* 0 while idle (fn_80131734) */
    u8 pad1;
    s8 x2;
    s8 x3;
    f32 f4;
    s8 x8;
    s8 grid[8][4][4];
    s8 sel[8][4];
    s8 slot[4];         /* 0xA9 */
    s8 psel;            /* 0xAD */
    s8 xae;
} Inner;

typedef struct Mgr {
    u8 pad0[0x18];
    u8 flags;           /* 0x18 */
    u8 state;           /* 0x19 */
    u8 pad1a[0x24 - 0x1a];
    Inner *inner;
    Obj **x28;          /* 0x28: two sprites (fn_80131734) */
} Mgr;
extern Mgr *lbl_80346F48;
typedef struct Pad_8013A794 {
    u8 pad0[0x8];
    u32 x8; /* buttons held */
} Pad_8013A794;
typedef struct PadInfo_8013A794 {
    Pad_8013A794 *pad;
    u8 pad4[0x18 - 4];
} PadInfo_8013A794;
extern PadInfo_8013A794 lbl_80311A60;
s32 fn_8013A538(s32 a, s32 b, s32 cur, s32 step, s32 d);
s32 fn_8013A794(s32 a, s32 b, s32 cur, s32 d);
extern void SePlay(s32 id, s32 a, s32 b);
/* A battle-menu step (fn_80138114, reset by fn_801380D4 / fn_801383DC). */
typedef struct {
    u8 pad0[1];
    s8 state;
    s8 b2;         /* row */
    u8 pad3;
    s8 b4;
    u8 pad5;
    s8 b6;         /* page */
    s8 b7;         /* cursor on the page */
    s8 b8;         /* chosen column */
    s8 b9;
    u8 ba;
    u8 padb[5];
    s8 x10[6];     /* crew ids on the page */
    s16 x16;       /* money */
    s16 x18[4];    /* cost paid per row */
} MenuStep;
extern s32 fn_801358A0(s32 pos, s32 y, s32 k, s32 x4, s32 n);
extern void fn_8013FB48(s32 a, s32 b);
extern void fn_8012F478(s32 a);
typedef struct {
    u8 pad0[0x14];
    f32 x14;
} H;
typedef struct {
    H *h;
    f32 a;
    f32 b;
    s32 c;
    s32 d;
    f32 e;
    f32 f;
} S;
typedef struct {
    u8 pad0[1];
    u8 x1;
    u8 pad2[0xa2];
    s16 xa4;
} Q;
typedef struct {
    u8 pad0[0x24];
    Q *x24;
    H **x28;
} P;
extern void fn_80130FB4(void);
typedef struct {
    u8 pad0[0x19];
    u8 state;
    u8 pad1a[2];
    u8 x1c;
    u8 pad1d[7];
    void *x24;
    void *x28;
} T;
extern s32 fn_80130318(void);
extern s32 fn_8012FF08(void);
extern void fn_8014093C(void *a, s32 b, s32 *c, s32 *d);
extern void fn_801300E0(s32 *a);
extern void fn_80130264(s32 *a);
typedef struct {
    u8 pad0[0xc];
    s32 kind[8];   /* 0x0C */
    u32 color[8];  /* 0x2C */
    u8 pad4c[0x94 - 0x4c];
    s8 mode;       /* 0x94 */
} Sys_80130B64;
typedef struct {
    u8 pad[0x24];
    Sys_80130B64* x24;
} Holder_80130B64;
void MemCopy(void* dst, const void* src, s32 size);
typedef struct {
    u8 pad0[4];
    s8 idx;
} Req;
extern char *lbl_802F7050[];
void fn_8012F458(s8 flag);
void fn_8012F468(char *str);
extern s32 fn_80136C14(s8 *src, s32 i, s32 a);
extern void fn_8012E4FC(void **p);
extern void fn_8012E498(s8 *p);
extern void fn_8012E434(s8 *p);
extern void fn_8012E424(s8 v);
extern void fn_8012E570(s8 v);

void fn_8012F6C4(s8 idx, s32 val) {
    lbl_80346F38->x24->w14[idx] = val;
}

void fn_8012F6E0(s8 idx, s8 val) {
    lbl_80346F38->x24->ba[idx] = val;
}

void fn_8012F6F8(s8 idx, s8 val) {
    lbl_80346F38->x24->b2[idx] = val;
}

void fn_8012F710(s8 idx, char *str) {
    lbl_80346F38->x24->str[idx] = str;
}

void fn_8012F72C(s8 v) {
    if (lbl_80346F38 == 0) return;
    lbl_80346F38->x24->b0 = v;
}

void fn_8012F744(void) {
    Obj_8012F75C *p = lbl_80346F38;
    if (p == NULL) {
        return;
    }
    p->state = 2;
}

static inline void DrawLabels(void)
{
    f32 z;
    s32 i;
    s8 slot;
    s16 x;
    s16 y;
    if (lbl_80346F38->x24->b0 == 0) {
        for (i = 0; i < 8; i++) {
            if (lbl_80346F38->x24->b2[i] == 0) {
                fn_8012FE2C(i);
                if (lbl_80346F38->x24->str[i] != 0) {
                    slot = i;
                    if (slot >= 0 && slot < 4) {
                        x = 8;
                        y = 0x1A8 - slot * 32;
                    } else {
                        x = 0x1B1;
                        y = 0x1A8 - (slot - 4) * 32;
                    }
                    z = TextGetZ();
                    TextSetZ(-1.29899991f);
                    TextPrint(x, y, lbl_80346F38->x24->str[slot]);
                    TextSetZ(z);
                }
                if (lbl_80346F38->x24->ba[i] != -1)
                    fn_8012FB10(i);
            }
        }
    }
}

void fn_8012F958(Obj_8012F75C *o)
{
    switch (o->state) {
    case 0xFE:
    case 0:
        lbl_80346F38->x28 = fn_801E1C7C(4);
        lbl_80346F38->x28[0] = fn_801D68C4(lbl_80346EFC, 0x23);
        o->state = 1;
        break;
    case 1:
        DrawLabels();
        break;
    case 2:
        o->state = 0xFF;
        break;
    case 0xFF:
        o->flags |= 0x40;
        break;
    }
}

void fn_8012FB10(s8 slot) {
    Obj *hh;
    Args ws;
    NumDraw t;
    s16 off;
    s16 x;
    s32 i;
    s16 y;
    s32 v;
    if (slot >= 0 && slot < 4) {
        x = 0x90;
        y = 0x1a3 - (slot << 5);
    } else {
        x = 0x23e;
        y = 0x1a3 - ((slot - 4) << 5);
    }
    hh = fn_801D68C4(lbl_80346EFC, 0x24);
    ws.obj = hh;
    hh->f14 = x;
    ws.obj->f18 = y;
    ws.f4 = -1.098f;
    ws.f8 = 1.0f;
    ws.c = 0;
    ws.d = 0;
    ws.e = 1.0f;
    ws.g = 1.0f;
    fn_8012A954(&ws);
    ws.obj = NULL;
    i = slot;
    switch (lbl_80346F38->x24->ba[i]) {
    case 0:
        ws.obj = fn_801D68C4(lbl_80346EFC, 0x25);
        break;
    case 1:
        ws.obj = fn_801D68C4(lbl_80346EFC, 0x26);
        break;
    case 2:
        ws.obj = NULL;
        t.col = 0xffe62020;
        break;
    case 3:
        ws.obj = NULL;
        t.col = 0xff20fa20;
        break;
    }
    if (ws.obj != NULL) {
        if (slot >= 0 && slot < 4) {
            x = 0xa1;
            y = 0x1a7 - (slot << 5);
        } else {
            x = 0x24f;
            y = 0x1a7 - ((slot - 4) << 5);
        }
        ws.obj->f14 = x;
        ws.obj->f18 = y;
        ws.f4 = -1.097f;
        ws.f8 = 1.0f;
        ws.c = 0;
        ws.d = 0;
        ws.e = 1.0f;
        ws.g = 1.0f;
        fn_8012A954(&ws);
    } else {
        v = lbl_80346F38->x24->w14[i];
        if (v < 10) {
            off = 0x16;
        } else if (v < 100) {
            off = 0x1c;
        } else if (v < 1000) {
            off = 0x21;
        } else if (v < 10000) {
            off = 0x26;
        } else {
            off = 0x2c;
        }
        if (slot >= 0 && slot < 4) {
            x = 0x96;
            y = 0x1a7 - (slot << 5);
        } else {
            x = 0x244;
            y = 0x1a7 - ((slot - 4) << 5);
        }
        t.y = y;
        t.x = x + off;
        t.v = lbl_80346F38->x24->w14[i];
        t.z = -1.097f;
        t.scale = 1.0f;
        fn_80133BE0(&t, 0xb);
    }
}

void fn_8012FE2C(s8 n) {
    Args a;
    s16 x;
    s16 y;
    if (n >= 0 && n < 4) {
        x = 3;
        y = 0x1a5 - n * 32;
    } else {
        x = 0x1ac;
        y = 0x1a5 - (n - 4) * 32;
    }
    a.obj = lbl_80346F38->x28[0];
    a.obj->f14 = (f32)x;
    a.obj->f18 = (f32)y;
    a.f4 = -1.3f;
    a.f8 = 1.0f;
    a.c = 0;
    a.d = 0;
    a.e = 1.0f;
    a.g = 1.0f;
    fn_8012A954(&a);
}

s32 fn_8012FF08(void) {
    u8 *o = *(u8 **)((u8 *)lbl_80346F40 + 0x24);
    u8 c = o[1];
    s32 t = (s8)c;
    if (t == 0xd || (u8)(c - 0xe) <= 1 || t == 0x10) {
        return 1;
    }
    return 0;
}

void fn_80130304(s8 v) {
    u8* p = *(u8**)((u8*)lbl_80346F40 + 0x24);
    *(s16*)(p + 0xa4) = v;
}

s32 fn_80130318(void) {
    s8 v = (*(u8**)((u8*)lbl_80346F40 + 0x24))[1];
    return v != 0;
}

void fn_80130338(u8 v) {
    if (lbl_80346F40 == 0) return;
    (*(u8**)((u8*)lbl_80346F40 + 0x24))[1] = v;
}

void fn_80130350(u8 v) {
    if (lbl_80346F40 == 0) return;
    (*(u8**)((u8*)lbl_80346F40 + 0x24))[0] = v;
}

void fn_80130368(void) {
    ((u8*)lbl_80346F40)[0x19] = 2;
}

void fn_80131254(void) {
    s32 i;
    s8 v = lbl_8030B4D4.x2d4;
    lbl_80346F40->x24->x94 = v;
    if (v == 3) {
        lbl_80346F40->x28[0] = fn_801D68C4(lbl_80346F04, 0x64);
        lbl_80346F40->x28[4] = fn_801D68C4(lbl_80346F04, 0x68);
        lbl_80346F40->x28[6] = fn_801D68C4(lbl_80346F04, 0x84);
        lbl_80346F40->x28[1] = fn_801D68C4(lbl_80346F04, 0x83);
    } else {
        lbl_80346F40->x28[0] = fn_801D68C4(lbl_80346F08, 0x64);
        lbl_80346F40->x28[4] = fn_801D68C4(lbl_80346F08, 0x68);
        lbl_80346F40->x28[6] = fn_801D68C4(lbl_80346F08, 0x84);
        lbl_80346F40->x28[1] = fn_801D68C4(lbl_80346F08, 0x83);
    }
    for (i = 0; i < 8; i++) {
        lbl_80346F40->x24->a2c[i] = 0xff40dc40;
        lbl_80346F40->x24->a4c[i] = 1.0f;
        lbl_80346F40->x24->a6c[i] = 1.0f;
    }
    lbl_80346F40->x24->x8 = -1;
    lbl_80346F40->x24->x8c = 250.0f;
    lbl_80346F40->x24->x90 = 77.0f;
    lbl_80346F40->x24->xa4 = 0;
    lbl_80346F40->x24->x1 = 0;
    lbl_80346F40->x24->x4 = 0;
    lbl_80346F40->x24->x98 = 0.0f;
    lbl_80346F40->x24->x9c = 0.0f;
    lbl_80346F40->x24->xa0 = 0.0f;
}

void fn_80131598(u8 v) {
    u8* p = *(u8**)((u8*)lbl_80346F48 + 0x24);
    p[0xad] = v;
}

void fn_801315A8(u8* src) {
    *(u8*)(*(u8**)((u8*)lbl_80346F48 + 0x24) + 0xa9) = src[0];
    *(u8*)(*(u8**)((u8*)lbl_80346F48 + 0x24) + 0xaa) = src[1];
    *(u8*)(*(u8**)((u8*)lbl_80346F48 + 0x24) + 0xab) = src[2];
    *(u8*)(*(u8**)((u8*)lbl_80346F48 + 0x24) + 0xac) = src[3];
}

void fn_801315EC(u8 v) { (*(u8**)((u8*)lbl_80346F48 + 0x24))[3] = v; }

void fn_801315FC(u8 v) { (*(u8**)((u8*)lbl_80346F48 + 0x24))[2] = v; }

void fn_8013160C(s8 a, s8 b, u8 v) {
    u8* p = *(u8**)((u8*)lbl_80346F48 + 0x24);
    u8* q = p + (s32)a * 4;
    q = q + (s32)b;
    q[0x89] = v;
}

void fn_80131630(s8 a, s8 b, u8 v) {
    u8* arr = *(u8**)((u8*)lbl_80346F48 + 0x24);
    arr[(s32)a * 16 + (s32)b * 4 + 0x9] = v;
}

void fn_801316B4(u8 v) {
    if (lbl_80346F48 == 0) return;
    (*(u8**)((u8*)lbl_80346F48 + 0x24))[0] = v;
}

void fn_801316CC(void) {
    ((u8*)lbl_80346F48)[0x19] = 2;
}

extern void fn_801321DC(void);
extern void fn_80132128(void);
extern void fn_80131A04(void);
extern void fn_80131820(void);

void fn_80131734(Mgr *s) {
    switch (s->state) {
    case 0:
    case 0xfe:
        lbl_80346F48->x28 = fn_801E1C7C(8);
        lbl_80346F48->x28[0] = fn_801D68C4(lbl_80346F04, 0x52);
        lbl_80346F48->x28[1] = fn_801D68C4(lbl_80346F04, 0x53);
        fn_801321DC();
        s->state = 1;
        break;
    case 1:
        if (lbl_80346F48->inner->x0 == 0) {
            fn_80132128();
            fn_80131A04();
            fn_80131820();
        }
        break;
    case 2:
        s->state = 0xff;
        break;
    case 0xff:
        s->flags |= 0x40;
        break;
    }
}

void fn_80131A04(void) {
    Args r;
    Obj *o;
    f32 fx, fy;
    s8 i, j, k, sel;

    fx = 0.0001f * (lbl_80346F48->x28[0]->x8 + lbl_80346F48->x28[1]->x8) + -1.2f;
    lbl_80346F48->inner->f4 = lbl_80346F48->inner->f4 + (0.54f * lbl_80346F48->inner->x8) / 15.0f;
    if (lbl_80346F48->inner->f4 < 0.16f || 0.7f < lbl_80346F48->inner->f4) {
        lbl_80346F48->inner->x8 *= -1;
        lbl_80346F48->inner->f4 = lbl_80346F48->inner->f4 + (0.54f * lbl_80346F48->inner->x8) / 15.0f;
    }
    fy = 0.0004f + fx;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 4; j++) {
            sel = lbl_80346F48->inner->sel[i][j];
            for (k = 0; k < 4; k++) {
                s8 v = lbl_80346F48->inner->grid[i][j][k];
                if (v == -1) continue;
                switch (v) {
            case 0:
                o = fn_801D68C4(lbl_80346F04, 0x54);
                break;
            case 1:
                o = fn_801D68C4(lbl_80346F04, 0x55);
                break;
            case 2:
                o = fn_801D68C4(lbl_80346F04, 0x56);
                break;
            case 3:
                o = fn_801D68C4(lbl_80346F04, 0x57);
                break;
            case 4:
                o = fn_801D68C4(lbl_80346F04, 0x58);
                break;
            case 5:
                o = fn_801D68C4(lbl_80346F04, 0x59);
                break;
            case 6:
                o = fn_801D68C4(lbl_80346F04, 0x5b);
                break;
            case 7:
                o = fn_801D68C4(lbl_80346F04, 0x5a);
                break;
            case 8:
                o = fn_801D68C4(lbl_80346F04, 0x5c);
                break;
            case 9:
                o = fn_801D68C4(lbl_80346F04, 0x5d);
                break;
            case 10:
                o = fn_801D68C4(lbl_80346F04, 0x5e);
                break;
            case 11:
                o = fn_801D68C4(lbl_80346F04, 0x5f);
                break;
            case 12:
                o = fn_801D68C4(lbl_80346F04, 0x60);
                break;
            case 13:
                o = fn_801D68C4(lbl_80346F04, 0x61);
                break;
            case 14:
                o = fn_801D68C4(lbl_80346F04, 0x62);
                break;
            case 15:
                o = fn_801D68C4(lbl_80346F04, 0x71);
                break;
            case 16:
                o = fn_801D68C4(lbl_80346F04, 0x63);
                break;
            case 17:
                o = fn_801D68C4(lbl_80346F04, 0x78);
                break;
            case 18:
                o = fn_801D68C4(lbl_80346F04, 0x79);
                break;
            case 19:
                o = fn_801D68C4(lbl_80346F04, 0x7f);
                break;
            case 20:
                o = fn_801D68C4(lbl_80346F04, 0x80);
                break;
            case 21:
                o = fn_801D68C4(lbl_80346F04, 0x81);
                break;
            case 22:
                o = fn_801D68C4(lbl_80346F04, 0x89);
                break;
            case 23:
                o = fn_801D68C4(lbl_80346F04, 0x8a);
                break;
            case 24:
                o = fn_801D68C4(lbl_80346F04, 0x8b);
                break;
            case 25:
                o = fn_801D68C4(lbl_80346F04, 0x88);
                break;
                default:
                    o = fn_801D68C4(lbl_80346F04, 0x54);
                    break;
                }
                o->f14 = 0xfa + i * 0x19;
                o->f18 = 0x6d + j * 0x19;
                r.obj = o;
                r.f4 = 0.0001f * k + fx;
                r.f8 = 1.0f;
                r.c = 0;
                r.d = 0;
                r.e = 1.0f;
                r.g = 1.0f;
                if (o == fn_801D68C4(lbl_80346F04, 0x63)) lbl_80347620 = 1;
                fn_8012A9A8(&r);
                lbl_80347620 = 0;
            }
            if (sel != -1) {
                u32 col;
                f32 w;
                o = fn_801D68C4(lbl_80346F04, 0x6c);
                switch (sel) {
                case 1:
                    col = 0x28808040;
                    w = 1.0f;
                    break;
                case 2:
                    col = 0xb4404080;
                    w = 1.0f;
                    break;
                case 0:
                    col = 0xb4808040;
                    w = lbl_80346F48->inner->f4;
                    break;
                default:
                    col = 2;
                    w = 1.0f;
                    break;
                }
                o->f14 = 0xfa + i * 0x19;
                o->f18 = 0x6d + j * 0x19;
                o->x4->x14 = col;
                r.obj = o;
                r.f4 = fy;
                r.f8 = 1.0f;
                r.c = 0;
                r.d = 1;
                r.e = 1.0f;
                r.g = w;
                fn_8012A9A8(&r);
            }
        }
    }
    if (lbl_80346F48->inner->x2 == 0) {
        Obj *o2;
        f32 fz;
        if (lbl_80346F48->inner->xae == 3) {
            o2 = fn_801D68C4(lbl_80346F04, 0x6f);
        } else {
            o2 = fn_801D68C4(lbl_80346F08, 0x6f);
        }
        o2->f14 = 235.0f;
        o2->f18 = lbl_80346F48->inner->x3 * 0x19 + 0x72;
        r.obj = o2;
        r.f4 = -1.1f;
        r.f8 = 1.0f;
        r.c = 0;
        r.d = 0;
        r.e = 1.0f;
        r.g = 1.0f;
        fn_8012A9A8(&r);
        fz = lbl_80346F48->inner->f4;
        if (lbl_80346F48->inner->xae == 3) {
            o2 = fn_801D68C4(lbl_80346F04, 0x70);
        } else {
            o2 = fn_801D68C4(lbl_80346F08, 0x70);
        }
        o2->f14 = 230.0f;
        o2->f18 = lbl_80346F48->inner->x3 * 0x19 + 0x6d;
        r.obj = o2;
        r.f4 = -1.0998f;
        r.f8 = 1.0f;
        r.c = 0;
        r.d = 1;
        r.e = 1.0f;
        r.g = fz;
        fn_8012A9A8(&r);
    }
}

void fn_80131820(void) {
    s32 v;
    s32 y;
    s8 i;
    f32 x;
    f32 one;
    Args r;
    Obj *spr;

    x = 0.0001f * (lbl_80346F48->x28[0]->x8 + lbl_80346F48->x28[1]->x8) + -1.2f;
    x = x + 0.0002f;
    for (i = 0, y = 0x6d; i < 4; i++) {
        v = lbl_80346F48->inner->slot[i];
        if (v == -1) {
            goto next;
        }
        switch (v) {
        case 0:
            spr = fn_801D68C4(lbl_80346F04, 0x72);
            break;
        case 1:
            spr = fn_801D68C4(lbl_80346F04, 0x73);
            break;
        case 2:
            spr = fn_801D68C4(lbl_80346F04, 0x74);
            break;
        case 3:
            spr = fn_801D68C4(lbl_80346F04, 0x75);
            break;
        case 4:
            spr = fn_801D68C4(lbl_80346F04, 0x76);
            break;
        case 5:
            spr = fn_801D68C4(lbl_80346F04, 0x77);
            break;
        default:
            spr = fn_801D68C4(lbl_80346F04, 0x72);
            break;
        }
        spr->f14 = 216.0f;
        spr->f18 = (f32)y;
        one = (i == lbl_80346F48->inner->psel) ? 1.0f : 0.5f;
        r.obj = spr;
        r.f4 = x;
        r.f8 = 1.0f;
        r.c = 0;
        r.d = 0;
        r.e = one;
        r.g = 1.0f;
        fn_8012A9A8(&r);
    next:
        y += 0x19;
    }
}

void fn_801323F0(void) {
    ((u8*)lbl_80346F50)[0x19] = 2;
}

typedef struct {
    u8 c[4];
} Colour4;
extern void fn_801D65B4(u32 colour, Colour4 *out, f32 a, f32 b);

void fn_80133900(void) {
    Args a;
    Colour4 c;
    f32 ratio;
    f32 t;
    s32 i;

    for (i = 0; i < 11; i++) {
        if (i >= 0 && i < 7) {
            a.obj = lbl_80346F58->x28[i];
            a.f4 = 0.0001f * (f32)i + -1.3f;
            a.f8 = 1.0f;
            a.c = 0;
            a.d = 0;
            a.e = 1.0f;
            a.g = 1.0f;
        } else if (i == 10) {
            ratio = (f32)lbl_80346F58->x24->v3 / (f32)lbl_80346F58->x24->v4;
            a.obj = lbl_80346F58->x28[i];
            a.obj->x4->fc = a.obj->x4->f4 + 80.0f * ratio;
            fn_801D65B4(a.obj->x4->x14, &c, 1.0f, 1.0f);
            if (ratio > 0.5f) {
                t = 1.0f - ratio;
                c.c[0] = 0xfa;
                c.c[3] = 0x20;
                c.c[1] = (s32)(376.0f * t) + 0x20;
                c.c[2] = 0xfa - (s32)(100.0f * t);
            } else {
                c.c[0] = 0xfa;
                c.c[3] = 0x20;
                c.c[1] = (s32)(30.0f * (1.0f - 2.0f * ratio)) + 0xdc;
                c.c[2] = 0xc8 - (s32)(168.0f * (1.0f - 2.0f * ratio));
            }
            a.obj->x4->x14 = (c.c[0] << 24) + (c.c[1] << 16) + (c.c[2] << 8) + c.c[3];
            a.f4 = 0.0001f * (f32)i + -1.3f;
            a.f8 = 1.0f;
            a.c = 0;
            a.d = 1;
            a.e = 1.0f;
            a.g = 1.0f;
        } else {
            a.obj = lbl_80346F58->x28[i];
            a.f4 = 0.0001f * (f32)i + -1.3f;
            a.f8 = 1.0f;
            a.c = 0;
            a.d = 0;
            a.e = 1.0f;
            a.g = 1.0f;
        }
        fn_8012A954(&a);
    }
}

void fn_80133030(s32* src) {
    if (lbl_80346F58 == 0) return;
    *(s32*)(*(u8**)((u8*)lbl_80346F58 + 0x24) + 0x1c) = src[0];
    *(s32*)(*(u8**)((u8*)lbl_80346F58 + 0x24) + 0x20) = src[1];
    *(s32*)(*(u8**)((u8*)lbl_80346F58 + 0x24) + 0x24) = src[2];
}

void fn_8013306C(void* v) {
    u8* p = (u8*)lbl_80346F58;
    if (p == NULL) {
        return;
    }
    *(void**)(*(u8**)((u8*)p + 0x24) + 0x18) = v;
}

void fn_80133084(void* v) {
    u8* p = (u8*)lbl_80346F58;
    if (p == NULL) {
        return;
    }
    *(void**)(*(u8**)((u8*)p + 0x24) + 0x14) = v;
}

void fn_8013309C(void* v) {
    u8* p = (u8*)lbl_80346F58;
    if (p == NULL) {
        return;
    }
    *(void**)(*(u8**)((u8*)p + 0x24) + 0x10) = v;
}

void fn_801330B4(void* v) {
    u8* p = (u8*)lbl_80346F58;
    if (p == NULL) {
        return;
    }
    *(void**)(*(u8**)((u8*)p + 0x24) + 0xc) = v;
}

void fn_801330CC(void* v) {
    u8* p = (u8*)lbl_80346F58;
    if (p == NULL) {
        return;
    }
    *(void**)(*(u8**)((u8*)p + 0x24) + 0x8) = v;
}

void fn_801330E4(u8 v) {
    u8* p = (u8*)lbl_80346F58;
    if (p == NULL) {
        return;
    }
    *(u8*)(*(u8**)((u8*)p + 0x24) + 0x4) = v;
}

void fn_801330FC(u8 v) {
    u8* p = (u8*)lbl_80346F58;
    if (p == NULL) {
        return;
    }
    *(u8*)(*(u8**)((u8*)p + 0x24) + 0x2) = v;
}

void fn_80133114(u8 v) {
    if (lbl_80346F58 == 0) return;
    (*(u8**)((u8*)lbl_80346F58 + 0x24))[1] = v;
}

void fn_8013312C(u8 v) {
    if (lbl_80346F58 == 0) return;
    (*(u8**)((u8*)lbl_80346F58 + 0x24))[0] = v;
}

void fn_80133144(void) {
    ((u8*)lbl_80346F58)[0x19] = 2;
}

extern s32 fn_8021ADA0(Save1568* p, void* q);
extern s16 fn_8021ACE0(Save1568* p, void* q);
extern s16 fn_8021AC20(Save1568* p, void* q);
extern s16 fn_8021AB60(Save1568* p, void* q);
extern s32 fn_8021AA48(Save1568* p, void* q, s32 k);
extern s16 fn_8021A880(Save1568* p, void* q);
extern s32 fn_8021A0BC(s32 v);
void fn_80134D1C(Member* out, Save1568* t, void* b, s32 idx);

static inline void PartyMembers(Member* ent, Save1568* p, s8* buf) {
    s32 i;
    if (ent != 0 && p != 0 && buf != 0) {
        for (i = 0; i < 5; i++) {
            fn_80134D1C(&ent[i], p, buf, i);
        }
    }
}

static inline void PartyMask(u32* m, s8* buf) {
    s32 j;
    if (m != 0 && buf != 0) {
        *m = 0;
        for (j = 0; j < 0x16; j++) {
            s32 v = buf[j];
            if (fn_8021A0BC(v) != 0) {
                *m |= 1 << v;
            }
        }
    }
}

void fn_80134E7C(Party* dst) {
    s8 buf[0x16];
    s32 i;
    Save1568* p;

    if (dst == 0) {
        return;
    }
    p = &lbl_8030B7F4.x1568;
    if (p->b1568 < 0) {
        p = 0;
    }
    if (p == 0) {
        return;
    }
    fn_8021A1C4(buf);
    MemCopy(dst, p->name, 0x11);
    dst->b11 = p->b1568;
    dst->x14 = fn_8021ADA0(p, buf);
    dst->x18 = p->x157c;
    dst->h1c = fn_8021ACE0(p, buf);
    dst->h1e = 0;
    dst->h20 = fn_8021AC20(p, buf);
    dst->h22 = 0;
    dst->h24 = fn_8021AB60(p, buf);
    dst->h26 = 0;
    for (i = 0; i < 6; i++) {
        dst->h28[i] = fn_8021AA48(p, buf, i);
        dst->h34[i] = 0;
    }
    dst->h40 = fn_8021A880(p, buf);
    dst->h42 = 0;
    dst->h44 = fn_8021A83C(p, buf);
    dst->h46 = 0;
    dst->h48 = 0;
    dst->h4a = 0;
    dst->h4c = 0;
    dst->h4e = 0;
    dst->h50 = 0;
    dst->h52 = 0;
    dst->h54 = 0;
    dst->h56 = 0;
    PartyMembers(dst->mem, p, buf);
    PartyMask(&dst->flags, buf);
    dst->x5c = 0;
}

void* fn_8013558C(void) {
    return lbl_80305FC0;
}

extern void fn_80140460(void);

/* Declared int (fn_801380E4 returns its value) though nothing is returned, as in the original. */
s32 fn_80136A28(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    s32 n = 0;
    Big *p = fn_80135598();
    if (p != 0) {
        for (n = 0; n < 4; n++) {
            if (p->order[n] < 0) break;
        }
    }
    if (fn_801358A0(b, a, c, d, n)) {
        lbl_80308E90[b + 4].a[0] = c;
        lbl_80308E90[b + 4].a[1] = a;
        lbl_80308E90[b + 4].a[2] = d;
        lbl_80308E90[b + 4].a[3] = e;
        lbl_80308E90[b + 4].a[4] = f;
    }
    fn_8013160C(b, a, 2);
    fn_80140460();
}

s32 fn_801380D4(MenuStep *p) {
    p->state = 0;
    return 2;
}

s32 fn_801380E4(s32 a, s32 b) {
    return fn_80136A28(a, b, 6, -1, -1, -1);
}

static inline s32 PartyCount(void)
{
    Big *p;
    s32 n;
    n = 0;
    p = fn_80135598();
    if (p != NULL) {
        n = 0;
        if (p->order[0] >= 0) {
            n = 1;
            if (p->order[1] >= 0) {
                n = 2;
                if (p->order[2] >= 0) {
                    n = 3;
                    if (p->order[3] >= 0) {
                        n = 4;
                    }
                }
            }
        }
    }
    return n;
}

static inline s32 FindFirst(MenuStep *o)
{
    s32 i;
    s32 cy = o->b2;
    s32 n = PartyCount();
    s32 t;
    s32 r;
    i = 0;
    while (i >= 0 && i < n && fn_801358A0(i, cy, 6, 0, n) == 0) {
        i++;
    }
    t = i > -1 ? i : -1;
    r = n;
    if (t < n) r = t;
    if (r < 0 || r >= n) r = -1;
    return r;
}

static inline void MarkChosen(MenuStep *o)
{
    Cell cb;
    Cell ca;
    s32 cy;
    s32 i;
    s32 n = PartyCount();
    if (o != NULL) {
        cy = o->b2;
        i = o->b8;
        ca.x = i; ca.y = cy; ca.a = 1; ca.c = -1; ca.b = -1;
        fn_80131658(&ca);
        cb.x = i; cb.y = cy; cb.a = 3; cb.c = -1; cb.b = -1;
        fn_80131658(&cb);
        fn_8013FB48(o->b2, n);
        if (o != NULL) o->ba = 0;
        fn_8012F478(1);
    }
}

s32 fn_80138114(MenuStep *o)
{
    s32 ret;

    ret = 0;
    switch (o->state) {
    case 0:
        o->b8 = FindFirst(o);
        fn_801315FC(0);
        o->state = 1;
    case 1:
        o->b8 = fn_801365D8(o->b8, o->b2, 6, 0, 0xb);
        if (lbl_80311A60.pad->x8 & 0x200) {
            MarkChosen(o);
            fn_80130304(-1);
            fn_801315FC(1);
            SePlay(0xf, 1, 7);
            ret = 1;
        } else if (lbl_80311A60.pad->x8 & 0x100) {
            fn_801380E4(o->b2, o->b8);
            fn_80130304(-1);
            fn_801315FC(1);
            SePlay(0xf, 1, 2);
            o->state = 2;
        }
        break;
    case 2:
        ret = 2;
        break;
    }
    return ret;
}

s32 fn_801383DC(MenuStep *p) {
    p->state = 0;
    return 2;
}

s32 fn_801383EC(s32 a, s32 b, s32 c) {
    return fn_80136A28(a, b, 5, -1, c, -1);
}

void fn_80130378(void) {
    *(void **)&lbl_80346F40 = fn_802268E8(lbl_803475A8, fn_801303D0);
    *(void **)((u8 *)lbl_80346F40 + 0x24) = fn_801E1C7C(0xe8);
    if (lbl_80346F40 != 0) {
        **(u8 **)((u8 *)lbl_80346F40 + 0x24) = 1;
    }
}

void fn_801316DC(void) {
    lbl_80346F48 = fn_802268E8(lbl_803475A8, fn_80131734);
    *(void **)((u8 *)lbl_80346F48 + 0x24) = fn_801E1C7C(0xb0);
    if (lbl_80346F48 != 0) {
        **(u8 **)((u8 *)lbl_80346F48 + 0x24) = 1;
    }
}

void fn_80132400(void) {
    *(void **)&lbl_80346F50 = fn_802268E8(lbl_803475A8, fn_80132458);
    *(void **)((u8 *)lbl_80346F50 + 0x24) = fn_801E1C7C(0x7c);
    if (lbl_80346F50 != 0) {
        **(u8 **)((u8 *)lbl_80346F50 + 0x24) = 1;
    }
}

void fn_80133154(void) {
    *(void **)&lbl_80346F58 = fn_802268E8(lbl_803475A8, fn_801331AC);
    *(void **)((u8 *)lbl_80346F58 + 0x24) = fn_801E1C7C(0x28);
    if (lbl_80346F58 != 0) {
        **(u8 **)((u8 *)lbl_80346F58 + 0x24) = 1;
    }
}

extern void fn_80133478(void);
extern void fn_80133750(void);
extern void fn_8013360C(void);

static inline void SetKind(s32 *src) {
    if (lbl_80346F58 == 0) return;
    lbl_80346F58->x24->kind[0] = src[0];
    lbl_80346F58->x24->kind[1] = src[1];
    lbl_80346F58->x24->kind[2] = src[2];
}

void fn_801331AC(Task_801303D0 *t) {
    s32 loc[3];
    switch (t->state) {
    case 0:
    case 0xfe:
        lbl_80346F58->x28 = fn_801E1C7C(0x2c);
        lbl_80346F58->x28[0] = fn_801D68C4(lbl_80346EFC, 0);
        lbl_80346F58->x28[1] = fn_801D68C4(lbl_80346EFC, 8);
        lbl_80346F58->x28[2] = fn_801D68C4(lbl_80346EFC, 2);
        lbl_80346F58->x28[3] = fn_801D68C4(lbl_80346EFC, 0xe);
        lbl_80346F58->x28[4] = fn_801D68C4(lbl_80346EFC, 0x10);
        lbl_80346F58->x28[5] = fn_801D68C4(lbl_80346EFC, 0xf);
        lbl_80346F58->x28[6] = fn_801D68C4(lbl_80346EFC, 0x14);
        lbl_80346F58->x28[7] = fn_801D68C4(lbl_80346EFC, 1);
        lbl_80346F58->x28[8] = fn_801D68C4(lbl_80346EFC, 0x13);
        lbl_80346F58->x28[9] = fn_801D68C4(lbl_80346EFC, 0x11);
        lbl_80346F58->x28[10] = fn_801D68C4(lbl_80346EFC, 0x12);
        lbl_80346F58->x24->x2 = 0;
        lbl_80346F58->x24->x3 = 0;
        lbl_80346F58->x24->v0 = 10;
        lbl_80346F58->x24->v1 = 7;
        lbl_80346F58->x24->v2 = 7;
        lbl_80346F58->x24->v3 = 60000;
        lbl_80346F58->x24->v4 = 100000;
        if (lbl_80346F58 != NULL) lbl_80346F58->x24->msg = 0;
        loc[0] = 0;
        loc[1] = 2;
        loc[2] = 3;
        { s32 *lp = loc; SetKind(lp); }
        t->state = 1;
        break;
    case 1:
        switch (lbl_80346F58->x24->x1) {
        case 0x11:
            fn_80133478();
            if (lbl_80346F58 != NULL) lbl_80346F58->x24->x1 = 0;
            break;
        case 0:
        default:
            break;
        }
        if (lbl_80346F58->x24->x0 == 0) {
            fn_80133900();
            fn_80133750();
            fn_8013360C();
        }
        break;
    case 2:
        t->state = 0xff;
        break;
    case 0xff:
        t->flags |= 0x40;
        break;
    }
}

void fn_80136FDC(s32 a, s32 b, s8 *tbl, s32 idx) {
    s32 v = 0x16;
    s32 ok = 0;
    if (idx >= 0 && idx < 6) {
        ok = 1;
    }
    if (ok != 0) {
        v = tbl[idx];
    }
    ok = 0;
    if (v >= 0 && v < 0x16) {
        ok = 1;
    }
    if (ok != 0) {
        fn_80136A28(a, b, 7, v, -1, -1);
    }
}

s32 fn_80137058(s32 a, s32 b, s8 *tbl, s32 idx) {
    s32 ok = 0;
    s32 v = 0x16;
    if (idx >= 0 && idx < 6) {
        ok = 1;
    }
    if (ok != 0) {
        v = tbl[idx];
    }
    return fn_801365D8(a, b, 7, v, 0xe);
}

inline s32 ValidIdx(s32 i)
{
    return i >= 0 && i < 0x16;
}

inline s32 HasFlag(s32 i)
{
    Party* p;
    s32 r = 0;
    p = &fn_80135598()->party;
    if (p != 0) {
        if (ValidIdx(i)) {
            r = (p->flags & (1 << i)) != 0;
        }
    }
    return r;
}

static inline s32 InRange(s32 v, s32 n) {
    s32 r = 0;
    if (v >= 0 && v < n) {
        r = 1;
    }
    return r;
}

extern char *lbl_802F7298[];
extern void fn_8012ADE8(s32 v);
extern void fn_801370B0(MenuStep *o);
extern void fn_8012E5B0(s8 v);
extern void fn_8012E580(s8 v);
extern void fn_8012E404(u8 v);
extern void fn_8012E560(s8 v);
extern void fn_8012E5A0(u16 v);
extern void fn_8012E590(s8 v);
extern void fn_8012E5C0(s8 v);
s32 fn_80137414(s8* out, s32 n);
void fn_801375A0(s32 a0, s32 a1, s8 *src);






/* Whether the crew member under the cursor has joined. */
static inline s32 CurJoined(MenuStep *o)
{
    s32 r;
    s32 ok = 0;
    s32 id = 0x16;
    if (InRange(o->b7, 6)) {
        id = o->x10[o->b7];
    }
    if (InRange(id, 0x16)) {
        Party *p;
        r = 0;
        p = &fn_80135598()->party;
        if (p != 0) {
            if (ValidIdx(id)) {
                r = (p->flags & (1 << id)) != 0;
            }
        }
        if (r) {
            ok = 1;
        }
    }
    return ok;
}

static inline void ShowDesc(MenuStep *o)
{
    s32 flag;
    char *str = NULL;
    s32 id;
    s32 idx;

    if (o != NULL) {
        idx = o->b7;
        flag = idx >= 3;
        if (CurJoined(o)) {
            id = 0x16;
            if (InRange(o->b7, 6)) {
                id = o->x10[o->b7];
            }
            if (InRange(id, 0x16)) {
                str = lbl_802F7298[id];
            }
        }
        if (str == NULL) {
            str = "\n";
        }
        fn_8012F458(flag);
        fn_8012F468(str);
    }
}

static inline s32 FindPost(MenuStep *o)
{
    s32 cy;
    s32 id = 0x16;
    s32 i;
    s32 n;
    s32 t;
    s32 r;
    if (InRange(o->b7, 6)) {
        id = o->x10[o->b7];
    }
    cy = o->b2;
    n = PartyCount();
    i = 0;
    while (i >= 0 && i < n && fn_801358A0(i, cy, 7, id, n) == 0) {
        i++;
    }
    t = i > -1 ? i : -1;
    r = n;
    if (t < n) r = t;
    if (r < 0 || r >= n) r = -1;
    return r;
}

static inline s32 JoinedCount(void)
{
    s32 n = 0;
    s32 i;
    for (i = 0; i < 0x16; i++) {
        if (HasFlag(i)) {
            n++;
        }
    }
    return n;
}

/* The crew member under the cursor's cost into v (100 when there is none). A macro: it
 * works on the caller's v. */
#define CUR_COST(o, v)                              {                                                   const CrewData *tbl_ = lbl_802D8E64;            s32 id_ = 0x16;                                 v = 100;                                        if (InRange((o)->b7, 6)) {                          id_ = (o)->x10[(o)->b7];                    }                                               if (InRange(id_, 0x16)) {                           const CrewData *e_ = &tbl_[id_];                v = 100;                                        if (e_ != NULL) {                                   v = e_->cost;                               }                                           }                                           }

static inline void Close(MenuStep *o)
{
    if (o != NULL) o->ba = 0;
    fn_8012F478(1);
}

static inline s32 AnyKey(MenuStep *o)
{
    s32 r = 0;
    if (lbl_80311A60.pad->x8 & 0xf0f) {
        Close(o);
        SePlay(0xf, 1, 7);
        r = 1;
    }
    return r;
}

static inline void BuildPage(MenuStep *o)
{
    s32 n;
    s32 pages;
    s32 sel = o->b7;
    s32 page = o->b6;
    s32 money = o->x16;

    fn_8012E5B0(3);
    pages = 1;
    n = JoinedCount();
    if (n != 0) {
        pages = (n + 5) / 6;
    }
    fn_8012E580(pages);
    fn_8012E404(1);
    fn_8012E560(sel);
    fn_8012E5A0(0);
    fn_8012E590(0);
    fn_801375A0(money, page, o->x10);
    fn_8012E5C0(0);
}

s32 fn_801377C0(MenuStep *o)
{
    s32 ret;
    s32 v;
    u32 pad;

    ret = 0;
    switch (o->state) {
    case 0:
        o->state = 1;
    case 1:
        fn_80137414(o->x10, o->b6);
        BuildPage(o);
        fn_80130304(-1);
        Close(o);
        o->state = 2;
    case 2:
        fn_801370B0(o);
        pad = lbl_80311A60.pad->x8;
        if (pad & 0x200) {
            fn_8012E5C0(1);
            Close(o);
            SePlay(0xf, 1, 7);
            ret = 1;
        } else if (pad & 0x100) {
            if (fn_80136C14(o->x10, o->b7, o->x16) == 0) {
                SePlay(0xf, 1, 3);
            } else {
                fn_801315FC(0);
                CUR_COST(o, v);
                fn_8012ADE8(o->x16 - v);
                SePlay(0xf, 1, 2);
                o->state = 4;
            }
        } else if (pad & 0x400) {
            if (CurJoined(o)) {
                ShowDesc(o);
                if (o != NULL) o->ba = 1;
                fn_8012F478(0);
                SePlay(0xf, 1, 6);
                o->state = 3;
            }
        }
        break;
    case 3:
        if (AnyKey(o)) {
            o->state = 2;
        }
        break;
    case 4:
        o->b8 = FindPost(o);
        o->state = 5;
    case 5:
        o->b8 = fn_80137058(o->b8, o->b2, o->x10, o->b7);
        pad = lbl_80311A60.pad->x8;
        if (pad & 0x200) {
            fn_8012ADE8(o->x16);
            MarkChosen(o);
            fn_80130304(-1);
            fn_801315FC(1);
            SePlay(0xf, 1, 7);
            o->state = 1;
        } else if (pad & 0x100) {
            if (fn_80136C14(o->x10, o->b7, o->x16) == 0) {
                SePlay(0xf, 1, 3);
            } else {
                fn_80136FDC(o->b2, o->b8, o->x10, o->b7);
                fn_80130304(-1);
                fn_801315FC(1);
                SePlay(0xf, 1, 2);
                o->state = 6;
            }
        }
        break;
    case 6:
        fn_8012E5C0(1);
        CUR_COST(o, v);
        if (o != NULL && v > 0 && v != 100) {
            o->x16 -= v;
            o->x18[o->b2] = v;
            fn_8012ADE8(o->x16);
        }
        Close(o);
        ret = 2;
        break;
    }
    return ret;
}

s32 fn_80138848(s32 r3)
{
    s32 r0 = -1;
    switch (r3) {
    case 0: r0 = 4; break;
    case 1: r0 = 3; break;
    case 2: r0 = 6; break;
    case 3: r0 = 5; break;
    case 4: r0 = 7; break;
    case 5: r0 = 8; break;
    }
    return r0;
}

s32 fn_801388B4(s32 r3)
{
    s32 r0 = -1;
    switch (r3) {
    case 0: r0 = 0; break;
    case 1: r0 = 1; break;
    case 2: r0 = 2; break;
    case 3: r0 = 3; break;
    case 4: r0 = 4; break;
    case 5: r0 = 5; break;
    }
    return r0;
}

void fn_80130040(void) {
    fn_80130C6C();
    ((Fn80130040Mgr *)lbl_80346F40)->inner->dst[0] = ((Fn80130040Mgr *)lbl_80346F40)->inner->src[0];
    ((Fn80130040Mgr *)lbl_80346F40)->inner->dst[1] = ((Fn80130040Mgr *)lbl_80346F40)->inner->src[1];
    ((Fn80130040Mgr *)lbl_80346F40)->inner->dst[2] = ((Fn80130040Mgr *)lbl_80346F40)->inner->src[2];
    ((Fn80130040Mgr *)lbl_80346F40)->inner->dst[3] = ((Fn80130040Mgr *)lbl_80346F40)->inner->src[3];
    ((Fn80130040Mgr *)lbl_80346F40)->inner->dst[4] = ((Fn80130040Mgr *)lbl_80346F40)->inner->src[4];
    ((Fn80130040Mgr *)lbl_80346F40)->inner->dst[5] = ((Fn80130040Mgr *)lbl_80346F40)->inner->src[5];
    ((Fn80130040Mgr *)lbl_80346F40)->inner->dst[6] = ((Fn80130040Mgr *)lbl_80346F40)->inner->src[6];
    ((Fn80130040Mgr *)lbl_80346F40)->inner->dst[7] = ((Fn80130040Mgr *)lbl_80346F40)->inner->src[7];
}

void fn_80130264(s32 *src) {
    ((Fn80130264Mgr *)lbl_80346F40)->inner->dst[0] = src[0];
    ((Fn80130264Mgr *)lbl_80346F40)->inner->dst[1] = src[1];
    ((Fn80130264Mgr *)lbl_80346F40)->inner->dst[2] = src[2];
    ((Fn80130264Mgr *)lbl_80346F40)->inner->dst[3] = src[3];
    ((Fn80130264Mgr *)lbl_80346F40)->inner->dst[4] = src[4];
    ((Fn80130264Mgr *)lbl_80346F40)->inner->dst[5] = src[5];
    ((Fn80130264Mgr *)lbl_80346F40)->inner->dst[6] = src[6];
    ((Fn80130264Mgr *)lbl_80346F40)->inner->dst[7] = src[7];
    fn_80130B64();
}

void fn_80130C6C(void) {
    s32 i;

    for (i = 0; i < 8; i++) {
        switch (((Fn80130C6CMgr *)lbl_80346F40)->inner->in[i]) {
        case 0:
            ((Fn80130C6CMgr *)lbl_80346F40)->inner->out[i] = 0xff40dc40;
            break;
        case 4:
            ((Fn80130C6CMgr *)lbl_80346F40)->inner->out[i] = 0xff40dcdc;
            break;
        case 1:
            ((Fn80130C6CMgr *)lbl_80346F40)->inner->out[i] = 0xffdcdc40;
            break;
        case 5:
            ((Fn80130C6CMgr *)lbl_80346F40)->inner->out[i] = 0xffdc7040;
            break;
        case 2:
            ((Fn80130C6CMgr *)lbl_80346F40)->inner->out[i] = 0xffdc4040;
            break;
        case 3:
            ((Fn80130C6CMgr *)lbl_80346F40)->inner->out[i] = 0;
            break;
        default:
            ((Fn80130C6CMgr *)lbl_80346F40)->inner->out[i] = 0xff40dc40;
            break;
        }
    }
}

void fn_80131500(s8 c) {
    ((Fn80131500Mgr *)lbl_80346F48)->inner->f_ae = c;
    if (c == 3) {
        ((Fn80131500Mgr *)lbl_80346F48)->holder->a = (s32)fn_801D68C4(lbl_80346F04, 0x52);
        ((Fn80131500Mgr *)lbl_80346F48)->holder->b = (s32)fn_801D68C4(lbl_80346F04, 0x53);
    } else {
        ((Fn80131500Mgr *)lbl_80346F48)->holder->a = (s32)fn_801D68C4(lbl_80346F08, 0x52);
        ((Fn80131500Mgr *)lbl_80346F48)->holder->b = (s32)fn_801D68C4(lbl_80346F08, 0x53);
    }
}

void fn_80132128(void)
{
    s32 i;
    Args b;

    for (i = 0; i < 2; i++) {
        b.obj = lbl_80346F48->x28[i];
        b.f4 = -1.2f;
        b.f8 = 1.0f;
        b.c = 0;
        b.d = 0;
        b.e = 1.0f;
        b.g = 1.0f;
        fn_8012A9A8(&b);
    }
}

void fn_8012FF48(s8 mode)
{
    lbl_80346F40->x24->x94 = mode;
    if (mode == 3) {
        lbl_80346F40->x28[0] = fn_801D68C4(lbl_80346F04, 0x64);
        lbl_80346F40->x28[4] = fn_801D68C4(lbl_80346F04, 0x68);
        lbl_80346F40->x28[6] = fn_801D68C4(lbl_80346F04, 0x84);
        lbl_80346F40->x28[1] = fn_801D68C4(lbl_80346F04, 0x83);
    } else {
        lbl_80346F40->x28[0] = fn_801D68C4(lbl_80346F08, 0x64);
        lbl_80346F40->x28[4] = fn_801D68C4(lbl_80346F08, 0x68);
        lbl_80346F40->x28[6] = fn_801D68C4(lbl_80346F08, 0x84);
        lbl_80346F40->x28[1] = fn_801D68C4(lbl_80346F08, 0x83);
    }
}

void fn_8013360C(void)
{
    s32 y;
    s32 i;
    y = 0x86;
    for (i = 0; i < 3; i++, y += 0x1c) {
        Args a;
        a.obj = NULL;
        switch (lbl_80346F58->x24->kind[i]) {
        case 0:
            a.obj = fn_801D68C4(lbl_80346EFC, 0x1f);
            break;
        case 1:
            a.obj = fn_801D68C4(lbl_80346EFC, 0x20);
            break;
        case 2:
            a.obj = fn_801D68C4(lbl_80346EFC, 0x21);
            break;
        case 3:
            a.obj = fn_801D68C4(lbl_80346EFC, 0x22);
            break;
        }
        if (a.obj != NULL) {
            a.obj->f14 = (f32)y;
            a.obj->f18 = 258.0f;
            a.f4 = -1.298f;
            a.f8 = 1.0f;
            a.c = 0;
            a.d = 0;
            a.e = 1.0f;
            a.g = 1.0f;
            fn_8012A954(&a);
        }
    }
}

static inline void Sync(Item *it)
{
    if (it != NULL) {
        s8 id = it->id;
        if (id >= 0 && id < 6) {
            lbl_8030B7F4.chr[id].mp = it->e;
        }
    }
}

void fn_80134900(void)
{
    Big *b = &lbl_803063F0;
    Item *it;
    Save1568 *q;
    s32 i;
    fn_80134754(b);
    if (&lbl_803063F0.items[0] != NULL) {
        it = b->items;
        for (i = 0; i < 4; i++, it++) {
            Sync(it);
        }
    }
    if (&b->party != NULL) {
        q = &lbl_8030B7F4.x1568;
        if (q->b1568 < 0) {
            q = NULL;
        }
        if (q != NULL) {
            q->x157c = b->party.x18;
        }
    }
}

void fn_80134C24(Member *p, ShipArm *src, const char *name)
{
    if (p != NULL) {
        if (src == NULL) {
            if (p != NULL) {
                memset(p, 0, 0x11);
                p->id = -1;
                p->b14 = -1;
                p->b15 = -1;
                p->s16 = 0;
                p->s18 = 0;
                p->s1a = 0;
                p->s1c = 0;
                p->b1e = 0;
                p->b1f = 0;
                p->b20 = 0;
            }
        } else {
            if (name == NULL) {
                memset(p, 0, 0x11);
            } else {
                strncpy(p->name, name, 0x10);
                p->name[0x10] = 0;
            }
            p->id = -1;
            p->b14 = src->type;
            p->b15 = src->element;
            p->s16 = src->attack;
            p->s18 = 0;
            p->s1a = src->accuracy;
            p->s1c = 0;
            p->b1e = src->range;
            p->b1f = 0;
            p->b20 = 0;
        }
    }
}

int fn_80136B10(s8 *dst) {
    int n = 0;
    s8 *src = fn_80135598()->order;
    if (dst != NULL && src != NULL) {
        int i;
        for (i = 0; i < 4; i++) {
            int c = src[i];
            if (c < 0) break;
            dst[i] = c;
        }
        n = i;
        for (; i < 4; i++) dst[i] = -1;
    }
    return n;
}

s32 fn_801361B8(s32 a, s32 lo, s32 y, s32 hi, s32 d)
{
    Cell c3;
    Cell c0;
    Cell c1;
    Cell c2;
    s32 i;
    s32 j;
    s32 end;
    s32 code;

    for (i = lo; i <= hi; i++) {
        c0.x = i;
        c0.y = y;
        c0.a = 1;
        c0.c = -1;
        c0.b = -1;
        fn_80131658(&c0);
        c1.x = i;
        c1.y = y;
        c1.a = 3;
        c1.c = -1;
        c1.b = -1;
        fn_80131658(&c1);
    }
    end = fn_8013A794(a, lo, hi, d);
    c2.x = lo;
    c2.y = y;
    c2.a = 1;
    c2.c = 2;
    c2.b = 1;
    fn_80131658(&c2);
    switch (end - lo) {
    case 0:
        code = 0x12;
        break;
    case 1:
        code = 0x13;
        break;
    case 2:
        code = 0x14;
        break;
    case 3:
        code = 0x15;
        break;
    default:
        code = 0x12;
        break;
    }
    c3.x = lo;
    c3.y = y;
    c3.a = 3;
    c3.c = 2;
    c3.b = code;
    fn_80131658(&c3);
    for (j = lo + 1; j <= end; j++)
        fn_8013160C(j, y, 0);
    return end;
}

void fn_80133478(void)
{
    void* a;
    void* b;
    switch ((*(Holder**)&lbl_80346F58)->x24->kind) {
    case 0:
        a = fn_801D68C4(lbl_80346EFC, 8);
        b = fn_801D68C4(lbl_80346EFC, 2);
        break;
    case 1:
        a = fn_801D68C4(lbl_80346EFC, 9);
        b = fn_801D68C4(lbl_80346EFC, 3);
        break;
    case 2:
        a = fn_801D68C4(lbl_80346EFC, 10);
        b = fn_801D68C4(lbl_80346EFC, 4);
        break;
    case 3:
        a = fn_801D68C4(lbl_80346EFC, 11);
        b = fn_801D68C4(lbl_80346EFC, 5);
        break;
    case 4:
        a = fn_801D68C4(lbl_80346EFC, 12);
        b = fn_801D68C4(lbl_80346EFC, 6);
        break;
    case 5:
        a = fn_801D68C4(lbl_80346EFC, 13);
        b = fn_801D68C4(lbl_80346EFC, 7);
        break;
    default:
        a = fn_801D68C4(lbl_80346EFC, 8);
        b = fn_801D68C4(lbl_80346EFC, 2);
        break;
    }
    (*(Holder**)&lbl_80346F58)->x28[1] = a;
    (*(Holder**)&lbl_80346F58)->x28[2] = b;
    ((Holder0C*)(*(Holder**)&lbl_80346F58)->x28[3])->spr->x14 = 0xFF808080;
}

void fn_8012F75C(void) {
    lbl_80346F38 = fn_802268E8(lbl_803475A8, fn_8012F958);
    lbl_80346F38->x24 = fn_801E1C7C(0x54);
    if (lbl_80346F38 != 0) {
        lbl_80346F38->x24->b0 = 1;
    }
    if (lbl_80346F38 != 0) {
        lbl_80346F38->x24->b1 = 0;
    }
    lbl_80346F38->x24->str[0] = 0;
    lbl_80346F38->x24->b2[0] = 1;
    lbl_80346F38->x24->ba[0] = -1;
    lbl_80346F38->x24->w14[0] = 0;
    lbl_80346F38->x24->str[1] = 0;
    lbl_80346F38->x24->b2[1] = 1;
    lbl_80346F38->x24->ba[1] = -1;
    lbl_80346F38->x24->w14[1] = 0;
    lbl_80346F38->x24->str[2] = 0;
    lbl_80346F38->x24->b2[2] = 1;
    lbl_80346F38->x24->ba[2] = -1;
    lbl_80346F38->x24->w14[2] = 0;
    lbl_80346F38->x24->str[3] = 0;
    lbl_80346F38->x24->b2[3] = 1;
    lbl_80346F38->x24->ba[3] = -1;
    lbl_80346F38->x24->w14[3] = 0;
    lbl_80346F38->x24->str[4] = 0;
    lbl_80346F38->x24->b2[4] = 1;
    lbl_80346F38->x24->ba[4] = -1;
    lbl_80346F38->x24->w14[4] = 0;
    lbl_80346F38->x24->str[5] = 0;
    lbl_80346F38->x24->b2[5] = 1;
    lbl_80346F38->x24->ba[5] = -1;
    lbl_80346F38->x24->w14[5] = 0;
    lbl_80346F38->x24->str[6] = 0;
    lbl_80346F38->x24->b2[6] = 1;
    lbl_80346F38->x24->ba[6] = -1;
    lbl_80346F38->x24->w14[6] = 0;
    lbl_80346F38->x24->str[7] = 0;
    lbl_80346F38->x24->b2[7] = 1;
    lbl_80346F38->x24->ba[7] = -1;
    lbl_80346F38->x24->w14[7] = 0;
}

s32 fn_80138920(s16* a, s16* b) {
    s16 bv = b[1];
    return a[1] - bv;
}

s32 fn_80139A94(u8* p) {
    p[0x1] = 0;
    return 2;
}

s32 fn_8013A310(u8* p) {
    p[0x1] = 0;
    return 2;
}

void fn_8013A35C(s32 a, s32 lo, s32 v, s32 hi) {
    Cell c1b;
    Cell c2b;
    Cell c1a;
    Cell c2a;
    Party *arr;
    s32 kind;
    s32 ok;
    s32 code;
    s32 i;

    fn_80136A28(a, lo, 4, v, -1, hi);
    arr = &fn_80135598()->party;
    kind = 4;
    ok = 0;
    if (arr != 0 && v >= 0 && v < 5 && arr->mem[v].b14 >= 0) {
        ok = 1;
    }
    if (ok != 0) {
        kind = arr->mem[v].b14;
    }
    switch (kind) {
    case 1:
        c1a.x = lo;
        c1a.y = a;
        c1a.a = 1;
        c1a.c = 2;
        c1a.b = 1;
        fn_80131658(&c1a);
        switch (hi - lo) {
        case 0:
            code = 0x12;
            break;
        case 1:
            code = 0x13;
            break;
        case 2:
            code = 0x14;
            break;
        case 3:
            code = 0x15;
            break;
        default:
            code = 0x12;
            break;
        }
        c1b.x = lo;
        c1b.y = a;
        c1b.a = 3;
        c1b.c = 2;
        c1b.b = code;
        fn_80131658(&c1b);
        for (i = lo + 1; i <= hi; i++) {
            fn_8013160C(i, a, 2);
        }
        break;
    case 2:
        c2a.x = lo;
        c2a.y = a;
        c2a.a = 1;
        c2a.c = 2;
        c2a.b = 0xd;
        fn_80131658(&c2a);
        c2b.x = hi;
        c2b.y = a;
        c2b.a = 3;
        c2b.c = 2;
        c2b.b = 0xc;
        fn_80131658(&c2b);
        break;
    }
}

void fn_801303D0(Task_801303D0 *t) {
    switch (t->state) {
    case 0:
    case 0xFE:
        lbl_80346F40->x28 = fn_801E1C7C(0x1c);
        lbl_80346F40->x28[0] = fn_801D68C4(lbl_80346F04, 0x64);
        lbl_80346F40->x28[2] = fn_801D68C4(lbl_80346F04, 0x66);
        lbl_80346F40->x28[5] = fn_801D68C4(lbl_80346F04, 0x67);
        lbl_80346F40->x28[3] = fn_801D68C4(lbl_80346F04, 0x65);
        lbl_80346F40->x28[4] = fn_801D68C4(lbl_80346F04, 0x68);
        lbl_80346F40->x28[1] = fn_801D68C4(lbl_80346F04, 0x83);
        lbl_80346F40->x28[6] = fn_801D68C4(lbl_80346F04, 0x84);
        fn_80131254();
        lbl_80305FA0[0][0] = fn_801D68C4(lbl_80346F04, 0x84);
        lbl_80305FA0[0][1] = fn_801D68C4(lbl_80346F04, 0x85);
        lbl_80305FA0[0][2] = fn_801D68C4(lbl_80346F04, 0x86);
        lbl_80305FA0[0][3] = fn_801D68C4(lbl_80346F04, 0x87);
        lbl_80305FA0[1][0] = fn_801D68C4(lbl_80346F08, 0x84);
        lbl_80305FA0[1][1] = fn_801D68C4(lbl_80346F08, 0x85);
        lbl_80305FA0[1][2] = fn_801D68C4(lbl_80346F08, 0x86);
        lbl_80305FA0[1][3] = fn_801D68C4(lbl_80346F08, 0x87);
        t->state = 1;
        break;
    case 1:
        if (fn_801305E4() == 0) {
            t->state = 2;
        }
        break;
    case 2:
        t->state = 0xFF;
        break;
    case 0xFF:
        t->flags |= 0x40;
        break;
    }
}

void fn_80132458(Task_801303D0 *t) {
    switch (t->state) {
    case 0:
    case 0xFE:
        ((Obj_80132458 *)lbl_80346F50)->x28 = fn_801E1C7C(0xc);
        ((Obj_80132458 *)lbl_80346F50)->x28[0] = (s32)fn_801D68C4(lbl_80346F00, 0);
        ((Obj_80132458 *)lbl_80346F50)->x28[1] = (s32)fn_801D68C4(lbl_80346F00, 1);
        ((Obj_80132458 *)lbl_80346F50)->x28[2] = (s32)fn_801D68C4(lbl_80346F00, 2);
        ((Obj_80132458 *)lbl_80346F50)->x24->b2 = 0xf;
        ((Obj_80132458 *)lbl_80346F50)->x24->b3 = 5;
        ((Obj_80132458 *)lbl_80346F50)->x24->b4 = -1;
        ((Obj_80132458 *)lbl_80346F50)->x24->f8 = 0.36f;
        ((Obj_80132458 *)lbl_80346F50)->x24->wc = 10000;
        ((Obj_80132458 *)lbl_80346F50)->x24->w10 = 40000;
        ((Obj_80132458 *)lbl_80346F50)->x24->w18 = lbl_80346EF8->x4->x20;
        ((Obj_80132458 *)lbl_80346F50)->x24->w1c = 0;
        ((Obj_80132458 *)lbl_80346F50)->x24->w28 = 20000;
        ((Obj_80132458 *)lbl_80346F50)->x24->w2c = 40000;
        ((Obj_80132458 *)lbl_80346F50)->x24->w34 = lbl_80346EF8->x4->x20;
        ((Obj_80132458 *)lbl_80346F50)->x24->w38 = 0;
        ((Obj_80132458 *)lbl_80346F50)->x24->w44 = 30000;
        ((Obj_80132458 *)lbl_80346F50)->x24->w48 = 40000;
        ((Obj_80132458 *)lbl_80346F50)->x24->w50 = lbl_80346EF8->x4->x20;
        ((Obj_80132458 *)lbl_80346F50)->x24->w54 = 0;
        ((Obj_80132458 *)lbl_80346F50)->x24->w60 = 40000;
        ((Obj_80132458 *)lbl_80346F50)->x24->w64 = 40000;
        ((Obj_80132458 *)lbl_80346F50)->x24->w6c = lbl_80346EF8->x4->x20;
        ((Obj_80132458 *)lbl_80346F50)->x24->w70 = 0;
        ((Obj_80132458 *)lbl_80346F50)->x24->w3c = 1;
        ((Obj_80132458 *)lbl_80346F50)->x24->b40 = 0;
        t->state = 1;
        break;
    case 1:
        if (((Obj_80132458 *)lbl_80346F50)->x24->b0 == 0) {
            FieldPartyStatusDraw();
        }
        break;
    case 2:
        t->state = 0xFF;
        break;
    case 0xFF:
        t->flags |= 0x40;
        break;
    }
}

s32 fn_8013D3F0(u8* p) {
    p[0x1] = 0;
    return 2;
}

static inline Save1568 *PlayerShip(void)
{
    Save1568 *q = &lbl_8030B7F4.x1568;
    if (q->b1568 < 0) {
        q = NULL;
    }
    return q;
}

static inline void RefreshParty(Item *items)
{
    s32 i;
    s32 time;
    Save1568 *q;
    s8 buf[0x18];

    time = 0;
    if (items != NULL) {
        q = PlayerShip();
        if (q != NULL) {
            fn_8021A1C4(buf);
            time = fn_8021A83C(q, buf);
        }
        for (i = 0; i < 4; i++) {
            fn_80135290(&items[i], i, time);
        }
    }
}

void fn_801353A8(void)
{
    Big *b = &lbl_803063F0;

    fn_8013506C(b);
    RefreshParty(b->items);
    fn_80134E7C(&b->party);
}

Big* fn_80135598(void) {
    return &lbl_803063F0;
}

void fn_8013A320(s32 i)
{
    if (i >= -4 && i < 4) {
        lbl_80308E90[i + 4].a[0] = -1;
        lbl_80308E90[i + 4].a[1] = -1;
        lbl_80308E90[i + 4].a[2] = -1;
        lbl_80308E90[i + 4].a[3] = -1;
        lbl_80308E90[i + 4].a[4] = -1;
    }
}

void fn_80131658(Cell *cell)
{
    s8 a = cell->x;
    s8 b = cell->y;
    s8 c = cell->a;

    lbl_80346F48->inner->grid[a][b][c] = cell->b;
    lbl_80346F48->inner->sel[a][b] = cell->c;
}

s32 fn_8013A794(s32 a, s32 b, s32 cur, s32 d) {
    s32 r;
    s32 step = 0;

    if (lbl_80311A60.pad->x8 & 1) {
        step = -1;
    }
    if (lbl_80311A60.pad->x8 & 2) {
        step++;
    }
    r = fn_8013A538(a, b, cur, step, d);
    if (r != cur) {
        SePlay(0xf, 1, 0);
    }
    return r;
}

static inline s32 chk(u8 t) {
    s8 s = t;
    if (s == 13 || (u8)(t - 14) <= 1 || s == 16) return 1;
    return 0;
}
void fn_80130D30(void) {
    S s;
    s32 i;
    for (i = 0; i < 7; i++) {
        switch (i) {
        case 2:
            fn_80130FB4();
            break;
        case 5: {
            s32 n = (*(P **)&lbl_80346F40)->x24->xa4;
            if (n == -1) break;
            s.h = (*(P **)&lbl_80346F40)->x28[i];
            s.h->x14 = (f32)(n * 0x19 + 0xfb);
            s.a = 0.001f * (f32)i + -1.2f;
            s.b = 1.0f;
            s.c = 0;
            s.d = 1;
            s.e = 1.0f;
            s.f = 1.0f;
            fn_8012A9A8((void *)(&s));
            break;
        }
        case 1:
            if (chk((*(P **)&lbl_80346F40)->x24->x1)) break;
            s.h = (*(P **)&lbl_80346F40)->x28[i];
            s.a = 0.001f * (f32)i + -1.2f;
            s.b = 1.0f;
            s.c = 0;
            s.d = 0;
            s.e = 1.0f;
            s.f = 1.0f;
            fn_8012A9A8((void *)(&s));
            break;
        case 6:
            s.h = (*(P **)&lbl_80346F40)->x28[i];
            s.a = 0.001f * (f32)i + -1.2f;
            s.b = 1.0f;
            s.c = 0;
            s.d = 0;
            s.e = 1.0f;
            s.f = 1.0f;
            break;
        case 3:
            break;
        case 0:
        case 4:
        default:
            s.h = (*(P **)&lbl_80346F40)->x28[i];
            s.a = 0.001f * (f32)i + -1.2f;
            s.b = 1.0f;
            s.c = 0;
            s.d = 0;
            s.e = 1.0f;
            s.f = 1.0f;
            break;
        }
        if ((u32)(i - 1) > 2 && i != 5) fn_8012A9A8((void *)(&s));
    }
}

void fn_801355A4(T *t) {
    s32 v;
    s32 a[8];
    s32 b[8];
    s32 d[8];
    s32 c[8];
    s8 *p;
    s32 v2;
    if (t == NULL) return;
    switch (t->state) {
    case 0:
        t->state = 1;
    case 1:
        t->x1c = 30;
        t->state = 2;
    case 2: {
        u32 n = t->x1c;
        if (n != 0) n--;
        t->x1c = n;
        if ((u8)n == 0) t->state = 3;
        break;
    }
    case 3:
        v = 0;
        if (fn_80130318() == 0 && fn_8012FF08() == 0) v = 1;
        if (v == 0) break;
        v = 0;
        p = fn_80135598()->order;
        if (p != NULL) {
            v = 0;
            if (p[0] >= 0) {
                v = 1;
                if (p[1] >= 0) {
                    v = 2;
                    if (p[2] >= 0) {
                        v = 3;
                        if (p[3] >= 0) v = 4;
                    }
                }
            }
        }
        if (t->x24 != NULL && t->x28 != NULL) {
            fn_8014093C(t->x24, v, a, b);
            fn_8014093C(t->x28, v, &a[v], &b[v]);
            if (a != NULL && b != NULL) {
                fn_801300E0(a);
                fn_80130264(b);
            }
            fn_80130338(0xd);
        }
        t->state = 4;
        break;
    case 4:
        v = 0;
        if (fn_80130318() == 0 && fn_8012FF08() == 0) v = 1;
        if (v != 0) t->state = 5;
        break;
    case 5:
        t->x1c = 30;
        t->state = 6;
    case 6: {
        u32 n = t->x1c;
        if (n != 0) n--;
        t->x1c = n;
        if ((u8)n == 0) t->state = 7;
        break;
    }
    case 7:
        v = 0;
        if (fn_80130318() == 0 && fn_8012FF08() == 0) v = 1;
        if (v == 0) break;
        v = 0;
        p = fn_80135598()->order;
        if (p != NULL) {
            v = 0;
            if (p[0] >= 0) {
                v = 1;
                if (p[1] >= 0) {
                    v = 2;
                    if (p[2] >= 0) {
                        v = 3;
                        if (p[3] >= 0) v = 4;
                    }
                }
            }
        }
        v2 = v * 2;
        if (t->x24 != NULL) {
            if (t->x24 != NULL) {
                fn_8014093C(t->x24, v2, c, d);
                if (c != NULL && d != NULL) {
                    fn_801300E0(c);
                    fn_80130264(d);
                }
            }
            fn_80130338(0xd);
        }
        t->state = 8;
        break;
    case 8:
        v = 0;
        if (fn_80130318() == 0 && fn_8012FF08() == 0) v = 1;
        if (v != 0) t->state = 1;
        break;
    case 9:
        break;
    }
}

void fn_80130B64(void)
{
    s32 i;
    s32 m;

    m = (*(Holder_80130B64**)&lbl_80346F40)->x24->mode;
    for (i = m; i < 8; i++) {
        switch ((*(Holder_80130B64**)&lbl_80346F40)->x24->kind[i - m]) {
        case 0:
            (*(Holder_80130B64**)&lbl_80346F40)->x24->color[i] = 0xFF40DC40;
            break;
        case 4:
            (*(Holder_80130B64**)&lbl_80346F40)->x24->color[i] = 0xFF40DCDC;
            break;
        case 1:
            (*(Holder_80130B64**)&lbl_80346F40)->x24->color[i] = 0xFFDCDC40;
            break;
        case 5:
            (*(Holder_80130B64**)&lbl_80346F40)->x24->color[i] = 0xFFDC7040;
            break;
        case 2:
            (*(Holder_80130B64**)&lbl_80346F40)->x24->color[i] = 0xFFDC4040;
            break;
        case 3:
            (*(Holder_80130B64**)&lbl_80346F40)->x24->color[i] = 0;
            break;
        default:
            (*(Holder_80130B64**)&lbl_80346F40)->x24->color[i] = 0xFF40DC40;
            break;
        }
    }
}

void fn_80135290(Item *v, s32 slot, s32 add)
{
    SaveChar *e = NULL;
    int id;
    StatRec *info;

    if (v == NULL) return;
    if (slot < 0 || slot >= 4) return;
    id = lbl_8030B7F4.party[slot];
    if (id >= 0) e = &lbl_8030B7F4.chr[id];
    v->id = id;
    if (e == NULL) return;
    MemCopy(v, e, 0xb);
    v->c = e->xb;
    v->d = e->mpMax;
    v->e = e->mp;
    v->stat[0] = e->stat[0];
    v->stat[1] = e->stat[1];
    v->stat[2] = e->stat[2];
    v->stat[3] = e->stat[3];
    v->stat[4] = e->stat[4];
    v->stat[5] = e->stat[5];
    v->stat[6] = e->stat[6];
    v->stat[7] = e->stat[7];
    info = &lbl_8030B4D4.chr[id];
    v->s18 = info->x48[1] + add;
    v->s1a = 0;
}



s32 fn_80137414(s8* out, s32 n)
{
    s32 i;
    s32 j;
    s32 rem;
    s32 ret = 0;
    s32 cnt;
    if (out != 0) {
        rem = n * 6;
        for (i = 0; i < 0x16 && rem > 0; i++) {
            if (HasFlag(i)) rem--;
        }
        cnt = 0;
        for (; i < 0x16 && cnt < 6; i++) {
            if (HasFlag(i)) {
                out[cnt] = i;
                cnt++;
            }
        }
        ret = cnt;
        for (j = cnt; j < 6; j++)
            out[j] = -1;
    }
    return ret;
}

static inline char *ItemName(int id)
{
    id -= 400;
    return lbl_802F7050[id];
}

static inline int MemberValid(int idx)
{
    Party *p = &fn_80135598()->party;
    int ok = 0;

    if (p != NULL && idx >= 0 && idx < 5 && p->mem[idx].b14 >= 0) {
        ok = 1;
    }
    return ok;
}

void fn_8013A818(Req *r)
{
    int idx;
    char *str = NULL;
    Member *m = fn_80135598()->party.mem;
    int flag;

    if (r == NULL) return;
    if (m == NULL) return;
    idx = r->idx;
    flag = idx >= 3;
    if (MemberValid(idx)) {
        str = ItemName(m[r->idx].id);
    }
    if (str == NULL) {
        str = "\n";
    }
    fn_8012F458(flag);
    fn_8012F468(str);
}

void fn_80134668(s8 n) {
    switch (n) {
    case 0:
        fn_801D68C4(lbl_80346EFC, 0x15);
        break;
    case 1:
        fn_801D68C4(lbl_80346EFC, 0x16);
        break;
    case 2:
        fn_801D68C4(lbl_80346EFC, 0x17);
        break;
    case 3:
        fn_801D68C4(lbl_80346EFC, 0x18);
        break;
    case 4:
        fn_801D68C4(lbl_80346EFC, 0x19);
        break;
    case 5:
        fn_801D68C4(lbl_80346EFC, 0x1a);
        break;
    case 6:
        fn_801D68C4(lbl_80346EFC, 0x1b);
        break;
    case 7:
        fn_801D68C4(lbl_80346EFC, 0x1c);
        break;
    case 8:
        fn_801D68C4(lbl_80346EFC, 0x1d);
        break;
    case 9:
        fn_801D68C4(lbl_80346EFC, 0x1e);
        break;
    default:
        fn_801D68C4(lbl_80346EFC, 0x15);
        break;
    }
}

static inline void Clear(void **p, s8 *a, s8 *b, s8 *c) {
    s32 i;
    if (p != NULL && a != NULL && b != NULL && c != NULL) {
        for (i = 0; i < 6; i++) {
            p[i] = NULL;
            a[i] = -1;
            b[i] = -1;
            c[i] = 0;
        }
    }
}


static inline s32 Bits(s8 *c) {
    s32 r = 0;
    s32 i;
    if (c != NULL) {
        for (i = 5; i >= 0; i--) {
            r <<= 1;
            r |= c[i];
        }
    }
    return r;
}

static inline void Set(CrewData *tbl, void **p, s8 *a, s8 *b, s8 *c, s8 *src, s32 i, s32 a0) {
    s32 id = 0x16;
    if (InRange(i, 6)) {
        id = src[i];
    }
    if (InRange(id, 0x16)) {
        CrewData *e = &tbl[id];
        s32 v = 100;
        p[i] = e;
        if (e != NULL) {
            v = e->cost;
        }
        a[i] = v;
        b[i] = 12;
        c[i] = fn_80136C14(src, i, a0) != 0;
    }
}

void fn_801375A0(s32 a0, s32 a1, s8 *src) {
    CrewData *tbl = lbl_802D8E64;
    void *ptrs[6];
    s8 a[6];
    s8 b[6];
    s8 c[6];
    s32 bits;
    s32 i;
    Clear(ptrs, a, b, c);
    for (i = 0; i < 6; i++) {
        Set(tbl, ptrs, a, b, c, src, i, a0);
    }
    bits = Bits(c);
    fn_8012E4FC(ptrs);
    fn_8012E498(a);
    fn_8012E434(b);
    fn_8012E424(bits);
    fn_8012E570(a1);
}
/* fn_801298CC's records (4 bytes each). */
typedef struct {
    s16 kind;
    s16 x2;
} Cmd_8013A8FC;

extern Cmd_8013A8FC* fn_801298CC(void);

inline s32 PartyCount_8013A8FC(void) {
    s32 i = 0;
    s8* p = fn_80135598()->order;
    if (p != NULL) {
        for (i = 0; i < 4; i++) {
            if (p[i] < 0) {
                break;
            }
        }
    }
    return i;
}

inline s32 Valid_8013A8FC(Party* p, s32 m) {
    s32 ok = 0;
    if (p != NULL && m >= 0 && m < 5 && p->mem[m].b14 >= 0) {
        ok = 1;
    }
    return ok;
}

inline s32 Status_8013A8FC(Party* p, s32 m) {
    s32 st = 4;
    if (Valid_8013A8FC(p, m)) {
        st = p->mem[m].b14;
    }
    return st;
}

inline s32 Flag_8013A8FC(void) {
    s32 r = 0;
    Party* p = &fn_80135598()->party;
    if (p != NULL) {
        if (p->b11 >= 2) {
            r = 1;
        }
    }
    return r;
}

inline s32 Find_8013A8FC(s32 m, s32 n) {
    s32 r = -1;
    if (n > 0 && n <= 4) {
        s32 last = n - 1;
        if (last < 4) {
            for (r = 0; r <= last; r++) {
                if (lbl_80308E90[r + 4].a[0] == 4 && m == lbl_80308E90[r + 4].a[2]) {
                    break;
                }
            }
        }
    }
    return r;
}

/* Whether party member i has a pending command of kind 2. */
inline s32 IsReady_8013A8FC(s32 i) {
    s32 ok = 0;
    s32 cnt = PartyCount_8013A8FC();
    if (i >= 0 && i < cnt && fn_801298CC()[i].kind == 2) {
        ok = 1;
    }
    return ok;
}

inline s32 Ready_8013A8FC(void) {
    s32 n = PartyCount_8013A8FC();
    s32 r = 0;
    s32 i;
    for (i = 0; i < n; i++) {
        if (IsReady_8013A8FC(i)) {
            r = 1;
            break;
        }
    }
    return r;
}

static inline s32 Bits4(s8 *c) {
    s32 r = 0;
    s32 i;
    if (c != NULL) {
        for (i = 3; i >= 0; i--) {
            r <<= 1;
            r |= c[i];
        }
    }
    return r;
}

inline void Set_8013A8FC(Party* party, Member* m, void** ptrs, s8* a, s8* b, s8* c, s32 i, s32 lim, s32 found) {
    if (Valid_8013A8FC(party, i)) {
        Member* e = &m[i];
        s32 v = 100;
        s32 code;
        ptrs[i] = e;
        if (e != NULL) {
            v = e->b1f + e->b20;
        }
        a[i] = v;
        code = -1;
        switch (e->b14) {
        case 0:
            code = 8;
            break;
        case 1:
            code = 9;
            break;
        case 2:
            code = 10;
            break;
        case 3:
            if (Flag_8013A8FC()) {
                code = 0xd;
            } else {
                code = 0xb;
            }
            break;
        }
        b[i] = code;
        c[i] = 0;
        if (a[i] <= lim) {
            s32 avail = 1;
            s32 cnt = PartyCount_8013A8FC();
            s32 idx = Find_8013A8FC(i, cnt);
            if (idx >= 0 && idx == cnt) {
                avail = 0;
            }
            if (!avail) {
                switch (Status_8013A8FC(party, i)) {
                case 3:
                    if (found) {
                        c[i] = 1;
                    }
                    break;
                default:
                    c[i] = 1;
                    break;
                }
            }
        }
    }
}

void fn_8013A8FC(s32 lim) {
    s32 found;
    s32 i;
    Party* party;
    Member* m;
    Big* base;
    void* ptrs[6];
    s8 a[6];
    s8 b[6];
    s8 c[6];
    s32 bits;

    base = fn_80135598();
    party = &base->party;
    m = base->party.mem;
    found = Ready_8013A8FC();

    Clear(ptrs, a, b, c);
    for (i = 0; i < 4; i++) {
        Set_8013A8FC(party, m, ptrs, a, b, c, i, lim, found);
    }
    bits = Bits4(c);
    fn_8012E4FC(ptrs);
    fn_8012E498(a);
    fn_8012E434(b);
    fn_8012E424(bits);
}

static inline void Rec5Clear(s32 i) {
    if (i >= -4 && i < 4) {
        lbl_80308E90[i + 4].a[0] = -1;
        lbl_80308E90[i + 4].a[1] = -1;
        lbl_80308E90[i + 4].a[2] = -1;
        lbl_80308E90[i + 4].a[3] = -1;
        lbl_80308E90[i + 4].a[4] = -1;
    }
}

static inline void Rec5Copy(s32 from, s32 to, s32 d) {
    if (from >= 0 && from < 4 && to >= -4 && to < 0) {
        s32 s = from + 4;
        s32 t = to + 4;
        lbl_80308E90[t] = lbl_80308E90[s];
        if (lbl_80308E90[t].a[4] != -1) {
            lbl_80308E90[t].a[4] += d;
        }
    }
}

static inline s32 MemberKind(s32 v) {
    s32 ok;
    s32 kind;
    Party *arr;
    arr = &fn_80135598()->party;
    kind = 4;
    ok = 0;
    if (arr != 0 && v >= 0 && v < 5 && arr->mem[v].b14 >= 0) {
        ok = 1;
    }
    if (ok != 0) {
        kind = arr->mem[v].b14;
    }
    return kind;
}

void fn_80136848(s32 x, s32 y) {
    s32 d;
    s32 kind;

    if (x >= 0 && x < 4 && y >= -4 && y < 0) {
        if (lbl_80308E90[x + 4].a[0] != 4) {
            Rec5Clear(y);
            return;
        }
        kind = MemberKind(lbl_80308E90[x + 4].a[2]);
        d = y - x;
        if (lbl_80308E90[x + 4].a[4] == -1 || lbl_80308E90[x + 4].a[4] - d < 0 ||
            (kind != 1 && kind != 2)) {
            Rec5Clear(y);
        } else {
            Rec5Copy(x, y, d);
        }
    }
}

void fn_80133750(void)
{
    NumDraw it;
    f32 z;

    it.x = 0x37;
    it.y = 0xC6;
    it.v = lbl_80346F58->x24->v0;
    it.z = -1.2989999f;
    it.scale = 1.0f;
    it.col = 0xFFC8C8C8;
    fn_80133BE0(&it, 12);

    it.x = 0x70;
    it.y = 0xC6;
    it.v = lbl_80346F58->x24->v1;
    it.z = -1.2989999f;
    it.scale = 1.0f;
    it.col = 0xFFC8C8C8;
    fn_80133BE0(&it, 12);

    it.x = 0x94;
    it.y = 0xC6;
    it.v = lbl_80346F58->x24->v2;
    it.z = -1.2989999f;
    it.scale = 1.0f;
    it.col = 0xFFC8C8C8;
    fn_80133BE0(&it, 12);

    it.x = 0x67;
    it.y = 0xFF;
    it.v = lbl_80346F58->x24->v3;
    it.z = -1.2989999f;
    it.scale = 1.0f;
    it.col = 0xFFC8C8C8;
    fn_80133BE0(&it, 12);

    if (lbl_80346F58->x24->msg != 0) {
        z = TextGetZ();
        TextSetZ(-1.2989999f);
        TextPushColor();
        TextSetColor(0xFFC8C8C8);
        TextPrint(0x15, 0xE1, lbl_80346F58->x24->msg);
        TextPopColor(1);
        TextSetZ(z);
    }
}

#ifdef NONMATCHING
extern const CannonData lbl_802D7E4C[40];
extern s32 fn_8021A0FC(s32 i);
extern s32 fn_8021A0DC(s32 id);
extern s16 fn_8021A6E8(Save1568* t, void* b, const CannonData* c);
extern s16 fn_8021A620(Save1568* t, void* b, const CannonData* c);
extern u8 fn_8021A608(Save1568* t, void* b, const CannonData* c);
extern u8 fn_8021A5F0(Save1568* t, void* b, const CannonData* c);

inline void ClearOut(Member* o)
{
    if (o != 0) {
        memset(o, 0, 0x11);
        o->id = -1;
        o->b14 = -1;
        o->b15 = -1;
        o->s16 = 0;
        o->s18 = 0;
        o->s1a = 0;
        o->s1c = 0;
        o->b1e = 0;
        o->b1f = 0;
        o->b20 = 0;
    }
}

void fn_80134D1C(Member* out, Save1568* t, void* b, s32 idx)
{
    if (out != 0) {
        if (t == 0 || b == 0 || fn_8021A0FC(idx) == 0 || fn_8021A0DC(t->s1580[idx]) == 0) {
            ClearOut(out);
        } else {
            const CannonData* info;
            s32 id = t->s1580[idx];
            info = &lbl_802D7E4C[id - 0x190];
            MemCopy(out, info, 0x11);
            out->id = id;
            out->b14 = info->type;
            out->b15 = info->element;
            out->s16 = fn_8021A6E8(t, b, info);
            out->s18 = 0;
            out->s1a = fn_8021A620(t, b, info);
            out->s1c = 0;
            out->b1e = fn_8021A608(t, b, info);
            out->b1f = fn_8021A5F0(t, b, info);
            out->b20 = 0;
        }
    }
}

#endif


static inline s32 NameCount(void) {
    s32 n = 0;
    s8 *p = fn_80135598()->order;
    if (p != NULL) {
        n = 0;
        if (p[0] >= 0) {
            n = 1;
            if (p[1] >= 0) {
                n = 2;
                if (p[2] >= 0) {
                    n = 3;
                    if (p[3] >= 0) {
                        n = 4;
                    }
                }
            }
        }
    }
    return n;
}

static inline s32 Valid(Party *p, s32 a) {
    s32 ok = 0;
    if (p != NULL && a >= 0 && a < 5 && p->mem[a].b14 >= 0) {
        ok = 1;
    }
    return ok;
}

static inline s32 GetX(s32 a) {
    Party *p = &fn_80135598()->party;
    s32 x = -1;
    if (Valid(p, a) != 0) {
        x = p->mem[a].b1e;
    }
    return x;
}

static inline s32 MemSum(Member *m) {
    s32 w = 100;
    if (m != NULL) {
        w = m->b1f + m->b20;
    }
    return w;
}

static inline s32 GetW(s32 a) {
    s32 w = 100;
    Big *base = fn_80135598();
    if (Valid(&base->party, a) != 0) {
        w = MemSum(&base->party.mem[a]);
    }
    return w;
}



#ifdef NONMATCHING
s32 fn_8013A538(s32 a, s32 b, s32 c, s32 d, s32 e) {
    s32 x;
    s32 w;
    s32 lim;
    s32 res;
    s32 t;
    s32 n;
    s32 q;
    s32 ee;
    s32 ff;

    x = GetX(a);
    w = GetW(a);
    lim = NameCount() * 2;
    if (b < 0 || x < 0 || lim <= 0) {
        res = c;
    } else {
        res = lim - 1;
        if (b + x < res) {
            res = b + x;
        }
        t = c + d;
        t = t > 0 ? t : 0;
        if (t < res) {
            res = t;
        }
        if (res < b || res >= lim) {
            res = c;
        }
    }
    n = NameCount();
    t = res;
    if (res > n - 1) {
        t = n - 1;
    }
    q = t - b + 1;
    if (q < 0) {
        q = 0;
    }
    ee = e < 0 ? 0 : e;
    ff = w < 0 ? 0 : w;
    if (q * ff > ee) {
        res = b + ee / ff - 1;
    }
    return res;
}
#endif

#ifdef NONMATCHING
static inline void Shift(s32 i)
{
    s32 m = i;
    for (; i < 8; i++)
        lbl_80346F40->x24->dst[i] = lbl_80346F40->x24->src[i - m];
}

void fn_801300E0(s32* in)
{
    s32 i;
    for (i = 0; i < 8; i++)
        lbl_80346F40->x24->src[i] = in[i];
    Shift(lbl_80346F40->x24->x94);
}
#endif
