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
typedef struct { u8 pad[0x128]; u32 x128; u8 pad2[0x1F8 - 0x12C]; void* parts[19]; } W;
typedef struct { s32 a; s16 b; s16 c; } Q;
typedef struct { u8 pad[0x24]; W* w; void* p28; Q* p2c; void* p30; } T;
void fn_801BE670(Task* t);

T* fn_801BEB10(void* a, s32 b, s32 c, s32 d) {
    extern void MenuDummy(Task* t);
    extern TextNode* TextPrint(s32 x, s32 y, const char *str);
    extern s32 UiLayoutDraw(NJS_TEXLIST** texlists, void* parts, u32 count, f32* pos, f32 z, f32 a, f32 b);
    extern s32 UiLayoutDrawPart(NJS_TEXLIST** texlists, void* parts, s32 count, f32* pos, u16 index, f32 z, f32 a, f32 b);
    extern void* fn_802267AC(void* a, void (*b)(Task*));
    extern void* fn_801E1A74(s32 a, s32 b);
    extern T* lbl_803471B8;
    extern s32 lbl_803473C0;
    extern u8 lbl_803473BF;
    extern u16 lbl_803473BC;
    u32 i;
    lbl_803473C0 = 1;
    lbl_803471B8 = fn_802267AC(a, fn_801BE670);
    lbl_803471B8->w = fn_801E1A74(1, 0x2C0);
    lbl_803471B8->p2c = fn_801E1A74(1, 0x224);
    lbl_803471B8->p30 = fn_801E1A74(1, 0x6CC);
    lbl_803471B8->p28 = fn_801E1A74(1, 0x5B8);
    lbl_803471B8->p2c->a = 0;
    lbl_803471B8->p2c->b = 0;
    lbl_803471B8->p2c->c = 0;
    for (i = 0; i < 19; i++) {
        lbl_803471B8->w->parts[i] = NULL;
    }
    lbl_803471B8->w->x128 = (u8)d;
    lbl_803473BF = b;
    lbl_803473BC = c;
    return lbl_803471B8;
}
