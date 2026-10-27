#include "types.h"
#include "game/work_8030CEA0.h"
#include "ninja.h"
#include "game/task.h"
#include <math.h>
void fn_80217B98();
void fn_801EFC88(s16 v);
typedef struct CmdStream { u8 pad_00[0x1c]; u8 *cur; } CmdStream;
typedef struct Cmd { u8 pad_00[0x1c]; float *cur; } Cmd;
void fn_800B0900(void *p);
void fn_800FF9FC(void *p);
extern u8 lbl_8030B4D4[];
extern u8 lbl_8030B7F4[];
void fn_801003F4(void *p);
void fn_800D2CA8(s32 a);
void fn_80210CE4(void);
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
float fn_801F6120(float **p);
void fn_801EFF0C(s16 v);
typedef struct CmdB { u8 pad_00[0x1c]; float *cur; } CmdB;
typedef struct {
    u32 kind;       /* 0x00 */
    u8 pad04[0x14];
    u16 n;          /* 0x18 */
    u8 pad1a[2];
    s32 x1c;        /* 0x1C */
    s32 x20;        /* 0x20 */
    f32 x24;        /* 0x24 */
    f32 x28;        /* 0x28 */
    u32 x2c;        /* 0x2C */
    u8 pad30[0x14];
} Work801F8;
/* 0x44 */

typedef struct {
    u8 pad00[8];
    s32 handle;     /* 0x08 */
    u8 pad0c[4];
    s16 cnt;        /* 0x10 */
    u8 pad12[10];
    f32* cursor;   /* 0x1C */
    s32 a20;        /* 0x20 */
    s32 a24;        /* 0x24 */
    s32 a28;        /* 0x28 */
    s32 a2c;        /* 0x2C */
    Work801F8* work; /* 0x30 */
} Script801F8;
extern void* fn_801E1A2C(s32 a, s32 b);
extern void fn_801DBE1C(const char* fmt, ...);
extern s32 fn_800CD0B8(s32 a, s32 b, s32 c, s32 d);
extern void fn_80211058(void* s, s32 a, s32 b, s32 c, s16 d, void* w);
typedef struct {
    u32 kind;       /* 0x00 */
    u8 pad04[0x14];
    u16 n;          /* 0x18 */
    u8 pad1a[2];
    f32 x1c;        /* 0x1C */
    f32 x20;        /* 0x20 */
    f32 x24;        /* 0x24 */
    s32 x28;        /* 0x28 */
    s32 x2c;        /* 0x2C */
    s32 x30;        /* 0x30 */
    f32 x34;        /* 0x34 */
    u8 pad38[0xc];
} Work801FC;
/* 0x44 */

typedef struct {
    u8 pad00[8];
    s32 handle;     /* 0x08 */
    u8 pad0c[4];
    s16 cnt;        /* 0x10 */
    u8 pad12[10];
    f32* cursor;   /* 0x1C */
    s32 a20;        /* 0x20 */
    s32 a24;        /* 0x24 */
    s32 a28;        /* 0x28 */
    s32 a2c;        /* 0x2C */
    Work801FC* work; /* 0x30 */
} Script801FC;
extern void fn_801E1784(void* p);
extern u32 fn_800CCC48(s32 a, s32 b);
typedef struct {
    u8 pad00[0x1c];
    f32* cursor;   /* 0x1C */
} Script8020;
extern void fn_80097294(u8 a);
extern void fn_80097270(f32 a, f32 b, f32 c);
extern void fn_8009724C(f32 a, f32 b, f32 c);
extern void fn_800971C4(f32 a);
extern void fn_800971E0(u32 a, u32 b, u32 c);
extern void fn_80097150(s32 a);
extern void fn_80097118(f32 a);
extern void fn_800970FC(f32 a);
extern void fn_80097318(s8 x);
typedef struct {
    u32 kind;       /* 0x00 */
    u8 pad04[0x14];
    u16 n;          /* 0x18 */
    u8 pad1a[2];
    s32 x1c;        /* 0x1C */
    f32 x20;        /* 0x20 */
    f32 x24;        /* 0x24 */
    f32 x28;        /* 0x28 */
    u8 pad2c[0xc];
    s32 x38;        /* 0x38 */
    s32 x3c;        /* 0x3C */
    u8 pad40[4];
} Work8020;
/* 0x44 */

typedef struct {
    u8 pad00[8];
    s32 handle;     /* 0x08 */
    u8 pad0c[4];
    s16 cnt;        /* 0x10 */
    u8 pad12[10];
    f32* cursor;   /* 0x1C */
    s32 a20;        /* 0x20 */
    s32 a24;        /* 0x24 */
    s32 a28;        /* 0x28 */
    s32 a2c;        /* 0x2C */
    Work8020* work; /* 0x30 */
} Script80209548;
typedef struct {
    u8 pad00[0x1c];
    f32* cursor;   /* 0x1C */
} Script8020C;
typedef struct {
    u8 pad00[0x44];
    s32 x44;
    s32 x48;
    s32 x4c;
} Actor8020C;
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
extern void fn_8020F998(s32 a, f32* v, s32 b, s32 c, s32 d, s32 e);
extern void fn_8020FF44(s32 a, s32 b);
extern void fn_8020FDE0(s32 a, s32 b, s32 c, s32 d);
extern Actor8020C* fn_8015F1A0(u16 id);
extern void* fn_801F4AE4(s16 id);
extern int fn_8025CB24(char* buf, const char* fmt, ...);
extern void fn_8021026C(char* s);
typedef struct CmdF { u8 pad_00[0x1c]; float *cur; } CmdF;
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
typedef struct { u8 pad_00[0x1c]; float *cur; } CmdB_801F5EB4;
typedef struct { u8 pad_00[0x1c]; float *cur; } CmdB_801F6044;
typedef struct { u8 pad_00[0x1c]; float *cur; } CmdB_801F984C;
void fn_8016D904(s32 n);
typedef struct { u8 pad_00[0x1c]; float *cur; } CmdB_801FD850;
typedef struct { u8 pad_00[0x1c]; float *cur; } CmdB_801FDC70;
void fn_801E749C(float *v);
typedef struct { u8 pad_00[0x1c]; float *cur; } CmdB_801FDE70;
void fn_800FF780(u8 *p);
extern s32 lbl_803473B4;
typedef struct { u8 pad_00[0x1c]; u8 *cur; } CmdStream_801FED58;
typedef struct { u8 pad_00[0x1c]; float *cur; } CmdB_801FEE54;
void fn_800D2C44(u16 v);
typedef struct { u8 pad_00[0x1c]; float *cur; } CmdB_801FFDB4;
void fn_8022D34C(s32 a, f32 b);
typedef struct { u8 pad_00[0x1c]; float *cur; } CmdB_80204F04;
void fn_801002D0(void *p);
typedef struct { u8 pad_00[0x1c]; u8 *cur; } CmdStream_802073B4;
void fn_801F7B04(s32 v);
extern s32 lbl_80347474;
typedef struct { u8 pad_00[0x1c]; u8 *cur; } CmdStream_80207428;
extern void ScreenFadeDraw(void *p, f32 a, f32 b, f32 c, f32 d, f32 e);
extern void njUnitMatrix(f32 *m);
extern void njRotateXYZ(f32 *m, s32 x, s32 y, s32 z);
typedef struct {
    u8 pad0[0x1c];
    float *x1c;
} Obj80214;
extern void fn_80148188(s32 v);
extern void *fn_802159E0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i);
typedef struct { u8 pad_00[0x1c]; float *cur; } CmdB_801F5D08;
typedef struct { u8 pad_00[0x1c]; float *cur; } CmdB_801FD1D0;
s32 fn_8011768C(u32 flags);
typedef struct { u8 pad_00[0x1c]; u8 *cur; } CmdStream_8020A2C8;
typedef struct {
    s32 kind;
    u8 pad04[0x14];
    s32 idx;
    u8 pad1c[0x34 - 0x1c];
} CtlEnt;
typedef struct {
    u8 pad0[4];
    u16 v;
    u8 pad6[6];
} CtlPart;
extern CtlPart lbl_802F7940[];
extern void fn_80210B44(s32 i);
typedef struct CmdStream_80205E48 { u8 pad_00[0x1c]; f32 *cur; } CmdStream_80205E48;
typedef struct {
    s32 kind;
    u8 pad04[0x14];
    s32 idx;
    u8 pad1c[4];
    u32 x20;
    u32 x24;
    u8 pad28[0x34 - 0x28];
} CtlEnt_80210EA4;
typedef struct Obj10A { void (*fn)(struct Obj10A *); u8 pad4[0x15]; u8 x19; u8 pad1a[0xa]; void *x24; } Obj10A;
extern void *lbl_80347450;
extern Obj10A *fn_8010A164(u32 id);
extern void fn_801559BC(void *p);
typedef struct { u8 pad_00[0x1c]; float *cur; } CmdB_801FDCDC;
extern void *lbl_8034759C;
extern s32 lbl_803473C0;
extern u8 fn_8020E984(void);
void fn_801BEA70(void *a, u32 idx, s32 mode);
typedef struct { u8 pad_00[0x1c]; float *cur; } CmdB_80213920;
void fn_80147DA8(s32 a, s32 b);
typedef struct { u8 pad_00[0x1c]; float *cur; } CmdB_80214C04;
void fn_80147DC8(s32 a, s32 b);
typedef struct CmdB_801F570C { u8 pad_00[4]; s32 w04; u8 pad_08[0x14]; float *cur; } CmdB_801F570C;
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
typedef struct { u8 pad_00[0x1c]; float *cur; } CmdB_801F5F50;
void fn_800EB58C(s32 n);
typedef struct { u8 pad_00[0x1c]; float *cur; } CmdB_8020B9EC;
extern f32 fn_80291A5C(f32 v);
double atan2(double y, double x);
typedef struct { u8 pad_00[0x1c]; float *cur; } CmdB_801F934C;
typedef struct { s32 flag; f32 f4; s32 i8; } Fx_8030CE94;
extern Fx_8030CE94 lbl_8030CE94;
void fn_800D23F8(s32 n, f32 a, f32 b, s32 m);
void fn_800D244C(s32 n, f32 a, f32 b, s32 m);
typedef struct {
    u8 pad0[0x828];
    s32 x828;
    s32 x82c;
    f32 x830;
    s32 x834;
    u8 pad838[0xc4a - 0x838];
    u8 xc4a;
    u8 xc4b;
} WorkB;
void fn_80211EB0(s16 mode, f32 v);
typedef struct { u8 pad_00[0x1c]; float *cur; } CmdB_801FA290;
extern s32 lbl_803475B4;
double fn_8026216C(double x);
void fn_8021730C(s32 a, s32 b);
typedef struct { u8 pad_00[0x1c]; float *cur; } CmdB_80207630;
typedef struct { u8 pad0[0x190]; f32 f190; } Obj_80207630;
s32 fn_8015F1F0(void *o);
typedef struct { u8 pad_00[0x1c]; float *cur; } CmdB_802057E0;
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
typedef struct { u8 pad_00[0x1c]; float *cur; } CmdB_801FA398;
extern s32 fn_80218570(s32 a, s32 b, s32 c);
void fn_80097204(f32 a, f32 b, f32 c);
void fn_800972E0(s32 a);
void fn_80225CAC(s32 a, u16 b, s16 c);
void fn_80213478(f32 *a, f32 *b, s32 *c);
void fn_801000F0(s32 a, s32 b);
void fn_80118578(s32 a, f32 f1, f32 f2, f32 f3, f32 f4);
typedef struct Cmd_8020170C { u8 pad_00[0x1c]; float *cur; u8 pad20[0x10]; u32 x30; } Cmd_8020170C;
extern void fn_801CBBBC(void);
extern s32 lbl_80347508;
extern f32 lbl_80347510;
extern f32 lbl_80347514;
extern u32 lbl_80347518;
extern void fn_8015F654(void* p);
extern char lbl_802D4D7C[];
typedef struct Sub { u8 pad[0x1a0]; s32 x1a0; } Sub;
typedef struct Mid {
    u8 pad[0x1d8];
    Sub* sub;
    u8 pad1dc[0x26c - 0x1dc];
    u8 b26c;
} Mid;
extern s32 fn_8025ECC4(void);
typedef struct { u8 pad_00[0x1c]; float *cur; } CmdB_801FE21C;
typedef struct { u8 pad_00[0x1c]; float *cur; } CmdB_80200CE4;
extern void fn_801D995C(s32 n, f32 a, f32 b, f32 c);
typedef struct {
    u8 pad00[0x18];
    s32 ent[256][2];
    u8 pad818[0x1920 - 0x818];
} Work;
typedef struct { u8 pad_00[0x1c]; float *cur; } Cmd_80200FC4;
extern void fn_800D2554(f32 x, f32 y);
extern void fn_800D25C4(u32 rgb, s32 n);
extern void fn_800D258C(s32 n, f32 a, f32 b);
typedef struct { u8 pad_00[0x1c]; float *cur; } Cmd_80201228;
typedef struct {
    u32 kind;       /* 0x00 */
    u8 pad04[0x14];
    s32 x18;
    s32 x1c;
    s32 x20;
} Work_80202004;
typedef struct {
    u8 pad00[8];
    s32 handle;     /* 0x08 */
    u8 pad0c[4];
    s16 cnt;        /* 0x10 */
    u8 pad12[10];
    f32* cursor;    /* 0x1C */
    s32 a20;
    s32 a24;
    s32 a28;
    s32 a2c;
    Work_80202004* work;     /* 0x30 */
} Script_80202004;
extern void fn_802110E8(void* s, s32 a, s32 b, s32 c, s16 d, void* w);
typedef struct CmdStream_802049BC { u8 pad_00[0x1c]; f32 *cur; } CmdStream_802049BC;
extern void fn_80097094(u16 a, f32 b);
extern void fn_80097228(f32 a, f32 b, f32 c);
typedef struct CmdStream_80204CD0 { u8 pad_00[0x1c]; f32 *cur; } CmdStream_80204CD0;
typedef struct {
    s32 total;      /* 0x00 */
    s32 step[3];    /* 0x04 */
    s32 dest[3];    /* 0x10 */
} Lerp;
typedef struct {
    u8 pad00[0x10];
    s16 cnt;        /* 0x10 */
    u8 pad12[10];
    f32* cursor;    /* 0x1C */
    u8 pad20[0x10];
    Lerp* work;     /* 0x30 */
} Script;
typedef struct CmdStream_80205A3C { u8 pad_00[0x1c]; f32 *cur; } CmdStream_80205A3C;
extern void fn_800971A8(f32 a);
extern void fn_80097134(s32 a);
typedef struct CmdStream_802060D4 { u8 pad_00[0x1c]; f32 *cur; } CmdStream_802060D4;
extern void fn_800970D8(u16 a, f32 b, s32 c);
extern void fn_800970B4(u16 a, f32 b, s32 c);
typedef struct CmdStream_80206904 { u8 pad_00[0x1c]; f32 *cur; } CmdStream_80206904;
typedef struct CmdStream_80206AB0 { u8 pad_00[0x1c]; f32 *cur; } CmdStream_80206AB0;
extern void fn_80097188(f32 a, f32 b);
extern void fn_8009716C(s16 a);
typedef struct Eff {
    f32 f[8];       /* 0x00 */
    s32 x20;
} Eff;
typedef struct CmdStream_80206CBC {
    u8 pad_00[4];
    s32 x04;
    u8 pad_08[0x14];
    f32 *cur;       /* 0x1c */
    s32 x20;
    u8 pad_24[0xc];
    Eff *work;      /* 0x30 */
} CmdStream_80206CBC;
typedef struct CmdStream_80206EA8 { u8 pad_00[0x1c]; f32 *cur; } CmdStream_80206EA8;
typedef struct Cmd_8020A168 {
    u8 pad00[0x1c];
    f32* cur;       /* 0x1c */
} Cmd_8020A168;
extern void fn_801185A8(s32 a, f32 b, f32 c, f32 d, f32 e, f32 f, f32 g);
typedef struct {
    u8 pad00[0x1c];
    f32* cursor;    /* 0x1C */
} Script_8020B670;
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
typedef struct {
    u32* x0;
    u32* x4;
    u8 pad8[0x820 - 8];
    void* x820;
    u32 x824;
    u8 pad828[0x1920 - 0x828];
} Work_801F7158;
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
typedef struct {
    u8 pad0[0x15cc];
    s32 x15cc;
    u8 pad15d0[0x1914 - 0x15d0];
    Script_801F7500* x1914;
    u8 pad1918[0x1920 - 0x1918];
} WorkB_801F7500;
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
typedef struct {
    u8 pad0[0x18fc];
    f32 x18fc, x1900, x1904;
    s32 x1908;
    u8 pad190c[4];
    s32 x1910;
    Script_801F773C* x1914;
    s32 x1918;
    u8 pad191c[4];
} WorkC_801F773C;
void fn_80213178(f32 x, f32 t, void* p0, void* p1, void* p2, void* p3, void* p4);
typedef struct {
    u8 pad0[0x1c];
    f32* cur;
} Cmd_801F7D2C;
void fn_800B09C0(s8 id, s8 a, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5);
void fn_800AFCC0(s8 id, s8 a, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5);
typedef struct {
    u32 x0;
    u8 pad4[0x14];
    u16 x18;
    u8 pad1a[2];
    f32 x1c, x20, x24, x28, x2c, x30;
    s32 x34;
    u8 pad38[0x44 - 0x38];
} Fx;
typedef struct {
    u8 pad0[8];
    s32 x8;
    u8 padc[4];
    s16 x10;
    u8 pad12[0x1c - 0x12];
    f32* cur;
    s32 x20, x24, x28, x2c;
    Fx* x30;
} Cmd_801F7F98;
typedef struct {
    u8 pad0[8];
    s16 x8;
    u8 pad_a[0x1920 - 0xa];
} Work_801F7F98;
typedef struct {
    u32 x0;
    u8 pad4[0x14];
    u16 x18;
    u8 pad1a[2];
    s32 x1c, x20;
    f32 x24, x28;
    s32 x2c;
    u8 pad30[0x44 - 0x30];
} Fx_801F8D0C;
typedef struct {
    u8 pad0[8];
    s32 x8;
    u8 padc[4];
    s16 x10;
    u8 pad12[0x1c - 0x12];
    f32* cur;
    s32 x20, x24, x28, x2c;
    Fx_801F8D0C* x30;
} Cmd_801F8D0C;
typedef struct {
    u8 pad0[8];
    s16 x8;
    u8 pad_a[0x1920 - 0xa];
} Work_801F8D0C;
extern char lbl_802D491C[];
extern char lbl_802D4938[];
typedef struct {
    u32 x0;
    u8 pad4[0x14];
    u16 x18;
    u16 x1a;
    u8 padend[0x44 - 0x1c];
} Fx_801F8F7C;
typedef struct {
    u8 pad0[8];
    s32 x8;
    u8 padc[4];
    s16 x10;
    u8 pad12[0x1c - 0x12];
    f32* cur;
    s32 x20, x24, x28, x2c;
    Fx_801F8F7C* x30;
} Cmd_801F8F7C;
typedef struct {
    u8 pad0[8];
    s16 x8;
    u8 pad_a[0x1920 - 0xa];
} Work_801F8F7C;
extern char lbl_802D4958[];
extern char lbl_802D4978[];
typedef struct {
    u32 x0;
    u8 pad4[0x14];
    u16 x18;
    u16 x1a;
    s32 x1c;
    f32 x20, x24, x28, x2c, x30, x34;
    u8 padend[0x44 - 0x38];
} Fx_801F9120;
typedef struct {
    u8 pad0[8];
    s32 x8;
    u8 padc[4];
    s16 x10;
    u8 pad12[0x1c - 0x12];
    f32* cur;
    s32 x20, x24, x28, x2c;
    Fx_801F9120* x30;
} Cmd_801F9120;
typedef struct {
    u8 pad0[8];
    s16 x8;
    u8 pad_a[0x1920 - 0xa];
} Work_801F9120;
extern char lbl_802D49A0[];
extern char lbl_802D49BC[];
typedef struct {
    u32 x0;
    u8 pad4[0x14];
    u16 x18;
    u8 pad1a[2];
    s32 x1c, x20;
    f32 x24;
    u8 pad28[0x44 - 0x28];
} Fx_801FBBA8;
typedef struct {
    u8 pad0[8];
    s32 x8;
    u8 padc[4];
    s16 x10;
    u8 pad12[0x1c - 0x12];
    f32* cur;
    s32 x20, x24, x28, x2c;
    Fx_801FBBA8* x30;
} Cmd_801FBBA8;
typedef struct {
    u8 pad0[8];
    s16 x8;
    u8 pad_a[0x1920 - 0xa];
} Work_801FBBA8;
extern char lbl_802D4B54[];
extern char lbl_802D4B70[];
typedef struct ScrState {
    u8 pad0[0x1c];
    s32 mode;
    s32 count;
    u8 pad24[0x20];
} ScrState;
typedef struct ScrObj {
    u8 pad0[0x1c];
    f32* script;
    u8 pad20[0x10];
    ScrState* st;
} ScrObj;
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
typedef struct {
    u8 pad00[0xc70];
    s32 xc70;
    u8 padc74[0xc88 - 0xc74];
    s16 xc88;
} Work_80200B90;
typedef struct { u8 pad_00[0x1c]; float *cur; } Cmd_80200B90;
extern void fn_801D9864(s32 n, f32 a, f32 b, f32 c, f32 d, f32 e, f32 g);
typedef struct { u8 pad_00[0x1c]; float *cur; } Cmd_80200DF4;
extern void fn_801D9A0C(s32 n, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f, f32 g, f32 h);
typedef struct {
    u8 pad00[0xc68];
    s32 xc68;
    u8 padc6c[0xc84 - 0xc6c];
    s16 xc84;
} Work_80200DF4;
typedef struct {
    u32 kind;       /* 0x00 */
    u8 pad04[0x14];
    u16 n;          /* 0x18 */
    u8 pad1a[2];
    u32 x1c;        /* 0x1C */
    u8 pad20[0x24];
} Work_8020184C;
/* 0x44 */

typedef struct {
    u8 pad00[8];
    s32 handle;     /* 0x08 */
    u8 pad0c[4];
    s16 cnt;        /* 0x10 */
    u8 pad12[10];
    f32* cursor;   /* 0x1C */
    s32 a20;        /* 0x20 */
    s32 a24;        /* 0x24 */
    s32 a28;        /* 0x28 */
    s32 a2c;        /* 0x2C */
    Work_8020184C* work; /* 0x30 */
} Script_8020184C;
typedef struct {
    u32 kind;       /* 0x00 */
    u8 pad04[0x14];
    s32 x18;        /* 0x18 */
    s32 x1c;        /* 0x1C */
    s32 x20;        /* 0x20 */
    u8 pad24[0x20];
} Work_802019F8;
/* 0x44 */

typedef struct {
    u8 pad00[8];
    s32 handle;     /* 0x08 */
    u8 pad0c[4];
    s16 cnt;        /* 0x10 */
    u8 pad12[10];
    f32* cursor;   /* 0x1C */
    s32 a20;        /* 0x20 */
    s32 a24;        /* 0x24 */
    s32 a28;        /* 0x28 */
    s32 a2c;        /* 0x2C */
    Work_802019F8* work; /* 0x30 */
} Script_802019F8;
typedef struct {
    u32 kind;       /* 0x00 */
    u8 pad04[0x14];
    s32 x18;        /* 0x18 */
    s32 x1c;        /* 0x1C */
    s32 x20;        /* 0x20 */
    u8 pad24[0x20];
} Work_80201B6C;
/* 0x44 */

typedef struct {
    u8 pad00[8];
    s32 handle;     /* 0x08 */
    u8 pad0c[4];
    s16 cnt;        /* 0x10 */
    u8 pad12[10];
    f32* cursor;   /* 0x1C */
    s32 a20;        /* 0x20 */
    s32 a24;        /* 0x24 */
    s32 a28;        /* 0x28 */
    s32 a2c;        /* 0x2C */
    Work_80201B6C* work; /* 0x30 */
} Script_80201B6C;
typedef struct {
    u32 kind;       /* 0x00 */
    u8 pad04[0x14];
    s32 x18;        /* 0x18 */
    s32 x1c;        /* 0x1C */
    s32 x20;        /* 0x20 */
    u8 pad24[0x20];
} Work_80201CE0;
/* 0x44 */

typedef struct {
    u8 pad00[8];
    s32 handle;     /* 0x08 */
    u8 pad0c[4];
    s16 cnt;        /* 0x10 */
    u8 pad12[10];
    f32* cursor;   /* 0x1C */
    s32 a20;        /* 0x20 */
    s32 a24;        /* 0x24 */
    s32 a28;        /* 0x28 */
    s32 a2c;        /* 0x2C */
    Work_80201CE0* work; /* 0x30 */
} Script_80201CE0;
typedef struct {
    u32 kind;       /* 0x00 */
    u8 pad04[0x14];
    s32 x18;        /* 0x18 */
    s32 x1c;        /* 0x1C */
    s32 x20;        /* 0x20 */
    u8 pad24[0x20];
} Work_80201E54;
/* 0x44 */

typedef struct {
    u8 pad00[8];
    s32 handle;     /* 0x08 */
    u8 pad0c[4];
    s16 cnt;        /* 0x10 */
    u8 pad12[10];
    f32* cursor;   /* 0x1C */
    s32 a20;        /* 0x20 */
    s32 a24;        /* 0x24 */
    s32 a28;        /* 0x28 */
    s32 a2c;        /* 0x2C */
    Work_80201E54* work; /* 0x30 */
} Script_80201E54;
typedef struct {
    u32 kind;       /* 0x00 */
    u8 pad04[0x14];
    s32 x18;
    s32 x1c;
    s32 x20;
} Work_802021B8;
typedef struct {
    u8 pad00[8];
    s32 handle;     /* 0x08 */
    u8 pad0c[4];
    s16 cnt;        /* 0x10 */
    u8 pad12[10];
    f32* cursor;    /* 0x1C */
    s32 a20;
    s32 a24;
    s32 a28;
    s32 a2c;
    Work_802021B8* work;     /* 0x30 */
} Script_802021B8;
typedef struct {
    u32 kind;       /* 0x00 */
    u8 pad04[0x14];
    u16 id;         /* 0x18 */
    u16 v;          /* 0x1a */
    f32 f0;         /* 0x1c */
    f32 f1;         /* 0x20 */
    f32 f2;         /* 0x24 */
} Work_80207CD0;
typedef struct {
    u8 pad00[8];
    s32 handle;     /* 0x08 */
    u8 pad0c[4];
    s16 cnt;        /* 0x10 */
    u8 pad12[10];
    f32* cursor;    /* 0x1C */
    s32 a20;
    s32 a24;
    s32 a28;
    s32 a2c;
    Work_80207CD0* work;     /* 0x30 */
} Script_80207CD0;
typedef struct Rec {
    u32 kind;       /* 0x00 */
    u8 pad04[0x14];
    u16 n;          /* 0x18 */
    u8 pad1a[2];
    f32 f1c, f20, f24, f28, f2c, f30;
    s32 i34;
    u8 pad38[0x44 - 0x38];
} Rec;
typedef struct Cmd_80207ED0 {
    s32 kind;       /* 0x00 */
    u8 pad04[4];
    s32 handle;     /* 0x08 */
    u8 pad0c[4];
    s16 cnt;        /* 0x10 */
    u8 pad12[6];
    s32 owner;      /* 0x18 */
    f32* cur;       /* 0x1c */
    s32 a0, a1, a2, a3; /* 0x20 */
    Rec* work;      /* 0x30 */
} Cmd_80207ED0;
extern char lbl_802D5158[], lbl_802D5170[];
typedef struct Cmd_80208044 {
    s32 kind;       /* 0x00 */
    u8 pad04[4];
    s32 handle;     /* 0x08 */
    u8 pad0c[4];
    s16 cnt;        /* 0x10 */
    u8 pad12[6];
    s32 owner;      /* 0x18 */
    f32* cur;       /* 0x1c */
    s32 a0, a1, a2, a3; /* 0x20 */
    Rec* work;      /* 0x30 */
} Cmd_80208044;
extern char lbl_802D5190[], lbl_802D51A8[];
typedef struct Cmd_80208234 {
    s32 kind;       /* 0x00 */
    u8 pad04[4];
    s32 handle;     /* 0x08 */
    u8 pad0c[4];
    s16 cnt;        /* 0x10 */
    u8 pad12[6];
    s32 owner;      /* 0x18 */
    f32* cur;       /* 0x1c */
    s32 a0, a1, a2, a3; /* 0x20 */
    Rec* work;      /* 0x30 */
} Cmd_80208234;
extern char lbl_802D51C8[], lbl_802D51E0[];
typedef struct Rec_80208424 {
    u32 kind;       /* 0x00 */
    u8 pad04[0x14];
    u16 n;          /* 0x18 */
    u8 pad1a[2];
    s32 i1c; f32 f20, f24, f28, f2c, f30;
    s32 i34;
    u8 pad38[0x44 - 0x38];
} Rec_80208424;
typedef struct Cmd_80208424 {
    s32 kind;       /* 0x00 */
    u8 pad04[4];
    s32 handle;     /* 0x08 */
    u8 pad0c[4];
    s16 cnt;        /* 0x10 */
    u8 pad12[6];
    s32 owner;      /* 0x18 */
    f32* cur;       /* 0x1c */
    s32 a0, a1, a2, a3; /* 0x20 */
    Rec_80208424* work;      /* 0x30 */
} Cmd_80208424;
extern char lbl_802D5200[], lbl_802D5220[];
typedef struct Rec_802085CC {
    u32 kind;       /* 0x00 */
    u8 pad04[0x14];
    u16 n;          /* 0x18 */
    u8 pad1a[2];
    s32 i1c; f32 f20, f24, f28, f2c, f30;
    s32 i34;
    u8 pad38[0x44 - 0x38];
} Rec_802085CC;
typedef struct Cmd_802085CC {
    s32 kind;       /* 0x00 */
    u8 pad04[4];
    s32 handle;     /* 0x08 */
    u8 pad0c[4];
    s16 cnt;        /* 0x10 */
    u8 pad12[6];
    s32 owner;      /* 0x18 */
    f32* cur;       /* 0x1c */
    s32 a0, a1, a2, a3; /* 0x20 */
    Rec_802085CC* work;      /* 0x30 */
} Cmd_802085CC;
extern char lbl_802D5248[], lbl_802D5260[];
typedef struct Cmd_80208774 {
    s32 kind;       /* 0x00 */
    u8 pad04[4];
    s32 handle;     /* 0x08 */
    u8 pad0c[4];
    s16 cnt;        /* 0x10 */
    u8 pad12[6];
    s32 owner;      /* 0x18 */
    f32* cur;       /* 0x1c */
    s32 a0, a1, a2, a3; /* 0x20 */
    Rec* work;      /* 0x30 */
} Cmd_80208774;
extern char lbl_802D5280[], lbl_802D52A0[];
typedef struct Rec_80208A20 {
    u32 kind;       /* 0x00 */
    u8 pad04[0x14];
    u16 n;          /* 0x18 */
    u8 pad1a[2];
    s32 i1c, i20; f32 f24, f28, f2c, f30;
    s32 i34;
    u8 pad38[0x44 - 0x38];
} Rec_80208A20;
typedef struct Cmd_80208A20 {
    s32 kind;       /* 0x00 */
    u8 pad04[4];
    s32 handle;     /* 0x08 */
    u8 pad0c[4];
    s16 cnt;        /* 0x10 */
    u8 pad12[6];
    s32 owner;      /* 0x18 */
    f32* cur;       /* 0x1c */
    s32 a0, a1, a2, a3; /* 0x20 */
    Rec_80208A20* work;      /* 0x30 */
} Cmd_80208A20;
extern char lbl_802D52E8[], lbl_802D5308[];
typedef struct Rec_80208C08 {
    u32 kind;       /* 0x00 */
    u8 pad04[0x14];
    u16 n;          /* 0x18 */
    u8 pad1a[2];
    s32 i1c; f32 f20, f24, f28, f2c, f30;
    s32 i34;
    u8 pad38[0x44 - 0x38];
} Rec_80208C08;
typedef struct Cmd_80208C08 {
    s32 kind;       /* 0x00 */
    u8 pad04[4];
    s32 handle;     /* 0x08 */
    u8 pad0c[4];
    s16 cnt;        /* 0x10 */
    u8 pad12[6];
    s32 owner;      /* 0x18 */
    f32* cur;       /* 0x1c */
    s32 a0, a1, a2, a3; /* 0x20 */
    Rec_80208C08* work;      /* 0x30 */
} Cmd_80208C08;
extern char lbl_802D532C[], lbl_802D5348[];
typedef struct Rec_80208D9C {
    u32 kind;       /* 0x00 */
    u8 pad04[0x14];
    u16 n;          /* 0x18 */
    u8 pad1a[2];
    s32 i1c; f32 f20, f24, f28, f2c, f30;
    s32 i34;
    u8 pad38[0x44 - 0x38];
} Rec_80208D9C;
typedef struct Cmd_80208D9C {
    s32 kind;       /* 0x00 */
    u8 pad04[4];
    s32 handle;     /* 0x08 */
    u8 pad0c[4];
    s16 cnt;        /* 0x10 */
    u8 pad12[6];
    s32 owner;      /* 0x18 */
    f32* cur;       /* 0x1c */
    s32 a0, a1, a2, a3; /* 0x20 */
    Rec_80208D9C* work;      /* 0x30 */
} Cmd_80208D9C;
extern char lbl_802D536C[], lbl_802D5384[];
typedef struct Rec_802097C0 {
    u32 kind;       /* 0x00 */
    u8 pad04[0x14];
    u16 n;          /* 0x18 */
    u8 pad1a[2];
    s32 i1c, i20; f32 f24, f28, f2c, f30;
    s32 i34;
    u8 pad38[0x44 - 0x38];
} Rec_802097C0;
typedef struct Cmd_802097C0 {
    s32 kind;       /* 0x00 */
    u8 pad04[4];
    s32 handle;     /* 0x08 */
    u8 pad0c[4];
    s16 cnt;        /* 0x10 */
    u8 pad12[6];
    s32 owner;      /* 0x18 */
    f32* cur;       /* 0x1c */
    s32 a0, a1, a2, a3; /* 0x20 */
    Rec_802097C0* work;      /* 0x30 */
} Cmd_802097C0;
extern char lbl_802D544C[], lbl_802D5468[];
typedef struct Rec_80209974 {
    u32 kind;       /* 0x00 */
    u8 pad04[0x14];
    u16 n;          /* 0x18 */
    u16 n2;         /* 0x1a */
    f32 f1c, f20, f24;
    s32 i28;
    u8 pad2c[0x44 - 0x2c];
} Rec_80209974;
typedef struct Cmd_80209974 {
    s32 kind;       /* 0x00 */
    u8 pad04[4];
    s32 handle;     /* 0x08 */
    u8 pad0c[4];
    s16 cnt;        /* 0x10 */
    u8 pad12[6];
    s32 owner;      /* 0x18 */
    f32* cur;       /* 0x1c */
    s32 a0, a1, a2, a3; /* 0x20 */
    Rec_80209974* work;      /* 0x30 */
} Cmd_80209974;
extern char lbl_802D548C[], lbl_802D54A8[];
typedef struct Rec_80209D74 {
    u32 kind;       /* 0x00 */
    u8 pad04[0x14];
    u16 n;          /* 0x18 */
    u16 n2;         /* 0x1a */
    f32 f1c, f20, f24;
    s32 i28;
    u8 pad2c[0x44 - 0x2c];
} Rec_80209D74;
typedef struct Cmd_80209D74 {
    s32 kind;       /* 0x00 */
    u8 pad04[4];
    s32 handle;     /* 0x08 */
    u8 pad0c[4];
    s16 cnt;        /* 0x10 */
    u8 pad12[6];
    s32 owner;      /* 0x18 */
    f32* cur;       /* 0x1c */
    s32 a0, a1, a2, a3; /* 0x20 */
    Rec_80209D74* work;      /* 0x30 */
} Cmd_80209D74;
extern char lbl_802D5504[], lbl_802D5520[];
typedef struct Rec_80209ED8 {
    u32 kind;       /* 0x00 */
    u8 pad04[0x14];
    u16 n;          /* 0x18 */
    u16 n2;         /* 0x1a */
    f32 f1c, f20, f24;
    s32 i28;
    u8 pad2c[0x44 - 0x2c];
} Rec_80209ED8;
typedef struct Cmd_80209ED8 {
    s32 kind;       /* 0x00 */
    u8 pad04[4];
    s32 handle;     /* 0x08 */
    u8 pad0c[4];
    s16 cnt;        /* 0x10 */
    u8 pad12[6];
    s32 owner;      /* 0x18 */
    f32* cur;       /* 0x1c */
    s32 a0, a1, a2, a3; /* 0x20 */
    Rec_80209ED8* work;      /* 0x30 */
} Cmd_80209ED8;
extern char lbl_802D54CC[], lbl_802D5544[];
typedef struct {
    u32 kind;       /* 0x00 */
    u8 pad04[4];
    void* x08;      /* 0x08 */
} Work_8020A938;
typedef struct {
    u8 pad00[8];
    s32 handle;     /* 0x08 */
    u8 pad0c[4];
    s16 cnt;        /* 0x10 */
    u8 pad12[10];
    s32* cursor;    /* 0x1C */
    s32 a20;
    s32 a24;
    s32 a28;
    s32 a2c;
    Work_8020A938* work;     /* 0x30 */
} Script_8020A938;
typedef struct {
    u32 kind;       /* 0x00 */
    u8 pad04[4];
    void* x08;      /* 0x08 */
} Work_8020AE04;
typedef struct {
    u8 pad00[8];
    s32 handle;     /* 0x08 */
    u8 pad0c[4];
    s16 cnt;        /* 0x10 */
    u8 pad12[10];
    s32* cursor;    /* 0x1C */
    s32 a20;
    s32 a24;
    s32 a28;
    s32 a2c;
    Work_8020AE04* work;     /* 0x30 */
} Script_8020AE04;
extern void* fn_8020AF8C(s32 id);
typedef struct {
    u32 kind;       /* 0x00 */
    u8 pad04[4];
    void* x08;      /* 0x08 */
} Work_8020B4AC;
typedef struct {
    u8 pad00[8];
    s32 handle;     /* 0x08 */
    u8 pad0c[4];
    s16 cnt;        /* 0x10 */
    u8 pad12[10];
    f32* cursor;    /* 0x1C */
    s32 a20;
    s32 a24;
    s32 a28;
    s32 a2c;
    Work_8020B4AC* work;     /* 0x30 */
} Script_8020B4AC;

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
        fn_80210CE4();
        fn_801F7500();
        lbl_8030CEA0.x15cc = 0;
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
extern u32 fn_802107A4(ScptArgs *s, u16 id);
extern u32 fn_80210860(ScptArgs *s, u16 id);
void fn_80207738(s32 a, s32 b)
{
    ScptArgs s;
    s32 i;

    for (i = 0; i < 256; i++) {
        if (lbl_8030CEA0.ent[i][0] != 0) {
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
        if (lbl_8030CEA0.ent[i][0] != 0) {
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
        if (lbl_8030CEA0.ent[i][0] != 0) {
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
        lbl_8030CEA0.x157c = r;
    } else {
        lbl_8030CEA0.x157c = 0;
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
    s32 flag;
    s32 pad10;
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

s32 fn_801F593C(s32 unused, CmdB *c) {
    f32 *p;
    p = c->cur;
    p++;
    {
        s32 v = ReadInt(&p);
        c->cur = p;
        fn_801EFF0C(v);
    }
    return 0;
}

s32 fn_801F8608(u32 flags, Script801F8* s) {
    Work801F8* w;
    f32* cur;
    u16 f = flags;
    s32 v;
    if (f & 1) {
        cur = s->cursor;
        w = fn_801E1A2C(1, 0x44);
        if (w == NULL) fn_801DBE1C("scptPlayMO3: malloc failed");
        s->work = w;
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
        w->kind = 0;
        fn_80211058(s, 6, w->n, 0x25, lbl_8030CEA0.x08, w);
        s->cursor = cur;
    }
    if (f & 2) {
        w = s->work;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("PlayMO3: message post time out");
        } else if (w->kind == 2) {
            return 0;
        }
    }
    if (f & 8) return 1;
    return 1;
}

s32 fn_801FC184(u32 flags, Script801FC* s) {
    Work801FC* w;
    f32* cur;
    u16 f = flags;
    if (f & 1) {
        cur = s->cursor;
        cur = cur + 1;
        w = fn_801E1A2C(1, 0x44);
        if (w == NULL) fn_801DBE1C("scptRollP: malloc failed");
        s->work = w;
        w->n = ReadInt(&cur);
        w->x1c = fn_801F6120(&cur);
        w->x20 = fn_801F6120(&cur);
        w->x24 = fn_801F6120(&cur);
        w->x28 = ReadInt(&cur);
        w->x2c = ReadInt(&cur);
        w->x30 = ReadInt(&cur);
        w->x34 = fn_801F6120(&cur);
        s->cursor = cur;
        if (f & 4) {
            if (fn_800CCC48(6, w->n) != 0) {
                fn_801E1784(w);
                return 0;
            }
        }
        w->kind = 0;
        fn_80211058((void *)(s), 6, w->n, 0xb, lbl_8030CEA0.x08, (void *)(w));
    }
    if (f & 2) {
        w = s->work;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("scptRollP: message post time out");
        } else if (w->kind == 2) {
            return 0;
        }
    }
    if (f & 8) return 1;
    return 1;
}

s32 fn_801FC408(u32 flags, Script801FC* s) {
    Work801FC* w;
    f32* cur;
    u16 f = flags;
    if (f & 1) {
        cur = s->cursor;
        cur = cur + 1;
        w = fn_801E1A2C(1, 0x44);
        if (w == NULL) fn_801DBE1C("scptRollA: malloc failed");
        s->work = w;
        w->n = ReadInt(&cur);
        w->x1c = fn_801F6120(&cur);
        w->x20 = fn_801F6120(&cur);
        w->x24 = fn_801F6120(&cur);
        w->x28 = ReadInt(&cur);
        w->x2c = ReadInt(&cur);
        w->x30 = ReadInt(&cur);
        w->x34 = fn_801F6120(&cur);
        s->cursor = cur;
        if (f & 4) {
            if (fn_800CCC48(6, w->n) != 0) {
                fn_801E1784(w);
                return 0;
            }
        }
        w->kind = 0;
        fn_80211058((void *)(s), 6, w->n, 0xa, lbl_8030CEA0.x08, (void *)(w));
    }
    if (f & 2) {
        w = s->work;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("scptRollA: message post time out");
        } else if (w->kind == 2) {
            return 0;
        }
    }
    if (f & 8) return 1;
    return 1;
}

s16 fn_8020660C(u16 f, Script8020* s) {
    f32 d, a1, a2, a3, b1, b2, b3, c, e, g, h;
    f32* cur;
    s32 i;
    if (f & 1) {
        cur = s->cursor;
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
        s->cursor = cur;
        fn_80097294(6);
        if (a1 != 3.4028235e38f) fn_80097270(a1, a2, a3);
        if (b1 != 3.4028235e38f) fn_8009724C(b1, b2, b3);
        fn_800971C4(c);
        fn_800971E0((s32)d, 0, 0);
        if (e == 0.0f) fn_80097150(0);
        if (e == 1.0f) fn_80097150(0x8000);
        if (g != 3.4028235e38f) fn_80097118(g);
        if (h != 3.4028235e38f) fn_800970FC(h);
        if (i == 0) fn_80097318(1);
        else fn_80097318(0);
    }
    return (f >> 3) & 1;
}

s32 fn_80209548(u32 flags, Script80209548* s) {
    Work8020* w;
    f32* cur;
    u16 f = flags;
    if (f & 1) {
        cur = s->cursor + 1;
        w = fn_801E1A2C(1, 0x44);
        if (w == NULL) fn_801DBE1C("Proll: malloc failed");
        s->work = w;
        w->n = ReadInt(&cur);
        w->x1c = ReadInt(&cur);
        w->x20 = fn_801F6120(&cur);
        w->x24 = fn_801F6120(&cur);
        w->x28 = fn_801F6120(&cur);
        w->x38 = ReadInt(&cur);
        w->x3c = ReadInt(&cur);
        s->cursor = cur;
        if (w->x38 == 0x7fffffff) w->x38 = 0;
        if (w->x1c == 0x7fffffff) w->x1c = 0;
        w->kind = 0;
        fn_80211058((void *)(s), 6, w->n, 0x22, lbl_8030CEA0.x08, (void *)(w));
    }
    if (f & 2) {
        w = s->work;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("Proll: message post timed out");
        } else if (w->kind == 2) {
            return 0;
        }
    }
    if (f & 8) return 1;
    return 1;
}

inline s32 FlagTest(u32 b) {
    return (lbl_80310B3C[b >> 5] & (1 << (b & 31))) != 0;
}


s32 fn_8020CBA4(u32 flags, Script8020C* s) {
    extern void fn_8020EEE8(s32 a, s32 b, s32 c, s32 d);
    f32* cur;
    s32 a;
    s32 b;
    s32 id;
    f32 v[3];
    f32 t;
    Actor8020C* act;
    u32 bit;
    if (flags & 1) {
        cur = s->cursor;
        cur = cur + 1;
        a = ReadInt(&cur);
        b = ReadInt(&cur);
        s->cursor = cur;
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
        fn_8025CB24(lbl_803146A8, "\h(\x81\x40)You received %s [1]!\c", fn_801F4AE4((s16)id));
        fn_8021026C(lbl_803146A8);
        fn_801EFF0C((s16)id);
        lbl_8030CEA0.stack[++lbl_8030CEA0.sp] = s->cursor;
        s->cursor = (f32*)&lbl_802F7848;
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

s32 fn_8020CEB4(u32 flags, CmdF *c)
{
    u16 f = flags;
    float *p;
    u32 n, i;
    s32 v;
    Obj *o;
    s32 *src;
    if (flags & 1) {
        p = c->cur;
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
        c->cur = p;
    }
    if (f & 8) {
        return 1;
    }
    return 0;
}

s32 fn_80213FE8(u32 flags, CmdF *c)
{
    float *p;
    Args b;
    if (flags & 1) {
        p = c->cur;
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
        c->cur = p;
        fn_80155994(&b);
        return 0;
    }
    return 1;
}


s32 fn_801F58B8(s32 unused, Cmd *c) {
    f32 *p;
    p = c->cur;
    p++;
    {
        s32 v = ReadInt(&p);
        c->cur = p;
        fn_801EFC88(v);
    }
    return 0;
}

s32 fn_801F5EB4(s32 unused, CmdB_801F5EB4 *st) {
    float *p = st->cur;
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
    st->cur = p;
    return 0;
}

s32 fn_801F6044(s32 unused, CmdB_801F6044 *st) {
    float *p = st->cur;
    p++;
    if (fn_801F6120(&p) == 0.0f) {
        p = (float *)((u8 *)p + (*(u32 *)p & ~3u));
        st->cur = p;
        return 0;
    }
    p++;
    st->cur = p;
    return 0;
}

s16 fn_801F984C(u32 flags, CmdB_801F984C *st) {
    u16 f = flags;
    if (flags & 1) {
        float *p = st->cur + 1;
        s32 n;
        if (*p == 3.4028235e38f) {
            p++;
            n = 0x7FFFFFFF;
        } else {
            n = (s32)fn_801F6120(&p);
        }
        st->cur = p;
        if ((u32)n >= 3) {
            fn_80217830(n);
        }
    }
    return (f >> 3) & 1;
}

s32 fn_801FD850(u32 flags, CmdB_801FD850 *st) {
    u16 f = flags;
    if (flags & 1) {
        float *p = st->cur + 1;
        s32 n;
        if (*p == 3.4028235e38f) {
            p++;
            n = 0x7FFFFFFF;
        } else {
            n = (s32)fn_801F6120(&p);
        }
        fn_8016D904(n);
        st->cur = p;
    }
    if (f & 8) return 1;
    return 0;
}

s32 fn_801FDC70(u32 flags, CmdB_801FDC70 *st) {
    if (flags & 1) {
        float *p = st->cur + 1;
        if (*p == 3.4028235e38f) {
            p++;
        } else {
            fn_801F6120(&p);
        }
        st->cur = p;
    }
    return 0;
}

s32 fn_801FDE70(u32 flags, CmdB_801FDE70 *st) {
    u16 f = flags;
    if (flags & 1) {
        float a[4];
        float *p = st->cur + 1;
        a[0] = fn_801F6120(&p);
        a[1] = fn_801F6120(&p);
        a[2] = fn_801F6120(&p);
        a[3] = fn_801F6120(&p);
        st->cur = p;
        fn_801E749C(a);
    }
    if (f & 8) return 1;
    return 0;
}

s32 fn_801FED58(u32 flags, CmdStream_801FED58 *st) {
    u16 f = flags;
    if (flags & 1) {
        u8 *c = st->cur;
        st->cur = c + 4;
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

s32 fn_801FEE54(u32 flags, CmdB_801FEE54 *st) {
    if (flags & 1) {
        float *p = st->cur + 1;
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
            st->cur = p;
            fn_80216E38(n, q + w);
        }
    }
    return 0;
}

s32 fn_801FFDB4(u32 flags, CmdB_801FFDB4 *st) {
    if (flags & 1) {
        float *p = st->cur + 1;
        s32 n;
        if (*p == 3.4028235e38f) {
            p++;
            n = 0x7FFFFFFF;
        } else {
            n = (s32)fn_801F6120(&p);
        }
        fn_800D2C44((u16)n);
        st->cur = p;
    }
    return 0;
}

s16 fn_80204F04(u32 flags, CmdB_80204F04 *st) {
    u16 f = flags;
    if (flags & 1) {
        float *p = st->cur;
        float v;
        p++;
        v = fn_801F6120(&p);
        st->cur = p;
        if (v == 3.4028235e38f) {
            fn_8022D34C(1, 60.0f);
        } else {
            fn_8022D34C(1, v);
        }
    }
    return (f >> 3) & 1;
}

s32 fn_802073B4(u32 flags, CmdStream_802073B4 *st) {
    u16 f = flags;
    if (flags & 1) {
        u8 *c = st->cur;
        u32 w = *(u32 *)(c + 4);
        u8 *q = c + 4;
        fn_801002D0(q + w);
        st->cur = q + 4;
    }
    if (f & 8) return 1;
    return 0;
}

s32 fn_80207428(u32 flags, CmdStream_80207428 *st) {
    u16 f = flags;
    if (flags & 1) {
        u8 *c = st->cur;
        u32 w = *(u32 *)(c + 4);
        u8 *q = c + 4;
        fn_801002D0(q + w);
        st->cur = q + 4;
        fn_801F7B04(0x9C40);
        lbl_80347474 = 1;
    }
    if (f & 8) return 1;
    return 0;
}

void fn_80210338(void)
{
    if (lbl_8030CEA0.xc5c != 0) {
        if (lbl_8030CEA0.xc60 & 0xFF000000) {
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

s32 fn_80214AA0(s32 flags, Obj80214 *obj)
{
    float *cur;
    s32 r;

    if (flags & 1) {
        cur = obj->x1c;
        cur++;
        if (*cur == 3.4028235e38f) {
            cur++;
            r = 0x7fffffff;
        } else {
            r = (s32)fn_801F6120(&cur);
        }
        obj->x1c = cur;
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

s32 fn_801F5D08(s32 unused, CmdB_801F5D08 *st) {
    float *p = st->cur;
    s16 idx;
    f32 v;
    p++;
    idx = (s16)(*(u32 *)p - 0x40000000);
    v = fn_801F6120(&p);
    lbl_8030CEA0.x1674[idx] = v;
    st->cur = p;
    return 0;
}

void fn_801F7B04(s32 v) {
    lbl_8030CEA0.x1580 = v;
}

s32 fn_801FD1D0(u32 flags, CmdB_801FD1D0 *st) {
    if (flags & 1) {
        float *p = st->cur + 1;
        s32 n;
        if (*p == 3.4028235e38f) {
            p++;
            n = 0x7FFFFFFF;
        } else {
            n = (s32)fn_801F6120(&p);
        }
        st->cur = p;
        lbl_8030CEA0.x82c = 2;
        lbl_8030CEA0.x834 = n;
    }
    return 0;
}

s16 fn_8020A2C8(u32 flags, CmdStream_8020A2C8 *st) {
    u16 f = flags;
    u8 *c = st->cur;
    if (flags & 1) {
        s32 v;
        st->cur = c + 4;
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
    ScptArgs s;

    if (fn_802107A4(&s, (u16)id) == 0) {
        return 0;
    }
    s.owner = 0x29;
    s.kind = 1;
    s.args = 0;
    *(s16 *)((u8 *)&s + 0x10) = 0;
    fn_80210F74(&s);
    return 1;
}

s32 fn_80210064(s32 id)
{
    ScptArgs s;

    if (fn_80210860(&s, (u16)id) == 0) {
        return 0;
    }
    s.owner = 0x1a;
    s.kind = 1;
    s.args = 0;
    *(s16 *)((u8 *)&s + 0x10) = 0;
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
        u8 *base = lbl_8030CEA0.x10;
        CtlEnt *e = (CtlEnt *)(base + i * 0x34);
        if (e->kind == 1 && lbl_802F7940[e->idx].v == 0xfffe) {
            fn_80210B44(i);
        }
    }
}

s32 fn_80205E48(u32 a0, CmdStream_80205E48 *st) {
    s32 n;
    u16 a = a0;
    if (a0 & 1) {
        f32 *p = st->cur;
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
        st->cur = p;
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
            CtlEnt_80210EA4 *e = (CtlEnt_80210EA4 *)(lbl_8030CEA0.x10 + i * 0x34);
            if (e->x20 == 6 || e->x20 == 9) {
                if ((u16)id == (u16)e->x24 && v == lbl_802F7940[e->idx].v) {
                    fn_80210B44(i);
                }
            }
        }
    }
}

s32 fn_802137D0(u32 flags, CmdB *c)
{
    f32 *p;
    s32 *list;
    s32 i;
    s32 n;

    if (flags & 1) {
        p = c->cur;
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
        c->cur = p;
        return 0;
    }
    return 1;
}

s32 fn_801FDCDC(u32 flags, CmdB_801FDCDC *st) {
    s32 n;
    u16 f = flags;
    if (flags & 1) {
        float *p = st->cur + 1;
        if (*p == 3.4028235e38f) {
            p++;
            n = 0x7FFFFFFF;
        } else {
            n = (s32)fn_801F6120(&p);
        }
        st->cur = p;
        fn_801BEA70(lbl_8034759C, n, fn_8020E984());
    }
    if ((f & 2) && lbl_803473C0 == 0) return 0;
    if (f & 8) return 0;
    return 1;
}

s32 fn_80213920(u32 flags, CmdB_80213920 *st) {
    if (flags & 1) {
        float *p = st->cur;
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
        st->cur = p;
        return 0;
    }
    return 1;
}

s32 fn_80214C04(u32 flags, CmdB_80214C04 *st) {
    if (flags & 1) {
        float *p = st->cur;
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
        st->cur = p;
        fn_80147DC8(a, b);
        return 0;
    }
    return 1;
}

s16 fn_80204E28(u32 a0, CmdStream *st) {
    u32 n;
    u16 a = a0;
    f32 x;
    if (a0 & 1) {
        u8 *p = st->cur + 4;
        x = fn_801F6120((f32**)&p);
        if (3.4028235e38f == *(f32 *)p) {
            p += 4;
            n = 0x7fffffff;
        } else {
            n = (s32)fn_801F6120((f32**)&p);
        }
        st->cur = p;
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

s32 fn_801F570C(u32 flags, CmdB_801F570C *cmd)
{
    u16 f = flags;
    if (flags & 1) {
        float *p = cmd->cur;
        p++;
        lbl_803477A8 = RDI(p);
        cmd->w04 = 0;
        cmd->cur = p;
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

s32 fn_801F5F50(u32 flags, CmdB_801F5F50 *st) {
    float *p;
    u8 *def = NULL;
    u32 n;
    u32 cnt;
    u32 i;
    p = st->cur;
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
            st->cur = p;
            return 0;
        } else {
            p += 2;
        }
    }
    st->cur = def != NULL ? (float *)def : p;
    return 0;
}

s16 fn_8020B9EC(u16 flags, CmdB_8020B9EC *st) {
    if (flags & 1) {
        float *p = st->cur + 1;
        s32 i = RDI(p);
        st->cur = p;
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

s32 fn_801F934C(u32 flags, CmdB_801F934C *st) {
    s32 n;
    u16 f = flags;
    if (flags & 1) {
        float *p = st->cur + 1;
        if (*p == 3.4028235e38f) {
            p++;
            n = 0x7FFFFFFF;
        } else {
            n = (s32)fn_801F6120(&p);
        }
        st->cur = p;
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

s32 fn_801FA290(u32 flags, CmdB_801FA290 *st) {
    u16 f = flags;
    if (flags & 1) {
        float *p = st->cur + 1;
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
        st->cur = p;
    }
    if (f & 8) {
        return 1;
    }
    return 0;
}

s32 fn_80207630(u32 flags, CmdB_80207630 *st) {
    if (flags & 1) {
        float *p = st->cur;
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
        st->cur = p;
    }
    return 0;
}

s16 fn_802057E0(u32 flags, CmdB_802057E0 *st) {
    u16 f = flags;
    if (flags & 1) {
        float *p = st->cur;
        s8 a;
        s32 b;
        fn_801F7500();
        p++;
        a = RDI(p);
        b = RDI(p);
        st->cur = p;
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

s32 fn_801FA398(u16 flags, CmdB_801FA398 *c)
{
    float *p;
    s8 a;
    s8 b;
    if (flags & 1) {
        p = c->cur + 1;
        a = RDI(p);
        b = RDI(p);
        RDI(p);
        c->cur = p;
        fn_80218570(0, a, b);
    }
    if (flags & 8) {
        return 1;
    }
    return 0;
}

s16 fn_802058F8(u32 a0, CmdStream *st) {
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
        fn_800972E0(0);
        if (n == 0) {
            fn_80097318(1);
        } else {
            fn_80097318(0);
        }
    }
    return (a >> 3) & 1;
}

s32 fn_801FEF80(u32 flags, Cmd *c) {
    float *p;
    u16 a;
    s32 t;
    s32 b;
    if (flags & 1) {
        p = c->cur + 1;
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
        fn_80225CAC(0xffff, a, b);
    }
    return 0;
}

s32 fn_80204BE8(u16 flags, Cmd *c) {
    float *p;
    f32 a[3];
    f32 b[3];
    if (flags & 1) {
        p = c->cur;
        fn_801F7500();
        p++;
        a[0] = fn_801F6120(&p);
        a[1] = fn_801F6120(&p);
        a[2] = fn_801F6120(&p);
        b[0] = fn_801F6120(&p);
        b[1] = fn_801F6120(&p);
        b[2] = fn_801F6120(&p);
        c->cur = p;
        lbl_8030CEA0.x18fc = a[0];
        lbl_8030CEA0.x1900 = a[1];
        lbl_8030CEA0.x1904 = a[2];
        fn_80213478(b, a, &lbl_8030CEA0.x1908);
    }
    if (flags & 8) return 1;
    return 0;
}

s32 fn_8020D1C0(u16 flags, Cmd *c) {
    float *p;
    s32 a, b;
    if (flags & 1) {
        p = c->cur + 1;
        a = RDI(p);
        b = RDI(p);
        fn_801000F0(a, b);
        c->cur = p;
    }
    if (flags & 8) return 1;
    return 0;
}

s32 fn_8020A048(u32 flags, Cmd *c) {
    float *p;
    s32 a;
    f32 x;
    f32 y;
    f32 z;
    f32 w;
    u16 fl = flags;
    p = c->cur;
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
        c->cur = p;
    }
    if (fl & 8) {
        return 1;
    }
    return 0;
}

s32 fn_8020170C(u16 flags, Cmd_8020170C *c) {
    float *p;
    u32 t;
    if (flags & 1) {
        p = c->cur;
        p++;
        if (*p == 3.4028235e38f) {
            p++;
            t = 0x7FFFFFFF;
        } else {
            t = (s32)fn_801F6120(&p);
        }
        c->cur = p;
        c->x30 = 0;
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
        if (c->x30 != 0) {
            if (lbl_80347508 == 0) {
                c->x30 = 0;
                return 0;
            }
        } else {
            c->x30 = 1;
        }
    }
    if (flags & 8) {
        c->x30 = 0;
        return 0;
    }
    return 1;
}

s32 fn_801FD584(u32 flags, Cmd* c) {
    float* p;
    s32 t;
    Obj10A* o;
    if (flags & 1) {
        p = c->cur + 1;
        RDI(p);
        t = RDI(p);
        c->cur = p;
        o = fn_8010A164(t);
        if (o == 0) {
            fn_801DBE1C(lbl_802D4D7C, t);
        }
        fn_8015F654(o->x24);
        return 0;
    }
    return 1;
}

s32 fn_801FF380(u32 flags, CmdB *cmd)
{
    if (flags & 1) {
        float *p;
        s32 a, b;
        Obj10A* c;
    Mid* m;
        p = cmd->cur + 1;
        a = RDI(p);
        b = RDI(p);
        cmd->cur = p;
        c = fn_8010A164(b);
        if (c != 0 && (m = c->x24) != 0 && m->b26c == 1) {
            m->sub->x1a0 = a;
        }
    }
    return 0;
}

s32 fn_801FE21C(u16 flags, CmdB_801FE21C *st) {
    s32 i;
    if (flags & 1) {
        float *p = st->cur + 1;
        i = (*p == 3.4028235e38f) ? (p++, 0x7FFFFFFF) : (s32)fn_801F6120(&p);
        st->cur = p;
        lbl_8030CEA0.x1584[i] = (s32)(9999.0f * (3.0517578e-05f * (f32)fn_8025ECC4()));
    }
    if (flags & 8) {
        return 1;
    }
    return 0;
}

s16 fn_80200CE4(u32 flags, CmdB_80200CE4 *st) {
    s32 n;
    u16 f = flags;
    if (flags & 1) {
        float *p = st->cur + 1;
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
        st->cur = p;
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

s32 fn_80200FC4(u32 flags, Cmd_80200FC4 *st) {
    if (flags & 1) {
        float *p = st->cur + 1;
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
        st->cur = p;
        fn_800D2554(f2, f4);
        fn_800D25C4(rgb, d);
        fn_800D258C(e, f1, f3);
        fn_800D2CA8(1);
    }
    return 0;
}

s32 fn_80201228(u32 flags, Cmd_80201228 *st) {
    if (flags & 1) {
        float *p = st->cur + 1;
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
        st->cur = p;
        fn_800D2554(0.0f, 1.0f);
        fn_800D25C4(rgb, d);
        fn_800D258C(e, f1, f2);
        fn_800D2CA8(1);
    }
    return 0;
}

s32 fn_80202004(u32 flags, Script_80202004* s)
{
    Work_80202004* w;
    f32* p;
    u16 f = flags;
    if (f & 1) {
        p = s->cursor;
        p++;
        w = fn_801E1A2C(1, 0x44);
        if (w == NULL) fn_801DBE1C("scptHclose: malloc failed");
        s->work = w;
        w->x18 = RDI(p);
        w->x1c = 0;
        w->x20 = RDI(p);
        s->cursor = p;
        w->kind = 0;
        fn_802110E8(s, 7, w->x18, 1, lbl_8030CEA0.x08, w);
    }
    if (f & 2) {
        w = s->work;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("scptHclose: message post time out");
        } else if (w->kind == 2) {
            return 0;
        }
    }
    return !(f & 8);
}

s16 fn_802049BC(u16 a, CmdStream_802049BC *st) {
    if (a & 1) {
        f32 *cur = st->cur;
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
        st->cur = cur;
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

s32 fn_80204CD0(u16 a, CmdStream_80204CD0 *st) {
    if (a & 1) {
        f32 *cur = st->cur;
        f32 f0, f1, f2, f3, f4, f5;
        fn_801F7500();
        cur++;
        f0 = fn_801F6120(&cur);
        f1 = fn_801F6120(&cur);
        f2 = fn_801F6120(&cur);
        f3 = fn_801F6120(&cur);
        f4 = fn_801F6120(&cur);
        f5 = fn_801F6120(&cur);
        st->cur = cur;
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

s32 fn_80204F8C(u32 flags, Script* s)
{
    Lerp* w;
    f32* p;
    f32 a[3];
    s32 n;
    s32 d[3];
    u32 f = flags & 0xffff;
    if (f & 1) {
        p = s->cursor;
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
        s->cursor = p;
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
        s->work = w;
    }
    if (f & 2) {
        w = s->work;
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

s32 fn_8020549C(u32 flags, Script* s)
{
    Lerp* w;
    f32* p;
    s32 n;
    u32 f = flags & 0xffff;
    s32 d0, d1, d2;
    if (f & 1) {
        p = s->cursor;
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
        s->cursor = p;
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
        s->work = w;
    }
    if (f & 2) {
        w = s->work;
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

s16 fn_80205A3C(u16 a, CmdStream_80205A3C *st) {
    if (a & 1) {
        f32 *cur = st->cur;
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
        st->cur = cur;
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

s32 fn_802060D4(u16 a, CmdStream_802060D4 *st) {
    if (a & 1) {
        s32 id;
        s32 v;
        f32 f;
        f32 *cur = st->cur;
        fn_801F7500();
        cur++;
        id = (u16)RDI(cur);
        v = RDI(cur);
        if (v == 0x7fffffff) {
            v = 100;
        }
        st->cur = cur;
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

s16 fn_80206904(u16 a, CmdStream_80206904 *st) {
    if (a & 1) {
        f32 *cur = st->cur;
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
        st->cur = cur;
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

s16 fn_80206AB0(u16 a, CmdStream_80206AB0 *st) {
    if (a & 1) {
        f32 *cur = st->cur;
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
        st->cur = cur;
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

s16 fn_80206CBC(u16 a, CmdStream_80206CBC *st) {
    if (a & 1) {
        f32 *cur = st->cur;
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
        st->work = w;
        st->cur = cur;
        st->x20 = 2;
        st->x04 = 0;
        return 1;
    }
    if (a & 2) {
        Eff *w;
        if (--st->x20 == 0) {
            w = st->work;
            st->x20 = 0;
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

s16 fn_80206EA8(u16 a, CmdStream_80206EA8 *st) {
    if (a & 1) {
        f32 *cur = st->cur;
        s32 v;
        u16 id;
        f32 f;
        fn_801F7500();
        lbl_80310B3C[34] |= 2;
        cur++;
        id = RDI(cur);
        f = fn_801F6120(&cur);
        v = RDI(cur);
        st->cur = cur;
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

s32 fn_8020A168(u16 flags, Cmd_8020A168* c)
{
    f32* p = c->cur;
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
        c->cur = p;
    }
    if (flags & 8) {
        return 1;
    }
    return 0;
}

s32 fn_8020B670(u32 flags, Script_8020B670* s)
{
    f32 pos[3];
    u32 ids[3];
    f32* p;
    u16 f = flags;
    if (f & 1) {
        p = s->cursor + 1;
        pos[0] = fn_801F6120(&p);
        pos[1] = fn_801F6120(&p);
        pos[2] = fn_801F6120(&p);
        ids[0] = RDI(p);
        ids[1] = RDI(p);
        ids[2] = RDI(p);
        s->cursor = p;
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

s32 fn_80213DD0(u32 flags, Cmd *c) {
    float *p;
    s32 v[7];
    if (flags & 1) {
        p = c->cur;
        p++;
#define RD(k) v[k] = (*p == 3.4028235e38f ? (p++, 0x7FFFFFFF) : (s32)fn_801F6120(&p));
        RD(0) RD(1) RD(2) RD(3) RD(4) RD(5) RD(6)
        c->cur = p;
        fn_801558B0(v);
        return 0;
    }
    return 1;
}

s32 fn_80215444(u32 flags, Cmd *c) {
    float *p;
    Pair8 v;
    s32 i;
    if (flags & 1) {
        p = c->cur;
        p++;
        v.a = RDI(p);
        for (i = 0; i < 8; i++) {
            v.b[i] = RDI(p);
            v.c[i] = RDI(p);
        }
        c->cur = p;
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

s16 fn_801F7D2C(u16 flags, Cmd_801F7D2C* c)
{
    if (flags & 1) {
        f32* p = c->cur + 1;
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
        c->cur = p;
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

s32 fn_801F7F98(u16 flags, Cmd_801F7F98* c)
{
    if (flags & 1) {
        f32* p = c->cur;
        Fx* fx;
        p++;
        fx = fn_801E1A2C(1, 0x44);
        c->x30 = fx;
        fx->x18 = ReadInt(&p);
        fx->x1c = fn_801F6120(&p);
        fx->x20 = fn_801F6120(&p);
        fx->x24 = fn_801F6120(&p);
        fx->x28 = fn_801F6120(&p);
        fx->x2c = fn_801F6120(&p);
        fx->x30 = fn_801F6120(&p);
        fx->x34 = ReadInt(&p);
        c->cur = p;
        fx->x0 = 0;
        fn_80211058(c, 6, fx->x18, 0x2e, lbl_8030CEA0.x08, fx);
    }
    if (flags & 2) {
        Fx* cur = c->x30;
        if (c->x8 == 0) {
            c->x8 = fn_800CD0B8(c->x20, c->x24, c->x28, c->x2c);
            c->x10++;
        } else if (cur->x0 == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_801F8D0C(u16 flags, Cmd_801F8D0C* c)
{
    if (flags & 1) {
        f32* p = c->cur;
        Fx_801F8D0C* fx = fn_801E1A2C(1, 0x44);
        if (fx == 0) {
            fn_801DBE1C(lbl_802D491C);
        }
        c->x30 = fx;
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
        fx->x0 = 0;
        fn_80211058(c, 6, fx->x18, 0x20, lbl_8030CEA0.x08, fx);
        c->cur = p;
    }
    if (flags & 2) {
        Fx_801F8D0C* cur = c->x30;
        if (c->x8 == 0) {
            c->x8 = fn_800CD0B8(c->x20, c->x24, c->x28, c->x2c);
            c->x10++;
            if (c->x10 == 5) {
                fn_801DBE1C(lbl_802D4938);
            }
        } else if (cur->x0 == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_801F8F7C(u16 flags, Cmd_801F8F7C* c)
{
    if (flags & 1) {
        f32* p = c->cur + 1;
        Fx_801F8F7C* fx = fn_801E1A2C(1, 0x44);
        if (fx == 0) {
            fn_801DBE1C(lbl_802D4958);
        }
        c->x30 = fx;
        fx->x18 = ReadInt(&p);
        fx->x1a = ReadInt(&p);
        c->cur = p;
        fx->x0 = 0;
        fn_80211058(c, 6, fx->x1a, 0x1a, lbl_8030CEA0.x08, fx);
    }
    if (flags & 2) {
        Fx_801F8F7C* cur = c->x30;
        if (c->x8 == 0) {
            c->x8 = fn_800CD0B8(c->x20, c->x24, c->x28, c->x2c);
            c->x10++;
            if (c->x10 == 5) {
                fn_801DBE1C(lbl_802D4978);
            }
        } else if (cur->x0 == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_801F9120(u16 flags, Cmd_801F9120* c)
{
    if (flags & 1) {
        f32* p = c->cur + 1;
        Fx_801F9120* fx = fn_801E1A2C(1, 0x44);
        if (fx == 0) {
            fn_801DBE1C(lbl_802D49A0);
        }
        c->x30 = fx;
        fx->x18 = ReadInt(&p);
        fx->x1c = ReadInt(&p);
        fx->x1a = ReadInt(&p);
        fx->x20 = fn_801F6120(&p);
        fx->x24 = fn_801F6120(&p);
        fx->x28 = fn_801F6120(&p);
        fx->x2c = fn_801F6120(&p);
        fx->x30 = fn_801F6120(&p);
        fx->x34 = fn_801F6120(&p);
        c->cur = p;
        fx->x0 = 0;
        fn_80211058(c, 6, fx->x1a, 0x19, lbl_8030CEA0.x08, fx);
    }
    if (flags & 2) {
        Fx_801F9120* cur = c->x30;
        if (c->x8 == 0) {
            c->x8 = fn_800CD0B8(c->x20, c->x24, c->x28, c->x2c);
            c->x10++;
            if (c->x10 == 5) {
                fn_801DBE1C(lbl_802D49BC);
            }
        } else if (cur->x0 == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_801FBBA8(u16 flags, Cmd_801FBBA8* c)
{
    if (flags & 1) {
        f32* p = c->cur;
        Fx_801FBBA8* fx = fn_801E1A2C(1, 0x44);
        if (fx == 0) {
            fn_801DBE1C(lbl_802D4B54);
        }
        c->x30 = fx;
        p++;
        fx->x18 = ReadInt(&p);
        fx->x1c = ReadInt(&p);
        fx->x20 = ReadInt(&p);
        fx->x24 = fn_801F6120(&p);
        fx->x0 = 0;
        fn_80211058(c, 6, fx->x18, 0x12, lbl_8030CEA0.x08, fx);
        c->cur = p;
    }
    if (flags & 2) {
        Fx_801FBBA8* cur = c->x30;
        if (c->x8 == 0) {
            c->x8 = fn_800CD0B8(c->x20, c->x24, c->x28, c->x2c);
            c->x10++;
            if (c->x10 == 5) {
                fn_801DBE1C(lbl_802D4B70);
            }
        } else if (cur->x0 == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_801FDAB8(u16 flags, ScrObj* o) {
    if (flags & 1) {
        f32* p = o->script + 1;
        ScrState* s = fn_801E1A2C(1, 0x44);
        if (s == 0) {
            fn_801DBE1C(lbl_802D4DC0);
        }
        o->st = s;
        s->mode = ReadInt(&p);
        s->count = ReadInt(&p);
        o->script = p;
    }
    if (flags & 2) {
        ScrState* s = o->st;
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

s16 fn_80200B90(u32 flags, Cmd_80200B90 *st) {
    s32 n;
    if (flags & 1) {
        float *p = st->cur + 1;
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
        st->cur = p;
        lbl_8030CEA0.xc70 = 0;
        lbl_8030CEA0.xc88 = 0;
    }
    return 0;
}

s32 fn_80200DF4(u32 flags, Cmd_80200DF4 *st) {
    if (flags & 1) {
        float *p = st->cur + 1;
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
        st->cur = p;
        lbl_8030CEA0.xc68 = 0;
        lbl_8030CEA0.xc84 = 0;
    }
    return 0;
}

s32 fn_8020184C(u32 flags, Script_8020184C* s) {
    u16 f = flags;
    Work_8020184C* w;
    f32* cur;
    if (flags & 1) {
        cur = s->cursor + 1;
        w = fn_801E1A2C(1, 0x44);
        if (w == NULL) fn_801DBE1C("HCLR: malloc failed");
        s->work = w;
        w->kind = 0;
        w->n = ReadInt(&cur);
        w->x1c = (u16)ReadInt(&cur);
        s->cursor = cur;
        fn_80211058(s, 6, w->n, 0x27, lbl_8030CEA0.x08, w);
    }
    if (f & 2) {
        w = s->work;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("HCLR: message post timed out");
        } else if (w->kind == 2) {
            return 0;
        }
    }
    return !(f & 8);
}

s32 fn_802019F8(u32 flags, Script_802019F8* s) {
    u16 f = flags;
    Work_802019F8* w;
    f32* cur;
    if (flags & 1) {
        cur = s->cursor;
        cur = cur + 1;
        w = fn_801E1A2C(1, 0x44);
        if (w == NULL) fn_801DBE1C("scptHset: malloc failed");
        s->work = w;
        w->x18 = ReadInt(&cur);
        w->x20 = 0;
        w->x1c = 0;
        s->cursor = cur;
        w->kind = 0;
        fn_802110E8(s, 7, w->x18, 2, lbl_8030CEA0.x08, w);
    }
    if (f & 2) {
        w = s->work;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("scptHset: message post time out");
        } else if (w->kind == 2) {
            return 0;
        }
    }
    return !(f & 8);
}

s32 fn_80201B6C(u32 flags, Script_80201B6C* s) {
    u16 f = flags;
    Work_80201B6C* w;
    f32* cur;
    if (flags & 1) {
        cur = s->cursor;
        cur = cur + 1;
        w = fn_801E1A2C(1, 0x44);
        if (w == NULL) fn_801DBE1C("scptHSetTask: malloc failed");
        s->work = w;
        w->x18 = ReadInt(&cur);
        w->x20 = 0;
        w->x1c = 0;
        s->cursor = cur;
        w->kind = 0;
        fn_802110E8(s, 7, w->x18, 5, lbl_8030CEA0.x08, w);
    }
    if (f & 2) {
        w = s->work;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("scptHtaskset: message post time out");
        } else if (w->kind == 2) {
            return 0;
        }
    }
    return !(f & 8);
}

s32 fn_80201CE0(u32 flags, Script_80201CE0* s) {
    u16 f = flags;
    Work_80201CE0* w;
    f32* cur;
    if (flags & 1) {
        cur = s->cursor;
        cur = cur + 1;
        w = fn_801E1A2C(1, 0x44);
        if (w == NULL) fn_801DBE1C("scptHread: malloc failed");
        s->work = w;
        w->x18 = ReadInt(&cur);
        w->x20 = 0;
        w->x1c = 0;
        s->cursor = cur;
        w->kind = 0;
        fn_802110E8(s, 7, w->x18, 3, lbl_8030CEA0.x08, w);
    }
    if (f & 2) {
        w = s->work;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("scptHread: message post time out");
        } else if (w->kind == 2) {
            return 0;
        }
    }
    return !(f & 8);
}

s32 fn_80201E54(u32 flags, Script_80201E54* s) {
    u16 f = flags;
    Work_80201E54* w;
    f32* cur;
    if (flags & 1) {
        cur = s->cursor;
        cur = cur + 1;
        w = fn_801E1A2C(1, 0x44);
        if (w == NULL) fn_801DBE1C("scptHchange: malloc failed");
        s->work = w;
        w->x18 = ReadInt(&cur);
        w->x1c = ReadInt(&cur);
        w->x20 = 0;
        s->cursor = cur;
        w->kind = 0;
        fn_802110E8(s, 7, w->x18, 4, lbl_8030CEA0.x08, w);
    }
    if (f & 2) {
        w = s->work;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("scptHchange: message post time out");
        } else if (w->kind == 2) {
            return 0;
        }
    }
    return !(f & 8);
}

s32 fn_802021B8(u32 flags, Script_802021B8* s)
{
    Work_802021B8* w;
    f32* p;
    u16 f = flags;
    if (f & 1) {
        p = s->cursor;
        p++;
        w = fn_801E1A2C(1, 0x44);
        if (w == NULL) fn_801DBE1C("scptHopen: malloc failed");
        s->work = w;
        w->x18 = RDI(p);
        w->x1c = RDI(p);
        w->x20 = RDI(p);
        s->cursor = p;
        if (w->x20 == 0x7FFFFFFF) w->x20 = 0;
        w->kind = 0;
        fn_802110E8(s, 7, w->x18, 0, lbl_8030CEA0.x08, w);
    }
    if (f & 2) {
        w = s->work;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("scptHopen: message post time out");
        } else if (w->kind == 2) {
            return 0;
        }
    }
    return !(f & 8);
}

s32 fn_80207CD0(u32 flags, Script_80207CD0* s)
{
    Work_80207CD0* w;
    f32* p;
    s32 id;
    s32 v;
    f32 f0, f1, f2;
    u16 f = flags;
    if (f & 1) {
        p = s->cursor;
        p++;
        id = (u16)RDI(p);
        v = (u16)RDI(p);
        f0 = fn_801F6120(&p);
        f1 = fn_801F6120(&p);
        f2 = fn_801F6120(&p);
        s->cursor = p;
        w = fn_801E1A2C(1, 0x44);
        if (w == NULL) fn_801DBE1C("NecM: malloc failed");
        s->work = w;
        w->kind = 0;
        w->id = id;
        w->v = v;
        w->f0 = f0;
        w->f1 = f1;
        w->f2 = f2;
        fn_80211058(s, 6, id, 0x1b, lbl_8030CEA0.x08, w);
    }
    if (f & 2) {
        w = s->work;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("necM: message post timed out");
        } else if (w->kind == 2) {
            return 0;
        }
    }
    if (f & 8) {
        return 1;
    }
    return 1;
}

s32 fn_80207ED0(u16 flags, Cmd_80207ED0* c)
{
    Rec* r;
    f32* p;
    if (flags & 1) {
        p = c->cur;
        p++;
        r = fn_801E1A2C(1, 0x44);
        if (r == 0) {
            fn_801DBE1C(lbl_802D5158);
        }
        c->work = r;
        r->n = RDI(p);
        r->f1c = fn_801F6120(&p);
        c->cur = p;
        r->kind = 0;
        fn_80211058(c, 6, r->n, 8, lbl_8030CEA0.x08, r);
    }
    if (flags & 2) {
        Rec* w = c->work;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a0, c->a1, c->a2, c->a3);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C(lbl_802D5170);
            }
        } else if (w->kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_80208044(u16 flags, Cmd_80208044* c)
{
    Rec* r;
    f32* p;
    if (flags & 1) {
        p = c->cur;
        p++;
        r = fn_801E1A2C(1, 0x44);
        if (r == 0) {
            fn_801DBE1C(lbl_802D5190);
        }
        c->work = r;
        r->n = RDI(p);
        r->f1c = fn_801F6120(&p);
        r->f20 = fn_801F6120(&p);
        r->f24 = fn_801F6120(&p);
        r->f28 = fn_801F6120(&p);
        r->f2c = fn_801F6120(&p);
        r->f30 = fn_801F6120(&p);
        r->i34 = RDI(p);
        c->cur = p;
        r->kind = 0;
        fn_80211058(c, 6, r->n, 5, lbl_8030CEA0.x08, r);
    }
    if (flags & 2) {
        Rec* w = c->work;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a0, c->a1, c->a2, c->a3);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C(lbl_802D51A8);
            }
        } else if (w->kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_80208234(u16 flags, Cmd_80208234* c)
{
    Rec* r;
    f32* p;
    if (flags & 1) {
        p = c->cur;
        p++;
        r = fn_801E1A2C(1, 0x44);
        if (r == 0) {
            fn_801DBE1C(lbl_802D51C8);
        }
        c->work = r;
        r->n = RDI(p);
        r->f1c = fn_801F6120(&p);
        r->f20 = fn_801F6120(&p);
        r->f24 = fn_801F6120(&p);
        r->f28 = fn_801F6120(&p);
        r->f2c = fn_801F6120(&p);
        r->f30 = fn_801F6120(&p);
        r->i34 = RDI(p);
        c->cur = p;
        r->kind = 0;
        fn_80211058(c, 6, r->n, 4, lbl_8030CEA0.x08, r);
    }
    if (flags & 2) {
        Rec* w = c->work;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a0, c->a1, c->a2, c->a3);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C(lbl_802D51E0);
            }
        } else if (w->kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_80208424(u16 flags, Cmd_80208424* c)
{
    Rec_80208424* r;
    f32* p;
    if (flags & 1) {
        p = c->cur;
        p++;
        r = fn_801E1A2C(1, 0x44);
        if (r == 0) {
            fn_801DBE1C(lbl_802D5200);
        }
        c->work = r;
        r->n = RDI(p);
        r->i1c = RDI(p);
        c->cur = p;
        r->kind = 0;
        fn_80211058(c, 6, r->n, 0x2d, lbl_8030CEA0.x08, r);
    }
    if (flags & 2) {
        Rec_80208424* w = c->work;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a0, c->a1, c->a2, c->a3);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C(lbl_802D5220);
            }
        } else if (w->kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_802085CC(u16 flags, Cmd_802085CC* c)
{
    Rec_802085CC* r;
    f32* p;
    if (flags & 1) {
        p = c->cur;
        p++;
        r = fn_801E1A2C(1, 0x44);
        if (r == 0) {
            fn_801DBE1C(lbl_802D5248);
        }
        c->work = r;
        r->n = RDI(p);
        r->i1c = RDI(p);
        c->cur = p;
        r->kind = 0;
        fn_80211058(c, 6, r->n, 3, lbl_8030CEA0.x08, r);
    }
    if (flags & 2) {
        Rec_802085CC* w = c->work;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a0, c->a1, c->a2, c->a3);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C(lbl_802D5260);
            }
        } else if (w->kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_80208774(u16 flags, Cmd_80208774* c)
{
    Rec* r;
    f32* p;
    if (flags & 1) {
        p = c->cur;
        r = fn_801E1A2C(1, 0x44);
        if (r == 0) {
            fn_801DBE1C(lbl_802D5280);
        }
        c->work = r;
        p++;
        r->n = RDI(p);
        r->kind = 0;
        fn_80211058(c, 6, r->n, 0x11, lbl_8030CEA0.x08, r);
        c->cur = p;
    }
    if (flags & 2) {
        Rec* w = c->work;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a0, c->a1, c->a2, c->a3);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C(lbl_802D52A0);
            }
        } else if (w->kind == 2) {
            return 0;
        }
    }
    return 1;
}

s32 fn_80208A20(u16 flags, Cmd_80208A20* c)
{
    Rec_80208A20* r;
    f32* p;
    if (flags & 1) {
        p = c->cur;
        p++;
        r = fn_801E1A2C(1, 0x44);
        if (r == 0) {
            fn_801DBE1C(lbl_802D52E8);
        }
        c->work = r;
        r->n = RDI(p);
        r->i1c = RDI(p);
        r->i20 = RDI(p);
        c->cur = p;
        r->kind = 0;
        fn_80211058(c, 6, r->n, 0xe, lbl_8030CEA0.x08, r);
    }
    if (flags & 2) {
        Rec_80208A20* w = c->work;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a0, c->a1, c->a2, c->a3);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C(lbl_802D5308);
            }
        } else if (w->kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_80208C08(u16 flags, Cmd_80208C08* c)
{
    Rec_80208C08* r;
    f32* p;
    if (flags & 1) {
        u16 n;
        s32 v;
        p = c->cur + 1;
        n = RDI(p);
        v = RDI(p);
        r = fn_801E1A2C(1, 0x44);
        if (r == 0) {
            fn_801DBE1C(lbl_802D532C);
        }
        c->work = r;
        r->kind = 0;
        r->n = n;
        r->i1c = v;
        fn_80211058(c, 6, r->n, 0x10, lbl_8030CEA0.x08, r);
        c->cur = p;
    }
    if (flags & 2) {
        Rec_80208C08* w = c->work;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a0, c->a1, c->a2, c->a3);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C(lbl_802D5348);
            }
        } else if (w->kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_80208D9C(u16 flags, Cmd_80208D9C* c)
{
    Rec_80208D9C* r;
    f32* p;
    if (flags & 1) {
        u16 n;
        s32 v;
        p = c->cur + 1;
        n = RDI(p);
        v = RDI(p);
        r = fn_801E1A2C(1, 0x44);
        if (r == 0) {
            fn_801DBE1C(lbl_802D536C);
        }
        c->work = r;
        r->kind = 0;
        r->n = n;
        r->i1c = v;
        fn_80211058(c, 6, r->n, 0x1c, lbl_8030CEA0.x08, r);
        c->cur = p;
    }
    if (flags & 2) {
        Rec_80208D9C* w = c->work;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a0, c->a1, c->a2, c->a3);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C(lbl_802D5384);
            }
        } else if (w->kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_802097C0(u16 flags, Cmd_802097C0* c)
{
    Rec_802097C0* r;
    f32* p;
    if (flags & 1) {
        p = c->cur;
        r = fn_801E1A2C(1, 0x44);
        if (r == 0) {
            fn_801DBE1C(lbl_802D544C);
        }
        c->work = r;
        p++;
        r->n = RDI(p);
        r->i1c = RDI(p);
        r->f24 = fn_801F6120(&p);
        r->kind = 0;
        fn_80211058(c, 6, r->n, 0x2a, lbl_8030CEA0.x08, r);
        c->cur = p;
    }
    if (flags & 2) {
        Rec_802097C0* w = c->work;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a0, c->a1, c->a2, c->a3);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C(lbl_802D5468);
            }
        } else if (w->kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_80209974(u16 flags, Cmd_80209974* c)
{
    Rec_80209974* r;
    f32* p;
    if (flags & 1) {
        p = c->cur + 1;
        r = fn_801E1A2C(1, 0x44);
        if (r == 0) {
            fn_801DBE1C(lbl_802D548C);
        }
        c->work = r;
        r->n = RDI(p);
        r->n2 = RDI(p);
        r->f1c = fn_801F6120(&p);
        r->f20 = fn_801F6120(&p);
        r->f24 = fn_801F6120(&p);
        r->i28 = RDI(p);
        c->cur = p;
        if (r->i28 == 0x7FFFFFFF) {
            r->i28 = 1;
        }
        r->kind = 0;
        fn_80211058(c, 6, r->n, 0x29, lbl_8030CEA0.x08, r);
    }
    if (flags & 2) {
        Rec_80209974* w = c->work;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a0, c->a1, c->a2, c->a3);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C(lbl_802D54A8);
            }
        } else if (w->kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_80209D74(u16 flags, Cmd_80209D74* c)
{
    Rec_80209D74* r;
    f32* p;
    if (flags & 1) {
        p = c->cur + 1;
        r = fn_801E1A2C(1, 0x44);
        if (r == 0) {
            fn_801DBE1C(lbl_802D5504);
        }
        c->work = r;
        r->n = RDI(p);
        c->cur = p;
        r->kind = 0;
        fn_80211058(c, 6, r->n, 0x2c, lbl_8030CEA0.x08, r);
    }
    if (flags & 2) {
        Rec_80209D74* w = c->work;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a0, c->a1, c->a2, c->a3);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C(lbl_802D5520);
            }
        } else if (w->kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_80209ED8(u16 flags, Cmd_80209ED8* c)
{
    Rec_80209ED8* r;
    f32* p;
    if (flags & 1) {
        p = c->cur + 1;
        r = fn_801E1A2C(1, 0x44);
        if (r == 0) {
            fn_801DBE1C(lbl_802D54CC);
        }
        c->work = r;
        r->n = RDI(p);
        r->f1c = fn_801F6120(&p);
        c->cur = p;
        r->kind = 0;
        fn_80211058(c, 6, r->n, 0x2b, lbl_8030CEA0.x08, r);
    }
    if (flags & 2) {
        Rec_80209ED8* w = c->work;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a0, c->a1, c->a2, c->a3);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C(lbl_802D5544);
            }
        } else if (w->kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_8020A938(u32 flags, Script_8020A938* s)
{
    Work_8020A938* w;
    s32* cur;
    u16 f = flags;
    if (f & 1) {
        cur = s->cursor + 1;
        {
            u8* end = (u8*)cur;
            end += *cur;
            s->cursor = cur + 1;
            lbl_8030CEA0.x15c8 = 1;
            w = fn_801E1A2C(1, 0xc);
            if (w == NULL) fn_801DBE1C("scptPRINT: malloc failed 1");
            s->work = w;
            w->kind = 0;
            w->x08 = end;
        }
        fn_802110E8(s, 5, 0, 0, lbl_8030CEA0.x08, w);
    }
    if (f & 2) {
        w = s->work;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("scptPRINT: message post timed out");
        } else if (w->kind == 2) {
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

s32 fn_8020AE04(u32 flags, Script_8020AE04* s)
{
    Work_8020AE04* w;
    s32* cur;
    u16 f = flags;
    if (f & 1) {
        void* msg;
        cur = s->cursor;
        s->cursor = cur + 1;
        msg = fn_8020AF8C(100);
        lbl_8030CEA0.x15c8 = 1;
        w = fn_801E1A2C(1, 0xc);
        if (w == NULL) fn_801DBE1C("scptPRINT: malloc failed 1");
        s->work = w;
        w->kind = 0;
        w->x08 = msg;
        fn_802110E8(s, 5, 0, 0, lbl_8030CEA0.x08, w);
    }
    if (f & 2) {
        w = s->work;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("scptSENNIN: message post timed out");
        } else if (w->kind == 2) {
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

s32 fn_8020B4AC(u32 flags, Script_8020B4AC* s)
{
    Work_8020B4AC* w;
    f32* cur;
    u16 f = flags;
    if (f & 1) {
        void* msg;
        s32 v;
        cur = s->cursor + 1;
        if (*cur == 3.4028235e38f) {
            cur++;
            v = 0x7FFFFFFF;
        } else {
            v = (s32)fn_801F6120(&cur);
        }
        s->cursor = cur;
        msg = fn_8020AF8C(v);
        lbl_8030CEA0.x15c8 = 1;
        w = fn_801E1A2C(1, 0xc);
        if (w == NULL) fn_801DBE1C("scptPRINT: malloc failed 1");
        s->work = w;
        w->kind = 0;
        w->x08 = msg;
        fn_802110E8(s, 5, 0, 0, lbl_8030CEA0.x08, w);
    }
    if (f & 2) {
        w = s->work;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("scptSENNIN: message post timed out");
        } else if (w->kind == 2) {
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
        lbl_8030CEA0.xc4b = 30;
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
            lbl_8030CEA0.xc4a = 7;
            lbl_8030CEA0.xc4b = 59;
        } else {
            lbl_8030CEA0.x830 = v;
            lbl_8030CEA0.xc4a = 1;
            lbl_8030CEA0.xc4b = 59;
        }
    } else if (mode == 2) {
        lbl_8030CEA0.x834 = (s32)v;
    }
}
