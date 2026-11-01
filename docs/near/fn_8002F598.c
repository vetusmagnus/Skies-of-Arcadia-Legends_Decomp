/* fn_8002F598 (battle.c, a battle-condition row check): a near miss, cast-free.
 *
 *   python tools/match/fdiff.py docs/near/fn_8002F598.c fn_8002F598
 *
 * The unit's version walks a `GameState*` 4 bytes at a time through a cast (9 diff lines). This one
 * indexes `x194[i]` instead: MWCC strength-reduces it into the original's pointer to the struct base
 * with the `lwz 0x194(r6)` displacement, so the instructions are exact (38 of 38) and only the counter
 * and that pointer swap r4/r6 (14 lines). About 70 variants did not move the swap: every order of
 * the `i`/`m`/table declarations, `*m` with `m++` vs `m[i]` vs `tbl[row][i]`, a `GameState*` local,
 * for vs while, `!`/`== 0`/continue forms, operand order, return forms, and a local `s32* f = x194`
 * (17-21 lines; it keeps the 0x194 add outside the loop). lbl_8030A10C is also `ObjStats` in
 * chunklist.h; battle.c's GameState view of it is local to the unit.
 * decomp-permuter (tools/match/permsetup.py on this file, 15 minutes at -j8) found nothing that
 * matches; its best only moves the `&` into a temp.
 */
#define fn_8002F598 fn_8002F598_old
#include "../src/game/battle.c" /* found through -i include */
#undef fn_8002F598

s32 fn_8002F598(s8 row) {
    s32 tbl[3][10] = {
        {2, 2, 1, 1, 8, 4, 8, 4, 2, 1},
        {8, 1, 8, 2, 4, 4, 8, 4, 1, 2},
        {8, 8, 4, 4, 2, 1, 2, 1, 4, 8},
    };
    s32* m = tbl[row];
    s8 i;
    for (i = 0; i < 10; i++) {
        if ((lbl_8030A10C.x194[i] & *m) == 0) break;
        m++;
    }
    return i >= 10;
}
