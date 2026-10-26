#include "types.h"

typedef struct SysA { u8 x0; u8 x1; u8 pad2[0xe]; u32 x10; s32 x14; s32 x18; } SysA;
typedef struct HolderA { u8 pad[0x24]; SysA* x24; } HolderA;
extern HolderA* lbl_80346F10;
typedef struct SysB { u8 pad0; s8 x1; u8 x2; u8 x3; u8 x4; u8 pad5; u8 x6; } SysB;
typedef struct HolderB { u8 pad[0x24]; SysB* x24; } HolderB;
extern HolderB* lbl_80346F20;
typedef struct SysC { u8 pad0[4]; u16 x4; u8 x6; u8 x7; u8 x8; u8 x9; u8 pad1[0x30 - 0xa]; u8 x30; u8 x31; u8 x32; } SysC;
typedef struct HolderC { u8 pad[0x24]; SysC* x24; } HolderC;
extern HolderC* lbl_80346F28;
typedef struct SysD { u8 pad0[4]; void* x4; } SysD;
typedef struct HolderD { u8 pad[0x24]; SysD* x24; } HolderD;
extern HolderD* lbl_80346F30;

s32 fn_8012ADB4(void) { return lbl_80346F10->x24->x14; }

void fn_8012ADC4(void) {
    lbl_80346F10->x24->x14 = 1;
    lbl_80346F10->x24->x18 = 0;
}

void fn_8012AEA8(u32 v) { lbl_80346F10->x24->x10 = v; }

void fn_8012AEB8(u8 v) {
    if (lbl_80346F10 == 0) return;
    lbl_80346F10->x24->x1 = v;
}

void fn_8012AED0(u8 v) {
    if (lbl_80346F10 == 0) return;
    lbl_80346F10->x24->x0 = v;
}

void fn_8012C454(u8 v) { lbl_80346F20->x24->x3 = v; }

void fn_8012C464(u8 v) { lbl_80346F20->x24->x2 = v; }

s32 fn_8012C5DC(void) {
    s8 v = lbl_80346F20->x24->x1;
    return v != 0;
}

void fn_8012C5FC(u8 v) {
    if (lbl_80346F20 == 0) return;
    lbl_80346F20->x24->x6 = v;
}

void fn_8012C614(s8 c) {
    if (lbl_80346F20 == 0) return;
    if (c == 9) {
        if (lbl_80346F20->x24->x1 != 8) return;
    }
    lbl_80346F20->x24->x1 = c;
}

void fn_8012E404(u8 v) { lbl_80346F28->x24->x31 = v; }

void fn_8012E414(u8 v) { lbl_80346F28->x24->x32 = v; }

void fn_8012E424(u8 v) { lbl_80346F28->x24->x30 = v; }

void fn_8012E560(u8 v) { lbl_80346F28->x24->x9 = v; }

void fn_8012E570(u8 v) { lbl_80346F28->x24->x8 = v; }

void fn_8012E580(u8 v) { lbl_80346F28->x24->x7 = v; }

void fn_8012E590(u8 v) { lbl_80346F28->x24->x6 = v; }

void fn_8012E5A0(u16 v) { lbl_80346F28->x24->x4 = v; }

void fn_8012F468(void* p) { lbl_80346F30->x24->x4 = p; }
