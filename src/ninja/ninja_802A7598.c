/* Sega Ninja library, 0x802A7598-0x802A7680. Renderer 2 light setters (the twin of
 * ninja_802A20DC.c); fn_802A75C8 owns the lone 1048576.0f at 0x8034D3E8. */

#include "ninja_lib.h"

void fn_802A7598(f32 a, f32 b, f32 c) {
    lbl_80300794.f18[0] = a;
    lbl_80300794.f18[1] = b;
    lbl_80300794.f18[2] = c;
}

void fn_802A75B0(f32 a, f32 b) {
    lbl_80300794.f0c = -a;
    lbl_80300794.f10 = b;
}

void fn_802A75C8(f32 x, f32 y, f32 z) {
    f64 a = x, b = y, c = z;
    lbl_80300794.dir[0] = x;
    lbl_80300794.dir[1] = y;
    lbl_80300794.dir[2] = z;
    GXInitLightPos(&lbl_803465E0, 1048576.0f * -(f32)a, 1048576.0f * -(f32)b, 1048576.0f * -(f32)c);
    GXInitSpecularDir(&lbl_803465A0, x, y, z);
}
