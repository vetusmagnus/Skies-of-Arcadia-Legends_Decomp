/* fn_801B7624, the shop's sell screen: a near miss (14 diff lines, all registers).
 *
 * Everything but one block matches. In the right-page case (state 6, pad 7) the second page count
 * puts the quotient in r4 where the original has r6, and the list/page in r6/r5 instead of r5/r4;
 * the instruction stream is the same. Tried: the count as an inline taking the tab, the list, the
 * part or the task; the count held in a variable first (u16, s32); the compare's operands swapped,
 * cast or negated; the page/list held in block locals; the case body as an inline; the
 * declaration-order search; decomp-permuter (14k iterations, nothing below the base).
 *
 * Those 14 lines are with the sell screen's view of two declarations: fn_801B93E8 returns s16
 * and fn_801B8F48 takes a u16 id. The unit keeps s32 and s16 (fn_801B11EC and fn_801B8F48 need
 * them; see matching.md), and against it this is 31 lines off. fn_801B94F0/fn_801B952C are
 * inline (defined after fn_801B1B3C, which calls them).
 */
#include "../src/game/unit_80199B9C.c" /* found through -i include */

/* fn_801B7624: the shop's sell screen. The tabs' item lists are counted into the task's tables
 * (t->p30), the list part (parts[8]) shows a tab six rows a page, parts[9] the item's details and
 * parts[2] the quantity window. */
extern void fn_801B914C(ShopTask* t, s32 tab);
extern u32 fn_801B95C8(void* p);
extern void fn_801C0FE8(s16 id, u8 n);

#define SELL_WORK ((ShopWork*)lbl_803471B8->p24)

/* Pages of six rows in a tab. */
static inline u16 SellPages(u16 tab)
{
    u16 n = fn_801B952C(tab);
    return n / 6 + (n % 6 != 0);
}

/* Rows on the list's current page. */
static inline u16 SellRows(ShopList* l)
{
    u16 n = fn_801B952C(l->tab);
    if (n >= (l->page + 1) * 6) {
        return 6;
    }
    return n % 6;
}

/* The sale's price, and the gold the party will have after it. */
static inline void SellSetCost(u32 c)
{
    SELL_WORK->cost = c;
    SELL_WORK->left = SELL_WORK->cost + lbl_8030B7F4.w34c;
    if (SELL_WORK->left >= 99999999) {
        SELL_WORK->left = 999999999;
    }
}

/* Collect a tab's items (the count, then the pointers after it). */
#define SELL_LIST(t, inv, field, out) \
    t->p30->field = fn_801B9810((Ent_801B9810*)((u8*)&lbl_8030B7F4 + (inv)), (Ent_801B9810**)((u8*)t->p30 + (out)), 0x50)

#define SELL_COUNT(t)                                                \
    {                                                                \
        SELL_LIST(t, 0x714, w3cc, 0x3d0);                            \
        SELL_LIST(t, 0x354, w00, 0x4);                               \
        SELL_LIST(t, 0x494, w144, 0x148);                            \
        SELL_LIST(t, 0x5d4, w288, 0x28c);                            \
        t->p30->w510 = fn_801B95C8((u8*)t->p30 + 0x514);             \
    }

/* Close the item's details and go back to choosing a tab. */
#define SELL_LEAVE(t)                                             \
    {                                                             \
        UiObjMoveToX(t->w->parts[9]->obj, 3, 5, 648.0f);          \
        UiObjSetCommand(t->w->parts[9]->obj, 15, 0);              \
        fn_801B6400(0);                                           \
        t->w->state = 7;                                          \
    }

void fn_801B7624(ShopTask* t)
{
    u16 page;
    ShopPart* p;
    ShopPart* q;
    u16 old;
    u16 row;

    switch (t->w->state) {
    case 0:
        *t->w->parts[3]->flag = 1;
        *t->w->parts[5]->flag = 1;
        t->w->parts[7] = (ShopPart*)fn_801B6320(t, -4450.0f);
        t->w->parts[8] = (ShopPart*)fn_801B2310(t);
        t->w->parts[9] = (ShopPart*)fn_801B1A78(t);
        t->w->state = 1;
        t->w->parts[2] = (ShopPart*)fn_801B2678(t, 1);
        *t->w->parts[2]->flag = 1;
        fn_801C09A4();
        fn_801C12C8();
        SELL_COUNT(t);
        break;
    case 1:
        UiObjMoveTo(t->w->parts[7]->obj, 6, 4, 24.0f, 384.0f);
        UiObjSetCommand(t->w->parts[7]->obj, 15, 0);
        UiObjMoveToX(t->w->parts[8]->obj, 6, 4, 240.0f);
        UiObjSetCommand(t->w->parts[8]->obj, 15, 0);
        t->w->state = 2;
        fn_801B914C(t, 0);
        break;
    case 2:
        if (MenuPartsBusy((MenuTask*)t) && !fn_801C09F8(0, 2)) {
            break;
        }
        MenuPartsFinish((MenuTask*)t);
        t->w->state = 3;
        t->w->parts[8]->x38->ha = 1;
        break;
    case 3:
        q = t->w->parts[8];
        if (fn_801C09F8(0, 1)) {
            t->w->state = 15;
            t->w->parts[8]->x38->ha = 0;
            break;
        }
        if (fn_801C09F8(0, 6)) {
            if (fn_801B94F0()) {
                old = q->list->tab;
                fn_801B914C(t, 3);
                if (old != q->list->tab) {
                    MenuPlaySe(4);
                }
            }
            break;
        }
        if (fn_801C09F8(0, 7)) {
            if (fn_801B94F0()) {
                old = q->list->tab;
                fn_801B914C(t, 2);
                if (old != q->list->tab) {
                    MenuPlaySe(4);
                }
            }
            break;
        }
        if (fn_801C09F8(0, 4)) {
            ShopList* l = t->w->parts[8]->list;
            if (fn_801B952C(l->tab) == 0) {
                break;
            }
            q->list->row = SellRows(l) - 1;
            goto pick;
        }
        if (fn_801C09F8(0, 5)) {
            if (fn_801B952C(t->w->parts[8]->list->tab) == 0) {
                break;
            }
            q->list->row = 0;
            goto pick;
        }
        if (!PAD_A) {
            break;
        }
        if (!fn_801B94F0()) {
            t->w->state = 15;
            t->w->parts[8]->x38->ha = 0;
            break;
        }
        if (fn_801B952C(t->w->parts[8]->list->tab)) {
            fn_801C08B4(2);
        pick:
            t->w->state = 4;
            ((ShopMObj*)t->w->parts[9]->obj)->h52 = (u8)fn_801B5868(fn_801B93E8((Game_UNIT*)t));
            break;
        }
        fn_801C08B4(3);
        break;
    case 4:
        UiObjMoveToX(t->w->parts[9]->obj, 3, 4, 328.0f);
        UiObjSetCommand(t->w->parts[9]->obj, 15, 0);
        t->w->state = 5;
        fn_801AB98C((Obj_UNIT0000*)t->w->parts[8]);
        break;
    case 5:
        if (MenuPartsBusy((MenuTask*)t) && !PAD_A) {
            break;
        }
        MenuPartsFinish((MenuTask*)t);
        t->w->state = 6;
        t->w->parts[8]->b19 = 1;
        p = t->w->parts[8];
        p->x38->ha = SellPages(p->list->tab) > 1;
        t->w->parts[8]->list->b1e = 2;
        break;
    case 6:
        p = t->w->parts[8];
        row = p->list->row;
        page = p->list->page;
        if (fn_801C09F8(0, 1)) {
            SELL_LEAVE(t);
            break;
        }
        if (fn_801C09F8(0, 4)) {
            if (p->list->row == 0) {
                SELL_LEAVE(t);
                break;
            }
            p->list->row--;
            goto moved;
        } else if (fn_801C09F8(0, 5)) {
            if (p->list->row == SellRows(t->w->parts[8]->list) - 1) {
                SELL_LEAVE(t);
                break;
            }
            p->list->row++;
        moved:
            p->list->h14 = 0;
            if (p->list->row != row) {
                MenuPlaySe(4);
            }
        } else if (fn_801C09F8(0, 6)) {
            if (p->list->page == 0) {
                p->list->page = SellPages(t->w->parts[8]->list->tab) - 1;
            } else {
                p->list->page--;
            }
            if (page != p->list->page) {
                MenuPlaySe(4);
                p->list->h14 = 0;
                p->list->row = 0;
                p->x38->hc = 0;
            }
        } else if (fn_801C09F8(0, 7)) {
            if (SellPages(t->w->parts[8]->list->tab) == 1) {
                break;
            }
            p->list->page++;
            if (p->list->page > SellPages(t->w->parts[8]->list->tab) - 1) {
                p->list->page = 0;
                p->list->row = 0;
            }
            if (page != p->list->page) {
                MenuPlaySe(4);
                p->list->h14 = 0;
                p->list->row = 0;
                p->x38->hc = 0;
            }
        } else if (PAD_A) {
            t->w->qty = 1;
            if (fn_801B8F48(0, &t->w->qty, fn_801B93E8((Game_UNIT*)t)) != -1) {
                *t->w->parts[2]->flag = 0;
                UiObjMoveToX(t->w->parts[2]->obj, 6, 4, -8.0f);
                UiObjSetCommand(t->w->parts[2]->obj, 15, 3);
                SellSetCost(fn_801B8F48(0, &t->w->qty, fn_801B93E8((Game_UNIT*)t)));
                t->w->state = 8;
                t->w->parts[8]->x38->ha = 0;
                fn_801C08B4(2);
            } else {
                fn_801C08B4(3);
            }
        }
        ((ShopMObj*)t->w->parts[9]->obj)->h52 = (u8)fn_801B5868(fn_801B93E8((Game_UNIT*)t));
        fn_801AB98C((Obj_UNIT0000*)p);
        if ((s16)fn_801B93E8((Game_UNIT*)t) != -1) {
            fn_801B6400((u32)fn_801F48AC(fn_801B93E8((Game_UNIT*)t)));
        } else {
            fn_801B6400(0);
        }
        break;
    case 7:
        if (UiObjIsBusy(t->w->parts[9]->obj) && !fn_801C09F8(0, 1)) {
            break;
        }
        MenuPartsFinish((MenuTask*)t);
        t->w->state = 3;
        t->w->parts[8]->x38->ha = 1;
        t->w->parts[8]->b19 = 0;
        break;
    case 8:
        if (MenuPartsBusy((MenuTask*)t) && !PAD_A) {
            break;
        }
        MenuPartsFinish((MenuTask*)t);
        t->w->state = 9;
        t->w->parts[8]->list->b1e = 3;
        ((ShopMObj*)t->w->parts[8]->obj)->h56 = 1;
        break;
    case 9:
        if (fn_801C09F8(0, 1)) {
            t->w->parts[8]->list->b1e = 2;
            UiObjMoveToX(t->w->parts[2]->obj, 6, 5, -240.0f);
            UiObjSetCommand(t->w->parts[2]->obj, 15, 0);
            t->w->state = 10;
            t->w->qty = 1;
            break;
        }
        if (fn_801C09F8(0, 4)) {
            fn_801B8F48(8, &t->w->qty, fn_801B93E8((Game_UNIT*)t));
        } else if (fn_801C09F8(0, 5)) {
            fn_801B8F48(4, &t->w->qty, fn_801B93E8((Game_UNIT*)t));
        } else if (fn_801C09F8(0, 6)) {
            fn_801B8F48(1, &t->w->qty, fn_801B93E8((Game_UNIT*)t));
        } else if (fn_801C09F8(0, 7)) {
            fn_801B8F48(2, &t->w->qty, fn_801B93E8((Game_UNIT*)t));
        } else if (PAD_A) {
            t->w->state = 11;
            t->w->parts[8]->list->b1e = 0xFF;
            UiObjMoveToX(t->w->parts[9]->obj, 6, 5, 648.0f);
            UiObjSetCommand(t->w->parts[9]->obj, 15, 0);
            MenuPlaySe(2);
            fn_801C08B4(0x19);
            fn_801C0814(t);
        }
        t->w->item = fn_801B93E8((Game_UNIT*)t);
        SellSetCost(fn_801B8F48(0, &t->w->qty, fn_801B93E8((Game_UNIT*)t)));
        fn_801A6A88((Task_801A6A88*)t, 8, t->w->parts[8]->list->row * 24 + 12);
        break;
    case 10:
        if (MenuPartsBusy((MenuTask*)t) && !fn_801C09F8(0, 1)) {
            break;
        }
        MenuPartsFinish((MenuTask*)t);
        p = t->w->parts[8];
        p->x38->ha = SellPages(p->list->tab) > 1;
        *t->w->parts[2]->flag = 1;
        t->w->state = 6;
        ((ShopMObj*)t->w->parts[8]->obj)->h56 = 0;
        break;
    case 11:
        fn_801B8E68((Task_801B8E68*)t);
        if (t->w->cost != 0) {
            break;
        }
        if (UiObjIsBusy(t->w->parts[9]->obj)) {
            MenuPartsFinish((MenuTask*)t);
        }
        fn_801C0FE8(t->w->item, t->w->qty);
        SELL_COUNT(t);
        if ((s16)fn_801B93E8((Game_UNIT*)t) == -1) {
            ShopList* l = t->w->parts[8]->list;
            if (l->row == 0) {
                if (l->page != 0) {
                    l->page--;
                }
            } else {
                l->row--;
            }
        }
        fn_801B6400(0);
        fn_801B914C(t, 1);
        t->w->state = 12;
        fn_801C08B4(0x18);
        t->w->step = 0;
        break;
    case 12:
        t->w->state = 13;
        break;
    case 13:
        UiObjMoveToX(t->w->parts[2]->obj, 6, 5, -240.0f);
        UiObjSetCommand(t->w->parts[2]->obj, 15, 0);
        UiObjMoveToX(t->w->parts[9]->obj, 6, 5, 648.0f);
        UiObjSetCommand(t->w->parts[9]->obj, 15, 0);
        t->w->state = 14;
        t->w->qty = 1;
        break;
    case 14:
        if (MenuPartsBusy((MenuTask*)t)) {
            break;
        }
        *t->w->parts[2]->flag = 1;
        t->w->parts[8]->x38->ha = 1;
        t->w->parts[8]->b19 = 0;
        t->w->state = 3;
        ((ShopMObj*)t->w->parts[8]->obj)->h56 = 0;
        break;
    case 15:
        UiObjMoveTo(t->w->parts[7]->obj, 6, 5, 640.0f, 480.0f);
        UiObjSetCommand(t->w->parts[7]->obj, 15, 0);
        UiObjMoveToX(t->w->parts[8]->obj, 6, 5, 648.0f);
        UiObjSetCommand(t->w->parts[8]->obj, 15, 0);
        t->w->state = 16;
        break;
    case 16:
        if (MenuPartsBusy((MenuTask*)t) && !fn_801C09F8(0, 1)) {
            break;
        }
        MenuPartsFinish((MenuTask*)t);
        MenuPartFree((MenuTask*)t, 9);
        MenuPartFree((MenuTask*)t, 7);
        MenuPartFree((MenuTask*)t, 8);
        MenuPartFree((MenuTask*)t, 2);
        *t->w->parts[3]->flag = 0;
        *t->w->parts[5]->flag = 0;
        t->w->state = 17;
        break;
    case 17:
        t->state = 5;
        break;
    }
}
