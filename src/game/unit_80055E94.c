#include "types.h"

extern u8 lbl_8030A10C[];
void fn_800D208C(void *obj, f32 f);
extern u8 *lbl_80309700[];
void fn_8006AFD0(s16 a, s16 b, s32 c, s32 d);
extern u8 *lbl_80309DE4[];
typedef struct {
    void *f0;
    void *f4;
    u32 f8;
    u8 fc;
    u8 pad[3];
} TblEnt;
extern TblEnt lbl_80309E88[4];
extern s32 *lbl_80347398;
typedef struct {
    u8 pad0[0x14];
    u32 *p14;
    u8 rest[0x68 - 0x18];
} Elem;
void fn_8006E924(void);

void fn_80055E94(u8 *p) {
    p[0x18] |= 0x40;
    *(s32 *)(lbl_8030A10C + 0x1c4) -= 1;
}

void fn_80056FA4(f32 *out, s16 flag) {
    if (flag) {
        *out = -1.0f;
    } else {
        *out = 0.0f;
    }
}

void fn_80060950(u8 *p) {
    fn_800D208C(*(void **)(p + 0x34), *(f32 *)(p + 0x38));
}

void fn_80061014(f32 *a, f32 *b, f32 *out) {
    out[0] = b[0] - a[0];
    out[1] = b[1] - a[1];
    out[2] = b[2] - a[2];
}

void fn_800614FC(u32 *src, u32 *dst) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

void fn_80061F3C(f32 *src, f32 *dst) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

void fn_800688C4(void *a, s16 idx, void *b, s8 v) {
    u8 *p = lbl_80309700[idx];
    *(s16 *)(*(u8 **)(p + 0x24) + 0x44) = v;
}

void fn_80069684(s16 a, s16 b, s32 c) {
    fn_8006AFD0(a, b, c, 0);
}

void fn_8006B3C4(void *a, s16 idx) {
    u8 *p = lbl_80309DE4[idx];
    *(u32 *)(p + 0x1c) |= 1;
}

void fn_8006B3E8(void) {
}

s32 fn_8006B670(s16 idx) {
    if (idx >= 4) {
        return 0;
    }
    return lbl_80309E88[idx].fc == 0;
}

void fn_8006B6A4(s16 idx, u32 v) {
    if (idx < 4) {
        lbl_80309E88[idx].f8 = v;
    }
}

u32 fn_8006B6C8(s16 idx) {
    if (idx >= 4) {
        return 0;
    }
    return lbl_80309E88[idx].f8;
}

void *fn_8006B6F4(s16 idx) {
    if (idx >= 4) {
        return 0;
    }
    return lbl_80309E88[idx].f0;
}

void fn_8006C5A4(void) {
    *lbl_80347398 = -1;
}

s32 fn_8006C8C4(void) {
    return *(u32 *)(lbl_8030A10C + 0x68) == 0;
}

void fn_8006CF28(u8 *a, u32 *out, s32 idx) {
    Elem *arr = *(Elem **)(a + 4);
    u32 *p3 = *(u32 **)((u8 *)arr + 0x14);
    u32 *p;

    if (*p3 == 0) {
        return;
    }
    p = arr[idx].p14;
    *out = p[1];
}

void fn_8006EA70(void) {
    fn_8006E924();
}

void fn_80071CBC(f32 *a, f32 *b) {
    b[0] = b[0] + a[0];
    b[1] = b[1] + a[1];
    b[2] = b[2] + a[2];
}
