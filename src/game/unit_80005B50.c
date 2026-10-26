#include "types.h"

#define PTR(p, off) (*(void**)((u8*)(p) + (off)))

extern void* fn_80005B9C(void* heap);
extern void* memset(void* dst, s32 c, u32 n);
extern void fn_800090F8(s32 packed, s16* p);

extern void* lbl_803475A8;
extern void* lbl_80346AA4;
extern void* fn_802268E8(void* a, void (*cb)(void*));
extern void* fn_801E1C7C(u32 size);
extern void fn_8000A3FC(void* p);

extern u32 lbl_803474E4[2];
extern void* lbl_80346AA0;
extern void fn_801DDCA8(void* p);
extern void fn_802275A4(void* a, s32 b);
extern void fn_801E17E0(void* p);
extern void* fn_801DB1A4(u32 size);
extern void fn_80227810(void* p);
extern void fn_801DDD74(void* p, s32 n);

typedef struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Vec3;
extern f32 fn_80291A5C(f32 v);
extern u32 lbl_80309E5C[];

extern void* lbl_80347394;
extern void* lbl_80309DE4[];
extern s32 fn_8000F718(void* p, s32 a, s32 b);
extern void fn_8000F6F8(void* obj, s32 a, s32 b, s32 c, s32 d);

typedef struct Entry16 {
    u8 pad[8];
    s8 mode;
    u8 pad2[7];
} Entry16;
extern Entry16 lbl_80309730[];

extern s32 lbl_8034733C;

typedef struct Pair {
    u32 a;
    u32 b;
} Pair;

extern void* lbl_80309E24[];

void* fn_80005B50(void* heap, u32 size) {
    void* p = fn_80005B9C(heap);
    if (p != 0) {
        memset(p, 0, size);
    }
    return p;
}

void fn_800091A4(s16* p) {
    s16 x = p[0];
    s16 y = p[1];
    if (x >= 0) {
        fn_800090F8((y << 16) | x, p);
    }
}

void fn_8000A3A4(void* obj) {
    lbl_80346AA4 = fn_802268E8(lbl_803475A8, fn_8000A3FC);
    PTR(lbl_80346AA4, 0x24) = fn_801E1C7C(12);
    *(void**)PTR(lbl_80346AA4, 0x24) = obj;
}

void fn_8000AA08(void) {
    fn_801DDCA8(lbl_803474E4);
    if (lbl_80346AA0 != 0) {
        fn_802275A4(PTR(PTR(lbl_80346AA0, 4), 0x20), 1);
        fn_801E17E0(lbl_80346AA0);
        lbl_80346AA0 = 0;
    }
}

void fn_8000AA58(void) {
    lbl_80346AA0 = fn_801DB1A4(4);
    fn_80227810(PTR(PTR(lbl_80346AA0, 4), 0x20));
    fn_801DDD74(lbl_803474E4, 1);
}

f32 fn_8000ACF0(Vec3* v) {
    return fn_80291A5C(v->z * v->z + (v->x * v->x + v->y * v->y));
}

void fn_8000CC84(s32 flag) {
    if (flag == 1) {
        lbl_80309E5C[2] |= 0x01000000;
    } else {
        lbl_80309E5C[2] &= ~0x01000000;
    }
}

s32 fn_8000F86C(s32 idx) {
    void* p = lbl_80347394;
    if (p != 0) {
        return (s8)*(s16*)((u8*)PTR(p, 0x24) + 0x5c);
    }
    return *(u8*)((u8*)lbl_80309DE4[(s8)idx] + 0x100);
}

void fn_8000F8A4(void* obj, void* x) {
    s32 v = fn_8000F718(x, 0, 0);
    fn_8000F6F8(obj, 0x40, v, -1, 0);
}

void fn_80010538(s16 idx) {
    s32 mode = lbl_80309730[idx].mode;
    void* q;
    if (mode == 0) {
        return;
    }
    if (mode == 4) {
        return;
    }
    q = lbl_80309DE4[idx];
    *(s16*)((u8*)q + 0xb4) += *(s16*)((u8*)q + 8);
}

s32 fn_80014CC0(void* obj) {
    u8* p = PTR(PTR(obj, 0x24), 0x4c);
    s16 id = *(s16*)(p + 6);
    switch (id) {
    case 0x1a:
    case 0x1b:
    case 0x1c:
        if (lbl_8034733C == 7) {
            return 1;
        }
        break;
    }
    return 0;
}

s32 fn_800153A0(Pair* p) {
    if (p == 0) {
        return 0;
    }
    if (p->a == 0) {
        return 0;
    }
    return p->b > 1;
}

s32 fn_80015828(const char* s) {
    if (s[0] == 'M' || s[0] == 'm') {
        if (s[1] == 'A' || s[1] == 'a') {
            if (s[3] == '1' || s[3] == '2') {
                return 1;
            }
        }
    }
    return 0;
}

void fn_80017778(void) {
    s8 i;
    for (i = 0; i < 14; i++) {
        void* obj = lbl_80309E24[i];
        if (obj != 0) {
            u8* p = PTR(PTR(obj, 0x24), 0x4c);
            *(u32*)(p + 0xf0) &= ~0x00400000;
        }
    }
}

s32 fn_8001BBF8(void* obj) {
    u8* p = PTR(PTR(obj, 0x24), 0x4c);
    s16 id = *(s16*)(p + 0x10);
    switch (id) {
    case 0x10:
    case 0x17:
    case 0x1d:
        return 0;
    default:
        return 1;
    }
}

s32 fn_8001EB6C(void* obj) {
    s16 type = *(s16*)((u8*)obj + 6);
    switch (type) {
    case 4:
    case 5:
    case 8:
    case 15:
    case 24:
        return 1;
    default:
        return 0;
    }
}
