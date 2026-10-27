/* Menu element animation (UiObj), the menu part table helpers, and the menu sprites and layouts.
 *
 * The file name is ours. UiObjUpdate runs an element's command each frame: "raise" and "lower"
 * animate the highlight offset (and alpha), "move" steps the position toward the target set by
 * UiObjMoveTo*. The sprite half draws layouts, sprites and numbers made of digit sprites. See
 * docs/ui.md for how the menus use all this, including parking hidden pages off-screen. */

#include "game/menu.h"
#include "game/sprite.h"
#include "ninja.h"

#define PACK(c) (((c).c[0] << 24) + ((c).c[1] << 16) + ((c).c[2] << 8) + (c).c[3])

typedef struct {
    u8 pad[0xC];
    void** obj; /* 0x0C */
} TexAddr;

typedef struct {
    u8 pad[0x20];
    void* texlist; /* 0x20 */
} MenuFileHdr;

typedef struct {
    u32 x0;
    MenuFileHdr* hdr; /* 0x04 */
} MenuFile;

typedef struct {
    u8 pad[0x38];
    Task* owner; /* 0x38 */
    u8 active;   /* 0x3C */
} PartLink;

typedef struct {
    u8 pad[0x1BC];
    void* res;      /* 0x1BC */
    u8 pad1C0[8];
    PartLink* link; /* 0x1C8 */
} PartWork;

typedef struct {
    u8 pad[0x24];
    PartWork* work; /* 0x24 */
} PartTask;

typedef struct {
    f32 x, y, z, w;
} Vec4;

typedef struct {
    u16 bank;
    u16 sprite;
} DigitSprite;

typedef struct {
    f32 x, y;
} Pos2;

typedef struct {
    u32 w[5];
} Obj14;

typedef struct {
    f32 x, y;      /* 0x00 */
    f32 pad08;     /* 0x08 */
    f32 sx, sy;    /* 0x0C */
    u32 colour;    /* 0x14 */
    NJS_TEXLIST* texlist; /* 0x18 */
    Obj14* data;   /* 0x1C */
} Obj20;

extern void fn_801D6944(void* bank);
extern void fn_801E17E0(void* p);
extern void* fn_801E49D8(void);
extern s32 fn_801E4974(void* file, s32 i);
extern s32 fn_801E48A8(void* file);
extern void* fn_801E1C7C(s32 size);
extern void* fn_801E4984(void* file, s32 i);
extern void* fn_801E1584(void* p, s32 size);
extern MenuFile* fn_801DB124(void* data);
extern void fn_801D6998(void* bank, void* data);
extern void fn_801DB244(void* p);
extern void fn_8022B9A8(void);
extern void fn_8022DBC8(void);
extern void fn_8022B9DC(void);
extern void fn_801E1784(void* p);
extern void* fn_801E1C34(s32 size);
extern void* fn_80226354(PartTask* task);
extern void fn_80222964(void* p);
extern u32 lbl_80347568;
extern DigitSprite lbl_802C39E4[];
extern Obj14 lbl_802C39D0;
extern NJS_TEXLIST lbl_80346818;

void SpriteQuadSetUV(Vertex2D* v, SpriteFrame* f, u8 flip);
void SpriteQuadBuild(Vertex2D* v, SpriteFrame* frame, SpritePiece* piece, u32 colour, f32 x, f32 y,
                 f32 z);
void TextPrint(s16 x, s16 y, const char* s);
void TextPrintNumber(s16 x, s16 y, s32 value, s32 digits);
void SpriteObjDrawAt(SpriteObj* obj, f32* pos);
void fn_80005D98(Obj20* obj, s32 a, s32 b, f32 z);
void UiDrawNumber(NJS_POINT3* pos, u32 flags, u16 ndigits, u32 value, f32 c1); /* SpriteObjDrawScaled's object. */
void SpriteQuadBuildScaled(SpriteQuad* q, u8 flip, f32 sx, f32 sy);
s32 UiSpriteDraw(Sprite* sprite, f32 x, f32 y, f32 z, NJS_TEXLIST* texlist, u16 flags, f32 a, f32 b);
s32 UiSpriteDrawEx(Sprite* sprite, f32 x, f32 y, f32 z, NJS_TEXLIST* texlist, u16 flags, f32 a, f32 b);
void UiDrawNumberText(s32 value, s32 digits, f32 x, f32 y);
void UiDrawNumberAt(u32 flags, u16 ndigits, u32 value, f32 x, f32 y, f32 z, f32 c1);
void UiDrawNumber(NJS_POINT3* pos, u32 flags, u16 ndigits, u32 value, f32 c1);
void fn_801C3F5C(f32 x, f32 y, f32 z);
void UiTexlistLoad(void);
void UiTexlistRelease(void);
void SpriteObjDraw(SpriteObj* obj);
s32 UiLayoutDrawPart(NJS_TEXLIST** texlists, LayoutPart* parts, s32 count, f32* pos, f32 z, f32 a, f32 b, u16 index);
s32 UiLayoutDraw(NJS_TEXLIST** texlists, LayoutPart* parts, u32 count, f32* pos, f32 z, f32 a, f32 b);
s32 UiSpriteDraw(Sprite* sprite, f32 x, f32 y, f32 z, NJS_TEXLIST* texlist, u16 flags, f32 a, f32 b);
s32 UiSpriteDrawEx(Sprite* sprite, f32 x, f32 y, f32 z, NJS_TEXLIST* texlist, u16 flags, f32 a, f32 b);
s32 SpriteObjDrawScaled(SpriteObjScaled* obj);
void SpriteQuadBuildScaled(SpriteQuad* q, u8 flip, f32 sx, f32 sy);
void SpriteObjDrawAt(SpriteObj* obj, f32* pos);
void SpriteObjDrawAtEx(SpriteObj* obj, f32* pos);
void SpriteQuadBuild(Vertex2D* v, SpriteFrame* frame, SpritePiece* piece, u32 colour, f32 x, f32 y,
                 f32 z);
void SpriteQuadSetUV(Vertex2D* v, SpriteFrame* f, u8 flip);
void UiSpritesFree(void);
void UiSpritesLoad(void);
void fn_801C5348(void* p);
void Ui2DEnd(void);
void Ui2DBegin(void);
void UiFree(void* p);
void** UiAllocPtrArray(s32 n);
void PartKill(PartTask* task);
void PartKillList(PartTask** list, s32 n);
void RotateDirection(Angle* ang, NJS_VECTOR* out, f32 len);

/* These were inlined into their callers (the game is built without auto-inlining). */
inline s32 UiObjBusy(UiObj* obj) {
    if (obj == NULL) {
        return 0;
    }
    if (obj->cmd == 0) {
        return 0;
    }
    return 1;
}

inline void UiObjLower(UiObj* obj) {
    obj->rdx = 0.0f;
    obj->rdy = 0.0f;
    obj->raised = 0;
    if (obj->alpha_en) {
        obj->alpha = 0.7f;
    }
}

inline void UiObjRaise(UiObj* obj) {
    obj->rdx = 12.0f;
    obj->rdy = 4.0f;
    obj->raised = 1;
    if (obj->alpha_en) {
        obj->alpha = 1.0f;
    }
}

inline void UiObjSnap(UiObj* obj) {
    obj->x = obj->tx;
    obj->y = obj->ty;
    obj->vy = 0.0f;
    obj->vx = 0.0f;
    obj->frames = 0;
    obj->cmd = 0;
}

inline s32 UiObjTween(UiObj* obj) {
    s32 done;
    if (obj->frames == 0) {
        obj->x = obj->tx;
        obj->y = obj->ty;
        obj->vy = 0.0f;
        obj->vx = 0.0f;
        done = 1;
    } else {
        obj->x += obj->vx;
        obj->y += obj->vy;
        obj->frames--;
        done = 0;
    }
    return done;
}

inline s32 UiObjPlaySe(s16 se) {
    if (se >= MENU_SE_COUNT || se == -1) {
        return 0;
    }
    return SePlay(menu_se_table[se].bank, 1, menu_se_table[se].id);
}

inline s32 PartHasLink(PartWork* work) {
    s32 has = 0;
    if (work != NULL && work->link != NULL) {
        has = 1;
    }
    return has;
}

inline void PartKillInline(PartTask* task) {
    PartWork* work;
    if (fn_80226354(task) != NULL) {
        work = task->work;
        if (PartHasLink(work) && (Task*)task == work->link->owner) {
            work->link->owner = NULL;
            task->work->link->active = 0;
        }
        if (TaskDelete((Task*)task) == 0) {
            work = task->work;
            if (work->res != NULL) {
                fn_80222964(work->res);
                fn_801E1784(work->res);
                work->res = NULL;
            }
        }
    }
}

/* The direction RotateDirection rotates: (0, 0, length). */
Vec4 lbl_802EE760 = {0.0f, 0.0f, 0.0f, 0.0f};

inline void CalcPointSafe(f32* m, NJS_VECTOR* v, NJS_VECTOR* out) {
    NJS_VECTOR t;
    if (m != NULL && v != NULL && out != NULL) {
        t.x = v->x;
        t.y = v->y;
        t.z = v->z;
        njCalcPoint(m, &t, out);
    }
}

inline void RotateVector(NJS_VECTOR* v, NJS_VECTOR* out, Angle x, Angle y, Angle z) {
    NJS_MATRIX m;
    if (v != NULL && out != NULL) {
        njUnitMatrix(m);
        njRotateXYZ(m, x, y, z);
        CalcPointSafe(m, v, out);
    }
}

s32 MenuPartsBusy(MenuTask* menu) {
    s32 i;
    for (i = 0; i < MENU_PART_COUNT; i++) {
        if (menu->work->parts[i] != NULL) {
            if (menu->work->parts[i]->obj != NULL && UiObjBusy(menu->work->parts[i]->obj)) {
                return 1;
            }
            if (menu->work->parts[i]->obj2 != NULL && UiObjBusy(menu->work->parts[i]->obj2)) {
                return 1;
            }
        }
    }
    return 0;
}

void MenuPartsFinish(MenuTask* menu) {
    s32 i;
    for (i = 0; i < MENU_PART_COUNT; i++) {
        if (menu->work->parts[i] != NULL) {
            if (menu->work->parts[i]->obj != NULL) {
                UiObjFinish(menu->work->parts[i]->obj);
            }
            if (menu->work->parts[i]->obj2 != NULL) {
                UiObjFinish(menu->work->parts[i]->obj2);
            }
        }
    }
}

void UiObjFinish(UiObj* obj) {
    if (obj == NULL) {
        return;
    }
    obj->delay = 0;
    switch (obj->cmd) {
    case 0:
        break;
    case 5:
    case 6:
    case 7:
    case 8:
        UiObjLower(obj);
        UiObjSnap(obj);
        break;
    case 10:
    case 11:
    case 12:
    case 13:
        UiObjRaise(obj);
        UiObjSnap(obj);
        break;
    case 15:
    case 16:
        UiObjSnap(obj);
        break;
    case 20:
        UiObjLower(obj);
        obj->cmd = 0;
        break;
    case 21:
        UiObjRaise(obj);
        obj->cmd = 0;
        break;
    case 22:
        obj->cmd = 0;
        break;
    case 23:
        obj->cmd = 0;
        break;
    case 24:
        obj->cmd = 0;
        break;
    case 25:
        obj->cmd = 0;
        break;
    }
}

void UiObjUpdate(UiObj* obj) {
    if (obj == NULL) {
        return;
    }
    if (obj->delay != 0) {
        obj->delay--;
        return;
    }
    switch (obj->cmd) {
    case 0:
        break;
    case 5:
        if (UiObjStepRaise(obj, 1)) {
            obj->cmd++;
        }
        break;
    case 6:
        UiObjPlaySe(obj->se);
        obj->cmd++;
    case 7:
        if (UiObjTween(obj)) {
            obj->cmd++;
        }
        break;
    case 8:
        if (UiObjStepRaise(obj, 0)) {
            obj->cmd = 0;
        }
        break;
    case 10:
        if (UiObjStepRaise(obj, 0)) {
            obj->cmd++;
        }
        break;
    case 11:
        UiObjPlaySe(obj->se);
        obj->cmd++;
    case 12:
        if (UiObjTween(obj)) {
            obj->cmd++;
        }
        break;
    case 13:
        if (UiObjStepRaise(obj, 1)) {
            obj->cmd = 0;
        }
        break;
    case 15:
        UiObjPlaySe(obj->se);
        obj->cmd++;
    case 16:
        if (UiObjTween(obj)) {
            obj->cmd = 0;
        }
        break;
    case 20:
        if (UiObjStepRaise(obj, 0)) {
            obj->cmd = 0;
        }
        break;
    case 21:
        if (UiObjStepRaise(obj, 1)) {
            obj->cmd = 0;
        }
        break;
    case 24:
        if (UiObjStepRaiseNoAlpha(obj, 0)) {
            obj->cmd = 0;
        }
        break;
    case 25:
        if (UiObjStepRaiseNoAlpha(obj, 1)) {
            obj->cmd = 0;
        }
        break;
    case 26:
        if (UiObjStepRaiseNoAlpha(obj, 0)) {
            obj->cmd = 15;
        }
        break;
    }
}

void UiObjSetCommand(UiObj* obj, u16 cmd, u16 delay) {
    obj->cmd = cmd;
    obj->delay = delay;
}

s32 UiObjIsBusy(UiObj* obj) {
    if (obj == NULL) {
        return 0;
    }
    return obj->cmd != 0;
}

void UiObjCalcRect(UiObj* obj) {
    obj->rect[0] = obj->x + obj->rdx;
    obj->rect[1] = obj->y - obj->rdy;
    obj->rect[2] = obj->x + obj->rdx;
    obj->rect[3] = obj->y + obj->rdy;
}

void UiObjMoveTo(UiObj* obj, u16 frames, s16 se, f32 x, f32 y) {
    obj->se = se;
    obj->tx = x;
    obj->ty = y;
    obj->vx = (obj->tx - obj->x) / frames;
    obj->vy = (obj->ty - obj->y) / frames;
    obj->frames = frames;
}

s32 UiObjMoveToXIfChanged(UiObj* obj, u16 frames, s16 se, f32 x) {
    if (obj == NULL) {
        return 0;
    }
    if (obj->tx == x) {
        return 0;
    }
    obj->ty = obj->y;
    obj->vy = 0.0f;
    obj->se = se;
    obj->tx = x;
    obj->vx = (obj->tx - obj->x) / frames;
    obj->frames = frames;
    return 1;
}

void UiObjMoveToX(UiObj* obj, u16 frames, s16 se, f32 x) {
    obj->ty = obj->y;
    obj->vy = 0.0f;
    obj->se = se;
    obj->tx = x;
    obj->vx = (obj->tx - obj->x) / frames;
    obj->frames = frames;
}

void UiObjMoveToY(UiObj* obj, u16 frames, s16 se, f32 y) {
    obj->tx = obj->x;
    obj->vx = 0.0f;
    obj->se = se;
    obj->ty = y;
    obj->vy = (obj->ty - obj->y) / frames;
    obj->frames = frames;
}

void UiObjSetLowered(UiObj* obj) {
    UiObjLower(obj);
}

void UiObjSetRaised(UiObj* obj) {
    UiObjRaise(obj);
}

s32 UiObjStepRaiseNoAlpha(UiObj* obj, u8 up) {
    if (up == 1) {
        if (obj->rdx >= 12.0f) {
            obj->rdx = 12.0f;
            obj->rdy = 4.0f;
            obj->raised = 1;
            return 1;
        }
        obj->rdx += 4.0f;
        obj->rdy += 4.0f / 3.0f;
        return 0;
    }
    if (obj->rdx <= 0.0f) {
    lower:
        obj->rdx = 0.0f;
        obj->rdy = 0.0f;
        obj->raised = 0;
        return 1;
    }
    obj->rdx -= 4.0f;
    obj->rdy -= 4.0f / 3.0f;
    if (obj->rdx <= 0.0f) {
        goto lower;
    }
    return 0;
}

s32 UiObjStepRaise(UiObj* obj, u8 up) {
    if (up == 1) {
        if (obj->rdx >= 12.0f) {
            obj->rdx = 12.0f;
            obj->rdy = 4.0f;
            obj->raised = 1;
            if (obj->alpha_en) {
                obj->alpha = 1.0f;
            }
            return 1;
        }
        obj->rdx += 4.0f;
        obj->rdy += 4.0f / 3.0f;
        if (obj->alpha_en) {
            obj->alpha += 0.1f;
            if (obj->alpha >= 1.0f) {
                obj->alpha = 1.0f;
            }
        }
        return 0;
    }
    if (obj->rdx <= 0.0f) {
    lower:
        UiObjLower(obj);
        return 1;
    }
    obj->rdx -= 4.0f;
    obj->rdy -= 4.0f / 3.0f;
    if (obj->alpha_en) {
        obj->alpha -= 0.1f;
    }
    if (obj->rdx <= 0.0f) {
        goto lower;
    }
    return 0;
}

void MenuDummy(void) {
}

void MenuPartFree(MenuTask* menu, u16 index) {
    if (menu->work->parts[index] != NULL) {
        TaskDelete(&menu->work->parts[index]->task);
        menu->work->parts[index] = NULL;
    }
}

void UiDrawNumberText(s32 value, s32 digits, f32 x, f32 y) {
    if (value < 0) {
        TextPrint(x, y, "-");
        TextPrintNumber(12.0f + x, y, -value, (u16)((digits & 0xFFF0) + ((digits & 0xF) - 1)));
    } else if (value == 0) {
        TextPrintNumber(x, y, value, digits);
    } else {
        TextPrintNumber(x, y, value, digits);
    }
}

void UiDrawNumberAt(u32 flags, u16 ndigits, u32 value, f32 x, f32 y, f32 z, f32 c1) {
    NJS_POINT3 pos;
    pos.x = x;
    pos.y = y;
    pos.z = z;
    UiDrawNumber(&pos, flags, ndigits, value, c1);
}

void UiDrawNumber(NJS_POINT3* pos, u32 flags, u16 ndigits, u32 value, f32 c1) {
    Pos2 xy;
    u8 d[10];
    SpriteObj obj;
    s32 set;
    u32 off;
    u8* p;
    u32 last;
    s32 started;
    u32 i;
    DigitSprite* e;
    u32 r9, r8, r7, r6, r5, r4, r3, r2;

    obj.flags = 1;
    obj.a = c1;
    obj.b = 1.0f;
    obj.texlist = menu_sprites.texlist8;
    started = (flags & 0x8000) == 0x8000;
    set = flags & 3;
    obj.z = pos->z;
    obj.colour = 0;
    xy.y = pos->y;
    if (ndigits == 0 || ndigits > 10) {
        return;
    }
    d[9] = value / 1000000000;
    r9 = value % 1000000000;
    d[8] = r9 / 100000000;
    r8 = r9 % 100000000;
    d[7] = r8 / 10000000;
    r7 = r8 % 10000000;
    d[6] = r7 / 1000000;
    r6 = r7 % 1000000;
    d[5] = r6 / 100000;
    r5 = r6 % 100000;
    d[4] = r5 / 10000;
    r4 = r5 % 10000;
    d[3] = r4 / 1000;
    r3 = r4 % 1000;
    d[2] = r3 / 100;
    r2 = r3 % 100;
    d[1] = r2 / 10;
    d[0] = r2 % 10;
    last = ndigits - 1;
    p = &d[last];
    off = last * 12;
    for (i = 0; i < last; i++, p--, off -= 12) {
        if (!started && *p != 0) {
            started = 1;
        }
        xy.x = pos->x - (f32)off;
        if (started) {
            e = &lbl_802C39E4[*p + set * 11];
            obj.sprite = fn_801D68C4(menu_sprites.banks[e->bank], e->sprite);
            SpriteObjDrawAt(&obj, &xy.x);
            obj.z += 0.05f;
        }
    }
    xy.x = pos->x;
    obj.sprite = fn_801D68C4(menu_sprites.banks[lbl_802C39E4[d[0] + set * 11].bank], lbl_802C39E4[d[0] + set * 11].sprite);
    SpriteObjDrawAt(&obj, &xy.x);
}

void fn_801C3F5C(f32 x, f32 y, f32 z) {
    Obj20 obj;
    Obj14 data = lbl_802C39D0;
    if (menu_sprites.tex10 != NULL) {
        obj.x = x;
        obj.texlist = menu_sprites.tex10;
        obj.data = &data;
        obj.colour = 0;
        obj.sx = 1.0f;
        obj.sy = 1.0f;
        obj.y = y;
        fn_80005D98(&obj, 0, 0x20, fn_801DBD9C(z));
    }
}

void UiTexlistLoad(void) {
    fn_80227810(menu_sprites.tex10 = &lbl_80346818);
}

void UiTexlistRelease(void) {
    if (menu_sprites.tex10 != NULL) {
        fn_802275A4(menu_sprites.tex10, 1);
        menu_sprites.tex10 = NULL;
    }
}

void SpriteObjDraw(SpriteObj* obj) {
    DrawState st;
    Colour4 c;
    SpriteFrame* frame;
    u32 saved;
    s32 i;
    Vertex2D* verts;
    SpritePiece* piece;
    f32 z;
    if (obj->sprite != NULL) {
        if (obj->flags & 6) {
            DrawStateDefault2D(&st);
            st.attr_or |= (obj->flags >> 2) & 1;
            if (obj->flags & 2) {
                st.blend_src = 8;
                st.blend_dst = 10;
            }
            DrawStatePush(&st);
        }
        fn_80299040(obj->texlist);
        verts = sprite_verts;
        for (i = 0; i < obj->sprite->count; i++) {
            z = 0.05f * i + obj->z;
            piece = &obj->sprite->pieces[i];
            saved = piece->colour;
            frame = &obj->sprite->frames[piece->frame];
            fn_801D65B4(saved, &c, obj->a, obj->b);
            SpriteQuadBuild(verts, frame, piece, piece->colour, obj->sprite->x, obj->sprite->y, z);
            fn_80297DC8(*((TexAddr*)obj->texlist->textures[frame->tex].texaddr)->obj);
            fn_80291064(verts, 4, obj->flags & 1);
            piece->colour = saved;
        }
        if (obj->flags & 6) {
            DrawStatePop(NULL);
            DrawStateRestore();
        }
    }
}

s32 UiLayoutDrawPart(NJS_TEXLIST** texlists, LayoutPart* parts, s32 count, f32* pos, f32 z, f32 a, f32 b, u16 index) {
    LayoutPart* p = &parts[index];
    return UiSpriteDrawEx(fn_801D68C4(menu_sprites.banks[p->bank], p->sprite),
                       pos[0] + p->x, pos[1] + p->y, p->z + z, texlists[p->texlist], p->flags, a, b);
}

s32 UiLayoutDraw(NJS_TEXLIST** texlists, LayoutPart* parts, u32 count, f32* pos, f32 z, f32 a, f32 b) {
    DrawState st;
    u32 i;
    s32 total;

    total = 0;
    DrawStateDefault2D(&st);
    DrawStatePush(&st);
    parts += count;
    for (i = 0; i < count; i++) {
        parts--;
        total += UiSpriteDraw(fn_801D68C4(menu_sprites.banks[parts->bank], parts->sprite), pos[0] + parts->x, pos[1] + parts->y, parts->z + z, texlists[parts->texlist],
                              parts->flags, a, b);
    }
    DrawStatePop(NULL);
    DrawStateRestore();
    return total;
}

s32 UiSpriteDraw(Sprite* sprite, f32 x, f32 y, f32 z, NJS_TEXLIST* texlist, u16 flags, f32 a, f32 b) {
    Colour4 c;
    s32 i;
    u32 saved;
    SpriteFrame* frame;
    SpritePiece* piece;

    if (sprite != NULL) {
        fn_80299040(texlist);
        for (i = 0; i < sprite->count; i++) {
            piece = &sprite->pieces[i];
            saved = piece->colour;
            frame = &sprite->frames[piece->frame];
            fn_801D65B4(saved, &c, a, b);
            SpriteQuadBuild(sprite_verts, frame, piece, (c.c[0] << 24) + (c.c[1] << 16) + (c.c[2] << 8) + c.c[3], x, y,
                        0.05f * i + z);
            fn_80297DC8(*((TexAddr*)texlist->textures[frame->tex].texaddr)->obj);
            fn_80291064(sprite_verts, 4, flags & 1);
            piece->colour = saved;
        }
        return sprite->count;
    }
}

s32 UiSpriteDrawEx(Sprite* sprite, f32 x, f32 y, f32 z, NJS_TEXLIST* texlist, u16 flags, f32 a, f32 b) {
    Colour4 c;
    DrawState st;
    u32 saved;
    s32 state;
    s32 i;
    Vertex2D* verts;
    SpriteFrame* frame;
    SpritePiece* piece;

    if (sprite != NULL) {
        state = flags & 6;
        if (state) {
            DrawStateDefault2D(&st);
            st.attr_or |= (flags >> 2) & 1;
            if (flags & 2) {
                st.blend_src = 8;
                st.blend_dst = 10;
            }
            DrawStatePush(&st);
        }
        fn_80299040(texlist);
        verts = sprite_verts;
        for (i = 0; i < sprite->count; i++) {
            piece = &sprite->pieces[i];
            saved = piece->colour;
            frame = &sprite->frames[piece->frame];
            fn_801D65B4(saved, &c, a, b);
            SpriteQuadBuild(verts, frame, piece, (c.c[0] << 24) + (c.c[1] << 16) + (c.c[2] << 8) + c.c[3], x, y,
                        0.05f * i + z);
            fn_80297DC8(*((TexAddr*)texlist->textures[frame->tex].texaddr)->obj);
            fn_80291064(verts, 4, flags & 1);
            piece->colour = saved;
        }
        if (state) {
            DrawStatePop(NULL);
            DrawStateRestore();
        }
        return sprite->count;
    }
}

s32 SpriteObjDrawScaled(SpriteObjScaled* obj) {
    DrawState st;
    SpriteQuad q;
    Colour4 c;
    s32 i;

    if (obj->sprite != NULL) {
        if (obj->flags & 6) {
            DrawStateDefault2D(&st);
            st.attr_or |= (obj->flags >> 2) & 1;
            if (obj->flags & 2) {
                st.blend_src = 8;
                st.blend_dst = 10;
            }
            DrawStatePush(&st);
        }
        fn_80299040(obj->texlist);
        q.verts = sprite_verts;
        for (i = 0; i < obj->sprite->count; i++) {
            q.x = obj->x;
            q.y = obj->y;
            q.z = 0.05f * i + obj->z;
            q.piece = &obj->sprite->pieces[i];
            q.frame = &obj->sprite->frames[q.piece->frame];
            if (obj->flags & 8) {
                q.colour = q.piece->colour;
                fn_801D65B4(obj->colour, &c, obj->a, obj->b);
                q.colour = (c.c[0] << 24) + (c.c[1] << 16) + (c.c[2] << 8) + c.c[3];
            } else {
                q.colour = q.piece->colour;
            }
            SpriteQuadBuildScaled(&q, obj->flip, obj->sx, obj->sy);
            fn_80297DC8(*((TexAddr*)obj->texlist->textures[q.frame->tex].texaddr)->obj);
            fn_80291064(q.verts, 4, obj->flags & 1);
        }
        if (obj->flags & 6) {
            DrawStatePop(NULL);
            DrawStateRestore();
        }
        return obj->sprite->count;
    }
}

void SpriteQuadBuildScaled(SpriteQuad* q, u8 flip, f32 sx, f32 sy) {
    f32 z = fn_801DBD9C(q->z);
    q->verts[0].x = q->x + q->piece->x0;
    q->verts[0].y = q->y + q->piece->y0;
    q->verts[0].z = z;
    q->verts[0].colour = q->colour;
    q->verts[2].x = q->piece->x1 * sx + q->x;
    q->verts[2].y = q->y + q->piece->y0;
    q->verts[2].z = z;
    q->verts[2].colour = q->colour;
    q->verts[3].x = q->piece->x1 * sx + q->x;
    q->verts[3].y = q->piece->y1 * sy + q->y;
    q->verts[3].z = z;
    q->verts[3].colour = q->colour;
    q->verts[1].x = q->x + q->piece->x0;
    q->verts[1].y = q->piece->y1 * sy + q->y;
    q->verts[1].z = z;
    q->verts[1].colour = q->colour;
    SpriteQuadSetUV(q->verts, q->frame, flip);
}

void SpriteObjDrawAt(SpriteObj* obj, f32* pos) {
    u32 i;
    SpriteFrame* frame;
    s32 saved;
    f32 z;
    Colour4 c;
    Vertex2D* verts;
    SpritePiece* piece;
    if (obj->sprite == NULL) {
        return;
    }
    fn_80299040(obj->texlist);
    verts = sprite_verts;
    for (i = 0; i < obj->sprite->count; i++) {
        z = 0.05f * (s32)i + obj->z;
        piece = &obj->sprite->pieces[i];
        saved = piece->colour;
        frame = &obj->sprite->frames[piece->frame];
        fn_801D65B4(saved, &c, obj->a, obj->b);
        SpriteQuadBuild(verts, frame, piece, PACK(c), pos[0], pos[1], z);
        fn_80297DC8(*((TexAddr*)obj->texlist->textures[frame->tex].texaddr)->obj);
        fn_80291064(verts, 4, obj->flags & 1);
        piece->colour = saved;
    }
}

void SpriteObjDrawAtEx(SpriteObj* obj, f32* pos) {
    s32 saved;
    u32 i;
    Vertex2D* verts;
    SpriteFrame* frame;
    u32 colour;
    f32 z;
    Colour4 c;
    DrawState state;
    SpritePiece* piece;
    if (obj->sprite == NULL) {
        return;
    }
    if (obj->flags & 6) {
        DrawStateDefault2D(&state);
        state.attr_or |= (obj->flags >> 2) & 1;
        if (obj->flags & 2) {
            state.blend_src = 8;
            state.blend_dst = 10;
        }
        DrawStatePush(&state);
    }
    fn_80299040(obj->texlist);
    verts = sprite_verts;
    for (i = 0; i < obj->sprite->count; i++) {
        z = 0.05f * (s32)i + obj->z;
        piece = &obj->sprite->pieces[i];
        frame = &obj->sprite->frames[piece->frame];
        saved = piece->colour;
        if (obj->flags & 8) {
            fn_801D65B4(obj->colour, &c, obj->a, obj->b);
            colour = PACK(c);
        } else {
            fn_801D65B4(saved, &c, obj->a, obj->b);
            colour = PACK(c);
        }
        SpriteQuadBuild(verts, frame, piece, colour, pos[0], pos[1], z);
        fn_80297DC8(*((TexAddr*)obj->texlist->textures[frame->tex].texaddr)->obj);
        fn_80291064(verts, 4, obj->flags & 1);
        piece->colour = saved;
    }
    if (obj->flags & 6) {
        DrawStatePop(NULL);
        DrawStateRestore();
    }
}

void SpriteQuadBuild(Vertex2D* v, SpriteFrame* frame, SpritePiece* piece, u32 colour, f32 x, f32 y,
                 f32 z) {
    z = fn_801DBD9C(z);
    v[0].x = x + piece->x0;
    v[0].y = y + piece->y0;
    v[0].z = z;
    v[0].colour = colour;
    v[2].x = x + piece->x1;
    v[2].y = y + piece->y0;
    v[2].z = z;
    v[2].colour = colour;
    v[3].x = x + piece->x1;
    v[3].y = y + piece->y1;
    v[3].z = z;
    v[3].colour = colour;
    v[1].x = x + piece->x0;
    v[1].y = y + piece->y1;
    v[1].z = z;
    v[1].colour = colour;
    SpriteQuadSetUV(v, frame, 0);
}

void SpriteQuadSetUV(Vertex2D* v, SpriteFrame* f, u8 flip) {
    switch (flip) {
    case 0:
        v[0].u = f->u0;
        v[0].v = f->v0;
        v[2].u = f->u1;
        v[2].v = f->v0;
        v[3].u = f->u1;
        v[3].v = f->v1;
        v[1].u = f->u0;
        v[1].v = f->v1;
        break;
    case 1:
        v[0].u = f->u1;
        v[0].v = f->v0;
        v[2].u = f->u1;
        v[2].v = f->v1;
        v[3].u = f->u0;
        v[3].v = f->v1;
        v[1].u = f->u0;
        v[1].v = f->v0;
        break;
    case 2:
        v[0].u = f->u1;
        v[0].v = f->v1;
        v[2].u = f->u0;
        v[2].v = f->v1;
        v[3].u = f->u0;
        v[3].v = f->v0;
        v[1].u = f->u1;
        v[1].v = f->v0;
        break;
    case 3:
        v[0].u = f->u0;
        v[0].v = f->v1;
        v[2].u = f->u0;
        v[2].v = f->v0;
        v[3].u = f->u1;
        v[3].v = f->v0;
        v[1].u = f->u1;
        v[1].v = f->v1;
        break;
    }
}

void UiSpritesFree(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (menu_sprites.banks[i] != NULL) {
            fn_801D6944(menu_sprites.banks[i]);
            fn_801E17E0(menu_sprites.banks[i]);
            menu_sprites.banks[i] = NULL;
        }
    }
    fn_802275A4(((MenuFile*)menu_sprites.file)->hdr->texlist, 1);
    fn_801E17E0(menu_sprites.file);
    menu_sprites.file = NULL;
    fn_801E17E0(menu_sprites.data24);
    menu_sprites.data24 = NULL;
}

void UiSpritesLoad(void) {
    s32 i;
    s32 end;
    void* buf;
    s32 size;
    void* src;
    menu_sprites.data24 = fn_801E49D8();
    size = fn_801E4974(menu_sprites.data24, 4);
    end = fn_801E48A8(menu_sprites.data24);
    buf = fn_801E1C7C(size);
    src = fn_801E4984(menu_sprites.data24, 4);
    MemCopy(buf, src, size);
    menu_sprites.data24 = fn_801E1584(menu_sprites.data24, end - size);
    menu_sprites.file = fn_801DB124(buf);
    fn_80227810(((MenuFile*)menu_sprites.file)->hdr->texlist);
    menu_sprites.texlist8 = ((MenuFile*)menu_sprites.file)->hdr->texlist;
    menu_sprites.textlistC = &lbl_80347568;
    for (i = 0; i < 4; i++) {
        menu_sprites.banks[i] = fn_801E1C7C(0x14);
        {
            void* data = fn_801E4984(menu_sprites.data24, i);
            fn_801D6998(menu_sprites.banks[i], data);
        }
    }
}

void fn_801C5348(void* p) {
    fn_801DB244(p);
}

void Ui2DEnd(void) {
    DrawStatePop(NULL);
    DrawStateRestore();
    fn_8022B9A8();
    fn_8022DBC8();
}

void Ui2DBegin(void) {
    DrawState state;
    fn_8022B9DC();
    fn_8022DBC8();
    DrawStateDefault2D(&state);
    DrawStatePush(&state);
}

void UiFree(void* p) {
    if (p != NULL) {
        fn_801E1784(p);
    }
}

void** UiAllocPtrArray(s32 n) {
    void** p = NULL;
    s32 i;
    if (n > 0) {
        p = fn_801E1C34(n * 4);
        if (p != NULL) {
            for (i = 0; i < n; i++) {
                p[i] = NULL;
            }
        }
    }
    return p;
}

void PartKill(PartTask* task) {
    PartKillInline(task);
}

void PartKillList(PartTask** list, s32 n) {
    PartTask** p;
    s32 i;
    if (list != NULL) {
        p = list;
        for (i = 0; i < n; p++, i++) {
            if (*p != NULL) {
                PartKillInline(*p);
            }
        }
    }
}

void RotateDirection(Angle* ang, NJS_VECTOR* out, f32 len) {
    NJS_VECTOR res;
    if (out != NULL && ang != NULL) {
        lbl_802EE760.z = len;
        RotateVector((NJS_VECTOR*)&lbl_802EE760, &res, ang[0], ang[1], ang[2]);
        out->x = res.x;
        out->y = res.y;
        out->z = res.z;
    }
}
