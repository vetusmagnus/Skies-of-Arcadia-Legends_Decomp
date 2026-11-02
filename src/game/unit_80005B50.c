#include "types.h"
#include "ninja.h"
#include "game/drawstate.h"
#include <dolphin/os.h>
#include <dolphin/dvd.h>
#include "game/task.h"
#include "game/save_8030B7F4.h"
#include "game/stat_8030B4D4.h"
#include "game/gamedata.h"
#include <string.h>
#include "game/unit_80005B50.h"
#define PTR(p, off) (*(void**)((u8*)(p) + (off)))
extern void fn_8007E13C(void* a);
extern void fn_8007E118(void* a);
extern void fn_8007DFC0(void* a);
extern void fn_8007DEE0(void* a);
extern void fn_8001FE44(void* a);
s32 fn_800090F8(s32 packed, s16* p);
extern void* fn_801E1C7C(u32 size);
extern void fn_801E17E0(void* p);
typedef struct {
    u16 x0;
    u8 pad2[6];
    u32 x8;
    u8 padc[0x18 - 0xc];
    s32 x18;
    f32 x1c;
    int cur;
    int pad24;
    Ent_BB28* tbl;
} Sys_80309E5C;
extern Sys_80309E5C lbl_80309E5C;
extern Task* lbl_80347394;
extern s32 lbl_8034733C;
extern void fn_8028AB48(void);
extern void fn_802A9B94(s32 a, s32 b, s32 c, void (*f)(void));
extern s32 lbl_803478A0;
extern s32* lbl_803478A4;
extern DVDFileInfo *lbl_803478DC;
/* A linked condition record (fn_800085EC walks the list). */
typedef struct CondLink {
    s16 x0;
    s16 x2;
    s16 x4;                 /* 0x4: first table index (fn_8000832C) */
    s16 x6;                 /* 0x6: end index */
    struct CondLink* next;  /* 0x8 */
    struct CondLink* prev;  /* 0xc */
} CondLink;
typedef struct {
    u8 pad0[0xc];
    void* xc;           /* 0x0c */
    void* x10;
    s8 x14[9][9];       /* 0x14 party grid */
    u8 pad65[0x68 - 0x65];
    void* x68;
    u32 x6c;
    u8 pad70[0xec - 0x70];
    f32 xec;            /* 0xec speed scale */
    s16 xf0;
    u8 padf2[0x180 - 0xf2];
    void* x180;         /* 0x180 */
    void* x184;         /* 0x184 */
    u8 pad188[0x1c4 - 0x188];
    s32 x1c4;
} GS;
extern GS lbl_8030A10C;
typedef struct ChrMot {
    u8 pad0[4];
    u32 x4;
} ChrMot;
/* One motion entry of a character (0x18 bytes). */
typedef struct ChrAnim {
    s16 x0;
    s16 x2;             /* 3 ends the table */
    s16 x4;
    s16 x6;
    u32 flags;
    s16 xc;
    s16 xe;
    f32 x10;
    f32 x14;
} ChrAnim;
/* A character's draw parameters (fn_80018B80 turns them into a DrawState). */
typedef struct ChrDraw {
    f32 a;              /* 0x00 colour */
    f32 r;
    f32 g;
    f32 b;
    u8 pad10[8];
    s32 blend_src;      /* 0x18 */
    s32 blend_dst;      /* 0x1c */
    u8 pad20[8];
    s32 x28;            /* 0x28: not 1 clears control3d 0x40 */
    s32 fog;            /* 0x2c */
    s32 x30;            /* 0x30: nonzero calls fn_80060950 */
} ChrDraw;
/* One 0x34-byte joint of a character's skeleton (ChrInfo 0x154). */
typedef struct Joint { u8 pad[8]; u8 data[0x34 - 8]; } Joint;
typedef struct ChrInfo {
    s8 id;              /* 0x00 */
    u8 pad1;
    s16 x2;             /* 0x02 kind */
    s8 target;          /* 0x04 */
    u8 pad5;
    s16 x6;             /* 0x06 */
    s16 x8;             /* 0x08 */
    u8 padA[8];
    s16 state;          /* 0x12 */
    s16 x14;            /* 0x14 */
    s16 x16;            /* 0x16 */
    s16 x18;            /* 0x18 */
    s16 x1a;            /* 0x1a */
    s16 x1c;            /* 0x1c previous action */
    u8 pad_1e[2];
    s16 x20;            /* 0x20 */
    u8 pad22[6];
    s8 x28[10];         /* 0x28 recent ids, -1 = free */
    u8 pad32[0x44 - 0x32];
    u32 x44;            /* 0x44 status bits */
    s8 x48;             /* 0x48 */
    u8 pad_49;
    s16 x4a;            /* 0x4a */
    s16 x4c;            /* 0x4c */
    u8 pad4e[2];
    u32 x50;            /* 0x50 draw flags */
    u8 pad54[0x8];
    ChrMot* x5c;        /* 0x5c */
    void* x60;          /* 0x60 */
    s16 x64;            /* 0x64 */
    u8 pad66[2];
    f32 x68;            /* 0x68 */
    f32 x6c;            /* 0x6c frame step */
    s32 x70;            /* 0x70 */
    u8 x74[0x10];       /* 0x74 */
    u8 x84[0x10];       /* 0x84 */
    u8 pad94[0xdc - 0x94];
    ChrAnim* anims;     /* 0xdc */
    s32 xe0;            /* 0xe0 */
    s16 xe4;            /* 0xe4 */
    s16 xe6;            /* 0xe6 */
    s16 xe8;            /* 0xe8 */
    s16 xea;            /* 0xea */
    u32 xec;            /* 0xec */
    u32 xf0;            /* 0xf0 */
    u32 xf4;            /* 0xf4 */
    NJS_POINT3 pos;     /* 0xf8 */
    f32 x104[3];        /* 0x104 */
    NJS_POINT3 x110;    /* 0x110 target */
    f32 x11c;           /* 0x11c turn from */
    f32 x120;           /* 0x120 turn to */
    f32 x124;           /* 0x124 turn step */
    f32 x128;           /* 0x128 turn speed */
    f32 x12c;
    f32 x130;
    s32 x134;           /* 0x134 */
    s16 x138;           /* 0x138 */
    u8 pad13a[2];
    NJS_POINT3 x13c;    /* 0x13c saved pos */
    Angle x148[3];      /* 0x148 saved angles */
    Joint* x154;        /* 0x154 joints */
    u8 pad158[0x15c - 0x158];
    f32 x15c;           /* 0x15c */
    f32 x160;           /* 0x160 alpha */
    ChrDraw draw;       /* 0x164 */
    u8 pad198[0x1dc - 0x198];
    void* x1dc;         /* 0x1dc */
    u8 pad1e0[0x1ec - 0x1e0];
    u32 x1ec;           /* 0x1ec */
    u8 pad1f0[4];
    NJS_TEXLIST* x1f4;  /* 0x1f4 */
    s16 x1f8;           /* 0x1f8 timer */
    u8 pad1fa[2];
    void* x1fc;         /* 0x1fc matrix */
    u8 pad200[0x204 - 0x200];
    s16 x204;           /* 0x204 */
    u8 pad206[0x20c - 0x206];
    s16 x20c;           /* 0x20c */
    s16 x20e;           /* 0x20e */
    s16 x210;           /* 0x210 */
    s16 x212;           /* 0x212 */
    u8 pad214[0x264 - 0x214];
    f32 x264;           /* 0x264 overlay alpha (fn_80018868) */
    f32 x268;           /* 0x268 overlay scale */
    f32 x26c;
    f32 x270;
    f32 x274;           /* 0x274 overlay offset */
    f32 x278;
    f32 x27c;
    s32 x280;           /* 0x280 overlay angles */
    s32 x284;
    s32 x288;
    u8 x28c;            /* 0x28c rotation order */
    u8 pad28d[0x294 - 0x28d];
    s16 x294;           /* 0x294 texture variant */
    s8 x296;            /* 0x296 draw kind */
    u8 pad297;
    CondLink* x298;     /* 0x298 condition list (fn_800193B8) */
} ChrInfo;
/* Event-target object referenced by an id record (x0 type, x4 id, x10 result). */
typedef struct Key {
    s16 x0;
    s16 x2;
    s16 x4;
    u8 pad6[0x10 - 6];
    s16 x10;
} Key;
/* 0x10-byte id record; lists end at a negative x0. */
typedef struct Ent_80008800 {
    s16 x0;
    s16 x2;
    u8 pad4[8];
    Key* xc;
} Ent_80008800;
s32 fn_8000832C(Task* obj, Ent_80008800* tbl, CondLink* range);
s16 fn_800086BC(Task* t, s16 a, s16 b, Ent_80008800* tbl, CondLink* e, u8 f);
typedef struct Obj_80017B18 {
    u8 pad0[0xc];
    char xc[0x24];      /* 0x0c name */
    Ent_80008800 *x30;
    u8 pad34[0x40 - 0x34];
    f32 x40;            /* 0x40 cached height (fn_800177C0) */
} Obj_80017B18;
typedef struct ChrWork {
    void* x0;           /* 0x00 model */
    u8 pad4[4];
    NJS_TEXLIST* x8;    /* 0x08 */
    u8 padc[4];
    Obj_80017B18 *x10; /* 0x10 */
    s16 x14;            /* 0x14 */
    u8 pad16[0x1c - 0x16];
    NJS_POINT3 pos;     /* 0x1c */
    Angle rx, ry, rz;   /* 0x28 */
    NJS_POINT3 scl;     /* 0x34 */
    u8 pad40[4];
    u8 x44;             /* 0x44 */
    u8 pad45[0x48 - 0x45];
    NJS_TEXLIST* x48;   /* 0x48 */
    ChrInfo *st; /* 0x4c */
} ChrWork;
typedef struct Key7 {
    u16 x0;
    u8 x2;
    u8 x3;
    u8 x4;
    u8 x5;
    u8 x6;
} Key7;
int fn_8003DE8C(s16 type, s16 id, s16 wtype, s16 wid);

inline ChrWork* ChrW(Task* t)
{
    return t->work;
}
extern void fn_801E17E0(void *);
extern s16 fn_80009030(Ent_80008800* list, s16 p1, s16 p2, s16 c, s16 d);
extern s8 fn_80017A14(ChrInfo*);
extern int fn_80061F58(void*, int, int);
/* Packed date stamp filled from the RTC (OSGetTime). Field names are ours. */
typedef struct CalendarStamp {
    s16 year;
    u8 month;
    u8 day;
    u8 hour;
    u8 minute;
    u8 second;
    u8 weekday;
    u8 pad;
} CalendarStamp;
extern s32 fn_80007BFC(void* a, s32 b);
#define FLD(p, off, T) (*(T*)((u8*)(p) + (off)))
/* The original temporarily writes two halfwords in a shape record, calls fn_80008DF4, and restores them. */
typedef struct Rec {
    u8 pad[6];
    s16 x;
    s16 y;
} Rec;
typedef struct Mid {
    u8 pad[0x4c];
    Rec* rec;
} Mid;
typedef struct Ent8C00 {
    u8 pad[0x24];
    Mid* mid;
} Ent8C00;
extern void fn_80008DF4(Ent8C00* obj, s32 a, s32 b, s32 c);
typedef s32 Angle;
extern s32 lbl_803478B8;
extern s32 lbl_803478B4;
extern s32 lbl_803478B0;
extern s32 lbl_803478C0;
extern s32 lbl_803478C4;
extern u8* lbl_803478C8;
s32 DVDGetTransferredSize(DVDFileInfo* fileinfo);
extern void *memcpy(void *d, const void *s, u32 n);
typedef struct Ent_800095D0 { s32 a; s32 b; s32 size; s32 off; } Ent_800095D0;
typedef struct EntD { s32 a; s32 b; s32 size; void *data; } EntD;
extern void fn_80035918(void *p);
extern s16 fn_800364F4(void *p);
extern s32 fn_800364B8(void *e);
extern s16 fn_800089F0(Ent_80008800* t, s16 a, s16 b, s16* lo, s16* hi, s16 start);
typedef struct ArcInfo {
    s32 x0;
    s32 x4;
    u8 pad8[8];
    s32 x10;
    s32 x14;
} ArcInfo;
typedef struct ArcSlot {
    ArcInfo* info;
    s32 x4;
    s32 x8;
} ArcSlot;
typedef struct ArcSet {
    ArcSlot* slots;
} ArcSet;
typedef struct ArcHdr {
    s32 x0;
    s16 x4;
    s16 x6;
} ArcHdr;
extern void fn_80298E48(void);
extern s32 fn_80297558(ArcSet* set, s32 idx, u32* a, s32* b);
extern u32 fn_80298798(ArcHdr* hdr, s32* c, void* info);
extern s32 fn_80298A04(ArcSet* set, s32 idx, s32 c, s32 b, ArcHdr* hdr, s32* out);
extern s32 fn_80298BF8(s32 out, s32 x);
extern void fn_80298BCC(s32 out);
typedef struct { s32 a; s32 b; s32 err; } Err_803457F8;
extern Err_803457F8 lbl_803457F8;
extern s32 lbl_803478AC;
extern s32 lbl_80346738;
extern s32 lbl_803478D4;
extern s32 lbl_803478BC;
extern u8 *lbl_803478D8;
extern s32 lbl_803478D0;
extern s32 lbl_803478CC;
extern s32 lbl_803478A8;
extern int sprintf(char* s, const char* fmt, ...);
extern char* strcpy(char* d, const char* s);
typedef struct Inner_80007640 { s32 x0; u8 pad[0xc - 4]; s32 xc; } Inner_80007640;
typedef struct Mid_80007640 { u8 pad[0xc]; Inner_80007640 *xc; } Mid_80007640;
extern s32 fn_80298CAC(u32 v, s32 b, s32 c, s32 *out);
extern s32 fn_80298210(Mid_80007640 **a, Inner_80007640 **b);
extern void fn_80298C78(ArcSet *o, s32 idx, s32 v);
extern s32 lbl_80347EC4;
extern void fn_80061048(char* s);
extern void fn_80035FC0(char* name, void* slot, s32 flag);

/* Ninja motion node data with one to four channels: key arrays, then key counts. */
typedef struct { void* p[1]; u32 nb[1]; } NJS_MDATA1;
typedef struct { void* p[2]; u32 nb[2]; } NJS_MDATA2;
typedef struct { void* p[3]; u32 nb[3]; } NJS_MDATA3;
typedef struct { void* p[4]; u32 nb[4]; } NJS_MDATA4;
typedef void (*MotionInterpFn)(void* keys, u32 i, u32 nbKeys, void* out);
typedef struct {
    void* mdata;   /* 0x00 current node's NJS_MDATAn */
    void** keys;   /* 0x04 key array pointers for the node */
    u32* counts;   /* 0x08 key counts for the node */
    f32 frame;     /* 0x0C */
    u32 nbFrame;   /* 0x10 */
    s32 unk14;
    f32* matrix;   /* 0x18 extra matrix applied after each node, or NULL */
    s32 unk1C;
} MotionState;
extern MotionState lbl_80316940;
extern u16 lbl_8034789A;
extern u16 lbl_8034789C;
extern MotionInterpFn lbl_80346730[2];

/* Steps the motion cursor past the current node's NJS_MDATAn, then applies the extra matrix. */
void fn_80006CE0(void) {
    switch (lbl_8034789C) {
    case 1: {
        NJS_MDATA1* m = lbl_80316940.mdata;
        lbl_80316940.mdata = m + 1;
        break;
    }
    case 2: {
        NJS_MDATA2* m = lbl_80316940.mdata;
        lbl_80316940.mdata = m + 1;
        break;
    }
    case 3: {
        NJS_MDATA3* m = lbl_80316940.mdata;
        lbl_80316940.mdata = m + 1;
        break;
    }
    case 4: {
        NJS_MDATA4* m = lbl_80316940.mdata;
        lbl_80316940.mdata = m + 1;
        break;
    }
    }
    if (lbl_80316940.matrix != 0) {
        njMultiMatrix(0, lbl_80316940.matrix);
    }
}

s32 fn_80006F1C(s32* out, s32 type) {
    NJS_MKEY_F* keys;
    u32 count;
    u32 lo;
    u32 hi;
    u32 f;
    s32 idx = lbl_8034789A & 1;
    switch (lbl_8034789C) {
    case 1: {
        NJS_MDATA1* m = lbl_80316940.mdata;
        lbl_80316940.keys = m->p;
        lbl_80316940.counts = m->nb;
        break;
    }
    case 2: {
        NJS_MDATA2* m = lbl_80316940.mdata;
        lbl_80316940.keys = m->p;
        lbl_80316940.counts = m->nb;
        break;
    }
    case 3: {
        NJS_MDATA3* m = lbl_80316940.mdata;
        lbl_80316940.keys = m->p;
        lbl_80316940.counts = m->nb;
        break;
    }
    case 4: {
        NJS_MDATA4* m = lbl_80316940.mdata;
        lbl_80316940.keys = m->p;
        lbl_80316940.counts = m->nb;
        break;
    }
    }
    lo = 0;
    keys = lbl_80316940.keys[idx];
    count = lbl_80316940.counts[idx];
    hi = count;
    f = lbl_80316940.frame;
    while (hi - lo > 1) {
        u32 mid = (lo + hi) >> 1;
        if (f >= keys[mid].keyframe) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    if (keys != NULL) {
        lbl_80346730[type](keys, lo, count, out);
        return 1;
    }
    out[0] = 0;
    out[1] = 0;
    out[2] = 0;
    return 0;
}

void fn_800068C4(NJS_MKEY_F* keys, u32 i, u32 nbKeys, f32* out) {
    NJS_MKEY_F* k1 = &keys[i];
    f32 div[2] = {1.0f, 1.0f};
    NJS_MKEY_F* k0 = &keys[(i + nbKeys - 1) % nbKeys];
    NJS_MKEY_F* k2 = &keys[(i + 1) % nbKeys];
    NJS_MKEY_F* k3 = &keys[(i + 2) % nbKeys];
    f32 t, t2, t3;
    f32 c0, c1, c2, c3;

    div[1] = (f32)(k2->keyframe - k1->keyframe);
    t = (lbl_80316940.frame - (f32)k1->keyframe) / div[(s32)(k2->keyframe - k1->keyframe) > 0];
    t2 = t * t;
    t3 = t2 * t;
    c0 = 0.5f * (-t3 + 2.0f * t2 - t);
    c1 = 1.5f * t3 - 2.5f * t2 + 1.0f;
    c2 = -1.5f * t3 + 2.0f * t2 + 0.5f * t;
    c3 = 0.5f * (t3 - t2);
    out[0] = c0 * k0->key[0] + c1 * k1->key[0] + c2 * k2->key[0] + c3 * k3->key[0];
    out[1] = c0 * k0->key[1] + c1 * k1->key[1] + c2 * k2->key[1] + c3 * k3->key[1];
    out[2] = c0 * k0->key[2] + c1 * k1->key[2] + c2 * k2->key[2] + c3 * k3->key[2];
}

extern void fn_802A9338(s32 a, s32 b, s32 c, void (*f)(void));
void fn_80006A70(NJS_MKEY_A* keys, u32 i, u32 nbKeys, Angle* out) {
    f32 div[2] = {1.0f, 1.0f};
    NJS_MKEY_A* k1 = &keys[i];
    NJS_MKEY_A* k2 = &keys[(i + 1) % nbKeys];
    f32 t;
    f32 u;

    div[1] = (f32)(k2->keyframe - k1->keyframe);
    t = (lbl_80316940.frame - (f32)k1->keyframe) / div[(s32)(k2->keyframe - k1->keyframe) > 0];
    u = 1.0f - t;
    out[0] = k1->key[0] * u + k2->key[0] * t;
    out[1] = k1->key[1] * u + k2->key[1] * t;
    out[2] = k1->key[2] * u + k2->key[2] * t;
}

extern u16 lbl_80347898;

void fn_800071D8(NJS_MOTION* m, f32 frame) {
    if (m != NULL) {
        if (frame >= m->nbFrame) {
            return;
        }
        lbl_8034789C = m->inp_fn & ~0xC0;
        lbl_80347898 = (m->inp_fn & 0xC0) > 0;
        lbl_8034789A = m->type;
        lbl_80316940.mdata = m->mdata;
        lbl_80316940.nbFrame = m->nbFrame;
    } else {
        lbl_8034789C = 0;
        lbl_80347898 = 0;
        lbl_8034789A = 0;
    }
    lbl_80316940.frame = frame;
    lbl_80316940.unk14 = 0;
    lbl_80316940.matrix = NULL;
}

void fn_800072A8(s32 a, s32 b, s32 c)
{
    fn_802A9338(a, b, c, fn_8028AB48);
}

extern void fn_80287C14(void);
void fn_800072D0(s32 a, s32 b, s32 c)
{
    fn_802A9B94(a, b, c, fn_80287C14);
}

void fn_800072F8(s32 a, s32 b, s32 c)
{
    fn_802A9338(a, b, c, fn_80287C14);
}

extern void fn_802873BC(void);
void fn_80007320(s32 a, s32 b, s32 c)
{
    fn_802A9B94(a, b, c, fn_802873BC);
}

void fn_80007348(s32 a, s32 b, s32 c)
{
    fn_802A9338(a, b, c, fn_802873BC);
}

extern void fn_802890A4(void);
void fn_80007370(s32 a, s32 b, s32 c)
{
    fn_802A9B94(a, b, c, fn_802890A4);
}

void fn_80007398(s32 a, s32 b, s32 c)
{
    fn_802A9338(a, b, c, fn_802890A4);
}

void fn_80008170(void);
extern NjTexRef* lbl_80347ED4;
extern char lbl_80348060[5];
extern char lbl_80348068[5];
extern char lbl_802DADC0[];
extern void fn_80298034(char* out, ArcInfo* info, char* ext);
extern s32 fn_80008194(char* name);
s32 fn_80008258(s32* out);
void fn_80007514(s32** buf, s32* size);
s32 fn_8000810C(void* a, s32 b);
s32 fn_800079AC(ArcSet* set, s32 idx) {
    char name[256];
    char path[256];
    ArcHdr hdr;
    s32 n;
    s32 c;
    u32 a;
    s32 b;
    s32 out;
    s32* ptr;
    s32 m;
    s32 r;
    fn_80298E48();
    r = fn_80297558(set, idx, &a, &b);
    if (r != 0) return r;
    fn_80298034(path, set->slots[idx].info, lbl_80348060);
    strcpy(name, lbl_802DADC0);
    strcat(name, path);
    if (fn_80008194(name) < 0) {
        fn_80298034(path, set->slots[idx].info, lbl_80348068);
        strcpy(name, lbl_802DADC0);
        strcat(name, path);
        if (fn_80008194(name) < 0) {
            lbl_803457F8.err = 2;
            return -1;
        }
    }
    fn_80008258(&n);
    fn_80007514(&ptr, &m);
    if (m < n) {
        fn_80008170();
        return -1;
    }
    if (fn_8000810C(ptr, 0x20) < 0) {
        fn_80008170();
        lbl_803457F8.err = 5;
        return -1;
    }
    if (fn_80298798(&hdr, &c, ptr) == 0) return -1;
    if (*ptr == 0x47434958) { /* "GCIX" */
        if (a != -1) c = a;
        r = fn_80298A04(set, idx, c, b, &hdr, &out);
        if (r != 0) return r;
        if (fn_8000810C(lbl_80347ED4[out].mem->body.data, lbl_80347ED4[out].mem->body.size) < 0) {
            fn_80008170();
            fn_80298BCC(out);
            set->slots[idx].x4 &= ~0x200000;
            set->slots[idx].x8 = 0;
            lbl_803457F8.err = 8;
            return -1;
        }
        fn_80008170();
    } else {
        return -1;
    }
    return 1;
}

void fn_80008170(void) {
    DVDClose(lbl_803478DC);
}

s32 fn_80008C68(s32 key, Task* obj);
extern s32 fn_800367E8(s32 key, Ent_80008800* e, Task* obj);
extern s32 fn_8003732C(s32 key, Ent_80008800* e, Task* obj);
static inline s32 CmdAllowed(Task* obj, s16 id, s16 g) {
    s16 grp = lbl_8030A10C.xf0;
    ChrInfo* work = ChrW(obj)->st;
    if (grp != 0 && g != grp) {
        switch (id) {
        case 0x36:
            return 1;
        default:
            return 0;
        }
    }
    if (work->xf0 & 0x8000) {
        switch ((g << 16) | id) {
        case 0x30009:
        case 0x3001F:
        case 0x3002A:
        case 0x30036:
        case 0x3003B:
        case 0x30042:
        case 0x30058:
            return 0;
        }
    }
    return 1;
}
s32 fn_8000832C(Task* obj, Ent_80008800* tbl, CondLink* range) {
    Ent_80008800* e;
    s32 count = 0;
    s16 i = 0;
    s32 v;
    s32 key;
    if (range != 0) i = range->x4;
    if (tbl != 0) {
        e = &tbl[i];
        do {
            s16 id = e->x0;
            s16 g = e->x2;
            if (id < 0) break;
            if (CmdAllowed(obj, id, g) != 0) {
                key = (g << 16) | id;
                v = 0;
                if (fn_80008C68(key, obj) == 0) {
                    v = 0;
                } else {
                    switch (key) {
                    case 0x30007:
                    case 0x30032:
                    case 0x30041:
                    case 0x3004E:
                        break;
                    default:
                        v = fn_800367E8(key, e, obj);
                        break;
                    }
                }
                if (v == 0) v = fn_8003732C(key, e, obj);
                if (v != 0) count++;
            }
            e++;
            i++;
        } while (range == 0 || i < range->x6);
    }
    return count;
}

static inline s16 EntScore(Task* a, Ent_80008800* d, CondLink* e)
{
    return fn_8000832C(a, d, e);
}
s16 fn_80008530(Task* a, s16 b, s16 c, Ent_80008800* d, CondLink* p) {
    CondLink* cur = p;
    s16 sum = 0;
    if (p == NULL) {
        return fn_800086BC(a, b, c, d, 0, 0);
    }
    while (cur != NULL) {
        if (fn_8003DE8C(cur->x0, cur->x2, b, c) != 0) {
            sum += (cur != NULL) ? EntScore(a, d, cur) : fn_8000832C(a, d, 0);
        }
        cur = cur->next;
    }
    return sum;
}

s16 fn_800085EC(Task* a, s16 b, s16 c, Ent_80008800* d, CondLink* p) {
    CondLink* cur = p;
    s16 sum = 0;
    if (p == NULL) {
        return fn_800086BC(a, b, c, d, 0, 0);
    }
    while (cur != NULL) {
        if (fn_8003DE8C(cur->x0, cur->x2, b, c) != 0) {
            sum += fn_800086BC(a, b, c, d, cur, 0);
        }
        cur = cur->next;
    }
    return sum;
}

CondLink* fn_80008938(Ent_80008800* t, s16 a, s16 b) {
    CondLink* out = 0;
    s16 lo;
    s16 hi;
    if (t != 0) {
        if (fn_800089F0(t, a, b, &lo, &hi, 0) != 0) {
            if (fn_80061F58(&out, 0x10, 0) != 0) {
                out->x0 = a;
                out->x2 = b;
                out->x4 = lo;
                out->x6 = hi;
                return out;
            }
            return 0;
        }
        return 0;
    }
    return 0;
}

extern f32 lbl_80348070;
extern s32 fn_80014C90(s8 id, s32 flags);

s32 fn_80008C68(s32 key, Task* obj) {
    ChrInfo* w = ChrW(obj)->st;
    u32 flags;

    if (w->id >= 12) return 1;
    if (fn_80017A14(w) == 2) {
        switch (key) {
        case 0x3000E:
            return 0;
        }
    }
    flags = w->xec;
    if (flags & 8) {
        switch (key) {
        case 0x30055:
            return 0;
        }
    }
    if (flags & 0x100000) {
        switch (key) {
        case 0x30036:
            return w->draw.a > lbl_80348070;
        case 0x30004:
            return 1;
        case 0x3000E:
            if (lbl_80347394 != 0) return 1;
            if (fn_80014C90(w->id, 0x800) != 0) return 0;
            break;
        }
        return 0;
    }
    if (fn_80014C90(w->id, 0x800) != 0 && lbl_8034733C != 7) {
        switch (key) {
        case 0x3000E:
            return 0;
        }
    }
    return 1;
}

void fn_800091A4(s16* p) {
    s16 x = p[0];
    s16 y = p[1];
    if (x >= 0) {
        fn_800090F8((y << 16) | x, p);
    }
}

typedef struct Slot1C {
    s32 id;
    s32 x4;
    u8 pad8[0x10];
    s32 x18;
} Slot1C;

extern u32 fn_8006E810(s32 id);

s32 fn_80009500(Slot1C* tbl, s32 id, s32 val)
{
    s16 i = 0;
    Slot1C* s;
    s32 v;

    if (fn_8006E810(id) == 0) goto set;
    return 0;
loop:
    while ((v = s->id) > 0) {
        if (id == v) return 0;
        i++;
        s++;
        if (i >= 0x80) return 0;
    }
    tbl[i].id = id;
    tbl[i].x4 = 0;
    tbl[i].x18 = val;
    tbl[i + 1].id = -1;
    return 1;
set:
    s = tbl;
    goto loop;
}

extern int sprintf(char* s, const char* fmt, ...);
s16 fn_80008530(Task* a, s16 b, s16 c, Ent_80008800* d, CondLink* p);

void fn_80007280(s32 a, s32 b, s32 c)
{
    fn_802A9B94(a, b, c, fn_8028AB48);
}

void fn_80007514(s32 **a, s32 *b)
{
    *b = lbl_803478A0;
    *a = lbl_803478A4;
}

s32 fn_80008258(s32 *out)
{
    u32 n = lbl_803478DC->length;
    *out = (n + 0x1f) & ~0x1fu;
    return 1;
}

void fn_80008308(Task* a, Ent_80008800* b)
{
    fn_8000832C(a, b, 0);
}

void fn_80008694(Task* a, s16 b, s16 c, Ent_80008800* d)
{
    fn_800086BC(a, b, c, d, 0, 0);
}

void fn_80008DE4(s16 v)
{
    lbl_8030A10C.xf0 = v;
}

s32 fn_800073C0(CalendarStamp* out) {
    OSCalendarTime td;

    OSTicksToCalendarTime(OSGetTime(), &td);
    out->year = td.year;
    out->month = td.mon + 1;
    out->day = td.mday;
    out->hour = td.hour;
    out->minute = td.min;
    out->second = td.sec;
    out->weekday = td.wday;
    out->pad = 0;
    return 1;
}

s32 fn_8000810C(void* a, s32 b) {
    s32 r = 0;
    while (r == 0) {
        r = fn_80007BFC(a, b);
        if (r < 0) {
            return -1;
        }
    }
    return 1;
}

void fn_80008C00(Ent8C00* obj, s16 x, s16 y, s32 a6, s32 a7, s32 a8) {
    Rec* r = obj->mid->rec;
    s16 sx = r->x;
    s16 sy = r->y;

    r->x = x;
    r->y = y;
    fn_80008DF4(obj, a8, a6, a7);
    r->x = sx;
    r->y = sy;
}

void fn_80007EC0(void) {
    s32 r;
    if (lbl_803478B8 == 2) {
        r = DVDGetCommandBlockStatus(&lbl_803478DC->cb);
        switch (r) {
        case 0:
            if (lbl_803478B4 == 1) {
                s32 n = DVDGetTransferredSize(lbl_803478DC);
                lbl_803478C4 -= n;
                lbl_803478C0 += n;
                lbl_803478C8 += n;
                if (lbl_803478C0 == 0) {
                    lbl_803478B8 = 3;
                } else {
                    lbl_803478B8 = 1;
                }
            } else {
                lbl_803478B8 = 1;
                lbl_803478B0 = 0;
            }
            break;
        case -1:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 9:
            lbl_803478B8 = 4;
            break;
        }
    } else if (lbl_803478B8 == 0) {
        r = DVDGetCommandBlockStatus(&lbl_803478DC->cb);
        switch (r) {
        case 0:
            lbl_803478B8 = 3;
            lbl_803478B0 = 0;
            break;
        case -1:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 9:
            lbl_803478B8 = 4;
            break;
        }
    }
}

EntD *fn_800095D0(void *old, u8 *src, void *extra) {
    s16 n;
    Ent_800095D0 *s;
    EntD *d;
    EntD *out;
    s16 i;
    if (old != 0) {
        fn_80035918(old);
        fn_801E17E0(old);
    }
    n = fn_800364F4(src);
    out = fn_801E1C7C(n * 16);
    s = (Ent_800095D0 *)src;
    d = out;
    for (i = 0; i < n; i++) {
        *(Ent_800095D0 *)d = *s;
        if (fn_800364B8(d)) {
            memcpy(d->data, src + s->off, d->size);
        }
        s++;
        d++;
    }
    if (extra != 0) fn_801E17E0(extra);
    else fn_801E17E0(src);
    return out;
}

CondLink* fn_80008800(Ent_80008800* t)
{
    CondLink* head = 0;
    CondLink* cur = 0;
    s16 n;
    Key* k;
    s16 lo;
    s16 hi;
    if (t != 0) {
        if (t->x0 < 0) return 0;
        k = t->xc;
        n = fn_800089F0(t, k->x0, k->x4, &lo, &hi, 0);
        while (n != 0) {
            if (head == 0) {
                fn_80061F58(&head, 0x10, 0);
                cur = head;
            } else {
                CondLink* prev;
                fn_80061F58(&cur->next, 0x10, 0);
                prev = cur;
                cur = cur->next;
                cur->prev = prev;
            }
            cur->x0 = k->x0;
            cur->x2 = k->x4;
            cur->x4 = lo;
            cur->x6 = hi;
            if ((s16)t[n].x0 < 0) break;
            k = t[n].xc;
            n = fn_800089F0(t, k->x0, k->x4, &lo, &hi, n);
        }
        return head;
    }
    return 0;
}

void fn_80006C00(NJS_MKEY_F* keys, u32 i, u32 nbKeys, f32* out) {
    f32 div[2] = {1.0f, 1.0f};
    NJS_MKEY_F* k1 = &keys[i];
    NJS_MKEY_F* k2 = &keys[(i + 1) % nbKeys];
    f32 t;
    f32 u;

    div[1] = (f32)(k2->keyframe - k1->keyframe);
    t = (lbl_80316940.frame - (f32)k1->keyframe) / div[(s32)(k2->keyframe - k1->keyframe) > 0];
    u = 1.0f - t;
    out[0] = k1->key[0] * u + k2->key[0] * t;
    out[1] = k1->key[1] * u + k2->key[1] * t;
    out[2] = k1->key[2] * u + k2->key[2] * t;
}

s32 fn_8000785C(ArcSet* set, s32 idx) {
    ArcHdr hdr;
    s32 c;
    u32 a;
    s32 b;
    s32 out;
    s32 r;
    s32 x;
    s32 magic;
    ArcInfo* info;

    fn_80298E48();
    r = fn_80297558(set, idx, &a, &b);
    if (r != 0) return r;
    x = fn_80298798(&hdr, &c, (ArcInfo*)set->slots[idx].info);
    if (x == 0) {
        x = fn_80298798(&hdr, &c, (ArcInfo*)set->slots[idx].info->x0);
        if (x == 0) {
            info = set->slots[idx].info;
            hdr.x4 = info->x10;
            hdr.x6 = info->x14;
            hdr.x0 = info->x4;
            x = info->x0;
        } else {
            magic = *(s32*)set->slots[idx].info->x0;
        }
    } else {
        magic = *(s32*)set->slots[idx].info;
    }
    if (magic == 0x47434958) {
        if (a != -1) c = a;
        r = fn_80298A04(set, idx, c, b, &hdr, &out);
        if (r != 0) return r;
        if (fn_80298BF8(out, x) < 0) {
            fn_80298BCC(out);
            return -1;
        }
    } else {
        return -1;
    }
    return 1;
}

s32 fn_80008000(s32 idx) {
    s32 blk;
    s32 bs;
    s32 q;
    if (idx >= lbl_803478AC || idx < 0) {
        return -1;
    }
    bs = lbl_80346738;
    q = idx / bs;
    blk = q * bs;
    if (blk != lbl_803478D4) {
        lbl_803478D4 = blk;
        if (lbl_803478AC > blk + bs) {
            lbl_803478BC = idx;
            lbl_803478D0 = bs;
            lbl_803478CC = bs << 11;
            if (DVDReadAsyncPrio(lbl_803478DC, lbl_803478D8, lbl_803478CC, blk << 11, 0, 2) == 0) {
                lbl_803457F8.err = 5;
                return -1;
            }
        } else {
            lbl_803478BC = idx;
            lbl_803478D0 = lbl_803478AC - blk;
            lbl_803478CC = lbl_803478A8 - (blk << 11);
            if (DVDReadAsyncPrio(lbl_803478DC, lbl_803478D8, lbl_803478CC, blk << 11, 0, 2) == 0) {
                lbl_803457F8.err = 5;
                return -1;
            }
        }
        lbl_803478B8 = 2;
        lbl_803478B4 = 0;
    }
    return 0;
}

extern DVDFileInfo lbl_80316980;
extern u8 lbl_803169C0[];
void* fn_802AC710(void* dst, const void* src, u32 n);

inline int Contains(s32 first, s32 cnt, s32 v)
{
    s32 last = cnt - 1 + first;
    if (first < 0) {
        return -1;
    }
    if (first <= v && v <= last) {
        return 1;
    }
    return -1;
}

s32 fn_80007BFC(void* dst, s32 size)
{
    s32 pos;
    s32 n;
    s32 in;

    if (size == 0) {
        return 1;
    }
    fn_80007EC0();
    switch (lbl_803478B8) {
    case 2:
        return 0;
    case 3:
        lbl_803478C4 = size;
        lbl_803478C8 = dst;
        lbl_803478B8 = 1;
    case 1:
        while (lbl_803478B8 != 3) {
            pos = lbl_803478C0;
            if (lbl_803478A8 < pos + lbl_803478C4) {
                lbl_803478C4 = lbl_803478A8 - pos;
            }
            lbl_803478BC = pos >> 11;
            lbl_803478B0 = pos & 0x7ff;
            if (lbl_803478BC > lbl_803478AC) {
                lbl_803457F8.err = 5;
                return -1;
            }
            in = Contains(lbl_803478D4, lbl_803478D0, lbl_803478BC);
            if (in > 0) {
                n = lbl_803478CC - lbl_803478B0;
                if (lbl_803478C4 <= n) {
                    fn_802AC710(lbl_803478C8, lbl_803478D8 + lbl_803478B0, lbl_803478C4);
                    DCFlushRange(lbl_803478C8, lbl_803478C4);
                    lbl_803478C8 = NULL;
                    lbl_803478C0 += lbl_803478C4;
                    lbl_803478C4 = 0;
                    lbl_803478B8 = 3;
                    lbl_803478BC = lbl_803478C0 >> 11;
                    lbl_803478B0 = lbl_803478C0 & 0x7ff;
                    if ((lbl_803478C0 & 0x7ff) == 0 && lbl_803478BC < lbl_803478AC) {
                        fn_80008000(lbl_803478BC);
                        lbl_803478B8 = 0;
                    }
                    return 1;
                }
                fn_802AC710(lbl_803478C8, lbl_803478D8 + lbl_803478B0, n);
                DCFlushRange(lbl_803478C8, n);
                lbl_803478C0 += n;
                lbl_803478C4 -= n;
                lbl_803478C8 += n;
            } else {
                if (lbl_803478C4 >= 0x81f && ((u32)lbl_803478C8 & 0x1f) == 0) { /* address alignment */
                    s32 sec = lbl_803478BC;
                    if (sec >= lbl_803478AC || sec < 0) {
                        return -1;
                    }
                    lbl_803478BC = sec;
                    if (!DVDReadAsyncPrio(lbl_803478DC, lbl_803478C8, lbl_803478C4 & ~0x7ff, sec << 11, 0, 2)) {
                        lbl_803457F8.err = 5;
                        return -1;
                    }
                    lbl_803478B8 = 2;
                    lbl_803478B4 = 1;
                } else {
                    return fn_80008000(lbl_803478BC);
                }
                return 0;
            }
        }
        break;
    case 0:
        return 0;
    case 4:
        lbl_803457F8.err = 5;
        return -1;
    default:
        break;
    }
    return 1;
}

s32 fn_80008194(char* name) {
    s32 len;
    s32 aligned;
    lbl_803478D8 = (u8*)(((u32)lbl_803169C0 + 0x1f) & ~0x1f); /* address alignment */
    lbl_803478DC = &lbl_80316980;
    if (!DVDOpen(name, &lbl_80316980)) {
        lbl_803457F8.err = 2;
        return -1;
    }
    len = lbl_803478DC->length;
    aligned = (len + 0x1f) & ~0x1f;
    lbl_803478A8 = aligned;
    lbl_803478AC = (aligned + 0x7ff) >> 11;
    lbl_803478B0 = 0;
    lbl_803478C0 = 0;
    lbl_803478BC = 0;
    lbl_803478D4 = -1;
    lbl_803478D0 = 0;
    lbl_803478CC = 0;
    if (fn_80008000(0) < 0) {
        return -1;
    }
    lbl_803478B8 = 0;
    return 0;
}

s32 fn_80007640(ArcSet *o, s32 idx) {
    u32 a;
    s32 b;
    s32 c;
    Mid_80007640 *m;
    Inner_80007640 *d;
    u32 v;
    s32 r;
    fn_80298E48();
    r = fn_80297558(o, idx, &a, &b);
    if (r != 0) {
        return r;
    }
    v = o->slots[idx].x8;
    if (a != -1) {
        v = a;
    }
    switch (fn_80298CAC(v, b, 0, &c)) {
    case -1:
        return -1;
    case 0:
        c = fn_80298210(&m, &d);
        if (c < 0) {
            return -1;
        }
        m->xc = d;
        if (v != -1) {
            m->xc->x0 = v;
        }
        lbl_80347EC4++;
        fn_80298C78(o, idx, c);
        break;
    }
    return 1;
}

s32 fn_800090F8(s32 packed, s16* p) {
    s32 ret = 1;
    switch (packed) {
    case 0:
        fn_8007E13C(p);
        break;
    case 1:
        fn_8007E118(p);
        break;
    case 2:
        fn_8007DFC0(p);
        break;
    case 3:
        fn_8007DEE0(p);
        break;
    case 4:
        break;
    case 0x10000:
        fn_8001FE44(p);
        break;
    default:
        ret = 0;
        break;
    }
    return ret;
}

void fn_80009750(char* dir, char* name, void* slot) {
    char path[0x80];
    char base[0x40];
    strcpy(base, name);
    fn_80061048(base);
    if (dir[0] != '/') {
        strcpy(path, "/");
        strcat(path, dir);
        strcat(path, base);
        strcat(path, ".STD");
    } else {
        sprintf(path, "%s%s.STD", dir, base);
    }
    fn_80035FC0(path, slot, 1);
}

s32 fn_8000743C(Key7* a, Key7* b) {
    if (a->x0 > b->x0) return 1;
    if (a->x0 < b->x0) return -1;
    if (a->x2 > b->x2) return 1;
    if (a->x2 < b->x2) return -1;
    if (a->x3 > b->x3) return 1;
    if (a->x3 < b->x3) return -1;
    if (a->x4 > b->x4) return 1;
    if (a->x4 < b->x4) return -1;
    if (a->x5 > b->x5) return 1;
    if (a->x5 < b->x5) return -1;
    if (a->x6 > b->x6) return 1;
    if (a->x6 < b->x6) return -1;
    return 0;
}

s16 fn_800089F0(Ent_80008800* t, s16 a, s16 b, s16* lo, s16* hi, s16 start) {
    Ent_80008800* e = &t[start];
    s32 found = 0;
    s16 i = start;

    *lo = start;
    for (;;) {
        if (e->x0 < 0) {
            *hi = i;
            break;
        }
        if (fn_8003DE8C(e->xc->x0, e->xc->x4, a, b)) {
            if (found == 0) {
                *lo = i;
                found = 1;
            }
        } else if (found == 1) {
            *hi = i;
            return i;
        }
        e++;
        i++;
    }
    if (found) {
        return i;
    }
    return 0;
}

static inline u32 MakeId(s16 lo, s16 hi) {
    return (hi << 16) | lo;
}
s32 fn_80008F08(Ent_80008800* list, s16 p1, s16 p2, s16 c, s16 d, s8 mode, Ent_80008800** out) {
    s32 found;
    s16 i;
    s16 lo;
    s16 hi;
    Key* pt;
    found = 0;
    if (list != NULL) {
        i = 0;
        while (1) {
            lo = list[i].x0;
            hi = list[i].x2;
            if (lo < 0) break;
            pt = list[i].xc;
            switch (mode) {
            case 0:
                if (fn_8003DE8C(pt->x0, pt->x4, p1, p2)) found = 1;
                break;
            case 1:
                if (MakeId(lo, hi) == MakeId(c, d)) found = 1;
                break;
            case 2:
                if (fn_8003DE8C(pt->x0, pt->x4, p1, p2)) {
                    if (MakeId(lo, hi) == MakeId(c, d)) found = 1;
                }
                break;
            }
            if (found) {
                *out = &list[i];
                return 1;
            }
            i++;
        }
    }
    return 0;
}

s16 fn_80009030(Ent_80008800* list, s16 p1, s16 p2, s16 c, s16 d) {
    Ent_80008800* e;
    u32 key;
    s16 count;
    s32 useKey;
    s32 v;
    count = 0;
    useKey = 0;
    if (c >= 0 && d >= 0) {
        useKey = 1;
    }
    if (list != NULL) {
        key = (d << 16) | c;
        e = list;
        while (1) {
            s16 lo = e->x0;
            s16 hi = e->x2;
            if (lo < 0) break;
            if (fn_8003DE8C(e->xc->x0, e->xc->x4, p1, p2)) {
                v = (hi << 16) | lo;
                switch (v) {
                case 0x30041:
                    break;
                default:
                    if (!useKey || v == key) count++;
                    break;
                }
            }
            e++;
        }
    }
    return count;
}

/* A pack of 12-byte entries; fn_80007528 hands each to one of four loaders by its flag bits. */
typedef struct ArcEnt {
    u32 x0;
    u32 flags;
    u32 x8;
} ArcEnt;
typedef struct ArcPack {
    ArcEnt* ents;
    u32 count;
} ArcPack;
typedef s32 (*ArcPackFn)(ArcPack* pk, u32 i);
extern ArcPackFn lbl_802DAE40[4];

s32 fn_80007528(ArcPack* pk) {
    u32 i;
    if (pk->count == 0) {
        lbl_803457F8.err = 1;
        return -1;
    }
    for (i = 0; i < pk->count; i++) {
        s32 kind;
        switch (pk->ents[i].flags & 0x5C000000) {
        case 0:
            kind = 0;
            break;
        case 0x40000000:
            kind = 1;
            break;
        case 0x08000000:
            kind = 2;
            break;
        case 0x04000000:
            kind = 3;
            break;
        default:
            kind = 2;
            break;
        }
        if (lbl_802DAE40[kind](pk, i) < 0) {
            lbl_803457F8.a = i;
            return -1;
        }
    }
    return 1;
}

#ifdef NONMATCHING
typedef struct HitEnt {
    s32 x0;
    void* x4;
    u8 pad8[0x14];
} HitEnt;
typedef struct HitWork {
    u8 pad0[0x50];
    u32 flags;
} HitWork;
typedef struct HitDef {
    u8 pad0[0x30];
    void* tbl;
} HitDef;
typedef struct HitInner {
    u8 pad0[0x10];
    HitDef* def;
    u8 pad14[0x38];
    HitWork* work;
} HitInner;
typedef struct HitObj {
    u8 pad0[0x24];
    HitInner* inner;
} HitObj;
extern s32 fn_8001C7E8(HitObj* obj);
extern void fn_800093C0(HitEnt* out, s16 a, s16 b, void* tbl);
extern int fn_80020700(s16 a, s16 b, void* obj);
extern s32 fn_8001C7B8(HitObj* obj, s16 a, s16 b);
extern void fn_8006DCFC(HitObj* obj, s16 a, s16 b);
#endif

/* Matches, but it uses the result of fn_8001C7B8, which unit_8000A38C defines as returning void
 * (and calls with an s32 last argument); kept here until those agree. */
#ifdef NONMATCHING
s32 fn_800091E0(HitObj* obj, HitEnt* out, s16 a, s16 b) {
    s16 n = 0;
    HitInner* in = obj->inner;
    void* tbl = in->def->tbl;
    HitWork* work = in->work;
    s32 ok;
    s32 r;
    HitEnt* e;
    GS* g;

    out->x0 = -1;
    ok = fn_8001C7E8(obj);
    if (ok == 0) work->flags |= 0x800000;
    else work->flags &= ~0x800000;
    fn_800093C0(out, a, b, tbl);
    switch (a) {
    case 0x1D:
        fn_800093C0(out, a, b + 0x12C, tbl);
        break;
    }
    if (ok != 0) fn_800093C0(out, a, b, lbl_8030A10C.x10);
    if (ok != 0) {
        g = &lbl_8030A10C;
        fn_800093C0(out, a, b, g->xc);
        fn_800093C0(out, a, b + 0x64, g->xc);
    }
    if (fn_80020700(a, b, obj) != 0) fn_800093C0(out, 0x15, -1, lbl_8030A10C.x10);
    for (e = out; e->x0 > 0; e++) n++;
    if (n == 0) return 0;
    if (ok == 0) return 0;
    r = fn_8001C7B8(obj, a, b);
    if (r != 0) fn_8006DCFC(obj, a, b);
    if (r != 0) {
        for (e = out; e->x0 > 0; e++) e->x4 = &e->x4;
        return 0;
    }
    return 1;
}
#endif
