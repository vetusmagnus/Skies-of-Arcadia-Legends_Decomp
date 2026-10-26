#include "types.h"
#include "ninja.h"
#include "game/task.h"
#include <math.h>
void fn_80217B98();

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
void fn_802193BC();
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

s32 fn_801F58B0(void) {
    return 1;
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

extern void fn_801DBE1C(const char *fmt, ...);
int fn_801F60F0(void) {
    fn_801DBE1C("scptSTUB: code error!");
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

s32 fn_801F95C0(u32 a, CmdStream *st) {
    u16 f = a;
    if (a & 1) {
        u8 *c = st->cur;
        st->cur = c + 4;
        fn_80217CB0(c);
    }
    if (f & 8) return 1;
    return 0;
}

s32 fn_801F9614(u32 a, CmdStream *st) {
    u16 f = a;
    if (a & 1) {
        u8 *c = st->cur;
        st->cur = c + 4;
        fn_80217B98(c);
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

s32 fn_801FEB08(u32 a, CmdStream *st) {
    if (a & 1) {
        u8 *c = st->cur;
        st->cur = c + 4;
        fn_801F3148(c);
    }
    return 0;
}

s32 fn_801FEB40(u32 a, CmdStream *st) {
    if (a & 1) {
        u8 *c = st->cur;
        st->cur = c + 4;
        fn_801F35A0(c);
    }
    return 0;
}

s32 fn_801FED04(u32 a, CmdStream *st) {
    if (a & 1) {
        u8 *c = st->cur;
        st->cur = c + 4;
        fn_800FF7A0(c);
    }
    return 0;
}

s32 fn_801FEDC8(void) {
    return 1;
}

int fn_801FEEE8(void) {
    fn_801DBE1C("scptDELL BG: SYNTAX ERROR!!!");
    return 0;
}

int fn_801FEF18(void) {
    fn_801DBE1C("scptINS BG: SYNTAX ERROR!!!");
    return 0;
}

s32 fn_801FEF48(u32 a, CmdStream *st) {
    if (a & 1) {
        u8 *c = st->cur;
        st->cur = c + 4;
        fn_800FFA18(c);
    }
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

int fn_801FF1E0(void) {
    fn_801DBE1C("scptKill: SYNTAX ERROR!!!");
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

typedef struct ScptArgs {
    s32 kind;
    u8 pad04[0x14];
    s32 owner;
    s32 *args;
    u8 pad20[0x10];
    s32 zero;
} ScptArgs;
extern s16 fn_80207830(s32, ScptArgs *);
extern void fn_80210F74(ScptArgs *);
void fn_80207738(s32 a, s32 b)
{
    ScptArgs s;
    s32 i;

    for (i = 0; i < 256; i++) {
        if (*(s32 *)((u8 *)lbl_8030CEA0 + i * 8 + 0x18) != 0) {
            s32 args[5] = { 0, 0, 0x1D, 0, 0x1D };
            s.args = args;
            args[0] = a;
            args[1] = b + 0x8000000;
            args[3] = i + 0x8000000;
            s.zero = 0;
            s.owner = a;
            if (fn_80207830(1, &s) == 1) {
                s.kind = 1;
                *(s16 *)((u8 *)&s + 0x10) = 0;
                *(s32 *)((u8 *)&s + 8) = 0;
                fn_80210F74(&s);
            }
        }
    }
}

extern s16 fn_80209028(s32, ScptArgs *);
void fn_80208F30(s32 a, s32 b)
{
    ScptArgs s;
    s32 i;

    for (i = 0; i < 256; i++) {
        if (*(s32 *)((u8 *)lbl_8030CEA0 + i * 8 + 0x18) != 0) {
            s32 args[5] = { 0, 0, 0x1D, 0, 0x1D };
            s.args = args;
            args[0] = a;
            args[1] = b + 0x8000000;
            args[3] = i + 0x8000000;
            s.zero = 0;
            s.owner = a;
            if (fn_80209028(1, &s) == 1) {
                s.kind = 1;
                *(s16 *)((u8 *)&s + 0x10) = 0;
                *(s32 *)((u8 *)&s + 8) = 0;
                fn_80210F74(&s);
            }
        }
    }
}

extern s16 fn_80209330(s32, ScptArgs *);
void fn_80209238(s32 a, s32 b)
{
    ScptArgs s;
    s32 i;

    for (i = 0; i < 256; i++) {
        if (*(s32 *)((u8 *)lbl_8030CEA0 + i * 8 + 0x18) != 0) {
            s32 args[5] = { 0, 0, 0x1D, 0, 0x1D };
            s.args = args;
            args[0] = a;
            args[1] = b + 0x8000000;
            args[3] = i + 0x8000000;
            s.zero = 0;
            s.owner = a;
            if (fn_80209330(1, &s) == 1) {
                s.kind = 1;
                *(s16 *)((u8 *)&s + 0x10) = 0;
                *(s32 *)((u8 *)&s + 8) = 0;
                fn_80210F74(&s);
            }
        }
    }
}

s32 fn_8020A72C(void) {
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

s32 fn_802138E0(u32 a, CmdStream *st) {
    if (a & 1) {
        u8 *c = st->cur;
        st->cur = c + 4;
        fn_80142CD8(c);
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

s32 fn_80214954(u32 a, CmdStream *st) {
    if (a & 1) {
        u8 *c = st->cur;
        st->cur = c + 4;
        fn_80147DF8(c);
        return 0;
    }
    return 1;
}

s32 fn_80214994(u32 a, CmdStream *st) {
    if (a & 1) {
        u8 *c = st->cur;
        u8 *q = c + 4;
        u32 off = *(u32 *)(c + 4);
        st->cur = q + 4;
        fn_80147E2C(q + off);
        return 0;
    }
    return 1;
}

s32 fn_802149E0(u32 a, CmdStream *st) {
    if (a & 1) {
        u8 *c = st->cur;
        st->cur = c + 4;
        fn_80148108(c);
        return 0;
    }
    return 1;
}

s32 fn_80214A20(u32 a, CmdStream *st) {
    if (a & 1) {
        u8 *c = st->cur;
        st->cur = c + 4;
        fn_80148124(c);
        return 0;
    }
    return 1;
}

s32 fn_80214A60(u32 a, CmdStream *st) {
    if (a & 1) {
        u8 *c = st->cur;
        st->cur = c + 4;
        fn_80148160(c);
        return 0;
    }
    return 1;
}

typedef struct Cmd { u8 pad_00[0x1c]; float *cur; } Cmd;
float fn_801F6120(float **p);
void fn_8014818C(u16 a, s32 b);
s32 fn_80214B28(u32 flags, Cmd *c) {
    float *p;
    u16 a;
    s32 t;
    s32 b;
    if (flags & 1) {
        p = c->cur;
        p++;
        if (*p == 3.4028235e38f) {
            p++;
            t = 0x7FFFFFFF;
        } else {
            t = (s32)fn_801F6120(&p);
        }
        a = t;
        if (*p == 3.4028235e38f) {
            p++;
            b = 0x7FFFFFFF;
        } else {
            b = (s32)fn_801F6120(&p);
        }
        c->cur = p;
        fn_8014818C(a, b);
        return 0;
    }
    return 1;
}

typedef struct { char pad[0x1c]; void *cur; } Stream;
extern void fn_80147EA4(s32 v);
s32 fn_80214CDC(s32 flags, Stream *s) {
    void *cur;
    s32 v;
    if (flags & 1) {
        cur = s->cur;
        cur = (char *)cur + 4;
        if (3.4028235e38f == *(f32 *)cur) {
            cur = (char *)cur + 4;
            v = 0x7FFFFFFF;
        } else {
            v = (s32)fn_801F6120((f32**)&cur);
        }
        s->cur = cur;
        fn_80147EA4(v);
        return 0;
    }
    return 1;
}

extern void fn_80147EA8(s32 v);
s32 fn_80214D6C(s32 flags, Stream *s) {
    void *cur;
    s32 v;
    if (flags & 1) {
        cur = s->cur;
        cur = (char *)cur + 4;
        if (3.4028235e38f == *(f32 *)cur) {
            cur = (char *)cur + 4;
            v = 0x7FFFFFFF;
        } else {
            v = (s32)fn_801F6120((f32**)&cur);
        }
        s->cur = cur;
        fn_80147EA8(v);
        return 0;
    }
    return 1;
}

extern void fn_80147EAC(s32 v);
s32 fn_80214DFC(s32 flags, Stream *s) {
    void *cur;
    s32 v;
    if (flags & 1) {
        cur = s->cur;
        cur = (char *)cur + 4;
        if (3.4028235e38f == *(f32 *)cur) {
            cur = (char *)cur + 4;
            v = 0x7FFFFFFF;
        } else {
            v = (s32)fn_801F6120((f32**)&cur);
        }
        s->cur = cur;
        fn_80147EAC(v);
        return 0;
    }
    return 1;
}

extern void fn_801486CC(s32 v);
s32 fn_80214E8C(s32 flags, Stream *s) {
    void *cur;
    s32 v;
    if (flags & 1) {
        cur = s->cur;
        cur = (char *)cur + 4;
        if (3.4028235e38f == *(f32 *)cur) {
            cur = (char *)cur + 4;
            v = 0x7FFFFFFF;
        } else {
            v = (s32)fn_801F6120((f32**)&cur);
        }
        s->cur = cur;
        fn_801486CC(v);
        return 0;
    }
    return 1;
}

extern void fn_80148BE8(s32 v);
s32 fn_80214F1C(s32 flags, Stream *s) {
    void *cur;
    s32 v;
    if (flags & 1) {
        cur = s->cur;
        cur = (char *)cur + 4;
        if (3.4028235e38f == *(f32 *)cur) {
            cur = (char *)cur + 4;
            v = 0x7FFFFFFF;
        } else {
            v = (s32)fn_801F6120((f32**)&cur);
        }
        s->cur = cur;
        fn_80148BE8(v);
        return 0;
    }
    return 1;
}

extern void fn_80148CAC(s32 v);
s32 fn_80214FAC(s32 flags, Stream *s) {
    void *cur;
    s32 v;
    if (flags & 1) {
        cur = s->cur;
        cur = (char *)cur + 4;
        if (3.4028235e38f == *(f32 *)cur) {
            cur = (char *)cur + 4;
            v = 0x7FFFFFFF;
        } else {
            v = (s32)fn_801F6120((f32**)&cur);
        }
        s->cur = cur;
        fn_80148CAC(v);
        return 0;
    }
    return 1;
}

s32 fn_8021503C(u32 a, CmdStream *st) {
    if (a & 1) {
        u8 *c = st->cur;
        st->cur = c + 4;
        fn_80148190(c);
        return 0;
    }
    return 1;
}

s32 fn_8021507C(u32 a, CmdStream *st) {
    if (a & 1) {
        u8 *c = st->cur;
        st->cur = c + 4;
        fn_801481B0(c);
        return 0;
    }
    return 1;
}

s32 fn_802150BC(u32 a, CmdStream *st) {
    if (a & 1) {
        u8 *c = st->cur;
        st->cur = c + 4;
        fn_801481D0(c);
        return 0;
    }
    return 1;
}

extern s32 lbl_803477E8;
void fn_8014836C(u16 a, s32 b);
s32 fn_80215368(u32 flags, Cmd *c) {
    float *p;
    u16 a;
    s32 t;
    s32 b;
    if (flags & 1) {
        p = c->cur;
        p++;
        if (*p == 3.4028235e38f) {
            p++;
            t = 0x7FFFFFFF;
        } else {
            t = (s32)fn_801F6120(&p);
        }
        a = t;
        if (*p == 3.4028235e38f) {
            p++;
            b = 0x7FFFFFFF;
        } else {
            b = (s32)fn_801F6120(&p);
        }
        c->cur = p;
        fn_8014836C(a, b);
        return 0;
    }
    return 1;
}

s32 fn_80215F8C(void) {
    return 1;
}

s32 fn_80216CA4(void)
{
    return lbl_803477E8 == 0;
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

typedef struct {
    u32 id;
    s32 pad4;
    s32 time;
    s32 pad0c;
    s32 pad10;
} SndSlot;
extern SndSlot lbl_80315030[12];
void fn_80217C24(void) {
    SndSlot *e = lbl_80315030;
    s32 i;
    for (i = 0; i < 6; i++, e++) {
        if (e->id != 0xFFFFFFFF) {
            if (e->id != lbl_803477E0) {
                sndSeqStop(e->id);
            }
            e->id = 0xFFFFFFFF;
            e->time = 0x2710;
        }
    }
}

void fn_80218D80(void) {
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

void fn_80216EFC(s32 a) {
    fn_80217830(a);
}

void fn_80216CB4(s32 p) {
    fn_802193BC(p, 0);
}

typedef struct {
    u8 pad[0x1c];
    f32* script;
} ScriptObj;
extern void fn_80168398(f32 a, f32 b, f32 c, f32 d, s32 i0, s32 i1, s32 i2, s32 i3, u16 i4, u8 i5);
static inline s32 ReadInt(f32** p)
{
    if (3.4028235e38f == **p) {
        (*p)++;
        return 0x7FFFFFFF;
    }
    return (s32)fn_801F6120(p);
}
s32 fn_801F9988(u16 flags, ScriptObj* obj)
{
    f32* p;
    f32 f0, f1, f2, f3;
    s32 h;
    u16 a;
    u32 c;
    s8 d;
    s8 e;
    s8 b;

    if (flags & 1) {
        p = obj->script + 1;
        a = ReadInt(&p);
        f0 = fn_801F6120(&p);
        f1 = fn_801F6120(&p);
        f2 = fn_801F6120(&p);
        b = ReadInt(&p);
        f3 = fn_801F6120(&p);
        c = ReadInt(&p);
        d = ReadInt(&p);
        e = ReadInt(&p);
        h = ReadInt(&p);
        h = (h == 0x7FFFFFFF) ? 0 : h + 1;
        obj->script = p;
        fn_80168398(f0, f1, f2, f3, c, d, e, b, a, h);
    }
    if (flags & 8)
        return 1;
    return 0;
}

extern void fn_80169144(f32 a, f32 b, f32 c, f32 d, s32 i0, s32 i1, s32 i2, s32 i3, u16 i4, u8 i5);
s32 fn_801F9C18(u16 flags, ScriptObj* obj)
{
    f32* p;
    f32 f0, f1, f2, f3;
    s32 h;
    u16 a;
    u32 c;
    s8 d;
    s8 e;
    s8 b;

    if (flags & 1) {
        p = obj->script + 1;
        a = ReadInt(&p);
        f0 = fn_801F6120(&p);
        f1 = fn_801F6120(&p);
        f2 = fn_801F6120(&p);
        b = ReadInt(&p);
        f3 = fn_801F6120(&p);
        c = ReadInt(&p);
        d = ReadInt(&p);
        e = ReadInt(&p);
        h = ReadInt(&p);
        h = (h == 0x7FFFFFFF) ? 0 : h + 1;
        obj->script = p;
        fn_80169144(f0, f1, f2, f3, c, d, e, b, a, h);
    }
    if (flags & 8)
        return 1;
    return 0;
}

typedef struct CurState {
    u8 pad0[0x1c];
    u8 *cur;
} CurState;
extern void fn_800D2C94(s32 v);
s32 fn_801FFE3C(u32 flags, CurState *s)
{
    if (flags & 1) {
        u8 *p = s->cur + 4;
        u32 v;
        if (3.4028235e38f == *(f32 *)p) {
            p += 4;
            v = 0x7FFFFFFF;
        } else {
            v = (s32)fn_801F6120((f32**)&p);
        }
        s->cur = p;
        if (v == 0x7FFFFFFF) {
            fn_800D2C94(1);
        } else if (v == 1) {
            fn_800D2C94(1);
        } else {
            fn_800D2C94(0);
        }
    }
    return 0;
}

extern void fn_800D2C84(s32 v);
s32 fn_801FFEF0(u32 flags, CurState *s)
{
    if (flags & 1) {
        u8 *p = s->cur + 4;
        u32 v;
        if (3.4028235e38f == *(f32 *)p) {
            p += 4;
            v = 0x7FFFFFFF;
        } else {
            v = (s32)fn_801F6120((f32**)&p);
        }
        s->cur = p;
        if (v == 0x7FFFFFFF) {
            fn_800D2C84(1);
        } else if (v == 1) {
            fn_800D2C84(1);
        } else {
            fn_800D2C84(0);
        }
    }
    return 0;
}

s32 fn_801F9668(u32 flags, CurState *s)
{
    u16 f = (u16)flags;
    if (flags & 1) {
        u8 *p = s->cur + 4;
        u32 v;
        if (3.4028235e38f == *(f32 *)p) {
            p += 4;
            v = 0x7FFFFFFF;
        } else {
            v = (s32)fn_801F6120((f32**)&p);
        }
        s->cur = p;
        fn_80217830(v);
    }
    if (f & 0x8) {
        return 1;
    }
    return 0;
}

extern void fn_80168B7C(s32 v);
s32 fn_801F98E8(u32 flags, CurState *s)
{
    u16 f = (u16)flags;
    if (flags & 1) {
        u8 *p = s->cur + 4;
        u32 v;
        if (3.4028235e38f == *(f32 *)p) {
            p += 4;
            v = 0x7FFFFFFF;
        } else {
            v = (s32)fn_801F6120((f32**)&p);
        }
        s->cur = p;
        fn_80168B7C(v);
    }
    if (f & 0x8) {
        return 1;
    }
    return 0;
}

extern void fn_800E2924(s32 v);
extern f32 lbl_8034C248;
s32 fn_8020B80C(u32 flags, CurState *s)
{
    u16 f = (u16)flags;
    if (flags & 1) {
        u8 *p = s->cur + 4;
        u32 v;
        if (lbl_8034C248 == *(f32 *)p) {
            p += 4;
            v = 0x7FFFFFFF;
        } else {
            v = (s32)fn_801F6120((f32**)&p);
        }
        s->cur = p;
        fn_800E2924(v);
    }
    if (f & 0x8) {
        return 1;
    }
    return 0;
}

extern void fn_8021BD7C(s32 v);
s32 fn_8020B8AC(u32 flags, CurState *s)
{
    u16 f = (u16)flags;
    if (flags & 1) {
        u8 *p = s->cur + 4;
        u32 v;
        if (lbl_8034C248 == *(f32 *)p) {
            p += 4;
            v = 0x7FFFFFFF;
        } else {
            v = (s32)fn_801F6120((f32**)&p);
        }
        s->cur = p;
        fn_8021BD7C(v);
    }
    if (f & 0x8) {
        return 1;
    }
    return 0;
}

extern void fn_801E4AB0(s32 v);
s32 fn_8020B94C(u32 flags, CurState *s)
{
    u16 f = (u16)flags;
    if (flags & 1) {
        u8 *p = s->cur + 4;
        u32 v;
        if (lbl_8034C248 == *(f32 *)p) {
            p += 4;
            v = 0x7FFFFFFF;
        } else {
            v = (s32)fn_801F6120((f32**)&p);
        }
        s->cur = p;
        fn_801E4AB0(v);
    }
    if (f & 0x8) {
        return 1;
    }
    return 0;
}

extern void fn_800FF4EC(s32 v);
s32 fn_801FEB78(s32 flags, Stream *s) {
    void *cur;
    s32 v;
    if (flags & 1) {
        cur = (char *)s->cur + 4;
        if (3.4028235e38f == *(f32 *)cur) {
            cur = (char *)cur + 4;
            v = 0x7FFFFFFF;
        } else {
            v = (s32)fn_801F6120((f32**)&cur);
        }
        s->cur = cur;
        fn_800FF4EC(v);
    }
    return 0;
}

extern void fn_800FF5D0(s32 v);
s32 fn_801FEBFC(s32 flags, Stream *s) {
    void *cur;
    s32 v;
    if (flags & 1) {
        cur = (char *)s->cur + 4;
        if (3.4028235e38f == *(f32 *)cur) {
            cur = (char *)cur + 4;
            v = 0x7FFFFFFF;
        } else {
            v = (s32)fn_801F6120((f32**)&cur);
        }
        s->cur = cur;
        fn_800FF5D0(v);
    }
    return 0;
}

extern void fn_800FF6B4(s32 v);
s32 fn_801FEC80(s32 flags, Stream *s) {
    void *cur;
    s32 v;
    if (flags & 1) {
        cur = (char *)s->cur + 4;
        if (3.4028235e38f == *(f32 *)cur) {
            cur = (char *)cur + 4;
            v = 0x7FFFFFFF;
        } else {
            v = (s32)fn_801F6120((f32**)&cur);
        }
        s->cur = cur;
        fn_800FF6B4(v);
    }
    return 0;
}

extern void fn_80216D98(s32 v);
s32 fn_801FEDD0(s32 flags, Stream *s) {
    void *cur;
    s32 v;
    if (flags & 1) {
        cur = (char *)s->cur + 4;
        if (3.4028235e38f == *(f32 *)cur) {
            cur = (char *)cur + 4;
            v = 0x7FFFFFFF;
        } else {
            v = (s32)fn_801F6120((f32**)&cur);
        }
        s->cur = cur;
        fn_80216D98(v);
    }
    return 0;
}

void fn_80097294(u8 a);
void fn_80097204(f32 a, f32 b, f32 c);
void fn_80097318(s8 x);
s16 fn_80206FF4(u32 a0, CmdStream *st) {
    s32 n;
    u16 a = a0;
    f32 x, y, z;
    if (a0 & 1) {
        u8 *p = st->cur;
        fn_801F7500();
        p += 4;
        x = fn_801F6120((f32**)&p);
        y = fn_801F6120((f32**)&p);
        z = fn_801F6120((f32**)&p);
        if (3.4028235e38f == *(f32 *)p) {
            p += 4;
            n = 0x7fffffff;
        } else {
            n = (s32)fn_801F6120((f32**)&p);
        }
        st->cur = p;
        fn_80097294(1);
        if (3.4028235e38f != x) {
            fn_80097204(x, y, z);
        }
        if (n == 0) {
            fn_80097318(1);
        } else {
            fn_80097318(0);
        }
    }
    return (a >> 3) & 1;
}

void fn_80097228(f32 a, f32 b, f32 c);
s16 fn_80207130(u32 a0, CmdStream *st) {
    s32 n;
    u16 a = a0;
    f32 x, y, z;
    if (a0 & 1) {
        u8 *p = st->cur;
        fn_801F7500();
        p += 4;
        x = fn_801F6120((f32**)&p);
        y = fn_801F6120((f32**)&p);
        z = fn_801F6120((f32**)&p);
        if (3.4028235e38f == *(f32 *)p) {
            p += 4;
            n = 0x7fffffff;
        } else {
            n = (s32)fn_801F6120((f32**)&p);
        }
        st->cur = p;
        fn_80097294(1);
        if (3.4028235e38f != x) {
            fn_80097228(x, y, z);
        }
        if (n == 0) {
            fn_80097318(1);
        } else {
            fn_80097318(0);
        }
    }
    return (a >> 3) & 1;
}
