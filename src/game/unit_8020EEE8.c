#include "types.h"
#include "game/work_8030CEA0.h"
#include "ninja.h"
#include "game/task.h"
#include "game/util.h"
#include "game/gamedata.h"
#include <math.h>
#include <stdarg.h>
/* The head of a message a script command posts through fn_800CD0B8; the receiver sets kind (2 = done). */
typedef struct EvHead {
    u32 kind;       /* 0x00 */
    s32 x04;        /* 0x04 */
} EvHead;
/* The event message fn_80211058 posts: the head plus the fields it clears. */
typedef struct Ev {
    EvHead hd;      /* 0x00 */
    s16 h8;         /* 0x08 */
    u8 pad0a[2];
    s32 x0c;        /* 0x0c */
    s32 x10;        /* 0x10 */
} Ev;
/* A script command's argument stream: words that are floats, ints or bytes depending on the command. */
typedef union ScptCur {
    f32 *f;
    u8 *b;
    const u32 *rom;  /* script data in .rodata */
    u32 *u;
    s32 *i;
} ScptCur;
/* One running script command, as every command handler and fn_80211058/fn_802110E8 see it. */
typedef struct Scpt {
    s32 kind;       /* 0x00 */
    s32 flags;      /* 0x04: bit 0 runs the next command in the same frame */
    s32 handle;     /* 0x08: set once the message is posted */
    Ev *ev;         /* 0x0c */
    s16 cnt;        /* 0x10: post attempts */
    u16 x12;        /* 0x12: from lbl_802F7940 */
    s32 x14;        /* 0x14: its slot in lbl_8030CEA0.x10 */
    s32 owner;      /* 0x18: the command, an index into lbl_802F7940 */
    ScptCur cur;    /* 0x1c */
    u32 a20;        /* 0x20: the message, kept to retry the post: type */
    u32 a24;        /* 0x24: id */
    u32 a28;        /* 0x28 */
    s32 a2c;        /* 0x2c: the message word fn_800CD0B8 posts last */
    union {         /* 0x30: the command's own work block */
        void *p;
        u32 n;
        u8 *b;
        struct Work801F8 *work801F8;
        struct Work801FC *work801FC;
        struct Work8020 *work8020;
        struct Work_80202004 *work_80202004;
        struct Lerp *lerp;
        struct Eff *eff;
        struct Fx *fx;
        struct Fx_801F8D0C *fx_801F8D0C;
        struct Fx_801F8F7C *fx_801F8F7C;
        struct Fx_801F9120 *fx_801F9120;
        struct Fx_801FBBA8 *fx_801FBBA8;
        struct ScrState *scrState;
        struct Work_8020184C *work_8020184C;
        struct Work_802019F8 *work_802019F8;
        struct Work_80207CD0 *work_80207CD0;
        struct Rec *rec;
        struct Rec_80208424 *rec_80208424;
        struct Rec_80208A20 *rec_80208A20;
        struct Rec_80209974 *rec_80209974;
        struct Work_8020A938 *work_8020A938;
        struct Work_8020A584 *work_8020A584;
        struct Work_8020D2A8 *work_8020D2A8;
        struct Work_8020DBC4 *work_8020DBC4;
    } work;
} Scpt;
s32 fn_800CD0B8(s32 a, s32 b, s32 c, s32 d);
void fn_80211058(Scpt *s, s32 a, s32 b, s32 c, s16 d, Ev *w);
void fn_802110E8(Scpt *s, s32 a, s32 b, s32 c, s16 d, EvHead *w);
#include "game/save_8030B7F4.h"
void fn_80210CE4(void);
void fn_80142C78(void *p);
void fn_80147DCC(void *p);
extern s32 lbl_8034757C;
s32 fn_801D6E38(s32 arg);
s32 SePlay(s32 bank, s8 arg1, s8 id);
void fn_8020EEE8(s32 bank, s8 arg1, s8 id, s32 unused);
float fn_801F6120(float **p);
/* An int argument of the script stream; FLT_MAX stands for 'unset' (0x7FFFFFFF). */
static inline s32 ReadInt(f32** p)
{
    if (3.4028235e38f == **p) {
        (*p)++;
        return 0x7FFFFFFF;
    }
    return (s32)fn_801F6120(p);
}
typedef struct Work801F8 {
    Ev ev;
    u8 pad14[0x4];
    u16 n;
    u8 pad1a[0x2];
    s32 x1c;
    s32 x20;
    f32 x24;
    f32 x28;
    u32 x2c;
    u8 pad30[0x14];
} Work801F8;
extern void* fn_801E1A2C(s32 a, s32 b);
extern void fn_801DBE1C(const char* fmt, ...);
typedef struct Work801FC {
    Ev ev;
    s32 x14;
    u16 n;
    u8 pad1a[0x2];
    f32 x1c;
    f32 x20;
    f32 x24;
    s32 x28;
    s32 x2c;
    s32 x30;
    f32 x34;
    u8 pad38[0xc];
} Work801FC;
extern void fn_801E1784(void* p);
extern void fn_80097294(u8 a);
typedef struct Work8020 {
    Ev ev;
    u8 pad14[0x4];
    u16 n;
    u8 pad1a[0x2];
    s32 x1c;
    f32 x20;
    f32 x24;
    f32 x28;
    u8 pad2c[0xc];
    s32 x38;
    s32 x3c;
    u8 pad40[0x4];
} Work8020;
typedef struct Sub { u8 pad00[8]; struct Actor *x8; u8 pad0c[0x1a0 - 0xc]; s32 x1a0; } Sub;
/* An actor: fn_8015F1A0's result, lbl_80347450, and the work of a task from fn_8010A164. */
typedef struct Actor {
    u8 pad00[0x2c];
    s32 x2c;
    u8 pad30[8];
    NJS_POINT3 pos;     /* 0x38 */
    s32 x44;
    s32 x48;
    s32 x4c;
    u8 pad_50[0xb0];
    s32 x100;
    u8 pad104[0x168 - 0x104];
    s16 x168;           /* 0x168 */
    u8 pad16a[0x1c8 - 0x16a];
    struct Info *x1c8;
    u8 pad1cc[0x1d8 - 0x1cc];
    Sub *x1d8;
    u8 pad1dc[0x26c - 0x1dc];
    u8 b26c;
} Actor;
/* lbl_80311970: the free camera. */
typedef struct {
    u8 pad00[8];
    f32* f8;            /* 0x08: eye point */
    u8 pad0c[4];
    f32 f[3];           /* 0x10 */
    s32 w[3];           /* 0x1c */
    u8 pad28[0x50 - 0x28];
    f32 x50;            /* 0x50: field of view */
} Cam8020C;
extern Cam8020C lbl_80311970;
extern s32 fn_80210064(s32 a);
extern s32 fn_8020F998(s32 a, f32* v, s32 c, s32 d, s32 e, s32 n);
extern s32 fn_8020FF44(s32 id, s32 b);
extern s32 fn_8020FDE0(s32 id, s32 b, s32 c, s32 d);
extern Actor* fn_8015F1A0(u16 id);
extern int sprintf(char* buf, const char* fmt, ...);
extern s32 fn_8021026C(const char* name);
typedef struct Info { u8 pad_00[0x10]; s32 *x10; u8 pad_14[0x30]; f32 x44, x48, x4c, x50, x54, x58; } Info;
typedef struct Args { s32 i[5]; f32 f[20]; } Args;
void fn_80155994(Args *a);
#define RDI(p) (*(p) == 3.4028235e38f ? ((p)++, 0x7FFFFFFF) : (s32)fn_801F6120(&(p)))
extern void ScreenFadeDraw(void *p, f32 a, f32 b, f32 c, f32 d, f32 e);
extern void njUnitMatrix(f32 *m);
extern void njRotateXYZ(f32 *m, s32 x, s32 y, s32 z);
extern void fn_80148188(s32 v);
/* lbl_802F7940: the script command table, indexed by Scpt.owner. */
typedef struct {
    s32 flags;
    u16 v;
    u8 pad6[2];
    s16 (*fn)(s32 flags, Scpt *s);
} CtlPart;
extern CtlPart lbl_802F7940[];
extern void fn_80210B44(s32 i);
typedef struct Obj10A { void (*fn)(struct Obj10A *); u8 pad4[0x15]; u8 x19; u8 pad1a[0xa]; Actor *x24; } Obj10A;
extern Actor *lbl_80347450;
extern Obj10A *fn_8010A164(u32 id);
extern void fn_801559BC(void *p);
void fn_80147DA8(s32 a, s32 b);
void fn_80147DC8(s32 a, s32 b);
extern void* memset(void* dst, int c, u32 n);
extern f32 fn_80291A5C(f32 v);
double atan2(double y, double x);
void fn_80211EB0(s16 mode, f32 v);
void fn_80213478(f32 *a, f32 *b, s32 *out);
typedef struct Work_80202004 {
    EvHead hd;
    u8 pad08[0x10];
    s32 x18;
    s32 x1c;
    s32 x20;
} Work_80202004;
typedef struct Lerp {
    s32 total;      /* 0x00 */
    s32 step[3];    /* 0x04 */
    s32 dest[3];    /* 0x10 */
} Lerp;
typedef struct Eff {
    f32 f[8];       /* 0x00 */
    s32 x20;
} Eff;
extern double sin(double);
extern double cos(double);
extern void fn_80212C04(f32 *a, f32 *b, f32 *c);
void fn_801558B0(s32 *v);
typedef struct Pair8 { s32 a; u8 b[8]; u8 c[8]; } Pair8;
void fn_80148464(Pair8 *v);
void fn_80213178(f32 t, f32 dur, f32 *p0, f32 *p1, f32 *p2, f32 *p3, f32 *out);
typedef struct Fx {
    Ev ev;
    u8 pad14[0x4];
    u16 x18;
    u8 pad1a[0x2];
    f32 x1c;
    f32 x20;
    f32 x24;
    f32 x28;
    f32 x2c;
    f32 x30;
    s32 x34;
    u8 pad38[0xc];
} Fx;
typedef struct Fx_801F8D0C {
    Ev ev;
    u8 pad14[0x4];
    u16 x18;
    u8 pad1a[0x2];
    s32 x1c;
    s32 x20;
    f32 x24;
    f32 x28;
    s32 x2c;
    u8 pad30[0x14];
} Fx_801F8D0C;
typedef struct Fx_801F8F7C {
    Ev ev;
    u8 pad14[0x4];
    u16 x18;
    u16 x1a;
    u8 pad1c[0x28];
} Fx_801F8F7C;
typedef struct Fx_801F9120 {
    Ev ev;
    u8 pad14[0x4];
    u16 x18;
    u16 x1a;
    s32 x1c;
    f32 x20;
    f32 x24;
    f32 x28;
    f32 x2c;
    f32 x30;
    f32 x34;
    u8 pad38[0xc];
} Fx_801F9120;
typedef struct Fx_801FBBA8 {
    Ev ev;
    u8 pad14[0x4];
    u16 x18;
    u8 pad1a[0x2];
    s32 x1c;
    s32 x20;
    f32 x24;
    u8 pad28[0x1c];
} Fx_801FBBA8;
typedef struct ScrState {
    u8 pad0[0x1c];
    s32 mode;
    s32 count;
    u8 pad24[0x20];
} ScrState;
typedef struct Work_8020184C {
    Ev ev;
    u8 pad14[0x4];
    u16 n;
    u8 pad1a[0x2];
    u32 x1c;
    u8 pad20[0x24];
} Work_8020184C;
typedef struct Work_802019F8 {
    EvHead hd;
    u8 pad08[0x10];
    s32 x18;
    s32 x1c;
    s32 x20;
    u8 pad24[0x20];
} Work_802019F8;
typedef struct Work_80207CD0 {
    Ev ev;
    u8 pad14[0x4];
    u16 id;
    u16 v;
    f32 f0;
    f32 f1;
    f32 f2;
} Work_80207CD0;
typedef struct Rec {
    Ev ev;
    u8 pad14[0x4];
    u16 n;
    u8 pad1a[0x2];
    f32 f1c;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2c;
    f32 f30;
    s32 i34;
    u8 pad38[0xc];
} Rec;
typedef struct Rec_80208424 {
    Ev ev;
    u8 pad14[0x4];
    u16 n;
    u8 pad1a[0x2];
    s32 i1c;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2c;
    f32 f30;
    s32 i34;
    u8 pad38[0xc];
} Rec_80208424;
typedef struct Rec_80208A20 {
    Ev ev;
    u8 pad14[0x4];
    u16 n;
    u8 pad1a[0x2];
    s32 i1c;
    s32 i20;
    f32 f24;
    f32 f28;
    f32 f2c;
    f32 f30;
    s32 i34;
    u8 pad38[0xc];
} Rec_80208A20;
typedef struct Rec_80209974 {
    Ev ev;
    u8 pad14[0x4];
    u16 n;
    u16 n2;
    f32 f1c;
    f32 f20;
    f32 f24;
    s32 i28;
    u8 pad2c[0x18];
} Rec_80209974;
typedef struct Work_8020A938 {
    EvHead hd;
    void *x08;
} Work_8020A938;
void fn_80148228(s32 a, s32 b);
extern s32 strlen(const char *s);
extern s32 fn_8025EF88(const char *a, const char *b);
extern void fn_801D6CBC(s32 chan, Pat *p);
extern void fn_801D6C3C(s32 chan);
extern int sprintf(char* buf, const char* fmt, ...);
extern s32 fn_800CCCA4(u32 a, u32 b, u32 c);
extern char *strcpy(void *dst, const char *src);
typedef struct Scpt_802139F8 {
    u8 pad0[0x1c];
    float* cur;
} Scpt_802139F8;
typedef struct Args14 { s32 i[14]; } Args14;
void fn_8015596C(void* p);
void fn_80155944(s32 *a);
typedef struct MapInfo {
    s32 map;        /* 0x00 */
    s32 area;       /* 0x04 */
    char room;      /* 0x08 */
} MapInfo;
extern MapInfo lbl_80311AC0;
/* void fn_801F452C(s32) in the unit */
extern void fn_801DBE1C(const char* fmt, ...);
s32 fn_8020FB10(s32 a, f32 f, s32 b, s32 c, s32 n, s32 e);
s32 fn_8020FC7C(s32 id, s32 b, s32 c, s32 d);
s32 fn_8020F934(s32 id);

extern void fn_801DBE1C(const char *fmt, ...);

float fn_801F6120(float **p);

void fn_8021331C(s32 n, f32 **in, f32 **out);
void fn_80213718(f32 *pt, s32 *ang, f32 *out, f32 d);
f32 fn_80212A78(s32 kind, f32 t, f32 dur);

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

void fn_8021331C(s32 n, f32 **in, f32 **out);
void fn_80213718(f32 *pt, s32 *ang, f32 *out, f32 d);
f32 fn_80212A78(s32 kind, f32 t, f32 dur);

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
extern s32 fn_80210F74(Scpt *s);
extern u32 fn_802107A4(Scpt *s, s32 id);
extern u32 fn_80210860(Scpt *s, u16 id);

void fn_8020EEE8(s32 bank, s8 arg1, s8 id, s32 unused) {
    u32 r = SePlay(bank, arg1, id);
    if (r) {
        lbl_8030CEA0.x157c = r;
    } else {
        lbl_8030CEA0.x157c = 0;
    }
}

s32 fn_8020EF30(s32 a)
{
    Scpt s;
    Fx_801F9120 *w;

    w = fn_801E1A2C(1, 0x44);
    if (w == 0) {
        return 0;
    }
    s.work.fx_801F9120 = w;
    w->x18 = a;
    w->x1c = w->x18;
    w->ev.hd.kind = 0;
    fn_80211058(&s, 9, w->x18, 2, lbl_8030CEA0.x08, &w->ev);
    s.owner = 0x63;
    s.kind = 1;
    s.cur.i = 0;
    s.cnt = 0;
    fn_80210F74(&s);
    return 1;
}

s32 fn_8020EFD4(s32 a)
{
    Scpt s;
    Fx_801F9120 *w;

    w = fn_801E1A2C(1, 0x44);
    if (w == 0) {
        return 0;
    }
    s.work.fx_801F9120 = w;
    w->x18 = a;
    w->x1c = w->x18;
    w->ev.hd.kind = 0;
    fn_80211058(&s, 9, w->x18, 1, lbl_8030CEA0.x08, &w->ev);
    s.owner = 0x62;
    s.kind = 1;
    s.cur.i = 0;
    s.cnt = 0;
    fn_80210F74(&s);
    return 1;
}

s32 fn_8020F154(s16 a, s32 b)
{
    Scpt c2;
    Scpt c1;
    Actor *o;
    Obj10A *t;
    Fx_801F8F7C *r;
    do {
        if ((u16)b == 0xffff) {
            o = lbl_80347450;
        } else {
            t = fn_8010A164(b);
            if (t == 0) {
                break;
            }
            o = t->x24;
        }
        if (o != 0 && o->x1d8->x8 == 0) {
            if (fn_80210860(&c1, b) != 0) {
                c1.owner = 0x1a;
                c1.kind = 1;
                c1.cur.i = 0;
                c1.cnt = 0;
                fn_80210F74(&c1);
            }
        }
    } while (0);
    r = fn_801E1A2C(1, 0x44);
    if (r == 0) {
        return 0;
    }
    c2.work.fx_801F8F7C = r;
    r->x18 = a;
    r->x1a = b;
    r->ev.hd.kind = 0;
    fn_80211058(&c2, 6, r->x1a, 0x1a, lbl_8030CEA0.x08, &r->ev);
    c2.owner = 0x6b;
    c2.kind = 1;
    c2.cur.i = 0;
    c2.cnt = 0;
    fn_80210F74(&c2);
    return 1;
}

s32 fn_8020F278(u16 a, s32 b, s32 id, f32* p, f32* q)
{
    Scpt m2;
    Scpt m1;
    Fx_801F9120* w;
    Actor* o;
    do {
        if ((u16)id == 0xffff) {
            o = lbl_80347450;
        } else {
            Obj10A* r = fn_8010A164(id);
            if (r == NULL) break;
            o = r->x24;
        }
        if (o == NULL) break;
        if (o->x1d8->x8 != 0) break;
        if (fn_80210860(&m1, id) == 0) break;
        m1.owner =0x1a;
        m1.kind = 1;
        m1.cur.f = NULL;
        m1.cnt = 0;
        fn_80210F74(&m1);
    } while (0);
    w = fn_801E1A2C(1, 0x44);
    if (w == NULL) return 0;
    m2.work.fx_801F9120 = w;
    w->x18 = a;
    w->x1c = b;
    w->x1a = id;
    w->x20 = p[0];
    w->x24 = p[1];
    w->x28 = p[2];
    w->x2c = q[0];
    w->x30 = q[1];
    w->x34 = q[2];
    w->ev.hd.kind = 0;
    fn_80211058(&m2, 6, w->x1a, 0x19, lbl_8030CEA0.x08, &w->ev);
    m2.owner =0x6a;
    m2.kind = 1;
    m2.cur.f = NULL;
    m2.cnt = 0;
    fn_80210F74(&m2);
    return 1;
}

s32 fn_8020F998(s32 a, f32* v, s32 c, s32 d, s32 e, s32 n)
{
    Scpt m2;
    Scpt m1;
    Work801FC* w;
    Actor* o;
    do {
        if ((u16)a == 0xffff) {
            o = lbl_80347450;
        } else {
            Obj10A* r = fn_8010A164(a);
            if (r == NULL) break;
            o = r->x24;
        }
        if (o == NULL) break;
        if (o->x1d8->x8 != 0) break;
        if (fn_80210860(&m1, a) == 0) break;
        m1.owner =0x1a;
        m1.kind = 1;
        m1.cur.f = NULL;
        m1.cnt = 0;
        fn_80210F74(&m1);
    } while (0);
    w = fn_801E1A2C(1, 0x44);
    if (w == NULL) return 0;
    m2.work.work801FC = w;
    w->n = a;
    w->x1c = v[0];
    w->x20 = v[1];
    w->x24 = v[2];
    w->x28 = c;
    w->x2c = d;
    w->x30 = e;
    w->x34 = (f32)n / 100.0f;
    w->ev.hd.kind = 0;
    w->x14 = 1;
    fn_80211058(&m2, 6, w->n, 0xa, lbl_8030CEA0.x08, &w->ev);
    m2.owner =0x24;
    m2.kind = 1;
    m2.cur.f = NULL;
    m2.cnt = 0;
    fn_80210F74(&m2);
    return 1;
}

s32 fn_8020FB10(s32 a, f32 f, s32 b, s32 c, s32 n, s32 e)
{
    Scpt m2;
    Scpt m1;
    Fx_801F8D0C* w;
    Actor* o;
    do {
        if ((u16)a == 0xffff) {
            o = lbl_80347450;
        } else {
            Obj10A* r = fn_8010A164(a);
            if (r == NULL) break;
            o = r->x24;
        }
        if (o == NULL) break;
        if (o->x1d8->x8 != 0) break;
        if (fn_80210860(&m1, a) == 0) break;
        m1.owner =0x1a;
        m1.kind = 1;
        m1.cur.f = NULL;
        m1.cnt = 0;
        fn_80210F74(&m1);
    } while (0);
    w = fn_801E1A2C(1, 0x44);
    if (w == NULL) return 0;
    m2.work.fx_801F8D0C = w;
    w->x18 = a;
    w->x1c = b;
    w->x20 = c;
    w->x24 = (f32)n / 100.0f;
    w->x28 = f;
    w->x2c = e;
    w->ev.hd.kind = 0;
    fn_80211058(&m2, 6, w->x18, 0x20, lbl_8030CEA0.x08, &w->ev);
    m2.owner =0x1d;
    m2.kind = 1;
    m2.cur.f = NULL;
    m2.cnt = 0;
    fn_80210F74(&m2);
    return 1;
}

s32 fn_8020FC7C(s32 id, s32 b, s32 c, s32 d) {
    Scpt s2;
    Scpt s1;
    Actor *o;
    Obj10A *t;
    Work801F8 *w;
    do {
        if ((u16)id == 0xffff) {
            o = lbl_80347450;
        } else {
            t = fn_8010A164(id);
            if (t == 0) {
                break;
            }
            o = t->x24;
        }
        if (o != 0 && o->x1d8->x8 == 0) {
            if (fn_80210860(&s1, id) != 0) {
                s1.owner = 0x1a;
                s1.kind = 1;
                s1.cur.i = 0;
                s1.cnt = 0;
                fn_80210F74(&s1);
            }
        }
    } while (0);
    w = fn_801E1A2C(1, 0x44);
    if (w == 0) {
        return 0;
    }
    s2.work.work801F8 = w;
    w->n = id;
    w->x1c = b;
    w->x20 = c;
    w->x24 = (f32)d / 100.0f;
    w->ev.hd.kind = 0;
    fn_80211058(&s2, 6, w->n, 0x12, lbl_8030CEA0.x08, &w->ev);
    s2.owner = 0x1c;
    s2.kind = 1;
    s2.cur.i = 0;
    s2.cnt = 0;
    fn_80210F74(&s2);
    return 1;
}

s32 fn_8020FDE0(s32 id, s32 b, s32 c, s32 d) {
    Scpt s2;
    Scpt s1;
    Actor *o;
    Obj10A *t;
    Work801F8 *w;
    do {
        if ((u16)id == 0xffff) {
            o = lbl_80347450;
        } else {
            t = fn_8010A164(id);
            if (t == 0) {
                break;
            }
            o = t->x24;
        }
        if (o != 0 && o->x1d8->x8 == 0) {
            if (fn_80210860(&s1, id) != 0) {
                s1.owner = 0x1a;
                s1.kind = 1;
                s1.cur.i = 0;
                s1.cnt = 0;
                fn_80210F74(&s1);
            }
        }
    } while (0);
    w = fn_801E1A2C(1, 0x44);
    if (w == 0) {
        return 0;
    }
    s2.work.work801F8 = w;
    w->n = id;
    w->x1c = b;
    w->x20 = c;
    w->x24 = (f32)d / 100.0f;
    w->ev.hd.kind = 0;
    fn_80211058(&s2, 6, w->n, 0x13, lbl_8030CEA0.x08, &w->ev);
    s2.owner = 0x1d;
    s2.kind = 1;
    s2.cur.i = 0;
    s2.cnt = 0;
    fn_80210F74(&s2);
    return 1;
}

s32 fn_8020FF44(s32 id, s32 b) {
    Scpt s2;
    Scpt s1;
    Actor *o;
    Obj10A *t;
    Work801F8 *w;
    do {
        if ((u16)id == 0xffff) {
            o = lbl_80347450;
        } else {
            t = fn_8010A164(id);
            if (t == 0) {
                break;
            }
            o = t->x24;
        }
        if (o != 0 && o->x1d8->x8 == 0) {
            if (fn_80210860(&s1, id) != 0) {
                s1.owner = 0x1a;
                s1.kind = 1;
                s1.cur.i = 0;
                s1.cnt = 0;
                fn_80210F74(&s1);
            }
        }
    } while (0);
    w = fn_801E1A2C(1, 0x44);
    if (w == 0) {
        return 0;
    }
    s2.work.work801F8 = w;
    w->n = id;
    w->x1c = b;
    w->ev.hd.kind = 0;
    fn_80211058(&s2, 6, w->n, 3, lbl_8030CEA0.x08, &w->ev);
    s2.owner = 0x61;
    s2.kind = 1;
    s2.cur.i = 0;
    s2.cnt = 0;
    fn_80210F74(&s2);
    return 1;
}

s32 fn_802100C8(s32 id, s16 a, s16 b, s16 c, f32 x, f32 y, f32 z) {
    Scpt s2;
    Scpt s1;
    Actor *o;
    Obj10A *t;
    Work8020 *w;
    u16 uid = id;
    do {
        if (uid == 0xffff) {
            o = lbl_80347450;
        } else {
            t = fn_8010A164(uid);
            if (t == 0) {
                break;
            }
            o = t->x24;
        }
        if (o != 0 && o->x1d8->x8 == 0) {
            if (fn_80210860(&s1, uid) != 0) {
                s1.owner = 0x1a;
                s1.kind = 1;
                s1.cur.i = 0;
                s1.cnt = 0;
                fn_80210F74(&s1);
            }
        }
    } while (0);
    w = fn_801E1A2C(1, 0x44);
    if (w == 0) {
        fn_801DBE1C("Proll: malloc failed");
    }
    s2.work.work8020 = w;
    w->n = id;
    w->x1c = a;
    w->x20 = x;
    w->x24 = y;
    w->x28 = z;
    w->x38 = b;
    w->x3c = c;
    if (w->x38 == 0x7fffffff) {
        w->x38 = 0;
    }
    if (w->x1c == 0x7fffffff) {
        w->x1c = 0;
    }
    w->ev.hd.kind = 0;
    fn_80211058(&s2, 6, w->n, 0x22, lbl_8030CEA0.x08, &w->ev);
    s2.owner = 0x86;
    s2.kind = 1;
    s2.cur.i = 0;
    s2.cnt = 0;
    fn_80210F74(&s2);
    return 1;
}

/* Copies src into the first free slot of lbl_8030CEA0.x10 (fn_80210F74, inlined). */
static inline s32 ScptAdd(Scpt* src) {
    Scpt* base = lbl_8030CEA0.x10;
    Scpt* e = base;
    s32 i;
    for (i = 0; i < 0x180; e++, i++) {
        if (e->kind == 0) {
            base[i] = *src;
            lbl_8030CEA0.x10[i].x14 = i;
            lbl_8030CEA0.x0a++;
            if (src->ev != 0) {
                src->ev->hd.x04 = i;
            }
            return 1;
        }
    }
    return 0;
}

s32 fn_80210F74(Scpt* src) {
    Scpt* base = lbl_8030CEA0.x10;
    Scpt* e = base;
    s32 i;
    for (i = 0; i < 0x180; e++, i++) {
        if (e->kind == 0) {
            base[i] = *src;
            lbl_8030CEA0.x10[i].x14 = i;
            lbl_8030CEA0.x0a++;
            if (src->ev != 0) {
                src->ev->hd.x04 = i;
            }
            return 1;
        }
    }
    return 0;
}

void fn_802110E8(Scpt *s, s32 a, s32 b, s32 c, s16 d, EvHead *w)
{
    s32 k;
    s->ev = 0;
    k = (c << 16) | (u16)d;
    s->handle = fn_800CD0B8(a, b, k, (s32)w);
    s->a20 = a;
    s->a24 = (u16)b;
    s->a28 = k;
    s->a2c = (s32)w;
    lbl_8030CEA0.x08++;
}

void fn_80212084(void) {
    lbl_8030CEA0.x828 = fn_801D6E38(lbl_8034757C) ? lbl_8034757C : -1;
    memset(lbl_8030CEA0.steps, 0, sizeof(lbl_8030CEA0.steps));
    fn_801D6C3C(lbl_8030CEA0.x828);
    lbl_8030CEA0.x82c = 0;
    lbl_8030CEA0.x830 = lbl_8030CEA0.x834 = 0;
    lbl_8030CEA0.pat.a = 1;
    lbl_8030CEA0.pat.b = 1;
    lbl_8030CEA0.pat.e = 0;
    lbl_8030CEA0.pat.d = 0;
    lbl_8030CEA0.pat.c = 0;
}

/* The offset fn_80213718 rotates (0x10 bytes of .data; z is set per call). */
extern NJS_POINT3 lbl_802F85B8;

void fn_80213718(f32 *src, Angle *rot, f32 *dst, f32 z)
{
    NJS_MATRIX m;
    NJS_POINT3 p;
    Angle rx;
    Angle ry;
    Angle rz;
    if (rot != 0) {
        lbl_802F85B8.z = z;
        rz = rot[2];
        ry = rot[1];
        rx = rot[0];
        if (&lbl_802F85B8 != 0 && &p != 0) {
            njUnitMatrix(m);
            njRotateXYZ(m, rx, ry, rz);
            njCalcPoint(m, &lbl_802F85B8, &p);
        }
        dst[0] = src[0] - p.x;
        dst[1] = src[1] - p.y;
        dst[2] = src[2] - p.z;
    }
}

s32 fn_802138A0(u32 a, Scpt *st) {
    if (a & 1) {
        u8 *c = st->cur.b;
        st->cur.b = c + 4;
        fn_80142C78(c);
        return 0;
    }
    return 1;
}

s32 fn_802138E0(u32 a, Scpt *st) {
    if (a & 1) {
        u8 *c = st->cur.b;
        st->cur.b = c + 4;
        fn_80142CD8(c);
        return 0;
    }
    return 1;
}

s32 fn_80214908(u32 a, Scpt *st) {
    if (a & 1) {
        u8 *c = st->cur.b;
        u8 *q = c + 4;
        u32 off = *(u32 *)(c + 4);
        st->cur.b = q + 4;
        fn_80147DCC(q + off);
        return 0;
    }
    return 1;
}

s32 fn_80214954(u32 a, Scpt *st) {
    if (a & 1) {
        u8 *c = st->cur.b;
        st->cur.b = c + 4;
        fn_80147DF8(c);
        return 0;
    }
    return 1;
}

s32 fn_80214994(u32 a, Scpt *st) {
    if (a & 1) {
        u8 *c = st->cur.b;
        u8 *q = c + 4;
        u32 off = *(u32 *)(c + 4);
        st->cur.b = q + 4;
        fn_80147E2C(q + off);
        return 0;
    }
    return 1;
}

s32 fn_802149E0(u32 a, Scpt *st) {
    if (a & 1) {
        u8 *c = st->cur.b;
        st->cur.b = c + 4;
        fn_80148108(c);
        return 0;
    }
    return 1;
}

s32 fn_80214A20(u32 a, Scpt *st) {
    if (a & 1) {
        u8 *c = st->cur.b;
        st->cur.b = c + 4;
        fn_80148124(c);
        return 0;
    }
    return 1;
}

s32 fn_80214A60(u32 a, Scpt *st) {
    if (a & 1) {
        u8 *c = st->cur.b;
        st->cur.b = c + 4;
        fn_80148160(c);
        return 0;
    }
    return 1;
}

float fn_801F6120(float **p);
void fn_8014818C(u16 a, s32 b);
s32 fn_80214B28(u32 flags, Scpt *c) {
    float *p;
    u16 a;
    s32 t;
    s32 b;
    if (flags & 1) {
        p = c->cur.f;
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
        c->cur.f = p;
        fn_8014818C(a, b);
        return 0;
    }
    return 1;
}

extern void fn_80147EA4(s32 v);
s32 fn_80214CDC(s32 flags, Scpt *s) {
    f32 *cur;
    s32 v;
    if (flags & 1) {
        cur = s->cur.f;
        cur++;
        if (3.4028235e38f == *cur) {
            cur++;
            v = 0x7FFFFFFF;
        } else {
            v = (s32)fn_801F6120(&cur);
        }
        s->cur.f = cur;
        fn_80147EA4(v);
        return 0;
    }
    return 1;
}

extern void fn_80147EA8(s32 v);
s32 fn_80214D6C(s32 flags, Scpt *s) {
    f32 *cur;
    s32 v;
    if (flags & 1) {
        cur = s->cur.f;
        cur++;
        if (3.4028235e38f == *cur) {
            cur++;
            v = 0x7FFFFFFF;
        } else {
            v = (s32)fn_801F6120(&cur);
        }
        s->cur.f = cur;
        fn_80147EA8(v);
        return 0;
    }
    return 1;
}

extern void fn_80147EAC(s32 v);
s32 fn_80214DFC(s32 flags, Scpt *s) {
    f32 *cur;
    s32 v;
    if (flags & 1) {
        cur = s->cur.f;
        cur++;
        if (3.4028235e38f == *cur) {
            cur++;
            v = 0x7FFFFFFF;
        } else {
            v = (s32)fn_801F6120(&cur);
        }
        s->cur.f = cur;
        fn_80147EAC(v);
        return 0;
    }
    return 1;
}

extern void fn_801486CC(s32 v);
s32 fn_80214E8C(s32 flags, Scpt *s) {
    f32 *cur;
    s32 v;
    if (flags & 1) {
        cur = s->cur.f;
        cur++;
        if (3.4028235e38f == *cur) {
            cur++;
            v = 0x7FFFFFFF;
        } else {
            v = (s32)fn_801F6120(&cur);
        }
        s->cur.f = cur;
        fn_801486CC(v);
        return 0;
    }
    return 1;
}

extern void fn_80148BE8(s32 v);
s32 fn_80214F1C(s32 flags, Scpt *s) {
    f32 *cur;
    s32 v;
    if (flags & 1) {
        cur = s->cur.f;
        cur++;
        if (3.4028235e38f == *cur) {
            cur++;
            v = 0x7FFFFFFF;
        } else {
            v = (s32)fn_801F6120(&cur);
        }
        s->cur.f = cur;
        fn_80148BE8(v);
        return 0;
    }
    return 1;
}

extern void fn_80148CAC(s32 v);
s32 fn_80214FAC(s32 flags, Scpt *s) {
    f32 *cur;
    s32 v;
    if (flags & 1) {
        cur = s->cur.f;
        cur++;
        if (3.4028235e38f == *cur) {
            cur++;
            v = 0x7FFFFFFF;
        } else {
            v = (s32)fn_801F6120(&cur);
        }
        s->cur.f = cur;
        fn_80148CAC(v);
        return 0;
    }
    return 1;
}

s32 fn_8021503C(u32 a, Scpt *st) {
    if (a & 1) {
        u8 *c = st->cur.b;
        st->cur.b = c + 4;
        fn_80148190(c);
        return 0;
    }
    return 1;
}

s32 fn_8021507C(u32 a, Scpt *st) {
    if (a & 1) {
        u8 *c = st->cur.b;
        st->cur.b = c + 4;
        fn_801481B0(c);
        return 0;
    }
    return 1;
}

s32 fn_802150BC(u32 a, Scpt *st) {
    if (a & 1) {
        u8 *c = st->cur.b;
        st->cur.b = c + 4;
        fn_801481D0(c);
        return 0;
    }
    return 1;
}
void fn_8014836C(u16 a, s32 b);
s32 fn_80215368(u32 flags, Scpt *c) {
    float *p;
    u16 a;
    s32 t;
    s32 b;
    if (flags & 1) {
        p = c->cur.f;
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
        c->cur.f = p;
        fn_8014836C(a, b);
        return 0;
    }
    return 1;
}
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
/* The argument block fn_80148954 takes. */
typedef struct {
    s32 x00;
    s32 x04;
    s32 x08;
    s32 x0c;
    s32 x10;
    s32 x14;
    s32 x18;
    s32 x1c;
    s32 x20;
    s16 h24;
    s16 h26;
    s16 h28;
    s16 h2a;
    f32 f2c;
    f32 f30;
    f32 f34;
    f32 f38;
    s16 h3c;
    s16 h3e;
} Args40;
extern void fn_80148954(Args40* a);

static inline u16 ReadU16(f32** p)
{
    return ReadInt(p);
}

s32 fn_80215590(u32 flags, Scpt* c)
{
    f32* p;
    Args40 a;
    if (flags & 1) {
        p = c->cur.f;
        p++;
        a.x00 = ReadU16(&p);
        a.x04 = ReadInt(&p);
        a.x08 = ReadInt(&p);
        a.x0c = ReadInt(&p);
        a.x10 = ReadInt(&p);
        a.x14 = ReadInt(&p);
        a.x18 = ReadInt(&p);
        a.x1c = ReadInt(&p);
        a.x20 = ReadU16(&p);
        a.h24 = ReadInt(&p);
        a.h26 = ReadInt(&p);
        a.h28 = ReadInt(&p);
        a.h2a = ReadInt(&p);
        a.f2c = fn_801F6120(&p);
        a.f30 = fn_801F6120(&p);
        a.f34 = fn_801F6120(&p);
        a.f38 = fn_801F6120(&p);
        a.h3c = ReadInt(&p);
        a.h3e = ReadInt(&p);
        c->cur.f = p;
        fn_80148954(&a);
        return 0;
    }
    return 1;
}

s32 fn_80212050(void) {
    return fn_801D6E38(lbl_8034757C) != 0 ? lbl_8034757C : -1;
}

void fn_80097294(u8 a);

s32 fn_80213FE8(u32 flags, Scpt *c)
{
    float *p;
    Args b;
    if (flags & 1) {
        p = c->cur.f;
        p++;
        b.i[0] = RDI(p);
        b.i[1] = RDI(p);
        b.i[2] = RDI(p);
        b.i[3] = RDI(p);
        b.i[4] = RDI(p);
        b.f[0] = fn_801F6120(&p);
        b.f[1] = fn_801F6120(&p);
        b.f[2] = fn_801F6120(&p);
        b.f[3] = fn_801F6120(&p);
        b.f[4] = fn_801F6120(&p);
        b.f[5] = fn_801F6120(&p);
        b.f[6] = fn_801F6120(&p);
        b.f[7] = fn_801F6120(&p);
        b.f[8] = fn_801F6120(&p);
        b.f[9] = fn_801F6120(&p);
        b.f[10] = fn_801F6120(&p);
        b.f[11] = fn_801F6120(&p);
        b.f[12] = fn_801F6120(&p);
        b.f[13] = fn_801F6120(&p);
        b.f[14] = fn_801F6120(&p);
        b.f[15] = fn_801F6120(&p);
        b.f[16] = fn_801F6120(&p);
        b.f[17] = fn_801F6120(&p);
        b.f[18] = fn_801F6120(&p);
        b.f[19] = fn_801F6120(&p);
        c->cur.f = p;
        fn_80155994(&b);
        return 0;
    }
    return 1;
}

void fn_80210338(void)
{
    if (lbl_8030CEA0.xc5c != 0) {
        if (lbl_8030CEA0.xc60.w & 0xFF000000) {
            ScreenFadeDraw(&lbl_8030CEA0.xc60, lbl_8030CEA0.xc64, 0.0f, 640.0f, 0.0f, 480.0f);
        }
    }
}

s32 fn_802114AC(s32 a, s32 b)
{
    Slot8 *arr = lbl_8030CEA0.x14;
    Slot8 *q = arr;
    s32 i;

    for (i = 0; i < 0x180; i++) {
        if (q->b == 0) {
            arr[i].a = a;
            lbl_8030CEA0.x14[i].b = b;
            return 1;
        }
        q++;
    }
    return 0;
}

void fn_802136A8(void *a, void *b, s32 x, s32 y, s32 z)
{
    f32 m[16];

    if (a != 0 && b != 0) {
        njUnitMatrix(m);
        njRotateXYZ(m, x, y, z);
        njCalcPoint(m, a, b);
    }
}

s32 fn_80214AA0(s32 flags, Scpt *obj)
{
    float *cur;
    s32 r;

    if (flags & 1) {
        cur = obj->cur.f;
        cur++;
        if (*cur == 3.4028235e38f) {
            cur++;
            r = 0x7fffffff;
        } else {
            r = (s32)fn_801F6120(&cur);
        }
        obj->cur.f = cur;
        fn_80148188(r);
    }
    return 0;
}

void fn_8020F078(f32 *a, f32 *b) {
    f32 k = 182.04444885f;
    lbl_8030CEA0.x18fc = a[0];
    lbl_8030CEA0.x1900 = a[1];
    lbl_8030CEA0.x1904 = a[2];
    lbl_8030CEA0.x1908 = (s32)(k * b[0]);
    lbl_8030CEA0.x190c = (s32)(k * b[1]);
    lbl_8030CEA0.x1910 = (s32)(k * b[2]);
}

s32 fn_8020F934(s32 id)
{
    Scpt s;

    if (fn_802107A4(&s, (u16)id) == 0) {
        return 0;
    }
    s.owner = 0x29;
    s.kind = 1;
    s.cur.i = 0;
    s.cnt = 0;
    fn_80210F74(&s);
    return 1;
}

s32 fn_80210064(s32 id)
{
    Scpt s;

    if (fn_80210860(&s, (u16)id) == 0) {
        return 0;
    }
    s.owner = 0x1a;
    s.kind = 1;
    s.cur.i = 0;
    s.cnt = 0;
    fn_80210F74(&s);
    return 1;
}

void fn_8020F0F0(void) {
    lbl_8030CEA0.x18fc = lbl_80311970.f[0];
    lbl_8030CEA0.x1900 = lbl_80311970.f[1];
    lbl_8030CEA0.x1904 = lbl_80311970.f[2];
    lbl_8030CEA0.x1908 = lbl_80311970.w[0];
    lbl_8030CEA0.x190c = lbl_80311970.w[1];
    lbl_8030CEA0.x1910 = lbl_80311970.w[2];
    fn_80097294(0);
}

void fn_80210CE4(void)
{
    s32 i;

    for (i = 0; i < 0x180; i++) {
        Scpt *e = &lbl_8030CEA0.x10[i];
        if (e->kind == 1 && lbl_802F7940[e->owner].v == 0xfffe) {
            fn_80210B44(i);
        }
    }
}

void fn_80210EA4(u32 id, s32 v)
{
    void *p;
    Obj10A *o;
    s32 i;

    if ((u16)id == 0xffff) {
        p = lbl_80347450;
    } else {
        o = fn_8010A164(id);
        if (o != NULL) {
            p = o->x24;
        }
    }
    if (p != NULL) {
        for (i = 0; i < 0x180; i++) {
            Scpt *e = &lbl_8030CEA0.x10[i];
            if (e->a20 == 6 || e->a20 == 9) {
                if ((u16)id == (u16)e->a24 && v == lbl_802F7940[e->owner].v) {
                    fn_80210B44(i);
                }
            }
        }
    }
}

s32 fn_802137D0(u32 flags, Scpt *c)
{
    f32 *p;
    s32 *list;
    s32 i;
    s32 n;

    if (flags & 1) {
        p = c->cur.f;
        list = (s32 *)++p;
        p++;
        n = *list;
        for (i = 0; i < n; i++) {
            if (3.4028235e38f == *p) {
                p++;
            } else {
                fn_801F6120(&p);
            }
        }
        fn_801559BC(list);
        c->cur.f = p;
        return 0;
    }
    return 1;
}

s32 fn_80213920(u32 flags, Scpt *st) {
    if (flags & 1) {
        float *p = st->cur.f;
        s32 a, b;
        p++;
        if (*p == 3.4028235e38f) {
            p++;
            a = 0x7FFFFFFF;
        } else {
            a = (s32)fn_801F6120(&p);
        }
        if (*p == 3.4028235e38f) {
            p++;
            b = 0x7FFFFFFF;
        } else {
            b = (s32)fn_801F6120(&p);
        }
        fn_80147DA8(a, b);
        st->cur.f = p;
        return 0;
    }
    return 1;
}

s32 fn_80214C04(u32 flags, Scpt *st) {
    if (flags & 1) {
        float *p = st->cur.f;
        s32 a, b;
        p++;
        if (*p == 3.4028235e38f) {
            p++;
            a = 0x7FFFFFFF;
        } else {
            a = (s32)fn_801F6120(&p);
        }
        if (*p == 3.4028235e38f) {
            p++;
            b = 0x7FFFFFFF;
        } else {
            b = (s32)fn_801F6120(&p);
        }
        st->cur.f = p;
        fn_80147DC8(a, b);
        return 0;
    }
    return 1;
}

void fn_802135B4(NJS_POINT3* v, s32* out) {
    f32 xz = v->x * v->x + v->z * v->z;
    if (0.0f == xz + v->y * v->y) {
        out[1] = 0;
        out[0] = 0;
    } else {
        f32 a = (f32)atan2(-v->y, fn_80291A5C(xz));
        out[0] = (s32)(10430.381f * a);
        if (0.0f == v->x && 0.0f == v->z) {
            out[1] = 0;
        } else {
            a = (f32)atan2(v->x, v->z);
            out[1] = (s32)(10430.381f * a);
        }
    }
    out[2] = 0;
}

f32 fn_80212A78(s32 kind, f32 t, f32 dur)
{
    f32 r;

    if (t < 0.0f) {
        return 0.0f;
    }
    if (t > dur) {
        return 1.0f;
    }
    switch (kind) {
    case 0:
        return t / dur;
    case 1:
        if (t <= 0.5f * dur) {
            r = 1.0 - cos(1.570796f * (t / dur));
            return r * r;
        }
        r = 1.0 - sin(1.570796f * (1.0f - t / dur));
        return r * r;
    case 2:
        if (t <= 0.5f * dur) {
            r = sin(1.570796f * (t / dur));
            return r * r;
        }
        r = cos(1.570796f * (1.0f - t / dur));
        return r * r;
    case 3:
        if (t <= 0.5f * dur) {
            r = 0.5 - 0.5 * cos(3.141592f * (t / dur));
            return r * r;
        }
        r = 0.5 + 0.5 * sin(3.141592f * (t / dur - 0.5f));
        return r * r;
    default:
        return 0.0f;
    }
}

void fn_8021331C(s32 n, f32 **in, f32 **out)
{
    s32 i;

    for (i = 0; i < n - 1; i++) {
        out[2 * i][0] = (2.0f * in[i][0] + in[i + 1][0]) * 0.33333334f;
        out[2 * i][1] = (2.0f * in[i][1] + in[i + 1][1]) * 0.33333334f;
        out[2 * i][2] = (2.0f * in[i][2] + in[i + 1][2]) * 0.33333334f;
        out[2 * i + 1][0] = (2.0f * in[i + 1][0] + in[i][0]) * 0.33333334f;
        out[2 * i + 1][1] = (2.0f * in[i + 1][1] + in[i][1]) * 0.33333334f;
        out[2 * i + 1][2] = (2.0f * in[i + 1][2] + in[i][2]) * 0.33333334f;
    }
    for (i = 1; i < n - 1; i++) {
        fn_80212C04(out[2 * i - 1], in[i], out[2 * i]);
    }
}

s32 fn_80213DD0(u32 flags, Scpt *c) {
    float *p;
    s32 v[7];
    if (flags & 1) {
        p = c->cur.f;
        p++;
#define RD(k) v[k] = (*p == 3.4028235e38f ? (p++, 0x7FFFFFFF) : (s32)fn_801F6120(&p));
        RD(0) RD(1) RD(2) RD(3) RD(4) RD(5) RD(6)
        c->cur.f = p;
        fn_801558B0(v);
        return 0;
    }
    return 1;
}

s32 fn_80215444(u32 flags, Scpt *c) {
    float *p;
    Pair8 v;
    s32 i;
    if (flags & 1) {
        p = c->cur.f;
        p++;
        v.a = RDI(p);
        for (i = 0; i < 8; i++) {
            v.b[i] = RDI(p);
            v.c[i] = RDI(p);
        }
        c->cur.f = p;
        fn_80148464(&v);
        return 0;
    }
    return 1;
}

void fn_80211EB0(s16 mode, f32 v)
{
    lbl_8030CEA0.x828 = fn_801D6E38(lbl_8034757C) ? lbl_8034757C : -1;
    if (lbl_8030CEA0.x82c == 3 && mode == 1) {
        return;
    }
    lbl_8030CEA0.x82c = mode;
    if (mode == 1) {
        lbl_8030CEA0.pat.d = 30;
        if (v >= 7.0f) {
            lbl_8030CEA0.x830 = 7.0f;
        } else if (v >= 6.0f) {
            lbl_8030CEA0.x830 = 6.0f;
        } else if (v >= 5.0f) {
            lbl_8030CEA0.x830 = 5.0f;
        } else if (v >= 4.0f) {
            lbl_8030CEA0.x830 = 4.0f;
        } else if (v >= 3.0f) {
            lbl_8030CEA0.x830 = 3.0f;
        } else if (v >= 2.0f) {
            lbl_8030CEA0.x830 = 2.0f;
        } else if (v >= 1.0f) {
            lbl_8030CEA0.x830 = 1.0f;
        } else if (v >= 0.5f) {
            lbl_8030CEA0.x830 = v;
            lbl_8030CEA0.pat.c = 7;
            lbl_8030CEA0.pat.d = 59;
        } else {
            lbl_8030CEA0.x830 = v;
            lbl_8030CEA0.pat.c = 1;
            lbl_8030CEA0.pat.d = 59;
        }
    } else if (mode == 2) {
        lbl_8030CEA0.x834 = (s32)v;
    }
}

void fn_80211058(Scpt *s, s32 a, s32 b, s32 c, s16 d, Ev *w)
{
    s32 k;
    w->h8 = 0;
    w->x0c = 0;
    w->x10 = 0;
    k = (c << 16) | (u16)d;
    s->handle = fn_800CD0B8(a, b, k, (s32)w);
    s->a20 = a;
    s->a24 = (u16)b;
    s->a28 = k;
    s->a2c = (s32)w;
    s->ev = w;
    lbl_8030CEA0.x08++;
}

s32 fn_8021528C(u32 flags, Scpt *c) {
    float *p;
    int a;
    s32 t;
    s32 b;
    if (flags & 1) {
        p = c->cur.f;
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
        c->cur.f = p;
        fn_80148228(a, b);
        return 0;
    }
    return 1;
}

static inline u8 *find(const char *name) {
    s32 len;
    u32 i;
    if (name == 0) {
        return 0;
    }
    len = strlen(name);
    for (i = 0; i < lbl_8030CEA0.x824; i++) {
        if (fn_8025EF88(name, lbl_8030CEA0.x820[i].name) == 0) {
            s32 n = strlen(lbl_8030CEA0.x820[i].name);
            if (n == len) {
                return lbl_8030CEA0.x0 + (lbl_8030CEA0.x820[i].off & ~3);
            }
        }
    }
    return 0;
}

/* Opens the archive entry called name once (x1874 guards it): its data becomes x4. */
u8 *fn_80210450(const char *name) {
    u8 *r;
    if (lbl_8030CEA0.x1874 == 1) {
        return 0;
    }
    lbl_8030CEA0.x1874 = 1;
    r = find(name);
    if (r == 0) {
        return 0;
    }
    lbl_8030CEA0.x4 = r;
    return r;
}

void fn_80211D90(void)
{
    lbl_8030CEA0.pat.c = lbl_8030CEA0.steps[lbl_8030CEA0.x842].a;
    lbl_8030CEA0.pat.d = lbl_8030CEA0.steps[lbl_8030CEA0.x842].b;
    if (++lbl_8030CEA0.x83c % (lbl_8030CEA0.steps[lbl_8030CEA0.x842].c + 1) != 0) {
        fn_801D6CBC(lbl_8030CEA0.x828, &lbl_8030CEA0.pat);
        return;
    }
    lbl_8030CEA0.x842 = lbl_8030CEA0.x842 + 1;
    if (lbl_8030CEA0.steps[lbl_8030CEA0.x842].c == 0) {
        if (lbl_8030CEA0.steps[lbl_8030CEA0.x842].b == 0) {
            lbl_8030CEA0.x842 = 0;
            fn_801D6CBC(lbl_8030CEA0.x828, &lbl_8030CEA0.pat);
            lbl_8030CEA0.x83c = 0;
            return;
        }
        lbl_8030CEA0.x844++;
        if (lbl_8030CEA0.x844 >= lbl_8030CEA0.x838) {
            fn_801D6C3C(lbl_8030CEA0.x828);
            lbl_8030CEA0.x82c = 4;
            return;
        }
        lbl_8030CEA0.x842 = 0;
    }
    fn_801D6CBC(lbl_8030CEA0.x828, &lbl_8030CEA0.pat);
    lbl_8030CEA0.x83c = 0;
}

static inline float* find_event(const char* name)
{
    s32 len;
    u32 i;
    if (name == 0) {
        return 0;
    }
    len = strlen(name);
    for (i = 0; i < lbl_8030CEA0.x824; i++) {
        if (fn_8025EF88(name, lbl_8030CEA0.x820[i].name) == 0) {
            s32 n = strlen(lbl_8030CEA0.x820[i].name);
            if (n == len) {
                return (float*)(lbl_8030CEA0.x0 + (lbl_8030CEA0.x820[i].off & ~3));
            }
        }
    }
    return 0;
}

s32 fn_8021067C(s32 id)
{
    char buf[20];
    float* p;
    s32 ret;
    sprintf(buf, "M%05d", id);
    p = find_event(buf);
    if (p == 0) {
        return 0;
    }
    p = p + 1;
    ret = 0;
    if (fn_801F6120(&p)) {
        ret = 1;
    }
    return ret;
}

u8* fn_80210550(s32 id)
{
    char buf[24];
    u8* r;
    if (lbl_8030CEA0.x1874 == 1) return 0;
    sprintf(buf, "M%05d", id);
    lbl_8030CEA0.x1874 = 1;
    r = find(buf);
    if (r == 0) return 0;
    lbl_8030CEA0.x4 = r;
    return r;
}

static inline void ScptDestruct(u16 n)
{
    if (n < 0x100) {
        Scpt* s = &lbl_8030CEA0.x10[n];
        if (s->a20 != 0 || s->a28 != 0) {
            fn_800CCCA4(s->a20, s->a24, s->a28);
            s->a28 = 0;
            s->a20 = 0;
        }
        s->kind = 0;
        if (s->work.p != NULL) {
            fn_801E1784(s->work.p);
            s->work.p = NULL;
        }
        if (lbl_8030CEA0.x0a >= 1) {
            lbl_8030CEA0.x0a--;
        }
    } else {
        fn_801DBE1C("scptDestruct: wrong enter rable ! call programer %d", n);
    }
}

static inline void ActorReset(Actor *o)
{
    if (o != 0 && o->x1d8 != 0 && o->x1d8->x8 != 0) {
        o->x1d8->x8->x168 = 0;
    }
}

void fn_802109E8(s32 i, Actor *o)
{
    if (lbl_802F7940[lbl_8030CEA0.x10[i].owner].fn(8, &lbl_8030CEA0.x10[i]) == 1) {
        if (lbl_8030CEA0.x10[i].handle == 1) {
            ActorReset(o);
        }
        ScptDestruct(i);
    }
}

void fn_80210B44(s32 i)
{
    if (lbl_802F7940[lbl_8030CEA0.x10[i].owner].fn(8, &lbl_8030CEA0.x10[i]) == 1) {
        if (lbl_8030CEA0.x10[i].handle == 1) {
            Actor *o;
            Obj10A *t;
            u32 id = lbl_8030CEA0.x10[i].a24;
            if ((u16)id == 0xffff) {
                o = lbl_80347450;
            } else {
                t = fn_8010A164(id);
                if (t != 0) {
                    o = t->x24;
                } else {
                    fn_801DBE1C("scptTskDestruct: no Task #%d", lbl_8030CEA0.x10[i].a24);
                }
            }
            ActorReset(o);
        }
        ScptDestruct(i);
    }
}

void fn_80210D7C(s32 id)
{
    s32 i;
    if (lbl_8030CEA0.x10 != NULL && fn_8015F1A0(id) != NULL) {
        for (i = 0; i < 0x180; i++) {
            Scpt* e = &lbl_8030CEA0.x10[i];
            if ((e->a20 == 6 || e->a20 == 9) && (u16)id == (u16)e->a24) {
                ScptDestruct(i);
            }
        }
    }
}
void fn_80207738(s32 a, s32 b);

/* One node of a scripted move path (0x30 bytes). */
typedef struct MvNode {
    f32 x;       /* 0x00 */
    f32 y;       /* 0x04 */
    f32 z;       /* 0x08 */
    u8 pad0c[0xc];
    f32 x18;     /* 0x18 */
    s32 x1c;     /* 0x1c */
    s32 x20;     /* 0x20 */
    f32 x24;     /* 0x24 */
    s32 x28;     /* 0x28 */
    s32 x2c;     /* 0x2c */
} MvNode;
/* fn_8020F3D4's command work: the event message, the actor id and the path. */
typedef struct SWork {
    Ev ev;           /* 0x00 */
    s32 x14;         /* 0x14 */
    u16 id;          /* 0x18 */
    u8 pad1a[2];
    u32 count;       /* 0x1c */
    MvNode* nodes;   /* 0x20 */
    struct Spline* result; /* 0x24 */
} SWork;
void fn_8016058C(u32 n, MvNode* nodes, Actor* o);
struct Spline* fn_80165EE4(u32 n, MvNode* nodes, NJS_POINT3* pos);
static inline s32 IsSelf(u16 id)
{
    return id == 0xffff;
}

/* Moves actor `id` along the `count` path nodes passed after it (a spline through them). */
s32 fn_8020F3D4(s32 id, s32 count, MvNode* first, ...)
{
    va_list ap;
    Scpt s2;
    Scpt s1;
    Actor* o;
    Obj10A* tk;
    SWork* w;
    MvNode* nodes;
    s32 i;
    if (count == 0) return 0;
    do {
        if (IsSelf(id)) {
            o = lbl_80347450;
        } else {
            tk = fn_8010A164(id);
            if (tk == NULL) break;
            o = tk->x24;
        }
        if (o != NULL && o->x1d8->x8 == NULL) {
            if (fn_80210860(&s1, id) != 0) {
                s1.owner = 0x1a;
                s1.kind = 1;
                s1.cur.i = NULL;
                s1.cnt = 0;
                fn_80210F74(&s1);
            }
        }
    } while (0);
    w = fn_801E1A2C(1, 0x44);
    if (w == NULL) return 0;
    s2.work.p = w;
    w->id = id;
    w->ev.hd.kind = 0;
    w->count = count;
    nodes = fn_801E1A2C(1, count * 0x30);
    if (nodes == NULL) {
        if (w != NULL) fn_801E1784(w);
        return 0;
    }
    w->nodes = nodes;
    w->nodes[0] = *first;
    va_start(ap, first);
    for (i = 1; i < count; i++) {
        w->nodes[i] = *va_arg(ap, MvNode*);
    }
    if (w->id == 0xffff) {
        o = lbl_80347450;
    } else {
        tk = fn_8010A164(w->id);
        if (tk == NULL) return 0;
        o = tk->x24;
    }
    if (o == NULL) return 0;
    if (o->x1d8 != NULL) {
        f32 px, py, pz;
        Actor* t;
        f32* save;
        struct Spline* r;
        s32 j;
        t = o->x1d8->x8;
        if (t == NULL) t = o;
        px = t->pos.x;
        py = t->pos.y;
        pz = t->pos.z;
        save = fn_801E1A2C(1, w->count * 4);
        for (j = 0; j < w->count; j++) save[j] = w->nodes[j].y;
        fn_8016058C(w->count, w->nodes, t);
        r = fn_80165EE4(w->count, w->nodes, &t->pos);
        w->result = r;
        if (r == NULL) return 0;
        for (i = 0; i < w->count; i++) w->nodes[i].y = save[i];
        if (save != NULL) fn_801E1784(save);
        t->pos.x = px;
        t->pos.y = py;
        t->pos.z = pz;
    }
    w->x14 = 1;
    fn_80211058(&s2, 6, w->id, 6, lbl_8030CEA0.x08, &w->ev);
    s2.owner = 0x23;
    s2.kind = 1;
    s2.cur.i = NULL;
    s2.cnt = 0;
    fn_80210F74(&s2);
    return 1;
}

s32 fn_8020F7F8(s32 id, s32 arg) {
    Scpt m2;
    Scpt m;
    Actor* o;
    Obj10A* t;
    Work801F8* w;
    if (id == 0x10000) {
        fn_80207738(0x2a, arg);
        return 1;
    }
    do {
        if ((u16)id == 0xffff) {
            o = lbl_80347450;
        } else {
            t = fn_8010A164(id);
            if (t == 0) {
                break;
            }
            o = t->x24;
        }
        if (o != 0 && o->x1d8->x8 == 0 && fn_80210860(&m, id) != 0) {
            m.owner = 0x1a;
            m.kind = 1;
            m.cur.i = 0;
            m.cnt = 0;
            fn_80210F74(&m);
        }
    } while (0);
    w = fn_801E1A2C(1, 0x44);
    if (w == 0) return 0;
    m2.work.work801F8 = w;
    w->n = id;
    w->x1c = arg;
    w->ev.hd.kind = 0;
    fn_80211058(&m2, 6, w->n, 0xf, lbl_8030CEA0.x08, &w->ev);
    m2.owner = 0x2a;
    m2.kind = 1;
    m2.cur.i = 0;
    m2.cnt = 0;
    fn_80210F74(&m2);
    return 1;
}

s32 fn_8021116C(u32 id)
{
    s32 i;
    for (i = 0; i < 0x180; i++) {
        if (lbl_8030CEA0.x10[i].kind != 0 && id == lbl_8030CEA0.x10[i].owner) return 1;
    }
    return 0;
}
void fn_80212084(void);

/* The work of a type-5 message with a value: the head, the value and the text. */
typedef struct Work_8020A584 {
    EvHead hd;
    s32 x08;
    char* x0c;
} Work_8020A584;

/* The work of a type-8 message: the head, an id and a value. */
typedef struct Work_8020D2A8 {
    EvHead hd;
    u8 pad08[0x10];
    u16 n;
    u8 pad1a[2];
    s32 x1c;
    u8 pad20[0x24];
} Work_8020D2A8;

/* The 0x88-byte block fn_8020DBC4 hands over: two tables of lbl_8034A034 entries. */
typedef struct EvBufs {
    u8 pad00[0x1c];
    void* x1c;
    void* x20;
    u8 pad24[0x64];
} EvBufs;
typedef struct Work_8020DBC4 {
    Ev ev;
    u8 pad14[8];
    EvBufs* x1c;
    u8 pad20[0x24];
} Work_8020DBC4;

extern char lbl_80314738[];
s32 fn_8021026C(const char *name)
{
    Scpt s;
    Work_8020A938 *w;

    if (name == NULL) {
        return 0;
    }
    strcpy(lbl_80314738, name);
    w = fn_801E1A2C(1, 12);
    if (w == NULL) {
        return 0;
    }
    s.work.work_8020A938 = w;
    w->hd.kind = 0;
    w->x08 = lbl_80314738;
    fn_802110E8(&s, 5, 0, 0, lbl_8030CEA0.x08, &w->hd);
    s.owner = 0x18;
    s.kind = 1;
    s.cur.i = 0;
    s.cnt = 0;
    fn_80210F74(&s);
    lbl_8030CEA0.x15c8 = 1;
    return 1;
}

extern void fn_80148790(s32 a, s32 b, s32 c, s32 d, s32 e);
s32 fn_802150FC(u32 flags, Scpt *c) {
    float *p;
    s32 a, b, d, e, f;
    if (flags & 1) {
        p = c->cur.f;
        p++;
        a = RDI(p);
        b = RDI(p);
        d = RDI(p);
        e = RDI(p);
        f = RDI(p);
        c->cur.f = p;
        fn_80148790(a, b, d, e, f);
        return 0;
    }
    return 1;
}

void fn_80213178(f32 t, f32 dur, f32 *p0, f32 *p1, f32 *p2, f32 *p3, f32 *out)
{
    f32 d = dur - t;
    f32 d2 = d * d;
    f32 td = t * d;
    f32 d3 = d * d2;
    f32 a, b, c;
    f32 x, y, z;

    if (t <= 0.0f) {
        out[0] = p0[0];
        out[1] = p0[1];
        out[2] = p0[2];
        return;
    }
    if (t >= dur) {
        out[0] = p3[0];
        out[1] = p3[1];
        out[2] = p3[2];
        return;
    }
    x = p0[0] * d3;
    y = p0[1] * d3;
    z = p0[2] * d3;
    a = 3.0f * (d * td);
    x += p1[0] * a;
    y += p1[1] * a;
    z += p1[2] * a;
    b = 3.0f * (td * t);
    x += p2[0] * b;
    y += p2[1] * b;
    z += p2[2] * b;
    c = t * (t * t);
    x += p3[0] * c;
    y += p3[1] * c;
    z += p3[2] * c;
    if (dur == 0.0f) {
        out[0] = x;
        out[1] = y;
        out[2] = z;
        return;
    }
    out[0] = ((x < 0.0f ? -x : x) > 0.01f) ? x / dur / dur / dur : p3[0];
    out[1] = ((y < 0.0f ? -y : y) > 0.01f) ? y / dur / dur / dur : p3[1];
    out[2] = ((z < 0.0f ? -z : z) > 0.01f) ? z / dur / dur / dur : p3[2];
}

void fn_80213478(f32 *a, f32 *b, s32 *out)
{
    f32 dx, dy, dz, xx, zz, xz;

    if (a != NULL && b != NULL && out != NULL) {
        dx = b[0] - a[0];
        dz = b[2] - a[2];
        dy = b[1] - a[1];
        xx = dx * dx;
        zz = dz * dz;
        xz = xx + zz;
        if (0.0f == xz + dy * dy) {
            out[1] = 0;
            out[0] = 0;
        } else {
            out[0] = (s32)(10430.381f * (f32)atan2(-dy, fn_80291A5C(xz)));
            if (0.0f == dx && 0.0f == dz) {
                out[1] = 0;
            } else {
                out[1] = (s32)(10430.381f * (f32)atan2(dx, dz));
            }
        }
        out[2] = 0;
    }
}

s32 fn_80211298(u32 **pc, s32 flag)
{
    Scpt e;
    u32 *w;
    s16 ok;
    if (lbl_8030CEA0.x0a > 0x180) {
        return 1;
    }
    e.cur.u = *pc;
    e.work.n = 0;
    e.flags = 0;
    e.handle = 0;
    e.ev = 0;
    e.a28 = 0;
    e.a20 = 0;
    if (*e.cur.u == 0xd) {
        *pc = e.cur.u + 1;
        e.cur.u = *pc;
        e.flags = 1;
    }
    w = *pc;
    if (*w > 0x10000) {
        __stwbrx(*w, w, 0);
    }
    e.owner = **pc;
    e.flags |= lbl_802F7940[e.owner].flags;
    e.x12 = lbl_802F7940[e.owner].v;
    ok = lbl_802F7940[e.owner].fn(1, &e);
    *pc = e.cur.u;
    if (ok == 1) {
        e.kind = 1;
        e.cnt = 0;
        ScptAdd(&e);
    }
    if (flag == 0 && e.flags != 0) {
        fn_80211298(pc, flag);
    }
    return 1;
}

s32 fn_802139F8(u32 flags, Scpt_802139F8* c) {
    float* p;
    Args14 b;
    if (flags & 1) {
        p = c->cur;
        p++;
        b.i[0] = RDI(p);
        b.i[1] = RDI(p);
        b.i[2] = RDI(p);
        b.i[3] = RDI(p);
        b.i[4] = RDI(p);
        b.i[5] = RDI(p);
        b.i[6] = RDI(p);
        b.i[7] = RDI(p);
        b.i[8] = RDI(p);
        b.i[9] = RDI(p);
        b.i[10] = RDI(p);
        b.i[11] = RDI(p);
        b.i[12] = RDI(p);
        b.i[13] = RDI(p);
        c->cur = p;
        fn_8015596C(&b);
        return 0;
    }
    return 1;
}

s32 fn_80214270(u32 flags, Scpt *c)
{
    float *p;
    s32 a[25];
    if (flags & 1) {
        p = c->cur.f;
        p++;
        a[0] = RDI(p);
        a[1] = RDI(p);
        a[2] = RDI(p);
        a[3] = RDI(p);
        a[4] = RDI(p);
        a[5] = RDI(p);
        a[6] = RDI(p);
        a[7] = RDI(p);
        a[8] = RDI(p);
        a[9] = RDI(p);
        a[10] = RDI(p);
        a[11] = RDI(p);
        a[12] = RDI(p);
        a[13] = RDI(p);
        a[14] = RDI(p);
        a[15] = RDI(p);
        a[16] = RDI(p);
        a[17] = RDI(p);
        a[18] = RDI(p);
        a[19] = RDI(p);
        a[20] = RDI(p);
        a[21] = RDI(p);
        a[22] = RDI(p);
        a[23] = RDI(p);
        a[24] = RDI(p);
        c->cur.f = p;
        fn_80155944(a);
        return 0;
    }
    return 1;
}

/* Rooms where opening a chest skips the item jingle. */
#define QUIET_ROOM()                                                  \
    ((lbl_80311AC0.area == 0x1c && lbl_80311AC0.room == 'b') ||      \
     (lbl_80311AC0.area == 0x7a && lbl_80311AC0.room == 'a') ||      \
     (lbl_80311AC0.area == 0x7d && lbl_80311AC0.room == 'a') ||      \
     (lbl_80311AC0.area == 0x7d && lbl_80311AC0.room == 'b') ||      \
     (lbl_80311AC0.area == 0x7d && lbl_80311AC0.room == 'd'))

