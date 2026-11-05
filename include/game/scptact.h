#ifndef GAME_SCPTACT_H
#define GAME_SCPTACT_H

#include "types.h"
#include "game/work_8030CEA0.h"
#include "ninja.h"
#include "game/task.h"
#include "game/util.h"
#include "game/gamedata.h"
#include <math.h>
#include <stdarg.h>
#include "game/save_8030B7F4.h"
#include "game/unit_801F5334.h"

/* A script command's argument stream: words that are floats, ints or bytes depending on the command. */
typedef union ScptCur {
    f32 *f;
    u8 *b;
    char *s;
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
        char *s;
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
        struct Work_8020527C *work_8020527C;
        struct Rec *rec;
        struct Rec_80208424 *rec_80208424;
        struct Rec_80208A20 *rec_80208A20;
        struct Rec_80209974 *rec_80209974;
        struct Work_8020A938 *work_8020A938;
        struct MesWin *mes;
        struct Work_8020A584 *work_8020A584;
        struct Work_8020D2A8 *work_8020D2A8;
        struct Work_8020DBC4 *work_8020DBC4;
    } work;
} Scpt;
s32 fn_800CD0B8(s32 a, s32 b, s32 c, s32 d);
void fn_80211058(Scpt *s, s32 a, s32 b, s32 c, s16 d, Ev *w);
void fn_802110E8(Scpt *s, s32 a, s32 b, s32 c, s16 d, EvHead *w);
void fn_801EFC88(s16 v);
void fn_801F7500(void);
s8 fn_801F452C(s16 id);
float fn_801F6120(float **p);
extern void fn_801DBE1C(const char *fmt, ...);
extern void* fn_801E1A2C(s32 a, s32 b);
void fn_801EFF0C(s16 v);
extern void* fn_801E1A2C(s32 a, s32 b);
extern void fn_801DBE1C(const char* fmt, ...);
extern void fn_801E1784(void* p);
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
    u8 pad104[0x1c8 - 0x104];
    struct Info *x1c8;
    u8 pad1cc[0x1d8 - 0x1cc];
    Sub *x1d8;
    u8 pad1dc[0x26c - 0x1dc];
    u8 b26c;
} Actor;
extern Cam8020C lbl_80311970;
extern u32 lbl_80310B3C[];
extern Actor* fn_8015F1A0(u16 id);
void *fn_8015F180(void *o);
extern u8 lbl_80310A1C[];
void fn_801F7B04(s32 v);
extern s32 lbl_80347474;
typedef struct Obj10A { void (*fn)(struct Obj10A *); u8 pad4[0x15]; u8 x19; u8 pad1a[0xa]; Actor *x24; } Obj10A;
extern Obj10A *fn_8010A164(u32 id);
extern const s32 lbl_8034A034;
s32 fn_8020E984(void);
void fn_80213478(f32 *a, f32 *b, s32 *out);
void* memcpy(void* d, const void* s, u32 n);
/* A camera spline script (lbl_8030CEA0.x1914): n nodes with their eye and look-at points and the
 * two control points per segment that fn_8021331C computes for each curve. */
typedef struct Script_801F773C {
    u32 n;                  /* 0x00 */
    u32 idx;                /* 0x04 */
    s32* times;             /* 0x08 */
    f32** xc;               /* 0x0c: eye points */
    f32** x10;              /* 0x10: 2 control points per segment of the eye curve */
    f32** x14;              /* 0x14: look-at points */
    f32** x18;              /* 0x18: 2 control points per segment of the look-at curve */
    f32* angles;            /* 0x1c */
    u8* x20;                /* 0x20: ease kind per node (fn_802023BC) */
} Script_801F773C;
void fn_80213178(f32 t, f32 dur, f32 *p0, f32 *p1, f32 *p2, f32 *p3, f32 *out);
extern SaveData lbl_8030B7F4;
/* void fn_801F452C(s32) in the unit */
extern void fn_801DBE1C(const char* fmt, ...);
s32 fn_8020F934(s32 id);
extern void fn_801DBE1C(const char *fmt, ...);
float fn_801F6120(float **p);
float fn_801F6120(float **p);
float fn_801F6120(float **p);
float fn_801F6120(float **p);
extern s32 fn_80210F74(Scpt *s);
float fn_801F6120(float **p);
float fn_801F6120(float **p);
extern s16 fn_801F6EC8(s32 v);
extern const s32 lbl_8034A034;
/* An int argument of the script stream; FLT_MAX stands for 'unset' (0x7FFFFFFF). */
static inline s32 ReadInt(f32** p)
{
    if (3.4028235e38f == **p) {
        (*p)++;
        return 0x7FFFFFFF;
    }
    return (s32)fn_801F6120(p);
}
#define RDI(p) (*(p) == 3.4028235e38f ? ((p)++, 0x7FFFFFFF) : (s32)fn_801F6120(&(p)))
inline s32 FlagTest(u32 b) {
    return (lbl_80310B3C[b >> 5] & (1 << (b & 31))) != 0;
}

#endif
