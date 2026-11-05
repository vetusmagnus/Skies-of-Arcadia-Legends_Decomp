#include "game/scptact.h"

extern s32 lbl_803477A8;
extern s32 lbl_803477AC;
typedef struct { u8 pad[0x54]; u32 size; } Res;
void fn_80218DDC(void);
Res* fn_801CC69C(s32 name);
void fn_801CC608(Res* h, void* buf, u32 size);
void fn_801CC65C(Res* h);
typedef struct {
    u32 n;                  /* 0x00 */
    u32 x4;
    void* x8;
    void** xc;
    void* (*x10_801F7500)[2];
    void** x14;
    void* (*x18)[2];
    void* x1c;
} Script_801F7500;
void fn_801EF300(void);

s32 fn_802114AC(s32 id, u8 *name);
extern const char lbl_802D4720[];

void fn_800B0F0C(void);
void fn_80212084(void);

/* A string argument: its byte length (padded to words), then the characters. */
static inline u8* StrText(void* p)
{
    u8* b = p;
    return b + 4;
}

static inline void* StrSkip(void* p)
{
    u32* w = p;
    return w + ((*w >> 2) + 1);
}

static inline void FlagClear(u32 b) {
    lbl_80310B3C[b >> 5] &= ~(1 << (b & 31));
}


s32 fn_801F570C(u32 flags, Scpt *cmd)
{
    u16 f = flags;
    if (flags & 1) {
        float *p = cmd->cur.f;
        p++;
        lbl_803477A8 = RDI(p);
        cmd->flags = 0;
        cmd->cur.f = p;
        if (lbl_803477A8 <= 0) {
            return 0;
        }
        lbl_803477AC = 0;
    }
    if (f & 2) {
        lbl_803477AC++;
        if (lbl_803477AC >= lbl_803477A8) {
            return 0;
        }
    }
    if (f & 8) {
        return 0;
    }
    return 1;
}

s32 fn_801F57F8(u32 flags, Scpt *cmd)
{
    if (flags & 1) {
        f32* p;
        s32 id;
        u8* name;
        p = cmd->cur.f + 1;
        id = ReadInt(&p);
        name = StrText(p);
        p = StrSkip(p);
        cmd->cur.f = p;
        if (fn_802114AC(id, name) == 0) {
            fn_801DBE1C("scptWWW: No Empty LazyBuffer");
        }
    }
    return 0;
}

s32 fn_801F58B0(void) {
    return 1;
}

s32 fn_801F58B8(s32 unused, Scpt *c) {
    f32 *p;
    p = c->cur.f;
    p++;
    {
        s32 v = ReadInt(&p);
        c->cur.f = p;
        fn_801EFC88(v);
    }
    return 0;
}

s32 fn_801F593C(s32 unused, Scpt *c) {
    f32 *p;
    p = c->cur.f;
    p++;
    {
        s32 v = ReadInt(&p);
        c->cur.f = p;
        fn_801EFF0C(v);
    }
    return 0;
}

s32 fn_801F59C0(s32 unused, Scpt *s) {
    f32 *p;
    u32 v;
    p = s->cur.f;
    p++;
    if (3.4028235e38f == *p) {
        p++;
        v = 0x7FFFFFFF;
    } else {
        v = (s32)fn_801F6120(&p);
    }
    s->cur.f = p;
    if (lbl_80310B3C[v >> 5] & (1u << (v & 31))) {
        lbl_80310B3C[v >> 5] &= ~(1u << (v & 31));
    } else {
        lbl_80310B3C[v >> 5] |= 1u << (v & 31);
    }
    return 0;
}

/* Scpt command: clear the story flag given by the next argument. */
s32 fn_801F5A74(s32 unused, Scpt *c) {
    f32 *p;
    p = c->cur.f;
    p++;
    {
        s32 v = ReadInt(&p);
        c->cur.f = p;
        FlagClear(v);
    }
    return 0;
}

s32 fn_801F5B14(u16 flags, Scpt* obj)
{
    f32* p;
    u32 bit;
    p = obj->cur.f;
    p++;
    bit = ReadInt(&p);
    obj->cur.f = p;
    lbl_80310B3C[bit >> 5] |= 1 << (bit & 31);
    return 0;
}

s32 fn_801F5BB4(s32 unused, Scpt *c) {
    u32 *p = c->cur.u;
    c->flags = 0;
    c->cur.u = p + 1;
    return 0;
}

/* Scpt "return": pops the cursor saved by a call (stack[sp--]); with an empty stack it
 * ends the script (x1874 = 0) unless x0a > 1, which reports 1. */
s32 fn_801F5BD0(s32 unused, Scpt* s) {
    f32* cur = s->cur.f;
    if (lbl_8030CEA0.sp <= 0) {
        if (lbl_8030CEA0.x0a <= 1) {
            lbl_8030CEA0.x1874 = 0;
            s->cur.f = cur;
            return 0;
        }
        return 1;
    }
    s->cur.f = lbl_8030CEA0.stack[lbl_8030CEA0.sp--];
    return 0;
}

s32 fn_801F5C30(s32 unused, Scpt *st)
{
    u32 *p = st->cur.u;

    if (lbl_8030CEA0.sp >= 0x20) {
        fn_801DBE1C("GOSUB: Stack over flow");
    }
    lbl_8030CEA0.stack[++lbl_8030CEA0.sp] = p + 2;
    p++;
    p += *p / 4;
    st->cur.u = p;
    return 0;
}

s32 fn_801F5CCC(s32 unused, Scpt *st) {
    u8 *p = st->cur.b;
    u32 v;
    p += 4;
    v = *(u32 *)p;
    if (v > 0x10000 && v < 0xffff0000) {
        v = (v >> 24) | ((v >> 8) & 0xff00) | ((v << 8) & 0xff0000) | (v << 24);
        *(u32 *)p = v;
    }
    p += *(u32 *)p & ~3u;
    st->cur.b = p;
    return 0;
}


s32 fn_801F5D08(s32 unused, Scpt *st) {
    float *p = st->cur.f;
    s16 idx;
    f32 v;
    p++;
    idx = (s16)(*(u32 *)p - 0x40000000);
    v = fn_801F6120(&p);
    lbl_8030CEA0.x1674[idx] = v;
    st->cur.f = p;
    return 0;
}

/* Scpt command: set script value idx (the argument's tag word minus 0x50000000) to the next
 * argument; value 1 is clamped to 0..255 and copied to the save's x348, value 0 is gold
 * (0..99,999,999). */
s32 fn_801F5D7C(s32 unused, Scpt *st) {
    f32 *p = st->cur.f;
    s16 idx;
    p++;
    idx = (s16)(*(u32 *)p - 0x50000000);
    lbl_8030CEA0.x1544[idx] = ReadInt(&p);
    switch (idx) {
    case 1:
        if (lbl_8030CEA0.x1544[idx] > 0xff) {
            lbl_8030CEA0.x1544[idx] = 0xff;
        } else if (lbl_8030CEA0.x1544[idx] < 0) {
            lbl_8030CEA0.x1544[idx] = 0;
        }
        lbl_8030B7F4.x348 = lbl_8030CEA0.x1544[idx];
        fn_801EF300();
        break;
    case 0:
        if (lbl_8030CEA0.x1544[idx] > 99999999) {
            lbl_8030CEA0.x1544[idx] = 99999999;
        } else if (lbl_8030CEA0.x1544[idx] < 0) {
            lbl_8030CEA0.x1544[idx] = 0;
        }
        lbl_8030B7F4.w34c = lbl_8030CEA0.x1544[idx];
        break;
    }
    st->cur.f = p;
    return 0;
}

s32 fn_801F5EB4(s32 unused, Scpt *st) {
    float *p = st->cur.f;
    s16 idx;
    s32 v;
    p++;
    idx = (s16)(*(u32 *)p - 0x10000000);
    if (*p == 3.4028235e38f) {
        p++;
        v = 0x7FFFFFFF;
    } else {
        v = (s32)fn_801F6120(&p);
    }
    lbl_80310A1C[idx] = v;
    st->cur.f = p;
    return 0;
}

s32 fn_801F5F50(u32 flags, Scpt *st) {
    float *p;
    u8 *def = NULL;
    u32 n;
    u32 cnt;
    u32 i;
    p = st->cur.f;
    p++;
    n = (u32)fn_801F6120(&p);
    cnt = *(u32 *)p++;
    for (i = 0; i < cnt; i++) {
        u32 v = *(u32 *)p;
        if (v == 0xFFFFFFFF) {
            p++;
            p = (float *)((u8 *)p + (*(u32 *)p & ~3));
            def = (u8 *)p;
        } else if (n == v) {
            p++;
            p = (float *)((u8 *)p + (*(u32 *)p & ~3));
            st->cur.f = p;
            return 0;
        } else {
            p += 2;
        }
    }
    st->cur.f = def != NULL ? (float *)def : p;
    return 0;
}

s32 fn_801F6044(s32 unused, Scpt *st) {
    float *p = st->cur.f;
    p++;
    if (fn_801F6120(&p) == 0.0f) {
        p = (float *)((u8 *)p + (*(u32 *)p & ~3u));
        st->cur.f = p;
        return 0;
    }
    p++;
    st->cur.f = p;
    return 0;
}

s32 fn_801F60C4(s32 unused, Scpt *c) {
    u32 *p = c->cur.u + 1;
    while (*p != 0x1d) {
        p++;
    }
    c->cur.u = p + 1;
    return 0;
}
int fn_801F60F0(void) {
    fn_801DBE1C("scptSTUB: code error!");
    return 0;
}

s16 fn_801F6EC8(s32 v) {
    s32 i;
    for (i = 0; i < 256; i++) {
        if (lbl_8030CEA0.ent[i][1] == v) {
            return i;
        }
    }
    return -1;
}

s16 fn_801F6FC8(s32 id)
{
    s32 i;
    for (i = 0; i < 256; i++) {
        if (lbl_8030CEA0.ent[i][0] != 0 && lbl_8030CEA0.ent[i][1] == id) {
            return -1;
        }
    }
    for (i = 0; i < 256; i++) {
        if (lbl_8030CEA0.ent[i][0] == 0) {
            lbl_8030CEA0.ent[i][0] = 1;
            lbl_8030CEA0.ent[i][1] = id;
            return i;
        }
    }
    return -1;
}

s32 fn_801F7158(s32 name)
{
    Res* res;
    u32 size;
    u32 len;
    u8* p;

    fn_80218DDC();
    if (lbl_8030CEA0.x0 != 0) {
        fn_801E1784(lbl_8030CEA0.x0);
        lbl_8030CEA0.x0 = 0;
    }
    res = fn_801CC69C(name);
    if (res != 0) {
        u8* base;
        u32 n;
        size = res->size;
        if (size == 0) {
            fn_801DBE1C("scptLoad: Len is zero");
        }
        len = (size + 0x1f) & ~0x1f;
        p = fn_801E1A2C(1, len);
        base = p;
        fn_801CC608(res, p, len);
        fn_801CC65C(res);
        lbl_8030CEA0.x824 = *(u32*)(p + 8);
        p += 0xc;
        if (lbl_8030CEA0.x824 != 0) {
            lbl_8030CEA0.x820 = fn_801E1A2C(1, lbl_8030CEA0.x824 * 0x14);
            n = lbl_8030CEA0.x824 * 0x14;
            memcpy(lbl_8030CEA0.x820, p, n);
            p += n;
        } else {
            lbl_8030CEA0.x820 = 0;
        }
        len -= lbl_8030CEA0.x824 * 0x14 + 8;
        lbl_8030CEA0.x0 = fn_801E1A2C(1, ((len >> 2) + 1) << 2);
        if (lbl_8030CEA0.x0 == 0) {
            fn_801DBE1C("scptLoad: gScpt.PtrTop == NULL");
        }
        memcpy(lbl_8030CEA0.x0, p, len);
        lbl_8030CEA0.x4 = lbl_8030CEA0.x0;
        *(u32*)((u8*)lbl_8030CEA0.x0 + (len & ~3)) = 0xc;
        if (base != 0) {
            fn_801E1784(base);
        }
        return 1;
    }
    return 0;
}

s32 fn_801F72F8(void)
{
    fn_800B0F0C();
    fn_80212084();
    fn_801F7500();
    lbl_8030CEA0.x191c = 0;
    if (lbl_8030CEA0.x0 != 0) {
        fn_801E1784(lbl_8030CEA0.x0);
        lbl_8030CEA0.x0 = 0;
    }
    if (lbl_8030CEA0.x820 != 0) {
        fn_801E1784(lbl_8030CEA0.x820);
        lbl_8030CEA0.x820 = 0;
    }
    lbl_8030CEA0.x824 = 0;
    lbl_8030CEA0.x08 = 0;
    lbl_8030CEA0.x0a = 0;
    if (lbl_8030CEA0.x10 != 0) {
        fn_801E1784(lbl_8030CEA0.x10);
        lbl_8030CEA0.x10 = 0;
    }
    lbl_8030CEA0.x1544[1] = lbl_8030B7F4.x348;
    if (lbl_80347474 != 0) {
        u32 i;
        lbl_8030CEA0.x156c = 0xffff;
        lbl_8030CEA0.x15d0 = 0xfffe;
        lbl_8030CEA0.x1578 = 0;
        lbl_8030CEA0.x1574 = 0;
        lbl_8030CEA0.x1570 = 0;
        lbl_8030CEA0.x1568 = 0;
        lbl_8030CEA0.x1544[8] = 0;
        lbl_80310B3C[58] = 0;
        lbl_80310B3C[59] = 0;
        lbl_80310B3C[60] = 0;
        lbl_80310B3C[61] = 0;
        lbl_80310B3C[62] = 0;
        lbl_80310B3C[63] = 0;
        FlagClear(0x401);
        FlagClear(0x43f);
        FlagClear(0x440);
        FlagClear(0x441);
        FlagClear(0x45f);
        FlagClear(0x442);
        FlagClear(0x44d);
        FlagClear(0x451);
        {
            u8* p = &lbl_80310A1C[0x80];
            for (i = 0; i < 128; i++) {
                *p++ = 0;
            }
        }
    }
    return 1;
}

void fn_801F7500(void)
{
    Script_801F7500* s;
    u32 i;
    s = lbl_8030CEA0.x1914;
    if (s != 0) {
        if (s->xc[0] != 0) {
            fn_801E1784(s->xc[0]);
            s->xc[0] = 0;
        }
        if (s->x14[0] != 0) {
            fn_801E1784(s->x14[0]);
            s->x14[0] = 0;
        }
        for (i = 0; i < s->n - 1; i++) {
            if (s->xc[i + 1] != 0) {
                fn_801E1784(s->xc[i + 1]);
                s->xc[i + 1] = 0;
            }
            if (s->x14[i + 1] != 0) {
                fn_801E1784(s->x14[i + 1]);
                s->x14[i + 1] = 0;
            }
            if (s->x10_801F7500[i][0] != 0) {
                fn_801E1784(s->x10_801F7500[i][0]);
                s->x10_801F7500[i][0] = 0;
            }
            if (s->x10_801F7500[i][1] != 0) {
                fn_801E1784(s->x10_801F7500[i][1]);
                s->x10_801F7500[i][1] = 0;
            }
            if (s->x18[i][0] != 0) {
                fn_801E1784(s->x18[i][0]);
                s->x18[i][0] = 0;
            }
            if (s->x18[i][1] != 0) {
                fn_801E1784(s->x18[i][1]);
                s->x18[i][1] = 0;
            }
        }
        if (s->x1c != 0) {
            fn_801E1784(s->x1c);
            s->x1c = 0;
        }
        if (s->xc != 0) {
            fn_801E1784(s->xc);
            s->xc = 0;
        }
        if (s->x14 != 0) {
            fn_801E1784(s->x14);
            s->x14 = 0;
        }
        if (s->x10_801F7500 != 0) {
            fn_801E1784(s->x10_801F7500);
            s->x10_801F7500 = 0;
        }
        if (s->x18 != 0) {
            fn_801E1784(s->x18);
            s->x18 = 0;
        }
        if (s->x8 != 0) {
            fn_801E1784(s->x8);
            s->x8 = 0;
        }
        if (lbl_8030CEA0.x1914 != 0) {
            fn_801E1784(lbl_8030CEA0.x1914);
            lbl_8030CEA0.x1914 = 0;
        }
        lbl_8030CEA0.x15cc = 0;
    }
}

void fn_801F773C(void)
{
    Script_801F773C* s = lbl_8030CEA0.x1914;
    if (s != 0) {
        f32 tmp[3];
        if (lbl_8030CEA0.x1918 == s->times[s->idx]) {
            lbl_8030CEA0.x1918 = 0;
            s->idx++;
            if (s->idx >= s->n - 2) {
                s->idx = 1;
            }
        }
        fn_80213178((f32)lbl_8030CEA0.x1918, (f32)s->times[s->idx], s->xc[s->idx], s->x10[2 * s->idx],
                    s->x10[2 * s->idx + 1], s->xc[s->idx + 1], &lbl_8030CEA0.x18fc);
        fn_80213178((f32)lbl_8030CEA0.x1918, (f32)s->times[s->idx], s->x14[s->idx], s->x18[2 * s->idx],
                    s->x18[2 * s->idx + 1], s->x14[s->idx + 1], tmp);
        fn_80213478(tmp, &lbl_8030CEA0.x18fc, &lbl_8030CEA0.x1908);
        {
            f32 lo = s->angles[s->idx];
            lbl_8030CEA0.x1910 = (s32)(182.04445f * (lo + ((f32)lbl_8030CEA0.x1918 / (f32)s->times[s->idx]) *
                                                           (s->angles[s->idx + 1] - lo)));
            lbl_8030CEA0.x1918++;
        }
    }
}

s32 fn_801F7958(void)
{
    u32 i;
    const char* str = lbl_802D4720;
    lbl_8030CEA0.x818.w = 12;
    lbl_8030CEA0.x0 = 0;
    lbl_8030CEA0.x4 = lbl_8030CEA0.x818.b;
    lbl_8030CEA0.x1874 = 0;
    lbl_8030CEA0.sp = 0;
    lbl_8030CEA0.x1878 = 0x20;
    lbl_8030CEA0.x1914 = 0;
    lbl_8030CEA0.x0a = 0;
    if (lbl_8030CEA0.x10 != 0) {
        fn_801DBE1C(str + 0xa4);
    }
    lbl_8030CEA0.xc = 0x180;
    lbl_8030CEA0.x10 = fn_801E1A2C(1, 0x4e00);
    if (lbl_8030CEA0.x10 == 0) {
        fn_801DBE1C(str + 0xc8);
    }
    lbl_8030CEA0.x14 = fn_801E1A2C(1, 0xc00);
    if (lbl_8030CEA0.x14 == 0) {
        fn_801DBE1C(str + 0xe8);
    }
    memset(lbl_8030CEA0.x10, 0, 0x4e00);
    memset(lbl_8030CEA0.x14, 0, 0xc00);
    for (i = 0; i < 256; i++) {
        lbl_8030CEA0.ent[i][1] = 0;
        lbl_8030CEA0.ent[i][0] = 0;
    }
    return 1;
}

void fn_801F7B04(s32 v) {
    lbl_8030CEA0.x1580 = v;
}
