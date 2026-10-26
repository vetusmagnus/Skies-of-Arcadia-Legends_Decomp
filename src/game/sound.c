/* Sound loading (0x8003DEE0 - 0x80040010): the sound state lbl_8030A10C (SoundSys), .SAMP
 * sample-bank loading through a task (fn_8003E2B4 reads /SOUND/<name> into the two sample
 * slots), the battle stage/enemy sample numbers (fn_8003E4CC, fn_8003E624), the voice-file
 * name builder fn_8003ECF4 ("B702%04dS.P04" etc.) with its id tables, the two voice stream
 * slots (fn_8003F890 opens /SOUND/<voice>, fn_8003FA70 polls them) and the character sound
 * id lookups into lbl_802DE630 (fn_8003FD40, fn_8003FE54).
 *
 * Built with -str reuse,readonly -inline noauto,deferred (configure.py): strings land in .rodata,
 * and with deferred codegen the compiler emits the functions in reverse source order, local
 * array initialisers (fn_8003E7A4's table) ahead of every string, and the jump tables in code
 * order. So the functions below are written from the highest address down; the inline helpers
 * come first because they must precede their users. See docs/compiler.md. */
#include "types.h"
#include "game/task.h"

/* One open voice stream (lbl_8030A10C.slot). */
typedef struct {
    void* obj;   /* 0x00 */
    s8 owner;    /* 0x04: character id */
    s8 kind;     /* 0x05: fn_8003ECF4 kind */
    s16 a;       /* 0x06 */
    s16 b;       /* 0x08 */
    u8 pad0a[6];
} SndSlot;

typedef struct {
    u8 pad0[0x6C];
    u32 flags;              /* 0x6C: 0x80000000 loading, 0x1000 stage sample toggle */
    s16 seArg;              /* 0x70 */
    s8 owner;               /* 0x72 */
    u8 pad73;
    s32 size[2];            /* 0x74 */
    void* data[2];          /* 0x7C */
    char sampName[2][0x20]; /* 0x84 */
    u8 padC4[0xCC - 0xC4];
    SndSlot slot[2];        /* 0xCC */
    u8 padEC[0x1D0 - 0xEC];
} SoundSys;

/* Work of the .SAMP loader task fn_8003E2B4. */
typedef struct {
    u32 flags;              /* 0x00: 0x80000000 cache, 0x40000000 two files */
    u8 pad4[0x4];
    void* handle;           /* 0x08 */
    u8 pad0c[0x2C - 0x0C];
    char path[0x40];        /* 0x2C */
    char name[2][0x10];     /* 0x6C */
    s16 idx;                /* 0x8C */
    u8 pad8e[0x9C - 0x8E];
    void* data;             /* 0x9C */
    u8 padA0[0xAC - 0xA0];
} SampWork;

typedef struct {
    u8 pad0[0x18];
    u8 flags;               /* 0x18 */
    u8 state;               /* 0x19 */
    u8 pad1a[0x24 - 0x1A];
    SampWork* work;         /* 0x24 */
} SampTask;

/* A battle character task and the parts of its work used here. */
typedef struct {
    u8 pad0[0xC];
    char name[0x30 - 0xC];  /* 0x0C */
    void* x30;              /* 0x30 */
} ChrRes;

typedef struct {
    s8 id;                  /* 0x00 */
    u8 pad1;
    s16 x2;                 /* 0x02 */
    u8 x4;                  /* 0x04 */
    u8 pad5;
    s16 x6;                 /* 0x06 */
    s16 x8;                 /* 0x08 */
    u8 padA[0x10 - 0xA];
    s16 x10;                /* 0x10 */
    u8 pad12[0x48 - 0x12];
    s8 x48;                 /* 0x48 */
    u8 pad49;
    s16 x4a;                /* 0x4A */
    u8 pad4c[0x50 - 0x4C];
    u32 x50;                /* 0x50 */
    u8 pad54[0xEC - 0x54];
    u32 xec;                /* 0xEC */
    u32 xf0;                /* 0xF0 */
    u8 padF4[0x298 - 0xF4];
    void* x298;             /* 0x298 */
} ChrInfo;

typedef struct {
    u8 pad0[0x10];
    ChrRes* res;            /* 0x10 */
    u8 pad14[0x4C - 0x14];
    ChrInfo* info;          /* 0x4C */
} ChrWork;

typedef struct {
    u8 pad0[0x24];
    ChrWork* work;          /* 0x24 */
} ChrTask;

typedef struct { s16 x0; s16 x2; } SndId;
typedef struct { u8 pad[0x24]; SndId* id; } SndIdTask;

typedef struct { u8 pad[0x24]; s16 x24, x26, x28; } SndRec;
typedef struct { u8 pad[0xC]; SndRec* rec; } SndFound;

extern SoundSys lbl_8030A10C;
extern void* lbl_803475A8;
extern struct { u8 pad[0x328]; s8 x328[4]; } lbl_8030B7F4;
extern SndIdTask* lbl_80309700[12];
extern ChrTask* lbl_80309E24[12];
/* Character voice id tables (fn_8003FD40, fn_8003FE54). */
s16 lbl_802DE630[190] = {
    0x0, 0x2B, 0x5, 0x11, 0x1, 0x21, 0x6, 0x12, 0x0, 0x0,
    0x0, 0x0, 0x2, 0x20, 0x7, 0x13, 0x3, 0x11, 0x8, 0x14,
    0xF, 0x4, 0x4, 0x15, 0x18, 0x16, 0x19, 0x17, 0x10, 0x1A,
    0x1B, 0x1C, 0x1D, 0x1E, 0x2B, 0x1E, 0x2B, 0x1F, 0x2C, 0x20,
    0x2D, 0x21, 0x2E, 0x22, 0x2F, 0x23, 0x30, 0x26, 0x33, 0x27,
    0x34, 0x28, 0x35, 0x29, 0x36, 0x2A, 0x37, 0xA, 0x3A, 0x39,
    0x38, 0x3B, 0x41, 0x49, 0x24, 0x31, 0x25, 0x32, 0xB, 0xC,
    0xB, 0xD, 0xE, 0xF, 0x3C, 0x3D, 0x3E, 0x3F, 0x40, 0x42,
    0x44, 0x45, 0x46, 0x47, 0x48, 0x4A, 0x4B, 0x4C, 0x4E, 0x4D,
    0x4F, 0x4E, 0x50, 0x4F, 0x51, 0x2B, 0x52, 0x2C, 0x53, 0x2D,
    0x54, 0x2E, 0x55, 0x2F, 0x56, 0x30, 0x57, 0x31, 0x58, 0x32,
    0x59, 0x33, 0x5A, 0x34, 0x5B, 0x35, 0x5C, 0x36, 0x5D, 0x37,
    0x5E, 0x5F, 0x61, 0x60, 0x62, 0x63, 0x64, 0x65, 0x0, 0x1,
    0x2, 0x3, 0x4, 0x5, 0x6, -1, -1, -1, 0x7, 0x8,
    0x9, 0xA, 0xB, 0xC, 0xD, -1, -1, -1, 0xE, 0xF,
    0x10, 0x11, 0x12, 0x13, 0x14, -1, -1, -1, 0x15, 0x16,
    0x17, 0x18, 0x19, 0x1A, 0x1B, 0x15, 0x15, 0x15, -1, -1,
    -1, -1, 0x66, 0x67, 0x68, 0x1C, 0x1D, 0x1E, 0x1F, 0x20,
    0x69, 0x9, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, -1,
};

extern Task* fn_802268E8(void*, void*);
extern void fn_80061F58(void*, int, int);
extern int fn_8025CB24(char*, const char*, ...);
extern char* fn_8025F120(char*, const char*);
extern char* fn_8025F0B0(char*, const char*);
extern int fn_8025ECC4(void);
extern void* fn_801CC1B4(char*);
extern int fn_801CC1A4(void*);
extern void* fn_801CC0A0(void*);
extern void fn_80218D84(void*, void*, u32);
extern void fn_80217830(void*);
extern void fn_80073B48(s8*);
extern int fn_80077E34(void);
extern s16 fn_80008274(s16);
extern void fn_800308FC(char*, s16, s16);
extern s8 fn_80020E10(char*);
extern int fn_80216F48(void*);
extern int fn_80020700(int, int, void*);
extern void fn_80215F94(void*);
extern int fn_80008AB4(void*, s16, s16, int, int, int, void*);
extern int fn_800154BC(ChrTask*);
extern s32 fn_800153E0(s32, s16);
extern void* fn_80215F14(s32, s32, s32, s32, s32, s32, char*);
extern s32 fn_80215F8C(void*);
extern s32 SePlay(s32 bank, s8 arg1, s8 id);
extern void fn_802172C8(void*, s32);
extern void* fn_800215EC(s32);
extern s32 fn_8001C1F0(void);
extern ChrTask* fn_80021658(s8);
extern s32 fn_8000F208(ChrTask**);
extern s32 fn_80008F08(void*, s32, s32, s32, s32, s32, SndFound**);
extern void fn_80219378(char*);

void fn_8003E1BC(void);
void fn_8003E2B4(SampTask*);
s16 fn_8003E4CC(void);
s16 fn_8003E624(void);
s16 fn_8003E7A4(s16);
void fn_8003EB1C(Task*);
s16 fn_8003F228(ChrTask*);
s16 fn_8003F2C0(ChrTask*);
s16 fn_8003F358(ChrTask*);
s16 fn_8003F3F0(ChrTask*);
s16 fn_8003F484(ChrTask*);
s8 fn_8003F890(s16 a, s16 b, s8 c, ChrTask* t);
s16 fn_8003FD40(s32 a, s8 kind);
s16 fn_8003FE54(ChrTask* t, s8 kind);

void fn_8003DEE0(void);
void fn_8003DFE0(void);
void fn_8003E084(void);
void fn_8003E0F4(s8 a, s8 b);
void fn_8003E464(char* buf);
void fn_8003EBE0(ChrTask* arg);
int fn_8003ECF4(char* out, s16 a, s16 b, ChrTask* t, s8 kind);
s8 fn_8003F5B8(ChrTask* t, s16 a, s16 b, s16 c, s16 d);
void fn_8003FA30(s8* p);
s32 fn_8003FA70(ChrTask* t);
void fn_8003FB70(ChrTask* t, s8 a);
void fn_8003FC18(ChrTask* t);
s16 fn_8003FF7C(s16 i);
void fn_8003FF94(void);

/* Voice set of the party member found in lbl_80309E24 (0 Vyse, 1 Aika, 2 Fina). */
static inline s8 PartyVoice(void)
{
    s8 i;
    for (i = 0; i < 12; i++) {
        if (lbl_80309E24[i] != NULL && fn_800154BC(lbl_80309E24[i]) == 0) {
            switch (fn_80020E10(lbl_80309E24[i]->work->res->name)) {
            case 3:
                return 0;
            case 4:
                return 1;
            case 5:
                return 2;
            }
        }
    }
    return 0;
}

static inline s16 VoiceA(ChrTask* t)
{
    ChrInfo* d = t->work->info;
    switch (fn_80008274(d->x2)) {
    case 0x63:
    case 0x88:
        return 0x15E0;
    case 0x4D:
    case 0x9A:
        return 0x15E1;
    case 0x17:
        return 0x15E4;
    case 0x46:
        return 0x15EE;
    case 0xEE:
        return 0x15F5;
    default:
        return d->x2 + 0x1560;
    }
}

static inline s16 VoiceB(ChrTask* t)
{
    ChrInfo* d = t->work->info;
    switch (fn_80008274(d->x2)) {
    case 0x63:
    case 0x88:
        return 0x157C;
    case 0x4D:
    case 0x9A:
        return 0x157D;
    case 0x97:
        return 0x1580;
    case 0x98:
        return 0x1588;
    case 0x46:
        return 0x158A;
    case 0xEE:
        return 0x1591;
    default:
        return d->x2 + 0x14FC;
    }
}

void fn_8003FF94(void)
{
    char name[16];
    char path[32];
    s16 base = fn_8003E624();
    fn_8025CB24(name, "STV%02d.SAMP", (s16)(base + fn_8025ECC4() % 2));
    fn_8025CB24(path, "/SOUND/%s", name);
    fn_80219378(path);
}

s16 fn_8003FF7C(s16 i)
{
    return lbl_802DE630[i];
}

s16 fn_8003FE54(ChrTask* t, s8 kind)
{
    s16 idx;
    SndFound* f;
    switch (kind) {
    default:
    case 0:
        idx = 0x21;
        break;
    case 1:
        idx = 0x27;
        break;
    case 2:
        idx = 0x39;
        break;
    case 3:
        idx = 0x28;
        break;
    case 4:
        idx = 0x19;
        break;
    }
    if (kind != 2) {
        if (fn_80008F08(t->work->res->x30, 0, 0, 0x36, 3, 1, &f)) {
            SndRec* r = f->rec;
            switch (kind) {
            default:
            case 0:
            case 2:
                idx = r->x24;
                break;
            case 1:
                idx = r->x28;
                break;
            case 3:
                idx = r->x24 + 1;
                break;
            case 4:
                idx = r->x26;
                break;
            }
        }
    }
    return lbl_802DE630[idx];
}

s16 fn_8003FD40(s32 a, s8 kind)
{
    ChrTask* t = fn_80021658(a);
    s8 x = fn_80020E10(t->work->res->name);
    s16 idx;
    if (x >= 0) {
        if (x != 2) {
            if (kind == 4) {
                idx = 0x18;
            } else {
                idx = kind + x * 4;
            }
        } else {
            if (fn_8000F208(&t)) {
                return fn_8003FE54(t, kind);
            }
            switch (kind) {
            default:
            case 0:
                idx = 0x27;
                break;
            case 1:
                idx = 0x27;
                break;
            case 2:
                idx = 0x39;
                break;
            case 3:
                idx = 0x28;
                break;
            case 4:
                idx = 0x19;
                break;
            }
        }
        return lbl_802DE630[idx];
    }
    return fn_8003FE54(t, kind);
}

void fn_8003FC18(ChrTask* t)
{
    ChrInfo* d = t->work->info;
    s32 hit = 0;
    if (!(d->xec & 0x100000)) {
        s8 kind;
        s16 r;
        if (fn_800215EC(d->x4) != NULL && fn_8001C1F0() != 0) {
            hit = 1;
        }
        if (hit != 0) {
            r = fn_8003FD40(0, 0);
        } else {
            switch (d->x4a) {
            case 4:
            case 9:
                kind = 0;
                break;
            case 5:
            case 10:
                kind = 1;
                break;
            case 8:
                kind = 3;
                break;
            default:
                return;
            }
            if (d->xec & 0x20) {
                return;
            }
            if (d->xec & 0x40) {
                kind = 4;
            }
            if (kind != 4) {
                r = fn_8003FD40(d->x48, kind);
            } else {
                r = fn_8003FD40(d->id, kind);
            }
        }
        SePlay(0, lbl_8030A10C.seArg, r);
    }
}

void fn_8003FB70(ChrTask* t, s8 a)
{
    ChrInfo* d = t->work->info;
    s8 kind = 0;
    s16 r;
    void* h;
    switch (d->x6) {
    case 13:
        kind = 2;
        break;
    case 12:
        kind = 4;
        break;
    }
    if (kind != 4) {
        r = fn_8003FD40(a, kind);
    } else {
        r = fn_8003FD40(d->id, kind);
    }
    h = (void*)SePlay(0, lbl_8030A10C.seArg, r);
    if (h != NULL) {
        fn_802172C8(h, -0x10);
    }
}

s32 fn_8003FA70(ChrTask* t)
{
    SoundSys* s;
    ChrInfo* d;
    s8 i;
    s8 n = 0;
    d = t->work->info;
    s = &lbl_8030A10C;
    if (s->owner == d->id) {
        if (s->data[0] != NULL && s->data[1] != NULL) {
            s->owner = -1;
            return 1;
        }
        return 0;
    }
    for (i = 0; i < 2; i++) {
        if (d->id == lbl_8030A10C.slot[i].owner && lbl_8030A10C.slot[i].obj != NULL) {
            if (fn_80215F8C(lbl_8030A10C.slot[i].obj) == 0) {
                return 0;
            }
            n++;
        }
    }
    return n != 0 ? 1 : -1;
}

void fn_8003FA30(s8* p)
{
    s16 snd = fn_8003FD40(*p, 2);
    SePlay(0, 7, snd);
}

s8 fn_8003F890(s16 a, s16 b, s8 c, ChrTask* t)
{
    ChrInfo* d = t->work->info;
    s8 i;
    s8 slot;
    char name[16];
    char path[32];
    for (i = 0; i < 2; i++) {
        if (lbl_8030A10C.slot[i].owner == d->id && lbl_8030A10C.slot[i].a == a &&
            lbl_8030A10C.slot[i].b == b && lbl_8030A10C.slot[i].kind == c) {
            return 1;
        }
    }
    slot = -1;
    for (i = 0; i < 2; i++) {
        if (lbl_8030A10C.slot[i].obj == NULL) {
            slot = i;
            break;
        }
    }
    if (slot < 0) {
        return 0;
    }
    if (fn_8003ECF4(name, a, b, t, c) != 0) {
        fn_8025F120(path, "/SOUND/");
        fn_8025F0B0(path, name);
        lbl_8030A10C.slot[slot].obj = fn_80215F14(2, 0x5622, 2, 0, 0, 0, path);
        if (lbl_8030A10C.slot[slot].obj != NULL) {
            lbl_8030A10C.slot[slot].owner = d->id;
            lbl_8030A10C.slot[slot].a = a;
            lbl_8030A10C.slot[slot].b = b;
            lbl_8030A10C.slot[slot].kind = c;
            return 1;
        }
        lbl_8030A10C.slot[slot].owner = -1;
        return -1;
    }
    return 0;
}

s8 fn_8003F5B8(ChrTask* t, s16 a, s16 b, s16 c, s16 d)
{
    ChrInfo* info = t->work->info;
    s8 r;
    if (!(info->xf0 & 0x20)) {
        return 0;
    }
    if (info->xf0 & 0x8000) {
        info->xf0 &= ~0x20;
        return 0;
    }
    switch (a) {
    case 0x15:
    case 0x16: {
        s8 x = fn_8003F890(a, d, 6, t);
        r = (info->x50 & 0x800000) ? 0 : fn_8003F890(c, d, 0, t);
        if (r < 0 || x < 0) {
            r = -1;
        } else {
            r = r + x;
        }
        break;
    }
    case 0x10:
    case 0x17: {
        s8 y;
        r = fn_8003F890(c, d, 0, t);
        y = fn_8003F890(0x10, d, 7, t);
        if (r < 0 || y < 0) {
            r = -1;
        } else {
            r = r + y;
        }
        break;
    }
    case 0x11:
        r = fn_8003F890(a, -1, 8, t);
        break;
    case 0x18:
        if (b == 0x3c) {
            fn_8003E1BC();
            lbl_8030A10C.owner = info->id;
            lbl_8030A10C.data[0] = 0;
            r = 1;
        } else {
            r = fn_8003F890(a, b, 1, t);
        }
        break;
    case 0x1d:
        switch (fn_800153E0(0x1d, b)) {
        case 0:
            r = fn_8003F890(a, b, 2, t);
            break;
        case 1:
            r = fn_8003F890(c, d, 0, t);
            break;
        case 2:
            fn_8003F890(a, b, 2, t);
            r = fn_8003F890(c, d, 0, t);
            break;
        }
        break;
    case 0xe:
        r = fn_8003F890(a, b, 3, t);
        break;
    case 0x1a:
    case 0x1b:
    case 0x1c:
        r = fn_8003F890(a, b, 4, t);
        break;
    case 0x1e:
        r = fn_8003F890(a, b, 5, t);
        break;
    case 0x14:
        r = fn_8003F890(a, b, 9, t);
        break;
    default:
        r = 0;
        break;
    }
    if (r >= 0) {
        info->xf0 &= ~0x20;
    }
    return r;
}

s16 fn_8003F484(ChrTask* arg)
{
    ChrWork* w = arg->work;
    ChrInfo* info = w->info;
    s16 r;
    switch (fn_80020E10(w->res->name)) {
    case -1:
        switch (info->x2) {
        case 0x84:
        case 0x97:
            return 0x1644;
        case 0x8c:
        case 0x98:
            return 0x1645;
        default:
            return -1;
        }
    case 0: r = 0x99; break;
    case 1: r = 0xfd; break;
    case 2: r = 0x161; break;
    case 3: r = 0x1c5; break;
    case 4: r = 0x229; break;
    case 5: r = 0x28d; break;
    }
    switch (info->x6) {
    case 0x1b:
        break;
    case 0x1c:
        r += 4;
        break;
    default:
        r = r + 1 + fn_8025ECC4() % 3;
        break;
    }
    return r;
}

s16 fn_8003F3F0(ChrTask* arg)
{
    s16 r;
    switch (fn_80020E10(arg->work->res->name)) {
    case -1: return -1;
    case 0: r = 0x98; break;
    case 1: r = 0xfc; break;
    case 2: r = 0x160; break;
    case 3: r = 0x1c4; break;
    case 4: r = 0x228; break;
    case 5: r = 0x28c; break;
    }
    return r;
}

s16 fn_8003F358(ChrTask* arg)
{
    switch (fn_80020E10(arg->work->res->name)) {
    default: return -1;
    case 0: return 0x97;
    case 1: return 0xfb;
    case 2: return 0x15f;
    case 3: return 0x1c3;
    case 4: return 0x227;
    case 5: return 0x28b;
    }
}

s16 fn_8003F2C0(ChrTask* arg)
{
    switch (fn_80020E10(arg->work->res->name)) {
    default: return -1;
    case 0: return 0x96;
    case 1: return 0xfa;
    case 2: return 0x15e;
    case 3: return 0x1c2;
    case 4: return 0x226;
    case 5: return 0x28a;
    }
}

s16 fn_8003F228(ChrTask* arg)
{
    switch (fn_80020E10(arg->work->res->name)) {
    default: return -1;
    case 0: return 0x8d;
    case 1: return 0xf1;
    case 2: return 0x155;
    case 3: return 0x1b9;
    case 4: return 0x21d;
    case 5: return 0x281;
    }
}

int fn_8003ECF4(char* out, s16 a, s16 b, ChrTask* t, s8 kind)
{
    char ext[8];
    ChrInfo* info = t->work->info;
    s16 r;

    fn_8025F120(ext, ".P04");
    switch (kind) {
    case 0:
        fn_8025CB24(out, "KO%04dS%s", b, ext);
        return 1;
    case 1:
        if (fn_80008AB4(t->work->res->x30, a, b, 0x3B, 3, 2, info->x298) == 0) {
            break;
        }
        switch (a) {
        case 0x18:
            if (b == 0x3D) {
                fn_8025CB24(out, "%03dS%s", PartyVoice() * 100 + 461, ext);
            } else {
                fn_8025CB24(out, "KO%04dS%s", b, ext);
            }
            return 1;
        }
        return 0;
    case 2:
    case 3:
    case 4:
    case 5:
    case 9:
        if (fn_80008AB4(t->work->res->x30, a, b, 0x3B, 3, 2, info->x298) == 0) {
            break;
        }
        switch (a) {
        case 29:
            r = fn_8003E7A4(b);
            if (r < 0) {
                return 0;
            }
            fn_8025CB24(out, "B702%04dS%s", r, ext);
            return 1;
        case 14:
            fn_8025CB24(out, "B702%04dS%s", VoiceA(t), ext);
            return 1;
        case 20:
            r = fn_8003F3F0(t);
            if (r < 0) {
                return 0;
            }
            fn_8025CB24(out, "%3dS%s", r, ext);
            return 1;
        case 26:
        case 27:
        case 28:
            r = fn_8003F484(t);
            if (r < 0) {
                return 0;
            }
            if (r >= 5000) {
                fn_8025CB24(out, "B702%dS%s", r, ext);
            } else {
                fn_8025CB24(out, "%3dS%s", r, ext);
            }
            return 1;
        case 30:
            fn_8025CB24(out, "B702%04dS%s", VoiceB(t), ext);
            return 1;
        }
        return 0;
    case 6:
        r = fn_8003F358(t);
        if (r < 0) {
            return 0;
        }
        fn_8025CB24(out, "%3dS%s", r, ext);
        return 1;
    case 7:
        r = fn_8003F2C0(t);
        if (r < 0) {
            return 0;
        }
        fn_8025CB24(out, "%3dS%s", r, ext);
        return 1;
    case 8:
        r = fn_8003F228(t);
        if (r < 0) {
            return 0;
        }
        fn_8025CB24(out, "%3dS%s", r, ext);
        return 1;
    }
    return 0;
}

void fn_8003EBE0(ChrTask* arg)
{
    ChrTask* a = arg;
    ChrWork* w = a->work;
    ChrInfo* info = w->info;
    if (fn_80020700(info->x6, info->x8, arg) == 0 && info->x6 != 0x15 && info->x6 != 0x16
        && info->x10 != 0x17 && info->x10 != 0x10) {
        return;
    }
    {
        s8 i;
        for (i = 0; i < 2; i++) {
            if (lbl_8030A10C.slot[i].owner == info->id && lbl_8030A10C.slot[i].obj != 0 && lbl_8030A10C.slot[i].kind == 0) {
                Task* t;
                fn_80215F94(lbl_8030A10C.slot[i].obj);
                t = fn_802268E8(lbl_803475A8, fn_8003EB1C);
                fn_80061F58(&t->work, 1, 0);
                *(s8*)t->work = i;
                return;
            }
        }
    }
}

void fn_8003EB1C(Task* node)
{
    SndSlot* s = lbl_8030A10C.slot;
    s8* idx = node->work;
    if (s[*idx].obj != 0 && fn_80216F48(s[*idx].obj) == 0) {
        s[*idx].obj = 0;
        lbl_8030A10C.slot[*idx].owner = -1;
    }
    if (s[*idx].obj == 0) {
        node->flags |= 0x40;
    }
}

s16 fn_8003E7A4(s16 id)
{
    s16 tbl[29] = {0x19C8, 0x17D4, 0x17D5, 0x1900, 0x1770, 0x1771, 0x1772, 0x1773, 0x1A90, 0x1A91, 0x1A2C, 0x1A2E, 0x1964, 0x1965, 0x1966, 0x1966, 0x1966, 0x1838, 0x1839, 0x183A, 0x183B, 0x183C, 0x189C, 0x189D, 0x189E, 0x189F, 0x18A0, 0x0, 0x17D5};
    switch (id) {
    case 210: case 211: case 212: case 213: return 100;
    case 64: return 201;
    case 40: return 200;
    case 20: case 37: return 300;
    case 63: return 301;
    case 47: return 302;
    case 270: case 271: return 400;
    case 162: return 502;
    case 22: return 503;
    case 70: return 500;
    case 71: return 501;
    case 28: case 29: case 49: case 50: case 62: case 68: case 69: case 73: case 78: case 82: case 87: case 88: case 89: case 200: case 201: return 600;
    case 98: case 106: case 107: case 108: case 109: case 110: case 111: case 113: case 115: return 601;
    case 67: return 604;
    case 114: return 605;
    case 74: return 602;
    case 97: return 700;
    case 96: return 701;
    case 13: return 800;
    case 39: return 900;
    case 56: case 75: return 901;
    case 181: return 1003;
    case 51: return 1004;
    case 180: return 1000;
    case 182: return 1002;
    case 53: case 66: case 183: case 184: return 1001;
    case 92: case 93: return 1100;
    case 170: return 1200;
    case 15: case 52: return 1300;
    case 1: return 1400;
    case 191: return 1500;
    case 250: case 251: return 1600;
    case 38: return 1700;
    case 12: return 1800;
    case 26: return 1900;
    case 260: return 2000;
    case 190: return 2100;
    case 4: return 2200;
    case 31: return 2201;
    case 32: case 33: return 2202;
    case 61: return 2203;
    case 44: return 2300;
    case 57: return 2301;
    case 41: return 2400;
    case 72: case 81: return 2500;
    case 79: case 80: return 2501;
    case 9: return 2600;
    case 160: return 2601;
    case 34: return 2602;
    case 55: return 2603;
    case 58: return 2604;
    case 21: return 2700;
    case 19: return 2701;
    case 100: return 2800;
    case 99: return 2900;
    case 17: return 3000;
    case 220: return 3100;
    case 27: return 3200;
    case 43: case 90: return 3300;
    case 48: return 3400;
    case 45: case 94: return 3500;
    case 83: return 3600;
    case 84: return 3700;
    case 0: return 3900;
    case 54: case 59: return 4000;
    case 30: return 4100;
    case 42: return 4200;
    case 7: return 4300;
    case 8: return 4301;
    case 36: return 4400;
    case 23: return 4500;
    case 24: return 4600;
    case 5: return 4700;
    case 65: return 4800;
    case 46: return 4801;
    case 86: return 4802;
    case 60: return 4900;
    case 25: return 5000;
    case 11: case 119: return 5100;
    case 2: return 5200;
    case 230: return 5300;
    case 76: return 5400;
    case 77: return 5800;
    default:
        if (id >= 0x118 && id <= 0x134) return tbl[id - 0x118];
        return -1;
    }
}

s16 fn_8003E624(void)
{
    s8 i;
    s8 b = 0;
    s8 a = 0;
    for (i = 0; i < 12; i++) {
        if (lbl_80309700[i] != 0) {
            SndId* id = lbl_80309700[i]->id;
            char name[0x20];
            fn_800308FC(name, id->x2, id->x0);
            switch (fn_80020E10(name)) {
            case 4:
                a = 2;
                break;
            case 5:
                a = 4;
                break;
            }
            switch (fn_80008274(id->x2)) {
            case 132: b = 6; break;
            case 151: b = 6; break;
            case 155: b = 0xc; break;
            case 145: case 146: b = 0xc; break;
            case 147: b = 0xe; break;
            case 140: case 152: case 153: b = 0x12; break;
            case 157: b = 0x18; break;
            case 141: b = 0x1a; break;
            case 149: b = 0x1c; break;
            case 158: case 163: case 168: case 173: b = 0x22; break;
            case 178: case 183: case 188: b = 0x28; break;
            case 193: b = 0x2e; break;
            case 198: case 208: b = 0x34; break;
            case 213: case 218: case 223: b = 0x3a; break;
            case 233: b = 0x40; break;
            case 238: b = (a == 4) ? 0x1c : 0x46; break;
            }
            if (b != 0) i = 14;
        }
    }
    return a + b;
}

s16 fn_8003E4CC(void)
{
    s8 b = 0;
    s8 a = 0;
    s8 i;
    for (i = 0; i < 4; i++) {
        switch (lbl_8030B7F4.x328[i]) {
        case 4:
            a = 2;
            i = 99;
            break;
        case 5:
            a = 4;
            i = 99;
            break;
        }
    }
    switch (fn_80077E34()) {
    case 4: b = 6; break;
    case 23: b = 6; break;
    case 27: b = 0xc; break;
    case 17: case 18: b = 0xc; break;
    case 19: b = 0xe; break;
    case 12: case 24: case 25: b = 0x12; break;
    case 29: b = 0x18; break;
    case 13: b = 0x1a; break;
    case 21: b = 0x1c; break;
    case 30: case 35: case 40: case 45: b = 0x22; break;
    case 50: b = 0x28; break;
    case 65: b = 0x2e; break;
    case 70: b = 0x34; break;
    case 85: b = 0x3a; break;
    case 105: b = 0x40; break;
    case 110: b = (a == 4) ? 0x1c : 0x46; break;
    }
    return a + b;
}

void fn_8003E464(char* buf)
{
    s16 n = fn_8003E4CC();
    fn_8025CB24(buf, "/SOUND/STV%02d.SAMP", (s16)(n + fn_8025ECC4() % 2));
}

void fn_8003E2B4(SampTask* node)
{
    SampWork* work = node->work;
    switch (node->state) {
    case 0:
        node->state = 1;
    case 1:
        fn_8025CB24(work->path, "/SOUND/%s", work->name[work->idx]);
        work->handle = fn_801CC1B4(work->path);
        node->state = 2;
        break;
    case 2:
        if (fn_801CC1A4(work->handle) == 1) {
            work->data = fn_801CC0A0(work->handle);
            lbl_8030A10C.data[work->idx] = work->data;
            lbl_8030A10C.size[work->idx] = 0x20;
            fn_8025F120(lbl_8030A10C.sampName[work->idx], work->path);
            if (work->flags & 0x80000000) {
                fn_80218D84(work->path, work->data, 0x20);
                if ((work->flags & 0x40000000) && work->idx == 0) {
                    work->idx++;
                    node->state = 1;
                } else {
                    node->state = 3;
                }
            } else {
                if ((work->flags & 0x40000000) && work->idx == 0) {
                    work->idx++;
                    node->state = 1;
                } else {
                    node->state = 3;
                }
            }
        }
        break;
    case 3:
        lbl_8030A10C.flags &= 0x7FFFFFFF;
        node->flags |= 0x40;
        break;
    }
}

void fn_8003E1BC(void)
{
    s8 buf[28];
    u8 found = 0;
    s8 i;
    SampTask* node = (SampTask*)fn_802268E8(lbl_803475A8, fn_8003E2B4);
    fn_80061F58(&node->work, 0xac, 0);
    fn_8025F120(node->work->name[0], "CR000.SAMP");
    node->work->flags |= 0x80000000;
    node->work->flags |= 0x40000000;
    fn_80073B48(buf);
    for (i = 0; i < 22; i++) {
        if (buf[i] < 0) break;
        if (buf[i] < 11) found |= 1;
    }
    fn_8025F120(node->work->name[1], (found & 1) == 0 ? "CR101.SAMP" : "CR100.SAMP");
}

void fn_8003E0F4(s8 a, s8 b)
{
    SampTask* node = (SampTask*)fn_802268E8(lbl_803475A8, fn_8003E2B4);
    fn_80061F58(&node->work, 0xac, 0);
    fn_8025CB24(node->work->name[0], "CR%03d.SAMP", a);
    lbl_8030A10C.flags |= 0x80000000;
    if (b >= 0) {
        node->work->flags |= 0x40000000;
        fn_8025CB24(node->work->name[1], "CR%03d.SAMP", b);
    }
}

void fn_8003E084(void)
{
    SampTask* node = (SampTask*)fn_802268E8(lbl_803475A8, fn_8003E2B4);
    fn_80061F58(&node->work, 0xac, 0);
    fn_8025F120(node->work->name[0], "B7000000.SAMP");
    lbl_8030A10C.flags |= 0x80000000;
}

void fn_8003DFE0(void)
{
    s8 i;
    for (i = 0; i < 1; i++) {
        if (lbl_8030A10C.data[i] != 0) {
            fn_80218D84(lbl_8030A10C.sampName[i], lbl_8030A10C.data[i], (lbl_8030A10C.size[i] + 0x1F) & ~0x1F);
            lbl_8030A10C.data[i] = 0;
            lbl_8030A10C.size[i] = 0;
        }
    }
    lbl_8030A10C.owner = -1;
}

void fn_8003DEE0(void)
{
    s16 n = fn_8003E624();
    s8 i;
    SampTask* node;
    if (lbl_8030A10C.flags & 0x1000) {
        lbl_8030A10C.flags &= ~0x1000;
        n++;
    } else {
        lbl_8030A10C.flags |= 0x1000;
    }
    for (i = 0; i < 2; i++) {
        if (lbl_8030A10C.slot[i].obj != 0) fn_80217830(lbl_8030A10C.slot[i].obj);
    }
    node = (SampTask*)fn_802268E8(lbl_803475A8, fn_8003E2B4);
    fn_80061F58(&node->work, 0xac, 0);
    fn_8025CB24(node->work->name[0], "STV%02d.SAMP", n);
    lbl_8030A10C.flags |= 0x80000000;
    node->work->flags |= 0x80000000;
}
