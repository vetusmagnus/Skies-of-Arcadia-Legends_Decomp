/* Near miss: fn_801B02F4 of game/unit_80199B9C.c (95/95 instructions, registers exact, 6 lines):
 * the original schedules `lis r4, base` before the `lbz r0, 0x19(r3)` of the switch, ours after.
 * Reading `state` through the Task parameter while the typed pointer is the copy (as fn_801ACE70
 * and fn_801AC16C do) fixed the registers; no entry form tried moves the lis (local state
 * variable, void* parameter, declaration order, a label, the typed pointer as the parameter).
 * fn_801B0B9C has the same entry.
 *
 *   python tools/match/fdiff.py docs/near/fn_801B02F4.c fn_801B02F4
 */
/* the unit only has extern void fn_801B02F4(void); rename it out of the way for this scratch file */
#define fn_801B02F4 fn_801B02F4_old
#include "../src/game/unit_80199B9C.c" /* found through -i include */
#undef fn_801B02F4

void fn_801B02F4(Task* task) {
    Task2_801B0470* t = (Task2_801B0470*)task;
    void (*cb)(Task2_801B0470*);
    f32 z;
    switch (task->state) {
    case 0:
    case 0xFE:
        if (t->data->b0 == 1) {
            return;
        }
        UiObjUpdate(&t->pan->ui);
        UiObjCalcRect(&t->pan->ui);
        UiLayoutDrawPart((NJS_TEXLIST**)&menu_sprites.texlist8, (void*)lbl_802B77FC, 1, t->pan->ui.rect,
                         t->pan->ui.z, t->pan->ui.alpha, 1.0f, t->data->s6);
        UiLayoutDraw((NJS_TEXLIST**)&menu_sprites.texlist8, (LayoutPart*)lbl_802B7894[t->data->s6 * 2],
                     (u32)lbl_802B7894[t->data->s6 * 2 + 1], t->pan->ui.rect, t->pan->ui.z,
                     t->pan->ui.alpha, 1.0f);
        UiLayoutDraw((NJS_TEXLIST**)&menu_sprites.texlist8, (LayoutPart*)lbl_802B77AC, 1, &t->pan->ui.rect[2],
                     t->pan->ui.z, 1.0f, 1.0f);
        cb = t->data->cb;
        if (cb != 0) {
            z = TextGetZ();
            TextPushColor();
            cb(t);
            TextPopColor(1);
            TextSetZ(z);
        }
        break;
    case 0xFF:
        MenuDummy();
        ((u8*)t)[0x18] |= 0x40;
        break;
    }
}
