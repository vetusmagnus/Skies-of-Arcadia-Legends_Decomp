/* Near misses: fn_801BA9CC of game/unit_80199B9C.c (6.8 KB, the guild's discoveries window: the
 * list, buying a discovery's information, the gold countdown) and fn_801BE608 (the guild-rank
 * test, an `inline` function: inlined into fn_801BA9CC and emitted out of line at the end of the
 * file).
 *
 * fn_801BA9CC: 1712 of 1713 instructions; with registers masked 11/10 lines differ (the entry
 * `mr`, one copy in state 2, the description in state 6 re-extending the id); the register
 * numbering is mostly one swap: the original keeps the task in r29 and the status window's part
 * in r31, we have them the other way round.
 * fn_801BE608: 26/26, 12 lines, two volatile registers swapped.
 *
 * Not in the unit, which keeps only matching functions. To diff (this file includes the unit and
 * appends the code; in the unit it goes after fn_801AC2E4, which calls fn_801BE608 out of line):
 *
 *   python tools/match/fdiff.py docs/near/fn_801BA9CC.c fn_801BA9CC fn_801BE608
 */
#include "../src/game/unit_80199B9C.c" /* found through -i include */

/* The discoveries window of the guild (buying a discovery's information). The record of discovery
 * id is lbl_802ED258[id]; three story-flag blocks of 90 each start at 0xBAE, 0xC08 and 0xC62. */
typedef struct DiscInfo {
    const char* name;  /* 0x00 */
    const char* text;  /* 0x04 */
    const char* text2; /* 0x08 */
    u8 padC[2];
    u8 need2;          /* 0x0E rank 2 from this guild level */
    u8 need1;          /* 0x0F rank 1 from this guild level */
    u8 pad10[0x28 - 0x10];
} DiscInfo;
typedef struct DiscText {
    const char* text;  /* 0x00 */
    const char* text1; /* 0x04 */
    const char* text2; /* 0x08 */
} DiscText;
extern DiscText lbl_802EE040[];

/* A discovery's list as this window keeps it (the count is unsigned here). */
typedef struct DiscBuf {
    u8 pad0[4];
    u16 pages;
    u16 count;
    ShopEntry out[0x30];
} DiscBuf;
typedef struct DiscTask {
    u8 pad0[0x19];
    u8 state;        /* 0x19 */
    u8 pad1a[0xa];
    ShopWork* w;     /* 0x24 */
    u8 pad28[4];
    DiscBuf* buf;    /* 0x2C */
} DiscTask;

extern void fn_801BDAC8(DiscTask* t, u8 mode);

static inline s32 DiscFlag(u32 b) {
    s32 f = (lbl_80310B3C[b >> 5] & (1 << (b & 31))) != 0;

    f = f != 0;
    return f;
}

/* How much the guild (at level lv) knows about discovery id: 2 or 1, 0 below, -1 none. */
static inline s8 DiscRank(s16 id, u8 lv) {
    s32 r;

    if (id == -1) {
        return -1;
    }
    if (lv >= 24) {
        return -1;
    }
    r = 0;
    if (lv >= ((DiscInfo*)lbl_802ED258)[id].need2) {
        r = 2;
    } else if (lv >= ((DiscInfo*)lbl_802ED258)[id].need1) {
        r = 1;
    }
    return r;
}

inline s8 fn_801BE608(s16 id) {
    u8 lv = lbl_803473BE;
    s32 r;

    if (id == -1) {
        return -1;
    }
    if (lv >= 24) {
        return -1;
    }
    r = 0;
    if (lv >= ((DiscInfo*)lbl_802ED258)[id].need2) {
        r = 2;
    } else if (lv >= ((DiscInfo*)lbl_802ED258)[id].need1) {
        r = 1;
    }
    return r;
}

/* The text shown for discovery id (once there is one). */
static inline const char* DiscTextOf(s16 id) {
    u8 lv = lbl_803473BE;

    if (DiscFlag(id + 0xc62)) {
        return lbl_802EE040[id].text;
    }
    if (DiscFlag(id + 0xc08)) {
        if (DiscRank(id, lv) == 2) {
            return lbl_802EE040[id].text;
        }
        if (DiscRank(id, lv) == 1) {
            return lbl_802EE040[id].text1;
        }
    }
    return NULL;
}

static inline const char* DiscDesc(s32 id) {
    if (id == -1) {
        return NULL;
    }
    return DiscTextOf(id);
}

/* 1 found by Vyse, 0 bought, -1 neither (or no discovery). */
static inline s8 DiscStatus(s16 id) {
    s8 r;

    if (id == -1) {
        r = -1;
    } else {
        if (DiscFlag(id + 0xbae)) {
            r = 1;
        } else if (DiscFlag(id + 0xc62)) {
            r = 0;
        } else {
            r = -1;
        }
    }
    return r;
}


/* Show the status window (part 16) for discovery id, or slide it away when it has none.
 * The id goes through an s32 copy: the original re-extends it (extsh) before every status test,
 * which a plain s16 argument doesn't give. */
#define DISC_STATUS(t, id)                             \
    {                                                  \
        ShopPart* sp_ = (t)->w->parts[16];             \
        s32 id_ = (id);                                \
        s8 st_;                                        \
                                                       \
        if (sp_->obj->x == -8.0f) {                    \
            st_ = DiscStatus(id_);                     \
            if (st_ == -1) {                           \
                UiObjMoveToX(sp_->obj, 3, -1, -260.0f); \
                UiObjSetCommand(sp_->obj, 15, 0);      \
            } else {                                   \
                ((ShopMObj*)sp_->obj)->h56 = st_;      \
            }                                          \
        } else {                                       \
            st_ = DiscStatus(id_);                     \
            if (st_ != -1) {                           \
                ((ShopMObj*)sp_->obj)->h56 = st_;      \
                UiObjMoveToX(sp_->obj, 3, -1, -8.0f);  \
                UiObjSetCommand(sp_->obj, 15, 0);      \
            }                                          \
        }                                              \
    }

#define DISC_SET_FLAG(n)                                     \
    {                                                        \
        u32 b_ = (n);                                        \
        lbl_80310B3C[b_ >> 5] |= 1 << (b_ & 31);             \
    }

/* Mark discovery item as bought (and the second flag when the guild knows it at rank 1). */
static inline void DiscBought(u16 item) {
    DISC_SET_FLAG(item + 0xc08);
    if (fn_801BE608(item) == 1) {
        DISC_SET_FLAG(item + 0x8a2);
    }
}

/* The discovery under the cursor of list part lp. */
#define DISC_CUR_ID(t, lp) ((t)->buf->out[(u8)(lp)->list->page * 6 + (u8)(lp)->list->row].id)

void fn_801BA9CC(DiscTask* t) {
    ShopPart* p;
    ShopEntry* e;
    s16 id;
    s32 i;
    s32 page;

    if (lbl_803475D8 != 0) {
        t->w->state = 12;
    }
    switch (t->w->state) {
    case 0:
        t->w->b36 = 0;
        fn_801BDAC8(t, t->w->b36);
        *t->w->parts[4]->flag = 1;
        *t->w->parts[5]->flag = 1;
        t->w->parts[7] = (ShopPart*)fn_801B6320(t, -4450.0f);
        t->w->parts[8] = (ShopPart*)fn_801ACD38(t, 0);
        t->w->parts[2] = (ShopPart*)fn_801B2678(t, 0);
        t->w->parts[16] = (ShopPart*)fn_801ABE90(t);
        if (t->buf->count >= 7) {
            t->w->parts[8]->x38->ha = 1;
        }
        *t->w->parts[2]->flag = 1;
        UiObjMoveTo(t->w->parts[7]->obj, 6, 4, 24.0f, 384.0f);
        UiObjSetCommand(t->w->parts[7]->obj, 15, 0);
        UiObjMoveToX(t->w->parts[8]->obj, 6, -1, 240.0f);
        UiObjSetCommand(t->w->parts[8]->obj, 15, 2);
        t->w->state = 1;
        break;
    case 1:
        if (UiObjIsBusy(t->w->parts[7]->obj) || UiObjIsBusy(t->w->parts[8]->obj)) {
            if (!PAD_A) {
                break;
            }
            MenuPartsFinish((MenuTask*)t);
        }
        t->w->state = 2;
        id = DISC_CUR_ID(t, t->w->parts[8]);
        fn_801B6400((u32)DiscDesc(id));
        DISC_STATUS(t, id);
        break;
    case 2:
        p = t->w->parts[8];
        if (t->buf->count == 0) {
            if (SHOP_PAD->x8 & 0x300) {
                goto cancel;
            }
            break;
        }
        if (PAD_B) {
        cancel: /* B, or A on an empty list */
            t->w->state = 11;
            UiObjMoveTo(t->w->parts[7]->obj, 6, 5, 640.0f, 480.0f);
            UiObjSetCommand(t->w->parts[7]->obj, 15, 0);
            UiObjMoveToX(t->w->parts[8]->obj, 6, -1, 648.0f);
            UiObjSetCommand(t->w->parts[8]->obj, 15, 0);
            UiObjMoveToX(t->w->parts[16]->obj, 6, -1, -260.0f);
            UiObjSetCommand(t->w->parts[16]->obj, 15, 6);
            break;
        }
        if (PAD_A) {
            SHOP_CUR_ENTRY(e, t, p);
            if (e->type == 0) {
                t->w->cost = fn_801BDEF4(e->id, 0);
                if (t->w->cost == 0) {
                    fn_801C08B4(3);
                    break;
                }
                t->w->left = lbl_8030B7F4.w34c - t->w->cost;
                t->w->item = e->id;
                fn_801C0814((ShopTask*)t);
                *t->w->parts[2]->flag = 0;
                UiObjMoveToX(t->w->parts[2]->obj, 6, 4, -8.0f);
                UiObjSetCommand(t->w->parts[2]->obj, 15, 1);
                t->w->state = 3;
                fn_801C08B4(2);
                t->w->parts[8]->x38->ha = 0;
            } else {
                fn_801C08B4(3);
            }
            break;
        }
        if (fn_801C09F8(0, 4)) {
            if (p->list->row == 0) {
                p->list->row = 5;
                for (i = 0; i < 6 - p->list->row; i++) {
                    if (t->buf->out[(u8)p->list->page * 6 + (u8)p->list->row].id != -1) {
                        break;
                    }
                    p->list->row--;
                }
            } else {
                p->list->row--;
            }
        } else if (fn_801C09F8(0, 5)) {
            p->list->row++;
            if (p->list->row == 6) {
                p->list->row = 0;
            }
            if (DISC_CUR_ID(t, p) == -1) {
                p->list->row = 0;
            }
        } else {
            if (fn_801C09F8(0, 6)) {
                page = p->list->page;
                if (t->buf->count <= 6) {
                    break;
                }
                if (p->list->page == 0) {
                    p->list->page = t->buf->pages;
                }
                p->list->page--;
                if (page != p->list->page) {
                    t->w->parts[8]->x38->hc = 0;
                }
            } else if (fn_801C09F8(0, 7)) {
                page = p->list->page;
                if (t->buf->count <= 6) {
                    break;
                }
                p->list->page++;
                if (p->list->page == t->buf->pages) {
                    p->list->page = 0;
                }
                if (page != p->list->page) {
                    t->w->parts[8]->x38->hc = 0;
                }
            } else {
                break;
            }
            if (DISC_CUR_ID(t, p) == -1) {
                for (i = 0; i < 6 - p->list->row; i++) {
                    if (t->buf->out[(u8)p->list->page * 6 + (u8)p->list->row].id != -1) {
                        break;
                    }
                    p->list->row--;
                }
            }
        }
        fn_801AB98C((Obj_UNIT0000*)p);
        id = DISC_CUR_ID(t, p);
        fn_801B6400((u32)DiscDesc(id));
        DISC_STATUS(t, id);
        MenuPlaySe(4);
        break;
    case 3:
        if (UiObjIsBusy(t->w->parts[2]->obj) == 0) {
            t->w->state = 4;
        } else if (PAD_A) {
            MenuPartsFinish((MenuTask*)t);
            t->w->state = 4;
        }
        break;
    case 4:
        if (PAD_A) {
            t->w->state = 6;
            MenuPlaySe(2);
            fn_801C08B4(0x19);
        } else if (PAD_B) {
            UiObjMoveToX(t->w->parts[2]->obj, 6, 5, -240.0f);
            UiObjSetCommand(t->w->parts[2]->obj, 15, 0);
            t->w->state = 5;
        }
        break;
    case 5:
        if (UiObjIsBusy(t->w->parts[2]->obj) == 0) {
            *t->w->parts[2]->flag = 1;
            t->w->state = 2;
            if (t->buf->count >= 7) {
                t->w->parts[8]->x38->ha = 1;
            }
        } else if (PAD_B) {
            MenuPartsFinish((MenuTask*)t);
            *t->w->parts[2]->flag = 1;
            t->w->state = 2;
            if (t->buf->count >= 7) {
                t->w->parts[8]->x38->ha = 1;
            }
        }
        break;
    case 6:
        if (PAD_A) {
            lbl_8030B7F4.w34c -= t->w->cost;
            t->w->cost = 0;
        } else if (t->w->cost <= t->w->step) {
            lbl_8030B7F4.w34c -= t->w->cost;
            t->w->cost = 0;
        } else {
            t->w->cost -= t->w->step;
            lbl_8030B7F4.w34c -= t->w->step;
        }
        if (t->w->cost == 0) {
            t->w->state = 7;
            fn_801C08B4(0x18);
            DiscBought(t->w->item);
            fn_801BDAC8(t, t->w->b36);
            id = DISC_CUR_ID(t, t->w->parts[8]);
            DISC_STATUS(t, id);
            UiObjMoveToX(t->w->parts[8]->obj, 6, -1, 648.0f);
            UiObjSetCommand(t->w->parts[8]->obj, 15, 0);
            UiObjMoveToX(t->w->parts[2]->obj, 6, 4, -240.0f);
            UiObjSetCommand(t->w->parts[2]->obj, 15, 0);
            UiObjMoveToX(t->w->parts[0]->obj, 6, 4, -260.0f);
            UiObjSetCommand(t->w->parts[0]->obj, 15, 0);
            t->w->parts[14] = (ShopPart*)fn_801AC2E4(t);
            UiObjMoveToX(t->w->parts[14]->obj, 6, -1, -8.0f);
            UiObjSetCommand(t->w->parts[14]->obj, 15, 0);
            t->w->parts[15] = (ShopPart*)fn_801AC094(t);
            UiObjMoveToX(t->w->parts[15]->obj, 6, -1, 320.0f);
            UiObjSetCommand(t->w->parts[15]->obj, 15, 2);
            fn_801B6400((u32)DiscDesc(id));
        }
        break;
    case 7:
        if (UiObjIsBusy(t->w->parts[15]->obj) == 0 || PAD_A) {
            MenuPartsFinish((MenuTask*)t);
            t->w->state = 8;
            *t->w->parts[2]->flag = 1;
        }
        break;
    case 8:
        if (PAD_A) {
            UiObjMoveToX(t->w->parts[8]->obj, 6, -1, 240.0f);
            UiObjSetCommand(t->w->parts[8]->obj, 15, 0);
            UiObjMoveToX(t->w->parts[0]->obj, 6, 5, -8.0f);
            UiObjSetCommand(t->w->parts[0]->obj, 15, 0);
            UiObjMoveToX(t->w->parts[14]->obj, 6, -1, -348.0f);
            UiObjSetCommand(t->w->parts[14]->obj, 5, 2);
            UiObjMoveToX(t->w->parts[15]->obj, 6, -1, 640.0f);
            UiObjSetCommand(t->w->parts[15]->obj, 15, 0);
            t->w->state = 10;
        }
        fn_801B60E8((MP_801B60E8*)t->w->parts[7]);
        break;
    case 10:
        if (UiObjIsBusy(t->w->parts[15]->obj)) {
            if (!PAD_A) {
                break;
            }
            MenuPartsFinish((MenuTask*)t);
        }
        MenuPartFree((MenuTask*)t, 14);
        MenuPartFree((MenuTask*)t, 15);
        t->w->state = 2;
        if (t->buf->count >= 7) {
            t->w->parts[8]->x38->ha = 1;
        }
        id = DISC_CUR_ID(t, t->w->parts[8]);
        fn_801B6400((u32)DiscDesc(id));
        DISC_STATUS(t, id);
        break;
    case 11:
        if (PAD_B) {
            MenuPartsFinish((MenuTask*)t);
            t->w->state = 12;
        } else if (UiObjIsBusy(t->w->parts[7]->obj) == 0) {
            t->w->state = 12;
        }
        break;
    case 12:
        MenuPartFree((MenuTask*)t, 7);
        MenuPartFree((MenuTask*)t, 8);
        MenuPartFree((MenuTask*)t, 2);
        MenuPartFree((MenuTask*)t, 16);
        *t->w->parts[4]->flag = 0;
        *t->w->parts[5]->flag = 0;
        t->state = 5;
        break;
    }
}
