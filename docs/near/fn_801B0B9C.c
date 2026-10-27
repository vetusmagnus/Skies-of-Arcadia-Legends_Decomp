/* the unit declares it void(void); renamed here only so the typed definition can follow */
#define fn_801B0B9C fn_801B0B9C_unitdecl
#include "../src/game/unit_80199B9C.c" /* through -i include */
#undef fn_801B0B9C

typedef struct Sel_801B0B9C { u8 pad0[0x18]; u16 cur; } Sel_801B0B9C; /* cur at 0x18 */
typedef struct Pos_801B0B9C { f32 x, y; u16 idx; } Pos_801B0B9C;
typedef struct Task_801B0B9C {
    u8 pad00[0x18];
    u8 flags;                 /* 0x18 */
    u8 state;                 /* 0x19 */
    u8 pad1a[0x24 - 0x1a];
    u8* flag;                 /* 0x24 */
    Panel_801B0DF8* pan;      /* 0x28 */
    s32 f2C;
    Sel_801B0B9C* c;          /* 0x30 */
    u8 pad34[4];
    Pos_801B0B9C* d;          /* 0x38 */
} Task_801B0B9C;

void fn_801B0B9C(Task_801B0B9C* t) {
    const LT* e;
    u32 i;
    u32 n;
    s32 mask;
    f32 z;
    switch (t->state) {
    case 0:
    case 0xFE:
        if (t->flag[0] == 1) {
            return;
        }
        UiObjUpdate(&t->pan->ui);
        UiObjCalcRect(&t->pan->ui);
        z = TextGetZ();
        TextPushColor();
        TextSetColor(0xFF201008);
        UiLayoutDraw((NJS_TEXLIST**)&menu_sprites.texlist8, (LayoutPart*)lbl_802B79F4, 2, t->pan->ui.rect, t->pan->ui.z, t->pan->ui.alpha, 1.0f);
        mask = fn_801F4CA0();
        i = n = 0;
        e = &((const LT*)lbl_802B7B20)[i];
        do {
            if (mask & (1 << i)) {
                Panel_801B0DF8* pan = t->pan;
                UiLayoutDraw((NJS_TEXLIST**)&menu_sprites.texlist8, e->parts, e->count, pan->ui.rect, pan->ui.z,
                             i == t->c->cur ? pan->ui.alpha : pan->ui.alpha - 0.5f,
                             *(f32*)((u8*)pan + 0x38));
                n++;
            }
            i++;
            e++;
        } while (i < 6);
        if (n == 0) {
            TextPrint(24.0f + (8.0f + t->pan->ui.rect[0]), 17.0f + t->pan->ui.rect[1], (const char*)lbl_802EC04C[8]);
        } else if (n >= 2) {
            t->d->idx = 3;
            t->d->x = t->pan->ui.rect[0] + (f32)(t->c->cur * 0x30);
            t->d->y = t->pan->ui.rect[1];
            fn_801B5D68((Task3_801B5D68*)t);
        }
        UiLayoutDraw((NJS_TEXLIST**)&menu_sprites.texlist8, (LayoutPart*)lbl_802B7B50, 1, &t->pan->ui.rect[2], t->pan->ui.z, 1.0f, 1.0f);
        TextPopColor(1);
        TextSetZ(z);
        break;
    case 0xFF:
        MenuDummy();
        t->flags |= 0x40;
        break;
    }
}
