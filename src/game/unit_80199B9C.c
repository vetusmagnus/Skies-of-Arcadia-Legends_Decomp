#include "types.h"
#include "game/task.h"
#include "game/uiobj.h"

extern u8 lbl_8030741C[];
extern u32 lbl_80347180;
extern u8 lbl_8034717C[2];
extern void fn_801E17E0(void* p);
extern u8 lbl_803081CC[];
extern u32 lbl_802B6810[];
void UiSpritesFree(void);
void UiSpritesLoad(void* p);
extern char lbl_802B69D4[];
extern u8 lbl_802EBEA4[];
extern void* lbl_803471B8;
void fn_801BEB10(void* a, s32 b, s32 c, s32 d);
extern void fn_801DC214(void);
extern s32 fn_80248708(u8 *obj, s32 a, s32 b);
extern s32 fn_801A6A04(s32 r);
extern void fn_801A4B40(void);
extern u8 *fn_80226670(u8 *obj, void (*cb)(void));
extern void *fn_801E1A74(s32 a, s32 b);
typedef struct Sub {
    u8 pad0[0x8];
    float f8;
    float fc;
    u8 pad1[0xa];
    u16 h1a;
} Sub;
typedef struct Obj {
    u8 pad[0x30];
    Sub *sub;
} Obj;
extern s32 lbl_80347508;
extern void fn_801A65D4(Task *t);
extern u8 *lbl_80311A60[];
extern s32 fn_801A6554(Task *t);
extern void fn_801A64E0(Task *t);
extern void fn_801A66AC(void *p);
extern void fn_801A4DCC(Task *t, s32 v);
extern void fn_801CBBAC(f32 f);
extern void Ui2DBegin(void);
extern u32 lbl_8034718C;
extern u32 lbl_80347184;
extern s32 CARDUnmount(s32 slot);
extern int fn_8025CB24(char *, const char *, ...);
extern void fn_8025F120(void *, const char *);
extern void fn_8025F0B0(void *, char *);
extern char lbl_802B69C0[];
extern void *fn_801CC3C4(const char *path);
extern s16 fn_800ED8C4(void *p);
extern u8 lbl_8030B4D4[];
extern void fn_801ABA30(void);
extern f32 lbl_8034B96C;
extern f32 lbl_8034B8B0;
extern void TextSetColor(u32 colour);
extern void TextPrint(s32 x, s32 y, const char *str);

void fn_80199B9C(void* p, f32 v) {
    *(f32*)((u8*)p + 0x34) = v;
}

void fn_80199BA4(void* p, u8 v) {
    *(u8*)((u8*)p + 0x40) = v;
}

void fn_80199BAC(void* p, f32 a, f32 b) {
    *(f32*)((u8*)p + 0x4) = a;
    *(f32*)((u8*)p + 0x8) = b;
}

void fn_80199BB8(void* p, f32 a, f32 b) {
    *(f32*)((u8*)p + 0xC) = a;
    *(f32*)((u8*)p + 0x10) = b;
}

void fn_80199F38(void* obj) {
    UiObjUpdate(obj);
}

void fn_8019AD94(void* p, u32 a, u32 b) {
    ((u32*)p)[0] = a;
    ((u32*)p)[1] = b;
}

void fn_8019B42C(void* p, u32 a) {
    ((u32*)p)[0] = a;
    ((u8**)p)[1] = lbl_8030741C + 8;
    ((u32*)p)[2] = 0;
}

void fn_801A289C(void) {
    lbl_80347180 = 0;
}

void fn_801A28AC(u8 *obj) {
    s32 r;
    fn_801DC214();
    do {
        r = fn_80248708(obj, 0, 0);
    } while (r == -1);
    fn_801A6A04(r);
}

void fn_801A2D20(u8 *obj, u32 a, u32 b) {
    *(f32 *)(*(u8 **)(obj + 0x24) + 0x1c) = (f32)a / (f32)b;
}

void fn_801A37C4(void) {
    u8* p = lbl_8034717C;
    p[1] = 0;
    lbl_8034717C[0] = 0;
}

void fn_801A4060(void* obj) {
    *(u32*)(*(u8**)((u8*)obj + 0x24) + 0x268) = 0;
}

void fn_801A41C0(void* obj) {
    void* p = *(void**)obj;
    if (p != 0) {
        fn_801E17E0(p);
    }
}

void fn_801A471C(s32 idx) {
    u8* p = lbl_803081CC + idx * 0x50;
    *(u32*)(p + 0xC) = 0;
    *(u32*)(p + 0x10) = 0;
}

u8 *fn_801A4AF4(u8 *obj) {
    u8 *r31 = fn_80226670(obj, fn_801A4B40);
    *(void **)(r31 + 0x24) = fn_801E1A74(1, 6);
    return r31;
}

void fn_801A64B4(void* obj, u8 idx) {
    u8* p = *(u8**)((u8*)obj + 0x24);
    u8* q = *(u8**)(p + 0x20C);
    if (q == 0) {
        return;
    }
    *(u32*)(*(u8**)(q + 0x28) + 0x4C) = lbl_802B6810[idx];
}

void fn_801A6824(u8 *obj) {
    if (*(void **)(*(u8 **)(obj + 0x24) + 0x204) != 0) {
        fn_801E17E0(*(void **)(*(u8 **)(obj + 0x24) + 0x204));
        *(u32 *)(*(u8 **)(obj + 0x24) + 0x204) = 0;
    }
}

void fn_801A69BC(void) {
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

void fn_801AB98C(Obj *o)
{
    Sub *s = o->sub;
    s->fc = (float)(s32)(s->h1a * 0x18);
    o->sub->f8 = 0.0f;
}

void fn_801B6400(u32 v) {
    u8* p = *(u8**)((u8*)lbl_803471B8 + 0x24);
    u8* q = *(u8**)(p + 0x214);
    if (q == 0) {
        return;
    }
    *(u32*)(*(u8**)(q + 0x28) + 0x4C) = v;
}

u32 fn_801B94F0(void)
{
    u8 *p = *(u8 **)((u8 *)lbl_803471B8 + 0x30);
    u32 sum = *(u32 *)(p + 0x3cc);
    sum += *(u32 *)(p + 0x0);
    sum += *(u32 *)(p + 0x144);
    sum += *(u32 *)(p + 0x288);
    sum += *(u32 *)(p + 0x510);
    return sum != 0;
}

void fn_801BCFAC(u8* obj, s32 idx) {
    s32 j = *(s32*)(*(u8**)(obj + 4) + idx * 0x34);
    *(f32*)(*(u8**)obj + j * 0x14 + 0xC) = 0.59f;
}

void fn_801BEAE4(void* a, s32 b) {
    fn_801BEB10(a, 0, b, 0);
}

void fn_8019E33C(Task *t) {
    if (lbl_80347508 == 0) {
        u8 *p = *(u8 **)((u8 *)t->work + 0x208);
        if (p != 0) {
            p[0x18] |= 0x40;
            *(void **)((u8 *)t->work + 0x208) = 0;
        }
        fn_801A65D4(t);
        t->state = 0x20;
    }
}

void fn_8019E3E0(Task *t) {
    if (fn_801A6554(t) == 0) {
        t->state = 0x1E;
    } else if (*(u32 *)(lbl_80311A60[0] + 0x8) & 0x200) {
        fn_801A64E0(t);
        t->state = 0x1E;
    }
}

void fn_8019E5F0(Task *t) {
    fn_801A66AC(*(void **)((u8 *)t->work + 0x20C));
    if (*(u32 *)(lbl_80311A60[0] + 0x8) & 0x300) {
        fn_801A4DCC(t, 1);
        t->state = 0xC;
    }
}

void fn_8019EDEC(Task *t) {
    if (fn_801A6554(t) == 0 || (*(u32 *)(lbl_80311A60[0] + 0x8) & 0x200)) {
        fn_801A64B4(t, 5);
        t->state = 0x8;
    }
}

void fn_801A18FC(Task *t) {
    if (((u8 *)t->work)[0x1] == 1) {
        fn_801CBBAC(8.0f);
    } else {
        Ui2DBegin();
        ((u8 *)t->work)[0x2] = 0xFF;
    }
    t->state = 0x1;
}

void fn_801A2CC4(void) {
    if (lbl_8034718C != 0) {
        s32 r;
        fn_801DC214();
        r = CARDUnmount(0);
        if (r == 0 || r == -3) {
            fn_801E17E0((void *)lbl_8034718C);
            lbl_8034718C = 0;
        }
    }
    lbl_80347184 = 0;
}

void fn_801A39B4(u16 id, void *obj) {
    char buf[0x8];

    fn_8025CB24(buf, ".%03d", id);
    fn_8025F120(obj, "SA_LEGENDS");
    fn_8025F0B0(obj, buf);
}

void fn_801A64E0(Task *t) {
    s32 i;

    for (i = 0; i < 0x10; i++) {
        u8 *slot = *(u8 **)((u8 *)t->work + 0x20C + i * 4);
        if (slot != 0 && *(UiObj **)(slot + 0x28) != 0) {
            UiObjFinish(*(UiObj **)(slot + 0x28));
        }
    }
}

s32 fn_801A6554(Task *t) {
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

void fn_801A686C(Task *t) {
    *(void **)((u8 *)t->work + 0x204) = fn_801CC3C4(lbl_802B69C0);
    if (*(void **)((u8 *)t->work + 0x204) != 0) {
        *(s16 *)((u8 *)t->work + 0x10) = fn_800ED8C4(*(void **)((u8 *)t->work + 0x204));
    }
}

void *fn_801AB9D0(s32 a) {
    u8 *obj = fn_80226670((u8 *)a, fn_801ABA30);
    *(void **)(obj + 0x24) = fn_801E1A74(1, 6);
    *(u8 *)(*(u8 **)(obj + 0x24) + 0x4) = *(s16 *)(lbl_8030B4D4 + 0x2D0);
    return obj;
}

void fn_801B0B2C(u8 *obj) {
    u8 *e;
    s32 x;
    s32 y;

    TextSetColor(0xFF201008);
    e = *(u8 **)(obj + 0x28);
    x = (s32)(lbl_8034B96C + *(f32 *)(e + 0x24));
    y = (s32)(lbl_8034B8B0 + *(f32 *)(e + 0x28));
    TextPrint(x, y, *(const char **)(e + 0x4C));
}
