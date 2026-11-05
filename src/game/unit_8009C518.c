#include "game/unit_8009C518.h"

void fn_8009D190(s32 key)
{
    s32 i;
    s32 zero;

    i = fn_8009014C(lbl_803033E0, &key, 6, 4);
    if (i == -1 || lbl_803033B0[i] == 0) {
        zero = 0;
        i = fn_8009014C(lbl_803033B0, &zero, 6, 4);
        if (i == -1) {
            fn_801DBE1C(lbl_802B0E14);
        }
        lbl_803033E0[i] = key;
        lbl_803033C8[i] = 1;
    } else {
        lbl_803033C8[i]++;
    }
    lbl_803033B0[i] = 50;
}

/* state */


void fn_8009CFD8(void) {
    s32 i;
    s32 y = 0x104;
    for (i = 0; i < 6; y -= 0x23, i++) {
        s32 n = lbl_803033B0[i];
        if (n > 0) {
            s32 s = lbl_803033F8[i];
            switch (s) {
            case 0:
            case 1:
            case 2: {
                f32 f = 0.5f * (s + 1);
                fn_800CAC04(lbl_803033E0[i], (s + 1) * 50, lbl_803033C8[i], 0xff, y, f, f);
                lbl_803033F8[i]++;
                break;
            }
            case 3: {
                s32 a, b;
                f32 sx, sy;
                if (n > 45) {
                    a = (n - 45) * 50;
                } else {
                    a = 0;
                }
                if (n >= 5) {
                    b = 0xff;
                    sx = 1.5f;
                    sy = 0.022222223f * (n - 5) + 1.5f;
                } else {
                    b = n * 50;
                    sy = 0.3f * n;
                    sx = sy;
                }
                fn_800CAC04(lbl_803033E0[i], b, lbl_803033C8[i], a, y, sx, sy);
                lbl_803033B0[i]--;
                if (lbl_803033B0[i] == 0) {
                    lbl_803033F8[i] = 0;
                }
                break;
            }
            }
        }
    }
}

void fn_8009CBBC(void) {
    Tab_8009CBBC* t = &lbl_802E0E18;
    u32 id = fn_80218DC4();
    s32 i;
    f32* ta;
    f32* tb;
    f32* tc;
    f32* td;
    f32* te;
    f32* tf;
    f32 dx;
    f32 dz;
    f32 v;
    if (id != 0xFFFFFFFF && !(lbl_80310B3C.flags & 0x40000)) {
        ta = t->a;
        tb = t->b;
        tc = t->c;
        td = t->d;
        te = t->e;
        tf = t->f;
        for (i = 0; i < 6; i++) {
            dx = Abs(lbl_80347450->x - ta[i]);
            dz = Abs(lbl_80347450->z - tb[i]);
            dx = Fold(dx, 16800.0f);
            dz = Fold(dz, 14400.0f);
            if (dx > tc[i] || dz > td[i]) {
                v = 0.0f;
            } else if (dx < te[i]) {
                if (dz < tf[i]) {
                    v = 1.0f;
                } else {
                    v = 1.0f - (dz - tf[i]) / tf[i];
                }
            } else if (dz < tf[i]) {
                v = 1.0f - (dx - te[i]) / te[i];
            } else {
                f32 p = (dx - te[i]) / te[i];
                f32 q = (dz - tf[i]) / tf[i];
                v = 1.0f - ((p > q) ? p : q);
            }
            sndSeqSetMidiCtrl(id, i + 10, 7, (s32)(127.0f * v));
        }
    }
}


void fn_8009CBB8(void) {
}

s32 lbl_803033F8[6];
s32 lbl_803033E0[6];
s32 lbl_803033C8[6];
s32 lbl_803033B0[6];
