/* fn_800AE4E0 (4.7 KB, the six neighbours of a cell on a hex spiral): a near miss.
 * fn_800DA744 (unit_800D81E8.c) is byte-identical (docs/duplicates.txt) and takes the same source.
 *
 *   python tools/match/fdiff.py docs/near/fn_800AE4E0.c fn_800AE4E0
 * Structure is exact (1192 instructions, registers masked: no difference). 151 instructions
 * differ in register numbers (fdiff prints 430 lines), all in the neighbour lookups after the
 * ring-to-ring divisions: from the `x = out[0]` load on, the original keeps x in r29 and the
 * ring-last sum in r31, where this build puts x in r8 and the sum in r28, and the same kind of
 * rotation follows in the out[4]/out[5] and corner-branch lookups.
 *
 * Cells are numbered in rings around cell 0: ring n holds 6n cells, so its first index is
 * 1 + 6(1 + ... + n-1) and its last 6(1 + ... + n). For a cell on an edge of ring r the
 * neighbours are two cells on ring r-1, its two neighbours on ring r and two on ring r+1; a
 * corner cell (d*6 is a multiple of the ring's length) has one inner neighbour and three outer.
 *
 * What the original shows:
 * - The ring sums are loops, not closed forms, and MWCC unrolls them by 8. Each sum is guarded by
 *   `n == 0` written on the textual ring (`r - 1`, `r + 1`): the original tests it with
 *   `subic.`/`addic.` every time, which an inline helper taking n as a parameter loses (the
 *   parameter's `r + 1` is computed once and tested with `cmpwi`), so the guard is a macro around
 *   inline loops.
 * - In both inline loops `i` is declared before `s`.
 * - Which lookup uses the inline expression (RING_LASTE) and which the statement macro with its
 *   own block counter (RING_LAST) was searched over all eight sites and all four declaration
 *   orders of the two loops: 430 for the source below (the macro only in the two ring r+1
 *   lookups whose x comes from out[]), 534 all-macro, 606 all-expression. Inline
 *   RingNext/RingPrev functions (x as a parameter), holding x in another of the function's
 *   variables, and 70 random declaration orders changed nothing or made it worse.
 */
#include "../src/game/unit_800972AC.c" /* found through -i include */

/* 1 + 6(1 + ... + n-1): the first index on ring n (n > 0). */
static inline s32 RingSum1(s32 n)
{
    s32 i;
    s32 s = 1;

    for (i = 1; i < n; i++) {
        s += i * 6;
    }
    return s;
}

/* 6(1 + ... + n): the last index on ring n. */
static inline s32 RingSum0(s32 n)
{
    s32 i;
    s32 s = 0;

    for (i = 1; i <= n; i++) {
        s += i * 6;
    }
    return s;
}

#define RING_FIRSTE(n) ((n) == 0 ? 0 : RingSum1(n))
#define RING_LASTE(n) ((n) == 0 ? 0 : RingSum0(n))

#define RING_LAST(s, n)                                     \
    {                                                       \
        s32 i_;                                             \
        if ((n) == 0) {                                     \
            s = 0;                                          \
        } else {                                            \
            s = 0;                                          \
            for (i_ = 1; i_ <= (n); i_++) {                 \
                s += i_ * 6;                                \
            }                                               \
        }                                                   \
    }

void fn_800AE4E0(s32 idx, s32* out)
{
    s32 t;
    s32 r;
    s32 k;
    s32 d;
    s32 span;
    s32 x;
    s32 l;

    if (idx == 0) {
        out[0] = 1;
        out[1] = 2;
        out[2] = 3;
        out[3] = 4;
        out[4] = 5;
        out[5] = 6;
        return;
    }
    t = idx;
    r = 0;
    for (k = 6; t > 0; k += 6) {
        t -= k;
        r++;
    }
    d = idx - RING_FIRSTE(r);
    span = r * 6;
    if (d * 6 % span != 0) {
        out[0] = d * ((r - 1) * 6) / span + RING_FIRSTE(r - 1);
        x = out[0];
        out[1] = x == RING_LASTE(r - 1) ? RING_FIRSTE(r - 1) : x + 1;
        out[2] = idx == RING_LASTE(r) ? RING_FIRSTE(r) : idx + 1;
        out[3] = idx == RING_FIRSTE(r) ? RING_LASTE(r) : idx - 1;
        out[4] = d * ((r + 1) * 6) / span + RING_FIRSTE(r + 1);
        x = out[4];
        RING_LAST(l, r + 1);
        out[5] = x == l ? RING_FIRSTE(r + 1) : x + 1;
    } else {
        out[0] = d * ((r - 1) * 6) / span + RING_FIRSTE(r - 1);
        out[1] = idx == RING_LASTE(r) ? RING_FIRSTE(r) : idx + 1;
        out[2] = idx == RING_FIRSTE(r) ? RING_LASTE(r) : idx - 1;
        out[3] = d * ((r + 1) * 6) / span + RING_FIRSTE(r + 1);
        x = out[3];
        RING_LAST(l, r + 1);
        out[4] = x == l ? RING_FIRSTE(r + 1) : x + 1;
        x = out[3];
        out[5] = x == RING_FIRSTE(r + 1) ? RING_LASTE(r + 1) : x - 1;
    }
}
