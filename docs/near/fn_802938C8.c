#include "ninja_lib.h"

static inline u32 search16(void* table, u32 stride, u32 count, u16 key) {
    u32 lo = 0;
    u32 hi = count;
    u32 mid;
    while (hi - lo > 1) {
        mid = (lo + hi) >> 1;
        if (key >= *(u16*)((u8*)table + mid * stride)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    return lo;
}

void fn_802938C8(void* table, s32 stride, s32 count, f32 t, s16** lo, s16** hi, f32* frac) {
    u32 l;
    s16* a;
    s16* b;
    s16 d;
    u16 fa;
    l = search16(table, stride, count, t);
    a = (s16*)((u8*)table + l * stride);
    if (l < count - 1) {
        b = (s16*)((u8*)table + (l + 1) * stride);
    } else {
        b = table;
    }
    *lo = a;
    *hi = b;
    fa = *(u16*)a;
    d = (s16)*(u16*)b - (s16)fa;
    if (d > 0) {
        *frac = (t - fa) / d;
    } else {
        *frac = t - fa;
    }
}
