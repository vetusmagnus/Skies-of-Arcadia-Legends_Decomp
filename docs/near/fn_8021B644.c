/* fn_8021B644 (unit_80219378.c, 728 bytes): picks a ship. Copies its name into the save record,
 * clears the cannon and accessory slots, then fills them from the ship's defaults, and rebuilds the
 * ship's stats (fn_8021AF94) from the crew list like fn_8021B4B4/fn_8021B91C. A near miss.
 *
 * Paste after fn_8021B4B4 in the unit (it uses the unit's InRange, GetEnt, CannonValid, GearValid
 * and fill inlines, and `extern void fn_801EFC88(s16)`). Everything matches except the crew-list
 * fill at the end: the list pointer and the count swap registers (r31/r29; 16 lines). The slot
 * loops only matched once they were inlines of their own (SetCannons/SetGears), with plain loops
 * they are 22 lines off. Note the original writes the accessory ids into the cannon slots
 * (s1580[slot]), as below.
 */

static inline s32 GearSlotValid(s32 v)
{
    s32 r = 0;
    if (v >= 0 && v < 3) {
        r = 1;
    }
    return r;
}

static inline void SetCannonSlot(Save1568* s, s32 slot, s16 id)
{
    if (s != NULL && InRange(slot) && CannonValid(id)) {
        lbl_8030B7F4.x1568.s1580[slot] = id;
        fn_801EFF0C(id);
    }
}

static inline void SetGearSlot(Save1568* s, s32 slot, s16 id)
{
    if (s != NULL && GearSlotValid(slot) && GearValid(id)) {
        lbl_8030B7F4.x1568.s1580[slot] = id;
        fn_801EFF0C(id);
    }
}

static inline void ClearCannons(Save1568* s)
{
    s32 i;
    if (s != NULL) {
        for (i = 0; i < 5; i++) {
            lbl_8030B7F4.x1568.s1580[i] = -1;
        }
    }
}

static inline void ClearGears(Save1568* s)
{
    s32 i;
    if (s != NULL) {
        for (i = 0; i < 3; i++) {
            lbl_8030B7F4.x1568.s158a[i] = -1;
        }
    }
}

static inline void SetCannons(Save1568* s, ShipData* e)
{
    s32 i;
    if (s != NULL && e != NULL) {
        for (i = 0; i < 5; i++) {
            SetCannonSlot(s, i, e->cannon[i]);
        }
    }
}

static inline void SetGears(Save1568* s, ShipData* e)
{
    s32 i;
    if (s != NULL && e != NULL) {
        for (i = 0; i < 3; i++) {
            SetGearSlot(s, i, e->acc[i]);
        }
    }
}

void fn_8021B644(s32 ship) {
    s8 buf[22];
    if (InRange(ship)) {
        ShipData* e = GetEnt(ship);
        Save1568* s = &lbl_8030B7F4.x1568;
        s->b1568 = ship;
        if (s != NULL && e != NULL) {
            MemCopy(s->name, e->name, 0x11);
            lbl_8030B7F4.x1568.name[0x10] = 0;
        }
        ClearCannons(s);
        ClearGears(s);
        fn_801EFC88(0x1ae);
        SetCannons(s, e);
        SetGears(s, e);
        fn_8021B3B4();
        fill(buf);
        fn_8021AF94(&lbl_8030B4D4.limit, s, buf);
    }
}
