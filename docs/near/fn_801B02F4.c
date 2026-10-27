/* the unit only has extern void fn_801B02F4(void); rename it out of the way for this scratch file */
#define fn_801B02F4 fn_801B02F4_old
#include "../src/game/unit_80199B9C.c" /* found through -i include */
#undef fn_801B02F4

void fn_801B02F4(Task2_801B0470* t) {
    void (*cb)(Task2_801B0470*);
    f32 z;
    switch (((u8*)t)[0x19]) {
    case 0:
    case 0xFE:
        if (t->data->b0 == 1) {
            return;
        }
        UiObjUpdate(&t->pan->ui);
        UiObjCalcRect(&t->pan->ui);
        UiLayoutDrawPart((NJS_TEXLIST**)&menu_sprites.texlist8, (void*)lbl_802B77FC, 1, t->pan->ui.rect,
                         t->data->s6, t->pan->ui.z, t->pan->ui.alpha, 1.0f);
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
