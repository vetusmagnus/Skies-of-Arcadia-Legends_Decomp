/* Near miss: fn_801B1B3C of game/unit_80199B9C.c (the shop's top menu panel, the task
 * fn_801B2310 creates). 217/217 instructions; 10 diff lines: the argument setup of the
 * UiLayoutDrawPart call (the cursor) is scheduled differently (lbz r7 of c->part comes first
 * here, last in the original). Everything else, registers included, matches.
 *
 *   python tools/match/fdiff.py build/agents/s4/fn_801B1B3C.c fn_801B1B3C
 */
/* The unit declares this as void(void) until it is merged; rename that declaration away. */
#define fn_801B1B3C fn_801B1B3C_decl
/* The unit has fn_801B94F0 return u32; the caller compares it signed (cmpwi), so it is s32. */
#define fn_801B94F0 fn_801B94F0_u32
#include "../src/game/unit_80199B9C.c" /* found through -i include */
#undef fn_801B1B3C
#undef fn_801B94F0
extern s32 fn_801B94F0(void);

/* The shop's top menu panel (the task fn_801B2310 creates). */
typedef struct Cur_1B3C {
    f32 x, y;     /* 0x00 draw position */
    f32 ox, oy;   /* 0x08 offset from the panel */
    f32 scale;    /* 0x10 pulse */
    u16 angle;    /* 0x14 */
    u8 pad16[2];
    s16 s18;
    s16 s1A;
    u16 sel;      /* 0x1C selected tab */
    u8 part;      /* 0x1E layout part, 0xFF none */
    u8 flags;     /* 0x1F 1 shown, 2 pulsing */
} Cur_1B3C;
typedef struct Arrow_1B3C {
    f32 x, y;     /* 0x00 */
    u16 idx;      /* 0x08 */
    u16 state;    /* 0x0A */
} Arrow_1B3C;
typedef struct Task_1B3C {
    u8 pad0[0x18];
    u8 flags; /* 0x18 */
    u8 state; /* 0x19 */
    u8 pad1A[0xA];
    u8* a;                /* 0x24 */
    Panel_801B2310* pan;  /* 0x28 */
    s32 f2C;
    Cur_1B3C* c;          /* 0x30 */
    u8 pad34[4];
    Arrow_1B3C* d;        /* 0x38 */
} Task_1B3C;

extern f32 njCos(s32 a);
extern void fn_801B1EA0(Task_1B3C* t);

void fn_801B1B3C(Task_1B3C* t) {
    NJS_TEXLIST** tl;
    f32 z;
    f32 s;

    if (lbl_803475D8 != 0) {
        t->state = 0xFF;
    }
    switch (t->state) {
    case 0:
    case 1:
    case 0xFE:
        if (t->a[0] == 1) {
            return;
        }
        UiObjUpdate(&t->pan->ui);
        tl = (NJS_TEXLIST**)&menu_sprites.texlist8;
        UiLayoutDraw(tl, (LayoutPart*)lbl_802B71EC, 3, &t->pan->ui.x, t->pan->ui.z, 1.0f, 1.0f);
        z = -42.75f + t->pan->ui.z;
        if (fn_801B94F0()) {
            s32 i;
            const void* const* p;
            UiLayoutDraw(tl, (LayoutPart*)lbl_802B7304[t->c->sel * 2], (u32)lbl_802B7304[t->c->sel * 2 + 1], &t->pan->ui.x, z, 1.0f, 1.0f);
            z -= 0.25f;
            for (i = 0, p = lbl_802B7304; i < 5; i++, p += 2) {
                if (t->c->sel != i && fn_801B952C(i)) {
                    UiLayoutDraw(tl, (LayoutPart*)p[0], 2, &t->pan->ui.x, z, 0.7f, 1.0f);
                    z -= 0.25f;
                }
            }
        } else {
            UiLayoutDraw(tl, (LayoutPart*)lbl_802B72F0, 1, &t->pan->ui.x, z, 1.0f, 1.0f);
        }
        switch (t->state) {
        case 0:
            if (fn_801B94F0()) {
                if (t->d->state == 0) {
                    t->d->state = 1;
                }
                t->d->idx = 1;
                t->d->x = t->pan->ui.x + t->pan->ui.rdx + (f32)(t->c->sel * 48);
                t->d->y = t->pan->ui.y + t->pan->ui.rdy;
            } else {
                t->d->state = 0;
            }
            break;
        case 1: {
            UiObj* ui;
            Cur_1B3C* c;
            t->d->idx = 2;
            t->d->x = t->pan->ui.x;
            t->d->y = t->pan->ui.y;
            c = t->c;
            ui = &t->pan->ui;
            if ((c->flags & 1) && c->part != 0xFF) {
                s = 0.0f;
                if (c->flags & 2) {
                    c->x = ui->x + c->ox;
                    c->y = ui->y + c->oy;
                    c->scale = 0.3f * njCos(c->angle) + 1.0f;
                    c->angle += 0x800;
                    s = c->scale;
                }
                UiLayoutDrawPart(tl, (void*)lbl_802B6A64, 1, &c->x, c->part, ui->z, s, 1.0f);
            }
            break;
        }
        }
        fn_801B5D68((Task3_801B5D68*)t);
        fn_801B1EA0(t);
        break;
    case 0xFF:
        MenuDummy(t);
        t->flags |= 0x40;
        break;
    }
}
