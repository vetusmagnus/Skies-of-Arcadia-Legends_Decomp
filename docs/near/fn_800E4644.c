/* fn_800E4644, the battle result screen's state machine (7.9 KB): a near miss, 130 diff lines,
 * all register numbers (the instruction stream matches with registers masked).
 *
 * Found on the way (the work's type is in the unit, as Ctx3594):
 * - lbl_80346DCC has to be declared with the work's own type. Through a cast
 *   (*(T**)&lbl_80346DCC) MWCC doesn't strength-reduce the byte-array loops (b34[i]).
 * - A loop counter of type int (not s32, which is long here) is what lets the unroller drop
 *   its trip-count check (the 99-byte clear in ResClearStats).
 * - Whether a loop sits in an inline function with its own locals or uses the function's
 *   variables changes the register colouring a lot (ResClearStats, ResRowsIn, ResStopEv are
 *   inline; ResShowSprites, ResHideSprites, ResCountB2, ResBonus are macros), though the
 *   variables' names and declaration order don't.
 * - `i = n = 0` (the counter's zero copied into the index) gives the original's
 *   mulli-by-the-counter start of the strength-reduced pointers.
 *
 * Left: register swaps in state 2 (the panel and the scaled index), the state-11 count and
 * state 13's loop.
 */
#include "../src/game/unit_800D81E8.c" /* found through -i include */
/* fn_800E4644: the battle result screen's state machine. Its work (lbl_80346DCC, 0x1610 bytes)
 * holds a row per party member (count at 0x0C), 22 sprite states and 22 panels, and a ring of
 * sound/effect requests at 0x1538. */
#define RES lbl_80346DCC
#define RES_PAD_A (lbl_80311A60[0]->flags & 0x100)

extern void fn_800E6A48(void);
extern s16 fn_800E6C2C(s32 a);
extern s16 fn_800E67C0(s32 a);
extern void fn_800E6E58(s32 a, s32 b, s32 c);
extern void fn_800E9F28(s32 a, s32 b, s32 c);
extern void fn_800E9B04(void);
extern void fn_800E96C0(void);
extern void fn_800E7240(void);
extern void fn_800E6554(void);
extern void fn_800EA79C(void);

/* Queue a request (the ring's last entry, 15, is kept for state 1's). */
static inline void ResPush(s16 id, s16 arg)
{
    s16 n = RES->evIdx;
    ResEv* e;

    if (n < 14) {
        RES->evIdx = n + 1;
    } else {
        RES->evIdx = 0;
    }
    e = &RES->ev[n];
    e->id = id;
    e->arg = arg;
    e->flags = 0;
    e->flags |= 1;
    e->ha = 0;
}

static inline void ResSprInit(ResSpr* s)
{
    s->h10 = 15;
    s->h16 = 0;
    s->h12 = 0;
    s->h14 = 0;
    s->c4 = s->c8 = 0xFF160800;
    s->cc = 0xFF16FF00;
    s->flags |= 2;
    s->flags &= ~0x38;
}

static inline void ResSprShow(ResSpr* s)
{
    s->flags |= 0x30;
    s->flags &= ~0x8000;
}

static inline void ResSprHide(ResSpr* s)
{
    s->flags &= ~0x10;
    s->flags &= ~0x8000;
}

/* A member's panel and sprite, by the page shown. */
static inline UiObj* ResMemObj(s16 i)
{
    return &RES->obj[RES->mem[i].slot[RES->mem[i].sel]].o;
}

static inline ResSpr* ResMemSpr(s16 i)
{
    return &RES->spr[RES->mem[i].slot[RES->mem[i].sel]];
}

/* How many members' panels are still moving. */
static inline s16 ResMemBusy(void)
{
    s16 n = 0;
    s16 i;

    for (i = 0; i < RES->count; i++) {
        if (UiObjIsBusy(ResMemObj(i)) == 1) {
            n++;
        }
    }
    return n;
}

#define ResCountB2() \
    { \
        for (i = n = 0; i < RES->count; i++) { \
            if (RES->row[i].b2) { \
                n++; \
            } \
        } \
    }

static inline s16 ResCountB17(void)
{
    s16 i;
    s16 n;
    Ctx3594* w = RES;

    for (i = n = 0; i < w->count; i++) {
        if (w->row[i].b17) {
            n++;
        }
    }
    return n;
}

static inline s16 ResCountActive(void)
{
    s16 i;
    s16 n;

    for (i = n = 0; i < RES->count; i++) {
        if (RES->b34[i] || RES->b38[i] || RES->stat[i].h0 || RES->stat[i].h2) {
            n++;
        }
    }
    return n;
}

static inline s16 ResAnyH28(void)
{
    s16 i;
    Ctx3594* w = RES;

    for (i = 0; i < 3; i++) {
        if (w->h28[i].h >= 0) {
            return 1;
        }
    }
    return 0;
}

/* Count `cur` up to `total` by `step`; 0 once it's there. */
static inline s16 ResCountUp(s32 step)
{
    if (RES->total - RES->cur >= step) {
        RES->cur += step;
    } else {
        RES->cur = RES->total;
        return 0;
    }
    return 1;
}

/* A skip (A): the panels' and sprites' delays and the queued requests' args are cleared. */
static inline void ResSkip(void)
{
    s16 i;

    for (i = 0; i < 22; i++) {
        if (i < 12 || i >= 20) {
            RES->obj[i].o.delay = 0;
            RES->spr[i].h16 = 0;
        }
    }
}

static inline void ResSkipRows(void)
{
    s16 i;

    for (i = 12; i < 20; i++) {
        RES->obj[i].o.delay = 0;
        RES->spr[i].h16 = 0;
    }
}

static inline void ResSkipEv(void)
{
    s16 i;

    for (i = 0; i < 16; i++) {
        RES->ev[i].arg = 0;
    }
}

#define ResShowSprites() \
    { \
        for (i = 0; i < RES->count; i++) { \
            ResSprInit(ResMemSpr(i)); \
            ResSprShow(ResMemSpr(i)); \
        } \
        ResSprInit(&RES->spr[20]); \
        ResSprShow(&RES->spr[20]); \
    }

#define ResHideSprites()                      \
    {                                         \
        for (i = 0; i < RES->count; i++) {    \
            ResSprHide(ResMemSpr(i));         \
        }                                     \
    }

/* Bring in the bonus panel (obj 21). */
#define ResBonus() \
    { \
        o = &RES->obj[21].o; \
        o->x = 0.0f; \
        o->y = 120.0f; \
        UiObjMoveTo(o, 8, -1, 0.0f, 0.0f); \
        UiObjSetCommand(o, 15, 60); \
        ResPush(6, 0x3f); \
        ResPush(11, 0x44); \
        RES->state = 12; \
        RES->b38[0] = 3; \
        RES->b38[1] = 3; \
        RES->b38[2] = 3; \
        RES->b38[3] = 3; \
    }

/* Clear the members' stat-gain rows. */
static inline void ResClearStats(void)
{
    s32 i;

    for (i = 0; i < RES->count; i++) {
        int k;
        RES->stat[i].b8 = 1;
        for (k = 0; k < 99; k++) {
            RES->stat[i].b9[k] = 0;
        }
        RES->stat[i].b6c = 0;
        RES->stat[i].b6d = 0;
    }
}

/* Slide the members' panels in. */
static inline void ResRowsIn(void)
{
    s32 i;
    UiObj* o;

    for (i = 0; i < RES->count; i++) {
        if (RES->row[i].b0) {
            o = ResMemObj(i);
            o->x = 320.0f;
            o->y = 0.0f;
            UiObjMoveTo(o, 6, -1, 0.0f, 0.0f);
            UiObjSetCommand(o, 15, i);
            RES->mem[i].on[RES->mem[(s16)i].sel] = 1;
            {
                s16 a = i + 6;
                ResPush(6, a);
            }
        } else {
            o = ResMemObj(i);
            o->x = 320.0f;
            o->y = 0.0f;
            UiObjMoveTo(o, 1, -1, 320.0f, 0.0f);
            UiObjSetCommand(o, 15, 0);
        }
    }
}

/* Stop the queued requests with this id. */
static inline void ResStopEv(s16 id)
{
    s16 i;

    for (i = 0; i < 16; i++) {
        if (RES->ev[i].id == id) {
            RES->ev[i].flags |= 8;
        }
    }
}

void fn_800E4644(void)
{
    s16 i;
    s16 n;
    UiObj* o;

    switch (RES->state) {
    case 0:
        if (RES->w1c <= 0 && RES->w44 == 0) {
            RES->timer += 0x41;
            RES->w44 = 1;
        }
        if (RES_PAD_A) {
            RES->timer = 0x55;
        }
        if (RES->timer >= 0x55) {
            for (i = 0; i < 22; i++) {
                RES->spr[i].flags |= 8;
                UiObjFinish(&RES->obj[i].o);
            }
            RES->state = 1;
            RES->fade = 1.0f;
        }
        if (RES->fade < 1.0f) {
            RES->fade += 0.1f;
        }
        RES->timer++;
        break;
    case 1:
        if (RES->total <= 0) {
            RES->state = 3;
            RES->h14f2 = 0;
            break;
        }
        n = 1;
        for (i = 0; i < RES->count; i++) {
            if (UiObjIsBusy(&RES->obj[i].o) == 1) {
                n = 0;
            }
        }
        if (n == 1) {
            RES->state = 2;
            RES->h14f2 = 1;
            {
                ResEv* e = &RES->ev[15];
                e->id = 25;
                e->arg = 0;
                e->flags = 2;
                e->ha = 1;
            }
            ResSprInit(&RES->spr[20]);
            ResSprShow(&RES->spr[20]);
        }
        break;
    case 2:
        if (RES_PAD_A) {
            n = ResCountUp(RES->total);
        } else {
            n = ResCountUp(14);
        }
        if (n) {
            break;
        }
        ResRowsIn();
        RES->state = 3;
        if (RES->h14f2 == 1) {
            ResStopEv(25);
            RES->h14f2 = 0;
            ResPush(0x18, 0);
        }
        break;
    case 3:
        if (ResMemBusy()) {
            break;
        }
        ResShowSprites()
        RES->timer = 0;
        RES->fade = 1.0f;
        RES->state = 4;
        RES->timer = 0;
        if (RES->w1c <= 0) {
            if (RES->w20 <= 0) {
                RES->state = 13;
            }
            RES->w44 = 0;
        }
        break;
    case 4:
        if (RES_PAD_A) {
            fn_800E6A48();
            ResHideSprites()
            break;
        }
        if (RES->timer >= 30) {
            if (fn_800E6C2C(14)) {
                break;
            }
            RES->state = 5;
            RES->timer = 0;
            ResHideSprites()
            break;
        }
        RES->timer++;
        break;
    case 5:
        if (ResCountActive()) {
            break;
        }
        ResCountB2();
        if (n) {
            fn_800E6E58(2, 8, 60);
        }
        RES->state = 6;
        break;
    case 6:
    case 7:
    case 8:
        if (RES_PAD_A) {
            ResSkip();
            ResSkipEv();
        }
        if (ResMemBusy()) {
            break;
        }
        ResCountB2();
        if (n) {
            RES->state = 6;
            fn_800E6E58(2, 8, 60);
            break;
        }
        if (RES->w0 == 0 && RES->w14 != 0) {
            fn_800E6E58(5, 8, 60);
            RES->timer = 0;
            RES->state = 9;
            RES->b38[0] = 3;
            RES->b38[1] = 3;
            RES->b38[2] = 3;
            RES->b38[3] = 3;
        } else if (ResAnyH28()) {
            ResBonus()
        } else {
            RES->state = 13;
            RES->timer = 0;
        }
        RES->w8 = 0;
        break;
    case 9:
        if (RES_PAD_A) {
            ResSkip();
            ResSkipRows();
            ResSkipEv();
        }
        if (RES->w8 != 0) {
            if (RES_PAD_A) {
                fn_800E67C0(RES->w14);
                RES->state = 10;
                ResHideSprites()
                break;
            }
            if (RES->timer >= 30) {
                if (fn_800E67C0(1)) {
                    break;
                }
                if (ResCountB17()) {
                    RES->state = 10;
                    ResHideSprites()
                    break;
                }
                if (ResAnyH28()) {
                    ResBonus()
                    break;
                }
                RES->state = 13;
                RES->timer = 0;
                break;
            }
            RES->timer++;
            break;
        }
        if (ResMemBusy()) {
            break;
        }
        RES->w8 = 1;
        ResShowSprites()
        ResClearStats();
        break;
    case 10:
        if (ResCountActive()) {
            break;
        }
        if (ResCountB17()) {
            fn_800E6E58(6, 8, 60);
            RES->state = 11;
            break;
        }
        if (ResAnyH28()) {
            ResBonus()
            break;
        }
        RES->state = 13;
        RES->timer = 0;
        break;
    case 11:
        if (RES_PAD_A) {
            ResSkip();
            ResSkipEv();
        }
        if (ResMemBusy()) {
            break;
        }
        if (ResCountB17()) {
            RES->state = 11;
            fn_800E6E58(6, 8, 60);
            break;
        }
        if (ResAnyH28()) {
            ResBonus()
        } else {
            RES->state = 13;
            RES->timer = 0;
        }
        RES->w8 = 0;
        break;
    case 12:
        if (RES_PAD_A) {
            ResSkip();
            ResSkipRows();
            ResSkipEv();
        }
        if (UiObjIsBusy(&RES->obj[21].o) == 0) {
            RES->state = 13;
            RES->timer = 0;
        }
        break;
    case 13:
        if (RES_PAD_A) {
            if (ResAnyH28()) {
                o = &RES->obj[21].o;
                o->x = 0.0f;
                o->y = 0.0f;
                UiObjMoveTo(o, 8, -1, 0.0f, 120.0f);
                UiObjSetCommand(o, 15, 0);
                ResPush(4, 0);
            }
            o = &RES->obj[20].o;
            o->x = 0.0f;
            o->y = 0.0f;
            UiObjMoveTo(o, 8, -1, 0.0f, -120.0f);
            UiObjSetCommand(o, 15, 0);
            ResPush(6, 0);
            for (i = 0; i < RES->count; i++) {
                u16 d;
                o = &RES->obj[i].o;
                o->x = 0.0f;
                o->y = 0.0f;
                UiObjMoveTo(o, 6, -1, -320.0f, 0.0f);
                d = i + 1;
                UiObjSetCommand(o, 15, d);
                ResPush(4, i + 7);
                if (RES->mem[i].on[RES->mem[i].sel]) {
                    o = ResMemObj(i);
                    o->x = 0.0f;
                    o->y = 0.0f;
                    UiObjMoveTo(o, 6, -1, 320.0f, 0.0f);
                    UiObjSetCommand(o, 15, d);
                    ResPush(4, i + 7);
                }
            }
            RES->b38[0] = 2;
            RES->b38[1] = 2;
            RES->b38[2] = 2;
            RES->b38[3] = 2;
            RES->state = 14;
            RES->timer = 0;
            break;
        }
        RES->timer++;
        break;
    case 14:
        if (RES_PAD_A) {
            RES->timer = 40;
        }
        if (RES->timer >= 18) {
            lbl_80346DD0 = 2;
            RES->fade = 0.0f;
        }
        if (RES->timer >= 8 && RES->fade > 0.0f) {
            RES->fade -= 0.1f;
        }
        RES->timer++;
        break;
    }
    if (RES->fade > 1.0f) {
        RES->fade = 1.0f;
    }
    fn_800EA244(RES->w48);
    fn_800E9F28(RES->w10, RES->w14, RES->cur);
    fn_800E9B04();
    fn_800E96C0();
    fn_800E7240();
    fn_800E6554();
    fn_800E9B04();
    fn_800EA79C();
}
