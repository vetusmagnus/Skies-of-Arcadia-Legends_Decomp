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
extern u32 lbl_80347460;
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
extern void fn_801096FC(s32 a, s32 b, s32 c, s32 d);

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
    fn_801096FC(1, a, b, c);
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
