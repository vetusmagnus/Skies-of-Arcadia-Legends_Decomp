/* Near miss: fn_801B28D4 of game/unit_80199B9C.c (6.7 KB, the shop's equip/compare window). The
 * instruction stream is 1673 of 1673 long; with registers masked 22 lines are scheduled
 * differently (the member loop's counters, one colour block, the page-2 fn_801B6BB4 calls), and
 * fdiff shows 220 lines in all. Not in the unit, which keeps only matching functions; in the unit
 * it goes right after fn_801B277C.
 *
 * To diff (this file includes the unit and appends the function):
 *
 *   python tools/match/fdiff.py docs/near/fn_801B28D4.c fn_801B28D4
 */
#include "../src/game/unit_80199B9C.c" /* found through -i include */

/* The equip/compare window of the shop: the item's own stats, then per party member whether they
 * can use it and what it changes (page 0: the difference, page 1: the new values in the stat
 * colours, page 2: the item they have on now). Ship items show their four stats instead. */

/* An equipment slot or a stat block: an id, then values from +6 (0x18). */
/* A character's stats, before and after (0x34). */
typedef struct CmpStat { s16 id; s16 x2; s16 col; s16 v[9]; u32 c[7]; } CmpStat;
typedef struct CmpChr { u32 x0; CmpEq eq[2]; CmpStat st[2]; } CmpChr; /* 0x9C */
typedef struct CmpMember { const char* name; s8 id; u8 pad5[0x1f]; } CmpMember; /* 0x24 */
typedef struct CmpInfo {
    u8 pad0[0x35];
    u8 count; /* 0x35 members */
    u8 pad36[2];
    CmpMember m[4]; /* 0x38 */
} CmpInfo;
typedef struct CmpParty { u8 pad0[0x24]; CmpInfo* info; CmpChr* chr; } CmpParty;
typedef struct EqWork { u8 pad0[8]; u32 id; u8 padc[4]; u32 page; } EqWork;

extern s32 fn_801F3FD0(s32 who, s16 id);
extern s32 fn_801C0B88(s16 id, u8 who);
extern void fn_801C1FC0(s16 id, s32 who);
extern const char* fn_801C2CBC(s16 id);
extern void fn_801B4CF0(Task* t);
extern void fn_801B49B0(Task* t);
extern void fn_801B46EC(Task* t);
extern void fn_801B42F8(Task* t);

#define EQ_PARTY ((CmpParty*)lbl_803471B8)
#define EQ_TEXT 0xFF201008
#define EQ_GREY 0x40201008
#define EQ_POS lbl_802B8E4C
/* One stat number at grid position k, plain. */
#define EQ_NUM(val, x, y, k) UiDrawNumberText((x) + EQ_POS[k].x, (y) + EQ_POS[k].y, (val), 0xC004)
/* The same, in the stat's colour. The two float temporaries are the window's x and y, reused the
 * other way round (y holds the column, x the row): that is how the original's registers fall. */
#define EQ_NUM_COL(val, col, ix, iy, k)    \
    {                                       \
        x = (iy) + EQ_POS[k].y;             \
        y = (ix) + EQ_POS[k].x;             \
        v = (val);                          \
        TextSetColor(col);                  \
        UiDrawNumberText(y, x, v, 0xC004);  \
    }
/* A ship stat number at column k. */
#define EQ_SNUM(val, ix, iy, tbl, k, fl) TextPrintNumber((ix) + (tbl)[k], (iy), (val), (fl))
/* The difference between the member's stats with and without the item, signed and coloured. */
#define EQ_DIFF(chr, d, row)                                         \
    {                                                                \
        s16 ix;                                                      \
        s16 iy;                                                      \
        s16 j;                                                       \
        s16 v;                                                       \
        s16 px;                                                      \
        s16 py;                                                      \
                                                                     \
        d[0] = (chr)->st[1].v[0] - (chr)->st[0].v[0];                \
        d[1] = (chr)->st[1].v[1] - (chr)->st[0].v[1];                \
        d[2] = (chr)->st[1].v[2] - (chr)->st[0].v[2];                \
        d[3] = (chr)->st[1].v[3] - (chr)->st[0].v[3];                \
        d[4] = (chr)->st[1].v[4] - (chr)->st[0].v[4];                \
        d[5] = (chr)->st[1].v[5] - (chr)->st[0].v[5];                \
        d[6] = (chr)->st[1].v[6] - (chr)->st[0].v[6];                \
        iy = 60.0f + obj->o.rect[1] + (row);                         \
        ix = obj->o.rect[0];                                         \
        TextPushColor();                                             \
        for (j = 0; j < 7; j++) {                                    \
            v = d[j];                                                \
            py = iy + EQ_POS[j].y;                                   \
            px = ix + EQ_POS[j].x;                                   \
            if (v != 0) {                                            \
                if (v < 0) {                                         \
                    TextSetColor(0xFFA00000);                        \
                    TextPrint(px, py, "-");                          \
                    TextPrintNumber(px, py, (u16)-v, 0xC004);        \
                } else {                                             \
                    TextSetColor(0xFF00A000);                        \
                    TextPrint(px, py, "+");                          \
                    TextPrintNumber(px, py, v, 0xC004);              \
                }                                                    \
            }                                                        \
        }                                                            \
        TextPopColor(1);                                             \
    }
/* The member's stats with the item, each in its colour. */
#define EQ_COL(chr, row)                                             \
    {                                                                \
        s16 iy;                                                      \
        s16 ix;                                                      \
                                                                     \
        iy = 60.0f + obj->o.rect[1] + (row);                         \
        ix = obj->o.rect[0];                                         \
        EQ_NUM_COL((chr)->st[1].v[0], (chr)->st[0].c[0], ix, iy, 0); \
        EQ_NUM_COL((chr)->st[1].v[1], (chr)->st[0].c[1], ix, iy, 1); \
        EQ_NUM_COL((chr)->st[1].v[2], (chr)->st[0].c[2], ix, iy, 2); \
        EQ_NUM_COL((chr)->st[1].v[3], (chr)->st[0].c[3], ix, iy, 3); \
        EQ_NUM_COL((chr)->st[1].v[4], (chr)->st[0].c[4], ix, iy, 4); \
        EQ_NUM_COL((chr)->st[1].v[5], (chr)->st[0].c[5], ix, iy, 5); \
        EQ_NUM_COL((chr)->st[1].v[6], (chr)->st[0].c[6], ix, iy, 6); \
        TextSetColor(EQ_TEXT);                                       \
    }

/* Whether the ship screens show the "can't change here" message instead of the slots. */
static inline s32 fn_801B28D4_locked(void) {
    s32 v;
    switch ((s8)lbl_80310A1C[6]) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 12:
        v = 1;
        break;
    default:
        if (lbl_8030B7F4.b1568 == -1) {
            v = 1;
        } else {
            v = 0;
        }
        break;
    }
    return v;
}

void fn_801B28D4(Task* task) {
    extern TextNode* TextPrint(s16 x, s16 y, const char* str);
    MObj* obj = ((MP*)task)->obj;
    f32 z;
    NJS_TEXLIST** tl;
    CmpEq eq;
    CmpEq eq2;
    s16 d1[7];
    s16 d2[7];
    CmpChr* chr;
    u32 i;
    f32 y;
    f32 x;
    s16 ix;
    s16 iy;
    s16 v;

    z = TextGetZ();
    TextPushColor();
    TextSetColor(EQ_TEXT);
    tl = (NJS_TEXLIST**)&menu_sprites.texlist8;
    UiLayoutDraw(tl, lbl_802B717C[obj->h52].parts, lbl_802B717C[obj->h52].count, obj->o.rect, obj->o.z, 1.0f, 1.0f);
    UiLayoutDrawPart(tl, (LayoutPart*)lbl_802B719C, 1, &obj->o.rect[2], obj->o.z, obj->o.alpha, 1.0f, obj->h52);
    TextSetZ(-27.5f + obj->o.z);
    TextPrint(44.0f + obj->o.rect[0], 4.0f + obj->o.rect[1], fn_801C2CBC(obj->h56));
    TextPrint(86.0f + obj->o.rect[0], 31.0f + obj->o.rect[1], (const char*)lbl_802EC04C[6]);
    TextPrintNumber(206.0f + obj->o.rect[0], 31.0f + obj->o.rect[1], fn_801F452C(obj->h56), 0xC002);
    switch (obj->h52) {
    case 0:
        fn_801B6BB4(obj, obj->o.rect, obj->h56, -1, 0x12, 4, obj->o.alpha);
        fn_801C2E48(&eq, obj->h56);
        TextSetColor(EQ_TEXT);
        x = obj->o.rect[0];
        y = 31.0f + obj->o.rect[1];
        EQ_NUM(eq.v[0], x, y, 0);
        EQ_NUM(eq.v[1], x, y, 1);
        EQ_NUM(eq.v[2], x, y, 2);
        EQ_NUM(eq.v[3], x, y, 3);
        EQ_NUM(eq.v[4], x, y, 4);
        EQ_NUM(eq.v[5], x, y, 5);
        EQ_NUM(eq.v[6], x, y, 6);
        if (obj->h56 != ((EqWork*)task->work)->id) {
            ((EqWork*)task->work)->id = obj->h56;
            for (i = 0; i < EQ_PARTY->info->count; i++) {
                fn_801C1FC0(obj->h56, (u16)i);
            }
        }
        for (i = 0; i < EQ_PARTY->info->count; i++) {
            switch (((EqWork*)task->work)->page) {
            case 0:
                if (fn_801F3FD0(EQ_PARTY->info->m[i].id, obj->h56)) {
                    TextSetColor(EQ_TEXT);
                    TextPrint(64.0f + obj->o.rect[0], 60.0f + obj->o.rect[1] + (f32)(i * 25), EQ_PARTY->info->m[i].name);
                    chr = &EQ_PARTY->chr[i];
                    if (chr->st[0].id == -1) {
                        EQ_DIFF(chr, d1, (f32)(i * 25));
                    } else if (fn_801C0B88(obj->h56, i)) {
                        TextPrint(288.0f + obj->o.rect[0], 60.0f + obj->o.rect[1] + (f32)(i * 25),
                                  (const char*)lbl_802EC04C[2]);
                    } else {
                        chr = &EQ_PARTY->chr[i];
                        EQ_DIFF(chr, d2, (f32)(i * 25));
                    }
                } else {
                    TextSetColor(EQ_GREY);
                    TextPrint(64.0f + obj->o.rect[0], 60.0f + obj->o.rect[1] + (f32)(i * 25), EQ_PARTY->info->m[i].name);
                    TextPrint(288.0f + obj->o.rect[0], 60.0f + obj->o.rect[1] + (f32)(i * 25),
                              (const char*)lbl_802EC04C[1]);
                }
                break;
            case 1:
                if (fn_801F3FD0(EQ_PARTY->info->m[i].id, obj->h56)) {
                    TextSetColor(EQ_TEXT);
                    TextPrint(64.0f + obj->o.rect[0], 60.0f + obj->o.rect[1] + (f32)(i * 25), EQ_PARTY->info->m[i].name);
                    chr = &EQ_PARTY->chr[i];
                    if (chr->st[0].id == -1) {
                        EQ_COL(chr, (f32)(i * 25));
                    } else if (fn_801C0B88(obj->h56, i)) {
                        TextPrint(288.0f + obj->o.rect[0], 60.0f + obj->o.rect[1] + (f32)(i * 25),
                                  (const char*)lbl_802EC04C[2]);
                    } else {
                        chr = &EQ_PARTY->chr[i];
                        EQ_COL(chr, (f32)(i * 25));
                    }
                } else {
                    TextSetColor(EQ_GREY);
                    TextPrint(64.0f + obj->o.rect[0], 60.0f + obj->o.rect[1] + (f32)(i * 25), EQ_PARTY->info->m[i].name);
                    TextPrint(288.0f + obj->o.rect[0], 60.0f + obj->o.rect[1] + (f32)(i * 25),
                              (const char*)lbl_802EC04C[1]);
                }
                break;
            case 2:
                if (fn_801F3FD0(EQ_PARTY->info->m[i].id, obj->h56)) {
                    TextSetColor(EQ_TEXT);
                    fn_801B6BB4(obj, obj->o.rect, EQ_PARTY->chr[i].st[0].id, -1, 0x12, (s16)(i * 25 + 60),
                                obj->o.alpha);
                    TextPrint(44.0f + obj->o.rect[0], 60.0f + obj->o.rect[1] + (f32)(i * 25),
                              fn_801C2CBC(EQ_PARTY->chr[i].st[0].id));
                    if (fn_801C0B88(obj->h56, i)) {
                        TextPrint(44.0f + obj->o.rect[0], 60.0f + obj->o.rect[1] + (f32)(i * 25),
                                  fn_801C2CBC(EQ_PARTY->chr[i].st[0].id));
                        TextPrint(288.0f + obj->o.rect[0], 60.0f + obj->o.rect[1] + (f32)(i * 25),
                                  (const char*)lbl_802EC04C[2]);
                    } else {
                        fn_801C2E48(&eq, EQ_PARTY->chr[i].st[0].id);
                        TextSetColor(EQ_TEXT);
                        x = obj->o.rect[0];
                        y = 60.0f + obj->o.rect[1] + (f32)(i * 25);
                        EQ_NUM(eq.v[0], x, y, 0);
                        EQ_NUM(eq.v[1], x, y, 1);
                        EQ_NUM(eq.v[2], x, y, 2);
                        EQ_NUM(eq.v[3], x, y, 3);
                        EQ_NUM(eq.v[4], x, y, 4);
                        EQ_NUM(eq.v[5], x, y, 5);
                        EQ_NUM(eq.v[6], x, y, 6);
                    }
                } else {
                    TextSetColor(EQ_GREY);
                    TextPrint(44.0f + obj->o.rect[0], 60.0f + obj->o.rect[1] + (f32)(i * 25),
                              fn_801C2CBC(EQ_PARTY->chr[i].st[0].id));
                    fn_801B6BB4(obj, obj->o.rect, EQ_PARTY->chr[i].st[0].id, -1, 0x12, (s16)(i * 25 + 60),
                                0.7 * obj->o.alpha);
                    TextPrint(288.0f + obj->o.rect[0], 60.0f + obj->o.rect[1] + (f32)(i * 25),
                              (const char*)lbl_802EC04C[1]);
                }
                break;
            }
        }
        break;
    case 2:
        TextSetColor(EQ_TEXT);
        fn_801C2CF4(&eq2, obj->h56);
        ix = obj->o.rect[0];
        iy = 31.0f + obj->o.rect[1];
        EQ_SNUM(eq2.v[0], ix, iy, lbl_802B8EBC, 0, 0xC004);
        EQ_SNUM(eq2.v[3], ix, iy, lbl_802B8EBC, 1, 0xC004);
        EQ_SNUM(eq2.v[5], ix, iy, lbl_802B8EBC, 2, 0xC004);
        EQ_SNUM(eq2.v[6], ix, iy, lbl_802B8EBC, 3, 0xC001);
        fn_801B6BB4(obj, obj->o.rect, obj->h56, -1, 0x10, 4, obj->o.alpha);
        if (fn_801B28D4_locked()) {
            TextPrint(64.0f + obj->o.rect[0], 60.0f + obj->o.rect[1], (const char*)lbl_802EC04C[10]);
        } else {
            switch (((EqWork*)task->work)->page) {
            case 0:
                fn_801B4CF0(task);
                break;
            case 1:
                fn_801B49B0(task);
                break;
            }
        }
        break;
    case 1:
        TextSetColor(EQ_TEXT);
        fn_801C2CF4(&eq2, obj->h56);
        ix = obj->o.rect[0];
        iy = 31.0f + obj->o.rect[1];
        EQ_SNUM(eq2.v[1], ix, iy, lbl_802B8ECC, 0, 0xC004);
        EQ_SNUM(eq2.v[2], ix, iy, lbl_802B8ECC, 1, 0xC004);
        EQ_SNUM(eq2.v[4], ix, iy, lbl_802B8ECC, 2, 0xC004);
        EQ_SNUM(eq2.v[7], ix, iy, lbl_802B8ECC, 3, 0xC004);
        fn_801B6BB4(obj, obj->o.rect, obj->h56, -1, 0x10, 4, obj->o.alpha);
        if (fn_801B28D4_locked()) {
            TextPrint(64.0f + obj->o.rect[0], 60.0f + obj->o.rect[1], (const char*)lbl_802EC04C[10]);
        } else {
            switch (((EqWork*)task->work)->page) {
            case 0:
                fn_801B46EC(task);
                break;
            case 1:
                fn_801B42F8(task);
                break;
            }
        }
        break;
    case 3:
        fn_801B6BB4(obj, obj->o.rect, obj->h56, -1, 0x10, 4, obj->o.alpha);
        break;
    }
    TextPopColor(1);
    TextSetZ(z);
}
