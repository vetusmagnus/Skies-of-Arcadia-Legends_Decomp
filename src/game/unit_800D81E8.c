#include "types.h"
#include <string.h>
#include "game/util.h"

typedef struct {
    u8 pad0[8];
    u32 x8;
} PadData;
typedef struct {
    PadData* pad;
    u8 rest[0x14];
} Lbl311A60Ty;
extern Lbl311A60Ty lbl_80311A60;
extern void fn_80226D14(void);
extern void fn_80226BD0(f32 a, f32 b);
typedef struct {
    u8 pad[0x198];
    s32 looped;
} LoopObj;
typedef struct {
    u8 pad[0x18C];
    f32 frame;
    f32 speed;
    u8 pad194[4];
    s32 looped;
} AnimObj;
extern void fn_800DF74C(void* p, void* data);
extern char lbl_802B1718[];
typedef struct {
    u8 pad[0x110];
    s32 tgt[3];
} TgtObj;
typedef struct {
    u8 pad0[4];
    u32 id;
    u8 rest[0x60];
} TblEntry;
typedef struct {
    s32 count;
    TblEntry* entries;
} Tbl;
typedef struct {
    u8 pad[4];
    s32 idx;
} IdxObj;
typedef struct {
    u8 pad0[0xE8];
    void* motion;
    u8 pad1[0x18C - 0xEC];
    f32 frame;
    f32 speed;
} MotObj;
typedef struct {
    u8 pad[0x24];
    MotObj* dst;
} MotCtx;
typedef struct {
    u32 w0;
    u32 w4;
    u8 b8;
} Unk80311AC0;
extern Unk80311AC0 lbl_80311AC0;
extern s32 lbl_80346DB0;
extern u32 lbl_803473A4;
extern s16 lbl_80346DC0;
extern u32 lbl_80346DB8;
extern u32 lbl_80346DB4;
extern s32 lbl_80311AD4[11];
extern s32 lbl_80346E48;
extern f32 lbl_80305C68[4];
extern void* lbl_80346E58;
extern s16 lbl_80346E64;
extern void (*lbl_80347490)(s32 a);
extern u32 lbl_8034748C;
extern u32 lbl_8034745C;
extern u16 lbl_80347458;
extern u8 *lbl_80346DCC;
extern u32 lbl_80346DD0;
extern u32 lbl_80346DD4;
extern u8 *lbl_80346E3C;
extern s32 lbl_80346E38;
extern u32 lbl_80310B3C[0xd58 / 4];
extern s32 lbl_8034757C;
extern void fn_801CC434(void* p, s32 zero, void* out);
extern void fn_80109A94(void* p);
extern void fn_800D2CA8(s32 x);
extern void fn_80100E68(void* p, s32 zero, s32 a, s32 b);
extern void fn_801E17E0(void* p);
extern void *fn_801E1C7C(u32 size);
extern s32 fn_800F7D6C(void *p);
extern s32 fn_801D6E38(s32 a);
extern void fn_801E1AC8(u16 a, u8 b, s32 c, s32 d);
typedef struct {
    u32 a;
    u32 b;
    u32 c;      /* only the high half is compared */
} Key;
typedef struct Ent_800E0470 {
    u8 pad0[0x190];
    f32 f190;
    u32 u194;
    u32 u198;
} Ent_800E0470;
extern f32 lbl_803496AC;
extern s32 fn_801C6068(void* p, s32 n);
extern f32 fn_801C5D04(void* p, s32 n);
typedef struct Src_800E04E0 {
    u8 pad0[4];
    u32 u4;
} Src_800E04E0;
typedef struct Ent_800E04E0 {
    u8 pad0[0xe8];
    Src_800E04E0* pe8;
    u8 padec[0x18c - 0xec];
    f32 f18c;
    f32 f190;
    u8 pad194[4];
    u32 u198;
} Ent_800E04E0;
extern f32 lbl_80349698;
typedef struct Ent_800E0540 {
    u8 pad0[0x190];
    f32 f190;
    u32 u194;
    u32 u198;
} Ent_800E0540;
typedef struct Mid {
    u8 pad0[8];
    u32 u8;
} Mid;
typedef struct Aux {
    u8 pad0[0x1c];
    Mid* m1c;
} Aux;
typedef struct Ent_800E05AC {
    u8 pad0[0xec];
    u32 uec;
    u8 padf0[0x18c - 0xf0];
    f32 f18c;
    f32 f190;
    u8 pad194[4];
    u32 u198;
    u8 pad19c[0x1c8 - 0x19c];
    Aux* p1c8;
} Ent_800E05AC;
extern s32 fn_801C5F40(void* p, s32 n);
typedef struct Ctx_800EDF38 {
    u8 pad0[0x19];
    u8 f19;
    u8 pad1a[0x24 - 0x1a];
    void* p24;
} Ctx_800EDF38;
extern void* lbl_803475A0;
extern Ctx_800EDF38* lbl_80346E18;
extern void* lbl_80346E14;
extern void* lbl_80346E10;
extern void* fn_802267AC(void* a, void (*b)(void));
extern void* fn_801E1C7C(u32 n);
extern void fn_800EDB70(void);
extern u32 lbl_8030A3C8[3];
extern void fn_800D2C44(u16 n);
typedef struct Rec {
    u32 u0;
    u32 u4;
    void* p8;
} Rec;
extern Rec* fn_80109404();
extern void fn_80109D74(void* p);
extern void* fn_801C6180(void* a);
extern void fn_80100BF8(void* a, u32 b, u32 c);
typedef struct Obj_801090A8 {
    u8 pad0[0x19];
    u8 state;
} Obj_801090A8;
extern u32 lbl_80347450;
extern s32 fog_enabled;
extern void fn_80100B74(void* o);
extern void fn_800D2B1C(void* p);
extern u32 fn_801096FC(s32 a, s32 b, void* c, s32 d);
extern void fn_801CC434(void* p, s32 zero, void* out);
extern s32 fn_801E1098(void* a, void* b);
typedef struct Ent_80109468 {
    u8 pad0[4];
    u32 key;
    u8 pad8[0x38 - 8];
    u32 v38;
    u8 pad3c[0x68 - 0x3c];
} Ent_80109468;
typedef struct Set_80109468 {
    s32 count;
    Ent_80109468* ent;
} Set_80109468;
typedef struct Out_80109468 {
    Set_80109468* s;
    Ent_80109468* e;
    u32 v;
} Out_80109468;
typedef struct Node_801094C8 {
    u8 pad0[4];
    Set_80109468* data;
    u8 pad8[0x30 - 8];
    struct Node_801094C8* next;
} Node_801094C8;
extern Node_801094C8* lbl_80347460;
extern s32 fn_80109468(u32 key, Set_80109468* s, Out_80109468* out);
typedef struct Src_8010AB60 {
    u8 pad0[0x38];
    f32 f38;
    f32 f3c;
    f32 f40;
    u32 u44;
    u32 u48;
    u32 u4c;
    u8 pad50[0xe8 - 0x50];
    u32 ue8;
    u8 padec[0x18c - 0xec];
    f32 f18c;
    f32 f190;
} Src_8010AB60;
typedef struct Ent_8010AB60 {
    u8 pad0[0xe8];
    u32 ue8;
    u8 padec[0x18c - 0xec];
    f32 f18c;
    f32 f190;
    u8 pad194[0x20c - 0x194];
    u32 u20c;
    u32 u210;
    u32 u214;
    u8 pad218[0x24c - 0x218];
    f32 f24c;
    f32 f250;
    f32 f254;
} Ent_8010AB60;
typedef struct Ctx_8010AB60 {
    u8 pad0[0x24];
    Ent_8010AB60* dst;
} Ctx_8010AB60;
typedef struct Tp {
    u8 pad0[0x24];
    void* p24;
} Tp;
extern s32 lbl_80346E60;
extern void* lbl_80347590;
extern void fn_8010D4F4(void);
extern void fn_802260E8(void* p);
typedef struct Sub {
    u8 pad0[0x100];
    void* p100;
    u8 pad104[0x170 - 0x104];
    s16 s170;
    s16 s172;
} Sub;
typedef struct Obj_8010DE84 {
    u8 pad0[0x19];
    u8 st;
    u8 pad1a[0x24 - 0x1a];
    Sub* p24;
} Obj_8010DE84;
extern void fn_80227810(void* p);
extern void fn_8010DDBC(void* o);

void fn_800D81E8(void) {
    fn_80226D14();
    fn_80226BD0(-2.92f, 1.0f);
}

s32 fn_800DDE60(u8 *self) {
    u8 *p = *(u8 **)(self + 0x24);
    memcpy(p + 0x104, *(u8 **)(p + 0x1d8) + 0x30, 0xc);
    return 1;
}

s32 fn_800E043C(LoopObj* obj) {
    return obj->looped != 0;
}

void fn_800E0450(AnimObj* obj) {
    if (obj == NULL) {
        return;
    }
    obj->frame = 0.0f;
    obj->speed = 0.0f;
    obj->looped = 1;
}

void fn_800E060C(void* p) {
    fn_800DF74C(p, lbl_802B1718);
}

void fn_800E0A8C(TgtObj* obj) {
    if (obj == NULL) {
        return;
    }
    obj->tgt[0] = 0;
    obj->tgt[1] = 0;
    obj->tgt[2] = 0;
}

s32 fn_800E0AD0(s32 mode, s32 a, s32 b) {
    s32 ret = 0;
    if (a > 0) {
        if ((mode == 0 && a >= b) || (mode == 1 && a > b)) {
            ret = 1;
        }
    }
    return ret;
}

s32 fn_800E0C38(u32 id) {
    s32 r = 0;
    if (id >= 0x4E20 && id < 0x6FB7) {
        r = 1;
    }
    return r;
}

void fn_800E1A24(void) {
    if (lbl_80346DB0 == 0) {
        return;
    }
    if (!(lbl_80311A60.pad->x8 & 0x1000)) {
        return;
    }
    lbl_803473A4 = ~lbl_803473A4;
}

void fn_800E28D4(f32 *src, u32 *cfg) {
    u32 a;
    u32 b;
    u32 c;
    lbl_80305C68[0] = src[0];
    lbl_80305C68[1] = src[1];
    lbl_80305C68[2] = src[2];
    a = cfg[0];
    b = cfg[1];
    c = cfg[2];
    lbl_80346DB4 = 0xFF000000 | ((a & 0xFF) << 16) | ((b & 0xFF) << 8) | (c & 0x00FF0000);
    lbl_80346DB8 = 1;
}

void fn_800E3544(void) {
    lbl_80346DC0 = 0;
    lbl_80346DB8 = 0;
}

void fn_800E36B0(void) {
    lbl_80346DCC = fn_801E1C7C(0x1610);
    memset(lbl_80346DCC, 0, 0x1610);
    lbl_80346DD4 = 0;
    lbl_80346DD0 = 0;
    *(u32 *)(lbl_80346DCC + 0x160c) = 0;
}

s32 fn_800F816C(u8 *obj) {
    s32 v = 0xa;
    if (obj != 0) {
        if (*(void **)(obj + 0x24) != 0) {
            v = fn_800F7D6C(*(void **)(obj + 0x24));
        }
        obj[0x19] = v;
    }
    return 1;
}

void fn_800FF3EC(void *src) {
    if (lbl_80346E3C != 0) {
        memcpy(lbl_80346E3C + lbl_80346E38 * 0xc0, src, 0xc0);
        lbl_80346E38 = lbl_80346E38 + 1;
    }
}

s32 fn_800FF438(void) {
    s32 ret = -1;
    if (lbl_80310B3C[0x88 / 4] & 0x10) {
        if (fn_801D6E38(lbl_8034757C) == 1) {
            ret = lbl_8034757C;
        }
    }
    return ret;
}

s32 fn_800FF48C(u32 a, u32 b) {
    s32 r = 0;
    if (lbl_80347490 == 0) {
        lbl_80347490 = (void (*)(s32))a;
        r = 1;
        lbl_8034748C = b;
    }
    return r;
}

void fn_800FF4B0(void) {
    if (lbl_80347490 != 0) {
        lbl_80347490(lbl_8034748C);
        lbl_80347490 = 0;
    }
}

void fn_800FF9FC(void) {
    lbl_80311AD4[6] = 15;
    lbl_80346E48 = 1;
}

void fn_801003F4(void* p) {
    u8 buf[0x20];
    fn_801CC434(p, 0, buf);
    fn_80109A94(buf);
}

void* fn_801005F8(Tbl* t, u16 key) {
    s32 i;
    TblEntry* e = t->entries;
    for (i = 0; i < t->count; i++) {
        if (key == e->id) {
            return e;
        }
        e++;
    }
    return NULL;
}

void fn_80100684(s32 a, s32 b) {
    fn_801E1AC8((u16)lbl_80311AC0.w4, lbl_80311AC0.b8, a, b);
}

void fn_80100720(s8 x) {
    fn_800D2CA8(x);
}

void fn_80101060(void* p, s32 a, s32 b) {
    fn_80100E68(p, 0, a, b);
}

void fn_8010108C(s32 a, s32 b, s32 c) {
    fn_80100E68((void*)0, a, b, c);
}

void fn_801097F8(s32 a, s32 b, s32 c) {
    fn_801096FC(1, a, (void*)b, c);
}

void fn_80109A4C(void) {
    void *p = lbl_80346E58;
    lbl_80347460 = 0;
    lbl_8034745C = 0;
    lbl_80347458 = 1000;
    if (p != 0) {
        memset(p, 0, 0x40000);
    }
}

void fn_8010A094(void) {
    fn_801E17E0(lbl_80346E58);
    lbl_80346E58 = NULL;
}

void* fn_8010A214(u32 idx) {
    void** tbl = (void**)lbl_80346E58;
    if (tbl != NULL) {
        if (idx < 0x10000) {
            return tbl[idx];
        }
    }
    return NULL;
}

void fn_8010A240(IdxObj* o) {
    void** tbl = (void**)lbl_80346E58;
    s32 idx;
    if (tbl == NULL) {
        return;
    }
    idx = o->idx;
    if (idx < 0) {
        return;
    }
    if (idx >= 0x10000) {
        return;
    }
    tbl[idx] = o;
}

s32 fn_8010A270(void) {
    return 0x9E;
}

s32 fn_8010A530(MotCtx* ctx, MotObj* src) {
    ctx->dst->frame = src->frame;
    ctx->dst->speed = src->speed;
    ctx->dst->motion = src->motion;
    return 0;
}

s32 fn_8010CED4(void) {
    if (lbl_80346E64 >= 2 && lbl_80346E64 < 8) {
        return 1;
    }
    return 0;
}

s32 fn_800DE390(Key* p, Key* q) {
    s32 r = 0;
    if (p != 0 && q != 0) {
        if (p->a == q->a && p->b != q->b && (p->c >> 16) == (q->c >> 16)) {
            r = 1;
        }
    }
    return r;
}

s32 fn_800DE3E8(Key* p, Key* q) {
    s32 r = 0;
    if (p != 0 && q != 0) {
        if (p->a == q->a && p->b == q->b && (p->c >> 16) == (q->c >> 16)) {
            r = 1;
        }
    }
    return r;
}

s32 fn_800DE5EC(u32 x) {
    s32 inr;
    s32 ret;
    u32 r5;
    ret = -1;
    inr = 0;
    if (x >= 0x4e20 && x < 0x6fb7) {
        inr = 1;
    }
    if (inr != 0) {
        if (x < 0x59d8) {
            r5 = x - 0x4e20;
        } else if (x < 0x6590) {
            r5 = x - 0x59d8;
        } else {
            r5 = x - 0x6590;
        }
        ret = ((r5 % 10000) / 100);
    }
    return ret;
}

void fn_800E0470(Ent_800E0470* p) {
    f32 f31;

    if (p != 0) {
        f31 = lbl_803496AC;
        if (fn_801C6068(p, 10) != 0) {
            f31 = fn_801C5D04(p, 9);
        }
        p->f190 = -f31;
        p->u198 = 0;
    }
}

void fn_800E04E0(Ent_800E04E0* p) {
    if (p != 0) {
        f32 v;
        if (p->pe8 != 0) {
            v = (f32)p->pe8->u4 - lbl_803496AC;
        } else {
            v = lbl_80349698;
        }
        p->f18c = v;
        p->f190 = lbl_80349698;
        p->u198 = 1;
    }
}

void fn_800E0540(Ent_800E0540* p) {
    f32 f31;

    if (p != 0) {
        f31 = lbl_803496AC;
        if (fn_801C6068(p, 10) != 0) {
            f31 = fn_801C5D04(p, 9);
        }
        p->f190 = f31;
        p->u198 = 0;
    }
}

void fn_800E05AC(Ent_800E05AC* p) {
    if (p != 0) {
        f32 z = lbl_80349698;
        p->f18c = z;
        p->f190 = z;
        p->u198 = 0;
        if (fn_801C5F40(p, 1) != 0) {
            p->uec = p->p1c8->m1c->u8;
        }
    }
}

void fn_800EDF38(void) {
    lbl_80346E18 = fn_802267AC(lbl_803475A0, fn_800EDB70);
    lbl_80346E18->p24 = fn_801E1C7C(0xdfc);
    memset(lbl_80346E18->p24, 0, 0xdfc);
    lbl_80346E18->f19 = 0;
    lbl_80346E14 = lbl_80346E18->p24;
    lbl_80346E10 = 0;
}

void fn_801000F0(u32 a, u32 b) {
    if (a != 0x7fffffff) {
        lbl_8030A3C8[0] = a;
        fn_800D2C44((u16)a);
    }
    if (b != 0x7fffffff) {
        lbl_8030A3C8[1] = b;
    }
}

s32 fn_8010038C(void) {
    Rec* r = fn_80109404();
    if (r == 0) {
        return 0;
    }
    if (r->u4 == 0) {
        return 0;
    }
    if (r->p8 != 0) {
        fn_80109D74(r->p8);
        r->p8 = 0;
    }
    return 1;
}

void* fn_80100E10(void* a, u32 unused, u32 b, u32 c) {
    void* r;
    r = fn_801C6180(a);
    if (r != 0) {
        fn_80100BF8(r, b, c);
    }
    return r;
}

void fn_801090A8(Obj_801090A8* o) {
    s32 s = o->state;
    switch (s) {
    case 0:
    case 0xfe:
        if (lbl_80347450 != 0) {
            fog_enabled = 1;
            o->state = 1;
        }
        break;
    case 1:
        break;
    case 0xff:
        fn_80100B74(o);
        break;
    }
}

s32 fn_80109388(s32 a, void* b) {
    s32 r;
    if (a == -1 || b == 0) {
        return 0;
    }
    fn_800D2B1C(b);
    r = 1;
    if (fn_801096FC(0, a, b, 0) == 0) {
        r = 0;
    }
    return r;
}

Rec* fn_80109404(u32 a) {
    u8 buf[0x20];
    Node_801094C8* n;

    fn_801CC434((void*)a, 0, buf);
    n = lbl_80347460;
    while (n != 0) {
        if (fn_801E1098(buf, (u8*)n + 0xc) == 0) {
            return (Rec*)n;
        }
        n = n->next;
    }
    return 0;
}

s32 fn_80109468(u32 key, Set_80109468* s, Out_80109468* out) {
    Ent_80109468* e;
    s32 n;

    if (s == 0) {
        return 0;
    }
    e = s->ent;
    n = s->count;
    do {
        if (e->key == key) {
            out->s = s;
            out->e = e;
            out->v = e->v38;
            return 1;
        }
        e = (Ent_80109468*)((u8*)e + 0x68);
    } while (--n != 0);
    out->s = 0;
    out->e = 0;
    out->v = 0;
    return 0;
}

u32 fn_801094C8(u32 key) {
    Node_801094C8* n;
    u32 r = 0;
    Out_80109468 out;

    n = lbl_80347460;
    while (n != 0) {
        if (fn_80109468(key, n->data, &out) == 1) {
            r = out.v;
            break;
        }
        n = n->next;
    }
    return r;
}

s32 fn_8010AB60(Ctx_8010AB60* c, Src_8010AB60* src) {
    c->dst->f18c = src->f18c;
    c->dst->f190 = src->f190;
    c->dst->ue8 = src->ue8;
    c->dst->f24c = src->f38;
    c->dst->f250 = src->f3c;
    c->dst->f254 = src->f40;
    c->dst->u20c = src->u44;
    c->dst->u210 = src->u48;
    c->dst->u214 = src->u4c;
    return 0;
}

void* fn_8010CEF8(void) {
    Tp* r31;
    void* r30;

    lbl_80346E60 = 0;
    r30 = fn_801E1C7C(0xb8);
    if (r30 != 0) {
        r31 = fn_802267AC(lbl_80347590, fn_8010D4F4);
        if (r31 != 0) {
            r31->p24 = r30;
            lbl_80346E64 = 0;
        } else {
            fn_801E17E0(r30);
        }
    }
    fn_802260E8(r31);
    return r31;
}

void fn_8010DE84(Obj_8010DE84* o) {
    if (o->st == 0) {
        Sub* p = o->p24;
        p->s170 = 0;
        p->s172 = 0;
        if (p->p100 != 0) {
            fn_80227810(p->p100);
        }
        o->st = 2;
    } else {
        fn_8010DDBC(o);
    }
}
