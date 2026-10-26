#include "types.h"

void fn_801EFC88(s32 v);
typedef struct CmdStream { u8 pad_00[0x1c]; u8 *cur; } CmdStream;
void fn_800B0900(void *p);
void fn_800FF9FC(void *p);
extern u8 lbl_8030B4D4[];
extern u8 lbl_8030B7F4[];
void fn_801003F4(void *p);
void fn_800D2CA8(s32 a);
extern u8 lbl_8030CEA0[];
void fn_80210CE4(void *p);
void fn_801F7500(void);
void fn_800976EC(u32 a);
void *fn_80217FF4(s8 id);
void fn_80142C78(void *p);
void fn_80147DCC(void *p);
s32 fn_80219B7C(void);
s32 fn_801D168C(void);
void fn_801D150C(s32 v);
void fn_802173F4(void *obj, s32 v, s32 w);
void fn_802193BC(void);
typedef struct Slot { u8 pad_00[0x10]; s32 field_10; u8 rest[0x28]; } Slot;
extern Slot lbl_80315120[];
s32 fn_80219834(s32 v);
void fn_801F452C(s32 arg);
typedef struct Cursor {
    u8 pad0[4];
    u32 f4;
    u8 pad8[0x14];
    u32 *cur;
} Cursor;
extern s32 lbl_8034757C;
s32 fn_801D6E38(s32 arg);
s32 SePlay(s32 bank, s8 arg1, s8 id);
extern s32 lbl_803477DC;
void fn_80217830(s32 arg);
extern s32 lbl_803477E0;

void fn_801F5334(s8 n) {
    s32 i;
    for (i = 0; i < n; i++) {
        fn_801EFC88(0x102);
    }
}

s32 fn_801F5CCC(s32 unused, CmdStream *st) {
    u8 *p = st->cur;
    u32 v;
    p += 4;
    v = *(u32 *)p;
    if (v > 0x10000 && v < 0xffff0000) {
        v = (v >> 24) | ((v >> 8) & 0xff00) | ((v << 8) & 0xff0000) | (v << 24);
        *(u32 *)p = v;
    }
    p += *(u32 *)p & ~3u;
    st->cur = p;
    return 0;
}

s32 fn_801F7CD8(u32 a, CmdStream *st) {
    u16 f = a;
    if (a & 1) {
        u8 *c = st->cur;
        st->cur = c + 4;
        fn_800B0900(c);
    }
    if (f & 8) return 1;
    return 0;
}

s32 fn_801FD54C(u32 a, CmdStream *st) {
    if (a & 1) {
        u8 *c = st->cur;
        st->cur = c + 4;
        fn_800FF9FC(c);
    }
    return 0;
}

s32 fn_801FDA70(u32 a, CmdStream *st) {
    u16 f = a;
    if (a & 1) {
        st->cur += 4;
        *(u32 *)(lbl_8030B7F4 + 0x157c) = *(u32 *)(lbl_8030B4D4 + 0x2dc);
    }
    if (f & 8) return 1;
    return 0;
}

s32 fn_801FF0F8(u32 a, CmdStream *st) {
    if (a & 1) {
        u8 *c = st->cur;
        u8 *q = c + 4;
        u32 off = *(u32 *)(c + 4);
        st->cur = q + 4;
        fn_801003F4(q + off);
    }
    return 0;
}

s32 fn_80200F88(u32 a, CmdStream *st) {
    if (a & 1) {
        u8 *c = st->cur;
        st->cur = c + 4;
        fn_800D2CA8(0);
    }
    return 0;
}

s32 fn_8020731C(u32 a, CmdStream *st) {
    if (a & 1) {
        u8 *c = st->cur;
        st->cur = c + 4;
        fn_80210CE4(c);
        fn_801F7500();
        *(s32 *)(lbl_8030CEA0 + 0x15cc) = 0;
    }
    return 0;
}

s32 fn_80207368(u32 a, CmdStream *st) {
    if (a & 1) {
        u8 *c = st->cur;
        fn_800976EC(a);
        st->cur = c + 4;
    }
    return 0;
}

void fn_8020EEE8(s8 id) {
    void *r = fn_80217FF4(id);
    if (r) {
        *(void **)(lbl_8030CEA0 + 0x157c) = r;
    } else {
        *(void **)(lbl_8030CEA0 + 0x157c) = 0;
    }
}

s32 fn_802138A0(u32 a, CmdStream *st) {
    if (a & 1) {
        u8 *c = st->cur;
        st->cur = c + 4;
        fn_80142C78(c);
        return 0;
    }
    return 1;
}

s32 fn_80214908(u32 a, CmdStream *st) {
    if (a & 1) {
        u8 *c = st->cur;
        u8 *q = c + 4;
        u32 off = *(u32 *)(c + 4);
        st->cur = q + 4;
        fn_80147DCC(q + off);
        return 0;
    }
    return 1;
}

void fn_80216CD8(void) {
    while (fn_80219B7C() != 0) {
        s32 r = fn_801D168C();
        if (r != -1) {
            fn_801D150C(r);
        }
    }
}

void fn_802172C8(void *obj, s8 a) {
    if (obj != 0) {
        s32 x = a;
        a = -0x7e;
        if (x > -0x7f) {
            a = x;
        }
        fn_802173F4(obj, a, 0);
    }
}

void fn_80218D84(void) {
    fn_802193BC();
    while (fn_80219B7C() != 0) {
        s32 r = fn_801D168C();
        if (r != -1) {
            fn_801D150C(r);
        }
    }
}

void fn_80219324(s32 i) {
    if (lbl_80315120[i].field_10 >= 0) {
        s32 r;
        do {
            r = fn_80219834(1);
        } while (i != r);
    }
}

void fn_801F5380(void) {
    fn_801F452C(0x102);
}

s32 fn_801F5BB4(s32 unused, Cursor *c) {
    u32 *p = c->cur;
    c->f4 = 0;
    c->cur = p + 1;
    return 0;
}

s32 fn_801F60C4(s32 unused, Cursor *c) {
    u32 *p = c->cur + 1;
    while (*p != 0x1d) {
        p++;
    }
    c->cur = p + 1;
    return 0;
}

s32 fn_801FED3C(s32 flag, Cursor *c) {
    if (flag & 1) {
        c->cur = c->cur + 1;
    }
    return 0;
}

s32 fn_80212050(void) {
    return fn_801D6E38(lbl_8034757C) != 0 ? lbl_8034757C : -1;
}

void fn_80216F1C(s8 a, s8 b) {
    SePlay(0xf, a, b);
}

void fn_80217800(s32 v) {
    if (v == lbl_803477DC) {
        fn_80217830(1);
    }
}

s32 fn_80217FD4(s32 bank, s8 arg1, s8 id) {
    return SePlay(bank, arg1, id);
}

s32 fn_80218DC4(void) {
    if (lbl_803477DC != 2) {
        return -1;
    }
    return lbl_803477E0;
}
