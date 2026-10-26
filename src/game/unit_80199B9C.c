#include "types.h"
#include "game/task.h"
#include "game/uiobj.h"

extern u8 lbl_8030741C[];
extern u32 lbl_80347180;
extern u8 lbl_8034717C[2];
extern u8 lbl_803081CC[];
extern u32 lbl_802B6810[];
void UiSpritesFree(void);
void UiSpritesLoad(void* p);
extern char lbl_802B69D4[];
extern u8 lbl_802EBEA4[];
void fn_801BEB10(void* a, s32 b, s32 c, s32 d);
extern void fn_801DC214(void);
extern s32 fn_80248708(u8 *obj, s32 a, s32 b);
extern s32 fn_801A6A04(s32 r);
extern void fn_801A4B40(void);
extern u8 *fn_80226670(u8 *obj, void (*cb)(void));
extern void *fn_801E1A74(s32 a, s32 b);
typedef struct Sub_UNIT0000 {
    u8 pad0[0x8];
    float f8;
    float fc;
    u8 pad1[0xa];
    u16 h1a;
} Sub_UNIT0000;
typedef struct Obj_UNIT0000 {
    u8 pad[0x30];
    Sub_UNIT0000 *sub;
} Obj_UNIT0000;
extern s32 lbl_80347508;
extern void fn_801A65D4(Task *t);
extern u8 *lbl_80311A60[];
extern s32 fn_801A6554(void *o);
extern void fn_801A64E0(void *o);
extern void fn_801A66AC(void *p);
extern void *fn_801A4DCC(void *a, u16 flag);
extern void fn_801CBBAC(f32 f);
extern void Ui2DBegin(void);
extern void *lbl_8034718C[2];
extern u32 lbl_80347184;
extern s32 CARDUnmount(s32 slot);
extern s32 fn_8025CB24(char *, const char *, ...);
extern void fn_8025F120(void *, const char *);
extern void fn_8025F0B0(void *, const char *);
extern char lbl_802B69C0[];
extern void *fn_801CC3C4(const char *path);
extern s16 fn_800ED8C4(void *p);
extern u8 lbl_8030B4D4[];
extern void fn_801ABA30(void);
extern f32 lbl_8034B96C;
extern f32 lbl_8034B8B0;
extern void TextSetColor(u32 colour);
extern void TextPrint(s32 x, s32 y, const char *str);
typedef struct Obj_80199F58 {
    u8 pad0[0x94];
    void *p94;
    void *p98;
    s8 f9c;
    u8 pad9d[3];
    void *pa0;
    void *pa4;
    s8 fa8;
    u8 pada9[3];
    void *pac;
    void *pb0;
    s8 fb4;
    u8 padb5[3];
    u8 padb8[4];
    void *pbc;
} Obj_80199F58;
extern void *fn_801E1C7C(u32 size);
extern void fn_8019A15C(u8 *o, s8 a, s8 b, s8 c);
extern void *fn_801D68C4(void *p, s32 n);
extern void *lbl_803470E8;
extern void *lbl_803470F0;
extern void fn_801A473C();
extern void fn_801A69BC();
extern void fn_801A6824(void *o);
extern void fn_80226DC4(void);
extern void Ui2DEnd(void);
extern s32 lbl_803473C4;
extern u32 lbl_80310B3C[];
typedef struct Ctx_8019E294 {
    u8 b0;
    u8 b1;
    u8 pad2[8];
    u8 ba;
} Ctx_8019E294;
typedef struct Self_8019E294 {
    u8 pad0[0x18];
    u8 flags18;
    u8 pad1[0xb];
    Ctx_8019E294 *ctx;
} Self_8019E294;
extern s32 fn_801A2670(u8 idx, s32 *out);
extern void fn_801A64B4(void *o, u8 k);
extern void MenuPlaySe(s32 se);
typedef struct Ctx_8019E650 {
    u8 pad0[4];
    u8 b4;
} Ctx_8019E650;
typedef struct Self_8019E650 {
    u8 pad0[0x19];
    u8 state19;
    u8 pad1[0xa];
    Ctx_8019E650 *ctx;
} Self_8019E650;
typedef struct Holder_8019FDB0 {
    u8 pad0[0x28];
    UiObj *ui;
} Holder_8019FDB0;
typedef struct Ctx_8019FDB0 {
    u8 pad0[8];
    u8 b8;
    u8 pad1[0x218 - 9];
    Holder_8019FDB0 *p218;
    Holder_8019FDB0 *p21c;
    Holder_8019FDB0 *p220;
    Holder_8019FDB0 *p224;
    Holder_8019FDB0 *p228;
} Ctx_8019FDB0;
typedef struct Self_8019FDB0 {
    u8 pad0[0x19];
    u8 state19;
    u8 pad1[0xa];
    Ctx_8019FDB0 *ctx;
} Self_8019FDB0;
extern void fn_801A6650(void *o, s32 k);
typedef struct Ctx_8019FE64 {
    u8 pad0[0x220];
    void *p220;
    void *p224;
    void *p228;
} Ctx_8019FE64;
typedef struct Self_8019FE64 {
    u8 pad0[0x19];
    u8 state19;
    u8 pad1[0xa];
    Ctx_8019FE64 *ctx;
} Self_8019FE64;
typedef struct Holder_8019FF38 {
    u8 pad0[0x28];
    UiObj *ui;
} Holder_8019FF38;
typedef struct Ctx_8019FF38 {
    u8 pad0[4];
    u8 b4;
    u8 pad1[0x218 - 5];
    Holder_8019FF38 *p218;
    Holder_8019FF38 *p21c;
} Ctx_8019FF38;
typedef struct Self_8019FF38 {
    u8 pad0[0x19];
    u8 state19;
    u8 pad1[0xa];
    Ctx_8019FF38 *ctx;
} Self_8019FF38;
extern void fn_801A47D8(void *o);
extern void fn_80227068(s32 a);
extern void fn_801A69DC(void);
extern void fn_801A686C(void *o);
extern void fn_801A68C4(void *o);
extern void *fn_801A4AF4(void *o);
extern void fn_801C09A4(void);
extern void fn_801CBC30(void);
extern void fn_801CBBD8(void);
extern void fn_801CBB9C(f32 f);
typedef struct Ctx_801A1834 {
    u8 b0;
    u8 b1;
    u8 pad2[0xe];
    u16 h10;
    u8 pad12[0x208 - 0x12];
    void *p208;
} Ctx_801A1834;
typedef struct Self_801A1834 {
    u8 pad0[0x19];
    u8 state19;
    u8 pad1[0xa];
    Ctx_801A1834 *ctx;
} Self_801A1834;
extern void* fn_802267AC(void* a, void (*b)(void));
extern void fn_801A2D60(void);
typedef struct Task_801A343C {
    u8 pad00[0x24];
    void* p24;
} Task_801A343C;
typedef struct Rec24 {
    u8 pad00[0xC];
    s32 w0c;
    s32 w10;
    u8 pad14;
    u8 b15;
    s16 h16;
    s16 h18;
} Rec24;
typedef struct Actor24 {
    u8 pad00;
    u8 b01;
    u8 pad02[2];
    u8 b04;
    u8 pad05[0xD];
    s16 h12;
    s32 w14;
    u8 pad18[0x238];
    s32 w250;
} Actor24;
#define R24(p) ((Rec24 *)((Task_801A343C *)(p))->p24)
#define A24(p) ((Actor24 *)((Task_801A343C *)(p))->p24)
extern s32 fn_801A388C(void* a, char* name, s32 flags);
extern const char lbl_802B4978[];
extern const char lbl_8034B6A0[6];
extern void fn_80252E5C(void* p);
extern void* lbl_8034716C;
extern void* lbl_80347168;
extern void* fn_801E1A74(s32 size, s32 n);
void fn_801A4E58(void *o);
typedef struct Ctl_801A4DCC {
    u8 pad00[0x8];
    void* p08;
    u8 pad0C[0xC];
    u8 b18;
    u8 b19;
    u8 pad1A[0xA];
    void* p24;
} Ctl_801A4DCC;
typedef struct Wk_801A4DCC {
    f32 f00;
} Wk_801A4DCC;
typedef struct Ctl_801A4E58 {
    u8 pad00[0x8];
    struct Ctl_801A4E58* p08;
    u8 pad0C[0xC];
    u8 b18;
    u8 b19;
    u8 pad1A[0xA];
    struct Wk_801A4E58* p24;
} Ctl_801A4E58;
typedef struct Wk_801A4E58 {
    f32 f00;
    u8 pad04[0x14];
    f32 f18;
} Wk_801A4E58;
extern void fn_801A5274(void);
typedef struct MenuUi {
    f32 z;
    f32 x, y;
    f32 tx, ty;
    f32 vx, vy;
    f32 rdx, rdy;
    f32 rect[4];
    f32 alpha;
    f32 f38, f3c;
    u8 alpha_en;
    u8 raised;
    u16 frames;
    u16 delay;
    u16 cmd;
    s16 se;
    u16 pad4A;
    u32 w4c;
    s16 h50;
    s16 h52;
    s16 h54;
    s16 h56;
    u8 pad58[0x14];
} MenuUi;
typedef struct Task_801A51A8 {
    u8 pad00[0x24];
    u8* p24;
    MenuUi* p28;
    u32 w2c;
} Task_801A51A8;
extern void fn_801ABD40(void);
typedef struct Task_801ABE90 {
    u8 pad00[0x24];
    u8* p24;
    MenuUi* p28;
    u32 w2c;
} Task_801ABE90;
extern void fn_801ABF70(void);
typedef struct Task_801AC094 {
    u8 pad00[0x24];
    u8* p24;
    MenuUi* p28;
    u32 w2c;
} Task_801AC094;
extern void fn_801B0F1C(void);
extern s32 fn_801F4AE4(s16 v);
typedef struct Task_801B1104 {
    u8 pad00[0x24];
    u8* p24;
    MenuUi* p28;
    u32 w2c;
} Task_801B1104;
typedef struct Sub_801B1104 {
    u8 pad00[6];
    u16 h06;
} Sub_801B1104;
typedef struct Pl {
    u32 w00;
    u8 pad04[0x140];
    u32 w144;
    u8 pad148[0x140];
    u32 w288;
    u8 pad28C[0x140];
    u32 w3cc;
    u8 pad3D0[0x140];
    u32 w510;
} Pl;
typedef struct Game_UNIT {
    u8 pad00[0x24];
    Sub_801B1104* p24;
    u8 pad28[0x8];
    Pl* p30;
} Game_UNIT;
extern Game_UNIT* lbl_803471B8;
extern void fn_801B11EC(void);
typedef struct Task_801B1A78 {
    u8 pad00[0x24];
    u8* p24;
    MenuUi* p28;
    u32 w2c;
} Task_801B1A78;
extern void fn_801B5EA8(void);
typedef struct Task_801B6240 {
    u8 pad00[0x24];
    u8* p24;
    MenuUi* p28;
    u32 w2c;
} Task_801B6240;
extern void fn_801B6950(void);
typedef struct Task_801B6AE8 {
    u8 pad00[0x24];
    u8* p24;
    MenuUi* p28;
    u32 w2c;
} Task_801B6AE8;
typedef struct Pair {
    const char* a;
    const char* b;
} Pair;
extern const Pair lbl_802EBFDC[8];
extern const char lbl_802B8F80[];
extern u8 lbl_80310A1C[0x120];
typedef struct Sub2 {
    u8 pad00[0x11C];
    u32 w11c;
    u8 pad120[4];
    u32 w124;
} Sub2;
typedef struct Task_801B8E68 {
    u8 pad00[0x24];
    Sub2* p24;
} Task_801B8E68;
typedef struct Flags {
    u8 pad00[8];
    u32 w08;
} Flags;
typedef struct Stat {
    u8 pad00[0x34C];
    s32 w34c;
    u8 pad350[0x16A0 - 0x350];
} Stat;
extern Stat lbl_8030B7F4;

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

void *fn_801A4AF4(void *obj) {
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

void fn_801A6824(void *o0) {
    u8 *obj = o0;
    if (*(void **)(*(u8 **)(obj + 0x24) + 0x204) != 0) {
        fn_801E17E0(*(void **)(*(u8 **)(obj + 0x24) + 0x204));
        *(u32 *)(*(u8 **)(obj + 0x24) + 0x204) = 0;
    }
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

void fn_801AB98C(Obj_UNIT0000 *o)
{
    Sub_UNIT0000 *s = o->sub;
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
    if (lbl_8034718C[0] != 0) {
        s32 r;
        fn_801DC214();
        r = CARDUnmount(0);
        if (r == 0 || r == -3) {
            fn_801E17E0(lbl_8034718C[0]);
            lbl_8034718C[0] = 0;
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

void fn_801A686C(void *o) {
    Task *t = o;
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

void fn_80199F58(Obj_80199F58 *o) {
    if (o->pbc != 0) {
        fn_801E17E0(o->pbc);
    }
    if (o->f9c > 0) {
        o->f9c = 0;
        fn_801E17E0(o->p94);
        fn_801E17E0(o->p98);
    }
    if (o->fa8 > 0) {
        o->fa8 = 0;
        fn_801E17E0(o->pa0);
        fn_801E17E0(o->pa4);
    }
    if (o->fb4 > 0) {
        o->fb4 = 0;
        fn_801E17E0(o->pac);
        fn_801E17E0(o->pb0);
    }
}

void fn_8019A15C(u8 *o, s8 a, s8 b, s8 c) {
    *(s8 *)(o + 0x28) = a;
    if (a > 0) {
        *(void **)(o + 0x20) = fn_801E1C7C(a * 4);
        *(void **)(o + 0x24) = fn_801E1C7C(a * 8);
    }
    *(s8 *)(o + 0x34) = c;
    if (c > 0) {
        *(void **)(o + 0x2c) = fn_801E1C7C(c * 4);
        *(void **)(o + 0x30) = fn_801E1C7C(c * 8);
    }
    *(s8 *)(o + 0x40) = b;
    if (b > 0) {
        *(void **)(o + 0x38) = fn_801E1C7C(b * 4);
        *(void **)(o + 0x3c) = fn_801E1C7C(b * 8);
    }
}

void fn_8019B36C(u8 *o) {
    *(f32 *)(o + 0x0) = -5440.0f;
    *(f32 *)(o + 0x4) = 0.0f;
    *(f32 *)(o + 0x10) = 1.0f;
    *(f32 *)(o + 0x14) = 0.0f;
    *(f32 *)(o + 0x18) = 1.0f;
    *(f32 *)(o + 0x1c) = 0.0f;
    *(u32 *)(o + 0x8) = 0;
    *(u32 *)(o + 0xc) = 0;
    fn_8019A15C(o, 1, 0, 1);
    *(void **)(*(u8 **)(o + 0x2c)) = fn_801D68C4(lbl_803470E8, 2);
    *(f32 *)(*(u8 **)(o + 0x30) + 0x0) = 0.0f;
    *(f32 *)(*(u8 **)(o + 0x30) + 0x4) = 0.0f;
    *(void **)(*(u8 **)(o + 0x20)) = fn_801D68C4(lbl_803470F0, 10);
    *(f32 *)(*(u8 **)(o + 0x24) + 0x0) = 0.0f;
    *(f32 *)(*(u8 **)(o + 0x24) + 0x4) = 0.0f;
    *(u32 *)(o + 0x44) = 0;
}

void fn_8019E294(Self_8019E294 *o) {
    fn_801A473C(o);
    fn_801A69BC();
    if (o->ctx->b1 == 1) {
        if (o->ctx->b0 == 0) {
            fn_80226DC4();
        }
        {
            u8 ba = o->ctx->ba;
            if (ba == 1) {
                lbl_803473C4 = ba;
                lbl_80310B3C[0x21] &= 0x7fffffff;
            } else {
                lbl_803473C4 = 2;
            }
        }
    } else {
        fn_801A6824(o);
        lbl_803473C4 = 1;
        Ui2DEnd();
    }
    o->flags18 |= 0x40;
}

void fn_8019E650(Self_8019E650 *o) {
    s32 x;

    if (fn_801A2670(o->ctx->b4, &x) != 0) {
        if (x == 0) {
            fn_801A4DCC(o, 1);
            fn_801A64B4(o, 0x17);
            MenuPlaySe(0x15);
        } else {
            u8 k;
            if (x == -3) {
                k = 0x18;
            } else {
                k = (u8)(o->ctx->b4 + 0x19);
            }
            fn_801A64B4(o, k);
            MenuPlaySe(3);
        }
        o->state19 = 0x1b;
    }
}

void fn_8019FDB0(Self_8019FDB0 *o) {
    if (fn_801A6554(o) == 0 || (*(u32 *)(lbl_80311A60[0] + 8) & 0x100)) {
        s32 cmd;
        fn_801A64E0(o);
        cmd = 0x14;
        if (o->ctx->b8 == 0) {
            cmd = 0x15;
        }
        UiObjSetCommand(o->ctx->p220->ui, (u16)cmd, 0);
        cmd = 0x14;
        if (o->ctx->b8 == 1) {
            cmd = 0x15;
        }
        UiObjSetCommand(o->ctx->p224->ui, (u16)cmd, 0);
        o->state19 = 0xf;
    }
}

void fn_8019FE64(Self_8019FE64 *o) {
    s32 doit = 0;
    s32 i;

    if (fn_801A6554(o) == 0) {
        doit = 1;
    } else if (*(u32 *)(lbl_80311A60[0] + 8) & 0x100) {
        fn_801A64E0(o);
        doit = 1;
    }
    if (doit) {
        if (o->ctx->p220 != 0) {
            fn_801A6650(o, 5);
            fn_801A6650(o, 6);
        }
        if (o->ctx->p228 != 0) {
            for (i = 0; i < 7; i++) {
                fn_801A6650(o, (u16)(i + 7));
            }
        }
        o->state19 = 4;
    }
}

void fn_8019FF38(Self_8019FF38 *o) {
    if (o->ctx->b4 >= 2) {
        return;
    }
    if (o->ctx->b4 == 0) {
        UiObjMoveToX(o->ctx->p21c->ui, 6, 5, -8.0f);
        UiObjSetCommand(o->ctx->p21c->ui, 0xf, 0);
    } else {
        UiObjMoveToX(o->ctx->p218->ui, 6, 5, -8.0f);
        UiObjSetCommand(o->ctx->p218->ui, 0xf, 3);
        UiObjMoveToY(o->ctx->p21c->ui, 3, -1, 164.0f);
        UiObjSetCommand(o->ctx->p21c->ui, 0xf, 0);
    }
    o->state19 = 0xd;
}

void fn_801A1834(Self_801A1834 *o) {
    if (o->ctx->b1 == 1 && lbl_80347508 != 0) {
        return;
    }
    fn_801A47D8(o->ctx);
    if (o->ctx->b1 == 1 && o->ctx->b0 == 0) {
        fn_80227068(0);
    }
    fn_801A69DC();
    if (o->ctx->b1 == 0) {
        if (o->ctx->h10 >= 0x3c) {
            fn_801A686C(o);
        }
        fn_801A68C4(o);
    }
    o->ctx->p208 = fn_801A4AF4(o);
    fn_801C09A4();
    fn_801CBC30();
    fn_801CBBD8();
    fn_801CBB9C(8.0f);
    o->state19 = 2;
}

void* fn_801A343C(Task_801A343C* a)
{
    Task_801A343C* o = fn_802267AC(a, fn_801A2D60);
    o->p24 = fn_801E1C7C(0x24);
    *(s32*)((u8*)o + 0x28) = 0;
    R24(o)->w10 = A24(a)->b04;
    R24(o)->b15 = 7;
    A24(a)->h12 = 7;
    R24(o)->w0c = 0;
    A24(a)->w14 = 0;
    A24(a)->w250 = 0;
    R24(o)->h16 = 0;
    if (A24(a)->b01 == 0) {
        R24(o)->h18 = R24(o)->b15 + 1;
    } else {
        R24(o)->h18 = R24(o)->b15 + 3;
    }
    return o;
}

s32 fn_801A37D8(void* a)
{
    char buf[8];
    char name[0x20];
    s32 i = 0;
    s32 ret = 0;
    s32 flag = 0;

    for (; i < 7 && flag == 0; i++) {
        s32 r;
        fn_8025CB24(buf, lbl_8034B6A0, (u16)i);
        fn_8025F120(name, lbl_802B4978);
        fn_8025F0B0(name, buf);
        r = fn_801A388C(a, name, 0);
        if (r == 0) {
            flag = 1;
            ret = 1;
        } else if (r != -4) {
            flag = 1;
        }
    }
    return ret;
}

void fn_801A473C(void)
{
    s32 i;

    for (i = 0; i < 2; i++) {
        if (lbl_8034718C[i]) {
            fn_801E17E0(lbl_8034718C[i]);
            lbl_8034718C[i] = 0;
        }
    }
    if (lbl_8034716C) {
        fn_80252E5C(&lbl_8034716C);
        lbl_8034716C = 0;
    }
    if (lbl_80347168) {
        fn_80252E5C(&lbl_80347168);
        lbl_80347168 = 0;
    }
}

void* fn_801A4DCC(void* a, u16 flag)
{
    Ctl_801A4DCC* o = fn_802267AC(a, (void (*)(void))fn_801A4E58);
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

Task_801A51A8* fn_801A51A8(void* a)
{
    Task_801A51A8* o = fn_802267AC(a, fn_801A5274);
    o->p24 = fn_801E1A74(1, 0x58);
    o->p28 = fn_801E1A74(1, 0x6c);
    o->p24[0] = 0;
    o->p28->alpha_en = 0;
    o->p28->z = -4000.0f;
    o->p28->x = 640.0f;
    o->p28->tx = 640.0f;
    o->p28->y = 480.0f;
    o->p28->ty = 480.0f;
    o->p28->rdx = 0.0f;
    o->p28->rdy = 0.0f;
    o->p28->alpha = 1.0f;
    o->p28->w4c = 0;
    return o;
}

Task_801ABE90* fn_801ABE90(void* a)
{
    Task_801ABE90* o = fn_802267AC(a, fn_801ABD40);
    o->p24 = fn_801E1A74(1, 0x58);
    o->p28 = fn_801E1A74(1, 0x6c);
    o->p28->alpha_en = 0;
    o->p24[0] = 0;
    o->p28->x = -260.0f;
    o->p28->tx = -260.0f;
    o->p28->y = 324.0f;
    o->p28->ty = 324.0f;
    o->p28->rdx = 0.0f;
    o->p28->rdy = 0.0f;
    o->p28->f38 = 1.0f;
    o->p28->alpha = 1.0f;
    o->p28->z = -4250.0f;
    o->w2c = 0;
    UiObjSetLowered((UiObj*)o->p28);
    UiObjCalcRect((UiObj*)o->p28);
    return o;
}

Task_801AC094* fn_801AC094(void* a)
{
    Task_801AC094* o = fn_802267AC(a, fn_801ABF70);
    o->p24 = fn_801E1A74(1, 0x58);
    o->p28 = fn_801E1A74(1, 0x6c);
    o->p28->alpha_en = 0;
    o->p24[0] = 0;
    o->p28->x = 640.0f;
    o->p28->tx = 640.0f;
    o->p28->y = 84.0f;
    o->p28->ty = 84.0f;
    o->p28->rdx = 0.0f;
    o->p28->rdy = 0.0f;
    o->p28->f38 = 1.0f;
    o->p28->alpha = 1.0f;
    o->p28->z = -4350.0f;
    o->w2c = 0;
    UiObjSetLowered((UiObj*)o->p28);
    return o;
}

Task_801B1104* fn_801B1104(void* a)
{
    Task_801B1104* o = fn_802267AC(a, fn_801B0F1C);
    o->p24 = fn_801E1A74(1, 0x58);
    o->p28 = fn_801E1A74(1, 0x6c);
    o->p28->f38 = 1.0f;
    o->p28->alpha = 1.0f;
    o->w2c = 0;
    o->p28->h54 = 0;
    o->p24[0] = 0;
    o->p28->x = -348.0f;
    o->p28->tx = -348.0f;
    o->p28->y = 36.0f;
    o->p28->ty = 36.0f;
    o->p28->z = -4050.0f;
    o->p28->h52 = 0;
    o->p28->w4c = fn_801F4AE4((s16)lbl_803471B8->p24->h06);
    UiObjSetLowered((UiObj*)o->p28);
    return o;
}

Task_801B1A78* fn_801B1A78(void* a)
{
    Task_801B1A78* o = fn_802267AC(a, fn_801B11EC);
    o->p24 = fn_801E1A74(1, 0x58);
    o->p28 = fn_801E1A74(1, 0x6c);
    o->w2c = 0;
    o->p24[0] = 0;
    o->p28->x = 648.0f;
    o->p28->tx = 648.0f;
    o->p28->y = 282.0f;
    o->p28->ty = 282.0f;
    o->p28->h54 = 0;
    o->p28->h52 = 0;
    o->p28->f38 = 1.0f;
    o->p28->alpha = 1.0f;
    o->p28->z = -4400.0f;
    return o;
}

Task_801B6240* fn_801B6240(void* a, f32 x)
{
    Task_801B6240* o = fn_802267AC(a, fn_801B5EA8);
    o->p24 = fn_801E1A74(1, 0x58);
    o->p28 = fn_801E1A74(1, 0x6c);
    o->w2c = 0;
    o->p24[0] = 0;
    o->p28->alpha_en = 0;
    o->p28->x = 640.0f;
    o->p28->tx = 640.0f;
    o->p28->y = 480.0f;
    o->p28->ty = 480.0f;
    o->p28->rdx = 0.0f;
    o->p28->rdy = 0.0f;
    o->p28->alpha = 1.0f;
    o->p28->z = x;
    UiObjSetLowered((UiObj*)o->p28);
    return o;
}

Task_801B6AE8* fn_801B6AE8(void* a)
{
    Task_801B6AE8* o = fn_802267AC(a, fn_801B6950);
    o->p24 = fn_801E1A74(1, 0x58);
    o->p28 = fn_801E1A74(1, 0x6c);
    o->p24[0] = 0;
    o->p28->alpha_en = 0;
    o->p28->z = -4400.0f;
    o->p28->x = -260.0f;
    o->p28->tx = -260.0f;
    o->p28->y = 100.0f;
    o->p28->ty = 100.0f;
    o->p28->rdx = 0.0f;
    o->p28->rdy = 0.0f;
    o->p28->alpha = 1.0f;
    UiObjSetRaised((UiObj*)o->p28);
    return o;
}

void fn_801B71E8(s32 x, s32 y, s16 idx)
{
    s8 kind = lbl_80310A1C[0x64 + idx];

    switch (kind) {
    case 1:
    case 2:
        TextPrint(x, y, lbl_802EBFDC[idx].a);
        break;
    case 3:
        TextPrint(x, y, lbl_802EBFDC[idx].b);
        break;
    default:
        TextPrint(x, y, lbl_802B8F80);
        break;
    }
}

void fn_801B8E68(Task_801B8E68* t)
{
    u32 n;
    Sub2* s = t->p24;

    n = s->w11c;
    if (n == 0) {
        return;
    }
    if (((Flags *)lbl_80311A60[0])->w08 & 0x100) {
        lbl_8030B7F4.w34c += n;
        s->w11c = 0;
        if (lbl_8030B7F4.w34c >= 99999999) {
            lbl_8030B7F4.w34c = 99999999;
        }
        return;
    }
    if (n <= s->w124) {
        lbl_8030B7F4.w34c += n;
        s->w11c = 0;
        if (lbl_8030B7F4.w34c >= 99999999) {
            lbl_8030B7F4.w34c = 99999999;
        }
        return;
    }
    s->w11c = n - s->w124;
    lbl_8030B7F4.w34c += t->p24->w124;
    if (lbl_8030B7F4.w34c >= 99999999) {
        lbl_8030B7F4.w34c = 99999999;
    }
}

u16 fn_801B952C(u16 k)
{
    switch (k) {
    case 0:
        return (u16)lbl_803471B8->p30->w3cc;
    case 1:
        return (u16)lbl_803471B8->p30->w00;
    case 2:
        return (u16)lbl_803471B8->p30->w144;
    case 3:
        return (u16)lbl_803471B8->p30->w288;
    case 4:
        return (u16)lbl_803471B8->p30->w510;
    default:
        return 0;
    }
}
