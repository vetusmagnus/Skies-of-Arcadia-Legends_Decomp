#include "types.h"
#include "game/work_8030CEA0.h"
#include "ninja.h"
#include "game/task.h"
#include "game/util.h"
#include <math.h>

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

void fn_80217B98();
void fn_801EFC88(s16 v);
void fn_800B0900(void *p);
void fn_800FF9FC(void *p);
extern u8 lbl_8030B4D4[];
#include "game/save_8030B7F4.h"
void fn_801003F4(void *p);
void fn_800D2CA8(s32 a);
void fn_80210CE4(void);
void fn_801F7500(void);
void fn_800976EC(u32 a);
void fn_80142C78(void *p);
void fn_80147DCC(void *p);
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
    u8 key[2];
    u8 pad0a[0x1e];
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
void fn_801F452C(s32 arg);
extern s32 lbl_8034757C;
s32 fn_801D6E38(s32 arg);
s32 SePlay(s32 bank, s8 arg1, s8 id);
void fn_8020EEE8(s32 bank, s8 arg1, s8 id, s32 unused);
extern s32 lbl_803477DC;
void fn_80217830(s32 arg);
extern u32 lbl_803477E0;
float fn_801F6120(float **p);
void fn_801EFF0C(s16 v);
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
extern u32 fn_800CCC48(s32 a, s32 b);
extern void fn_80097294(u8 a);
extern void fn_80097270(f32 a, f32 b, f32 c);
extern void fn_8009724C(f32 a, f32 b, f32 c);
extern void fn_800971C4(f32 a);
extern void fn_800971E0(s32 a, s32 b, s32 c);
extern void fn_80097150(s32 a);
extern void fn_80097118(f32 a);
extern void fn_800970FC(f32 a);
extern void fn_80097318(s8 x);
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
typedef struct Part { u8 pad00[0x2c]; s32 x2c; u8 pad30[0x138]; s16 x168; } Part;
typedef struct Sub { u8 pad00[8]; Part *x8; u8 pad0c[0x1a0 - 0xc]; s32 x1a0; } Sub;
/* An actor: fn_8015F1A0's result, lbl_80347450, and the work of a task from fn_8010A164. */
typedef struct Actor {
    u8 pad00[0x2c];
    s32 x2c;
    u8 pad30[0x14];
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
typedef struct {
    u8 pad00[0x10];
    f32 f[3];
    s32 w[3];
} Cam8020C;
typedef struct {
    u8 pad00[0x7c];
    u32 x7c;
    u8 pad80[8];
    u32 x88;
    u8 pad8c[8];
    u32 x94;
} Sub8020C;
extern Cam8020C lbl_80311970;
extern Sub8020C lbl_802F7848;
extern u32 lbl_80310B3C[];
extern char lbl_803146A8[];
extern s32 fn_80210064(s32 a);
extern s32 fn_8020F998(s32 a, f32* v, s32 c, s32 d, s32 e, s32 n);
extern s32 fn_8020FF44(s32 id, s32 b);
extern s32 fn_8020FDE0(s32 id, s32 b, s32 c, s32 d);
extern Actor* fn_8015F1A0(u16 id);
extern void* fn_801F4AE4(s16 id);
extern int sprintf(char* buf, const char* fmt, ...);
extern s32 fn_8021026C(const char* name);
typedef struct Vec3i { s32 x, y, z; } Vec3i;
typedef struct Vec3f { f32 x, y, z; } Vec3f;
typedef struct Link { u8 pad_00[0x18]; Vec3f *pos; u8 pad_1c[4]; Vec3i *col; } Link;
typedef struct Info { u8 pad_00[0x10]; s32 *x10; u8 pad_14[0x30]; f32 x44, x48, x4c, x50, x54, x58; } Info;
typedef struct Obj {
    u8 pad_00[0x38];
    f32 x38, x3c, x40;
    s32 x44, x48, x4c;
    u8 pad_50[0xb4];
    f32 x104, x108, x10c;
    u8 pad_110[0xac];
    Link *x1bc;
    u8 pad_1c0[8];
    Info *x1c8;
} Obj;
void *fn_8015F180(void *o);
void fn_80222838(Link *l);
typedef struct Args { s32 i[5]; f32 f[20]; } Args;
void fn_80155994(Args *a);
#define RDI(p) (*(p) == 3.4028235e38f ? ((p)++, 0x7FFFFFFF) : (s32)fn_801F6120(&(p)))
void fn_80216E38(s32 n, u8 *p);
extern u8 lbl_80310A1C[];
void fn_8016D904(s32 n);
void fn_801E749C(float *v);
void fn_800FF780(u8 *p);
extern s32 lbl_803473B4;
void fn_800D2C44(u16 v);
void fn_8022D34C(s32 a, f32 b);
void fn_801002D0(void *p);
void fn_801F7B04(s32 v);
extern s32 lbl_80347474;
extern void ScreenFadeDraw(void *p, f32 a, f32 b, f32 c, f32 d, f32 e);
extern void njUnitMatrix(f32 *m);
extern void njRotateXYZ(f32 *m, s32 x, s32 y, s32 z);
extern void fn_80148188(s32 v);
extern void *fn_802159E0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i);
s32 fn_8011768C(u32 flags);
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
extern void *lbl_8034759C;
extern s32 lbl_803473C0;
extern u8 fn_8020E984(void);
void fn_801BEA70(void *a, u32 idx, s32 mode);
void fn_80147DA8(s32 a, s32 b);
void fn_80147DC8(s32 a, s32 b);
extern s32 lbl_803477A8;
extern s32 lbl_803477AC;
typedef struct { u8 pad[0xc]; u32 len; } StrmSrc;
typedef struct Strm {
    u8 state;
    u8 pad01[0xf];
    StrmSrc* src;
    u8 a;
    u8 b;
    u8 pad16[0x3e];
    u32 handle;
    u32 half;
    u32 len;
    u8* buf;
    u32 size;
    u32 w68;
    u8 b6c;
    u8 pad6d[3];
    s32 w70;
    s32 w74;
    s32 w78;
    s32 w7c;
} Strm;
extern void* memset(void* dst, int c, u32 n);
extern void sndStreamMixParameterEx(u32 h, u32 a, u32 b, u32 c, u32 d, u32 e);
void fn_800EB58C(s32 n);
extern f32 fn_80291A5C(f32 v);
double atan2(double y, double x);
typedef struct { s32 flag; f32 f4; s32 i8; } Fx_8030CE94;
extern Fx_8030CE94 lbl_8030CE94;
void fn_800D23F8(s32 n, f32 a, f32 b, s32 m);
void fn_800D244C(s32 n, f32 a, f32 b, s32 m);
void fn_80211EB0(s16 mode, f32 v);
extern s32 lbl_803475B4;
double fn_8026216C(double x);
void fn_8021730C(u32 mode, s32 x);
typedef struct { u8 pad0[0x190]; f32 f190; } Obj_80207630;
s32 fn_8015F1F0(void *o);
extern void fn_8009701C(s8 a);
typedef struct Slot_80216B88 {
    u8 used;
    u8 pad1[3];
    u32 id;
    s32 f8;
    s32 fc;
    u8 pad10[0x80 - 0x10];
} Slot_80216B88;
typedef struct Tbl_80216B88 {
    Slot_80216B88 s[4];
    u32 counter;
} Tbl_80216B88;
extern Tbl_80216B88 lbl_80314B80;
extern s32 fn_80218570(s32 a, s32 b, s32 c);
void fn_80097204(f32 a, f32 b, f32 c);
void fn_800972E0(s32 a);
void fn_80225CAC(s32 a, u16 b, s16 c);
void fn_80213478(f32 *a, f32 *b, s32 *out);
void fn_801000F0(s32 a, s32 b);
void fn_80118578(s32 a, f32 f1, f32 f2, f32 f3, f32 f4);
extern void fn_801CBBBC(void);
extern s32 lbl_80347508;
extern f32 lbl_80347510;
extern f32 lbl_80347514;
extern u32 lbl_80347518;
extern void fn_8015F654(void* p);
extern char lbl_802D4D7C[];
extern s32 rand(void);
extern void fn_801D995C(s32 n, f32 a, f32 b, f32 c);
extern void fn_800D2554(f32 x, f32 y);
extern void fn_800D25C4(u32 rgb, s32 n);
extern void fn_800D258C(s32 n, f32 a, f32 b);
typedef struct Work_80202004 {
    EvHead hd;
    u8 pad08[0x10];
    s32 x18;
    s32 x1c;
    s32 x20;
} Work_80202004;
extern void fn_80097094(u16 a, f32 b);
extern void fn_80097228(f32 a, f32 b, f32 c);
typedef struct Lerp {
    s32 total;      /* 0x00 */
    s32 step[3];    /* 0x04 */
    s32 dest[3];    /* 0x10 */
} Lerp;
extern void fn_800971A8(f32 a);
extern void fn_80097134(s32 a);
extern void fn_800970D8(u16 a, f32 b, s32 c);
extern void fn_800970B4(u16 a, f32 b, s32 c);
extern void fn_80097188(f32 a, f32 b);
extern void fn_8009716C(s16 a);
typedef struct Eff {
    f32 f[8];       /* 0x00 */
    s32 x20;
} Eff;
extern void fn_801185A8(s32 a, f32 b, f32 c, f32 d, f32 e, f32 f, f32 g);
extern void fn_800E28D4(f32* pos, u32* ids);
extern double sin(double);
extern double cos(double);
extern void fn_80212C04(f32 *a, f32 *b, f32 *c);
void fn_801558B0(s32 *v);
typedef struct Pair8 { s32 a; u8 b[8]; u8 c[8]; } Pair8;
void fn_80148464(Pair8 *v);
typedef struct { u8 pad[8]; u32 off; u32 len; } StrmSrc_80216744;
typedef struct Strm_80216744 {
    u8 state;
    u8 pad01[0xf];
    StrmSrc_80216744* src;
    u8 a;
    u8 b;
    u8 pad16[2];
    u8 info[0x3c];
    u32 handle;
    u32 pos;
    u32 len;
    u8* buf;
    u32 size;
    u32 w68;
    u8 b6c;
    u8 pad6d[3];
    s32 w70;
    s32 w74;
    s32 w78;
    s32 w7c;
} Strm_80216744;
extern void sndStreamARAMUpdate(u32 h, u32 a, u32 b, u32 c, u32 d);
extern void sndStreamDeactivate(u32 h);
extern s32 fn_8023CD10(void *info);
extern s32 fn_8023AB88(void *info, void *addr, s32 len, s32 offset, void (*cb)(void), s32 prio);
extern void fn_8023A8E0(void *info);
extern void fn_80216030(void);
extern char lbl_802D478C[];
extern char lbl_802D47A4[];
typedef struct { u8 pad[0x54]; u32 size; } Res;
void fn_80218DDC(void);
Res* fn_801CC69C(s32 name);
void fn_801CC608(Res* h, void* buf, u32 size);
void fn_801CC65C(Res* h);
void* memcpy(void* d, const void* s, u32 n);
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
typedef struct { void* a; void* b; } Pair;
typedef struct {
    u32 n;                  /* 0x00 */
    u32 idx;                /* 0x04 */
    s32* times;             /* 0x08 */
    void** xc;              /* 0x0c */
    Pair* x10;              /* 0x10 */
    void** x14;             /* 0x14 */
    Pair* x18;              /* 0x18 */
    f32* angles;            /* 0x1c */
} Script_801F773C;
void fn_80213178(f32 t, f32 dur, f32 *p0, f32 *p1, f32 *p2, f32 *p3, f32 *out);
void fn_800B09C0(s8 id, s8 a, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5);
void fn_800AFCC0(s8 id, s8 a, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5);
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
extern char lbl_802D491C[];
extern char lbl_802D4938[];
typedef struct Fx_801F8F7C {
    Ev ev;
    u8 pad14[0x4];
    u16 x18;
    u16 x1a;
    u8 pad1c[0x28];
} Fx_801F8F7C;
extern char lbl_802D4958[];
extern char lbl_802D4978[];
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
extern char lbl_802D49A0[];
extern char lbl_802D49BC[];
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
extern char lbl_802D4B54[];
extern char lbl_802D4B70[];
typedef struct ScrState {
    u8 pad0[0x1c];
    s32 mode;
    s32 count;
    u8 pad24[0x20];
} ScrState;
typedef struct Pad {
    u8 pad0[8];
    u32 flags;
} Pad;
extern char lbl_802D4DC0[];
typedef struct PadInfo {
    Pad* pad;
    u8 pad4[0x14];
} PadInfo;
extern PadInfo lbl_80311A60;
extern void fn_801D9864(s32 n, f32 a, f32 b, f32 c, f32 d, f32 e, f32 g);
extern void fn_801D9A0C(s32 n, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f, f32 g, f32 h);
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
extern char lbl_802D5158[], lbl_802D5170[];
extern char lbl_802D5190[], lbl_802D51A8[];
extern char lbl_802D51C8[], lbl_802D51E0[];
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
extern char lbl_802D5200[], lbl_802D5220[];
extern char lbl_802D5248[], lbl_802D5260[];
extern char lbl_802D5280[], lbl_802D52A0[];
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
extern char lbl_802D52E8[], lbl_802D5308[];
extern char lbl_802D532C[], lbl_802D5348[];
extern char lbl_802D536C[], lbl_802D5384[];
extern char lbl_802D544C[], lbl_802D5468[];
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
extern char lbl_802D548C[], lbl_802D54A8[];
extern char lbl_802D5504[], lbl_802D5520[];
extern char lbl_802D54CC[], lbl_802D5544[];
typedef struct Work_8020A938 {
    EvHead hd;
    void *x08;
} Work_8020A938;
extern void* fn_8020AF8C(s32 id);
s32 fn_8009763C(void);
void fn_800972AC(void);
extern char lbl_802D4740[];
s32 fn_8010038C(void *p);
void fn_80148228(s32 a, s32 b);
extern s32 strlen(const char *s);
extern s32 fn_8025EF88(const char *a, const char *b);

extern void fn_801D6CBC(s32 chan, Pat *p);
extern void fn_801D6C3C(s32 chan);

extern int sprintf(char* buf, const char* fmt, ...);

extern s32 fn_800CCCA4(u32 a, u32 b, u32 c);
extern char *lbl_80346848;
extern char lbl_8034C198;
extern char *strcpy(void *dst, const char *src);
extern char *strcat(void *dst, const char *src);
extern void fn_80219378(void *p);
void fn_801EF300(void);
extern void fn_800C1A34(s32 a, s32 b, s32 c, s32 d);
extern void fn_801D9728(s32 n, s32 mode, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f, f32 g, f32 h);
typedef struct {
    f32 x;
    s16 u;
    s16 v;
    f32 a;
    f32 b;
} Pos;
typedef struct {
    u8 r, g, b, a;
    f32 x, y, z;
} TextHead;
typedef struct {
    char* name;
    u8 pad04[0x24];
} Name;
typedef struct {
    s32 x0, x4;
    char* desc;
} Desc;
extern Pos lbl_80314698;
extern Name lbl_802ED258[];
extern Desc lbl_802EE040[];
extern f32 fn_800C2D18(Pos* p);
extern TextHead* TextPrint(s32 x, s32 y, const char* str);
extern void fn_800DDE98(s32 a, s32 b, s32 c, s32 d, s32 e, f32 f1, f32 f2, s32 g);
void fn_801694FC(s32 a, s8 b, s8 c, s32 d, f32 x, f32 y, f32 z);
extern s32 fn_801F3F88(void* p, s8 i);
typedef struct Info_801FE06C {
    u8 pad0[0x38];
    f32 x38;
    f32 x3c;
    f32 x40;
    s32 x44;
    s32 x48;
    s32 x4c;
    f32 x50;
    f32 x54;
    f32 x58;
} Info_801FE06C;

void fn_801F5334(s8 n) {
    s32 i;
    for (i = 0; i < n; i++) {
        fn_801EFC88(0x102);
    }
}

s32 fn_801F58B0(void) {
    return 1;
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

extern void fn_801DBE1C(const char *fmt, ...);
int fn_801F60F0(void) {
    fn_801DBE1C("scptSTUB: code error!");
    return 0;
}

s32 fn_801F7CD8(u32 a, Scpt *st) {
    u16 f = a;
    if (a & 1) {
        u8 *c = st->cur.b;
        st->cur.b = c + 4;
        fn_800B0900(c);
    }
    if (f & 8) return 1;
    return 0;
}

s32 fn_801F95C0(u32 a, Scpt *st) {
    u16 f = a;
    if (a & 1) {
        u8 *c = st->cur.b;
        st->cur.b = c + 4;
        fn_80217CB0(c);
    }
    if (f & 8) return 1;
    return 0;
}

s32 fn_801F9614(u32 a, Scpt *st) {
    u16 f = a;
    if (a & 1) {
        u8 *c = st->cur.b;
        st->cur.b = c + 4;
        fn_80217B98(c);
    }
    if (f & 8) return 1;
    return 0;
}

s32 fn_801FD54C(u32 a, Scpt *st) {
    if (a & 1) {
        u8 *c = st->cur.b;
        st->cur.b = c + 4;
        fn_800FF9FC(c);
    }
    return 0;
}

s32 fn_801FDA70(u32 a, Scpt *st) {
    u16 f = a;
    if (a & 1) {
        st->cur.b += 4;
        *(u32 *)&lbl_8030B7F4.x157c = *(u32 *)(lbl_8030B4D4 + 0x2dc);
    }
    if (f & 8) return 1;
    return 0;
}

s32 fn_801FEB08(u32 a, Scpt *st) {
    if (a & 1) {
        u8 *c = st->cur.b;
        st->cur.b = c + 4;
        fn_801F3148(c);
    }
    return 0;
}

s32 fn_801FEB40(u32 a, Scpt *st) {
    if (a & 1) {
        u8 *c = st->cur.b;
        st->cur.b = c + 4;
        fn_801F35A0(c);
    }
    return 0;
}

s32 fn_801FED04(u32 a, Scpt *st) {
    if (a & 1) {
        u8 *c = st->cur.b;
        st->cur.b = c + 4;
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

s32 fn_801FEF48(u32 a, Scpt *st) {
    if (a & 1) {
        u8 *c = st->cur.b;
        st->cur.b = c + 4;
        fn_800FFA18(c);
    }
    return 0;
}

s32 fn_801FF0F8(u32 a, Scpt *st) {
    if (a & 1) {
        u8 *c = st->cur.b;
        u8 *q = c + 4;
        u32 off = *(u32 *)(c + 4);
        st->cur.b = q + 4;
        fn_801003F4(q + off);
    }
    return 0;
}

int fn_801FF1E0(void) {
    fn_801DBE1C("scptKill: SYNTAX ERROR!!!");
    return 0;
}

s32 fn_80200F88(u32 a, Scpt *st) {
    if (a & 1) {
        u8 *c = st->cur.b;
        st->cur.b = c + 4;
        fn_800D2CA8(0);
    }
    return 0;
}

s32 fn_80201458(u32 flags, Scpt *st) {
    if (flags & 1) {
        float *p = st->cur.f;
        s32 v, n, i;
        Actor *a;
        p++;
        v = RDI(p);
        n = *(s32 *)p++;
        for (i = 0; i < n; i++) {
            a = fn_8015F1A0(RDI(p));
            if (a == 0) {
                st->cur.f = p;
                return 0;
            }
            a->x2c = v;
            if (a->x1d8 != 0 && a->x1d8->x8 != 0) {
                a->x1d8->x8->x2c = v;
            }
        }
        st->cur.f = p;
        return 0;
    }
    return 1;
}

s32 fn_8020731C(u32 a, Scpt *st) {
    if (a & 1) {
        u8 *c = st->cur.b;
        st->cur.b = c + 4;
        fn_80210CE4();
        fn_801F7500();
        lbl_8030CEA0.x15cc = 0;
    }
    return 0;
}

s32 fn_80207368(u32 a, Scpt *st) {
    if (a & 1) {
        u8 *c = st->cur.b;
        fn_800976EC(a);
        st->cur.b = c + 4;
    }
    return 0;
}

extern s16 fn_80207830(s32, Scpt *);
extern s32 fn_80210F74(Scpt *s);
extern u32 fn_802107A4(Scpt *s, s32 id);
extern u32 fn_80210860(Scpt *s, u16 id);
void fn_80207738(s32 a, s32 b)
{
    Scpt s;
    s32 i;

    for (i = 0; i < 256; i++) {
        if (lbl_8030CEA0.ent[i][0] != 0) {
            s32 args[5] = { 0, 0, 0x1D, 0, 0x1D };
            s.cur.i = args;
            args[0] = a;
            args[1] = b + 0x8000000;
            args[3] = i + 0x8000000;
            s.work.n = 0;
            s.owner = a;
            if (fn_80207830(1, &s) == 1) {
                s.kind = 1;
                s.cnt = 0;
                s.handle = 0;
                fn_80210F74(&s);
            }
        }
    }
}

extern s16 fn_80209028(s32, Scpt *);
void fn_80208F30(s32 a, s32 b)
{
    Scpt s;
    s32 i;

    for (i = 0; i < 256; i++) {
        if (lbl_8030CEA0.ent[i][0] != 0) {
            s32 args[5] = { 0, 0, 0x1D, 0, 0x1D };
            s.cur.i = args;
            args[0] = a;
            args[1] = b + 0x8000000;
            args[3] = i + 0x8000000;
            s.work.n = 0;
            s.owner = a;
            if (fn_80209028(1, &s) == 1) {
                s.kind = 1;
                s.cnt = 0;
                s.handle = 0;
                fn_80210F74(&s);
            }
        }
    }
}

extern s16 fn_80209330(s32, Scpt *);
void fn_80209238(s32 a, s32 b)
{
    Scpt s;
    s32 i;

    for (i = 0; i < 256; i++) {
        if (lbl_8030CEA0.ent[i][0] != 0) {
            s32 args[5] = { 0, 0, 0x1D, 0, 0x1D };
            s.cur.i = args;
            args[0] = a;
            args[1] = b + 0x8000000;
            args[3] = i + 0x8000000;
            s.work.n = 0;
            s.owner = a;
            if (fn_80209330(1, &s) == 1) {
                s.kind = 1;
                s.cnt = 0;
                s.handle = 0;
                fn_80210F74(&s);
            }
        }
    }
}

s32 fn_8020A72C(void) {
    return 0;
}

void fn_8020EEE8(s32 bank, s8 arg1, s8 id, s32 unused) {
    u32 r = SePlay(bank, arg1, id);
    if (r) {
        lbl_8030CEA0.x157c = r;
    } else {
        lbl_8030CEA0.x157c = 0;
    }
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

extern s32 lbl_803477E8;
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

typedef struct {
    u32 id;
    s32 slot;
    s32 time;
    s32 flag;
    u8 vol;
    u8 pad11[3];
} SndSlot;
extern SndSlot lbl_80315030[12];
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

void fn_801F5380(void) {
    fn_801F452C(0x102);
}

s32 fn_801F5BB4(s32 unused, Scpt *c) {
    u32 *p = c->cur.u;
    c->flags = 0;
    c->cur.u = p + 1;
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

s32 fn_801FED3C(s32 flag, Scpt *c) {
    if (flag & 1) {
        c->cur.u = c->cur.u + 1;
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

void fn_80216CB4(char *p) {
    fn_802193BC(p, 0);
}

extern void fn_80168398(f32 a, f32 b, f32 c, f32 d, s32 i0, s32 i1, s32 i2, s32 i3, u16 i4, u8 i5);
static inline s32 ReadInt(f32** p)
{
    if (3.4028235e38f == **p) {
        (*p)++;
        return 0x7FFFFFFF;
    }
    return (s32)fn_801F6120(p);
}
s32 fn_801F9988(u16 flags, Scpt* obj)
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
        p = obj->cur.f + 1;
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
        obj->cur.f = p;
        fn_80168398(f0, f1, f2, f3, c, d, e, b, a, h);
    }
    if (flags & 8)
        return 1;
    return 0;
}

extern void fn_80169144(f32 a, f32 b, f32 c, f32 d, s32 i0, s32 i1, s32 i2, s32 i3, u16 i4, u8 i5);
s32 fn_801F9C18(u16 flags, Scpt* obj)
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
        p = obj->cur.f + 1;
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
        obj->cur.f = p;
        fn_80169144(f0, f1, f2, f3, c, d, e, b, a, h);
    }
    if (flags & 8)
        return 1;
    return 0;
}

extern void fn_800D2C94(s32 v);
s32 fn_801FFE3C(u32 flags, Scpt *s)
{
    if (flags & 1) {
        u8 *p = s->cur.b + 4;
        u32 v;
        if (3.4028235e38f == *(f32 *)p) {
            p += 4;
            v = 0x7FFFFFFF;
        } else {
            v = (s32)fn_801F6120((f32**)&p);
        }
        s->cur.b = p;
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
s32 fn_801FFEF0(u32 flags, Scpt *s)
{
    if (flags & 1) {
        u8 *p = s->cur.b + 4;
        u32 v;
        if (3.4028235e38f == *(f32 *)p) {
            p += 4;
            v = 0x7FFFFFFF;
        } else {
            v = (s32)fn_801F6120((f32**)&p);
        }
        s->cur.b = p;
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

s32 fn_801F9668(u32 flags, Scpt *s)
{
    u16 f = (u16)flags;
    if (flags & 1) {
        u8 *p = s->cur.b + 4;
        u32 v;
        if (3.4028235e38f == *(f32 *)p) {
            p += 4;
            v = 0x7FFFFFFF;
        } else {
            v = (s32)fn_801F6120((f32**)&p);
        }
        s->cur.b = p;
        fn_80217830(v);
    }
    if (f & 0x8) {
        return 1;
    }
    return 0;
}

extern void fn_80168B7C(s32 v);
s32 fn_801F98E8(u32 flags, Scpt *s)
{
    u16 f = (u16)flags;
    if (flags & 1) {
        u8 *p = s->cur.b + 4;
        u32 v;
        if (3.4028235e38f == *(f32 *)p) {
            p += 4;
            v = 0x7FFFFFFF;
        } else {
            v = (s32)fn_801F6120((f32**)&p);
        }
        s->cur.b = p;
        fn_80168B7C(v);
    }
    if (f & 0x8) {
        return 1;
    }
    return 0;
}

extern void fn_800E2924(s32 v);
extern f32 lbl_8034C248;
s32 fn_8020B80C(u32 flags, Scpt *s)
{
    u16 f = (u16)flags;
    if (flags & 1) {
        u8 *p = s->cur.b + 4;
        u32 v;
        if (lbl_8034C248 == *(f32 *)p) {
            p += 4;
            v = 0x7FFFFFFF;
        } else {
            v = (s32)fn_801F6120((f32**)&p);
        }
        s->cur.b = p;
        fn_800E2924(v);
    }
    if (f & 0x8) {
        return 1;
    }
    return 0;
}

extern void fn_8021BD7C(s32 v);
s32 fn_8020B8AC(u32 flags, Scpt *s)
{
    u16 f = (u16)flags;
    if (flags & 1) {
        u8 *p = s->cur.b + 4;
        u32 v;
        if (lbl_8034C248 == *(f32 *)p) {
            p += 4;
            v = 0x7FFFFFFF;
        } else {
            v = (s32)fn_801F6120((f32**)&p);
        }
        s->cur.b = p;
        fn_8021BD7C(v);
    }
    if (f & 0x8) {
        return 1;
    }
    return 0;
}

extern void fn_801E4AB0(s32 v);
s32 fn_8020B94C(u32 flags, Scpt *s)
{
    u16 f = (u16)flags;
    if (flags & 1) {
        u8 *p = s->cur.b + 4;
        u32 v;
        if (lbl_8034C248 == *(f32 *)p) {
            p += 4;
            v = 0x7FFFFFFF;
        } else {
            v = (s32)fn_801F6120((f32**)&p);
        }
        s->cur.b = p;
        fn_801E4AB0(v);
    }
    if (f & 0x8) {
        return 1;
    }
    return 0;
}

extern void fn_800FF4EC(s32 v);
s32 fn_801FEB78(s32 flags, Scpt *s) {
    f32 *cur;
    s32 v;
    if (flags & 1) {
        cur = s->cur.f + 1;
        if (3.4028235e38f == *cur) {
            cur++;
            v = 0x7FFFFFFF;
        } else {
            v = (s32)fn_801F6120(&cur);
        }
        s->cur.f = cur;
        fn_800FF4EC(v);
    }
    return 0;
}

extern void fn_800FF5D0(s32 v);
s32 fn_801FEBFC(s32 flags, Scpt *s) {
    f32 *cur;
    s32 v;
    if (flags & 1) {
        cur = s->cur.f + 1;
        if (3.4028235e38f == *cur) {
            cur++;
            v = 0x7FFFFFFF;
        } else {
            v = (s32)fn_801F6120(&cur);
        }
        s->cur.f = cur;
        fn_800FF5D0(v);
    }
    return 0;
}

extern void fn_800FF6B4(s32 v);
s32 fn_801FEC80(s32 flags, Scpt *s) {
    f32 *cur;
    s32 v;
    if (flags & 1) {
        cur = s->cur.f + 1;
        if (3.4028235e38f == *cur) {
            cur++;
            v = 0x7FFFFFFF;
        } else {
            v = (s32)fn_801F6120(&cur);
        }
        s->cur.f = cur;
        fn_800FF6B4(v);
    }
    return 0;
}

extern void fn_80216D98(s32 v);
s32 fn_801FEDD0(s32 flags, Scpt *s) {
    f32 *cur;
    s32 v;
    if (flags & 1) {
        cur = s->cur.f + 1;
        if (3.4028235e38f == *cur) {
            cur++;
            v = 0x7FFFFFFF;
        } else {
            v = (s32)fn_801F6120(&cur);
        }
        s->cur.f = cur;
        fn_80216D98(v);
    }
    return 0;
}

void fn_80097294(u8 a);
void fn_80097204(f32 a, f32 b, f32 c);
void fn_80097318(s8 x);
s16 fn_80206FF4(u32 a0, Scpt *st) {
    s32 n;
    u16 a = a0;
    f32 x, y, z;
    if (a0 & 1) {
        u8 *p = st->cur.b;
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
        st->cur.b = p;
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
s16 fn_80207130(u32 a0, Scpt *st) {
    s32 n;
    u16 a = a0;
    f32 x, y, z;
    if (a0 & 1) {
        u8 *p = st->cur.b;
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
        st->cur.b = p;
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

s32 fn_801F8608(u32 flags, Scpt* s) {
    Work801F8* w;
    f32* cur;
    u16 f = flags;
    s32 v;
    if (f & 1) {
        cur = s->cur.f;
        w = fn_801E1A2C(1, 0x44);
        if (w == NULL) fn_801DBE1C("scptPlayMO3: malloc failed");
        s->work.work801F8 = w;
        cur = cur + 1;
        w->n = ReadInt(&cur);
        w->x1c = ReadInt(&cur);
        w->x20 = ReadInt(&cur);
        w->x24 = fn_801F6120(&cur);
        w->x28 = fn_801F6120(&cur);
        w->x2c = ReadInt(&cur);
        v = (u16)ReadInt(&cur);
        if (w->x28 == 3.4028235e38f) w->x28 = 0.0f;
        if (w->x2c == 0x7fffffff) w->x2c = 0;
        w->x2c = (u16)w->x2c;
        w->x2c |= v << 16;
        w->ev.hd.kind = 0;
        fn_80211058(s, 6, w->n, 0x25, lbl_8030CEA0.x08, &w->ev);
        s->cur.f = cur;
    }
    if (f & 2) {
        w = s->work.work801F8;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("PlayMO3: message post time out");
        } else if (w->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (f & 8) return 1;
    return 1;
}

s32 fn_801FC184(u32 flags, Scpt* s) {
    Work801FC* w;
    f32* cur;
    u16 f = flags;
    if (f & 1) {
        cur = s->cur.f;
        cur = cur + 1;
        w = fn_801E1A2C(1, 0x44);
        if (w == NULL) fn_801DBE1C("scptRollP: malloc failed");
        s->work.work801FC = w;
        w->n = ReadInt(&cur);
        w->x1c = fn_801F6120(&cur);
        w->x20 = fn_801F6120(&cur);
        w->x24 = fn_801F6120(&cur);
        w->x28 = ReadInt(&cur);
        w->x2c = ReadInt(&cur);
        w->x30 = ReadInt(&cur);
        w->x34 = fn_801F6120(&cur);
        s->cur.f = cur;
        if (f & 4) {
            if (fn_800CCC48(6, w->n) != 0) {
                fn_801E1784(w);
                return 0;
            }
        }
        w->ev.hd.kind = 0;
        fn_80211058(s, 6, w->n, 0xb, lbl_8030CEA0.x08, &w->ev);
    }
    if (f & 2) {
        w = s->work.work801FC;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("scptRollP: message post time out");
        } else if (w->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (f & 8) return 1;
    return 1;
}

s32 fn_801FC408(u32 flags, Scpt* s) {
    Work801FC* w;
    f32* cur;
    u16 f = flags;
    if (f & 1) {
        cur = s->cur.f;
        cur = cur + 1;
        w = fn_801E1A2C(1, 0x44);
        if (w == NULL) fn_801DBE1C("scptRollA: malloc failed");
        s->work.work801FC = w;
        w->n = ReadInt(&cur);
        w->x1c = fn_801F6120(&cur);
        w->x20 = fn_801F6120(&cur);
        w->x24 = fn_801F6120(&cur);
        w->x28 = ReadInt(&cur);
        w->x2c = ReadInt(&cur);
        w->x30 = ReadInt(&cur);
        w->x34 = fn_801F6120(&cur);
        s->cur.f = cur;
        if (f & 4) {
            if (fn_800CCC48(6, w->n) != 0) {
                fn_801E1784(w);
                return 0;
            }
        }
        w->ev.hd.kind = 0;
        fn_80211058(s, 6, w->n, 0xa, lbl_8030CEA0.x08, &w->ev);
    }
    if (f & 2) {
        w = s->work.work801FC;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("scptRollA: message post time out");
        } else if (w->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (f & 8) return 1;
    return 1;
}

s16 fn_8020660C(u16 f, Scpt* s) {
    f32 d, a1, a2, a3, b1, b2, b3, c, e, g, h;
    f32* cur;
    s32 i;
    if (f & 1) {
        cur = s->cur.f;
        fn_801F7500();
        cur = cur + 1;
        a1 = fn_801F6120(&cur);
        a2 = fn_801F6120(&cur);
        a3 = fn_801F6120(&cur);
        b1 = fn_801F6120(&cur);
        b2 = fn_801F6120(&cur);
        b3 = fn_801F6120(&cur);
        c = fn_801F6120(&cur);
        d = fn_801F6120(&cur);
        e = (f32)ReadInt(&cur);
        g = fn_801F6120(&cur);
        h = fn_801F6120(&cur);
        i = ReadInt(&cur);
        s->cur.f = cur;
        fn_80097294(6);
        if (a1 != 3.4028235e38f) fn_80097270(a1, a2, a3);
        if (b1 != 3.4028235e38f) fn_8009724C(b1, b2, b3);
        fn_800971C4(c);
        fn_800971E0(d, 0, 0);
        if (e == 0.0f) fn_80097150(0);
        if (e == 1.0f) fn_80097150(0x8000);
        if (g != 3.4028235e38f) fn_80097118(g);
        if (h != 3.4028235e38f) fn_800970FC(h);
        if (i == 0) fn_80097318(1);
        else fn_80097318(0);
    }
    return (f >> 3) & 1;
}

s32 fn_80209548(u32 flags, Scpt* s) {
    Work8020* w;
    f32* cur;
    u16 f = flags;
    if (f & 1) {
        cur = s->cur.f + 1;
        w = fn_801E1A2C(1, 0x44);
        if (w == NULL) fn_801DBE1C("Proll: malloc failed");
        s->work.work8020 = w;
        w->n = ReadInt(&cur);
        w->x1c = ReadInt(&cur);
        w->x20 = fn_801F6120(&cur);
        w->x24 = fn_801F6120(&cur);
        w->x28 = fn_801F6120(&cur);
        w->x38 = ReadInt(&cur);
        w->x3c = ReadInt(&cur);
        s->cur.f = cur;
        if (w->x38 == 0x7fffffff) w->x38 = 0;
        if (w->x1c == 0x7fffffff) w->x1c = 0;
        w->ev.hd.kind = 0;
        fn_80211058(s, 6, w->n, 0x22, lbl_8030CEA0.x08, &w->ev);
    }
    if (f & 2) {
        w = s->work.work8020;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("Proll: message post timed out");
        } else if (w->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (f & 8) return 1;
    return 1;
}

inline s32 FlagTest(u32 b) {
    return (lbl_80310B3C[b >> 5] & (1 << (b & 31))) != 0;
}

s32 fn_8020CBA4(u32 flags, Scpt* s) {
    f32* cur;
    s32 a;
    s32 b;
    s32 id;
    f32 v[3];
    f32 t;
    Actor* act;
    u32 bit;
    if (flags & 1) {
        cur = s->cur.f;
        cur = cur + 1;
        a = ReadInt(&cur);
        b = ReadInt(&cur);
        s->cur.f = cur;
        fn_8020EEE8(0, 1, 0xb, 1);
        bit = b + 0xa00;
        if (FlagTest(bit) == 1) return 0;
        switch (a) {
        case 0:
            id = 0x121;
            break;
        case 1:
            id = 0x103;
            break;
        case 2:
            id = 0x122;
            break;
        }
        lbl_80310B3C[bit >> 5] |= 1 << (bit & 31);
        fn_80210064(0xffff);
        v[1] = 0.005493164f * (f32)lbl_80311970.w[1];
        v[2] = 0.0f;
        v[0] = 0.0f;
        fn_8020F998(0xffff, v, 5, 2, 0x7fffffff, 0xc8);
        fn_8020FF44(0xffff, 3);
        fn_8020FDE0(0xffff, 0x32, 0x7fffffff, 0x64);
        act = fn_8015F1A0(0xffff);
        t = 0.005493164f * (f32)act->x44;
        lbl_802F7848.x7c = *(u32*)&t;
        t = 0.005493164f * (f32)act->x48;
        lbl_802F7848.x88 = *(u32*)&t;
        t = 0.005493164f * (f32)act->x4c;
        lbl_802F7848.x94 = *(u32*)&t;
        sprintf(lbl_803146A8, "\h(\x81\x40)You received %s [1]!\c", fn_801F4AE4((s16)id));
        fn_8021026C(lbl_803146A8);
        fn_801EFF0C((s16)id);
        lbl_8030CEA0.stack[++lbl_8030CEA0.sp] = s->cur.f;
        s->cur.f = (f32*)&lbl_802F7848;
    }
    return 0;
}

static inline void apply(Obj *o)
{
    o->x38 = o->x1c8->x44;
    o->x3c = o->x1c8->x48;
    o->x40 = o->x1c8->x4c;
    o->x44 = (s32)(182.04445f * o->x1c8->x50);
    o->x48 = (s32)(182.04445f * o->x1c8->x54);
    o->x4c = (s32)(182.04445f * o->x1c8->x58);
    o->x104 = o->x38;
    o->x108 = o->x3c;
    o->x10c = o->x40;
    o->x1bc->pos->x = o->x38;
    o->x1bc->pos->y = o->x3c;
    o->x1bc->pos->z = o->x40;
    o->x1bc->col->x = o->x44;
    o->x1bc->col->y = o->x48;
    o->x1bc->col->z = o->x4c;
    fn_80222838(o->x1bc);
}

s32 fn_8020CEB4(u32 flags, Scpt *c)
{
    u16 f = flags;
    float *p;
    u32 n, i;
    s32 v;
    Obj *o;
    s32 *src;
    if (flags & 1) {
        p = c->cur.f;
        p++;
        n = *(u32 *)p++;
        for (i = 0; i < n; i++) {
            if (*p == 3.4028235e38f) {
                p++;
                v = 0x7FFFFFFF;
            } else {
                v = (s32)fn_801F6120(&p);
            }
            o = fn_8015F180(fn_8015F1A0((u16)v));
            apply(o);
            src = o->x1c8->x10;
            v = (*src > 8) ? src[9] : 0;
            o = fn_8015F180(fn_8015F1A0((u16)v));
            apply(o);
        }
        c->cur.f = p;
    }
    if (f & 8) {
        return 1;
    }
    return 0;
}

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

s16 fn_801F984C(u32 flags, Scpt *st) {
    u16 f = flags;
    if (flags & 1) {
        float *p = st->cur.f + 1;
        s32 n;
        if (*p == 3.4028235e38f) {
            p++;
            n = 0x7FFFFFFF;
        } else {
            n = (s32)fn_801F6120(&p);
        }
        st->cur.f = p;
        if ((u32)n >= 3) {
            fn_80217830(n);
        }
    }
    return (f >> 3) & 1;
}

s32 fn_801FD850(u32 flags, Scpt *st) {
    u16 f = flags;
    if (flags & 1) {
        float *p = st->cur.f + 1;
        s32 n;
        if (*p == 3.4028235e38f) {
            p++;
            n = 0x7FFFFFFF;
        } else {
            n = (s32)fn_801F6120(&p);
        }
        fn_8016D904(n);
        st->cur.f = p;
    }
    if (f & 8) return 1;
    return 0;
}

s32 fn_801FDC70(u32 flags, Scpt *st) {
    if (flags & 1) {
        float *p = st->cur.f + 1;
        if (*p == 3.4028235e38f) {
            p++;
        } else {
            fn_801F6120(&p);
        }
        st->cur.f = p;
    }
    return 0;
}

s32 fn_801FDE70(u32 flags, Scpt *st) {
    u16 f = flags;
    if (flags & 1) {
        float a[4];
        float *p = st->cur.f + 1;
        a[0] = fn_801F6120(&p);
        a[1] = fn_801F6120(&p);
        a[2] = fn_801F6120(&p);
        a[3] = fn_801F6120(&p);
        st->cur.f = p;
        fn_801E749C(a);
    }
    if (f & 8) return 1;
    return 0;
}

s32 fn_801FED58(u32 flags, Scpt *st) {
    u16 f = flags;
    if (flags & 1) {
        u8 *c = st->cur.b;
        st->cur.b = c + 4;
        fn_800FF780(c);
        return 1;
    }
    if ((f & 2) && lbl_803473B4 == 0) {
        return 0;
    }
    if (f & 8) {
        return 0;
    }
    return 1;
}

s32 fn_801FEE54(u32 flags, Scpt *st) {
    if (flags & 1) {
        float *p = st->cur.f + 1;
        s32 n;
        if (*p == 3.4028235e38f) {
            p++;
            n = 0x7FFFFFFF;
        } else {
            n = (s32)fn_801F6120(&p);
        }
        {
            u32 w;
            u8 *q = (u8 *)p;
            w = *(u32 *)q;
            p = (float *)(q + 4);
            st->cur.f = p;
            fn_80216E38(n, q + w);
        }
    }
    return 0;
}

s32 fn_801FFDB4(u32 flags, Scpt *st) {
    if (flags & 1) {
        float *p = st->cur.f + 1;
        s32 n;
        if (*p == 3.4028235e38f) {
            p++;
            n = 0x7FFFFFFF;
        } else {
            n = (s32)fn_801F6120(&p);
        }
        fn_800D2C44((u16)n);
        st->cur.f = p;
    }
    return 0;
}

s16 fn_80204F04(u32 flags, Scpt *st) {
    u16 f = flags;
    if (flags & 1) {
        float *p = st->cur.f;
        float v;
        p++;
        v = fn_801F6120(&p);
        st->cur.f = p;
        if (v == 3.4028235e38f) {
            fn_8022D34C(1, 60.0f);
        } else {
            fn_8022D34C(1, v);
        }
    }
    return (f >> 3) & 1;
}

s32 fn_802073B4(u32 flags, Scpt *st) {
    u16 f = flags;
    if (flags & 1) {
        u8 *c = st->cur.b;
        u32 w = *(u32 *)(c + 4);
        u8 *q = c + 4;
        fn_801002D0(q + w);
        st->cur.b = q + 4;
    }
    if (f & 8) return 1;
    return 0;
}

s32 fn_80207428(u32 flags, Scpt *st) {
    u16 f = flags;
    if (flags & 1) {
        u8 *c = st->cur.b;
        u32 w = *(u32 *)(c + 4);
        u8 *q = c + 4;
        fn_801002D0(q + w);
        st->cur.b = q + 4;
        fn_801F7B04(0x9C40);
        lbl_80347474 = 1;
    }
    if (f & 8) return 1;
    return 0;
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

void *fn_80215EA0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h)
{
    return fn_802159E0(1, a, b, c, d, e, f, g, h);
}

void *fn_80215F14(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, char *path)
{
    return fn_802159E0(1, a, b, c, d, e, f, (s32)path, 0x8000);
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

void fn_801F7B04(s32 v) {
    lbl_8030CEA0.x1580 = v;
}

s32 fn_801FD1D0(u32 flags, Scpt *st) {
    if (flags & 1) {
        float *p = st->cur.f + 1;
        s32 n;
        if (*p == 3.4028235e38f) {
            p++;
            n = 0x7FFFFFFF;
        } else {
            n = (s32)fn_801F6120(&p);
        }
        st->cur.f = p;
        lbl_8030CEA0.x82c = 2;
        lbl_8030CEA0.x834 = n;
    }
    return 0;
}

s16 fn_8020A2C8(u32 flags, Scpt *st) {
    u16 f = flags;
    u8 *c = st->cur.b;
    if (flags & 1) {
        s32 v;
        st->cur.b = c + 4;
        v = fn_8011768C(flags);
        if (v != -1) {
            lbl_8030CEA0.x1574 = v;
        } else {
            lbl_8030CEA0.x1574 = 0;
        }
    }
    return (f >> 3) & 1;
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

s32 fn_80205E48(u32 a0, Scpt *st) {
    s32 n;
    u16 a = a0;
    if (a0 & 1) {
        f32 *p = st->cur.f;
        fn_801F7500();
        if (3.4028235e38f == *p) {
            p++;
            n = 0x7fffffff;
        } else {
            n = (s32)fn_801F6120(&p);
        }
        fn_80097294(9);
        if ((u16)n == 0) {
            fn_80097318(1);
        } else {
            fn_80097318(0);
        }
        st->cur.f = p;
    }
    if (a & 8) return 1;
    return 0;
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

s32 fn_801FDCDC(u32 flags, Scpt *st) {
    s32 n;
    u16 f = flags;
    if (flags & 1) {
        float *p = st->cur.f + 1;
        if (*p == 3.4028235e38f) {
            p++;
            n = 0x7FFFFFFF;
        } else {
            n = (s32)fn_801F6120(&p);
        }
        st->cur.f = p;
        fn_801BEA70(lbl_8034759C, n, fn_8020E984());
    }
    if ((f & 2) && lbl_803473C0 == 0) return 0;
    if (f & 8) return 0;
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

s16 fn_80204E28(u32 a0, Scpt *st) {
    u32 n;
    u16 a = a0;
    f32 x;
    if (a0 & 1) {
        u8 *p = st->cur.b + 4;
        x = fn_801F6120((f32**)&p);
        if (3.4028235e38f == *(f32 *)p) {
            p += 4;
            n = 0x7fffffff;
        } else {
            n = (s32)fn_801F6120((f32**)&p);
        }
        st->cur.b = p;
        if (n == 0) {
            n = 1;
        }
        if (3.4028235e38f == x) {
            fn_8022D34C(n, 60.0f);
        } else {
            fn_8022D34C(n, x);
        }
    }
    return (a >> 3) & 1;
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
    s->half = h;
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

s16 fn_8020B9EC(u16 flags, Scpt *st) {
    if (flags & 1) {
        float *p = st->cur.f + 1;
        s32 i = RDI(p);
        st->cur.f = p;
        switch (i) {
        case 0:
            fn_800EB58C(1);
            break;
        case 1:
            fn_800EB58C(2);
            break;
        case 2:
            fn_800EB58C(3);
            break;
        case 3:
            fn_800EB58C(4);
            break;
        case 4:
            fn_800EB58C(5);
            break;
        }
    }
    return (flags >> 3) & 1;
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

s16 fn_801F6EC8(s32 v) {
    s32 i;
    for (i = 0; i < 256; i++) {
        if (lbl_8030CEA0.ent[i][1] == v) {
            return i;
        }
    }
    return -1;
}

s32 fn_801F934C(u32 flags, Scpt *st) {
    s32 n;
    u16 f = flags;
    if (flags & 1) {
        float *p = st->cur.f + 1;
        if (*p == 3.4028235e38f) {
            p++;
            n = 0x7FFFFFFF;
        } else {
            n = (s32)fn_801F6120(&p);
        }
        st->cur.f = p;
        if (lbl_8030CE94.flag != 0) {
            fn_800D23F8(n, lbl_8030CE94.f4, 0.0f, lbl_8030CE94.i8);
        } else {
            fn_800D244C(n, lbl_8030CE94.f4, 0.0f, lbl_8030CE94.i8);
        }
        fn_80211EB0(2, (f32)n);
    }
    if (f & 8) {
        return 1;
    }
    return 0;
}

s32 fn_801FA290(u32 flags, Scpt *st) {
    u16 f = flags;
    if (flags & 1) {
        float *p = st->cur.f + 1;
        s32 n;
        s16 m;
        if (*p == 3.4028235e38f) {
            p++;
            n = 0x7FFFFFFF;
        } else {
            n = (s32)fn_801F6120(&p);
        }
        m = n;
        if (m <= 0) {
            m = 1;
        }
        fn_8021730C(1, (s32)(f32)fn_8026216C((f32)m * (16.666666f * (f32)lbl_803475B4)));
        st->cur.f = p;
    }
    if (f & 8) {
        return 1;
    }
    return 0;
}

s32 fn_80207630(u32 flags, Scpt *st) {
    if (flags & 1) {
        float *p = st->cur.f;
        s32 i;
        s32 cnt;
        s32 *q = (s32 *)++p;
        p++;
        cnt = *q;
        for (i = 0; i < cnt; i++) {
            s32 n;
            u16 id;
            void *a;
            if (*p == 3.4028235e38f) {
                p++;
                n = 0x7FFFFFFF;
            } else {
                n = (s32)fn_801F6120(&p);
            }
            id = n;
            fn_80210EA4(id, 2);
            a = fn_8015F1A0(id);
            if (fn_8015F1F0(a) == 1) {
                Obj_80207630 *o = fn_8015F180(a);
                o->f190 = 0.0f;
            }
        }
        st->cur.f = p;
    }
    return 0;
}

s16 fn_802057E0(u32 flags, Scpt *st) {
    u16 f = flags;
    if (flags & 1) {
        float *p = st->cur.f;
        s8 a;
        s32 b;
        fn_801F7500();
        p++;
        a = RDI(p);
        b = RDI(p);
        st->cur.f = p;
        fn_80097294(0xd);
        fn_8009701C(a);
        if (b == 0) {
            fn_80097318(1);
        } else {
            fn_80097318(0);
        }
    }
    return (f >> 3) & 1;
}

s32 fn_80216B88(Slot_80216B88 **out) {
    s32 i;
    u32 j;
    u32 id;
    Slot_80216B88 *base = lbl_80314B80.s;
    Slot_80216B88 *p = base;
    for (i = 0; i < 4; p++, i++) {
        if (p->used == 0) {
            do {
                id = lbl_80314B80.counter++;
                if (id == -1) {
                    id = lbl_80314B80.counter++;
                }
                for (j = 0; j < 4; j++) {
                    if (base[j].used != 0 && id == base[j].id) {
                        break;
                    }
                }
            } while (j != 4);
            lbl_80314B80.s[i].used = 1;
            lbl_80314B80.s[i].id = id;
            lbl_80314B80.s[i].f8 = 0;
            lbl_80314B80.s[i].fc = 0;
            *out = &lbl_80314B80.s[i];
            return id;
        }
    }
    return -1;
}

s32 fn_801FA398(u16 flags, Scpt *c)
{
    float *p;
    s8 a;
    s8 b;
    if (flags & 1) {
        p = c->cur.f + 1;
        a = RDI(p);
        b = RDI(p);
        RDI(p);
        c->cur.f = p;
        fn_80218570(0, a, b);
    }
    if (flags & 8) {
        return 1;
    }
    return 0;
}

s16 fn_802058F8(u32 a0, Scpt *st) {
    s32 n;
    u16 a = a0;
    f32 x, y, z;
    if (a0 & 1) {
        u8 *p = st->cur.b;
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
        st->cur.b = p;
        fn_80097294(1);
        if (3.4028235e38f != x) {
            fn_80097204(x, y, z);
        }
        fn_800972E0(0);
        if (n == 0) {
            fn_80097318(1);
        } else {
            fn_80097318(0);
        }
    }
    return (a >> 3) & 1;
}

s32 fn_801FEF80(u32 flags, Scpt *c) {
    float *p;
    u16 a;
    s32 t;
    s32 b;
    if (flags & 1) {
        p = c->cur.f + 1;
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
        fn_80225CAC(0xffff, a, b);
    }
    return 0;
}

s32 fn_80204BE8(u16 flags, Scpt *c) {
    float *p;
    f32 a[3];
    f32 b[3];
    if (flags & 1) {
        p = c->cur.f;
        fn_801F7500();
        p++;
        a[0] = fn_801F6120(&p);
        a[1] = fn_801F6120(&p);
        a[2] = fn_801F6120(&p);
        b[0] = fn_801F6120(&p);
        b[1] = fn_801F6120(&p);
        b[2] = fn_801F6120(&p);
        c->cur.f = p;
        lbl_8030CEA0.x18fc = a[0];
        lbl_8030CEA0.x1900 = a[1];
        lbl_8030CEA0.x1904 = a[2];
        fn_80213478(b, a, &lbl_8030CEA0.x1908);
    }
    if (flags & 8) return 1;
    return 0;
}

s32 fn_8020D1C0(u16 flags, Scpt *c) {
    float *p;
    s32 a, b;
    if (flags & 1) {
        p = c->cur.f + 1;
        a = RDI(p);
        b = RDI(p);
        fn_801000F0(a, b);
        c->cur.f = p;
    }
    if (flags & 8) return 1;
    return 0;
}

s32 fn_8020A048(u32 flags, Scpt *c) {
    float *p;
    s32 a;
    f32 x;
    f32 y;
    f32 z;
    f32 w;
    u16 fl = flags;
    p = c->cur.f;
    if (flags & 1) {
        p++;
        if (*p == 3.4028235e38f) {
            p++;
            a = 0x7FFFFFFF;
        } else {
            a = (s32)fn_801F6120(&p);
        }
        x = fn_801F6120(&p);
        y = fn_801F6120(&p);
        z = fn_801F6120(&p);
        w = fn_801F6120(&p);
        fn_80118578(a, x, y, z, w);
        c->cur.f = p;
    }
    if (fl & 8) {
        return 1;
    }
    return 0;
}

s32 fn_8020170C(u16 flags, Scpt *c) {
    float *p;
    u32 t;
    if (flags & 1) {
        p = c->cur.f;
        p++;
        if (*p == 3.4028235e38f) {
            p++;
            t = 0x7FFFFFFF;
        } else {
            t = (s32)fn_801F6120(&p);
        }
        c->cur.f = p;
        c->work.n = 0;
        if (t == 0) {
            fn_801CBBBC();
            return 0;
        }
        if (t == 0x7FFFFFFF) {
            lbl_80347514 = 30.0f;
        } else {
            lbl_80347514 = (f32)(t + 1);
        }
        lbl_80347510 = 1.0f;
        lbl_80347518 = 0;
    }
    if (flags & 2) {
        if (c->work.n != 0) {
            if (lbl_80347508 == 0) {
                c->work.n = 0;
                return 0;
            }
        } else {
            c->work.n = 1;
        }
    }
    if (flags & 8) {
        c->work.n = 0;
        return 0;
    }
    return 1;
}

s32 fn_801FD584(u32 flags, Scpt* c) {
    float* p;
    s32 t;
    Obj10A* o;
    if (flags & 1) {
        p = c->cur.f + 1;
        RDI(p);
        t = RDI(p);
        c->cur.f = p;
        o = fn_8010A164(t);
        if (o == 0) {
            fn_801DBE1C(lbl_802D4D7C, t);
        }
        fn_8015F654(o->x24);
        return 0;
    }
    return 1;
}

s32 fn_801FF380(u32 flags, Scpt *cmd)
{
    if (flags & 1) {
        float *p;
        s32 a, b;
        Obj10A* c;
    Actor* m;
        p = cmd->cur.f + 1;
        a = RDI(p);
        b = RDI(p);
        cmd->cur.f = p;
        c = fn_8010A164(b);
        if (c != 0 && (m = c->x24) != 0 && m->b26c == 1) {
            m->x1d8->x1a0 = a;
        }
    }
    return 0;
}

s32 fn_801FE21C(u16 flags, Scpt *st) {
    s32 i;
    if (flags & 1) {
        float *p = st->cur.f + 1;
        i = (*p == 3.4028235e38f) ? (p++, 0x7FFFFFFF) : (s32)fn_801F6120(&p);
        st->cur.f = p;
        lbl_8030CEA0.x1584[i] = (s32)(9999.0f * (3.0517578e-05f * (f32)rand()));
    }
    if (flags & 8) {
        return 1;
    }
    return 0;
}

s16 fn_80200CE4(u32 flags, Scpt *st) {
    s32 n;
    u16 f = flags;
    if (flags & 1) {
        float *p = st->cur.f + 1;
        f32 a, b, c;
        if (*p == 3.4028235e38f) {
            p++;
            n = 0x7FFFFFFF;
        } else {
            n = (s32)fn_801F6120(&p);
        }
        a = fn_801F6120(&p);
        b = fn_801F6120(&p);
        c = fn_801F6120(&p);
        fn_801D995C(n, a, b, c);
        st->cur.f = p;
        lbl_8030CEA0.xc6c = 0;
        lbl_8030CEA0.xc86 = 0;
    }
    if (f & 8) {
        return 0;
    }
    return 0;
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

s32 fn_80200FC4(u32 flags, Scpt *st) {
    if (flags & 1) {
        float *p = st->cur.f + 1;
        s32 r, g, b;
        u32 d, e;
        u32 rgb;
        f32 f1, f3, f2, f4;
        r = RDI(p);
        g = RDI(p);
        b = RDI(p);
        d = RDI(p);
        f1 = fn_801F6120(&p);
        f2 = fn_801F6120(&p);
        e = RDI(p);
        f3 = fn_801F6120(&p);
        f4 = fn_801F6120(&p);
        rgb = ((r & 0xff) << 16) | ((g & 0xff) << 8) | (b & 0xff);
        if (d == 0x7FFFFFFF || d == 0) {
            d = 1;
        }
        if (f1 == 3.4028235e38f) {
            f1 = 1.0f;
        }
        if (e == 0x7FFFFFFF || e == 0) {
            e = 1;
        }
        if (f3 == 3.4028235e38f) {
            f3 = 200.0f;
        }
        st->cur.f = p;
        fn_800D2554(f2, f4);
        fn_800D25C4(rgb, d);
        fn_800D258C(e, f1, f3);
        fn_800D2CA8(1);
    }
    return 0;
}

s32 fn_80201228(u32 flags, Scpt *st) {
    if (flags & 1) {
        float *p = st->cur.f + 1;
        s32 r, g, b;
        u32 d, e;
        u32 rgb;
        f32 f1, f2;
        r = RDI(p);
        g = RDI(p);
        b = RDI(p);
        d = RDI(p);
        f1 = fn_801F6120(&p);
        f2 = fn_801F6120(&p);
        e = RDI(p);
        rgb = ((r & 0xff) << 16) | ((g & 0xff) << 8) | (b & 0xff);
        if (d == 0x7FFFFFFF) {
            d = 1;
        }
        if (f1 == 3.4028235e38f) {
            f1 = 1.0f;
        }
        if (f2 == 3.4028235e38f) {
            f2 = 200.0f;
        }
        if (e == 0x7FFFFFFF) {
            e = 1;
        }
        st->cur.f = p;
        fn_800D2554(0.0f, 1.0f);
        fn_800D25C4(rgb, d);
        fn_800D258C(e, f1, f2);
        fn_800D2CA8(1);
    }
    return 0;
}

s32 fn_80202004(u32 flags, Scpt* s)
{
    Work_80202004* w;
    f32* p;
    u16 f = flags;
    if (f & 1) {
        p = s->cur.f;
        p++;
        w = fn_801E1A2C(1, 0x44);
        if (w == NULL) fn_801DBE1C("scptHclose: malloc failed");
        s->work.work_80202004 = w;
        w->x18 = RDI(p);
        w->x1c = 0;
        w->x20 = RDI(p);
        s->cur.f = p;
        w->hd.kind = 0;
        fn_802110E8(s, 7, w->x18, 1, lbl_8030CEA0.x08, &w->hd);
    }
    if (f & 2) {
        w = s->work.work_80202004;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("scptHclose: message post time out");
        } else if (w->hd.kind == 2) {
            return 0;
        }
    }
    return !(f & 8);
}

s16 fn_802049BC(u16 a, Scpt *st) {
    if (a & 1) {
        f32 *cur = st->cur.f;
        f32 f0, f1, f2, f3, f4, f5;
        u16 id;
        u16 v;
        fn_801F7500();
        cur++;
        f0 = fn_801F6120(&cur);
        f1 = fn_801F6120(&cur);
        f2 = fn_801F6120(&cur);
        id = RDI(cur);
        f3 = fn_801F6120(&cur);
        f4 = fn_801F6120(&cur);
        f5 = fn_801F6120(&cur);
        v = RDI(cur);
        st->cur.f = cur;
        if (f3 == 3.4028235e38f) {
            f3 = 0.0f;
        }
        if (f4 == 3.4028235e38f) {
            f4 = 14.0f;
        }
        if (f5 == 3.4028235e38f) {
            f5 = 0.0f;
        }
        fn_80097294(2);
        fn_80097094(id, f4);
        fn_80097204(0.0f, 0.0f, 0.0f);
        fn_8009724C(f3, f4, f5);
        fn_80097228(f0, f1, f2);
        if (v == 0) {
            fn_80097318(1);
        } else {
            fn_80097318(0);
        }
    }
    return (a >> 3) & 1;
}

s32 fn_80204CD0(u16 a, Scpt *st) {
    if (a & 1) {
        f32 *cur = st->cur.f;
        f32 f0, f1, f2, f3, f4, f5;
        fn_801F7500();
        cur++;
        f0 = fn_801F6120(&cur);
        f1 = fn_801F6120(&cur);
        f2 = fn_801F6120(&cur);
        f3 = fn_801F6120(&cur);
        f4 = fn_801F6120(&cur);
        f5 = fn_801F6120(&cur);
        st->cur.f = cur;
        lbl_8030CEA0.x18fc = f0;
        lbl_8030CEA0.x1900 = f1;
        lbl_8030CEA0.x1904 = f2;
        lbl_8030CEA0.x1908 = (s32)(182.04445f * f3);
        lbl_8030CEA0.x190c = (s32)(182.04445f * f4);
        lbl_8030CEA0.x1910 = (s32)(182.04445f * f5);
    }
    if (a & 8) {
        return 1;
    }
    return 0;
}

s32 fn_80204F8C(u32 flags, Scpt* s)
{
    Lerp* w;
    f32* p;
    f32 a[3];
    s32 n;
    s32 d[3];
    u32 f = flags & 0xffff;
    if (f & 1) {
        p = s->cur.f;
        fn_801F7500();
        p++;
        a[0] = fn_801F6120(&p);
        a[1] = fn_801F6120(&p);
        a[2] = fn_801F6120(&p);
        if (*p == 3.4028235e38f) {
            p++;
            n = 0x7FFFFFFF;
        } else {
            n = (s32)fn_801F6120(&p);
        }
        s->cur.f = p;
        fn_80213478(a, &lbl_8030CEA0.x18fc, d);
        if (n <= 0 || n == 1) {
            lbl_8030CEA0.x1908 = d[0];
            lbl_8030CEA0.x190c = d[1];
            lbl_8030CEA0.x1910 = d[2];
            return 0;
        }
        lbl_8030CEA0.x15cc = 1;
        w = fn_801E1A2C(1, 0x1c);
        w->total = n;
        w->step[0] = (s16)(d[0] - lbl_8030CEA0.x1908) / n;
        w->step[1] = (s16)(d[1] - lbl_8030CEA0.x190c) / n;
        w->step[2] = (s16)(d[2] - lbl_8030CEA0.x1910) / n;
        w->dest[0] = d[0];
        w->dest[1] = d[1];
        w->dest[2] = d[2];
        s->work.lerp = w;
    }
    if (f & 2) {
        w = s->work.lerp;
        lbl_8030CEA0.x1908 += w->step[0];
        lbl_8030CEA0.x190c += w->step[1];
        lbl_8030CEA0.x1910 += w->step[2];

        if (++s->cnt == w->total) {
            lbl_8030CEA0.x1908 = w->dest[0];
            lbl_8030CEA0.x190c = w->dest[1];
            lbl_8030CEA0.x1910 = w->dest[2];
            lbl_8030CEA0.x15cc = 0;
            return 0;
        }
    }
    if (f & 8) {
        lbl_8030CEA0.x15cc = 0;
    }
    return 1;
}

s32 fn_8020549C(u32 flags, Scpt* s)
{
    Lerp* w;
    f32* p;
    s32 n;
    u32 f = flags & 0xffff;
    s32 d0, d1, d2;
    if (f & 1) {
        p = s->cur.f;
        fn_801F7500();
        p++;
        d0 = 182.04445f * fn_801F6120(&p);
        d1 = 182.04445f * fn_801F6120(&p);
        d2 = 182.04445f * fn_801F6120(&p);
        if (*p == 3.4028235e38f) {
            p++;
            n = 0x7FFFFFFF;
        } else {
            n = (s32)fn_801F6120(&p);
        }
        s->cur.f = p;
        if (n <= 0 || n == 1) {
            lbl_8030CEA0.x1908 = d0;
            lbl_8030CEA0.x190c = d1;
            lbl_8030CEA0.x1910 = d2;
            return 0;
        }
        lbl_8030CEA0.x15cc = 1;
        w = fn_801E1A2C(1, 0x1c);
        w->total = n;
        w->step[0] = (s16)(d0 - lbl_8030CEA0.x1908) / n;
        w->step[1] = (s16)(d1 - lbl_8030CEA0.x190c) / n;
        w->step[2] = (s16)(d2 - lbl_8030CEA0.x1910) / n;
        w->dest[0] = d0;
        w->dest[1] = d1;
        w->dest[2] = d2;
        s->work.lerp = w;
    }
    if (f & 2) {
        w = s->work.lerp;
        lbl_8030CEA0.x1908 += w->step[0];
        lbl_8030CEA0.x190c += w->step[1];
        lbl_8030CEA0.x1910 += w->step[2];

        if (s->cnt++ == w->total) {
            lbl_8030CEA0.x15cc = 0;
            return 0;
        }
    }
    if (f & 8) {
        lbl_8030CEA0.x15cc = 0;
    }
    return 1;
}

s16 fn_80205A3C(u16 a, Scpt *st) {
    if (a & 1) {
        f32 *cur = st->cur.f;
        f32 f0, f1, f2, f3, f4, f5;
        s32 v;
        fn_801F7500();
        cur++;
        f0 = fn_801F6120(&cur);
        f1 = fn_801F6120(&cur);
        f2 = fn_801F6120(&cur);
        f3 = fn_801F6120(&cur);
        f4 = fn_801F6120(&cur);
        f5 = fn_801F6120(&cur);
        v = RDI(cur);
        st->cur.f = cur;
        fn_80097294(11);
        if (f0 != 3.4028235e38f) {
            fn_80097204(f0, f1, f2);
        }
        if (f3 == 3.4028235e38f) {
            f3 = 14.0f;
        }
        fn_8009724C(0.0f, f3, 0.0f);
        if (f4 == 3.4028235e38f) {
            f4 = 40.0f;
        }
        fn_800971A8(f4);
        if (f5 == 3.4028235e38f) {
            f5 = 348.0f;
        }
        fn_80097134((s32)f5);
        if (v == 0) {
            fn_80097318(1);
        } else {
            fn_80097318(0);
        }
    }
    return (a >> 3) & 1;
}

s32 fn_802060D4(u16 a, Scpt *st) {
    if (a & 1) {
        s32 id;
        s32 v;
        f32 f;
        f32 *cur = st->cur.f;
        fn_801F7500();
        cur++;
        id = (u16)RDI(cur);
        v = RDI(cur);
        if (v == 0x7fffffff) {
            v = 100;
        }
        st->cur.f = cur;
        fn_80097294(7);
        f = v / 100.0f;
        fn_800970D8(id, f, 0);
        fn_800970B4(id, f, 1);
    }
    if (a & 8) {
        return 1;
    }
    return 0;
}

s16 fn_80206904(u16 a, Scpt *st) {
    if (a & 1) {
        f32 *cur = st->cur.f;
        f32 f0, f1, f2, f3, f4, f5;
        s32 v;
        fn_801F7500();
        cur++;
        f0 = fn_801F6120(&cur);
        f1 = fn_801F6120(&cur);
        f2 = fn_801F6120(&cur);
        f3 = fn_801F6120(&cur);
        f4 = fn_801F6120(&cur);
        f5 = fn_801F6120(&cur);
        v = RDI(cur);
        st->cur.f = cur;
        fn_80097294(5);
        if (f0 != 3.4028235e38f) {
            fn_80097228(f0, f1, f2);
        }
        if (f3 != 3.4028235e38f) {
            fn_8009724C(f3, f4, f5);
        }
        if (v == 0) {
            fn_80097318(1);
        } else {
            fn_80097318(0);
        }
    }
    return (a >> 3) & 1;
}

s16 fn_80206AB0(u16 a, Scpt *st) {
    if (a & 1) {
        f32 *cur = st->cur.f;
        f32 f0, f1, f2, f3, f4, f5, f6, f7;
        s32 v;
        fn_801F7500();
        fn_80097294(4);
        cur++;
        f0 = fn_801F6120(&cur);
        f1 = fn_801F6120(&cur);
        f2 = fn_801F6120(&cur);
        fn_80097204(f0, f1, f2);
        f3 = fn_801F6120(&cur);
        f4 = fn_801F6120(&cur);
        f5 = fn_801F6120(&cur);
        fn_8009724C(f3, f4, f5);
        f6 = fn_801F6120(&cur);
        f7 = fn_801F6120(&cur);
        fn_80097188(f6, f7);
        v = RDI(cur);
        fn_8009716C(RDI(cur));
        st->cur.f = cur;
        if (f0 != 3.4028235e38f) {
            fn_80097204(f0, f1, f2);
        }
        if (v == 0) {
            fn_80097318(1);
        } else {
            fn_80097318(0);
        }
    }
    return (a >> 3) & 1;
}

s16 fn_80206CBC(u16 a, Scpt *st) {
    if (a & 1) {
        f32 *cur = st->cur.f;
        Eff *w;
        fn_801F7500();
        cur++;
        w = fn_801E1A2C(1, 0x24);
        w->f[0] = fn_801F6120(&cur);
        w->f[1] = fn_801F6120(&cur);
        w->f[2] = fn_801F6120(&cur);
        w->f[3] = fn_801F6120(&cur);
        w->f[4] = fn_801F6120(&cur);
        w->f[5] = fn_801F6120(&cur);
        w->f[6] = fn_801F6120(&cur);
        w->f[7] = fn_801F6120(&cur);
        w->x20 = RDI(cur);
        st->work.eff = w;
        st->cur.f = cur;
        st->a20 = 2;
        st->flags = 0;
        return 1;
    }
    if (a & 2) {
        Eff *w;
        if (--st->a20 == 0) {
            w = st->work.eff;
            st->a20 = 0;
            fn_80097294(3);
            if (w->f[0] != 3.4028235e38f) {
                fn_80097204(w->f[0], w->f[1], w->f[2]);
            }
            if (w->f[3] != 3.4028235e38f) {
                fn_8009724C(w->f[3], w->f[4], w->f[5]);
            }
            if (w->f[6] != 3.4028235e38f) {
                fn_80097118(w->f[6]);
            }
            if (w->f[7] != 3.4028235e38f) {
                fn_800970FC(w->f[7]);
            }
            if (w->x20 == 0) {
                fn_80097318(1);
            } else {
                fn_80097318(0);
            }
            return 0;
            }
        return 1;
    }
    return (a >> 3) & 1;
}

s16 fn_80206EA8(u16 a, Scpt *st) {
    if (a & 1) {
        f32 *cur = st->cur.f;
        s32 v;
        u16 id;
        f32 f;
        fn_801F7500();
        lbl_80310B3C[34] |= 2;
        cur++;
        id = RDI(cur);
        f = fn_801F6120(&cur);
        v = RDI(cur);
        st->cur.f = cur;
        fn_80097294(2);
        fn_80097094(id, f);
        if ((u16)v == 0) {
            fn_80097318(1);
        } else {
            fn_80097318(0);
        }
    }
    return (a >> 3) & 1;
}

s32 fn_8020A168(u16 flags, Scpt* c)
{
    f32* p = c->cur.f;
    if (flags & 1) {
        s32 n;
        f32 a, b, d, e, f, g;
        p++;
        n = RDI(p);
        a = fn_801F6120(&p);
        b = fn_801F6120(&p);
        d = fn_801F6120(&p);
        e = fn_801F6120(&p);
        f = fn_801F6120(&p);
        g = fn_801F6120(&p);
        fn_801185A8(n, a, b, d, e, f, g);
        c->cur.f = p;
    }
    if (flags & 8) {
        return 1;
    }
    return 0;
}

s32 fn_8020B670(u32 flags, Scpt* s)
{
    f32 pos[3];
    u32 ids[3];
    f32* p;
    u16 f = flags;
    if (f & 1) {
        p = s->cur.f + 1;
        pos[0] = fn_801F6120(&p);
        pos[1] = fn_801F6120(&p);
        pos[2] = fn_801F6120(&p);
        ids[0] = RDI(p);
        ids[1] = RDI(p);
        ids[2] = RDI(p);
        s->cur.f = p;
        if (ids[0] == 0x7FFFFFFF) ids[0] = 0xff;
        if (ids[1] == 0x7FFFFFFF) ids[1] = 0;
        if (ids[2] == 0x7FFFFFFF) ids[2] = 0;
        fn_800E28D4(pos, ids);
    }
    if (f & 8) return 1;
    return 0;
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

void fn_80216744(Strm_80216744 *s)
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
            fn_801DBE1C(lbl_802D478C);
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
            fn_801DBE1C(lbl_802D47A4);
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
        fn_80213178((f32)lbl_8030CEA0.x1918, (f32)s->times[s->idx], s->xc[s->idx], s->x10[s->idx].a,
                    s->x10[s->idx].b, s->xc[s->idx + 1], &lbl_8030CEA0.x18fc);
        fn_80213178((f32)lbl_8030CEA0.x1918, (f32)s->times[s->idx], s->x14[s->idx], s->x18[s->idx].a,
                    s->x18[s->idx].b, s->x14[s->idx + 1], tmp);
        fn_80213478(tmp, &lbl_8030CEA0.x18fc, &lbl_8030CEA0.x1908);
        {
            f32 lo = s->angles[s->idx];
            lbl_8030CEA0.x1910 = (s32)(182.04445f * (lo + ((f32)lbl_8030CEA0.x1918 / (f32)s->times[s->idx]) *
                                                           (s->angles[s->idx + 1] - lo)));
            lbl_8030CEA0.x1918++;
        }
    }
}

s16 fn_801F7D2C(u16 flags, Scpt* c)
{
    if (flags & 1) {
        f32* p = c->cur.f + 1;
        s8 kind;
        s8 b;
        u32 n;
        f32 f31;
        f32 f30;
        f32 f29;
        f32 f4;
        kind = ReadInt(&p);
        f29 = (f32)ReadInt(&p);
        f31 = fn_801F6120(&p);
        f30 = fn_801F6120(&p);
        n = ReadInt(&p);
        b = ReadInt(&p);
        if (n == 0x7FFFFFFF) {
            switch (kind) {
            case 0:
            case 1:
            case 2:
            case 3:
                f4 = 120.0f;
                break;
            default:
                f4 = 10.0f;
                break;
            }
        } else {
            f4 = (f32)n;
        }
        if (b == 0x7FFFFFFF) {
            b = 0;
        }
        c->cur.f = p;
        switch (kind) {
        case 0:
        case 1:
        case 2:
        case 3:
            fn_800B09C0(kind, b, 0.49f, f31, f30, f4, f29);
            break;
        case 4:
        case 5:
            fn_800AFCC0(4, b, 0.49f, 0.0f, f30, f4, 0.0f);
            break;
        }
    }
    return (flags >> 3) & 1;
}

s32 fn_801F7F98(u16 flags, Scpt* c)
{
    if (flags & 1) {
        f32* p = c->cur.f;
        Fx* fx;
        p++;
        fx = fn_801E1A2C(1, 0x44);
        c->work.fx = fx;
        fx->x18 = ReadInt(&p);
        fx->x1c = fn_801F6120(&p);
        fx->x20 = fn_801F6120(&p);
        fx->x24 = fn_801F6120(&p);
        fx->x28 = fn_801F6120(&p);
        fx->x2c = fn_801F6120(&p);
        fx->x30 = fn_801F6120(&p);
        fx->x34 = ReadInt(&p);
        c->cur.f = p;
        fx->ev.hd.kind = 0;
        fn_80211058(c, 6, fx->x18, 0x2e, lbl_8030CEA0.x08, &fx->ev);
    }
    if (flags & 2) {
        Fx* cur = c->work.fx;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a20, c->a24, c->a28, c->a2c);
            c->cnt++;
        } else if (cur->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_801F8D0C(u16 flags, Scpt* c)
{
    if (flags & 1) {
        f32* p = c->cur.f;
        Fx_801F8D0C* fx = fn_801E1A2C(1, 0x44);
        if (fx == 0) {
            fn_801DBE1C(lbl_802D491C);
        }
        c->work.fx_801F8D0C = fx;
        p++;
        fx->x18 = ReadInt(&p);
        fx->x1c = ReadInt(&p);
        fx->x20 = ReadInt(&p);
        fx->x24 = fn_801F6120(&p);
        fx->x28 = fn_801F6120(&p);
        fx->x2c = ReadInt(&p);
        if (fx->x28 == 3.4028235e38f) {
            fx->x28 = 0.0f;
        }
        if (fx->x2c == 0x7FFFFFFF) {
            fx->x2c = 0;
        }
        fx->ev.hd.kind = 0;
        fn_80211058(c, 6, fx->x18, 0x20, lbl_8030CEA0.x08, &fx->ev);
        c->cur.f = p;
    }
    if (flags & 2) {
        Fx_801F8D0C* cur = c->work.fx_801F8D0C;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a20, c->a24, c->a28, c->a2c);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C(lbl_802D4938);
            }
        } else if (cur->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_801F8F7C(u16 flags, Scpt* c)
{
    if (flags & 1) {
        f32* p = c->cur.f + 1;
        Fx_801F8F7C* fx = fn_801E1A2C(1, 0x44);
        if (fx == 0) {
            fn_801DBE1C(lbl_802D4958);
        }
        c->work.fx_801F8F7C = fx;
        fx->x18 = ReadInt(&p);
        fx->x1a = ReadInt(&p);
        c->cur.f = p;
        fx->ev.hd.kind = 0;
        fn_80211058(c, 6, fx->x1a, 0x1a, lbl_8030CEA0.x08, &fx->ev);
    }
    if (flags & 2) {
        Fx_801F8F7C* cur = c->work.fx_801F8F7C;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a20, c->a24, c->a28, c->a2c);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C(lbl_802D4978);
            }
        } else if (cur->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_801F9120(u16 flags, Scpt* c)
{
    if (flags & 1) {
        f32* p = c->cur.f + 1;
        Fx_801F9120* fx = fn_801E1A2C(1, 0x44);
        if (fx == 0) {
            fn_801DBE1C(lbl_802D49A0);
        }
        c->work.fx_801F9120 = fx;
        fx->x18 = ReadInt(&p);
        fx->x1c = ReadInt(&p);
        fx->x1a = ReadInt(&p);
        fx->x20 = fn_801F6120(&p);
        fx->x24 = fn_801F6120(&p);
        fx->x28 = fn_801F6120(&p);
        fx->x2c = fn_801F6120(&p);
        fx->x30 = fn_801F6120(&p);
        fx->x34 = fn_801F6120(&p);
        c->cur.f = p;
        fx->ev.hd.kind = 0;
        fn_80211058(c, 6, fx->x1a, 0x19, lbl_8030CEA0.x08, &fx->ev);
    }
    if (flags & 2) {
        Fx_801F9120* cur = c->work.fx_801F9120;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a20, c->a24, c->a28, c->a2c);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C(lbl_802D49BC);
            }
        } else if (cur->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_801FBBA8(u16 flags, Scpt* c)
{
    if (flags & 1) {
        f32* p = c->cur.f;
        Fx_801FBBA8* fx = fn_801E1A2C(1, 0x44);
        if (fx == 0) {
            fn_801DBE1C(lbl_802D4B54);
        }
        c->work.fx_801FBBA8 = fx;
        p++;
        fx->x18 = ReadInt(&p);
        fx->x1c = ReadInt(&p);
        fx->x20 = ReadInt(&p);
        fx->x24 = fn_801F6120(&p);
        fx->ev.hd.kind = 0;
        fn_80211058(c, 6, fx->x18, 0x12, lbl_8030CEA0.x08, &fx->ev);
        c->cur.f = p;
    }
    if (flags & 2) {
        Fx_801FBBA8* cur = c->work.fx_801FBBA8;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a20, c->a24, c->a28, c->a2c);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C(lbl_802D4B70);
            }
        } else if (cur->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_801FDAB8(u16 flags, Scpt* o) {
    if (flags & 1) {
        f32* p = o->cur.f + 1;
        ScrState* s = fn_801E1A2C(1, 0x44);
        if (s == 0) {
            fn_801DBE1C(lbl_802D4DC0);
        }
        o->work.scrState = s;
        s->mode = ReadInt(&p);
        s->count = ReadInt(&p);
        o->cur.f = p;
    }
    if (flags & 2) {
        ScrState* s = o->work.scrState;
        if (--s->count == 0) {
            return 0;
        }
        switch (s->mode) {
        case 0:
            if (lbl_80311A60.pad->flags & 0x100) {
                return 0;
            }
        case 1:
            if (lbl_80311A60.pad->flags & 0x1000) {
                return 0;
            }
        case 2:
            if (lbl_80311A60.pad->flags & 0x1f00) {
                return 0;
            }
        }
    }
    return !(flags & 8);
}

s16 fn_80200B90(u32 flags, Scpt *st) {
    s32 n;
    if (flags & 1) {
        float *p = st->cur.f + 1;
        f32 a, b, c, d, e, g;
        if (*p == 3.4028235e38f) {
            p++;
            n = 0x7FFFFFFF;
        } else {
            n = (s32)fn_801F6120(&p);
        }
        a = fn_801F6120(&p);
        b = fn_801F6120(&p);
        c = fn_801F6120(&p);
        d = fn_801F6120(&p);
        e = fn_801F6120(&p);
        g = fn_801F6120(&p);
        fn_801D9864(n, a, b, c, d, e, g);
        st->cur.f = p;
        lbl_8030CEA0.xc70 = 0;
        lbl_8030CEA0.xc88 = 0;
    }
    return 0;
}

s32 fn_80200DF4(u32 flags, Scpt *st) {
    if (flags & 1) {
        float *p = st->cur.f + 1;
        s32 n;
        f32 a, b, c, d, e, f, g, h;
        if (*p == 3.4028235e38f) {
            p++;
            n = 0x7FFFFFFF;
        } else {
            n = (s32)fn_801F6120(&p);
        }
        a = fn_801F6120(&p);
        b = fn_801F6120(&p);
        c = fn_801F6120(&p);
        d = fn_801F6120(&p);
        e = fn_801F6120(&p);
        f = fn_801F6120(&p);
        g = fn_801F6120(&p);
        h = fn_801F6120(&p);
        fn_801D9A0C(n, a, b, c, d, e, f, g, h);
        st->cur.f = p;
        lbl_8030CEA0.xc68 = 0;
        lbl_8030CEA0.xc84 = 0;
    }
    return 0;
}

s32 fn_8020184C(u32 flags, Scpt* s) {
    u16 f = flags;
    Work_8020184C* w;
    f32* cur;
    if (flags & 1) {
        cur = s->cur.f + 1;
        w = fn_801E1A2C(1, 0x44);
        if (w == NULL) fn_801DBE1C("HCLR: malloc failed");
        s->work.work_8020184C = w;
        w->ev.hd.kind = 0;
        w->n = ReadInt(&cur);
        w->x1c = (u16)ReadInt(&cur);
        s->cur.f = cur;
        fn_80211058(s, 6, w->n, 0x27, lbl_8030CEA0.x08, &w->ev);
    }
    if (f & 2) {
        w = s->work.work_8020184C;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("HCLR: message post timed out");
        } else if (w->ev.hd.kind == 2) {
            return 0;
        }
    }
    return !(f & 8);
}

s32 fn_802019F8(u32 flags, Scpt* s) {
    u16 f = flags;
    Work_802019F8* w;
    f32* cur;
    if (flags & 1) {
        cur = s->cur.f;
        cur = cur + 1;
        w = fn_801E1A2C(1, 0x44);
        if (w == NULL) fn_801DBE1C("scptHset: malloc failed");
        s->work.work_802019F8 = w;
        w->x18 = ReadInt(&cur);
        w->x20 = 0;
        w->x1c = 0;
        s->cur.f = cur;
        w->hd.kind = 0;
        fn_802110E8(s, 7, w->x18, 2, lbl_8030CEA0.x08, &w->hd);
    }
    if (f & 2) {
        w = s->work.work_802019F8;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("scptHset: message post time out");
        } else if (w->hd.kind == 2) {
            return 0;
        }
    }
    return !(f & 8);
}

s32 fn_80201B6C(u32 flags, Scpt* s) {
    u16 f = flags;
    Work_802019F8* w;
    f32* cur;
    if (flags & 1) {
        cur = s->cur.f;
        cur = cur + 1;
        w = fn_801E1A2C(1, 0x44);
        if (w == NULL) fn_801DBE1C("scptHSetTask: malloc failed");
        s->work.work_802019F8 = w;
        w->x18 = ReadInt(&cur);
        w->x20 = 0;
        w->x1c = 0;
        s->cur.f = cur;
        w->hd.kind = 0;
        fn_802110E8(s, 7, w->x18, 5, lbl_8030CEA0.x08, &w->hd);
    }
    if (f & 2) {
        w = s->work.work_802019F8;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("scptHtaskset: message post time out");
        } else if (w->hd.kind == 2) {
            return 0;
        }
    }
    return !(f & 8);
}

s32 fn_80201CE0(u32 flags, Scpt* s) {
    u16 f = flags;
    Work_802019F8* w;
    f32* cur;
    if (flags & 1) {
        cur = s->cur.f;
        cur = cur + 1;
        w = fn_801E1A2C(1, 0x44);
        if (w == NULL) fn_801DBE1C("scptHread: malloc failed");
        s->work.work_802019F8 = w;
        w->x18 = ReadInt(&cur);
        w->x20 = 0;
        w->x1c = 0;
        s->cur.f = cur;
        w->hd.kind = 0;
        fn_802110E8(s, 7, w->x18, 3, lbl_8030CEA0.x08, &w->hd);
    }
    if (f & 2) {
        w = s->work.work_802019F8;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("scptHread: message post time out");
        } else if (w->hd.kind == 2) {
            return 0;
        }
    }
    return !(f & 8);
}

s32 fn_80201E54(u32 flags, Scpt* s) {
    u16 f = flags;
    Work_802019F8* w;
    f32* cur;
    if (flags & 1) {
        cur = s->cur.f;
        cur = cur + 1;
        w = fn_801E1A2C(1, 0x44);
        if (w == NULL) fn_801DBE1C("scptHchange: malloc failed");
        s->work.work_802019F8 = w;
        w->x18 = ReadInt(&cur);
        w->x1c = ReadInt(&cur);
        w->x20 = 0;
        s->cur.f = cur;
        w->hd.kind = 0;
        fn_802110E8(s, 7, w->x18, 4, lbl_8030CEA0.x08, &w->hd);
    }
    if (f & 2) {
        w = s->work.work_802019F8;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("scptHchange: message post time out");
        } else if (w->hd.kind == 2) {
            return 0;
        }
    }
    return !(f & 8);
}

s32 fn_802021B8(u32 flags, Scpt* s)
{
    Work_80202004* w;
    f32* p;
    u16 f = flags;
    if (f & 1) {
        p = s->cur.f;
        p++;
        w = fn_801E1A2C(1, 0x44);
        if (w == NULL) fn_801DBE1C("scptHopen: malloc failed");
        s->work.work_80202004 = w;
        w->x18 = RDI(p);
        w->x1c = RDI(p);
        w->x20 = RDI(p);
        s->cur.f = p;
        if (w->x20 == 0x7FFFFFFF) w->x20 = 0;
        w->hd.kind = 0;
        fn_802110E8(s, 7, w->x18, 0, lbl_8030CEA0.x08, &w->hd);
    }
    if (f & 2) {
        w = s->work.work_80202004;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("scptHopen: message post time out");
        } else if (w->hd.kind == 2) {
            return 0;
        }
    }
    return !(f & 8);
}

s32 fn_80207CD0(u32 flags, Scpt* s)
{
    Work_80207CD0* w;
    f32* p;
    s32 id;
    s32 v;
    f32 f0, f1, f2;
    u16 f = flags;
    if (f & 1) {
        p = s->cur.f;
        p++;
        id = (u16)RDI(p);
        v = (u16)RDI(p);
        f0 = fn_801F6120(&p);
        f1 = fn_801F6120(&p);
        f2 = fn_801F6120(&p);
        s->cur.f = p;
        w = fn_801E1A2C(1, 0x44);
        if (w == NULL) fn_801DBE1C("NecM: malloc failed");
        s->work.work_80207CD0 = w;
        w->ev.hd.kind = 0;
        w->id = id;
        w->v = v;
        w->f0 = f0;
        w->f1 = f1;
        w->f2 = f2;
        fn_80211058(s, 6, id, 0x1b, lbl_8030CEA0.x08, &w->ev);
    }
    if (f & 2) {
        w = s->work.work_80207CD0;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("necM: message post timed out");
        } else if (w->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (f & 8) {
        return 1;
    }
    return 1;
}

s32 fn_80207ED0(u16 flags, Scpt* c)
{
    Rec* r;
    f32* p;
    if (flags & 1) {
        p = c->cur.f;
        p++;
        r = fn_801E1A2C(1, 0x44);
        if (r == 0) {
            fn_801DBE1C(lbl_802D5158);
        }
        c->work.rec = r;
        r->n = RDI(p);
        r->f1c = fn_801F6120(&p);
        c->cur.f = p;
        r->ev.hd.kind = 0;
        fn_80211058(c, 6, r->n, 8, lbl_8030CEA0.x08, &r->ev);
    }
    if (flags & 2) {
        Rec* w = c->work.rec;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a20, c->a24, c->a28, c->a2c);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C(lbl_802D5170);
            }
        } else if (w->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_80208044(u16 flags, Scpt* c)
{
    Rec* r;
    f32* p;
    if (flags & 1) {
        p = c->cur.f;
        p++;
        r = fn_801E1A2C(1, 0x44);
        if (r == 0) {
            fn_801DBE1C(lbl_802D5190);
        }
        c->work.rec = r;
        r->n = RDI(p);
        r->f1c = fn_801F6120(&p);
        r->f20 = fn_801F6120(&p);
        r->f24 = fn_801F6120(&p);
        r->f28 = fn_801F6120(&p);
        r->f2c = fn_801F6120(&p);
        r->f30 = fn_801F6120(&p);
        r->i34 = RDI(p);
        c->cur.f = p;
        r->ev.hd.kind = 0;
        fn_80211058(c, 6, r->n, 5, lbl_8030CEA0.x08, &r->ev);
    }
    if (flags & 2) {
        Rec* w = c->work.rec;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a20, c->a24, c->a28, c->a2c);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C(lbl_802D51A8);
            }
        } else if (w->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_80208234(u16 flags, Scpt* c)
{
    Rec* r;
    f32* p;
    if (flags & 1) {
        p = c->cur.f;
        p++;
        r = fn_801E1A2C(1, 0x44);
        if (r == 0) {
            fn_801DBE1C(lbl_802D51C8);
        }
        c->work.rec = r;
        r->n = RDI(p);
        r->f1c = fn_801F6120(&p);
        r->f20 = fn_801F6120(&p);
        r->f24 = fn_801F6120(&p);
        r->f28 = fn_801F6120(&p);
        r->f2c = fn_801F6120(&p);
        r->f30 = fn_801F6120(&p);
        r->i34 = RDI(p);
        c->cur.f = p;
        r->ev.hd.kind = 0;
        fn_80211058(c, 6, r->n, 4, lbl_8030CEA0.x08, &r->ev);
    }
    if (flags & 2) {
        Rec* w = c->work.rec;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a20, c->a24, c->a28, c->a2c);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C(lbl_802D51E0);
            }
        } else if (w->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_80208424(u16 flags, Scpt* c)
{
    Rec_80208424* r;
    f32* p;
    if (flags & 1) {
        p = c->cur.f;
        p++;
        r = fn_801E1A2C(1, 0x44);
        if (r == 0) {
            fn_801DBE1C(lbl_802D5200);
        }
        c->work.rec_80208424 = r;
        r->n = RDI(p);
        r->i1c = RDI(p);
        c->cur.f = p;
        r->ev.hd.kind = 0;
        fn_80211058(c, 6, r->n, 0x2d, lbl_8030CEA0.x08, &r->ev);
    }
    if (flags & 2) {
        Rec_80208424* w = c->work.rec_80208424;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a20, c->a24, c->a28, c->a2c);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C(lbl_802D5220);
            }
        } else if (w->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_802085CC(u16 flags, Scpt* c)
{
    Rec_80208424* r;
    f32* p;
    if (flags & 1) {
        p = c->cur.f;
        p++;
        r = fn_801E1A2C(1, 0x44);
        if (r == 0) {
            fn_801DBE1C(lbl_802D5248);
        }
        c->work.rec_80208424 = r;
        r->n = RDI(p);
        r->i1c = RDI(p);
        c->cur.f = p;
        r->ev.hd.kind = 0;
        fn_80211058(c, 6, r->n, 3, lbl_8030CEA0.x08, &r->ev);
    }
    if (flags & 2) {
        Rec_80208424* w = c->work.rec_80208424;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a20, c->a24, c->a28, c->a2c);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C(lbl_802D5260);
            }
        } else if (w->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_80208774(u16 flags, Scpt* c)
{
    Rec* r;
    f32* p;
    if (flags & 1) {
        p = c->cur.f;
        r = fn_801E1A2C(1, 0x44);
        if (r == 0) {
            fn_801DBE1C(lbl_802D5280);
        }
        c->work.rec = r;
        p++;
        r->n = RDI(p);
        r->ev.hd.kind = 0;
        fn_80211058(c, 6, r->n, 0x11, lbl_8030CEA0.x08, &r->ev);
        c->cur.f = p;
    }
    if (flags & 2) {
        Rec* w = c->work.rec;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a20, c->a24, c->a28, c->a2c);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C(lbl_802D52A0);
            }
        } else if (w->ev.hd.kind == 2) {
            return 0;
        }
    }
    return 1;
}

s32 fn_80208A20(u16 flags, Scpt* c)
{
    Rec_80208A20* r;
    f32* p;
    if (flags & 1) {
        p = c->cur.f;
        p++;
        r = fn_801E1A2C(1, 0x44);
        if (r == 0) {
            fn_801DBE1C(lbl_802D52E8);
        }
        c->work.rec_80208A20 = r;
        r->n = RDI(p);
        r->i1c = RDI(p);
        r->i20 = RDI(p);
        c->cur.f = p;
        r->ev.hd.kind = 0;
        fn_80211058(c, 6, r->n, 0xe, lbl_8030CEA0.x08, &r->ev);
    }
    if (flags & 2) {
        Rec_80208A20* w = c->work.rec_80208A20;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a20, c->a24, c->a28, c->a2c);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C(lbl_802D5308);
            }
        } else if (w->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_80208C08(u16 flags, Scpt* c)
{
    Rec_80208424* r;
    f32* p;
    if (flags & 1) {
        u16 n;
        s32 v;
        p = c->cur.f + 1;
        n = RDI(p);
        v = RDI(p);
        r = fn_801E1A2C(1, 0x44);
        if (r == 0) {
            fn_801DBE1C(lbl_802D532C);
        }
        c->work.rec_80208424 = r;
        r->ev.hd.kind = 0;
        r->n = n;
        r->i1c = v;
        fn_80211058(c, 6, r->n, 0x10, lbl_8030CEA0.x08, &r->ev);
        c->cur.f = p;
    }
    if (flags & 2) {
        Rec_80208424* w = c->work.rec_80208424;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a20, c->a24, c->a28, c->a2c);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C(lbl_802D5348);
            }
        } else if (w->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_80208D9C(u16 flags, Scpt* c)
{
    Rec_80208424* r;
    f32* p;
    if (flags & 1) {
        u16 n;
        s32 v;
        p = c->cur.f + 1;
        n = RDI(p);
        v = RDI(p);
        r = fn_801E1A2C(1, 0x44);
        if (r == 0) {
            fn_801DBE1C(lbl_802D536C);
        }
        c->work.rec_80208424 = r;
        r->ev.hd.kind = 0;
        r->n = n;
        r->i1c = v;
        fn_80211058(c, 6, r->n, 0x1c, lbl_8030CEA0.x08, &r->ev);
        c->cur.f = p;
    }
    if (flags & 2) {
        Rec_80208424* w = c->work.rec_80208424;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a20, c->a24, c->a28, c->a2c);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C(lbl_802D5384);
            }
        } else if (w->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_802097C0(u16 flags, Scpt* c)
{
    Rec_80208A20* r;
    f32* p;
    if (flags & 1) {
        p = c->cur.f;
        r = fn_801E1A2C(1, 0x44);
        if (r == 0) {
            fn_801DBE1C(lbl_802D544C);
        }
        c->work.rec_80208A20 = r;
        p++;
        r->n = RDI(p);
        r->i1c = RDI(p);
        r->f24 = fn_801F6120(&p);
        r->ev.hd.kind = 0;
        fn_80211058(c, 6, r->n, 0x2a, lbl_8030CEA0.x08, &r->ev);
        c->cur.f = p;
    }
    if (flags & 2) {
        Rec_80208A20* w = c->work.rec_80208A20;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a20, c->a24, c->a28, c->a2c);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C(lbl_802D5468);
            }
        } else if (w->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_80209974(u16 flags, Scpt* c)
{
    Rec_80209974* r;
    f32* p;
    if (flags & 1) {
        p = c->cur.f + 1;
        r = fn_801E1A2C(1, 0x44);
        if (r == 0) {
            fn_801DBE1C(lbl_802D548C);
        }
        c->work.rec_80209974 = r;
        r->n = RDI(p);
        r->n2 = RDI(p);
        r->f1c = fn_801F6120(&p);
        r->f20 = fn_801F6120(&p);
        r->f24 = fn_801F6120(&p);
        r->i28 = RDI(p);
        c->cur.f = p;
        if (r->i28 == 0x7FFFFFFF) {
            r->i28 = 1;
        }
        r->ev.hd.kind = 0;
        fn_80211058(c, 6, r->n, 0x29, lbl_8030CEA0.x08, &r->ev);
    }
    if (flags & 2) {
        Rec_80209974* w = c->work.rec_80209974;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a20, c->a24, c->a28, c->a2c);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C(lbl_802D54A8);
            }
        } else if (w->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_80209D74(u16 flags, Scpt* c)
{
    Rec_80209974* r;
    f32* p;
    if (flags & 1) {
        p = c->cur.f + 1;
        r = fn_801E1A2C(1, 0x44);
        if (r == 0) {
            fn_801DBE1C(lbl_802D5504);
        }
        c->work.rec_80209974 = r;
        r->n = RDI(p);
        c->cur.f = p;
        r->ev.hd.kind = 0;
        fn_80211058(c, 6, r->n, 0x2c, lbl_8030CEA0.x08, &r->ev);
    }
    if (flags & 2) {
        Rec_80209974* w = c->work.rec_80209974;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a20, c->a24, c->a28, c->a2c);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C(lbl_802D5520);
            }
        } else if (w->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_80209ED8(u16 flags, Scpt* c)
{
    Rec_80209974* r;
    f32* p;
    if (flags & 1) {
        p = c->cur.f + 1;
        r = fn_801E1A2C(1, 0x44);
        if (r == 0) {
            fn_801DBE1C(lbl_802D54CC);
        }
        c->work.rec_80209974 = r;
        r->n = RDI(p);
        r->f1c = fn_801F6120(&p);
        c->cur.f = p;
        r->ev.hd.kind = 0;
        fn_80211058(c, 6, r->n, 0x2b, lbl_8030CEA0.x08, &r->ev);
    }
    if (flags & 2) {
        Rec_80209974* w = c->work.rec_80209974;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a20, c->a24, c->a28, c->a2c);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C(lbl_802D5544);
            }
        } else if (w->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_8020A938(u32 flags, Scpt* s)
{
    Work_8020A938* w;
    s32* cur;
    u16 f = flags;
    if (f & 1) {
        cur = s->cur.i + 1;
        {
            u8* end = (u8*)cur;
            end += *cur;
            s->cur.i = cur + 1;
            lbl_8030CEA0.x15c8 = 1;
            w = fn_801E1A2C(1, 0xc);
            if (w == NULL) fn_801DBE1C("scptPRINT: malloc failed 1");
            s->work.work_8020A938 = w;
            w->hd.kind = 0;
            w->x08 = end;
        }
        fn_802110E8(s, 5, 0, 0, lbl_8030CEA0.x08, &w->hd);
    }
    if (f & 2) {
        w = s->work.work_8020A938;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("scptPRINT: message post timed out");
        } else if (w->hd.kind == 2) {
            lbl_8030CEA0.x15c8 = 0;
            return 0;
        }
    }
    if (f & 8) {
        lbl_8030CEA0.x15c8 = 0;
        return 0;
    }
    return 1;
}

s32 fn_8020AE04(u32 flags, Scpt* s)
{
    Work_8020A938* w;
    s32* cur;
    u16 f = flags;
    if (f & 1) {
        void* msg;
        cur = s->cur.i;
        s->cur.i = cur + 1;
        msg = fn_8020AF8C(100);
        lbl_8030CEA0.x15c8 = 1;
        w = fn_801E1A2C(1, 0xc);
        if (w == NULL) fn_801DBE1C("scptPRINT: malloc failed 1");
        s->work.work_8020A938 = w;
        w->hd.kind = 0;
        w->x08 = msg;
        fn_802110E8(s, 5, 0, 0, lbl_8030CEA0.x08, &w->hd);
    }
    if (f & 2) {
        w = s->work.work_8020A938;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("scptSENNIN: message post timed out");
        } else if (w->hd.kind == 2) {
            lbl_8030CEA0.x15c8 = 0;
            if (w->x08 != NULL) {
                fn_801E1784(w->x08);
                w->x08 = NULL;
            }
            return 0;
        }
    }
    if (f & 8) {
        lbl_8030CEA0.x15c8 = 0;
        return 0;
    }
    return 1;
}

s32 fn_8020B4AC(u32 flags, Scpt* s)
{
    Work_8020A938* w;
    f32* cur;
    u16 f = flags;
    if (f & 1) {
        void* msg;
        s32 v;
        cur = s->cur.f + 1;
        if (*cur == 3.4028235e38f) {
            cur++;
            v = 0x7FFFFFFF;
        } else {
            v = (s32)fn_801F6120(&cur);
        }
        s->cur.f = cur;
        msg = fn_8020AF8C(v);
        lbl_8030CEA0.x15c8 = 1;
        w = fn_801E1A2C(1, 0xc);
        if (w == NULL) fn_801DBE1C("scptPRINT: malloc failed 1");
        s->work.work_8020A938 = w;
        w->hd.kind = 0;
        w->x08 = msg;
        fn_802110E8(s, 5, 0, 0, lbl_8030CEA0.x08, &w->hd);
    }
    if (f & 2) {
        w = s->work.work_8020A938;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("scptSENNIN: message post timed out");
        } else if (w->hd.kind == 2) {
            lbl_8030CEA0.x15c8 = 0;
            if (w->x08 != NULL) {
                fn_801E1784(w->x08);
                w->x08 = NULL;
            }
            return 0;
        }
    }
    if (f & 8) {
        lbl_8030CEA0.x15c8 = 0;
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

s16 fn_802056A8(u32 a0, Scpt *st) {
    s32 n;
    u16 a = a0;
    s8 r;
    if (a0 & 1) {
        u8 *p = st->cur.b;
        fn_801F7500();
        p += 4;
        if (3.4028235e38f == *(f32 *)p) {
            p += 4;
            n = 0x7fffffff;
        } else {
            n = (s32)fn_801F6120((f32**)&p);
        }
        st->cur.b = p;
        r = fn_8009763C();
        fn_800972AC();
        if (n == 0) {
            fn_80097318(1);
        } else {
            fn_80097318(0);
        }
        if (r == 2) {
            st->a20 = 2;
            st->flags = 0;
            return 1;
        }
    }
    if (a & 2) {
        if (--st->a20 == 0) {
            lbl_80310B3C[34] &= ~2;
            st->a20 = 0;
            return 0;
        }
        return 1;
    }
    return (a >> 3) & 1;
}

s32 fn_801F5C30(s32 unused, Scpt *st)
{
    u32 *p = st->cur.u;

    if (lbl_8030CEA0.sp >= 0x20) {
        fn_801DBE1C(lbl_802D4740);
    }
    lbl_8030CEA0.stack[++lbl_8030CEA0.sp] = p + 2;
    p++;
    p += *p / 4;
    st->cur.u = p;
    return 0;
}

s32 fn_801FF05C(u32 flags, Scpt *st) {
    u16 f = flags;
    if (flags & 1) {
        u8 *c = st->cur.b;
        u8 *q = c + 4;
        u32 w = *(u32 *)(c + 4);
        u8 *e = q + w;
        st->cur.b = q + 4;
        st->flags = 0;
        st->work.b = e;
    }
    if (f & 2) {
        if (fn_8010038C(st->work.b) == 1) {
            st->work.b = 0;
            return 0;
        }
    }
    if (f & 8) return 0;
    return 1;
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

s32 fn_801FFFA4(u32 flags, Scpt *st) {
    if (flags & 1) {
        float *p = st->cur.f + 1;
        s32 i = RDI(p);
        s32 a = RDI(p);
        f32 b = fn_801F6120(&p);
        st->cur.f = p;
        lbl_8030CEA0.x14b8[i] = a;
        lbl_8030CEA0.x14cb[i] = b;
    }
    return 0;
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

s16 fn_801FA1D0(u32 flags, Scpt *s)
{
    u16 f = (u16)flags;
    if (flags & 1) {
        u8 *p4 = s->cur.b + 4;
        char *name = (char *)p4 + *(u32 *)p4;
        u8 *buf;
        s->cur.b = p4 + 4;
        buf = fn_801E1A2C(1, strlen(lbl_80346848) + strlen(name) + 5);
        strcpy(buf, lbl_80346848);
        strcat(buf, name);
        strcat(buf, &lbl_8034C198);
        fn_80219378(buf);
        if (buf != 0) {
            fn_801E1784(buf);
        }
    }
    return (s16)((f >> 3) & 1);
}

static inline void FlagClear(u32 b) {
    lbl_80310B3C[b >> 5] &= ~(1 << (b & 31));
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

s16 fn_801F7C18(u32 flags, Scpt *s)
{
    u16 f = (u16)flags;
    if (flags & 1) {
        u8 *p4 = s->cur.b + 4;
        char *name = (char *)p4 + *(u32 *)p4;
        char *buf;
        s->cur.b = p4 + 4;
        buf = fn_801E1A2C(1, strlen(lbl_80346848) + strlen(name) + 5);
        strcpy(buf, lbl_80346848);
        strcat(buf, name);
        strcat(buf, &lbl_8034C198);
        fn_80216CB4(buf);
        if (buf != 0) {
            fn_801E1784(buf);
        }
    }
    return (s16)((f >> 3) & 1);
}

s32 fn_801FF210(u16 flags, Scpt *st) {
    if (flags & 1) {
        float *p = st->cur.f + 1;
        int a, b, c, d;
        a = RDI(p);
        b = RDI(p);
        c = RDI(p);
        d = RDI(p);
        st->cur.f = p;
        fn_800C1A34(a, b, c, d);
        st->flags = 0;
    }
    return 0;
}

static inline s32 rdi(float **pp) {
    if (3.4028235e38f == **pp) {
        (*pp)++;
        return 0x7FFFFFFF;
    }
    return (s32)fn_801F6120(pp);
}

s32 fn_802009C4(u32 flags, Scpt *st) {
    if (flags & 1) {
        float *p = st->cur.f + 1;
        int n, m;
        f32 a, b, c, d, e, f, g, h;
        n = rdi(&p);
        m = rdi(&p);
        a = fn_801F6120(&p);
        b = fn_801F6120(&p);
        c = fn_801F6120(&p);
        d = fn_801F6120(&p);
        e = fn_801F6120(&p);
        f = fn_801F6120(&p);
        g = fn_801F6120(&p);
        h = fn_801F6120(&p);
        fn_801D9728(n, m, a, b, c, d, e, f, g, h);
        st->cur.f = p;
    }
    return 0;
}

s32 fn_80209B94(u16 flags, Scpt* c)
{
    Rec_80209974* r;
    f32* p;
    if (flags & 1) {
        p = c->cur.f + 1;
        r = fn_801E1A2C(1, 0x44);
        if (r == 0) {
            fn_801DBE1C(lbl_802D54CC);
        }
        c->work.rec_80209974 = r;
        r->n = RDI(p);
        r->f1c = fn_801F6120(&p);
        r->f20 = fn_801F6120(&p);
        r->f24 = fn_801F6120(&p);
        r->i28 = RDI(p);
        c->cur.f = p;
        if (r->i28 == 0x7FFFFFFF) {
            r->i28 = 1;
        }
        r->ev.hd.kind = 0;
        fn_80211058(c, 6, r->n, 0x23, lbl_8030CEA0.x08, &r->ev);
    }
    if (flags & 2) {
        Rec_80209974* w = c->work.rec_80209974;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a20, c->a24, c->a28, c->a2c);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C(lbl_802D54A8);
            }
        } else if (w->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

void fn_8020DA2C(s32 idx, f32 x, f32 y)
{
    Actor* a;
    TextHead* t;
    f32 z;
    f32 x2;
    a = fn_8015F1A0(0x752f);
    if (a != NULL) {
        lbl_80314698.x = -1.5f;
        lbl_80314698.u = (s32)x;
        lbl_80314698.v = 0x48;
        lbl_80314698.a = 1.0f;
        lbl_80314698.b = 1.0f;
        z = fn_800C2D18(&lbl_80314698);
        t = TextPrint((s32)(330.0f + x), 0x58, lbl_802ED258[idx].name);
        t->z = z;
        t->r = 0xff;
        t->g = 0x20;
        t->b = 0x10;
        t->a = 8;
        t = TextPrint((s32)(295.0f + x), 0x79, lbl_802EE040[idx].desc);
        t->z = z;
        t->r = 0xff;
        t->g = 0x20;
        t->b = 0x10;
        t->a = 8;
        x2 = 20.0f + x;
        fn_800DDE98((s32)x2, 0x64, (s32)(256.0f + x2), 0x164, a->x100, y, z, 0);
    }
}

s32 fn_801F9EA8(u16 flags, Scpt* c)
{
    if (flags & 1) {
        f32* p = c->cur.f + 1;
        s32 e;
        int a;
        s8 b;
        s8 d;
        f32 x;
        f32 y;
        f32 z;
        a = ReadInt(&p);
        b = ReadInt(&p);
        d = ReadInt(&p);
        e = ReadInt(&p);
        x = fn_801F6120(&p);
        y = fn_801F6120(&p);
        z = fn_801F6120(&p);
        c->cur.f = p;
        fn_801694FC(a, b, d, e, x, y, z);
    }
    if (flags & 8) {
        return 1;
    }
    return 0;
}

s32 fn_801FCFF0(u16 flags, Scpt* o) {
    if (flags & 1) {
        f32* p;
        s32 who, chr;
        u32 bit;
        p = o->cur.f + 1;
        who = ReadInt(&p);
        chr = ReadInt(&p);
        bit = ReadInt(&p);
        o->cur.f = p;
        if (who == 6) {
            s32 i;
            lbl_80310B3C[bit >> 5] &= ~(1 << (bit & 31));
            for (i = 0; i < 4; i++) {
                if (fn_801F3F88(&lbl_8030B7F4.chr[lbl_8030B7F4.party[i]], chr)) {
                    lbl_80310B3C[bit >> 5] |= 1 << (bit & 31);
                }
            }
        } else if (fn_801F3F88(&lbl_8030B7F4.chr[who], chr)) {
            lbl_80310B3C[bit >> 5] |= 1 << (bit & 31);
        } else {
            lbl_80310B3C[bit >> 5] &= ~(1 << (bit & 31));
        }
    }
    return 0;
}

s32 fn_801FE06C(u16 flags, Scpt* o) {
    if (flags & 1) {
        f32* p = o->cur.f + 1;
        void* q;
        u16 id;
        Info_801FE06C* n;
        f32 f;
        id = ReadInt(&p);
        o->cur.f = p;
        q = fn_8015F1A0(id);
        if (q == 0) {
            return 0;
        }
        n = fn_8015F180(q);
        f = n->x38;
        lbl_8030CEA0.x1584[8] = *(s32*)&f;
        f = n->x3c;
        lbl_8030CEA0.x1584[9] = *(s32*)&f;
        f = n->x40;
        lbl_8030CEA0.x1584[10] = *(s32*)&f;
        f = 0.005493164f * (f32)(n->x44 & 0xffff);
        lbl_8030CEA0.x1584[11] = *(s32*)&f;
        f = 0.005493164f * (f32)(n->x48 & 0xffff);
        lbl_8030CEA0.x1584[12] = *(s32*)&f;
        f = 0.005493164f * (f32)(n->x4c & 0xffff);
        lbl_8030CEA0.x1584[13] = *(s32*)&f;
        f = n->x50;
        lbl_8030CEA0.x1584[14] = *(s32*)&f;
        f = n->x54;
        lbl_8030CEA0.x1584[15] = *(s32*)&f;
        f = n->x58;
        lbl_8030CEA0.x1584[16] = *(s32*)&f;
    }
    if (flags & 8) {
        return 1;
    }
    return 0;
}
s32 fn_801FF470(u16 flags, Scpt* o) {
    if (flags & 1) {
        f32* p = o->cur.f;
        Obj10A* t;
        u16 id;
        p++;
        id = ReadInt(&p);
        o->cur.f = p;
        t = fn_8010A164(id);
        if (t != 0) {
            s32 n;
            s32 size;
            Actor* e;
            s32 i;
            u32* copy;
            s32 j;
            e = t->x24;
            n = e->x1c8->x10[0];
            size = n * 4;
            copy = fn_801E1A2C(1, size);
            memcpy(copy, e->x1c8->x10 + 1, size);
            for (i = 1; i < n - 1; i += 2) {
                for (j = i + 2; j < n - 1; j += 2) {
                    if (copy[i] == copy[j]) {
                        copy[j] = 0;
                    }
                }
            }
            for (i = 1; i < n - 1; i += 2) {
                u16 id = copy[i];
                if (id != 0) {
                    Actor* q = fn_8015F1A0(id);
                    if (q != 0 && q->b26c == 1) {
                        fn_8020F934(id);
                    }
                }
            }
            if (copy != 0) {
                fn_801E1784(copy);
            }
        }
    }
    return 0;
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

s16 fn_801FA060(u16 flags, Scpt* c)
{
    if (flags & 1) {
        f32* p = c->cur.f + 1;
        s32 vol;
        s8 b;
        s8 d;
        u32 r;
        vol = ReadInt(&p);
        b = ReadInt(&p);
        d = ReadInt(&p);
        if (3.4028235e38f == *p) {
            p++;
        } else {
            fn_801F6120(&p);
        }
        c->cur.f = p;
        vol = 16 - vol;
        if (vol >= 16) {
            vol = 0;
        } else if (vol < 1) {
            vol = 1;
        }
        r = SePlay(vol, b, d);
        if (r != 0) {
            lbl_8030CEA0.x157c = r;
        }
    }
    return (flags >> 3) & 1;
}

s16 fn_801F9708(u32 a0, Scpt *st) {
    u16 a = a0;
    if (a0 & 1) {
        float *p = st->cur.f + 1;
        int i;
        s8 j;
        s8 k;
        u32 r;
        i = RDI(p);
        j = RDI(p);
        k = RDI(p);
        st->cur.f = p;
        r = fn_80217FD4(i, j, k);
        if (r != 0) lbl_8030CEA0.x157c = r;
    }
    return (a >> 3) & 1;
}

void fn_800B0F0C(void);
void fn_80212084(void);

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

s32 fn_801FE310(u16 flags, Scpt* o) {
    if (flags & 1) {
        f32* p;
        s32 r, g, b;
        u32 n;
        p = o->cur.f + 1;
        r = ReadInt(&p);
        g = ReadInt(&p);
        b = ReadInt(&p);
        lbl_8030CEA0.xc64 = fn_801F6120(&p);
        n = ReadInt(&p);
        o->cur.f = p;
        if (n == 0) {
            n = 1;
        }
        if (n == 0x7fffffff) {
            n = 30;
        }
        lbl_8030CEA0.xc54 = 0;
        lbl_8030CEA0.xc50 = n;
        lbl_8030CEA0.xc60.b[0] = 0;
        lbl_8030CEA0.xc60.b[1] = r;
        lbl_8030CEA0.xc60.b[2] = g;
        lbl_8030CEA0.xc60.b[3] = b;
    }
    if (flags & 2) {
        s32 cur;
        f32 v;
        lbl_8030CEA0.xc5c = 1;
        lbl_8030CEA0.xc54++;
        cur = lbl_8030CEA0.xc54;
        v = 255.0f * ((f32)cur / (f32)lbl_8030CEA0.xc50);
        lbl_8030CEA0.xc58 = v;
        if (v > 255.0f) {
            lbl_8030CEA0.xc60.b[0] = 0xff;
            return 0;
        }
        lbl_8030CEA0.xc60.b[0] = (u8)v;
        if (lbl_8030CEA0.xc50 == cur) {
            return 0;
        }
    }
    if (flags & 8) {
        lbl_8030CEA0.xc5c = 0;
        return 1;
    }
    return 1;
}

s32 fn_801FE560(u16 flags, Scpt* o) {
    if (flags & 1) {
        f32* p;
        s32 r, g, b;
        u32 n;
        p = o->cur.f + 1;
        r = ReadInt(&p);
        g = ReadInt(&p);
        b = ReadInt(&p);
        lbl_8030CEA0.xc64 = fn_801F6120(&p);
        n = ReadInt(&p);
        o->cur.f = p;
        if (n == 0) {
            n = 1;
        }
        if (n == 0x7fffffff) {
            n = 30;
        }
        lbl_8030CEA0.xc50 = lbl_8030CEA0.xc54 = n;
        lbl_8030CEA0.xc60.b[0] = 0xff;
        lbl_8030CEA0.xc60.b[1] = r;
        lbl_8030CEA0.xc60.b[2] = g;
        lbl_8030CEA0.xc60.b[3] = b;
    }
    if (flags & 2) {
        s32 cur;
        f32 v;
        lbl_8030CEA0.xc5c = 1;
        lbl_8030CEA0.xc54--;
        cur = lbl_8030CEA0.xc54;
        v = 255.0f * ((f32)cur / (f32)lbl_8030CEA0.xc50);
        lbl_8030CEA0.xc58 = v;
        if (v < 0.0f) {
            lbl_8030CEA0.xc60.b[0] = 0;
            lbl_8030CEA0.xc5c = 0;
            return 0;
        }
        lbl_8030CEA0.xc60.b[0] = (u8)v;
        if (cur == 0) {
            lbl_8030CEA0.xc5c = 0;
            return 0;
        }
    }
    return 1;
}

s32 fn_801FE960(u16 flags, Scpt* o) {
    if (flags & 1) {
        f32* p;
        u32 n;
        p = o->cur.f + 1;
        n = ReadInt(&p);
        o->cur.f = p;
        lbl_8030CEA0.xc60.w = 0xffc0c0c0;
        if (n == 0) {
            n = 1;
        }
        if (n == 0x7fffffff) {
            n = 30;
        }
        lbl_8030CEA0.xc50 = lbl_8030CEA0.xc54 = n;
        lbl_8030CEA0.xc64 = -1.0f;
    }
    if (flags & 2) {
        s32 cur;
        f32 v;
        lbl_8030CEA0.xc5c = 1;
        lbl_8030CEA0.xc54--;
        cur = lbl_8030CEA0.xc54;
        v = 255.0f * ((f32)cur / (f32)lbl_8030CEA0.xc50);
        lbl_8030CEA0.xc58 = v;
        if (v < 0.0f) {
            lbl_8030CEA0.xc60.b[0] = 0;
            lbl_8030CEA0.xc5c = 0;
            return 0;
        }
        lbl_8030CEA0.xc60.b[0] = (u8)v;
        if (cur == 0) {
            lbl_8030CEA0.xc5c = 0;
            return 0;
        }
    }
    if (flags & 8) {
        lbl_8030CEA0.xc5c = 0;
        return 1;
    }
    return 1;
}

s32 fn_801FE7A0(u16 flags, Scpt* o) {
    if (flags & 1) {
        f32* p;
        u32 n;
        p = o->cur.f + 1;
        n = ReadInt(&p);
        o->cur.f = p;
        if (FlagTest(0x31) == 1) {
            return 0;
        }
        lbl_8030CEA0.xc60.w = 0xc0c0c0;
        lbl_8030CEA0.xc58 = 0.0f;
        if (n == 0) {
            n = 1;
        }
        if (n == 0x7fffffff) {
            n = 30;
        }
        lbl_8030CEA0.xc50 = n;
        lbl_8030CEA0.xc54 = 0;
        lbl_8030CEA0.xc64 = -1.0f;
    }
    if (flags & 2) {
        s32 cur;
        f32 v;
        lbl_8030CEA0.xc5c = 1;
        lbl_8030CEA0.xc54++;
        cur = lbl_8030CEA0.xc54;
        v = 255.0f * ((f32)cur / (f32)lbl_8030CEA0.xc50);
        lbl_8030CEA0.xc58 = v;
        if (v > 255.0f) {
            lbl_8030CEA0.xc60.b[0] = 0xff;
            return 0;
        }
        lbl_8030CEA0.xc60.b[0] = (u8)v;
        if (lbl_8030CEA0.xc50 == cur) {
            return 0;
        }
    }
    if (flags & 8) {
        lbl_8030CEA0.xc5c = 0;
        return 1;
    }
    return 1;
}

extern char lbl_802D4B94[];
extern char lbl_802D4BB4[];
s32 fn_801FBD9C(u16 flags, Scpt* o) {
    if (flags & 1) {
        f32* p = o->cur.f;
        Work801F8* s = fn_801E1A2C(1, 0x44);
        if (s == 0) {
            fn_801DBE1C(lbl_802D4B94);
        }
        o->work.work801F8 = s;
        p++;
        s->n = ReadInt(&p);
        s->x1c = ReadInt(&p);
        s->x20 = ReadInt(&p);
        s->x24 = fn_801F6120(&p);
        s->ev.hd.kind = 0;
        fn_80211058(o, 6, s->n, 0x14, lbl_8030CEA0.x08, &s->ev);
        o->cur.f = p;
    }
    if (flags & 2) {
        Work801F8* st = o->work.work801F8;
        if (o->handle == 0) {
            o->handle = fn_800CD0B8(o->a20, o->a24, o->a28, o->a2c);
            o->cnt++;
            if (o->cnt == 5) {
                fn_801DBE1C(lbl_802D4BB4);
            }
        } else if (st->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

extern char lbl_802D4BDC[];
extern char lbl_802D4BF8[];
s32 fn_801FBF90(u16 flags, Scpt* o) {
    if (flags & 1) {
        f32* p = o->cur.f;
        Work801F8* s = fn_801E1A2C(1, 0x44);
        if (s == 0) {
            fn_801DBE1C(lbl_802D4BDC);
        }
        o->work.work801F8 = s;
        p++;
        s->n = ReadInt(&p);
        s->x1c = ReadInt(&p);
        s->x20 = ReadInt(&p);
        s->x24 = fn_801F6120(&p);
        s->ev.hd.kind = 0;
        fn_80211058(o, 6, s->n, 0x13, lbl_8030CEA0.x08, &s->ev);
        o->cur.f = p;
    }
    if (flags & 2) {
        Work801F8* st = o->work.work801F8;
        if (o->handle == 0) {
            o->handle = fn_800CD0B8(o->a20, o->a24, o->a28, o->a2c);
            o->cnt++;
            if (o->cnt == 5) {
                fn_801DBE1C(lbl_802D4BF8);
            }
        } else if (st->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

/* The camera path defaults: node 0 of path n (position, two values, look-at) is at init[n]. */
typedef struct {
    f32 a[3];
    f32 c[2];
    f32 b[3];
    u8 pad20[8];
} PathInit;
typedef struct {
    u8 pad000[0x148];
    PathInit init[4];
} PathInitTbl;
extern PathInitTbl lbl_8030E830;

s16 fn_802001F8(u32 flags, Scpt *st) {
    s32 n;
    u16 f = flags;
    s32 i;
    s32 cnt;
    s32 sum;
    if (flags & 1) {
        float *p = st->cur.f + 1;
        cnt = *(s32 *)p++ + 1;
        n = (*p == 3.4028235e38f) ? (p++, 0x7FFFFFFF) : (s32)fn_801F6120(&p);
        lbl_8030CEA0.xca0[n] = 0;
        lbl_8030CEA0.xc8a[n] = cnt;
        lbl_8030CEA0.path[n][0].b[0] = lbl_8030E830.init[n].b[0];
        lbl_8030CEA0.path[n][0].b[1] = lbl_8030E830.init[n].b[1];
        lbl_8030CEA0.path[n][0].b[2] = lbl_8030E830.init[n].b[2];
        lbl_8030CEA0.path[n][0].c[0] = lbl_8030E830.init[n].c[0];
        lbl_8030CEA0.path[n][0].c[1] = lbl_8030E830.init[n].c[1];
        lbl_8030CEA0.path[n][0].a[0] = lbl_8030E830.init[n].a[0];
        lbl_8030CEA0.path[n][0].a[1] = lbl_8030E830.init[n].a[1];
        lbl_8030CEA0.path[n][0].a[2] = lbl_8030E830.init[n].a[2];
        sum = 0;
        for (i = 0; i < cnt - 1; i++) {
            lbl_8030CEA0.path[n][i + 1].a[0] = fn_801F6120(&p);
            lbl_8030CEA0.path[n][i + 1].a[1] = fn_801F6120(&p);
            lbl_8030CEA0.path[n][i + 1].a[2] = fn_801F6120(&p);
            lbl_8030CEA0.path[n][i + 1].c[0] = fn_801F6120(&p);
            lbl_8030CEA0.path[n][i + 1].c[1] = fn_801F6120(&p);
            lbl_8030CEA0.path[n][i + 1].b[0] = fn_801F6120(&p);
            lbl_8030CEA0.path[n][i + 1].b[1] = fn_801F6120(&p);
            lbl_8030CEA0.path[n][i + 1].b[2] = fn_801F6120(&p);
            lbl_8030CEA0.path[n][i].w = (*p == 3.4028235e38f) ? (p++, 0x7FFFFFFF) : (s32)fn_801F6120(&p);
            sum += lbl_8030CEA0.path[n][i].w;
        }
        lbl_8030CEA0.path[n][cnt - 1].w = lbl_8030CEA0.path[n][0].w;
        sum += lbl_8030CEA0.path[n][0].w;
        lbl_8030CEA0.xcbc[n] = sum;
        st->cur.f = p;
        if (lbl_8030CEA0.path[n][0].w == 0) {
            lbl_8030CEA0.xc74[n] = 0;
            lbl_8030CEA0.xc8a[n] = 0;
            fn_801D9728(n, 1, lbl_8030CEA0.path[n][1].a[0], lbl_8030CEA0.path[n][1].a[1], lbl_8030CEA0.path[n][1].a[2], lbl_8030CEA0.path[n][1].c[0], lbl_8030CEA0.path[n][1].c[1], lbl_8030CEA0.path[n][1].b[0], lbl_8030CEA0.path[n][1].b[1], lbl_8030CEA0.path[n][1].b[2]);
        } else {
            lbl_8030CEA0.xc74[n] = 1;
        }
    }
    return (f >> 3) & 1;
}

static inline s32 FlagCount(u32 base, s32 cnt)
{
    s32 i;
    s32 n = 0;
    for (i = 0; i < cnt; i++) {
        if (FlagTest(base + i) == 1) n++;
    }
    return n;
}

void fn_8020ED58(void)
{
    s32 n;
    f32 pct;
    lbl_8030CEA0.tbl[9] = lbl_8030B7F4.x344;
    lbl_8030CEA0.tbl[10] = lbl_8030B7F4.x350;
    lbl_8030CEA0.tbl[11] = lbl_8030B7F4.x346;
    lbl_8030CEA0.tbl[12] = lbl_8030B7F4.chr[0].xc;
    lbl_8030CEA0.tbl[13] = lbl_8030B7F4.chr[1].xc;
    lbl_8030CEA0.tbl[14] = lbl_8030B7F4.chr[2].xc;
    lbl_8030CEA0.tbl[15] = lbl_8030B7F4.chr[3].xc;
    lbl_8030CEA0.tbl[16] = lbl_8030B7F4.chr[4].xc;
    lbl_8030CEA0.tbl[17] = lbl_8030B7F4.chr[5].xc;
    n = FlagCount(0x800, 0x77);
    pct = 100.0f * ((f32)n / 119.0f);
    lbl_8030CEA0.tbl[18] = (s32)pct;
    lbl_8030CEA0.tbl[19] = lbl_8030B7F4.x32d;
    lbl_8030CEA0.x17a0 = lbl_80310A1C[0x4e];
    lbl_8030CEA0.x17a0 |= lbl_80310A1C[0x4f] << 8;
    lbl_8030CEA0.x17a0 |= lbl_80310A1C[0x50] << 16;
    lbl_8030CEA0.x17a0 |= lbl_80310A1C[0x51] << 24;
    lbl_8030CEA0.x17a4 = lbl_80310A1C[0x52];
    lbl_8030CEA0.x17a4 |= lbl_80310A1C[0x53] << 8;
    lbl_8030CEA0.x17a4 |= lbl_80310A1C[0x54] << 16;
    lbl_8030CEA0.x17a4 |= lbl_80310A1C[0x55] << 24;
    lbl_8030CEA0.tbl[20] = lbl_8030CEA0.x17a0;
}

s32 fn_801F9454(u16 flags, Scpt* c)
{
    if (flags & 1) {
        f32* p = c->cur.f + 1;
        s32 on = ReadInt(&p);
        f32 v = fn_801F6120(&p);
        s32 m;
        lbl_8030CE94.f4 = v;
        lbl_8030CE94.i8 = m = ReadInt(&p);
        c->cur.f = p;
        if (on != 0) {
            fn_800D23F8(1, 0.0f, v, m);
            lbl_8030CE94.flag = 1;
        } else {
            fn_800D244C(1, 0.0f, v, m);
            lbl_8030CE94.flag = 0;
        }
        fn_80211EB0(1, lbl_8030CE94.f4);
    }
    if (flags & 8) {
        return 1;
    }
    return 0;
}

extern char lbl_8034C1CC[5];
extern char lbl_8034C1D4[5];
s16 fn_801FA4C0(u16 flags, Scpt* c)
{
    if (flags & 1) {
        f32* p = c->cur.f + 1;
        s32 a;
        char* str;
        char* b1;
        char* b2;
        if (3.4028235e38f == *p) {
            p++;
            a = 0x7FFFFFFF;
        } else {
            a = (s32)fn_801F6120(&p);
        }
        str = (char*)p + *(s32*)p;
        p++;
        c->cur.f = p;
        b1 = fn_801E1A2C(1, strlen(lbl_80346848) + strlen(str) + 5);
        strcpy(b1, lbl_80346848);
        strcat(b1, str);
        strcat(b1, lbl_8034C1CC);
        b2 = fn_801E1A2C(1, strlen(lbl_80346848) + strlen(str) + 4);
        strcpy(b2, lbl_80346848);
        strcat(b2, str);
        strcat(b2, lbl_8034C1D4);
        fn_80218D80(b1, 0x42504d53, a);
        fn_80218D80(b2, 0x42534d53, a);
        if (b1 != 0) {
            fn_801E1784(b1);
        }
        if (b2 != 0) {
            fn_801E1784(b2);
        }
    }
    return (flags >> 3) & 1;
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

s32 fn_8020BDB0(u16 flags, Scpt* obj)
{
    f32* p;
    s32 b;
    s32 c;
    u32 a;
    if (flags & 1) {
        p = obj->cur.f + 1;
        a = ReadInt(&p);
        b = ReadInt(&p);
        c = ReadInt(&p);
        obj->cur.f = p;
        fn_802173F4(a, b, c);
    }
    if (flags & 8)
        return 1;
    return 0;
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

extern char lbl_802D4E34[];
extern char lbl_802D4E50[];
s32 fn_801FF714(u16 flags, Scpt* o) {
    if (flags & 1) {
        f32* p = o->cur.f;
        Work801F8* s;
        s32 i, cnt;
        p++;
        cnt = *(s32 *)p++;
        for (i = 0; i < cnt; i++) {
            s = fn_801E1A2C(1, 0x44);
            if (s == 0) {
                fn_801DBE1C(lbl_802D4E34, i);
            }
            o->work.work801F8 = s;
            s->ev.hd.kind = 0;
            s->n = ReadInt(&p);
            s->x1c = s->n;
            fn_80211058(o, 9, s->n, 2, lbl_8030CEA0.x08, &s->ev);
            o->kind = 1;
            o->cnt = 0;
            fn_80210F74(o);
        }
        o->flags = 1;
        o->cur.f = p;
        return 0;
    }
    if (flags & 2) {
        Work801F8* st = o->work.work801F8;
        if (o->handle == 0) {
            o->handle = fn_800CD0B8(o->a20, o->a24, o->a28, o->a2c);
            o->cnt++;
            if (o->cnt == 5) {
                fn_801DBE1C(lbl_802D4E50);
            }
        } else if (st->ev.hd.kind == 2) {
            return 0;
        }
    }
    return !(flags & 8);
}

extern char lbl_802D4E34[];
extern char lbl_802D4E50[];
s32 fn_801FFA60(u16 flags, Scpt* o) {
    if (flags & 1) {
        f32* p = o->cur.f;
        Work801F8* s;
        s32 i, cnt;
        p++;
        cnt = *(s32 *)p++;
        for (i = 0; i < cnt; i++) {
            s = fn_801E1A2C(1, 0x44);
            if (s == 0) {
                fn_801DBE1C(lbl_802D4E34, i);
            }
            o->work.work801F8 = s;
            s->ev.hd.kind = 0;
            s->n = ReadInt(&p);
            s->x1c = s->n;
            fn_80211058(o, 9, s->n, 2, lbl_8030CEA0.x08, &s->ev);
            o->kind = 1;
            o->cnt = 0;
            fn_80210F74(o);
        }
        o->flags = 0;
        o->cur.f = p;
        return 0;
    }
    if (flags & 2) {
        Work801F8* st = o->work.work801F8;
        if (o->handle == 0) {
            o->handle = fn_800CD0B8(o->a20, o->a24, o->a28, o->a2c);
            o->cnt++;
            if (o->cnt == 5) {
                fn_801DBE1C(lbl_802D4E50);
            }
        } else if (st->ev.hd.kind == 2) {
            return 0;
        }
    }
    return !(flags & 8);
}

s32 fn_801FF8D4(u16 flags, Scpt* o) {
    if (flags & 1) {
        f32* p = o->cur.f;
        Work801F8* s;
        s32 i, cnt;
        p++;
        cnt = *(s32 *)p++;
        for (i = 0; i < cnt; i++) {
            s = fn_801E1A2C(1, 0x44);
            o->work.work801F8 = s;
            s->ev.hd.kind = 0;
            s->n = ReadInt(&p);
            s->x1c = s->n;
            fn_80211058(o, 9, s->n, 1, lbl_8030CEA0.x08, &s->ev);
            o->kind = 1;
            o->cnt = 0;
            fn_80210F74(o);
        }
        o->cur.f = p;
        o->flags = 1;
        return 0;
    }
    if (flags & 2) {
        Work801F8* st = o->work.work801F8;
        if (o->handle == 0) {
            o->handle = fn_800CD0B8(o->a20, o->a24, o->a28, o->a2c);
            o->cnt++;
        } else if (st->ev.hd.kind == 2) {
            return 0;
        }
    }
    return !(flags & 8);
}

s32 fn_801FFC20(u16 flags, Scpt* o) {
    if (flags & 1) {
        f32* p = o->cur.f;
        Work801F8* s;
        s32 i, cnt;
        p++;
        cnt = *(s32 *)p++;
        for (i = 0; i < cnt; i++) {
            s = fn_801E1A2C(1, 0x44);
            o->work.work801F8 = s;
            s->ev.hd.kind = 0;
            s->n = ReadInt(&p);
            s->x1c = s->n;
            fn_8010A164(s->n);
            fn_80211058(o, 9, s->n, 1, lbl_8030CEA0.x08, &s->ev);
            o->kind = 1;
            o->cnt = 0;
            fn_80210F74(o);
        }
        o->cur.f = p;
        o->flags = 0;
        return 0;
    }
    if (flags & 2) {
        Work801F8* st = o->work.work801F8;
        if (o->handle == 0) {
            o->handle = fn_800CD0B8(o->a20, o->a24, o->a28, o->a2c);
            o->cnt++;
        } else if (st->ev.hd.kind == 2) {
            return 0;
        }
    }
    return !(flags & 8);
}

s32 fn_801FD264(u16 flags, Scpt* o) {
    if (flags & 1) {
        f32* p;
        s32 i, cnt;
        PatStep* e;
        f32 v;
        p = o->cur.f + 1;
        cnt = *(s32 *)p++;
        lbl_8030CEA0.x828 = fn_80212050();
        lbl_8030CEA0.x842 = 0;
        lbl_8030CEA0.x844 = 0;
        lbl_8030CEA0.x83c = 0;
        e = lbl_8030CEA0.steps;
        for (i = 0; i < cnt; i++) {
            e->a = ReadInt(&p);
            e->b = ReadInt(&p);
            e->c = ReadInt(&p);
            if (e->c == 0) {
                lbl_8030CEA0.x838 = (s8)e->b;
                lbl_8030CEA0.x840 = i + 1;
                break;
            }
            e++;
        }
        if (i >= cnt) {
            e[-1].c = 0;
            lbl_8030CEA0.x840 = cnt;
            lbl_8030CEA0.x838 = (s8)e[-1].b;
        }
        v = (s8)lbl_8030CEA0.steps[0].a;
        lbl_8030CEA0.x830 = v;
        lbl_8030CEA0.x82c = 3;
        o->cur.f = p;
    }
    return 0;
}

s32 fn_80205C24(u16 a, Scpt *st) {
    if (a & 1) {
        f32 *cur = st->cur.f;
        f32 f0, f1, f2, f3, f4, f5, f6;
        u16 id;
        s32 v;
        fn_801F7500();
        id = RDI(cur);
        f0 = fn_801F6120(&cur);
        f1 = fn_801F6120(&cur);
        f2 = fn_801F6120(&cur);
        f3 = fn_801F6120(&cur);
        f4 = fn_801F6120(&cur);
        f5 = fn_801F6120(&cur);
        f6 = fn_801F6120(&cur);
        v = RDI(cur);
        fn_80097294(10);
        fn_8009703C(id, f0, f1);
        fn_8009724C(f2, f3, f4);
        fn_800971E0(182.04445f * f5, 182.04445f * f6, 0);
        if ((u16)v == 0) {
            fn_80097318(1);
        } else {
            fn_80097318(0);
        }
        st->cur.f = cur;
    }
    if (a & 8) {
        return 1;
    }
    return 0;
}

s32 fn_80205F14(u16 a, Scpt *st) {
    if (a & 1) {
        f32 *cur = st->cur.f;
        f32 f0, f1, f2, f3;
        u32 v;
        fn_801F7500();
        f0 = fn_801F6120(&cur);
        if (f0 == 3.4028235e38f) {
            f0 = 14.0f;
        }
        f1 = fn_801F6120(&cur);
        if (f1 == 3.4028235e38f) {
            f1 = 200.0f;
        }
        f2 = fn_801F6120(&cur);
        if (f2 == 3.4028235e38f) {
            f2 = 337.5f;
        }
        f3 = fn_801F6120(&cur);
        if (f3 == 3.4028235e38f) {
            f3 = 337.5f;
        }
        v = RDI(cur);
        fn_80097294(8);
        fn_800971C4(f1);
        fn_8009724C(0.0f, f0, 0.0f);
        fn_800971E0(182.04445f * f2, 182.04445f * f3, 0);
        if (v == 0) {
            fn_80097318(1);
        } else {
            fn_80097318(0);
        }
        st->cur.f = cur;
    }
    if (a & 8) {
        return 1;
    }
    return 0;
}

extern void fn_801CBBD8(void);
s32 fn_802015AC(u32 flags, Scpt *st) {
    u16 f = flags;
    if (flags & 1) {
        float *p = st->cur.f;
        u32 n;
        p++;
        n = RDI(p);
        st->cur.f = p;
        st->work.n = 0;
        if (FlagTest(0x31) == 1) {
            return 0;
        }
        if (n == 0) {
            fn_801CBBD8();
            return 0;
        }
        lbl_80347510 = 0.0f;
        lbl_80347514 = (n == 0x7FFFFFFF) ? 30.0f : (f32)(n + 1);
        lbl_80347518 = 1;
    }
    if (f & 2) {
        if (st->work.n != 0) {
            if (lbl_80347508 == 0) {
                st->work.n = 0;
                return 0;
            }
        } else {
            st->work.n = 1;
        }
    }
    if (f & 8) {
        st->work.n = 0;
        return 0;
    }
    return 1;
}

extern s16 fn_801F6EC8(s32 v);
static inline void ReleaseAll(void)
{
    s32 i;
    for (i = 0; i < 256; i++) {
        if (lbl_8030CEA0.ent[i][0]) {
            fn_8020F934(lbl_8030CEA0.ent[i][1]);
        }
    }
}

s32 fn_80207A40(u32 flags, Scpt* s)
{
    f32* p;
    s32 id;
    s16 k;
    u16 f = flags;
    if (f & 1) {
        p = s->cur.f;
        p++;
        id = RDI(p);
        s->cur.f = p;
        if (id == 0x10000) {
            ReleaseAll();
            return 0;
        }
        fn_802107A4(s, id);
    }
    if (f & 2) {
        Work801F8* w = s->work.work801F8;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("scptRet: message post time out %d", w->n);
        } else if (w->ev.hd.kind == 2) {
            k = fn_801F6EC8(w->n);
            if (k != -1) {
                lbl_8030CEA0.ent[k][0] = 0;
            } else {
                fn_801DBE1C("scptRet: no use enter table!!! No:%d", w->n);
            }
            return 0;
        }
    }
    if (f & 8) {
        Work801F8* w = s->work.work801F8;
        k = fn_801F6EC8(w->n);
        if (k != -1) {
            lbl_8030CEA0.ent[k][0] = 0;
        } else {
            fn_801DBE1C("scptRet: no use enter table!!! No:%d", w->n);
        }
    }
    return 1;
}

s16 fn_8020623C(u16 a, Scpt *st) {
    if (a & 1) {
        f32 *cur = st->cur.f;
        f32 f0, f1, f2, f3, f4, f5;
        s32 v;
        fn_801F7500();
        cur++;
        f0 = fn_801F6120(&cur);
        f1 = fn_801F6120(&cur);
        f2 = fn_801F6120(&cur);
        f3 = fn_801F6120(&cur);
        f4 = fn_801F6120(&cur);
        f5 = fn_801F6120(&cur);
        v = ReadInt(&cur);
        st->cur.f = cur;
        fn_80097294(1);
        if (f0 != 3.4028235e38f) {
            fn_80097204(f0, f1, f2);
        }
        if (f3 == 3.4028235e38f) {
            f3 = 14.0f;
        }
        fn_8009724C(0.0f, f3, 0.0f);
        if (f4 == 3.4028235e38f) {
            f4 = 40.0f;
        }
        fn_800971A8(f4);
        if (f5 == 3.4028235e38f) {
            f5 = 348.0f;
        }
        fn_80097134((s32)f5);
        if (v == 0) {
            fn_80097318(1);
        } else {
            fn_80097318(0);
        }
    }
    return (a >> 3) & 1;
}

/* The work of a type-5 message with a value: the head, the value and the text. */
typedef struct Work_8020A584 {
    EvHead hd;
    s32 x08;
    char* x0c;
} Work_8020A584;
extern char lbl_802D5584[], lbl_802D55A0[];
s32 fn_8020A584(u16 flags, Scpt* c)
{
    Work_8020A584* r;
    f32* p;
    if (flags & 1) {
        s32 n;
        char* s;
        p = c->cur.f + 1;
        n = RDI(p);
        s = (char*)p + *(s32*)p;
        p++;
        c->cur.f = p;
        lbl_8030CEA0.x15c8 = 1;
        r = fn_801E1A2C(1, 0x10);
        if (r == 0) {
            fn_801DBE1C(lbl_802D5584);
        }
        c->work.work_8020A584 = r;
        r->hd.kind = 0;
        r->x08 = n;
        r->x0c = s;
        fn_802110E8(c, 5, 0, 1, lbl_8030CEA0.x08, &r->hd);
    }
    if (flags & 2) {
        Work_8020A584* w = c->work.work_8020A584;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a20, c->a24, c->a28, c->a2c);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C(lbl_802D55A0);
            }
        } else if (w->hd.kind == 2) {
            lbl_8030CEA0.x15c8 = 0;
            lbl_8030CEA0.x1568 = w->x08;
            return 0;
        }
    }
    if (flags & 8) {
        lbl_8030CEA0.x15c8 = 0;
        return 0;
    }
    return 1;
}

/* The work of a type-8 message: the head, an id and a value. */
typedef struct Work_8020D2A8 {
    EvHead hd;
    u8 pad08[0x10];
    u16 n;
    u8 pad1a[2];
    s32 x1c;
    u8 pad20[0x24];
} Work_8020D2A8;
s32 fn_8020D2A8(u32 flags, Scpt* s)
{
    Work_8020D2A8* w;
    f32* p;
    s32 cnt;
    s32 v;
    s32* cp;
    s32 i;
    u16 f = flags;
    if (f & 1) {
        p = s->cur.f + 1;
        v = RDI(p);
        cp = (s32*)p;
        p++;
        cnt = *cp;
        for (i = 0; i < cnt; i++) {
            w = fn_801E1A2C(1, 0x44);
            if (w == NULL) fn_801DBE1C("Ukitome: malloc failed 1");
            s->work.work_8020D2A8 = w;
            w->hd.kind = 0;
            w->n = RDI(p);
            w->x1c = v;
            fn_802110E8(s, 8, w->n, 3, lbl_8030CEA0.x08, &w->hd);
            s->kind = 1;
            s->cnt = 0;
            fn_80210F74(s);
        }
        s->cur.f = p;
        return 0;
    }
    if (f & 2) {
        w = s->work.work_8020D2A8;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("Ukitome: message post timed out");
        } else if (w->hd.kind == 2) {
            return 0;
        }
    }
    return 1;
}

s32 fn_8020D488(u32 flags, Scpt* s)
{
    Work_8020D2A8* w;
    f32* p;
    s32 cnt;
    s32 v;
    s32* cp;
    s32 i;
    u16 f = flags;
    if (f & 1) {
        p = s->cur.f + 1;
        v = RDI(p);
        cp = (s32*)p;
        p++;
        cnt = *cp;
        for (i = 0; i < cnt; i++) {
            w = fn_801E1A2C(1, 0x44);
            if (w == NULL) fn_801DBE1C("Ukinoru: malloc failed 1");
            s->work.work_8020D2A8 = w;
            w->hd.kind = 0;
            w->n = RDI(p);
            w->x1c = v;
            fn_802110E8(s, 8, w->n, 2, lbl_8030CEA0.x08, &w->hd);
            s->kind = 1;
            s->cnt = 0;
            fn_80210F74(s);
        }
        s->cur.f = p;
        return 0;
    }
    if (f & 2) {
        w = s->work.work_8020D2A8;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("Ukinoru: message post timed out");
        } else if (w->hd.kind == 2) {
            return 0;
        }
    }
    return 1;
}

s32 fn_8020D668(u32 flags, Scpt* s)
{
    Work_8020D2A8* w;
    f32* p;
    s32 cnt;
    s32 v;
    s32* cp;
    s32 i;
    u16 f = flags;
    if (f & 1) {
        p = s->cur.f + 1;
        v = RDI(p);
        cp = (s32*)p;
        p++;
        cnt = *cp;
        for (i = 0; i < cnt; i++) {
            w = fn_801E1A2C(1, 0x44);
            if (w == NULL) fn_801DBE1C("Ukisugu1: malloc failed 1");
            s->work.work_8020D2A8 = w;
            w->hd.kind = 0;
            w->n = RDI(p);
            w->x1c = v;
            fn_802110E8(s, 8, w->n, 1, lbl_8030CEA0.x08, &w->hd);
            s->kind = 1;
            s->cnt = 0;
            fn_80210F74(s);
        }
        s->cur.f = p;
        return 0;
    }
    if (f & 2) {
        w = s->work.work_8020D2A8;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("Ukisugu1: message post timed out");
        } else if (w->hd.kind == 2) {
            return 0;
        }
    }
    return 1;
}

s32 fn_8020D848(u32 flags, Scpt* s)
{
    Work_8020D2A8* w;
    f32* p;
    s32 cnt;
    s32 v;
    s32* cp;
    s32 i;
    u16 f = flags;
    if (f & 1) {
        f32* c = s->cur.f + 1;
        s->cur.f = c;
        p = c;
        v = RDI(p);
        cp = (s32*)p;
        p++;
        cnt = *cp;
        for (i = 0; i < cnt; i++) {
            w = fn_801E1A2C(1, 0x44);
            if (w == NULL) fn_801DBE1C("scptUkisuguR: malloc failed 1");
            s->work.work_8020D2A8 = w;
            w->hd.kind = 0;
            w->n = RDI(p);
            w->x1c = v;
            fn_802110E8(s, 8, w->n, 0, lbl_8030CEA0.x08, &w->hd);
            s->kind = 1;
            s->cnt = 0;
            fn_80210F74(s);
        }
        s->cur.f = p;
        return 0;
    }
    if (f & 2) {
        w = s->work.work_8020D2A8;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("scptUkisuguR: message post timed out");
        } else if (w->hd.kind == 2) {
            return 0;
        }
    }
    return 1;
}

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
extern const s32 lbl_8034A034;
void fn_8020DBC4(s32 id)
{
    Scpt s;
    Work_8020DBC4* w;
    EvBufs* w2;
    void* buf;
    w = fn_801E1A2C(1, 0x44);
    if (w == NULL) fn_801DBE1C("Malloc Failed : %s : %d", "scpteve.c", 1028);
    s.work.work_8020DBC4 = w;
    w2 = fn_801E1A2C(1, 0x88);
    if (w2 == NULL) fn_801DBE1C("Malloc Failed : %s : %d", "scpteve.c", 1036);
    buf = fn_801E1A2C(1, lbl_8034A034 * 0x58);
    w2->x20 = buf;
    if (buf == NULL) fn_801DBE1C("Malloc Failed : %s : %d", "scpteve.c", 1039);
    buf = fn_801E1A2C(1, lbl_8034A034 << 6);
    w2->x1c = buf;
    if (buf == NULL) fn_801DBE1C("Malloc Failed : %s : %d", "scpteve.c", 1042);
    w->x1c = w2;
    fn_80211058(&s, 6, id, 0x28, lbl_8030CEA0.x08, &w->ev);
    s.owner = 0xaf;
    s.kind = 1;
    s.cur.f = NULL;
    s.cnt = 0;
    fn_80210F74(&s);
}

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

