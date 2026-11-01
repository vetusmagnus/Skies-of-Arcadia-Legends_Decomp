#include "types.h"
#include "game/task.h"
#include "game/uiobj.h"
#include "game/sprite.h"
#include "game/menu.h"
#include "game/text.h"
#define MenuDummy MenuDummy_hdr
#undef MenuDummy
#define TextPrint TextPrint_hdr
#undef TextPrint
typedef struct { UiObj o; const char* text; u16 h50, h52, h54, h56; } MObj;
typedef struct { u8 pad[0x28]; MObj* obj; } MP;
typedef struct { u8 pad[0x28]; MObj* obj; MObj* obj2; } MP2;
typedef struct { s32 a; s16 b; s16 c; } Q;
/* The choice menu task fn_801BEB10 creates: a menu task with three more blocks. */
typedef struct { MenuTask m; void* p28; Q* p2c; void* p30; } T;
void fn_801BE670(Task* t);
typedef struct Ctl { u8 pad0[0x11c]; u32 v; u8 pad1[4]; s32 out; } Ctl;
typedef struct Obj { u8 pad[0x24]; Ctl *c; } Obj;
extern u32 lbl_803471C0;
void fn_80217830(u32 h);

T* fn_801BEB10(void* a, s32 b, s32 c, s32 d) {
    extern void MenuDummy(Task* t);
    extern TextNode* TextPrint(s32 x, s32 y, const char *str);
    extern void* fn_802267AC(void* a, void (*b)(Task*));
    extern void* fn_801E1A74(s32 a, s32 b);
    extern T* lbl_803471B8;
    extern s32 lbl_803473C0;
    extern u8 lbl_803473BF;
    extern u16 lbl_803473BC;
    u32 i;
    lbl_803473C0 = 1;
    lbl_803471B8 = fn_802267AC(a, fn_801BE670);
    lbl_803471B8->m.work = fn_801E1A74(1, 0x2C0);
    lbl_803471B8->p2c = fn_801E1A74(1, 0x224);
    lbl_803471B8->p30 = fn_801E1A74(1, 0x6CC);
    lbl_803471B8->p28 = fn_801E1A74(1, 0x5B8);
    lbl_803471B8->p2c->a = 0;
    lbl_803471B8->p2c->b = 0;
    lbl_803471B8->p2c->c = 0;
    for (i = 0; i < 19; i++) {
        lbl_803471B8->m.work->parts[i] = NULL;
    }
    lbl_803471B8->m.work->x128 = (u8)d;
    lbl_803473BF = b;
    lbl_803473BC = c;
    return lbl_803471B8;
}

typedef struct { u32 held; u8 pad4[4]; u32 trig; } PadState;
extern PadState* lbl_80311A60[];
extern u8 lbl_803473BF;
extern s32 fn_801C09F8(s32 a, s32 b);
void fn_801C08B4(s32 msg);

#define OBJ(n) t->m.work->parts[n]->obj

void fn_801BECA8(T* t)
{
    s32 cmd;

    switch (t->m.work->state) {
    case 0:
        UiObjMoveToX(OBJ(0), 6, 4, -8.0f);
        UiObjSetCommand(OBJ(0), 15, 0);
        UiObjMoveToX(OBJ(1), 6, 4, -8.0f);
        UiObjSetCommand(OBJ(1), 15, 2);
        UiObjMoveToX(OBJ(3), 6, 4, -8.0f);
        UiObjSetCommand(OBJ(3), 15, 4);
        UiObjMoveToX(OBJ(4), 6, 4, -8.0f);
        UiObjSetCommand(OBJ(4), 15, 6);
        UiObjMoveToX(OBJ(5), 6, 4, -8.0f);
        UiObjSetCommand(OBJ(5), 15, 8);
        UiObjMoveToX(OBJ(6), 6, 4, -8.0f);
        UiObjSetCommand(OBJ(6), 15, 10);
        t->m.work->state = 1;
        break;
    case 1:
        if (!UiObjIsBusy(OBJ(6))) {
        open:
            UiObjSetCommand(OBJ(0), 20, 0);
            UiObjSetCommand(OBJ(1), 20, 0);
            UiObjSetCommand(OBJ(3), 21, 0);
            t->m.work->state = 2;
            t->m.work->sel = 0;
        } else if (lbl_80311A60[0]->trig & 0x100) {
            MenuPartsFinish(&t->m);
            goto open;
        }
        break;
    case 2:
        if (!UiObjIsBusy(OBJ(3)) && !UiObjIsBusy(OBJ(4)) && !UiObjIsBusy(OBJ(5)) && !UiObjIsBusy(OBJ(6))) {
            t->m.work->state = 3;
        } else if ((lbl_80311A60[0]->held & 8) && (lbl_80311A60[0]->held & 4)) {
            MenuPartsFinish(&t->m);
            t->m.work->state = 3;
        }
        break;
    case 3:
        if (fn_801C09F8(0, 1)) {
            t->m.work->state = 0xa;
            MenuPlaySe(5);
        } else {
            if (fn_801C09F8(0, 4)) {
                if (t->m.work->sel == 0) {
                    t->m.work->sel = 4;
                }
                t->m.work->sel--;
                goto cursor;
            }
            if (fn_801C09F8(0, 5)) {
                t->m.work->sel++;
                if (t->m.work->sel == 4) {
                    t->m.work->sel = 0;
                }
            cursor:
                MenuPlaySe(4);
                cmd = 20;
                if (t->m.work->sel == 0) {
                    cmd = 21;
                }
                UiObjSetCommand(OBJ(3), cmd, 0);
                cmd = 20;
                if (t->m.work->sel == 1) {
                    cmd = 21;
                }
                UiObjSetCommand(OBJ(4), cmd, 0);
                cmd = 20;
                if (t->m.work->sel == 2) {
                    cmd = 21;
                }
                UiObjSetCommand(OBJ(5), cmd, 0);
                cmd = 20;
                if (t->m.work->sel == 3) {
                    cmd = 21;
                }
                UiObjSetCommand(OBJ(6), cmd, 0);
            } else {
                if (lbl_80311A60[0]->trig & 0x100) {
                    MenuPartsFinish(&t->m);
                    fn_801C08B4(2);
                    switch (t->m.work->sel) {
                    case 0:
                        UiObjMoveToY(OBJ(1), 6, 4, 164.0f);
                        UiObjSetCommand(OBJ(1), 15, 0);
                        UiObjMoveToY(OBJ(3), 6, -1, 100.0f);
                        UiObjSetCommand(OBJ(3), 15, 0);
                        UiObjMoveToX(OBJ(4), 6, -1, -260.0f);
                        UiObjSetCommand(OBJ(4), 15, 0);
                        UiObjMoveToX(OBJ(5), 6, 4, -260.0f);
                        UiObjSetCommand(OBJ(5), 15, 1);
                        UiObjMoveToX(OBJ(6), 6, 4, -260.0f);
                        UiObjSetCommand(OBJ(6), 15, 2);
                        t->m.work->x3 = 0;
                        t->m.work->state = 4;
                        break;
                    case 1:
                        UiObjMoveToY(OBJ(1), 6, 4, 164.0f);
                        UiObjSetCommand(OBJ(1), 15, 0);
                        UiObjMoveToY(OBJ(4), 6, -1, 100.0f);
                        UiObjSetCommand(OBJ(4), 15, 0);
                        UiObjMoveToX(OBJ(3), 6, -1, -260.0f);
                        UiObjSetCommand(OBJ(3), 15, 0);
                        UiObjMoveToX(OBJ(5), 6, 4, -260.0f);
                        UiObjSetCommand(OBJ(5), 15, 1);
                        UiObjMoveToX(OBJ(6), 6, 4, -260.0f);
                        UiObjSetCommand(OBJ(6), 15, 2);
                        t->m.work->x3 = 0;
                        t->m.work->state = 6;
                        break;
                    case 2:
                        UiObjMoveToX(OBJ(1), 6, 4, -260.0f);
                        UiObjSetCommand(OBJ(1), 15, 0);
                        UiObjMoveToX(OBJ(3), 6, -1, -260.0f);
                        UiObjSetCommand(OBJ(3), 15, 0);
                        UiObjMoveToX(OBJ(4), 6, 4, -260.0f);
                        UiObjSetCommand(OBJ(4), 15, 0);
                        UiObjMoveToY(OBJ(5), 6, -1, 100.0f);
                        UiObjSetCommand(OBJ(5), 15, 1);
                        UiObjMoveToX(OBJ(6), 6, 4, -260.0f);
                        UiObjSetCommand(OBJ(6), 15, 2);
                        t->m.work->x3 = 0;
                        t->m.work->state = 8;
                        break;
                    case 3:
                        t->m.work->state = 0xa;
                        break;
                    }
                }
            }
        }
        break;
    case 8:
        if (!UiObjIsBusy(OBJ(1))) {
            t->m.work->state = 9;
            OBJ(5)->alpha_en = 0;
            UiObjSetCommand(OBJ(5), 20, 0);
        }
        break;
    case 9:
        t->m.state = 10;
        t->m.work->state = 0x11;
        break;
    case 4:
        if (!UiObjIsBusy(OBJ(1))) {
            t->m.work->state = 5;
            OBJ(3)->alpha_en = 0;
            UiObjSetCommand(OBJ(3), 20, 0);
        }
        break;
    case 5:
        t->m.state = 8;
        t->m.work->state = 0xd;
        break;
    case 6:
        if (!UiObjIsBusy(OBJ(1))) {
            t->m.work->state = 7;
            OBJ(4)->alpha_en = 0;
            UiObjSetCommand(OBJ(4), 20, 0);
        }
        break;
    case 7:
        t->m.state = 9;
        t->m.work->state = 0xf;
        break;
    case 0xa:
        UiObjSetCommand(OBJ(0), 21, 0);
        UiObjSetCommand(OBJ(1), 21, 0);
        UiObjSetCommand(OBJ(3), 20, 0);
        UiObjSetCommand(OBJ(4), 20, 0);
        UiObjSetCommand(OBJ(5), 20, 0);
        UiObjSetCommand(OBJ(6), 20, 0);
        t->m.work->state = 0xb;
        break;
    case 0xb:
        if (!UiObjIsBusy(OBJ(0))) {
            UiObjMoveToX(OBJ(0), 6, 5, -260.0f);
            UiObjSetCommand(OBJ(0), 15, 0);
            UiObjMoveToX(OBJ(1), 6, 5, -260.0f);
            UiObjSetCommand(OBJ(1), 15, 2);
            UiObjMoveToX(OBJ(3), 6, 5, -260.0f);
            UiObjSetCommand(OBJ(3), 15, 4);
            UiObjMoveToX(OBJ(4), 6, 5, -260.0f);
            UiObjSetCommand(OBJ(4), 15, 6);
            UiObjMoveToX(OBJ(5), 6, 5, -260.0f);
            UiObjSetCommand(OBJ(5), 15, 8);
            UiObjMoveToX(OBJ(6), 6, 5, -260.0f);
            UiObjSetCommand(OBJ(6), 15, 10);
            t->m.work->state = 0xc;
        } else if (fn_801C09F8(0, 1)) {
            MenuPartsFinish(&t->m);
            t->m.work->state = 0xc;
        }
        break;
    case 0xc:
        if (!UiObjIsBusy(OBJ(6))) {
            t->m.state = 0xc;
        }
        break;
    case 0x11:
        OBJ(5)->alpha_en = 1;
        UiObjSetCommand(OBJ(5), 21, 0);
        t->m.work->state = 0x12;
    case 0x12:
        if (!UiObjIsBusy(OBJ(5))) {
            UiObjMoveToX(OBJ(1), 6, 5, -8.0f);
            UiObjSetCommand(OBJ(1), 15, 0);
            UiObjMoveToY(OBJ(5), 6, -1, 276.0f);
            UiObjSetCommand(OBJ(5), 15, 0);
            UiObjMoveToX(OBJ(4), 6, -1, -8.0f);
            UiObjSetCommand(OBJ(4), 15, 0);
            UiObjMoveToX(OBJ(3), 6, 5, -8.0f);
            UiObjSetCommand(OBJ(3), 15, 1);
            UiObjMoveToX(OBJ(6), 6, 5, -8.0f);
            UiObjSetCommand(OBJ(6), 15, 2);
            t->m.work->state = 0x13;
        }
        break;
    case 0xd:
        OBJ(3)->alpha_en = 1;
        UiObjSetCommand(OBJ(3), 21, 0);
        t->m.work->state = 0xe;
    case 0xe:
        if (!UiObjIsBusy(OBJ(3))) {
            UiObjMoveToY(OBJ(1), 6, 5, 100.0f);
            UiObjSetCommand(OBJ(1), 15, 0);
            UiObjMoveToY(OBJ(3), 6, -1, 148.0f);
            UiObjSetCommand(OBJ(3), 15, 0);
            UiObjMoveToX(OBJ(4), 6, -1, -8.0f);
            UiObjSetCommand(OBJ(4), 15, 0);
            UiObjMoveToX(OBJ(5), 6, 5, -8.0f);
            UiObjSetCommand(OBJ(5), 15, 1);
            UiObjMoveToX(OBJ(6), 6, 5, -8.0f);
            UiObjSetCommand(OBJ(6), 15, 2);
            t->m.work->state = 0x13;
        }
        break;
    case 0xf:
        OBJ(4)->alpha_en = 1;
        UiObjSetCommand(OBJ(4), 21, 0);
        t->m.work->state = 0x10;
    case 0x10:
        if (!UiObjIsBusy(OBJ(4))) {
            UiObjMoveToY(OBJ(1), 6, 5, 100.0f);
            UiObjSetCommand(OBJ(1), 15, 0);
            UiObjMoveToY(OBJ(4), 6, -1, 212.0f);
            UiObjSetCommand(OBJ(4), 15, 0);
            UiObjMoveToX(OBJ(3), 6, -1, -8.0f);
            UiObjSetCommand(OBJ(3), 15, 0);
            UiObjMoveToX(OBJ(5), 6, 5, -8.0f);
            UiObjSetCommand(OBJ(5), 15, 1);
            UiObjMoveToX(OBJ(6), 6, 5, -8.0f);
            UiObjSetCommand(OBJ(6), 15, 2);
            t->m.work->state = 0x13;
        }
        break;
    case 0x13:
        if (fn_801C09F8(0, 1)) {
            MenuPartsFinish(&t->m);
            t->m.work->state = 3;
        } else if (!UiObjIsBusy(OBJ(4))) {
            t->m.work->state = 3;
        }
        break;
    }
}
#undef OBJ

#define OBJ(n) t->m.work->parts[n]->obj

void fn_801BFC84(T* t)
{
    s32 cmd;

    switch (t->m.work->state) {
    case 0:
        UiObjMoveToX(OBJ(0), 6, 4, -8.0f);
        UiObjSetCommand(OBJ(0), 15, 0);
        UiObjMoveToX(OBJ(1), 6, 4, -8.0f);
        UiObjSetCommand(OBJ(1), 15, 2);
        UiObjMoveToX(OBJ(3), 6, 4, -8.0f);
        UiObjSetCommand(OBJ(3), 15, 4);
        UiObjMoveToX(OBJ(4), 6, 4, -8.0f);
        UiObjSetCommand(OBJ(4), 15, 6);
        UiObjMoveToX(OBJ(5), 6, 4, -8.0f);
        UiObjSetCommand(OBJ(5), 15, 8);
        t->m.work->state = 1;
        break;
    case 1:
        if (!UiObjIsBusy(OBJ(5))) {
        open:
            UiObjSetCommand(OBJ(0), 20, 0);
            UiObjSetCommand(OBJ(1), 20, 0);
            UiObjSetCommand(OBJ(3), 21, 0);
            t->m.work->state = 2;
            t->m.work->sel = 0;
        } else if (lbl_80311A60[0]->trig & 0x100) {
            MenuPartsFinish(&t->m);
            goto open;
        }
        break;
    case 2:
        if (!UiObjIsBusy(OBJ(3)) && !UiObjIsBusy(OBJ(4)) && !UiObjIsBusy(OBJ(5))) {
            t->m.work->state = 3;
        } else if ((lbl_80311A60[0]->held & 8) && (lbl_80311A60[0]->held & 4)) {
            MenuPartsFinish(&t->m);
            t->m.work->state = 3;
        }
        break;
    case 3:
        if (fn_801C09F8(0, 1)) {
            t->m.work->state = 0xa;
            MenuPlaySe(5);
        } else {
            if (fn_801C09F8(0, 4)) {
                if (t->m.work->sel == 0) {
                    t->m.work->sel = 3;
                }
                t->m.work->sel--;
                goto cursor;
            }
            if (fn_801C09F8(0, 5)) {
                t->m.work->sel++;
                if (t->m.work->sel == 3) {
                    t->m.work->sel = 0;
                }
            cursor:
                MenuPlaySe(4);
                cmd = 20;
                if (t->m.work->sel == 0) {
                    cmd = 21;
                }
                UiObjSetCommand(OBJ(3), cmd, 0);
                cmd = 20;
                if (t->m.work->sel == 1) {
                    cmd = 21;
                }
                UiObjSetCommand(OBJ(4), cmd, 0);
                cmd = 20;
                if (t->m.work->sel == 2) {
                    cmd = 21;
                }
                UiObjSetCommand(OBJ(5), cmd, 0);
            } else {
                if (lbl_80311A60[0]->trig & 0x100) {
                    MenuPartsFinish(&t->m);
                    fn_801C08B4(2);
                    switch (t->m.work->sel) {
                    case 0:
                        UiObjMoveToY(OBJ(1), 6, 4, 164.0f);
                        UiObjSetCommand(OBJ(1), 15, 0);
                        UiObjMoveToY(OBJ(3), 6, -1, 100.0f);
                        UiObjSetCommand(OBJ(3), 15, 0);
                        UiObjMoveToX(OBJ(4), 6, -1, -260.0f);
                        UiObjSetCommand(OBJ(4), 15, 0);
                        UiObjMoveToX(OBJ(5), 6, 4, -260.0f);
                        UiObjSetCommand(OBJ(5), 15, 2);
                        t->m.work->x3 = 0;
                        t->m.work->state = 4;
                        break;
                    case 1:
                        UiObjMoveToY(OBJ(1), 6, 4, 164.0f);
                        UiObjSetCommand(OBJ(1), 15, 0);
                        UiObjMoveToY(OBJ(4), 6, -1, 100.0f);
                        UiObjSetCommand(OBJ(4), 15, 0);
                        UiObjMoveToX(OBJ(3), 6, -1, -260.0f);
                        UiObjSetCommand(OBJ(3), 15, 0);
                        UiObjMoveToX(OBJ(5), 6, 4, -260.0f);
                        UiObjSetCommand(OBJ(5), 15, 2);
                        t->m.work->x3 = 0;
                        t->m.work->state = 6;
                        break;
                    case 2:
                        t->m.work->state = 0xa;
                        break;
                    }
                }
            }
        }
        break;
    case 4:
        if (!UiObjIsBusy(OBJ(1))) {
            t->m.work->state = 5;
            OBJ(3)->alpha_en = 0;
            UiObjSetCommand(OBJ(3), 20, 0);
        }
        break;
    case 5:
        if (lbl_803473BF == 0) {
            t->m.state = 6;
        } else {
            t->m.state = 8;
        }
        t->m.work->state = 0xd;
        break;
    case 6:
        if (!UiObjIsBusy(OBJ(1))) {
            t->m.work->state = 7;
            OBJ(4)->alpha_en = 0;
            UiObjSetCommand(OBJ(4), 20, 0);
        }
        break;
    case 7:
        if (lbl_803473BF == 0) {
            t->m.state = 7;
        } else {
            t->m.state = 9;
        }
        t->m.work->state = 0xf;
        break;
    case 0xa:
        UiObjSetCommand(OBJ(0), 21, 0);
        UiObjSetCommand(OBJ(1), 21, 0);
        UiObjSetCommand(OBJ(3), 20, 0);
        UiObjSetCommand(OBJ(4), 20, 0);
        UiObjSetCommand(OBJ(5), 20, 0);
        t->m.work->state = 0xb;
        break;
    case 0xb:
        if (!UiObjIsBusy(OBJ(0))) {
            UiObjMoveToX(OBJ(0), 6, 5, -260.0f);
            UiObjSetCommand(OBJ(0), 15, 0);
            UiObjMoveToX(OBJ(1), 6, 5, -260.0f);
            UiObjSetCommand(OBJ(1), 15, 2);
            UiObjMoveToX(OBJ(3), 6, 5, -260.0f);
            UiObjSetCommand(OBJ(3), 15, 4);
            UiObjMoveToX(OBJ(4), 6, 5, -260.0f);
            UiObjSetCommand(OBJ(4), 15, 6);
            UiObjMoveToX(OBJ(5), 6, 5, -260.0f);
            UiObjSetCommand(OBJ(5), 15, 8);
            t->m.work->state = 0xc;
        } else if (fn_801C09F8(0, 1)) {
            MenuPartsFinish(&t->m);
            t->m.work->state = 0xc;
        }
        break;
    case 0xc:
        if (!UiObjIsBusy(OBJ(5))) {
            t->m.state = 0xc;
        }
        break;
    case 0xd:
        OBJ(3)->alpha_en = 1;
        UiObjSetCommand(OBJ(3), 21, 0);
        t->m.work->state = 0xe;
    case 0xe:
        if (!UiObjIsBusy(OBJ(3))) {
            UiObjMoveToY(OBJ(1), 6, 5, 100.0f);
            UiObjSetCommand(OBJ(1), 15, 0);
            UiObjMoveToY(OBJ(3), 6, -1, 148.0f);
            UiObjSetCommand(OBJ(3), 15, 0);
            UiObjMoveToX(OBJ(4), 6, -1, -8.0f);
            UiObjSetCommand(OBJ(4), 15, 0);
            UiObjMoveToX(OBJ(5), 6, 5, -8.0f);
            UiObjSetCommand(OBJ(5), 15, 2);
            t->m.work->state = 0x13;
        }
        break;
    case 0xf:
        OBJ(4)->alpha_en = 1;
        UiObjSetCommand(OBJ(4), 21, 0);
        t->m.work->state = 0x10;
    case 0x10:
        if (!UiObjIsBusy(OBJ(4))) {
            UiObjMoveToY(OBJ(1), 6, 5, 100.0f);
            UiObjSetCommand(OBJ(1), 15, 0);
            UiObjMoveToY(OBJ(4), 6, -1, 212.0f);
            UiObjSetCommand(OBJ(4), 15, 0);
            UiObjMoveToX(OBJ(3), 6, -1, -8.0f);
            UiObjSetCommand(OBJ(3), 15, 0);
            UiObjMoveToX(OBJ(5), 6, 5, -8.0f);
            UiObjSetCommand(OBJ(5), 15, 2);
            t->m.work->state = 0x13;
        }
        break;
    case 0x13:
        if (fn_801C09F8(0, 1)) {
            MenuPartsFinish(&t->m);
            t->m.work->state = 3;
        } else if (!UiObjIsBusy(OBJ(4))) {
            t->m.work->state = 3;
        }
        break;
    }
}
#undef OBJ

void fn_801C0814(Obj *o) {
    Ctl *c = o->c;
    u32 v = c->v;
    if (v > 1000000) {
        c->out = 100000;
    } else if (v > 100000) {
        c->out = 10000;
    } else if (v > 10000) {
        c->out = 1000;
    } else if (v > 1000) {
        c->out = 100;
    } else if (v > 100) {
        c->out = 10;
    } else if (v > 50) {
        c->out = 5;
    } else {
        c->out = 1;
    }
}

static inline s32 PlaySe(s16 se) {
    if (se >= MENU_SE_COUNT || se == -1) {
        return 0;
    }
    return SePlay(menu_se_table[se].bank, 1, menu_se_table[se].id);
}

void fn_801C08B4(s32 msg) {
    if (lbl_803471C0 != 0) {
        if (lbl_803471C0 != 0) {
            fn_80217830(lbl_803471C0);
        }
        lbl_803471C0 = 0;
    }
    lbl_803471C0 = PlaySe(msg);
}

s32 MenuPlaySe(s16 se) {
    if (se >= MENU_SE_COUNT || se == -1) {
        return 0;
    }
    return SePlay(menu_se_table[se].bank, 1, menu_se_table[se].id);
}
