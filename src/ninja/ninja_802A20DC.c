/* Sega Ninja library, 0x802A20DC-0x802A21C4. Light setters; fn_802A210C owns the lone 1048576.0f
 * at 0x8034D380. */

#include "ninja_lib.h"

void fn_802A20DC(f32 a, f32 b, f32 c) {
    lbl_80300760.f18[0] = a;
    lbl_80300760.f18[1] = b;
    lbl_80300760.f18[2] = c;
}

void fn_802A20F4(f32 a, f32 b) {
    lbl_80300760.f0c = -a;
    lbl_80300760.f10 = b;
}

void fn_802A210C(f32 x, f32 y, f32 z) {
    f64 dx = x, dy = y, dz = z;
    lbl_80300760.dir[0] = x;
    lbl_80300760.dir[1] = y;
    lbl_80300760.dir[2] = z;
    GXInitLightPos(&lbl_80346560, 1048576.0f * -(f32)dx, 1048576.0f * -(f32)dy, 1048576.0f * -(f32)dz);
    GXInitSpecularDir(&lbl_80346520, x, y, z);
}
