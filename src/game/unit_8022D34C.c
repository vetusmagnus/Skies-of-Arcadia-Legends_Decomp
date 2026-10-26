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

extern void fn_8022E964(void*, void*);
extern char lbl_8034C750;
void fn_8022E8F8(void* p, void* arg) {
    if (!(*(u32*)p & 0x80000000)) {
        if (strncmp((const char*)p, &lbl_8034C750, 4) == 0) {
            p = (u8*)p + 8;
        } else {
            return;
        }
    }
    fn_8022E964(p, arg);
}

void fn_8022F00C(void *p) {
    fn_8022F64C(p, 0x4000);
}

extern void fn_801F01E4(void);
extern void fn_801D6850(void);
typedef struct Msg {
    s16 x0;
    s16 x2;
    s16 x4;
    s16 x6;
    s32 x8;
    s32 xc;
} Msg;
extern void fn_8022F050(Msg*, s16);
void fn_8022F030(Msg* a, s16 i) {
    fn_8022F050(a, i);
}

extern void fn_8023080C(Msg*, s16);
void fn_802307EC(Msg* a, s16 i) {
    fn_8023080C(a, i);
}

extern void fn_801D6890(Msg*, s16);
void fn_80230F24(void) {
}

void fn_80230F28(Msg* a, s16 i) {
    fn_801D6890(a, i);
}

void fn_80230F48(void) {
    fn_801F01E4();
    fn_801D6850();
}
