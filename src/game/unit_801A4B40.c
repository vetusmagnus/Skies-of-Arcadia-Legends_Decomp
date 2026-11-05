#include "game/shop.h"



void fn_801A4B40(void* a) {
    Tsk_801A4B40* t = a;
    SpriteObj obj;
    f32 pos[2];
    f32 z;
    s32 j, i;
    if (lbl_803475D8 != 0) t->state = 0xff;
    switch (t->state) {
    case 0:
    case 0xfe:
        z = -9990.0f;
        obj.sprite = fn_801D68C4(menu_sprites.banks[1], 0);
        obj.z = -9990.0f;
        obj.b = 1.0f;
        obj.a = t->par->in->f18;
        obj.texlist = (NJS_TEXLIST*)menu_sprites.textlistC;
        obj.flags = 0;
        obj.colour = 0;
        for (j = 0; j < 8; j++) {
            for (i = 0; i < 10; i++) {
                obj.z = z;
                pos[0] = i * 64;
                pos[1] = j * 64;
                SpriteObjDrawAt(&obj, pos);
                z += 0.05f;
            }
        }
        obj.sprite = fn_801D68C4(menu_sprites.banks[0], 0);
        obj.z = -9980.0f;
        obj.flags = 3;
        obj.texlist = (NJS_TEXLIST*)menu_sprites.textlistC;
        SpriteObjDraw(&obj);
        obj.flags = 1;
        obj.texlist = (NJS_TEXLIST*)menu_sprites.texlist8;
        obj.sprite = fn_801D68C4(menu_sprites.banks[2], 0);
        obj.z = -9970.0f;
        SpriteObjDraw(&obj);
        obj.sprite = fn_801D68C4(menu_sprites.banks[2], 3);
        obj.z = -9960.0f;
        SpriteObjDraw(&obj);
        obj.sprite = fn_801D68C4(menu_sprites.banks[2], 1);
        obj.z = -9950.0f;
        SpriteObjDraw(&obj);
        obj.sprite = fn_801D68C4(menu_sprites.banks[2], 2);
        obj.z = -9940.0f;
        SpriteObjDraw(&obj);
        obj.texlist = (NJS_TEXLIST*)menu_sprites.texlist8;
        obj.sprite = fn_801D68C4(menu_sprites.banks[3], 0);
        SpriteObjDraw(&obj);
        if (t->par->flags & 0x40) t->flags |= 0x40;
        break;
    case 0xff:
        t->flags |= 0x40;
        break;
    }
}

void* fn_801A4DCC(void* a, u16 flag)
{
    Ctl_801A4DCC* o = fn_802267AC(a, (void *)fn_801A4E58);
    o->p24 = fn_801E1A74(1, 4);
    if (flag == 0) {
        ((Wk_801A4DCC*)o->p24)->f00 = 0.1f;
        o->b19 = 0;
    } else {
        ((Wk_801A4DCC*)o->p24)->f00 = 0.1f;
        o->b19 = 1;
    }
    return o;
}

void fn_801A4E58(void *a)
{
    Ctl_801A4E58* o = a;
    Ctl_801A4E58* t = o->p08;

    if (t == 0) {
        o->b19 = 0xff;
    }
    switch (o->b19) {
    case 0:
    case 0xfe: {
        f32 f2;
        f32 f1;
        f2 = t->p24->f18;
        f1 = o->p24->f00;
        t->p24->f18 = f2 - f1;
        if (!(t->p24->f18 <= 0.4f)) {
            return;
        }
        t->p24->f18 = 0.4f;
        o->b19 = 0xff;
        break;
    }
    case 1: {
        f32 f2;
        f32 f1;
        f2 = t->p24->f18;
        f1 = o->p24->f00;
        t->p24->f18 = f2 + f1;
        if (!(t->p24->f18 >= 1.0f)) {
            return;
        }
        t->p24->f18 = 1.0f;
        o->b19 = 0xff;
        break;
    }
    case 0xff:
        o->b18 |= 0x40;
        break;
    default:
        break;
    }
}

SlotTask* SaveLoadCursorCreate(void* parent) {
    SlotTask* t = fn_802267AC(parent, SaveLoadCursorDraw);
    t->w = fn_801E1A74(1, 0x58);
    t->obj = fn_801E1A74(1, 0x6c);
    t->obj->h54 = 0;
    t->w->b0 = 0;
    t->obj->o.alpha_en = 0;
    t->obj->o.z = -4050.0f;
    t->obj->o.x = -330.0f;
    t->obj->o.tx = -330.0f;
    t->obj->o.y = 160.0f;
    t->obj->o.ty = 160.0f;
    t->obj->o.rdx = 1.0f;
    t->obj->o.rdy = 0.0f;
    t->obj->o.alpha = 1.0f;
    return t;
}

void SaveLoadCursorDraw(Task_801A54AC* t) {
    SpriteObjScaled so;
    SaveTask* par = t->parent;
    switch (t->state) {
    case 0:
    case 1:
        t->pan->o.rdx = 30.0f * par->w->f1c;
        if (par->w->f1c >= 1.0f) {
            t->state = 0;
        }
        UiObjUpdate(&t->pan->o);
        UiLayoutDraw(&menu_sprites.texlist8, lbl_802B4DB8[t->pan->h54].parts, lbl_802B4DB8[t->pan->h54].count,
                     &t->pan->o.x, t->pan->o.z, t->pan->o.alpha, 1.0f);
        if (t->pan->h54 != 0) {
            so.colour = 0xFF0080FF;
            so.flags = 9;
        } else {
            so.colour = 0;
            so.flags = 1;
        }
        so.sprite = fn_801D68C4(menu_sprites.banks[3], 0x1d);
        so.texlist = menu_sprites.texlist8;
        so.x = 52.0f + t->pan->o.x;
        so.y = 19.0f + t->pan->o.y;
        so.z = -32.5f + t->pan->o.z;
        so.a = 1.0f;
        so.b = 1.0f;
        so.sx = t->pan->o.rdx;
        so.sy = 1.0f;
        so.flip = 0;
        SpriteObjDrawScaled(&so);
        break;
    case 0xFE:
        break;
    case 0xFF:
        t->flags |= 0x40;
        break;
    }
}

Node* fn_801A51A8(void* a)
{
    Node* o = fn_802267AC(a, fn_801A5274);
    o->w = fn_801E1A74(1, 0x58);
    o->obj = fn_801E1A74(1, 0x6c);
    o->w->b0 = 0;
    o->obj->o.alpha_en = 0;
    o->obj->o.z = -4000.0f;
    o->obj->o.x = 640.0f;
    o->obj->o.tx = 640.0f;
    o->obj->o.y = 480.0f;
    o->obj->o.ty = 480.0f;
    o->obj->o.rdx = 0.0f;
    o->obj->o.rdy = 0.0f;
    o->obj->o.alpha = 1.0f;
    o->obj->text = 0;
    return o;
}

void fn_801A5274(Task_801A5274 *t) {
    f32 x;
    f32 y;
    f32 z;
    switch (t->state) {
    case 0:
    case 0xFE:
        if (t->flag[0] == 1) {
            return;
        }
        UiObjUpdate(&t->pan->o);
        UiLayoutDraw(&menu_sprites.texlist8, lbl_802B4A00, 2, &t->pan->o.x, t->pan->o.z, t->pan->o.alpha, 1.0f);
        z = TextGetZ();
        y = 12.0f + t->pan->o.y;
        x = 18.0f + t->pan->o.x;
        if (t->pan->text != 0) {
            TextPushColor();
            TextSetColor(0xFF201008);
            TextSetZ(-27.5f + t->pan->o.z);
            TextPrint((s32)x, (s32)y, t->pan->text);
            TextPopColor(1);
        }
        TextSetZ(z);
        break;
    case 0xFF:
        t->flags |= 0x40;
        break;
    }
}

Sub_801A0C3C *fn_801A53D4(void *o, u16 idx) {
    Sub_801A0C3C *t = fn_802267AC(o, fn_801A54AC);
    t->w = fn_801E1A74(1, 0x58);
    t->obj = fn_801E1A74(1, 0x6c);
    t->w->b0 = 0;
    t->obj->o.alpha_en = 0;
    t->obj->h54 = idx;
    t->obj->o.z = lbl_802B690C[idx].z;
    t->obj->o.tx = t->obj->o.x = lbl_802B690C[idx].x;
    t->obj->o.ty = t->obj->o.y = lbl_802B690C[idx].y;
    t->obj->o.alpha = lbl_802B690C[idx].alpha;
    return t;
}

void fn_801A54AC(Task_801A54AC *t) {
    SaveTask *parent = t->parent;
    f32 z;
    switch (t->state) {
    case 0:
    case 0xFE:
        if (t->flag[0] == 1) {
            return;
        }
        UiObjUpdate(&t->pan->o);
        if (-132.0f < t->pan->o.y && t->pan->o.y < 370.0f) {
            if (UiObjIsBusy(&t->pan->o) == 0 && t->pan->h54 == parent->w->f7) {
                t->pan->o.alpha = 1.0f;
            } else {
                t->pan->o.alpha = 0.5f;
            }
            UiLayoutDraw(&menu_sprites.texlist8, lbl_802B4B9C, 6, &t->pan->o.x, t->pan->o.z, t->pan->o.alpha * t->parent->w->f18, 1.0f);
            TextPushColor();
            z = TextGetZ();
            fn_801A5600(t);
            TextSetZ(z);
            TextPopColor(1);
        }
        break;
    case 0xFF:
        t->flags |= 0x40;
        break;
    }
}

void fn_801A5600(Task_801A54AC *t) {
    E2c *e;
    SaveTask *w;
    char *s = lbl_802EBE08;
    w = t->parent;
    e = &w->w->ent[t->pan->h54];
    TextSetZ(-27.5f + t->pan->o.z);
    TextSetColor(0xff201008);
    UiLayoutDrawPart(&menu_sprites.texlist8, lbl_802B4C14, 1, &t->pan->o.x, t->pan->o.z, t->pan->o.alpha * t->parent->w->f18, 1.0f, t->pan->h54);
    switch (e->f0) {
    case 0:
        if (w->w->f1 == 0) TextPrint(8.0f + t->pan->o.x, 27.0f + t->pan->o.y, s + 0x38);
        else TextPrint(8.0f + t->pan->o.x, 27.0f + t->pan->o.y, s + 0x8c);
        break;
    case 1:
        fn_801A58A0(t, e);
        break;
    case 2:
        TextPrint(8.0f + t->pan->o.x, 27.0f + t->pan->o.y, s + 0x44);
        break;
    case 3:
        if (w->w->f1 == 0) TextPrint(8.0f + t->pan->o.x, 27.0f + t->pan->o.y, s + 0x5c);
        else TextPrint(8.0f + t->pan->o.x, 27.0f + t->pan->o.y, s + 0x8c);
        break;
    case 4:
        TextPrint(8.0f + t->pan->o.x, 27.0f + t->pan->o.y, s + 0x74);
        break;
    }
}

void fn_801A58A0(Task_801A54AC* t, E2c* e) {
    MenuPanel* o;
    u32 v;
    SpriteObj obj;
    s32 j;
    f32 pos[2];
    s32 s;
    s32 c;
    s32 m;
    u32 t2;
    TextPrint(8.0f + t->pan->o.x, 27.0f + t->pan->o.y, lbl_802B9428[e->h6]);
    o = t->pan;
    UiSpriteDraw(fn_801D68C4(menu_sprites.banks[3], (e->h4 & 1) + 0x1e), 6.0f + o->o.x, 51.0f + o->o.y, -31.5f + o->o.z,
                 menu_sprites.texlist8, 1, o->o.alpha * t->parent->w->f18, 1.0f);
    UiDrawNumberAt(2, 2, e->hc, 12.0f + (27.0f + t->pan->o.x), 71.0f + t->pan->o.y, -32.1f + t->pan->o.z,
                   t->pan->o.alpha * t->parent->w->f18);
    v = e->w8;
    if (v >= 35996459) {
        m = 9999;
        s = 59;
    } else {
        t2 = v / 60;
        m = t2 / 60;
        s = t2 % 60;
    }
    UiDrawNumberAt(2, 5, m, 36.0f + (60.0f + t->pan->o.x), 71.0f + t->pan->o.y, -32.0f + t->pan->o.z,
                   t->pan->o.alpha * t->parent->w->f18);
    UiDrawNumberAt(0x8002, 2, s, 24.0f + (105.0f + t->pan->o.x), 71.0f + t->pan->o.y, -31.8f + t->pan->o.z,
                   t->pan->o.alpha * t->parent->w->f18);
    pos[1] = 58.0f + t->pan->o.y;
    pos[0] = 144.0f + t->pan->o.x;
    obj.a = t->pan->o.alpha * t->parent->w->f18;
    obj.b = 1.0f;
    obj.z = -32.5f + t->pan->o.z;
    obj.texlist = menu_sprites.textlistC;
    obj.flags = 5;
    obj.colour = -1;
    for (j = 0; j < 4; j++) {
        c = e->fe[j];
        if (c != -1) {
            obj.sprite = fn_801D68C4(menu_sprites.banks[0], lbl_802B69B4[c]);
            SpriteObjDrawAt(&obj, pos);
            obj.z -= 0.1f;
            obj.sprite = fn_801D68C4(menu_sprites.banks[0], 5);
            SpriteObjDrawAt(&obj, pos);
            obj.z -= 0.05f;
            pos[0] += 40.0f;
        }
    }
}

Node* fn_801A5BE8(void* parent, u16 mode) {
    Node* n = fn_802267AC(parent, fn_801A5D08);
    n->w = fn_801E1A74(1, 0x58);
    n->obj = fn_801E1A74(1, 0x6c);
    n->w->b0 = 0;
    n->obj->o.alpha_en = 1;
    if (mode == 0) {
        n->obj->o.z = -4250.0f;
        n->obj->o.x = -240.0f;
        n->obj->o.tx = -240.0f;
        n->obj->o.y = 228.0f;
        n->obj->o.ty = 228.0f;
        n->obj->text = lbl_80346808;
    } else {
        n->obj->o.z = -4300.0f;
        n->obj->o.x = -240.0f;
        n->obj->o.tx = -240.0f;
        n->obj->o.y = 292.0f;
        n->obj->o.ty = 292.0f;
        n->obj->text = lbl_8034680C;
    }
    n->obj->o.alpha = 1.0f;
    UiObjSetLowered(&n->obj->o);
    return n;
}

void fn_801A5D08(Task_801A5D08 *t) {
    f32 x;
    f32 y;
    f32 z;
    switch (t->state) {
    case 0:
    case 0xFE:
        if (t->flag[0] == 1) {
            return;
        }
        UiObjUpdate(&t->pan->o);
        UiObjCalcRect(&t->pan->o);
        UiLayoutDraw(&menu_sprites.texlist8, lbl_802B4B88, 1, &t->pan->o.rect[2], t->pan->o.z, 1.0f, 1.0f);
        UiLayoutDraw(&menu_sprites.texlist8, lbl_802B4B4C, 3, &t->pan->o.rect[0], t->pan->o.z, t->pan->o.alpha * t->parent->ctx->f18, 1.0f);
        z = TextGetZ();
        y = 19.0f + t->pan->o.rect[1];
        x = 74.0f + t->pan->o.rect[0];
        if (t->pan->text != 0) {
            TextPushColor();
            TextSetColor(0xFF201008);
            TextSetZ(-27.5f + t->pan->o.z);
            TextPrint((s32)x, (s32)y, t->pan->text);
            TextPopColor(1);
        }
        TextSetZ(z);
        break;
    case 0xFF:
        t->flags |= 0x40;
        break;
    }
}

SlotTask* fn_801A5EB4(void* a, u16 slot) {
    SlotTask* t = fn_802267AC(a, fn_801A5FD8);
    t->w = fn_801E1A74(1, 0x58);
    t->obj = fn_801E1A74(1, 0x6c);
    t->w->b0 = 0;
    t->obj->o.alpha_en = 0;
    t->obj->h54 = slot;
    if (slot == 0) {
        t->obj->o.z = -4200.0f;
        t->obj->o.x = -340.0f;
        t->obj->o.tx = -340.0f;
        t->obj->o.y = 100.0f;
        t->obj->o.ty = 100.0f;
        t->obj->text = "Slot A";
    } else {
        t->obj->o.z = -4150.0f;
        t->obj->o.x = -340.0f;
        t->obj->o.tx = -340.0f;
        t->obj->o.y = 164.0f;
        t->obj->o.ty = 164.0f;
        t->obj->text = "Slot B";
    }
    t->obj->o.alpha = 1.0f;
    UiObjSetLowered(&t->obj->o);
    return t;
}

SlotTask* fn_801A6244(void* a, u16 slot) {
    SlotTask* t = fn_802267AC(a, fn_801A6344);
    t->w = fn_801E1A74(1, 0x58);
    t->obj = fn_801E1A74(1, 0x6c);
    t->w->b0 = 0;
    t->obj->o.alpha_en = 0;
    t->obj->o.z = -4100.0f;
    t->obj->o.x = -340.0f;
    t->obj->o.tx = -340.0f;
    t->obj->o.y = 36.0f;
    t->obj->o.ty = 36.0f;
    t->obj->o.rdx = 105.0f;
    t->obj->o.rdy = 18.0f;
    t->obj->o.alpha = 1.0f;
    t->obj->h54 = slot;
    if (slot == 0) {
        t->obj->text = "Save";
    } else {
        t->obj->text = "Load";
    }
    return t;
}

void fn_801A6344(Task_801A5D08 *t) {
    f32 x;
    f32 y;
    f32 z;
    switch (t->state) {
    case 0:
    case 0xFE:
        if (t->flag[0] == 1) {
            return;
        }
        UiObjUpdate(&t->pan->o);
        UiLayoutDraw(&menu_sprites.texlist8, lbl_802B4A28, 3, &t->pan->o.x, t->pan->o.z, t->pan->o.alpha * t->parent->ctx->f18, 1.0f);
        z = TextGetZ();
        y = 18.0f + t->pan->o.y;
        x = 105.0f + t->pan->o.x;
        if (t->pan->text != 0) {
            TextPushColor();
            TextSetColor(0xFF201008);
            TextSetZ(-27.5f + t->pan->o.z);
            TextPrint((s32)x, (s32)y, t->pan->text);
            TextPopColor(1);
        }
        TextSetZ(z);
        break;
    case 0xFF:
        t->flags |= 0x40;
        break;
    }
}

void fn_801A64B4(void* obj, s32 idx) {
    u8* p = *(u8**)((u8*)obj + 0x24);
    u8* q = *(u8**)(p + 0x20C);
    if (q == 0) {
        return;
    }
    *(u32*)(*(u8**)(q + 0x28) + 0x4C) = lbl_802B6810[(u8)idx];
}

void fn_801A64E0(void *o) {
    Task *t = o;
    s32 i;

    for (i = 0; i < 0x10; i++) {
        u8 *slot = *(u8 **)((u8 *)t->work + 0x20C + i * 4);
        if (slot != 0 && *(UiObj **)(slot + 0x28) != 0) {
            UiObjFinish(*(UiObj **)(slot + 0x28));
        }
    }
}

s32 fn_801A6554(void *o) {
    Task *t = o;
    s32 i;

    for (i = 0; i < 0x10; i++) {
        u8 *slot = *(u8 **)((u8 *)t->work + 0x20C + i * 4);
        if (slot != 0 && UiObjIsBusy(*(UiObj **)(slot + 0x28)) != 0) {
            return 1;
        }
    }
    return 0;
}

void fn_801A65D4(Task *t) {
    u32 off;
    s32 i;

    for (i = 0; i < 0x10; i++) {
        off = (u16)i << 2;
        if (*(Task **)((u8 *)t->work + off + 0x20C) != 0) {
            TaskDelete(*(Task **)((u8 *)t->work + off + 0x20C));
            *(void **)((u8 *)t->work + off + 0x20C) = 0;
        }
    }
}

void fn_801A6650(SaveTask *t, u16 i)
{
    if (t->w->p[i] != NULL) {
        TaskDelete(&t->w->p[i]->task);
        t->w->p[i] = NULL;
    }
}

void fn_801A66AC(Node *t) {
    VertexCol v[3] = {
        { 0.0f, 0.0f, 0.0f, 0xFF201008 },
        { 24.0f, 0.0f, 0.0f, 0xFF201008 },
        { 12.0f, 20.0f, 0.0f, 0xFF201008 },
    };
    u32 i;
    u32 n;
    VertexCol *p;
    if (t != 0) {
        n = t->w->w44 + 1;
        t->w->w44 = n;
        if ((n & 8) == 0) {
            p = v;
            for (i = 0; i < 3; i++, p++) {
                p->x = 18.0f + p->x + 264.0f + t->obj->o.x;
                p->y = 16.0f + p->y + 48.0f + t->obj->o.y;
                p->z = fn_801DBD9C(-0.1f);
            }
            fn_80290ED4(v, 3, 0);
        }
    }
}

void fn_801A6824(void *o0) {
    u8 *obj = o0;
    if (*(void **)(*(u8 **)(obj + 0x24) + 0x204) != 0) {
        fn_801E17E0(*(void **)(*(u8 **)(obj + 0x24) + 0x204));
        *(u32 *)(*(u8 **)(obj + 0x24) + 0x204) = 0;
    }
}

void fn_801A686C(void *o) {
    Task *t = o;
    *(void **)((u8 *)t->work + 0x204) = fn_801CC3C4(lbl_802B69C0);
    if (*(void **)((u8 *)t->work + 0x204) != 0) {
        *(s16 *)((u8 *)t->work + 0x10) = fn_800ED8C4(*(void **)((u8 *)t->work + 0x204));
    }
}

void fn_801A68C4(void* tt) {
    ElemTask* t = tt;
    t->b = fn_801A456C();
    t->b->f31E8 = t->a->id;
    t->b->f31EA = lbl_80310A1C[0x32];
    t->a->f1E0 = 0;
    t->b->f31EC = 0;
    t->a->f1D8 = 1;
    t->a->f1DC = t->b->f31EA;
    t->a->f1DE = t->a->id;
    t->a->f1E0 = t->b->f31EC;
    t->a->f1E4 = t->b->f1B;
    t->a->b1E6 = t->b->b338;
    t->a->b1E7 = t->b->b339;
    t->a->b1E8 = t->b->b33A;
    t->a->b1E9 = t->b->b33B;
}

void fn_801A69BC() {
    UiSpritesFree();
}

void fn_801A69DC(void) {
    UiSpritesLoad(lbl_802B69D4);
}

s32 fn_801A6A04(s32 x)
{
    s32 r;
    switch (x + 13) {
    case 12:
    case 13:
        r = 0;
        break;
    case 11:
        r = 5;
        break;
    case 10:
        r = 1;
        break;
    case 8:
        r = 4;
        break;
    case 0:
    case 7:
        r = 2;
        break;
    default:
        r = 8;
        break;
    }
    return r;
}

int fn_801A6A58(int sub, int idx) {
    if (idx >= 0 && idx < 9) {
        return *(lbl_802EBEA4 + idx * 2 + sub);
    }
    return 0x29;
}
