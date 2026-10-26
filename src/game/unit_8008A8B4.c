#include "types.h"

typedef struct Chr {
    u8 pad0[0x10];
    u32 x10;
} Chr;
extern Chr* lbl_80309DE4[12];
typedef struct Rec_8008AAD8 {
    u8 pad0[0x24];
    s16 x24;
    s16 x26;
} Rec_8008AAD8;
extern u8 lbl_8030B7F4[0x16A0];
typedef struct Rec_8008AEAC {
    u8 pad0[0x80];
    s16 x80;
} Rec_8008AEAC;
typedef struct Rec_8008AEDC {
    u8 pad0[0x80];
    s16 x80;
} Rec_8008AEDC;
extern u8 lbl_80347340;

s32 fn_8008A8B4(s32 i)
{
    Chr* e = lbl_80309DE4[i];
    if (e->x10 & 0x100) {
        e->x10 &= ~0x100;
        return 1;
    }
    return 0;
}

s32 fn_8008AAC8(s32 unused, s16* p)
{
    return *p == 0;
}

s32 fn_8008AAD8(s32 unused, Rec_8008AAD8* p)
{
    if (p->x24 == 1) {
        return 1;
    }
    return p->x26 == 1;
}

s32 fn_8008AD6C(s32 i)
{
    Chr* e = lbl_80309DE4[i];
    if (e->x10 & 0x2000) {
        e->x10 &= ~0x2000;
        return 1;
    }
    return 0;
}

s32 fn_8008AE08(s32 i)
{
    return (lbl_80309DE4[i]->x10 & 0x8000) != 0;
}

s32 fn_8008AE24(s32 i)
{
    return (lbl_80309DE4[i]->x10 & 0x4000) != 0;
}

s32 fn_8008AE74(s32 i)
{
    return (lbl_80309DE4[i]->x10 & 0x1000) != 0;
}

s32 fn_8008AE90(s32 i)
{
    return (lbl_80309DE4[i]->x10 & 0x800) != 0;
}

s32 fn_8008AEAC(s32 unused, Rec_8008AEAC* p)
{
    s32 t = (s8)lbl_8030B7F4[0xB] - p->x80;
    return !(t < 8);
}

s32 fn_8008AEDC(s32 unused, Rec_8008AEDC* p)
{
    s32 t = (s8)lbl_8030B7F4[0xB] - p->x80;
    return !(t < 4);
}

s32 fn_8008AF0C(s32 i)
{
    return (lbl_80309DE4[i]->x10 & 0x400) != 0;
}

s32 fn_8008AF28(s32 i)
{
    return (lbl_80309DE4[i]->x10 & 0x200) != 0;
}

s32 fn_8008B0AC(void)
{
    return (s8)lbl_80347340 >= 5;
}

s32 fn_8008B0CC(s32 i)
{
    return (lbl_80309DE4[i]->x10 & 0x80) != 0;
}

s32 fn_8008B0E8(s32 i)
{
    return (lbl_80309DE4[i]->x10 & 0x40) != 0;
}

s32 fn_8008B104(s32 i)
{
    return (lbl_80309DE4[i]->x10 & 0x20) != 0;
}

s32 fn_8008B120(s32 i)
{
    return (lbl_80309DE4[i]->x10 & 0x10) != 0;
}

s32 fn_8008B13C(s32 i)
{
    return (lbl_80309DE4[i]->x10 & 0x8) != 0;
}

s32 fn_8008B158(s32 i)
{
    return (lbl_80309DE4[i]->x10 & 0x4) != 0;
}
