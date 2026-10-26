#include "types.h"

typedef struct {
    u8 pad[0x4c];
    s32 a;
    f32 b;
    f32 c;
} Unk8022D34C;
extern Unk8022D34C lbl_80311970;
extern f32 lbl_80347570;
extern void fn_8022F64C(void *p, u32 flags);

void fn_8022D34C(s32 a, f32 b) {
    if (a > 0) {
        lbl_80311970.a = a;
        lbl_80311970.b = lbl_80347570;
        lbl_80311970.c = b;
    } else {
        lbl_80311970.a = -1;
    }
}

void fn_8022F00C(void *p) {
    fn_8022F64C(p, 0x4000);
}
