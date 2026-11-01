#include "types.h"
#include "game/work_8030CEA0.h"
#include "ninja.h"
#include "game/task.h"
#include "game/util.h"
#include "game/gamedata.h"
#include <math.h>
#include <stdarg.h>
void fn_80217B98();
#include "game/save_8030B7F4.h"
s32 fn_80219B7C(void);
s32 fn_801D168C(void);
void fn_801D150C(s32 v);
void fn_802173F4(u32 mode, s8 vol8, s16 time);
extern u32 lbl_803477B8;
extern s32 lbl_803477BC;
extern s32 lbl_803477C0;
/* A sequence request: x4 key pairs (bank, id) from key; lbl_80315484 is the one playing,
 * lbl_80315434 the one paused, lbl_8031545C the next one. */
typedef struct SeqReq {
    s32 x0;
    s32 x4;
    u8 key[0x20];
} SeqReq;
extern SeqReq lbl_80315484;
extern SeqReq lbl_80315434;
extern SeqReq lbl_8031545C;
extern s32 lbl_803477D4;
extern s32 lbl_803477D8;
void sndSeqVolume(u8 vol, u16 time, u32 id, u8 mode);
void sndSeqPause(u32 id);
void sndSeqStop(u32 id);
void fn_802193BC();
typedef struct Slot { u8 pad_00[0x10]; s32 field_10; u8 pad_14[0x24]; u8 vol; u8 pad39[3]; } Slot;
extern Slot lbl_80315120[];
s32 fn_80219834(s32 v);
s32 SePlay(s32 bank, s8 arg1, s8 id);
extern s32 lbl_803477DC;
void fn_80217830(s32 arg);
extern u32 lbl_803477E0;
float fn_801F6120(float **p);
extern void fn_801E1784(void* p);
#define RDI(p) (*(p) == 3.4028235e38f ? ((p)++, 0x7FFFFFFF) : (s32)fn_801F6120(&(p)))
void fn_80216E38(u32 n, char *p);
u32 fn_802159E0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, char *path, s32 size);
typedef struct { u8 pad[8]; u32 off; u32 len; } StrmSrc;
/* One of the four DVD audio stream slots (lbl_80314B80). */
typedef struct Strm {
    u8 state;           /* 0x00 in use / playing */
    u8 pad01[3];
    u32 id;             /* 0x04 */
    struct Strm* left;  /* 0x08 linked channel slots */
    struct Strm* right; /* 0x0C */
    StrmSrc* src;       /* 0x10 */
    u8 a;               /* 0x14 */
    u8 b;               /* 0x15 */
    u8 pad16[2];
    u8 info[0x3c];      /* 0x18 DVDFileInfo */
    u32 handle;         /* 0x54 */
    u32 pos;            /* 0x58 */
    u32 len;            /* 0x5C */
    u8* buf;            /* 0x60 */
    u32 size;           /* 0x64 */
    u32 w68;            /* 0x68 */
    u8 b6c;             /* 0x6C */
    u8 pad6d[3];
    s32 w70;            /* 0x70 */
    s32 w74;            /* 0x74 */
    s32 w78;            /* 0x78 */
    s32 w7c;            /* 0x7C */
} Strm;
extern void* memset(void* dst, int c, u32 n);
extern void sndStreamMixParameterEx(u32 h, u32 a, u32 b, u32 c, u32 d, u32 e);
typedef struct StrmTbl {
    Strm s[4];
    u32 counter;        /* 0x200 */
    u32 intr;           /* 0x204 */
    u32 lock;           /* 0x208 */
} StrmTbl;
extern StrmTbl lbl_80314B80;
typedef struct {
    u32 id;
    s32 slot;
    s32 time;
    s32 flag;
    u8 vol;
    u8 pad11[3];
} SndSlot;
extern SndSlot lbl_80315030[12];
extern s32 fn_80218570(s32 a, s32 b, s32 c);
extern void sndStreamARAMUpdate(u32 h, u32 a, u32 b, u32 c, u32 d);
extern void sndStreamDeactivate(u32 h);
extern s32 fn_8023CD10(void *info);
extern void fn_8023A8E0(void *info);
extern void fn_80216030(void);
extern char *strcpy(void *dst, const char *src);
extern char *strcat(void *dst, const char *src);
typedef struct MapInfo {
    s32 map;        /* 0x00 */
    s32 area;       /* 0x04 */
    char room;      /* 0x08 */
} MapInfo;
extern MapInfo lbl_80311AC0;
float fn_801F6120(float **p);
#define FREEALL(s, v) \
    for (v = 0; v < s->n; v++) { \
        if (s->xc[v] != NULL) { \
            fn_801E1784(s->xc[v]); \
            s->xc[v] = NULL; \
        } \
        if (s->x14[v] != NULL) { \
            fn_801E1784(s->x14[v]); \
            s->x14[v] = NULL; \
        } \
        if (s->x10[2 * v] != NULL) { \
            fn_801E1784(s->x10[2 * v]); \
            s->x10[2 * v] = NULL; \
        } \
        if (s->x10[2 * v + 1] != NULL) { \
            fn_801E1784(s->x10[2 * v + 1]); \
            s->x10[2 * v + 1] = NULL; \
        } \
        if (s->x18[2 * v] != NULL) { \
            fn_801E1784(s->x18[2 * v]); \
            s->x18[2 * v] = NULL; \
        } \
        if (s->x18[2 * v + 1] != NULL) { \
            fn_801E1784(s->x18[2 * v + 1]); \
            s->x18[2 * v + 1] = NULL; \
        } \
    } \
    if (s->xc != NULL) { \
        fn_801E1784(s->xc); \
        s->xc = NULL; \
    } \
    if (s->x14 != NULL) { \
        fn_801E1784(s->x14); \
        s->x14 = NULL; \
    } \
    if (s->x10 != NULL) { \
        fn_801E1784(s->x10); \
        s->x10 = NULL; \
    } \
    if (s->x18 != NULL) { \
        fn_801E1784(s->x18); \
        s->x18 = NULL; \
    } \
    if (s->times != NULL) { \
        fn_801E1784(s->times); \
        s->times = NULL; \
    } \
    if (s->angles != NULL) { \
        fn_801E1784(s->angles); \
        s->angles = NULL; \
    } \
    if (s->x20 != NULL) { \
        fn_801E1784(s->x20); \
        s->x20 = NULL; \
    } \
    lbl_8030CEA0.x15cc = 0;
float fn_801F6120(float **p);
float fn_801F6120(float **p);
#define FREEALL_802034B0(s, v) \
if (s->xc[0] != NULL) { \
    fn_801E1784(s->xc[0]); \
    s->xc[0] = NULL; \
} \
if (s->x14[0] != NULL) { \
    fn_801E1784(s->x14[0]); \
    s->x14[0] = NULL; \
} \
for (v = 0; v < s->n - 1; v++) { \
    if (s->xc[v + 1] != NULL) { \
        fn_801E1784(s->xc[v + 1]); \
        s->xc[v + 1] = NULL; \
    } \
    if (s->x14[v + 1] != NULL) { \
        fn_801E1784(s->x14[v + 1]); \
        s->x14[v + 1] = NULL; \
    } \
    if (s->x10[2 * v] != NULL) { \
        fn_801E1784(s->x10[2 * v]); \
        s->x10[2 * v] = NULL; \
    } \
    if (s->x10[2 * v + 1] != NULL) { \
        fn_801E1784(s->x10[2 * v + 1]); \
        s->x10[2 * v + 1] = NULL; \
    } \
    if (s->x18[2 * v] != NULL) { \
        fn_801E1784(s->x18[2 * v]); \
        s->x18[2 * v] = NULL; \
    } \
    if (s->x18[2 * v + 1] != NULL) { \
        fn_801E1784(s->x18[2 * v + 1]); \
        s->x18[2 * v + 1] = NULL; \
    } \
} \
if (s->angles != NULL) { \
    fn_801E1784(s->angles); \
    s->angles = NULL; \
} \
if (s->xc != NULL) { \
    fn_801E1784(s->xc); \
    s->xc = NULL; \
} \
if (s->x14 != NULL) { \
    fn_801E1784(s->x14); \
    s->x14 = NULL; \
} \
if (s->x10 != NULL) { \
    fn_801E1784(s->x10); \
    s->x10 = NULL; \
} \
if (s->x18 != NULL) { \
    fn_801E1784(s->x18); \
    s->x18 = NULL; \
} \
if (s->times != NULL) { \
    fn_801E1784(s->times); \
    s->times = NULL; \
} \
lbl_8030CEA0.x15cc = 0;
float fn_801F6120(float **p);
#define FREEALL_80203FFC(s, v) \
if (s->xc[0] != NULL) { \
    fn_801E1784(s->xc[0]); \
    s->xc[0] = NULL; \
} \
if (s->x14[0] != NULL) { \
    fn_801E1784(s->x14[0]); \
    s->x14[0] = NULL; \
} \
for (v = 0; v < s->n - 1; v++) { \
    if (s->xc[v + 1] != NULL) { \
        fn_801E1784(s->xc[v + 1]); \
        s->xc[v + 1] = NULL; \
    } \
    if (s->x14[v + 1] != NULL) { \
        fn_801E1784(s->x14[v + 1]); \
        s->x14[v + 1] = NULL; \
    } \
    if (s->x10[2 * v] != NULL) { \
        fn_801E1784(s->x10[2 * v]); \
        s->x10[2 * v] = NULL; \
    } \
    if (s->x10[2 * v + 1] != NULL) { \
        fn_801E1784(s->x10[2 * v + 1]); \
        s->x10[2 * v + 1] = NULL; \
    } \
    if (s->x18[2 * v] != NULL) { \
        fn_801E1784(s->x18[2 * v]); \
        s->x18[2 * v] = NULL; \
    } \
    if (s->x18[2 * v + 1] != NULL) { \
        fn_801E1784(s->x18[2 * v + 1]); \
        s->x18[2 * v + 1] = NULL; \
    } \
} \
if (s->xc != NULL) { \
    fn_801E1784(s->xc); \
    s->xc = NULL; \
} \
if (s->x14 != NULL) { \
    fn_801E1784(s->x14); \
    s->x14 = NULL; \
} \
if (s->x10 != NULL) { \
    fn_801E1784(s->x10); \
    s->x10 = NULL; \
} \
if (s->x18 != NULL) { \
    fn_801E1784(s->x18); \
    s->x18 = NULL; \
} \
if (s->times != NULL) { \
    fn_801E1784(s->times); \
    s->times = NULL; \
} \
lbl_8030CEA0.x15cc = 0;
float fn_801F6120(float **p);
extern s32 lbl_803477E8;
extern struct NJS_MOTION;
typedef struct {
    void* model;          /* 0x00 */
    u32 pad4;
    NJS_TEXLIST texlist;  /* 0x08 */
} ModelFile;
typedef struct {
    u8 pad0[8];
    ModelFile* body;    /* 0x08 */
    ModelFile* extra;   /* 0x0C */
    ModelFile* spark;   /* 0x10 */
} ModelFiles;
typedef struct {
    s32 count;
    void* items[1]; /* count entries */
} ItemList;
typedef struct {
    u8 pad0[0x14];
    u32 flags;     /* 0x14 */
    u8 pad18[0x24 - 0x18];
    u32 nearDist;  /* 0x24 */
    u32 actDist;   /* 0x28 */
    u32 x2c;       /* 0x2C */
    u32 speed;     /* 0x30 */
    u8 pad34[4];
    s32 mode;      /* 0x38 */
    u32 flag;      /* 0x3C story flag */
} EvInfo;
typedef struct {
    u8 pad0[0x10];
    EvInfo* info;          /* 0x10 */
    ModelFiles* files;     /* 0x14 */
    u8 pad18[4];
    ItemList* items;       /* 0x1C */
    NJS_TEXLIST* texlist;  /* 0x20 */
    u8 pad24[0x44 - 0x24];
    NJS_POINT3 target;     /* 0x44 */
    NJS_POINT3 rot;        /* 0x50 */
} EvExt;
extern struct EvObj;
typedef struct {
    u8 pad0[8];
    struct EvObj* obj;   /* 0x08 (added) */
    u8 pad0c[0x18 - 0xc];
    s16 h18;      /* 0x18 */
} EvSub;
typedef struct {
    s32 mode;     /* 0x00 */
} EvMode;
typedef struct {
    u8 pad0[0x28];
    u16 x28;      /* 0x28 */
    u16 id;       /* 0x2A */
    s16 x2c;      /* 0x2C */
    s16 x2e;      /* 0x2E */
} EvHit;
typedef struct EvObj {
    u8 pad0[4];
    s32 kind;                /* 0x04 */
    s32 x08;                 /* 0x08 */
    f32 clipNear;            /* 0x0C */
    f32 clipFar;             /* 0x10 */
    u8 pad14[0x1C - 0x14];
    NJS_ARGB colour;         /* 0x1C */
    s32 x2c;                 /* 0x2C */
    u8 pad30[0x38 - 0x30];
    NJS_POINT3 pos;          /* 0x38 */
    Angle ang[3];            /* 0x44 */
    NJS_POINT3 scl;          /* 0x50 */
    NJS_POINT3 vel;          /* 0x5C */
    Angle rotv[3];           /* 0x68 */
    s16 x74;                 /* 0x74 */
    u8 pad76[0xB4 - 0x76];
    NJS_POINT3 pivotPos;     /* 0xB4 */
    u8 padC0[0xE4 - 0xC0];
    void* model;             /* 0xE4 */
    struct NJS_MOTION* motion; /* 0xE8 */
    void* shape;             /* 0xEC */
    u8 padF0[0x100 - 0xF0];
    NJS_TEXLIST* texlist;    /* 0x100 */
    NJS_POINT3 home;         /* 0x104 */
    Angle tgt[3];            /* 0x110 */
    u8 pad11C[0x164 - 0x11C];
    f32 x164;                /* 0x164 */
    s16 state;               /* 0x168 */
    u8 b16a;                 /* 0x16A */
    u8 b16b;                 /* 0x16B */
    s16 pivot;               /* 0x16C */
    u8 pad16E[2];
    u16 motionId;            /* 0x170 */
    u16 x172;                /* 0x172 */
    u8 pad174[2];
    u16 id;                  /* 0x176 */
    u8 pad178[2];
    u16 x17a;                /* 0x17A */
    u8 pad17C[4];
    s32 x180;                /* 0x180 */
    s32 hidden;              /* 0x184 */
    u8 pad188[4];
    f32 x18c;                /* 0x18C */
    f32 speed;               /* 0x190 */
    u8 pad194[4];
    s32 x198;                /* 0x198 */
    u8 pad19C[0x1B8 - 0x19C];
    EvHit* hit;              /* 0x1B8 */
    void* x1bc;              /* 0x1BC */
    u8 pad1C0[0x1C8 - 0x1C0];
    EvExt* ext;              /* 0x1C8 */
    u8 pad1CC[0x1D8 - 0x1CC];
    EvSub* sub;              /* 0x1D8 */
    u8 pad1DC[0x1EC - 0x1DC];
    s8 x1ec;                 /* 0x1EC */
    s8 x1ed;                 /* 0x1ED */
    s8 x1ee;                 /* 0x1EE */
    u8 pad1EF[0x1FC - 0x1EF];
    s16 x1fc;                /* 0x1FC */
    s16 x1fe;                /* 0x1FE */
    s16 x200;                /* 0x200 */
    s16 x202;                /* 0x202 */
    s16 x204;                /* 0x204 */
    s16 x206;                /* 0x206 */
    s16 x208;                /* 0x208 */
    s16 x20a;                /* 0x20A */
    Angle x20c;              /* 0x20C */
    u32 x210;                /* 0x210 */
    u8 pad214[0x21C - 0x214];
    u8 x21c;                 /* 0x21C */
    u8 x21d;                 /* 0x21D */
    u8 x21e;                 /* 0x21E */
    u8 x21f;                 /* 0x21F */
    u8 pad220[0x22C - 0x220];
    u16 x22c;                /* 0x22C frame counter */
    u16 x22e;                /* 0x22E colour key index */
    u16 x230;                /* 0x230 */
    u16 point;               /* 0x232 */
    u8 pad234[0x23C - 0x234];
    void* x23c;              /* 0x23C */
    void* x240;              /* 0x240 */
    u8 pad244[0x24C - 0x244];
    NJS_POINT3 x24c;         /* 0x24C */
    u8 pad258[0x260 - 0x258];
    EvMode* mapMode;         /* 0x260 */
} EvObj;
float fn_801F6120(float **p);
extern u32 lbl_803477C8[2];

s32 fn_80215F8C(void) {
    return 1;
}

extern u32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(u32 level);
void fn_80216744(Strm *s);

static inline void strm_stop(Strm *s)
{
    if (s->state != 0 && s->w74 == 0) {
        sndStreamMixParameterEx(s->handle, 0, s->b, 0, 0, 0);
        s->w74 = 1;
        sndStreamDeactivate(s->handle);
        if (s->w78 == 0) {
            fn_8023A8E0(s->info);
            s->state = 0;
        } else {
            s->w7c = 1;
        }
    }
}

static inline s32 strm_find(u32 id)
{
    s32 i;
    Strm *p = lbl_80314B80.s;
    for (i = 0; i < 4; i++) {
        if (p->state != 0 && id == p->id) {
            return i;
        }
        p++;
    }
    return -1;
}

static inline void strm_stop_id(Strm *s)
{
    u32 idx;
    Strm *t;
    u32 id = s->id;
    if (lbl_80314B80.lock++ == 0) {
        lbl_80314B80.intr = OSDisableInterrupts();
    }
    idx = strm_find(id);
    if (idx != -1) {
        strm_stop(&lbl_80314B80.s[idx]);
        t = lbl_80314B80.s[idx].left;
        if (t != 0) {
            strm_stop(t);
        }
        t = lbl_80314B80.s[idx].right;
        if (t != 0) {
            strm_stop(t);
        }
    }
    if (lbl_80314B80.lock != 0 && --lbl_80314B80.lock == 0) {
        OSRestoreInterrupts(lbl_80314B80.intr);
    }
}

s32 fn_802163FC(s32 a, s32 b, s32 c, s32 d, Strm *s)
{
    s32 st = fn_8023CD10(s->info);
    if (st != 0 && st != 1 && st != 2) {
        strm_stop_id(s);
        return 0;
    }
    if (s->w74 != 0) {
        sndStreamDeactivate(s->handle);
        if (s->w78 == 0) {
            fn_8023A8E0(s->info);
            s->state = 0;
        } else {
            s->w7c = 1;
        }
        return 0;
    }
    if (b + d < (s->w68 >> 1)) {
        return 0;
    }
    fn_80216744(s);
    return s->w68 >> 1;
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

extern u32 lbl_803477C8[2];
extern s32 sndSeqGetValid(u32 id);

/* Whether stream id is playing; under the stream lock. */
static inline s32 strm_active(u32 id)
{
    s32 r = 0;
    u32 i;
    if (lbl_80314B80.lock++ == 0) {
        lbl_80314B80.intr = OSDisableInterrupts();
    }
    i = strm_find(id);
    if (i != -1) {
        r = lbl_80314B80.s[i].state != 0 && lbl_80314B80.s[i].w70 != 0;
    }
    if (lbl_80314B80.lock != 0 && --lbl_80314B80.lock == 0) {
        OSRestoreInterrupts(lbl_80314B80.intr);
    }
    return r;
}

void fn_80216E38(u32 n, char *p)
{
    char buf[0x40];

    strcpy(buf, "/sound/");
    strcat(buf, p);
    if (n == 0) {
        lbl_803477B8 = fn_802159E0(1, 2, 0x5622, 2, 0, 0, 0, buf, 0x4000);
    } else if (n == 1) {
        lbl_803477B8 = fn_802159E0(1, 2, 0xAC44, 2, 0, 0, 0, buf, 0x100000);
    }
}

s32 fn_80216F48(u32 h) {
    if (h == 1) {
        return lbl_803477E0 != -1;
    }
    if ((h & 0xfffe) == 0x10) {
        u32 id = lbl_803477C8[h - 0x10];
        return id != -1 && strm_active(id);
    }
    if (h >= 0x100) {
        SndSlot *e = lbl_80315030;
        s32 i;
        for (i = 0; i < 6; i++, e++) {
            if (e->id == h - 0x100) {
                return sndSeqGetValid(e->id);
            }
        }
    }
    return 0;
}

void fn_802172C8(u32 mode, s8 a) {
    if (mode != 0) {
        s32 x = a;
        s32 v = -0x7e;
        if (x > -0x7f) {
            v = x;
        }
        fn_802173F4(mode, v, 0);
    }
}

void fn_80217B98(void) {
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

static inline s32 req_commit(SeqReq *r)
{
    SeqReq *prev = &lbl_80315484;
    if (r->x4 == prev->x4 && MemEqual(r->key, prev->key, r->x4 * 2)) {
        lbl_8031545C.x4 = 0;
        return 1;
    }
    if (lbl_803477E0 != -1) {
        if (r->x4 > 1) {
            sndSeqStop(lbl_803477E0);
            lbl_803477E0 = -1;
        } else {
            sndSeqVolume(0, 500, lbl_803477E0, 1);
        }
        prev->x4 = 0;
    }
    MemCopy(&lbl_8031545C, r, 0x28);
    return 1;
}

s32 fn_802182F4(s32 unused, s32 n, s8 a, s8 b, ...)
{
    SeqReq q;
    SeqReq r;
    va_list ap;
    s32 i;
    if (n == 1) {
        memset(&r, 0, 0x28);
        r.x4 = 1;
        r.x0 = 0;
        r.key[0] = a;
        r.key[1] = b;
        return req_commit(&r);
    }
    memset(&q, 0, 0x28);
    q.x4 = n;
    q.x0 = (a < 0);
    q.key[0] = a;
    q.key[1] = b;
    va_start(ap, b);
    for (i = 1; i < n; i++) {
        q.key[i * 2] = va_arg(ap, int);
        q.key[i * 2 + 1] = va_arg(ap, int);
    }
    return req_commit(&q);
}

void fn_80218D80(char *name, u32 tag, s32 v) {
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

void fn_80216CB4(char *p) {
    fn_802193BC(p, 0);
}

u32 fn_80215EA0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, char *g, s32 h)
{
    return fn_802159E0(1, a, b, c, d, e, f, g, h);
}

u32 fn_80215F14(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, char *path)
{
    return fn_802159E0(1, a, b, c, d, e, f, path, 0x8000);
}

void fn_80217790(void)
{
    SndSlot *e = lbl_80315030;
    s32 i;

    for (i = 0; i < 6; i++) {
        if (e->id != -1) {
            sndSeqPause(e->id);
            e->flag = 1;
        }
        e++;
    }
}

u32 fn_80216A9C(Strm* s, StrmSrc* src, u8 a, u8 b)
{
    u32 ret;
    u32 h;
    s->src = src;
    s->a = a;
    s->b = b;
    s->w70 = 1;
    s->w74 = 0;
    s->w7c = 0;
    s->w78 = 1;
    s->b6c = 1;
    s->size = 0x6280;
    s->w68 = (s->size >> 3) * 14;
    if (s->size > 0x6280) {
        s->size = 0x6280;
    }
    h = s->size >> 1;
    s->pos = h;
    s->len = s->src->len;
    if (s->len < h) {
        ret = s->len;
        memset(s->buf + s->len, 0, h - s->len);
    } else {
        ret = h;
    }
    s->state = 2;
    sndStreamMixParameterEx(s->handle, s->a, s->b, 0, 0, 0);
    return ret;
}

s32 fn_80216B88(Strm **out) {
    s32 i;
    u32 j;
    u32 id;
    Strm *base = lbl_80314B80.s;
    Strm *p = base;
    for (i = 0; i < 4; p++, i++) {
        if (p->state == 0) {
            do {
                id = lbl_80314B80.counter++;
                if (id == -1) {
                    id = lbl_80314B80.counter++;
                }
                for (j = 0; j < 4; j++) {
                    if (base[j].state != 0 && id == base[j].id) {
                        break;
                    }
                }
            } while (j != 4);
            lbl_80314B80.s[i].state = 1;
            lbl_80314B80.s[i].id = id;
            lbl_80314B80.s[i].left = 0;
            lbl_80314B80.s[i].right = 0;
            *out = &lbl_80314B80.s[i];
            return id;
        }
    }
    return -1;
}

void fn_80216744(Strm *s)
{
    u8 *dst;
    u32 cnt;

    cnt = s->size >> 1;
    if (s->b6c != 0) {
        dst = s->buf + cnt;
    } else {
        dst = s->buf;
    }
    if (s->pos + cnt > s->len) {
        if (s->len > s->pos) {
            cnt = s->len - s->pos;
            memset(dst + cnt, 0, (s->size >> 1) - cnt);
        } else {
            memset(dst, 0, s->size >> 1);
            sndStreamARAMUpdate(s->handle, s->b6c != 0 ? s->w68 >> 1 : 0, s->w68 >> 1, 0, 0);
            cnt = 0;
        }
    }
    if (cnt != 0) {
        if (fn_8023CD10(s->info) == 0) {
            fn_8023AB88(s->info, dst, cnt, s->src->off + s->pos, fn_80216030, 2);
            s->w78 = 1;
            s->pos += cnt;
        }
    } else if (s->w70 != 0) {
        s->w70 = 0;
    } else {
        sndStreamDeactivate(s->handle);
        if (s->w78 == 0) {
            fn_8023A8E0(s->info);
            s->state = 0;
        } else {
            s->w7c = 1;
        }
    }
    s->b6c ^= 1;
}

void fn_80216D14(s16 x)
{
    u32 mode = lbl_803477B8;

    if (mode != 0) {
        if (mode == 0x10 || mode == 0x11) {
            lbl_803477C0 = 0x20;
            lbl_803477BC = mode - 0x10;
        } else {
            fn_802173F4(mode, -0x7f, x);
            if (mode == 1) {
                lbl_80315484.x4 = 0;
            }
        }
    }
    lbl_803477B8 = 0;
}

void fn_8021730C(u32 mode, s16 time)
{
    if (mode != 0) {
        if (mode == 0x10 || mode == 0x11) {
            lbl_803477C0 = 0x20;
            lbl_803477BC = mode - 0x10;
        } else {
            fn_802173F4(mode, -0x7f, time);
            if (mode == 1) {
                lbl_80315484.x4 = 0;
            }
        }
    }
}

void fn_80217380(u32 mode)
{
    if (mode != 0) {
        if (mode == 0x10 || mode == 0x11) {
            lbl_803477C0 = 0x20;
            lbl_803477BC = mode - 0x10;
        } else {
            fn_802173F4(mode, -0x7f, 1000);
            if (mode == 1) {
                lbl_80315484.x4 = 0;
            }
        }
    }
}

/* Sets the music and the six sequence slots to m/128 of their volumes. */
static inline void SetVol(s32 m) {
    s32 i;
    SndSlot *e;
    if (lbl_803477E0 != 0xFFFFFFFF) {
        sndSeqVolume(m * lbl_80315120[lbl_803477DC].vol / 128, 500, lbl_803477E0, 0);
    }
    for (i = 0; i < 6; i++) {
        e = &lbl_80315030[i];
        if (e->id != 0xFFFFFFFF) {
            sndSeqVolume(m * e->vol / 128, 500, e->id, 0);
        }
    }
}

void fn_80217134(void) {
    SetVol(127);
}

void fn_802171F0(s8 v) {
    s32 m = (v + 0x80) / 2;
    s32 i;
    SndSlot *e;
    if (lbl_803477E0 != 0xFFFFFFFF) {
        sndSeqVolume(m * lbl_80315120[lbl_803477DC].vol / 128, 500, lbl_803477E0, 0);
    }
    for (i = 0; i < 6; i++) {
        e = &lbl_80315030[i];
        if (e->id != 0xFFFFFFFF) {
            sndSeqVolume(m * e->vol / 128, 500, e->id, 0);
        }
    }
}

void fn_80217608(void)
{
    if (lbl_803477E0 != -1) {
        sndSeqVolume(0, 500, lbl_803477E0, 2);
        sndSeqPause(lbl_803477E0);
        MemCopy(&lbl_80315434, &lbl_80315484, 0x28);
        lbl_803477D8 = lbl_803477E0;
        lbl_803477D4 = lbl_803477DC;
        lbl_80315484.x4 = 0;
        lbl_803477E0 = -1;
    }
}

s32 fn_80218570(s32 unused, s32 a, s32 b) {
    SeqReq t;
    memset(&t, 0, sizeof(t));
    t.x4 = 1;
    t.x0 = 0;
    t.key[0] = a;
    t.key[1] = b;
    if (t.x4 == lbl_80315484.x4 && MemEqual(t.key, lbl_80315484.key, t.x4 << 1)) {
        lbl_8031545C.x4 = 0;
        return 1;
    }
    if (lbl_803477E0 != -1) {
        if (t.x4 > 1) {
            sndSeqStop(lbl_803477E0);
            lbl_803477E0 = -1;
        } else {
            sndSeqVolume(0, 500, lbl_803477E0, 1);
        }
        lbl_80315484.x4 = 0;
    }
    MemCopy(&lbl_8031545C, &t, 0x28);
    return 1;
}

void fn_802173F4(u32 mode, s8 vol8, s16 time) {
    s32 vol = (vol8 + 0x80) / 2;
    u8 stop = vol8 <= -0x7f;
    SndSlot *e;
    s32 i;
    if (time > 500) {
        time = 500;
    }
    if (mode == 1) {
        sndSeqVolume(vol * lbl_80315120[lbl_803477DC].vol / 128, time, lbl_803477E0, stop);
    } else if (mode >= 0x100) {
        e = lbl_80315030;
        for (i = 0; i < 6; e++, i++) {
            if (mode - 0x100 == e->id) {
                if (lbl_803477E0 != lbl_80315030[i].id) {
                    lbl_80315030[i].vol = vol * lbl_80315120[lbl_80315030[i].slot].vol / 128;
                    sndSeqVolume(lbl_80315030[i].vol, time, mode - 0x100, stop);
                }
                if (stop == 1) {
                    lbl_80315030[i].time = 10000;
                }
                return;
            }
        }
    }
}

/* Rooms where opening a chest skips the item jingle. */
#define QUIET_ROOM()                                                  \
    ((lbl_80311AC0.area == 0x1c && lbl_80311AC0.room == 'b') ||      \
     (lbl_80311AC0.area == 0x7a && lbl_80311AC0.room == 'a') ||      \
     (lbl_80311AC0.area == 0x7d && lbl_80311AC0.room == 'a') ||      \
     (lbl_80311AC0.area == 0x7d && lbl_80311AC0.room == 'b') ||      \
     (lbl_80311AC0.area == 0x7d && lbl_80311AC0.room == 'd'))

#ifdef NONMATCHING
/* Near miss (2 lines): the original schedules `li r0, 0` after the `stwx` of the call result.
   fn_80216D98 has the same body for id = lbl_803477B8 (also 2 lines, same cause). */

typedef struct Ent60 {
    u32 x00;
    u8 pad04[0x2c];
    u8 x30[0x30];
} Ent60;
extern Ent60 lbl_80314940[2];
extern u32 fn_802168CC(void *p, void *q, s32 n);
#endif

#ifdef NONMATCHING
void fn_80215F94(u32 id)
{
    u32 idx;

    if (id == 0x10 || id == 0x11) {
        idx = id - 0x10;
        if (lbl_803477C8[idx] == 0xffffffff) {
            if (lbl_80314940[idx].x00 != 0) {
                lbl_803477C8[idx] = fn_802168CC(&lbl_80314940[idx], lbl_80314940[idx].x30, 0x78);
                lbl_803477C0 = 0;
                lbl_80314940[idx].x00 = 0;
            }
        }
    }
}
#endif
