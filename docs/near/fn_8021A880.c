/* fn_8021A880, fn_8021A940, fn_8021A9C4, fn_8021AB60, fn_8021AC20, fn_8021ACE0, fn_8021ADA0
 * (unit_80219378.c): the ship stat getters, one per ShipData stat. Near misses.
 *
 * Each reads the ship's base stat, adds fn_8021A2B0's bonus for that stat (not the two SP ones)
 * and the level times the per-level gain, and caps the sum (99 for SP, 999 for the others,
 * 999999 for HP). To try them, give the unit's `Src` a `s8 level` at 0x01 and paste these after
 * fn_8021AA48 (they use the unit's GetEnt/InRange inlines).
 *
 * Every instruction is right except two: the original takes the zero for GetEnt's `e = NULL` and
 * InRange's `r = 0` from the register that already holds the result's 0 (`mr r31, r3`,
 * `mr r0, r3`), where this emits `li r31, 0` and copies that. fn_8021ADA0 also differs in where
 * the 999999 constant lives. Tried: early returns, a ternary or if/else for the cap, the cap
 * before or after the compare, the sum as one expression, `int` types, hand-inlined lookups,
 * declaration orders, and the permuter (10 minutes on fn_8021A940, no improvement on 205).
 */

s32 fn_8021A880(Src* p, void* q)
{
    s32 res = 0;
    if (p != NULL && q != NULL) {
        ShipData* e = GetEnt(p->id);
        if (e != NULL) {
            s32 v = e->dodge;
            v += fn_8021A2B0(p, q, 6);
            v += p->level * e->dodge_up;
            res = 999;
            if (v < 999) {
                res = v;
            }
        }
    }
    return res;
}

s32 fn_8021A940(Src* p, void* q)
{
    s32 res = 0;
    if (p != NULL && q != NULL) {
        ShipData* e = GetEnt(p->id);
        if (e != NULL) {
            s32 v = e->sp;
            v += p->level * e->sp_up;
            res = 99;
            if (v < 99) {
                res = v;
            }
        }
    }
    return res;
}

s32 fn_8021A9C4(Src* p, void* q)
{
    s32 res = 0;
    if (p != NULL && q != NULL) {
        ShipData* e = GetEnt(p->id);
        if (e != NULL) {
            s32 v = e->sp_max;
            v += p->level * e->sp_max_up;
            res = 99;
            if (v < 99) {
                res = v;
            }
        }
    }
    return res;
}

s32 fn_8021AB60(Src* p, void* q)
{
    s32 res = 0;
    if (p != NULL && q != NULL) {
        ShipData* e = GetEnt(p->id);
        if (e != NULL) {
            s32 v = e->quick;
            v += fn_8021A2B0(p, q, 4);
            v += p->level * e->quick_up;
            res = 999;
            if (v < 999) {
                res = v;
            }
        }
    }
    return res;
}

s32 fn_8021AC20(Src* p, void* q)
{
    s32 res = 0;
    if (p != NULL && q != NULL) {
        ShipData* e = GetEnt(p->id);
        if (e != NULL) {
            s32 v = e->mag_def;
            v += fn_8021A2B0(p, q, 3);
            v += p->level * e->mag_def_up;
            res = 999;
            if (v < 999) {
                res = v;
            }
        }
    }
    return res;
}

s32 fn_8021ACE0(Src* p, void* q)
{
    s32 res = 0;
    if (p != NULL && q != NULL) {
        ShipData* e = GetEnt(p->id);
        if (e != NULL) {
            s32 v = e->defense;
            v += fn_8021A2B0(p, q, 2);
            v += p->level * e->defense_up;
            res = 999;
            if (v < 999) {
                res = v;
            }
        }
    }
    return res;
}

s32 fn_8021ADA0(Src* p, void* q)
{
    s32 res = 0;
    if (p != NULL && q != NULL) {
        ShipData* e = GetEnt(p->id);
        if (e != NULL) {
            s32 v = e->hp_max;
            v += fn_8021A2B0(p, q, 0);
            v += p->level * e->hp_up;
            res = 999999;
            if (v < 999999) {
                res = v;
            }
        }
    }
    return res;
}
