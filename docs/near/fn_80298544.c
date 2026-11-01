/* fn_80298544 (texture reference table reset): the smallest clean case of the Ninja copy blocker.
 *
 *   python tools/match/fdiff.py docs/near/fn_80298544.c fn_80298544
 *
 * Everything else comes out identical with GC/1.3.2: the prologue, the 8x unroll with the
 * mtctr/bdnz trip count, and the unrolled body, which keeps `li r5,0; li r0,-1` inside the loop
 * and shares r5 for every zero exactly like the original. The only difference is the leftover loop
 * MWCC builds for the last n % 8 entries. The original hoists its constants as
 *     li r9,0 ; li r8,-1 ; mr r7,r9 ; mr r6,r9 ; mr r5,r9
 *     stw r9,0 ; stw r9,4 ; stw r8,8 ; stw r7,0xc ; stw r6,0x10 ; stw r5,0x14
 * (the first two zeros share, each later zero gets a copy: the same shape as the FIFO address in
 * fifo_8029681C.c), and every available compiler emits one `li r6,0` for all of them. The extra
 * registers also renumber the counter (r10 vs r7). That is the whole diff (about 25 lines).
 *
 * Ruled out on this function (2026-11-01): every GC and Wii compiler at -O4,p/-O4,s/-O3,p and
 * with each -opt switch; #pragma opt_propagation/opt_common_subs/opt_loop_invariants/
 * opt_lifetimes/opt_strength_reduction/opt_dead_code/opt_dead_assignments/opt_unroll_loops/
 * global_optimizer/peephole/scheduling/opt_partial/opt_pointer_analysis/opt_unroll_count/
 * opt_unroll_instr_count (register_coloring is not recognised by any of them); -g, -sym, C++,
 * ANSI modes, -inline modes, -proc 750/604/generic and ~25 other flags on 1.1/1.2.5n/1.3.2/2.6;
 * chained assignments, NULL vs 0, mixed field types, an inline setter taking the values or one
 * zero, locals holding the values, indexing; 10 minutes of decomp-permuter (no improvement at all).
 * A struct copy from a local template does give one register per field (r10..r5), but it loads
 * the template from memory, so it isn't the original's code.
 */

void fn_80298544(NjTexRef* refs, s32 n) {
    s32 i;
    lbl_80347ED4 = refs;
    lbl_80347ED0 = n;
    for (i = 0; i < n; i++) {
        refs->w00 = 0;
        refs->w04 = 0;
        refs->key = -1;
        refs->mem = NULL;
        refs->refs = 0;
        refs->w14 = 0;
        refs++;
    }
}
