/* Near misses of game/unit_8012F6C4.c, written for fn_8013AD9C (9.8 KB, not attempted yet), which
 * inlines the same helpers dozens of times:
 *
 *   fn_8013A538 (151/151 instructions, 10 lines): a cursor clamped to a member's list; `n` and the
 *     clamped per-item value swap r4/r5 at the end.
 *   fn_8013A8FC (296/296, 74 lines, 2 of them scheduling): the four party arrays (member, value,
 *     icon, usable mask); the parameter and `any` swap r20/r31, `i` and the count r23/r24.
 *
 * What they show: the party count written out (here a macro) where the function stores it in its
 * own variable, but as an inline call inside the other helpers; a member's fields read through
 * Party.mem[i] (Member now has b1e/b1f/b20, Party b11); MAX(x, 0) as `x < 0 ? 0 : x`; the list
 * helpers are the ones fn_801375A0 uses (Clear, and Bits' `m <<= 1; m |= d[k];`).
 *
 *   python tools/match/fdiff.py docs/near/fn_8013A538.c fn_8013A538 fn_8013A8FC
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

/* A member's b1e (-1 when there is no such member). */
static inline s32 MemberB1E(s32 idx) {
    Party* p = (Party*)(fn_80135598() + 0x238);
    s32 v = -1;

    if (PartyMemValid(p, idx)) {
        v = p->mem[idx].b1e;
    }
    return v;
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

#define PARTY_COUNT(n, p)                   \
    {                                       \
        n = 0;                              \
        p = fn_80135598();                  \
        if (p != NULL) {                    \
            n = 0;                          \
            if (p[0] >= 0) {                \
                n = 1;                      \
                if (p[1] >= 0) {            \
                    n = 2;                  \
                    if (p[2] >= 0) {        \
                        n = 3;              \
                        if (p[3] >= 0) {    \
                            n = 4;          \
                        }                   \
                    }                       \
                }                           \
            }                               \
        }                                   \
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

static inline s32 ListMask(s8* d) {
    s32 m = 0;
    s32 k;

    if (d != NULL) {
        for (k = 3; k >= 0; k--) {
            m <<= 1;
            m |= d[k];
        }
    }
    return m;
}

s32 fn_8013A538(s32 who, s32 base, s32 cur, s32 step, s32 limit) {
    s32 cnt = MemberB1E(who);
    s32 each = MemberSum(who);
    s32 rows = PartyCount() * 2;
    s32 r;
    s32 last;
    s32 n;
    s32 t;

    if (base < 0 || cnt < 0 || rows <= 0) {
        r = cur;
    } else {
        r = rows - 1;
        if (base + cnt < r) {
            r = base + cnt;
        }
        t = cur + step;
        t = t > 0 ? t : 0;
        if (t < r) {
            r = t;
        }
        if (r < base || r >= rows) {
            r = cur;
        }
    }
    last = PartyCount() - 1;
    n = r;
    if (r > last) {
        n = last;
    }
    n = n - base + 1;
    if (n < 0) {
        n = 0;
    }
    limit = limit < 0 ? 0 : limit;
    each = each < 0 ? 0 : each;
    if (n * each > limit) {
        r = limit / each - 1;
        r += base;
    }
    return r;
}


void fn_8013A8FC(s32 limit) {
    s8* base = fn_80135598();
    Party* p = (Party*)(base + 0x238);
    Dst* m = (Dst*)(base + 0x298);
    s32 cnt;
    s8* q;
    s32 any;
    s32 i;
    E24* a[6];
    s8 b[6];
    s8 c[6];
    s8 d[6];
    s32 kind;
    s32 mask;

    PARTY_COUNT(cnt, q);
    any = 0;
    for (i = 0; i < cnt; i++) {
        if (MemberState2(i)) {
            any = 1;
            break;
        }
    }
    Clear(a, b, c, d);
    for (i = 0; i < 4; i++) {
        if (PartyMemValid(p, i)) {
            a[i] = (E24*)&m[i];
            b[i] = DstSum(&m[i]);
            kind = -1;
            switch (m[i].b14) {
            case 0:
                kind = 8;
                break;
            case 1:
                kind = 9;
                break;
            case 2:
                kind = 10;
                break;
            case 3:
                if (PartyB11()) {
                    kind = 0xd;
                } else {
                    kind = 0xb;
                }
                break;
            }
            c[i] = kind;
            d[i] = 0;
            if (b[i] <= limit && !MemberPlaced(i)) {
                switch (PartyMemKind(p, i)) {
                case 3:
                    if (any) {
                        d[i] = 1;
                    }
                    break;
                default:
                    d[i] = 1;
                    break;
                }
            }
        }
    }
    mask = ListMask(d);
    fn_8012E4FC(a);
    fn_8012E498(b);
    fn_8012E434(c);
    fn_8012E424(mask);
}
