#include "game/unit_80055E94.h"

extern void fn_8021A1C4(s8 *buf);
extern Node *fn_80074E2C(char *, char *, void *, int, int);
typedef struct MdlObj { u8 id; u8 pad1[0x164 - 1]; f32 x164; } MdlObj;
typedef struct MdlCtl { u8 pad[0x4c]; MdlObj *obj; } MdlCtl;
extern s32 fn_800154BC(Task *t);

typedef struct Snd { u8 pad_00[7]; s8 x7; u8 pad_08[0x20]; s32 x28; s32 x2c; } Snd;
extern void fn_80218D84(void *dst, u32 src, u32 size);


void fn_80073D14(void) {
}

void fn_80073D10(void) {
}

void fn_80073D0C(void) {
}

void fn_80073C44(CamObj *arg, s8 mode) {
    s8 i;
    for (i = 0; i < 12; i++) {
        if (lbl_80309E24[i] != NULL && fn_800154BC(lbl_80309E24[i]) == 0) {
            MdlCtl *c = lbl_80309E24[i]->work;
            MdlObj *w = c->obj;
            switch (mode) {
            case 0:
                if (fn_8001D944(w->id, arg) == 0) {
                    w->x164 = 0.0f;
                }
                break;
            case 1:
                if (fn_8001D944(w->id, arg) != 0) {
                    w->x164 = 0.0f;
                }
                break;
            }
        }
    }
}

void fn_80073B48(s8 *out) {
    s8 pat[] = { 0, 4, 5, 6, 10, 11, 14, 16, 18, 17, 21, 1, 2, 3, 7, 8, 9, 12, 13, 15, 19, 20, -1 };
    s8 buf[0x20];
    s32 i = 0;
    s8 *b;
    s8 *p;
    s8 j;
    s8 n = 0;
    fn_8021A1C4(buf);
    for (p = pat; *p >= 0; p++, i++) {
        b = buf;
        for (j = 0; j < 0x16; b++, j++) {
            if (*b < 0) break;
            if (*b == *p) {
                out[n++] = i;
            }
        }
    }
    out[n] = -1;
}

void fn_80073024(Ent6EB88* out, s8* p, s8 c) {
    char buf[0x18];
    out->f0 = -1;
    switch (c) {
    case 0:
        while (*p >= 0) {
            sprintf(buf, "CR%03d.MLD", *p + 1);
            fn_8006E75C(out, buf, 0);
            sprintf(buf, "CR%03d.STD", *p + 1);
            fn_8006E75C(out, buf, 0);
            sprintf(buf, "CR%03d0.STD", *p + 1);
            fn_8006E75C(out, buf, 0);
            sprintf(buf, "CR%03d.MLK", *p + 1);
            fn_8006E75C(out, buf, 0);
            break;
        }
        break;
    default:
        sprintf(buf, "CREN%2d.MLK", c + 0x1d);
        fn_8006E75C(out, buf, 0);
        break;
    }
    fn_8006DC6C();
}

void fn_80072F10(Snd *s) {
    if (lbl_8030A10C.x7c != 0) {
        if (s->x28 != 0) {
            fn_80217830(s->x28);
        }
        fn_80218D84(lbl_8030A10C.x84, lbl_8030A10C.x7c, (lbl_8030A10C.x74 + 0x1f) & ~0x1f);
        s->x28 = SePlay(3, 3, 0);
        lbl_8030A10C.x7c = 0;
        lbl_8030A10C.x74 = 0;
    }
    if (lbl_8030A10C.x80 != 0) {
        if (s->x2c != 0) {
            fn_80217830(s->x2c);
        }
        if (s->x7 != 0) {
            fn_80218D84(lbl_8030A10C.xa4, lbl_8030A10C.x80, (lbl_8030A10C.x78 + 0x1f) & ~0x1f);
        }
        s->x2c = SePlay(3, 7, 0);
        lbl_8030A10C.x80 = 0;
        lbl_8030A10C.x78 = 0;
    }
}

void fn_80072E8C(s16 k, s16 b, s16 c, char *d) {
    switch (k) {
    case 0x18:
    case 0x19:
    case 0x1d:
    case 0x1e:
        sprintf(d, "E67%03d%02d.MLD", b, k);
        break;
    default:
        sprintf(d, "E67%03d%02d.MLD", c, k);
        break;
    }
}

s32 fn_80072DD4(s16 a, s16 b, s16 c, void *d)
{
    char buf2[0x20];
    char buf1[0x20];

    switch (a) {
    case 0x18:
    case 0x19:
    case 0x1d:
    case 0x1e:
        sprintf(buf2, "E67%03d%02d.MLD", b, a);
        break;
    default:
        sprintf(buf2, "E67%03d%02d.MLD", c, a);
        break;
    }
    fn_8006C8DC(buf1, buf2);
    fn_80074E2C(buf1, buf2, d, 0, 1);
    return 1;
}
