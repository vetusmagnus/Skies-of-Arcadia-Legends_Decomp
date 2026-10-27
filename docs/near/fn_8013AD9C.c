/* fn_8013AD9C (9.8 KB, the party-member pick menu's state machine): a near miss.
 *
 * Compile it with GC/1.3, not 1.3.2 (the unit itself stays on 1.3.2; whether the original was
 * built with 1.3 is an open hypothesis):
 *   CCV=1.3 python tools/match/fdiff.py docs/near/fn_8013AD9C.c fn_8013AD9C
 * Structure, stack layout and instruction count are exact (2453 instructions). About 330
 * instructions differ, all of them in register numbers (fdiff prints 1194 lines).
 *
 * Why 1.3: the original inlines about 8,200 nodes of helper code into this function (zero copies
 * as `mr` and the stack-slot order show the helpers were inline functions, not macros). GC/1.3.2
 * stops inlining once a function goes over inline_max_total_size, which defaults to 7000 (the
 * value is in mwcceppc.exe). From there it drops the biggest helpers first. GC/1.3 has no such
 * limit, and every function that already matches in unit_8012F6C4.c matches under 1.3 too. See
 * docs/matching.md, "MWCC's inline budget".
 *
 * Which shape each helper has, and what it showed:
 * - The search (PM_FIND) and the points display (PM_SHOW_PTS) are macros with block-scoped
 *   temporaries. As inline functions their locals were coloured in reverse order, and the
 *   registers came out mirrored.
 * - The party count is a loop over p[n] < 0 that MWCC unrolls. It costs fewer inline nodes than
 *   the written-out if chain and compiles to the same code.
 * - The cell helpers nest two deep (PmClear and PmCellSel call PmCell). The original's two
 *   groups of stack slots come from that.
 * Still open: register numbering in the cursor step (case 2), the row-cost lines (case 9), the
 * kind-1 marks (case 7) and the PmCost temporaries (case 15).
 */
#include "../src/game/unit_8012F6C4.c" /* found through -i include */

/* Whether party member idx exists (p is fn_80135598() + 0x238). */
static inline s32 PartyMemValid(Party* p, s32 idx) {
    s32 ok = 0;

    if (p != NULL && idx >= 0 && idx < 5 && p->mem[idx].b14 >= 0) {
        ok = 1;
    }
    return ok;
}

static inline s32 DstSum(Dst* m) {
    s32 v = 100;

    if (m != NULL) {
        v = m->b1f + m->b20;
    }
    return v;
}

/* A member's b1f + b20 (100 when there is no such member). */
static inline s32 MemberSum(s32 idx) {
    s32 v = 100;
    s8* b = fn_80135598();

    if (PartyMemValid((Party*)(b + 0x238), idx)) {
        v = DstSum((Dst*)(b + 0x298 + idx * 0x22));
    }
    return v;
}

/* How many of the four party slots are filled (they fill from the front). */
static inline s32 PartyCount(void) {
    s32 n = 0;
    s8* p = fn_80135598();

    if (p != NULL) {
        for (n = 0; n < 4; n++) {
            if (p[n] < 0) {
                break;
            }
        }
    }
    return n;
}

/* Member idx's kind (4 when there is no such member). */
static inline s32 PartyMemKind(Party* p, s32 idx) {
    s32 k = 4;

    if (PartyMemValid(p, idx)) {
        k = p->mem[idx].b14;
    }
    return k;
}

static inline s32 PartyB11(void) {
    s32 r = 0;
    Party* p = (Party*)(fn_80135598() + 0x238);

    if (p != NULL && p->b11 >= 2) {
        r = 1;
    }
    return r;
}

/* Where member who sits among the first n kind-4 records of lbl_80308E90: its index, n when it
 * is in none of them, -1 when n is out of range. */
typedef struct { u8 kind; s8 b1; s8 who; s8 b3; s8 b4; } Rec5v;

static inline s32 RecSlot(s32 who, s32 n) {
    s32 i = -1;

    if (n > 0 && n <= 4) {
        s32 last = n - 1;

        if (last < 4) {
            for (i = 0; i <= last; i++) {
                if ((s32)((Rec5v*)lbl_80308E90)[i + 4].kind == 4 && ((Rec5v*)lbl_80308E90)[i + 4].who == who) {
                    break;
                }
            }
        }
    }
    return i;
}

/* Whether member who is placed (not placed only when the record search runs to the end). */
static inline s32 MemberPlaced(s32 who) {
    s32 ok = 1;
    s32 n = PartyCount();
    s32 i = RecSlot(who, n);

    if (i >= 0 && i == n) {
        ok = 0;
    }
    return ok;
}

typedef struct { s16 s0; s16 s2; } Pair_801298CC;
extern Pair_801298CC* fn_801298CC(void);

static inline s32 MemberState2(s32 i) {
    s32 r = 0;
    s32 n = PartyCount();

    if (i >= 0 && i < n && fn_801298CC()[i].s0 == 2) {
        r = 1;
    }
    return r;
}

typedef struct PmW {
    u8 b0;     /* 0x00 */
    s8 state;  /* 0x01 */
    s8 mem;    /* 0x02 */
    u8 b3;
    s8 who;    /* 0x04 */
    u8 pad5[3];
    s8 lo;     /* 0x08 */
    s8 hi;     /* 0x09 */
    u8 xa;     /* 0x0A */
    u8 padb[0x16 - 0xb];
    s16 pts;   /* 0x16 */
    s16 cost[4]; /* 0x18 */
} PmW;

typedef struct { u8 pad0[0xc]; u32 rep; u8 pad10[0x24 - 0x10]; } PmPad;
extern PmPad lbl_8030A6D4[];
extern s32 lbl_8034757C;
extern char lbl_802B34B0[];
extern void fn_8012E5B0(s32 a);
extern void fn_8012E580(s32 a);
extern void fn_8012E560(s8 a);
extern void fn_8012E5A0(s32 a);
extern void fn_8012E590(s32 a);
extern void fn_8012E414(s32 a);
extern void fn_8012E5C0(s32 a);
extern void fn_8012F478(s32 a);
extern s32 fn_801358A0(s32 i, s32 m, s32 a, s32 b, s32 n);
extern void fn_8012ADE8(s32 v);
extern void fn_8013FB48(s32 m, s32 n);
extern s32 fn_8013FCF0(s32 i, s32 m, s32 n);
extern s32 fn_8013FE10(s32 i, s32 m);
extern void fn_80136320(PmW* w);
extern void fn_80135EBC(PmW* w);
extern void fn_8013FF50(s32 who, s32 lo, s32 m, s32 pts);
extern s32 fn_80135BE8(s32 who, s32 lo, s32 m, s32 hi);

#define PM_PAD (lbl_80311A60.pad->x8)

static inline void PmCell(s32 x, s32 y, s32 a, s32 b, s32 c)
{
    extern void fn_80131658(Cell* c);
    Cell t;
    t.x = x;
    t.y = y;
    t.a = a;
    t.c = c;
    t.b = b;
    fn_80131658(&t);
}

/* Layer 1 of cell (x, y) starts a selection. */
static inline void PmCellSel(s32 x, s32 y, s32 b)
{
    PmCell(x, y, 1, b, 2);
}

/* Clears both layers (1 and 3) of cell (x, y). */
static inline void PmClear(s32 x, s32 y)
{
    PmCell(x, y, 1, -1, -1);
    PmCell(x, y, 3, -1, -1);
}

static inline void PmFocus(PmW* w, s32 on)
{
    if (w != NULL) {
        w->xa = on;
    }
    fn_8012F478(!on);
}

static inline s32 PmIdxValid(s32 i)
{
    s32 r = 0;
    s32 n = PartyCount();

    if (i >= 0 && i < n) {
        r = 1;
    }
    return r;
}

static inline s32 PmAvail(s32 m)
{
    s32 r = 0;

    if (PartyMemValid((Party*)(fn_80135598() + 0x238), m) && !MemberPlaced(m)) {
        r = 1;
    }
    return r;
}

static inline s32 PmAfford(s32 m, s32 pts)
{
    s32 r = 0;

    if (pts >= MemberSum(m)) {
        r = 1;
    }
    return r;
}

static inline void PmBack(PmW* w)
{
    s32 n = PartyCount();
    fn_80130304(-1);
    fn_801315FC(1);
    if (w != NULL) {
        fn_8012ADE8(w->pts);
        fn_8013FB48(w->mem, n);
    }
}

static inline s32 PmFree(s32 f)
{
    s32 r = 0;
    if (!(f & 0xc)) {
        r = 1;
    }
    return r;
}

static inline s32 PmUsed(s32 f)
{
    s32 r = 0;
    if (!PmFree(f)) {
        r = 1;
    }
    return r;
}

static inline s32 PmMark(s32 f)
{
    s32 r = 0;
    if (f & 0x12) {
        r = 1;
    }
    return r;
}

static inline s32 PmMarkFree(s32 f)
{
    s32 r = 0;
    if (PmMark(f) && PmFree(f)) {
        r = 1;
    }
    return r;
}

static inline s32 PmMarkUsed(s32 f)
{
    s32 r = 0;
    if (PmMark(f) && !PmFree(f)) {
        r = 1;
    }
    return r;
}

static inline s32 PmNone(s32 f)
{
    s32 r = 0;
    if (!(f & 3)) {
        r = 1;
    }
    return r;
}

static inline s32 PmRows(s32 lo, s32 hi)
{
    s32 n = PartyCount();
    s32 c;

    if (hi > n - 1) {
        hi = n - 1;
    }
    c = hi - lo + 1;
    if (c < 0) {
        c = 0;
    }
    return c;
}

static inline s32 PmWaitKey(PmW* w, u32 mask)
{
    s32 f = 0;

    if (PM_PAD & mask) {
        PmFocus(w, 0);
        SePlay(0xf, 1, 7);
        f = 1;
    }
    return f;
}

static inline s32 PmCanPick(s32 m, s32 pts)
{
    s32 ok = 0;

    if (PmAvail(m) && PmAfford(m, pts)) {
        ok = 1;
    }
    return ok;
}

/* What the pick costs: the member's sum, times the rows for a kind-1 member. */
static inline s32 PmCost(PmW* w)
{
    s32 s = MemberSum(w->who);

    if (PartyMemKind((Party*)(fn_80135598() + 0x238), w->who) == 1) {
        s *= PmRows(w->lo, w->hi);
    }
    return s;
}

#define PM_FIND(r, m_, b_)                                  \
    {                                                       \
        s32 fm_;                                            \
        s32 fb_;                                            \
        s32 fi_;                                            \
        s32 fn_;                                            \
        fb_ = b_;                                           \
        fm_ = m_;                                           \
        fn_ = PartyCount();                                 \
        fi_ = 0;                                            \
        while (fi_ >= 0 && fi_ < fn_ && !fn_801358A0(fi_, fm_, 4, fb_, fn_)) { \
            fi_++;                                          \
        }                                                   \
        fi_ = fi_ > -1 ? fi_ : -1;                          \
        fi_ = fi_ < fn_ ? fi_ : fn_;                        \
        if (fi_ < 0 || fi_ >= fn_) {                        \
            fi_ = -1;                                       \
        }                                                   \
        r = fi_;                                            \
    }

#define PM_SHOW_PTS(w) { s32 sm_; s32 sp_; sm_ = (w)->who; sp_ = (w)->pts; fn_8012ADE8(sp_ - MemberSum(sm_)); }

/* Clears the marks (fn_80131630 -1) of rows 0..last that have none of bits 0-1. */
#define PM_UNMARK(m, last)                                  \
    {                                                       \
        extern void fn_80131630(s8 a, s8 b, s8 v);          \
        s32 uk_;                                            \
        s32 um_;                                            \
        s32 ul_;                                            \
        ul_ = (last);                                       \
        um_ = (m);                                          \
        for (uk_ = 0; uk_ <= ul_; uk_++) {                  \
            if (PmNone(fn_8013FE10(uk_, um_))) {            \
                fn_80131630(uk_, um_, -1);                  \
            }                                               \
        }                                                   \
    }

/* fn_8013AD9C */
s32 fn_8013AD9C(PmW* w)
{
    extern s32 fn_801365D8(s32 a, s32 b, s32 c, s32 d, s32 e);
    s32 ret = 0;
    s32 k;
    s32 h;
    s32 m;
    s32 n;
    s32 d;
    s32 step;
    s32 i;
    s32 ok;
    s32 f;
    s32 code;
    s32 lo;
    s32 hi;
    s32 s;
    s32 fi;

    switch (w->state) {
    case 0:
        w->state = 1;
    case 1:
        k = w->who;
        h = w->pts;
        fn_8012E5B0(2);
        fn_8012E580(1);
        fn_8012E570(0);
        fn_8012E560(k);
        fn_8012E5A0(0);
        fn_8012E590(0);
        fn_8013A8FC(h);
        fn_8012E414(0);
        fn_8012E5C0(0);
        fn_80130304(-1);
        PmFocus(w, 0);
        w->state = 2;
    case 2:
        if (w != NULL) {
            s32 cur;
            s32 d;
            s32 n;
            s32 i;
            s32 step;
            u32 rep;
            cur = w->who;
            rep = lbl_8030A6D4[lbl_8034757C].rep;
            d = 0;
            if (rep & 8) {
                d = -1;
            }
            if (rep & 4) {
                d++;
            }
            n = cur + d;
            if (n < 0) {
                n = 3;
            }
            if (n > 3) {
                n = 0;
            }
            step = d > -1 ? d : -1;
            step = step < 1 ? step : 1;
            if (step != 0) {
                for (i = 0; i < 4; i++) {
                    if (PartyMemValid((Party*)(fn_80135598() + 0x238), n)) {
                        break;
                    }
                    n += step;
                    if (n < 0) {
                        n = 3;
                    }
                    if (n > 3) {
                        n = 0;
                    }
                }
            }
            fn_8012E560(n);
            if (w->who != n) {
                w->who = n;
                PmFocus(w, 0);
                SePlay(0xf, 1, 0);
            }
        }
        if (PM_PAD & 0x200) {
            fn_8012E5C0(1);
            PmFocus(w, 0);
            SePlay(0xf, 1, 7);
            ret = 1;
        } else if (PM_PAD & 0x100) {
            if (!PmCanPick(w->who, w->pts)) {
                SePlay(0xf, 1, 3);
                break;
            }
            PM_FIND(fi, w->mem, w->who);
            if (fi < 0) {
                fn_8012F458(w->who >= 3);
                fn_8012F468(lbl_802B34B0);
                PmFocus(w, 1);
                SePlay(0xf, 1, 3);
                w->state = 4;
                break;
            }
            PmFocus(w, 0);
            switch (PartyMemKind((Party*)(fn_80135598() + 0x238), w->who)) {
            case 0:
                fn_801315FC(0);
                PM_SHOW_PTS(w);
                SePlay(0xf, 1, 2);
                w->state = 5;
                break;
            case 1:
                fn_801315FC(0);
                PM_SHOW_PTS(w);
                SePlay(0xf, 1, 2);
                w->state = 7;
                break;
            case 2:
                PM_FIND(fi, w->mem, w->who);
                if (!PmIdxValid(fi)) {
                    SePlay(0xf, 1, 3);
                    break;
                }
                fn_801315FC(0);
                PM_SHOW_PTS(w);
                SePlay(0xf, 1, 2);
                w->state = 10;
                break;
            case 3:
                fn_801315FC(0);
                PM_SHOW_PTS(w);
                SePlay(0xf, 1, 2);
                w->state = 13;
                break;
            }
        } else if (PM_PAD & 0x400) {
            if (PartyMemValid((Party*)(fn_80135598() + 0x238), w->who)) {
                fn_8013A818((Req*)w);
                PmFocus(w, 1);
                SePlay(0xf, 1, 6);
                w->state = 3;
            }
        }
        break;
    case 3:
        if (PmWaitKey(w, 0xf0f)) {
            w->state = 2;
        }
        break;
    case 4:
        if (PmWaitKey(w, 0xf00)) {
            w->state = 2;
        }
        break;
    case 5:
        PM_FIND(w->lo, w->mem, w->who);
        w->state = 6;
    case 6:
        w->lo = fn_801365D8(w->lo, w->mem, 4, w->who, 0);
        if (PM_PAD & 0x200) {
            m = w->mem;
            lo = w->lo;
            PmCell(lo, m, 1, -1, -1);
            PmCell(lo, m, 3, -1, -1);
            PmBack(w);
            SePlay(0xf, 1, 7);
            w->state = 1;
        } else if (PM_PAD & 0x100) {
            fn_8013A35C(w->mem, w->lo, w->who, -1);
            fn_80130304(-1);
            fn_801315FC(1);
            SePlay(0xf, 1, 2);
            w->state = 15;
        }
        break;
    case 7:
        PM_FIND(w->lo, w->mem, w->who);
        w->hi = w->lo;
        n = PartyCount();
        m = w->who;
        k = w->mem;
        if (PartyMemKind((Party*)(fn_80135598() + 0x238), m) == 1) {
            i = 0;
            if (n > 0 && n <= 4) {
                s32 j = -n;
                i = -1;
                if (j >= -4) {
                    for (i = j; i <= -1; i++) {
                        if ((s32)((Rec5v*)lbl_80308E90)[i + 4].kind == 4 && ((Rec5v*)lbl_80308E90)[i + 4].who == m) {
                            break;
                        }
                    }
                }
            }
            if (i < 0) {
                s32 lv = lbl_80308E90[i + 4].a[4];
                for (h = 0; h <= lv; h++) {
                    f = fn_8013FCF0(h, k, PartyCount());
                    if (PmFree(f)) {
                        fn_80131630(h, k, 0x10);
                    } else if (PmUsed(f)) {
                        fn_80131630(h, k, 0x11);
                    }
                }
            }
        }
        w->state = 8;
    case 8:
        fn_80136320(w);
        if (PM_PAD & 0x200) {
            hi = w->hi;
            m = w->mem;
            for (k = w->lo; k <= hi; k++) {
                PmClear(k, m);
            }
            PM_UNMARK(w->mem, w->lo - 1);
            PmBack(w);
            SePlay(0xf, 1, 7);
            w->state = 1;
        } else if (PM_PAD & 0x100) {
            m = w->mem;
            lo = w->lo;
            hi = w->hi;
            PmCellSel(lo, m, 1);
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
            PmCell(lo, m, 3, code, 2);
            for (lo++; lo <= hi; lo++) {
                fn_8013160C(lo, m, 0);
            }
            fn_8013FF50(w->who, w->lo, w->mem, w->pts);
            SePlay(0xf, 1, 2);
            w->state = 9;
        }
        break;
    case 9:
        w->hi = fn_801361B8((void*)(s32)w->who, w->lo, w->mem, w->hi, w->pts);
        hi = w->hi;
        lo = w->lo;
        h = w->pts;
        n = PmRows(lo, hi);
        fn_8012ADE8(h - n * MemberSum(w->who));
        if (PM_PAD & 0x200) {
            hi = w->hi;
            m = w->mem;
            for (k = w->lo; k <= hi; k++) {
                PmClear(k, m);
            }
            PmCell(w->lo, w->mem, 1, 1, 0);
            n = PartyCount();
            m = w->mem;
            hi = n * 2 - 1;
            for (k = w->lo; k <= hi; k++) {
                f = fn_8013FE10(k, m);
                if (PmMarkFree(f)) {
                    fn_80131630(k, m, 0x10);
                } else if (PmMarkUsed(f)) {
                    fn_80131630(k, m, 0x11);
                }
            }
            fn_8013FB48(w->mem, PartyCount());
            PM_SHOW_PTS(w);
            SePlay(0xf, 1, 7);
            w->state = 8;
        } else if (PM_PAD & 0x100) {
            fn_8013A35C(w->mem, w->lo, w->who, w->hi);
            PM_UNMARK(w->mem, w->lo - 1);
            fn_80130304(-1);
            fn_801315FC(1);
            SePlay(0xf, 1, 2);
            w->state = 15;
        }
        break;
    case 10:
        PM_FIND(w->lo, w->mem, w->who);
        w->hi = w->lo + 1;
        w->state = 11;
    case 11:
        fn_80135EBC(w);
        if (PM_PAD & 0x200) {
            m = w->mem;
            lo = w->lo;
            hi = w->hi;
            PmClear(lo, m);
            PmClear(hi, m);
            PmBack(w);
            SePlay(0xf, 1, 7);
            w->state = 1;
        } else if (PM_PAD & 0x100) {
            if (!PmIdxValid(w->lo)) {
                SePlay(0xf, 1, 3);
                break;
            }
            m = w->mem;
            hi = w->hi;
            PmCellSel(w->lo, m, 0xd);
            PmCell(hi, m, 3, 0xc, 0);
            fn_8013FF50(w->who, w->lo, w->mem, w->pts);
            SePlay(0xf, 1, 2);
            w->state = 12;
        }
        break;
    case 12:
        w->hi = fn_80135BE8(w->who, w->lo, w->mem, w->hi);
        if (PM_PAD & 0x200) {
            m = w->mem;
            lo = w->lo;
            hi = w->hi;
            PmClear(lo, m);
            PmClear(hi, m);
            PmCell(w->lo, w->mem, 1, 0xd, 0);
            n = PartyCount();
            m = w->mem;
            hi = n * 2 - 1;
            for (k = w->lo; k <= hi; k++) {
                f = fn_8013FE10(k, m);
                if (PmMarkFree(f)) {
                    fn_80131630(k, m, 0x10);
                } else if (PmMarkUsed(f)) {
                    fn_80131630(k, m, 0x11);
                }
            }
            fn_8013FB48(w->mem, PartyCount());
            SePlay(0xf, 1, 7);
            w->state = 11;
        } else if (PM_PAD & 0x100) {
            fn_8013A35C(w->mem, w->lo, w->who, w->hi);
            fn_80130304(-1);
            fn_801315FC(1);
            SePlay(0xf, 1, 2);
            w->state = 15;
        }
        break;
    case 13:
        PM_FIND(w->lo, w->mem, w->who);
        n = PartyCount();
        m = w->mem;
        for (k = 0; k < n; k++) {
            if (!MemberState2(k)) {
                f = fn_8013FCF0(k, m, PartyCount());
                if (PmFree(f)) {
                    fn_80131630(k, m, 0x10);
                } else if (PmUsed(f)) {
                    fn_80131630(k, m, 0x11);
                }
            }
        }
        w->state = 14;
    case 14:
        code = 0xf;
        if (PartyB11()) {
            code = 0x19;
        }
        w->lo = fn_801365D8(w->lo, w->mem, 4, w->who, code);
        if (PM_PAD & 0x200) {
            m = w->mem;
            lo = w->lo;
            PmCell(lo, m, 1, -1, -1);
            PmCell(lo, m, 3, -1, -1);
            PM_UNMARK(w->mem, PartyCount() - 1);
            PmBack(w);
            SePlay(0xf, 1, 7);
            w->state = 1;
        } else if (PM_PAD & 0x100) {
            fn_8013A35C(w->mem, w->lo, w->who, -1);
            PM_UNMARK(w->mem, PartyCount() - 1);
            fn_80130304(-1);
            fn_801315FC(1);
            SePlay(0xf, 1, 2);
            w->state = 15;
        }
        break;
    case 15:
        fn_8012E5C0(1);
        s = PmCost(w);
        if (w != NULL && s > 0 && s != 100) {
            w->pts -= s;
            w->cost[w->mem] = s;
            fn_8012ADE8(w->pts);
        }
        PmFocus(w, 0);
        ret = 2;
        break;
    }
    fn_80135598();
    return ret;
}
