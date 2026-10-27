/* Near miss: fn_801AD1D4 of game/unit_80199B9C.c (10,448 bytes, the stat-comparison windows of the
 * shop). The instruction stream matches (2612 of 2612 with registers masked); 433 lines differ in
 * register numbers only. Not in the unit, which keeps only matching functions.
 *
 * The function reaches its tables through the file's .rodata base, so the file's data has to be
 * defined in C, first in .rodata (see docs/matching.md). To diff:
 *
 *   python tools/match/gen_rodata.py 802B6A18 802B8EDC tools/match/rodata_80199B9C.py \
 *       > build/rodata_80199B9C.c
 *   XF="-i build" python tools/match/fdiff.py docs/near/fn_801AD1D4.c fn_801AD1D4
 *
 * In the unit it goes after the data (with the unit's TextPrint prototype, s16 coordinates). */
#include "types.h"
#include "game/task.h"
#include "game/uiobj.h"
#include "game/sprite.h"
#include "game/text.h"
#include "ninja.h"

typedef struct ShopCmpPos {
    f32 x, y;
} ShopCmpPos;

/* Types the generated data uses (as in the unit). */
typedef struct {
    LayoutPart* parts;
    u32 count;
} LayoutDef;
typedef struct {
    LayoutPart* parts; /* 0x00 */
    u16 pad4;
    u16 flag6;         /* 0x06 */
    u32 pad8, padC;
} AnimDef;
typedef struct { void* parts; u32 count; } LT;

#include "rodata_80199B9C.c"

typedef struct ShopMObj {
    UiObj o;
    const char* text;
    u16 h50, h52, h54, h56;
} ShopMObj;

/* An equipment slot: the item and the stats it gives (0x18). */
typedef struct CmpEq {
    s16 id;
    s16 x2;
    s16 col; /* colour index (lbl_802B8E34) */
    s16 v[9];
} CmpEq;
/* A character's stats with an item applied, plus a colour per stat (0x34). */
typedef struct CmpStat {
    s16 id;
    s16 x2;
    s16 col;
    s16 v[9];
    u32 c[7];
} CmpStat;
typedef struct CmpShipStat {
    s16 id;
    s16 x2;
    s16 col;
    s16 v[9];
    u32 c[9];
} CmpShipStat;
typedef struct CmpChr {
    u32 x0;
    CmpEq eq[2];     /* 0x04 */
    CmpStat st[2];   /* 0x34 */
} CmpChr;            /* 0x9C */
typedef struct CmpShip {
    CmpShipStat st[2]; /* 0x00 */
    CmpEq eq[2];       /* 0x78 */
} CmpShip;             /* 0xA8 */
typedef struct CmpData {
    CmpChr chr[4];   /* 0x000 */
    CmpShip ship[4]; /* 0x270 */
} CmpData;
typedef struct CmpMember {
    const char* name;
    u8 pad4[0x20];
} CmpMember;
typedef struct CmpInfo {
    u8 pad0[0xc];
    u8 eqd[4];         /* 0x0C */
    u8 pad10[0x28];
    CmpMember m[4];    /* 0x38 */
    const char* ship;  /* 0xC8 */
} CmpInfo;
typedef struct CmpParty {
    u8 pad0[0x24];
    CmpInfo* info; /* 0x24 */
    CmpData* data; /* 0x28 */
} CmpParty;
extern CmpParty* lbl_803471B8;
typedef struct CmpWork {
    u8 pad0[8];
    u32 blink; /* 0x08 */
    u32 timer; /* 0x0C */
    u32 mode;  /* 0x10 */
} CmpWork;
typedef struct CmpTask {
    u8 pad0[0x24];
    CmpWork* work;   /* 0x24 */
    ShopMObj* obj;   /* 0x28 */
    ShopMObj* obj2;  /* 0x2C */
} CmpTask;

extern u32 lbl_802EC04C[13];
extern void fn_801B6BB4(void* ui, f32* pos, s16 id, s32 colour, s32 c, s32 d, f32 alpha);
extern const char* fn_801C2CBC(s16 id);
void UiDrawNumberText(s32 value, s32 digits, f32 x, f32 y);
s32 UiLayoutDraw(NJS_TEXLIST** texlists, LayoutPart* parts, u32 count, f32* pos, f32 z, f32 a, f32 b);

#define CMP_TEXT 0xFF201008
#define CMP_POS lbl_802B8E4C

/* One stat number at a grid position, plain. */
#define CMP_NUM(val, x, y, k) UiDrawNumberText((val), 0xC004, (x) + CMP_POS[k].x, (y) + CMP_POS[k].y)
/* The same, in the stat's colour. */
#define CMP_NUM_COL(val, col, ix, iy, k) \
    {                                       \
        cy = (iy) + CMP_POS[k].y;           \
        cx = (ix) + CMP_POS[k].x;           \
        v = (val);                          \
        TextSetColor(col);                  \
        UiDrawNumberText(v, 0xC004, cx, cy); \
    }
#define PARTY lbl_803471B8
/* The colour code reaches a ship through the data pointer advanced by whole ships, so that the
 * ship's fields sit at +0x270 from it (the original keeps data + who * 0xA8 in a register). */
#define CMP_SHIP_BASE(who) ((CmpData*)((CmpShip*)PARTY->data + (who)))
#define CMP_SHIP_X1 lbl_802B8EBC
#define CMP_SHIP_X2 lbl_802B8ECC

/* A ship stat number at column k, plain (ix is an s16, iy the row). */
#define CMP_SNUM(val, ix, iy, tbl, k, fl) TextPrintNumber((ix) + (tbl)[k], (iy), (val), (fl))
/* The same, in the stat's colour. */
#define CMP_SNUM_COL(val, col, ix, iy, tbl, k)        \
    {                                                  \
        cx = (ix) + (tbl)[k];                          \
        v = (val);                                     \
        TextSetColor(col);                             \
        UiDrawNumberText(v, 0xC004, cx, (iy));         \
    }
/* The two blinking arrows of the "new item" windows. */
#define CMP_ARROWS(t, p)                                                                       \
    {                                                                                          \
        UiLayoutDraw((NJS_TEXLIST**)&menu_sprites.texlist8, (LayoutPart*)lbl_802B7140, 2, (t)->obj->o.rect, \
                     -4550.0f, 1.0f, 1.0f);                                                    \
        if ((t)->work->timer <= 24) {                                                          \
            (p)[0] = (t)->obj->o.rect[0];                                                      \
            (p)[1] = (t)->obj->o.rect[1] + (t)->work->blink;                                   \
            UiLayoutDraw((NJS_TEXLIST**)&menu_sprites.texlist8, (LayoutPart*)lbl_802B7168, 1, (p), -4550.0f, \
                         1.0f, 1.0f);                                                          \
        }                                                                                      \
        (t)->work->timer++;                                                                    \
        if ((t)->work->timer >= 30) {                                                          \
            (t)->work->timer = 0;                                                              \
        }                                                                                      \
        (t)->work->blink = (t)->work->timer / 2;                                               \
    }

void fn_801AD1D4(CmpTask* t) {
    f32 cy;
    s16 iy;

    TextSetZ(-27.5f + t->obj->o.z);
    switch (t->obj->h54) {
    case 0:
        TextSetColor(CMP_TEXT);
        TextPrint(44.0f + t->obj->o.x, 5.0f + t->obj->o.y, PARTY->info->m[t->obj->h56].name);
        if (PARTY->info->eqd[t->obj->h56] == 0) {
            f32 y;
            f32 x;
            CmpStat* st;

            y = 31.0f + t->obj->o.y;
            x = t->obj->o.x - 14.0f;
            st = &PARTY->data->chr[t->obj->h56].st[0];
            CMP_NUM(st->v[0], x, y, 7);
            CMP_NUM(st->v[1], x, y, 8);
            CMP_NUM(st->v[2], x, y, 9);
            CMP_NUM(st->v[3], x, y, 10);
            CMP_NUM(st->v[4], x, y, 11);
            CMP_NUM(st->v[5], x, y, 12);
            CMP_NUM(st->v[6], x, y, 13);
        } else if (t->work->mode == 1) {
            s16 ix;
            s16 iy;
            CmpChr* chr;
            f32 cx;
            s16 v;

            chr = &PARTY->data->chr[t->obj->h56];
            iy = 31.0f + t->obj->o.y;
            ix = t->obj->o.x - 14.0f;
            CMP_NUM_COL(chr->st[0].v[0], chr->st[1].c[0], ix, iy, 7);
            CMP_NUM_COL(chr->st[0].v[1], chr->st[1].c[1], ix, iy, 8);
            CMP_NUM_COL(chr->st[0].v[2], chr->st[1].c[2], ix, iy, 9);
            CMP_NUM_COL(chr->st[0].v[3], chr->st[1].c[3], ix, iy, 10);
            CMP_NUM_COL(chr->st[0].v[4], chr->st[1].c[4], ix, iy, 11);
            CMP_NUM_COL(chr->st[0].v[5], chr->st[1].c[5], ix, iy, 12);
            CMP_NUM_COL(chr->st[0].v[6], chr->st[1].c[6], ix, iy, 13);
            TextSetColor(CMP_TEXT);
        } else {
            CmpChr* chr;
            s16 d[7];
            s16 j;
            s16 ix;
            s16 px;
            s16 py;
            s16 v;

            chr = &PARTY->data->chr[t->obj->h56];
            d[0] = chr->st[0].v[0] - chr->st[1].v[0];
            d[1] = chr->st[0].v[1] - chr->st[1].v[1];
            d[2] = chr->st[0].v[2] - chr->st[1].v[2];
            d[3] = chr->st[0].v[3] - chr->st[1].v[3];
            d[4] = chr->st[0].v[4] - chr->st[1].v[4];
            d[5] = chr->st[0].v[5] - chr->st[1].v[5];
            d[6] = chr->st[0].v[6] - chr->st[1].v[6];
            iy = 31.0f + t->obj->o.y;
            ix = t->obj->o.x - 14.0f;
            TextPushColor();
            for (j = 0; j < 7; j++) {
                v = d[j];
                py = iy + CMP_POS[7 + j].y;
                px = ix + CMP_POS[7 + j].x;
                if (v != 0) {
                    if (v < 0) {
                        TextSetColor(0xFFA00000);
                        TextPrint(px, py, "-");
                        TextPrintNumber(px, py, (u16)-v, 0xC004);
                    } else {
                        TextSetColor(0xFF00A000);
                        TextPrint(px, py, "+");
                        TextPrintNumber(px, py, v, 0xC004);
                    }
                }
            }
            TextPopColor(1);
        }
        TextSetColor(CMP_TEXT);
        if (PARTY->data->chr[t->obj->h56].eq[0].id == -1) {
            TextPrint(44.0f + t->obj2->o.x, 5.0f + t->obj2->o.y, (const char*)lbl_802EC04C[0]);
        } else {
            TextPrint(44.0f + t->obj2->o.x, 5.0f + t->obj2->o.y, fn_801C2CBC(PARTY->data->chr[t->obj->h56].eq[0].id));
            fn_801B6BB4(t->obj2, &t->obj2->o.x, PARTY->data->chr[t->obj->h56].eq[0].id,
                        lbl_802B8E34[PARTY->data->chr[t->obj->h56].st[0].col], 10, 6, t->obj2->o.alpha);
        }
        {
            f32 x;
            f32 y;
            CmpEq* eq;

            y = 31.0f + t->obj2->o.y;
            x = t->obj2->o.x - 14.0f;
            eq = &PARTY->data->chr[t->obj->h56].eq[0];
            CMP_NUM(eq->v[0], x, y, 7);
            CMP_NUM(eq->v[1], x, y, 8);
            CMP_NUM(eq->v[2], x, y, 9);
            CMP_NUM(eq->v[3], x, y, 10);
            CMP_NUM(eq->v[4], x, y, 11);
            CMP_NUM(eq->v[5], x, y, 12);
            CMP_NUM(eq->v[6], x, y, 13);
        }
        break;
    case 1:
        TextSetColor(CMP_TEXT);
        TextPrint(44.0f + t->obj->o.x, 5.0f + t->obj->o.y, PARTY->info->m[t->obj->h56].name);
        if (PARTY->info->eqd[t->obj->h56] == 0) {
            if (t->work->mode == 1) {
                CmpChr* chr;
                s16 ix;
                s16 iy;
                f32 cx;
                s16 v;

                chr = &PARTY->data->chr[t->obj->h56];
                iy = 31.0f + t->obj->o.y;
                ix = t->obj->o.x - 14.0f;
                CMP_NUM_COL(chr->st[1].v[0], chr->st[0].c[0], ix, iy, 7);
                CMP_NUM_COL(chr->st[1].v[1], chr->st[0].c[1], ix, iy, 8);
                CMP_NUM_COL(chr->st[1].v[2], chr->st[0].c[2], ix, iy, 9);
                CMP_NUM_COL(chr->st[1].v[3], chr->st[0].c[3], ix, iy, 10);
                CMP_NUM_COL(chr->st[1].v[4], chr->st[0].c[4], ix, iy, 11);
                CMP_NUM_COL(chr->st[1].v[5], chr->st[0].c[5], ix, iy, 12);
                CMP_NUM_COL(chr->st[1].v[6], chr->st[0].c[6], ix, iy, 13);
                TextSetColor(CMP_TEXT);
            } else {
                CmpChr* chr;
                s16 d[7];
                s16 ix;
                s16 j;
                s16 py;
                s16 v;
                s16 px;

                chr = &PARTY->data->chr[t->obj->h56];
                d[0] = chr->st[1].v[0] - chr->st[0].v[0];
                d[1] = chr->st[1].v[1] - chr->st[0].v[1];
                d[2] = chr->st[1].v[2] - chr->st[0].v[2];
                d[3] = chr->st[1].v[3] - chr->st[0].v[3];
                d[4] = chr->st[1].v[4] - chr->st[0].v[4];
                d[5] = chr->st[1].v[5] - chr->st[0].v[5];
                d[6] = chr->st[1].v[6] - chr->st[0].v[6];
                iy = 31.0f + t->obj->o.y;
                ix = t->obj->o.x - 14.0f;
                TextPushColor();
                for (j = 0; j < 7; j++) {
                    v = d[j];
                    py = iy + CMP_POS[7 + j].y;
                    px = ix + CMP_POS[7 + j].x;
                    if (v != 0) {
                        if (v < 0) {
                            TextSetColor(0xFFA00000);
                            TextPrint(px, py, "-");
                            TextPrintNumber(px, py, (u16)-v, 0xC004);
                        } else {
                            TextSetColor(0xFF00A000);
                            TextPrint(px, py, "+");
                            TextPrintNumber(px, py, v, 0xC004);
                        }
                    }
                }
                TextPopColor(1);
            }
            fn_801B6BB4(t->obj2, &t->obj2->o.x, PARTY->data->chr[t->obj->h56].eq[1].id, -1, 10, 6, t->obj2->o.alpha);
        } else {
            f32 x;
            f32 y;
            CmpStat* st;

            y = 31.0f + t->obj->o.y;
            x = t->obj->o.x - 14.0f;
            st = &PARTY->data->chr[t->obj->h56].st[1];
            CMP_NUM(st->v[0], x, y, 7);
            CMP_NUM(st->v[1], x, y, 8);
            CMP_NUM(st->v[2], x, y, 9);
            CMP_NUM(st->v[3], x, y, 10);
            CMP_NUM(st->v[4], x, y, 11);
            CMP_NUM(st->v[5], x, y, 12);
            CMP_NUM(st->v[6], x, y, 13);
            fn_801B6BB4(t->obj2, &t->obj2->o.x, PARTY->data->chr[t->obj->h56].eq[0].id,
                        lbl_802B8E34[PARTY->data->chr[t->obj->h56].st[1].col], 10, 6, t->obj2->o.alpha);
        }
        TextSetColor(CMP_TEXT);
        if (PARTY->data->chr[t->obj->h56].eq[1].id == -1) {
            TextPrint(44.0f + t->obj2->o.x, 5.0f + t->obj2->o.y, (const char*)lbl_802EC04C[0]);
        } else {
            TextPrint(44.0f + t->obj2->o.x, 5.0f + t->obj2->o.y, fn_801C2CBC(PARTY->data->chr[t->obj->h56].eq[1].id));
        }
        {
            f32 x;
            f32 y;
            CmpEq* eq;

            y = 31.0f + t->obj2->o.y;
            x = t->obj2->o.x - 14.0f;
            eq = &PARTY->data->chr[t->obj->h56].eq[1];
            CMP_NUM(eq->v[0], x, y, 7);
            CMP_NUM(eq->v[1], x, y, 8);
            CMP_NUM(eq->v[2], x, y, 9);
            CMP_NUM(eq->v[3], x, y, 10);
            CMP_NUM(eq->v[4], x, y, 11);
            CMP_NUM(eq->v[5], x, y, 12);
            CMP_NUM(eq->v[6], x, y, 13);
        }
        {
            f32 p[2];

            CMP_ARROWS(t, p);
        }
        break;
    case 2:
        TextSetColor(CMP_TEXT);
        TextPrint(38.0f + t->obj->o.x, 5.0f + t->obj->o.y, PARTY->info->ship);
        if (PARTY->info->eqd[t->obj->h56] == 0) {
            s16 ix;
            s16 iy;
            CmpShipStat* shs;

            ix = t->obj->o.x - 10.0f;
            iy = 31.0f + t->obj->o.y;
            shs = &PARTY->data->ship[t->obj->h56].st[0];
            CMP_SNUM(shs->v[1], ix, iy, CMP_SHIP_X2, 4, 0xC004);
            CMP_SNUM(shs->v[2], ix, iy, CMP_SHIP_X2, 5, 0xC004);
            CMP_SNUM(shs->v[4], ix, iy, CMP_SHIP_X2, 6, 0xC004);
            CMP_SNUM(shs->v[7], ix, iy, CMP_SHIP_X2, 7, 0xC004);
        } else {
            CmpData* sd;
            s16 ix;
            s16 iy;
            f32 cx;
            s16 v;

            sd = CMP_SHIP_BASE(t->obj->h56);
            ix = t->obj->o.x - 10.0f;
            iy = 31.0f + t->obj->o.y;
            CMP_SNUM_COL(sd->ship[0].st[0].v[1], sd->ship[0].st[1].c[1], ix, iy, CMP_SHIP_X2, 4);
            CMP_SNUM_COL(sd->ship[0].st[0].v[2], sd->ship[0].st[1].c[2], ix, iy, CMP_SHIP_X2, 5);
            CMP_SNUM_COL(sd->ship[0].st[0].v[4], sd->ship[0].st[1].c[4], ix, iy, CMP_SHIP_X2, 6);
            CMP_SNUM_COL(sd->ship[0].st[0].v[7], sd->ship[0].st[1].c[7], ix, iy, CMP_SHIP_X2, 7);
        }
        TextSetColor(CMP_TEXT);
        fn_801B6BB4(t->obj2, &t->obj2->o.x, PARTY->data->ship[t->obj->h56].eq[0].id, -1, 7, 6, t->obj2->o.alpha);
        TextPrint(38.0f + t->obj2->o.x, 5.0f + t->obj2->o.y, fn_801C2CBC(PARTY->data->ship[t->obj->h56].eq[0].id));
        {
            s16 ix;
            s16 iy;
            CmpEq* eq;

            iy = 31.0f + t->obj2->o.y;
            ix = t->obj2->o.x - 13.0f;
            eq = &PARTY->data->ship[t->obj->h56].eq[0];
            CMP_SNUM(eq->v[0], ix, iy, CMP_SHIP_X1, 4, 0xC004);
            CMP_SNUM(eq->v[3], ix, iy, CMP_SHIP_X1, 5, 0xC004);
            CMP_SNUM(eq->v[5], ix, iy, CMP_SHIP_X1, 6, 0xC004);
            CMP_SNUM(eq->v[6], ix, iy, CMP_SHIP_X1, 7, 0xC001);
        }
        break;
    case 3:
        TextSetColor(CMP_TEXT);
        TextPrint(38.0f + t->obj->o.x, 5.0f + t->obj->o.y, PARTY->info->ship);
        if (PARTY->info->eqd[t->obj->h56] == 0) {
            CmpData* sd;
            s16 ix;
            s16 iy;
            f32 cx;
            s16 v;

            sd = CMP_SHIP_BASE(t->obj->h56);
            ix = t->obj->o.x - 10.0f;
            iy = 31.0f + t->obj->o.y;
            CMP_SNUM_COL(sd->ship[0].st[1].v[1], sd->ship[0].st[0].c[1], ix, iy, CMP_SHIP_X2, 4);
            CMP_SNUM_COL(sd->ship[0].st[1].v[2], sd->ship[0].st[0].c[2], ix, iy, CMP_SHIP_X2, 5);
            CMP_SNUM_COL(sd->ship[0].st[1].v[4], sd->ship[0].st[0].c[4], ix, iy, CMP_SHIP_X2, 6);
            CMP_SNUM_COL(sd->ship[0].st[1].v[7], sd->ship[0].st[0].c[7], ix, iy, CMP_SHIP_X2, 7);
        } else {
            s16 ix;
            s16 iy;
            CmpShipStat* shs;

            ix = t->obj->o.x - 10.0f;
            iy = 31.0f + t->obj->o.y;
            shs = &PARTY->data->ship[t->obj->h56].st[1];
            CMP_SNUM(shs->v[1], ix, iy, CMP_SHIP_X2, 4, 0xC004);
            CMP_SNUM(shs->v[2], ix, iy, CMP_SHIP_X2, 5, 0xC004);
            CMP_SNUM(shs->v[4], ix, iy, CMP_SHIP_X2, 6, 0xC004);
            CMP_SNUM(shs->v[7], ix, iy, CMP_SHIP_X2, 7, 0xC004);
        }
        TextSetColor(CMP_TEXT);
        fn_801B6BB4(t->obj2, &t->obj2->o.x, PARTY->data->ship[t->obj->h56].eq[1].id, -1, 7, 6, t->obj2->o.alpha);
        TextPrint(38.0f + t->obj2->o.x, 5.0f + t->obj2->o.y, fn_801C2CBC(PARTY->data->ship[t->obj->h56].eq[1].id));
        {
            CmpData* sd;
            s16 ix;
            s16 iy;
            f32 cx;
            s16 v;
            s16 px;

            sd = CMP_SHIP_BASE(t->obj->h56);
            iy = 31.0f + t->obj2->o.y;
            ix = t->obj2->o.x - 13.0f;
            CMP_SNUM_COL(sd->ship[0].eq[1].v[0], sd->ship[0].st[0].c[0], ix, iy, CMP_SHIP_X1, 4);
            CMP_SNUM_COL(sd->ship[0].eq[1].v[3], sd->ship[0].st[0].c[3], ix, iy, CMP_SHIP_X1, 5);
            CMP_SNUM_COL(sd->ship[0].eq[1].v[5], sd->ship[0].st[0].c[5], ix, iy, CMP_SHIP_X1, 6);
            v = sd->ship[0].eq[1].v[6];
            px = ix + CMP_SHIP_X1[7];
            TextSetColor(sd->ship[0].st[0].c[6]);
            TextPrintNumber(px, iy, v, 0xC001);
        }
        {
            f32 p[2];

            CMP_ARROWS(t, p);
        }
        break;
    case 4:
        TextSetColor(CMP_TEXT);
        TextPrint(38.0f + t->obj->o.x, 5.0f + t->obj->o.y, PARTY->info->ship);
        if (PARTY->info->eqd[t->obj->h56] == 0) {
            s16 ix;
            s16 iy;
            CmpShipStat* shs;

            ix = t->obj->o.x - 10.0f;
            iy = 31.0f + t->obj->o.y;
            shs = &PARTY->data->ship[t->obj->h56].st[0];
            CMP_SNUM(shs->v[1], ix, iy, CMP_SHIP_X2, 4, 0xC004);
            CMP_SNUM(shs->v[2], ix, iy, CMP_SHIP_X2, 5, 0xC004);
            CMP_SNUM(shs->v[4], ix, iy, CMP_SHIP_X2, 6, 0xC004);
            CMP_SNUM(shs->v[7], ix, iy, CMP_SHIP_X2, 7, 0xC004);
        } else {
            CmpData* sd;
            s16 ix;
            s16 iy;
            f32 cx;
            s16 v;

            sd = CMP_SHIP_BASE(t->obj->h56);
            ix = t->obj->o.x - 10.0f;
            iy = 31.0f + t->obj->o.y;
            CMP_SNUM_COL(sd->ship[0].st[0].v[1], sd->ship[0].st[1].c[1], ix, iy, CMP_SHIP_X2, 4);
            CMP_SNUM_COL(sd->ship[0].st[0].v[2], sd->ship[0].st[1].c[2], ix, iy, CMP_SHIP_X2, 5);
            CMP_SNUM_COL(sd->ship[0].st[0].v[4], sd->ship[0].st[1].c[4], ix, iy, CMP_SHIP_X2, 6);
            CMP_SNUM_COL(sd->ship[0].st[0].v[7], sd->ship[0].st[1].c[7], ix, iy, CMP_SHIP_X2, 7);
        }
        TextSetColor(CMP_TEXT);
        fn_801B6BB4(t->obj2, &t->obj2->o.x, PARTY->data->ship[t->obj->h56].eq[0].id, -1, 7, 6, t->obj2->o.alpha);
        TextPrint(38.0f + t->obj2->o.x, 5.0f + t->obj2->o.y, fn_801C2CBC(PARTY->data->ship[t->obj->h56].eq[0].id));
        {
            s16 ix;
            s16 iy;
            CmpEq* eq;

            iy = 31.0f + t->obj2->o.y;
            ix = t->obj2->o.x - 10.0f;
            eq = &PARTY->data->ship[t->obj->h56].eq[0];
            CMP_SNUM(eq->v[1], ix, iy, CMP_SHIP_X2, 4, 0xC004);
            CMP_SNUM(eq->v[2], ix, iy, CMP_SHIP_X2, 5, 0xC004);
            CMP_SNUM(eq->v[4], ix, iy, CMP_SHIP_X2, 6, 0xC004);
            CMP_SNUM(eq->v[7], ix, iy, CMP_SHIP_X2, 7, 0xC004);
        }
        break;
    case 5:
        TextSetColor(CMP_TEXT);
        TextPrint(38.0f + t->obj->o.x, 5.0f + t->obj->o.y, PARTY->info->ship);
        if (PARTY->info->eqd[t->obj->h56] == 0) {
            CmpData* sd;
            s16 ix;
            s16 iy;
            f32 cx;
            s16 v;

            sd = CMP_SHIP_BASE(t->obj->h56);
            ix = t->obj->o.x - 10.0f;
            iy = 31.0f + t->obj->o.y;
            CMP_SNUM_COL(sd->ship[0].st[1].v[1], sd->ship[0].st[0].c[1], ix, iy, CMP_SHIP_X2, 4);
            CMP_SNUM_COL(sd->ship[0].st[1].v[2], sd->ship[0].st[0].c[2], ix, iy, CMP_SHIP_X2, 5);
            CMP_SNUM_COL(sd->ship[0].st[1].v[4], sd->ship[0].st[0].c[4], ix, iy, CMP_SHIP_X2, 6);
            CMP_SNUM_COL(sd->ship[0].st[1].v[7], sd->ship[0].st[0].c[7], ix, iy, CMP_SHIP_X2, 7);
        } else {
            s16 ix;
            s16 iy;
            CmpShipStat* shs;

            ix = t->obj->o.x - 10.0f;
            iy = 31.0f + t->obj->o.y;
            shs = &PARTY->data->ship[t->obj->h56].st[1];
            CMP_SNUM(shs->v[1], ix, iy, CMP_SHIP_X2, 4, 0xC004);
            CMP_SNUM(shs->v[2], ix, iy, CMP_SHIP_X2, 5, 0xC004);
            CMP_SNUM(shs->v[4], ix, iy, CMP_SHIP_X2, 6, 0xC004);
            CMP_SNUM(shs->v[7], ix, iy, CMP_SHIP_X2, 7, 0xC004);
        }
        TextSetColor(CMP_TEXT);
        fn_801B6BB4(t->obj2, &t->obj2->o.x, PARTY->data->ship[t->obj->h56].eq[1].id, -1, 7, 6, t->obj2->o.alpha);
        TextPrint(38.0f + t->obj2->o.x, 5.0f + t->obj2->o.y, fn_801C2CBC(PARTY->data->ship[t->obj->h56].eq[1].id));
        {
            s16 ix;
            s16 iy;
            CmpEq* eq;

            iy = 31.0f + t->obj2->o.y;
            ix = t->obj2->o.x - 10.0f;
            eq = &PARTY->data->ship[t->obj->h56].eq[1];
            CMP_SNUM(eq->v[1], ix, iy, CMP_SHIP_X2, 4, 0xC004);
            CMP_SNUM(eq->v[2], ix, iy, CMP_SHIP_X2, 5, 0xC004);
            CMP_SNUM(eq->v[4], ix, iy, CMP_SHIP_X2, 6, 0xC004);
            CMP_SNUM(eq->v[7], ix, iy, CMP_SHIP_X2, 7, 0xC004);
        }
        {
            f32 p[2];

            CMP_ARROWS(t, p);
        }
        break;
    }
}
