/* Task command handlers (0x80036520 - 0x8003DEE0): the two task command tables (lbl_802DD238,
 * lbl_802DE208) and their handlers. A handler checks the command's target with fn_8003DCF4,
 * allocates a task node (TaskNew / TaskAlloc, "Error: tasSetTask"), and fills that task's work
 * area. Per-handler work layouts are named <Type>_<handler address>. The chunk-list code before
 * it (0x80035918-0x80036520) is chunklist.c: its jump table sits ahead of the 4-byte gap before
 * lbl_802DD238, so it is a separate original file.
 *
 * Built with -str reuse,readonly -inline noauto,deferred (configure.py), so the functions are
 * written from the highest address down (see sound.c and docs/compiler.md); the tables stay
 * ahead of them. fn_8003DBAC's "ABG" initialiser comes out first in .sdata2 for the same reason. */
#include "types.h"
#include "game/chunklist.h"





typedef struct { u8 pad[0xC]; u8 xc[1]; } TaskSub;
typedef struct { u8 pad0[0x10]; TaskSub* x10; u8 pad1[0x4C - 0x14]; void* x4c; } TaskRes;
typedef struct { u8 pad[0x24]; TaskRes* res; } TaskArg;
typedef struct { u8 pad[0xC]; void* obj; } Handler;
typedef struct { u8 pad[0x18]; u8 flags; u8 state; u8 pad1a[0x24 - 0x1A]; void* work; } Node;

/* Task command table entry (lbl_802DD238, lbl_802DE208): key = type << 16 | id. */
typedef int (*TaskFunc)(Handler*, TaskArg*);
typedef struct {
    s16 a;              /* id */
    s16 b;              /* type */
    char name[0x20];
    void (*init)(void);
    TaskFunc fn;
} TaskEnt;

typedef struct { u8 pad[0x4c]; void* data; } TaskInfo;
typedef struct { u8 pad[0x24]; TaskInfo* info; } TaskObj;

typedef struct { f32 x, y, z; } Vec;
typedef struct { u8 data[0x64]; } SaveHead;
typedef struct { SaveHead head; Vec a[12]; Vec b[12]; } SaveBuf;

/* Per-function layouts (named after the function that uses them). */
typedef struct { u8 pad[0xEC]; u32 flags; u8 pad2[0x154 - 0xF0]; void* x154; } Obj_80036584;
typedef struct { u8 pad[0x2C]; void* x2c; } Sub_80036584;
typedef struct { u8 pad[0x10]; Sub_80036584* sub; s16 x14; u8 pad2[0x4C - 0x16]; Obj_80036584* obj; } Data_80036584;
typedef struct { void* arg; s16 id; } Work_80036880;
typedef struct { void* arg; void* obj; } Work_80036914;
typedef struct { void* arg; s16 a; s16 b; s16 c; s16 d; } Work_800369A4;
typedef struct { void* arg; s16 a; s16 b; s16 c; s16 d; } Work_80036A38;
typedef struct { void* arg; u8 pad[8]; s16 c; s16 d; s16 e; } Work_80036AE4;
typedef struct { void* arg; s16 a; s16 b; s16 c; s16 d; } Work_80036B88;
typedef struct { void* arg; s16 a; s16 pad; s16 b; } Work_80036C1C;
typedef struct { s16 s; u8 p[0xE]; s16 a; s16 b; s16 c; } O1_80036CB0;
typedef struct { void* owner; u8 p[0xC-4]; s16 a; s16 b; s16 c; s16 d; } W1_80036CB0;
typedef struct { u8 p0[0x10]; f32 f10; s16 s14; s16 s16x; s16 s18; u8 p1[2]; f32 f1c; s16 s20; } O_80036D5C;
typedef struct { void* owner; u8 p0[0x70]; f32 f74; f32 f78; u8 p1[4]; s16 s80; s16 s82; s16 s84; u8 p2[0x18]; s16 s9e; } W_80036D5C;
typedef struct { s16 id; u8 p[2]; f32 f[16]; } O_80036E18;
typedef struct { void* owner; f32 f[0x1F]; s16 id; } W_80036E18;
typedef struct { s16 id; u8 p[2]; f32 f[16]; } O_80036EC4;
typedef struct { void* owner; f32 f[0x1F]; s16 id; } W_80036EC4;
typedef struct { s16 id; u8 p[2]; f32 f[16]; } O_80036F70;
typedef struct { void* owner; f32 f[0x1F]; s16 id; } W_80036F70;
typedef struct { s16 id; u8 p[2]; f32 f[16]; } O_8003701C;
typedef struct { void* owner; f32 f[0x1F]; s16 id; } W_8003701C;
typedef struct { s16 id; u8 p[2]; f32 f[16]; } O_800370C8;
typedef struct { void* owner; f32 f[0x1F]; s16 id; } W_800370C8;
typedef struct { s16 id; u8 p[2]; f32 f[16]; } O_8003716C;
typedef struct { void* owner; f32 f[0x1F]; s16 id; } W_8003716C;
typedef struct { u8 pad0[0x74]; void* x74; u8 pad1[0x178 - 0x78]; void* x178; } W_80037250;
typedef struct {
    u8 x0;
    u8 pad1[0x5];
    s16 x6;
    s16 x8;
    u8 pad2[0x13c - 0xa];
    Vec x13c;
    Vec x148;
} TaskRes_80037918;
typedef struct { u8 pad0[0x8]; void* arg; } Work_80037918;
typedef struct { u8 pad[0x4]; u32 x4; } ResInfo_80037AF0;
typedef struct {
    s8 x0;
    u8 pad1[0x5c - 0x1];
    ResInfo_80037AF0* x5c;
    u8 pad2[0x68 - 0x60];
    f32 x68;
} TaskRes_80037AF0;
typedef struct { s16 count; s16 timer; u8 pad[0x4]; TaskObj* arg; } Work_80037AF0;
typedef struct { u8 pad[0x8]; u32 x8; } PadState_80037AF0;
typedef struct { PadState_80037AF0* pad; u8 pad4[0x14]; } PadInfo_80037AF0;
typedef struct { u8 pad[0x48]; u32 x48; } BattleSys_80037AF0;
typedef struct { u8 pad[0xF0]; u32 flags; u8 p1[0x164 - 0xF4]; f32 x164; u8 p2[0x194 - 0x168]; s32 x194; u8 p3[0x208 - 0x198]; f32 x208; } Body_80037EB4;
typedef struct { u8 pad0[6]; s16 flags; } Ent_80037FD8;
typedef struct { u8 pad0[8]; u32 flags; u8 pad1[4]; f32 x10; f32 x14; } Cam_8003801C;
typedef struct { void* arg; u8 pad[4]; void* owner; } Work_80038078;
typedef struct { void* arg; u8 pad[4]; void* owner; } Work_80038140;
typedef struct { u8 pad0[120]; void* arg; u8 pad1[56]; void* owner; } Work_80038208;
typedef struct { u8 pad0[4]; void* arg; u8 pad1[24]; void* owner; } Work_800382D0;
typedef struct { u8 pad[0x4]; void* arg; u8 pad2[0x34]; void* owner; } Work_80038398;
typedef struct { u8 pad0[0x8]; void* arg; u8 pad1[0x2c]; void* owner; } Work_80038460;
typedef struct { u8 pad[0x8]; s32 src; } Obj_80038534;
typedef struct { u8 d[0x4C]; } Buf_80038534;
typedef struct { u8 pad0[0x4]; void* arg; u8 pad1[0x60]; void* owner; } Sub_80038534;
typedef struct { Buf_80038534 buf; Sub_80038534* sub; } Work_80038534;
typedef struct { u8 pad[0x8]; s32 src; } Obj_80038654;
typedef struct { u8 d[0x4C]; } Buf_80038654;
typedef struct { u8 pad0[0x10]; void* arg; void* owner; } Sub_80038654;
typedef struct { Buf_80038654 buf; Sub_80038654* sub; } Work_80038654;
typedef struct { u8 pad0[0x4]; void* arg; u8 pad1[0xe8]; void* owner; } Work_80038774;
typedef struct { u8 pad0[0x4]; void* arg; u8 pad1[0x9c]; void* owner; } Work_80038848;
typedef struct { u8 pad0[0x30]; void* arg; void* owner; } Work_8003891C;
typedef struct { u8 pad0[0x4]; void* arg; u8 pad1[0x8]; void* owner; } Work_800389F0;
typedef struct { u8 pad0[0x4]; void* arg; u8 pad1[0x44]; void* owner; } Work_80038AC4;
typedef struct { u8 pad[0x8]; s32 src; } Obj_80038B98;
typedef struct { u8 d[0x4C]; } Buf_80038B98;
typedef struct { u8 pad0[0x8]; void* arg; u8 pad1[0x4]; void* owner; } Sub_80038B98;
typedef struct { Buf_80038B98 buf; Sub_80038B98* sub; } Work_80038B98;
typedef struct { u8 pad0[0x4]; void* arg; u8 pad1[0x18]; void* owner; } Work_80038CB8;
typedef struct { u8 pad[0x8]; s32 src; } Obj_80038D8C;
typedef struct { u8 d[0x4C]; } Buf_80038D8C;
typedef struct { u8 pad0[0x4]; void* arg; u8 pad1[0x60]; void* owner; } Sub_80038D8C;
typedef struct { Buf_80038D8C buf; Sub_80038D8C* sub; } Work_80038D8C;
typedef struct { u8 pad0[0x4]; void* arg; u8 pad1[0x4]; void* owner; } Work_80038EAC;
typedef struct { u8 pad[0x8]; s32 src; } Obj_80038F80;
typedef struct { u8 d[0x4C]; } Buf_80038F80;
typedef struct { u8 pad0[0x4]; void* arg; u8 pad1[0x2c]; void* owner; } Sub_80038F80;
typedef struct { Buf_80038F80 buf; Sub_80038F80* sub; } Work_80038F80;
typedef struct { u8 pad0[0x50]; void* arg; void* owner; } Work_800390A0;
typedef struct { u32 a, b; s32 src; u32 c, d, e; } Obj_80039174;
typedef struct { u32 first; u8 rest[0x48]; } Buf_80039174;
typedef struct { u8 pad0[4]; void* arg; u8 pad1[0xC]; Buf_80039174 buf; void* owner; } Work_80039174;
typedef struct { u32 a, b; s32 src; u32 c, d, e; } Obj_80039280;
typedef struct { u32 first; u8 rest[0x48]; } Buf_80039280;
typedef struct { Buf_80039280 buf; u8 pad0[0x54-0x4C]; void* arg; u8 pad1[0xB4-0x58]; void* owner; } Work_80039280;
typedef struct { u32 a, b; s32 src; u32 c, d, e; } Obj_800393AC;
typedef struct { u32 first; u8 rest[0x48]; } Buf_800393AC;
typedef struct { u8 pad0[4]; void* arg; Buf_800393AC buf; Obj_800393AC copy; } Work_800393AC;
typedef struct { u8 pad[0x8]; s32 src; } Obj_800394E4;
typedef struct { u8 d[0x4C]; } Buf_800394E4;
typedef struct { u8 pad0[0x4]; void* arg; u8 pad1[0x2c]; void* owner; } Sub_800394E4;
typedef struct { Buf_800394E4 buf; Sub_800394E4* sub; } Work_800394E4;
typedef struct { u8 pad0[4]; void* arg; u8 pad1[28]; void* owner; } Work_80039604;
typedef struct { u8 pad0[4]; void* arg; u8 pad1[48]; void* owner; } Work_800396D8;
typedef struct { u8 pad0[4]; void* arg; u8 pad1[4]; void* owner; } Work_800397AC;
typedef struct { u8 pad0[4]; void* arg; void* owner; } Work_80039880;
typedef struct { u8 pad0[4]; void* arg; void* owner; } Work_80039954;
typedef struct { u8 pad0[4]; void* arg; u8 pad1[136]; void* owner; } Work_80039A28;
typedef struct { u8 pad[0x8]; s32 src; } Obj_80039AFC;
typedef struct { u8 d[0x4C]; } Buf_80039AFC;
typedef struct { u8 pad0[0x4]; void* arg; u8 pad1[0xC]; void* owner; } Sub_80039AFC;
typedef struct { Buf_80039AFC buf; Sub_80039AFC* sub; } Work_80039AFC;
typedef struct { u8 pad0[4]; void* arg; u8 pad1[12]; void* owner; } Work_80039C38;
typedef struct { u8 pad0[4]; void* arg; u8 pad1[24]; void* owner; } Work_80039D0C;
typedef struct { u8 pad0[8]; void* arg; void* owner; } Work_80039DE0;
typedef struct { u8 pad0[4]; void* arg; void* owner; } Work_80039EB4;
typedef struct { u8 pad0[0x8]; void* arg; void* owner; } Sub_80039F88;
typedef struct { u8 pad[0x4C]; Sub_80039F88* sub; } Work_80039F88;
typedef struct { u8 pad[0x8]; s32 src; } Obj_8003A070;
typedef struct { u8 d[0x4C]; } Buf_8003A070;
typedef struct { u8 pad0[0x4]; void* arg; u8 pad1[0x24]; void* owner; } Sub_8003A070;
typedef struct { Buf_8003A070 buf; Sub_8003A070* sub; } Work_8003A070;
typedef struct { u8 pad0[4]; void* arg; u8 pad1[60]; void* owner; } Work_8003A190;
typedef struct { u8 pad[0x8]; s32 src; } Obj_8003A264;
typedef struct { u8 d[0x4C]; } Buf_8003A264;
typedef struct { Buf_8003A264 buf; u8 pad0[0x8]; void* arg; u8 pad1[0x34]; void* owner; } Work_8003A264;
typedef struct {
    u8 pad0[0x8]; s32 src;            /* 0x08 */
    u8 pad1[0x14 - 0xC]; s16 x14;     /* 0x14 */
    s16 x16;                          /* 0x16 */
    s16 x18;                          /* 0x18 */
    u8 pad2[0x1E - 0x1A]; s16 x1e;    /* 0x1E */
    s16 x20;                          /* 0x20 */
    u8 pad3[0x34 - 0x22]; f32 x34, x38, x3c; /* 0x34 */
    s16 x40;                          /* 0x40 */
    u8 pad4[0x146 - 0x42]; s16 x146;  /* 0x146 */
    f32 x148, x14c, x150, x154, x158, x15c; /* 0x148 */
} Obj_8003A370;
typedef struct { u8 d[0x4C]; } Buf_8003A370;
typedef struct {
    u8 pad0[0x2]; s16 x2; s16 x4; u8 pad1[2];
    f32 x8, xc;
    s16 x10; u8 pad2[2];
    f32 x14, x18, x1c;
    u8 pad3[0x24 - 0x20]; void* arg;  /* 0x24 */
    u8 pad4[0x30 - 0x28]; f32 x30, x34; /* 0x30 */
    u8 pad5[0x40 - 0x38]; void* owner; /* 0x40 */
} Sub_8003A370;
typedef struct { Buf_8003A370 buf; Sub_8003A370* sub; } Work_8003A370;
typedef struct { u8 pad0[4]; void* arg; void* owner; } Work_8003A75C;
typedef struct { u8 pad0[4]; void* arg; u8 pad1[28]; void* owner; } Work_8003A830;
typedef struct { u8 pad0[0x4]; void* arg; u8 pad1[0x40]; void* owner; } Work_8003A904;
typedef struct { u8 pad0[0x4]; void* arg; u8 pad1[0x8]; void* owner; } Work_8003A9D8;
typedef struct { u8 pad[0x8]; s32 src; } Obj_8003AAAC;
typedef struct { u8 d[0x4C]; } Buf_8003AAAC;
typedef struct { u8 pad0[0x4]; void* arg; u8 pad1[0x34]; void* owner; } Sub_8003AAAC;
typedef struct { Buf_8003AAAC buf; Sub_8003AAAC* sub; } Work_8003AAAC;
typedef struct { u8 d[0x7C]; } Obj_8003ABCC;
typedef struct { u8 d[0x4C]; } Buf_8003ABCC;
typedef struct { u8 pad0[0x8]; void* arg; u32 x; Obj_8003ABCC copy; } Sub_8003ABCC;
typedef struct { Buf_8003ABCC buf; Sub_8003ABCC* sub; } Work_8003ABCC;
typedef struct { u8 pad[0x8]; s32 src; u8 rest[0x84]; } Obj_8003AD14;
typedef struct { u8 d[0x4C]; } Buf_8003AD14;
typedef struct { u8 pad0[0x4]; void* arg; u8 pad1[0x14]; Obj_8003AD14 copy; } Sub_8003AD14;
typedef struct { Buf_8003AD14 buf; Sub_8003AD14* sub; } Work_8003AD14;
typedef struct { u8 pad[0x8]; s32 src; } Obj_8003AE54;
typedef struct { u8 d[0x4C]; } Buf_8003AE54;
typedef struct { u8 pad0[0x4]; void* arg; u8 pad1[0x10]; void* owner; } Sub_8003AE54;
typedef struct { Buf_8003AE54 buf; Sub_8003AE54* sub; } Work_8003AE54;
typedef struct { u8 pad[0x8]; s32 src; } Obj_8003AF7C;
typedef struct { u8 d[0x4C]; } Buf_8003AF7C;
typedef struct { u8 pad0[0x4]; void* arg; u8 pad1[0x60]; void* owner; } Sub_8003AF7C;
typedef struct { Buf_8003AF7C buf; Sub_8003AF7C* sub; } Work_8003AF7C;
typedef struct { u8 pad[0x8]; s32 src; } Obj_8003B09C;
typedef struct { u8 d[0x4C]; } Buf_8003B09C;
typedef struct { u8 pad0[0x4]; void* arg; u8 pad1[0xC]; void* owner; } Sub_8003B09C;
typedef struct { Buf_8003B09C buf; Sub_8003B09C* sub; } Work_8003B09C;
typedef struct { u8 d[0x1C]; } Obj_8003B1D8;
typedef struct { u8 pad0[0x8]; void* arg; u32 pad1; Obj_8003B1D8 copy; } Work_8003B1D8;
typedef struct { u8 pad[0x8]; s32 src; u8 p1[0x8]; s16 x; s16 y; u8 p2[0x10]; s16 count; s16 step; u8 p3[0x20]; } Obj_8003B2E0;
typedef struct { u8 d[0x4C]; } Buf_8003B2E0;
typedef struct { u8 pad0[0x4]; void* arg; u8 pad1[0x18]; Obj_8003B2E0 copy; } Sub_8003B2E0;
typedef struct { Buf_8003B2E0 buf; Sub_8003B2E0* sub; } Work_8003B2E0;
typedef struct { u8 pad[0x8]; s32 src; } Obj_8003B464;
typedef struct { u8 d[0x4C]; } Buf_8003B464;
typedef struct { u8 pad0[0x4]; void* arg; u8 pad1[0x84]; void* owner; } Sub_8003B464;
typedef struct { Buf_8003B464 buf; Sub_8003B464* sub; } Work_8003B464;
typedef struct { u8 pad[0x8]; s32 src; u8 p1[0x8]; s16 x; s16 y; u8 p2[0x10]; s16 count; s16 step; u8 p3[0x18]; } Obj_8003B584;
typedef struct { u8 d[0x4C]; } Buf_8003B584;
typedef struct { u8 pad0[0x4]; void* arg; u8 pad1[0x8]; Obj_8003B584 copy; } Sub_8003B584;
typedef struct { Buf_8003B584 buf; Sub_8003B584* sub; } Work_8003B584;
typedef struct { u8 pad[0x8]; s32 src; u8 p1[0x8]; s16 x; s16 y; u8 p2[0x12]; s16 count; s16 step; u8 p3[0x2a]; } Obj_8003B708;
typedef struct { u8 d[0x4C]; } Buf_8003B708;
typedef struct { u8 pad0[0x4]; void* arg; u8 pad1[0x1c]; Obj_8003B708 copy; } Sub_8003B708;
typedef struct { Buf_8003B708 buf; Sub_8003B708* sub; } Work_8003B708;
typedef struct { u8 pad[0x8]; s32 src; u8 p1[0x8]; s16 x; s16 y; u8 p2[0x12]; s16 count; s16 step; u8 p3[0x12e]; } Obj_8003B884;
typedef struct { u8 d[0x4C]; } Buf_8003B884;
typedef struct { s16 x; s16 y; u8 pad0[0x4]; void* arg; u8 pad1[0x1c]; Obj_8003B884 copy; } Sub_8003B884;
typedef struct { Buf_8003B884 buf; Sub_8003B884* sub; } Work_8003B884;
typedef struct { u8 pad[0x8]; s32 src; u8 p1[0x8]; s16 x; s16 y; u8 p2[0x12]; s16 count; s16 step; u8 p3[0x136]; } Obj_8003BA08;
typedef struct { u8 d[0x4C]; } Buf_8003BA08;
typedef struct { u8 pad0[0x4]; void* arg; u8 pad1[0x20]; Obj_8003BA08 copy; } Sub_8003BA08;
typedef struct { Buf_8003BA08 buf; Sub_8003BA08* sub; } Work_8003BA08;
typedef struct { u8 pad[0x14]; s16 start; s16 end; u8 p2[0x36]; s16 mod; } Obj_8003BB50;
typedef struct { u8 pad0[0x4]; void* arg; u8 pad1[0x8]; s16 idx; s16 next; u8 pad2[0x4C]; void* owner; } Work_8003BB50;
typedef struct { u8 pad[0x8]; s32 src; } Obj_8003BC58;
typedef struct { u8 d[0x4C]; } Buf_8003BC58;
typedef struct { void* arg; void* owner; } Sub_8003BC58;
typedef struct { Buf_8003BC58 buf; Sub_8003BC58* sub; } Work_8003BC58;
typedef struct { u8 pad[0x8]; s32 src; } Obj_8003BD78;
typedef struct { u8 d[0x4C]; } Buf_8003BD78;
typedef struct { u8 pad0[0x8]; void* arg; u8 pad1[0x44]; void* owner; } Sub_8003BD78;
typedef struct { Buf_8003BD78 buf; Sub_8003BD78* sub; } Work_8003BD78;
typedef struct { u8 pad0[0x8]; void* arg; void* owner; } Work_8003BE98;
typedef struct { u8 pad[0x8]; s32 src; } Obj_8003BF74;
typedef struct { u8 d[0x4C]; } Buf_8003BF74;
typedef struct { u8 pad0[0x8]; void* arg; u8 pad1[0x28]; void* owner; } Sub_8003BF74;
typedef struct { Buf_8003BF74 buf; Sub_8003BF74* sub; } Work_8003BF74;
typedef struct { u8 pad[0x8]; s32 src; u8 rest[0x110]; } Obj_8003C094;
typedef struct { u32 first; u8 rest[0x48]; } Buf_8003C094;
typedef struct { u8 pad0[0x4]; void* arg; Obj_8003C094 copy; } Sub_8003C094;
typedef struct { Buf_8003C094 buf; Sub_8003C094* sub; } Work_8003C094;
typedef struct { u8 pad0[4]; void* arg; u8 pad1[0xC]; void* owner; } Sub_8003C1F0;
typedef struct { u8 d[0x4C]; Sub_8003C1F0* sub; } Work_8003C1F0;
typedef struct { u8 d[0x4C]; } Buf_8003C2D8;
typedef struct { u8 pad0[4]; void* arg; u8 pad1[0x14]; void* owner; } Sub_8003C2D8;
typedef struct { Buf_8003C2D8 buf; Sub_8003C2D8* sub; } Work_8003C2D8;
typedef struct { u8 d[0x174]; } Obj_8003C400;
typedef struct { u8 d[0x4C]; } Buf_8003C400;
typedef struct { u8 pad0[8]; void* arg; u8 pad1[0x20]; Obj_8003C400 copy; } Sub_8003C400;
typedef struct { Buf_8003C400 buf; Sub_8003C400* sub; } Work_8003C400;
typedef struct { u32 a, b; s32 src; u8 rest[0x1A0 - 12]; } Obj_8003C550;
typedef struct { u8 d[0x4C]; } Buf_8003C550;
typedef struct { u8 pad0[4]; void* arg; u8 pad1[0x14]; Obj_8003C550 copy; } Sub_8003C550;
typedef struct { Buf_8003C550 buf; Sub_8003C550* sub; } Work_8003C550;
typedef struct { u8 pad116[0x74]; void* arg; u8 pad376[0x100]; void* owner; } Work_8003C690;
typedef struct { u8 pad24[0x18]; void* arg; u8 pad32[0x4]; void* owner; } Work_8003C764;
typedef struct { u8 pad4[0x4]; void* arg; void* owner; } Work_8003C838;
typedef struct { u8 pad4[0x4]; void* arg; u8 pad44[0x24]; void* owner; } Work_8003C90C;
typedef struct { u8 d[0x38]; } Obj_8003C9E0;
typedef struct { u8 pad0[4]; void* arg; u8 pad1[0x1C]; Obj_8003C9E0 copy; } Work_8003C9E0;
typedef struct { u8 d[0x28]; } Obj_8003CB20;
typedef struct { u8 pad0[4]; Obj_8003CB20 copy; } Work_8003CB20;
typedef struct { u8 pad4[0x4]; void* arg; u8 pad44[0x24]; void* owner; } Work_8003CC30;
typedef struct { u8 pad4[0x4]; void* arg; u8 pad32[0x18]; void* owner; } Work_8003CD04;
typedef struct { u8 pad4[0x4]; void* arg; u8 pad12[0x4]; void* owner; } Work_8003CDD8;
typedef struct { u32 d[10]; } Obj_8003CEAC;
typedef struct { u8 pad0[4]; void* arg; u8 pad1[0x14 - 0x8]; Obj_8003CEAC copy; } Work_8003CEAC;
typedef struct { u8 pad[6]; s16 flags; u8 rest[0x10]; } Obj_8003D040;
typedef struct { u8 pad0[4]; void* arg; u8 pad1[0x4C]; Obj_8003D040 copy; } Work_8003D040;
typedef struct {
    u8 pad0[0x8]; s32 src;            /* 0x08 */
    u8 pad1[0x10 - 0xC]; u32 flags;   /* 0x10 */
    u8 pad2[0x45 - 0x14]; u8 x45;     /* 0x45 */
    u8 pad3[0x50 - 0x46];
} Obj_8003D14C;
typedef struct { u8 d[0x4C]; } Buf_8003D14C;
typedef struct { u8 pad0[0x4]; void* arg; u8 pad1[0x20 - 0x8]; Obj_8003D14C copy; } Sub_8003D14C;
typedef struct { Buf_8003D14C buf; Sub_8003D14C* sub; } Work_8003D14C;
typedef struct { u32 a, b; s32 src; u32 rest[9]; } Obj_8003D2E4;
typedef struct { u8 d[0x4C]; } Buf_8003D2E4;
typedef struct { u8 pad0[0x8]; void* arg; u8 pad1[0x18 - 0xC]; Obj_8003D2E4 copy; u8 pad2[0x50 - 0x48]; } Sub_8003D2E4;
typedef struct { Buf_8003D2E4 buf; Sub_8003D2E4* sub; } Work_8003D2E4;
typedef struct { u8 pad[0x8]; s32 src; } Obj_8003D520;
typedef struct { u8 d[0x4C]; } Buf_8003D520;
typedef struct { u8 pad0[0x70]; void* arg; u8 pad1[0x4C]; void* owner; } Sub_8003D520;
typedef struct { Buf_8003D520 buf; Sub_8003D520* sub; } Work_8003D520;
typedef struct { u32 a, b; s32 src; u8 rest[0x1A8 - 12]; } Obj_8003D640;
typedef struct { u8 d[0x4C]; } Buf_8003D640;
typedef struct { u8 pad0[4]; void* arg; u8 pad1[0x14]; Obj_8003D640 copy; } Sub_8003D640;
typedef struct { Buf_8003D640 buf; Sub_8003D640* sub; } Work_8003D640;
typedef struct { u8 pad4[0x4]; void* arg; u8 pad236[0xe4]; void* owner; } Work_8003D780;
typedef struct { u8 pad4[0x4]; void* arg; u8 pad16[0x8]; void* owner; } Work_8003D854;
typedef struct { u8 pad4[0x4]; void* arg; u8 pad16[0x8]; void* owner; } Work_8003D928;
typedef struct { u8 pad4[0x4]; void* arg; u8 pad168[0xa0]; void* owner; } Work_8003D9FC;
typedef struct { s16 type; s16 x2; s16 id; } TaskTarget;
typedef struct {
    u8 pad0[0x6]; s16 x6; s16 x8;
    u8 pad1[0x4a - 0xa]; s16 x4a; s16 x4c;
    u8 pad2[0x56 - 0x4e]; s16 x56; s16 x58;
    u8 pad3[0xec - 0x5a]; u32 xec;
} TaskCond;

extern void fn_801E17E0(void*);
extern void* fn_801E1C7C(u32 size);
extern void* memcpy(void* dst, const void* src, u32 n);
extern void fn_80046BB0(void* obj, s32* key);
extern ChunkHdr* fn_8006DAF8(void* obj);
extern void* fn_801CC69C(void* name);
extern void fn_801CC608(void* h, void* buf, u32 size);
extern void fn_801CC65C(void* h);
extern void fn_80061F58(void*, int, int);
extern void fn_8006C8DC(void*, void*);
extern void fn_80074E2C(void*, void*, void*, int, int);
extern void fn_80073FB8(void*, void*, int, s16);
extern TaskObj* lbl_80309E24[];
extern void fn_80062444(void);
extern void fn_80061FCC(void);
extern void fn_8006228C(void);
extern void fn_80062318(void);
extern void fn_800624FC(void);
extern void fn_80062674(void);
extern void fn_80062E94(void);
extern void fn_80062F70(void);
extern void fn_800631B0(void);
extern void fn_80064AC8(void);
extern void fn_80064C00(void);
extern void fn_80064CA4(void);
extern void fn_80064E38(void);
extern void fn_80064FE0(void);
extern void fn_800651D0(void);
extern void fn_80051264(void);
extern void* lbl_803475A8;
extern SaveBuf* lbl_803472EC;
extern int fn_80014C90(u8, u32);
extern Node* fn_802268E8(void*, void*);
extern SaveHead* fn_8006B6F4(int);
extern void fn_80071CF0(void*, void*);
extern void fn_800614FC(void*, void*);
extern PadInfo_80037AF0 lbl_80311A60;
extern BattleSys_80037AF0 lbl_80309EC8;
extern s32 lbl_80347508;
extern f32 lbl_80347510;
extern s32 lbl_8034733C;
extern int fn_8001BCC8(int, TaskObj*);
extern void fn_801CBC10(void);
extern void fn_801CBBAC(f32);
extern void fn_801CBB9C(f32);
extern void fn_801CBBF8(void);
extern void fn_80028E0C(void);
extern int fn_80028B90(void);
extern void fn_80028DE4(void);
extern void fn_80033888(int, int, int, int, int, f32, f32);
extern int fn_8006D1C4(void);
extern Cam_8003801C lbl_80309E5C;
extern void fn_8007E414(int);
extern void fn_801DBE1C(const char*, ...);
extern void fn_8005CBA4(void);
extern void fn_8005CCB0(void);
extern void fn_8005CDF0(void);
extern void fn_8005D614(void);
extern void fn_8005DB1C(void);
extern void fn_8005E42C(void);
extern void fn_8005E9D4(void);
extern void fn_8005F640(void);
extern void fn_8005F8D8(void);
extern void fn_800601C0(void);
extern void fn_80073164(void);
extern void fn_8006065C(void);
extern void fn_800583D4(void);
extern void fn_80058E20(void);
extern void fn_80059788(void);
extern void fn_80059D6C(void);
extern void fn_8005A694(void);
extern void fn_8005ACD4(void);
extern void fn_8005B094(void);
extern void fn_8005B2C8(void);
extern void fn_8005B648(void);
extern void fn_8005BAA0(void);
extern void fn_8005BBC4(void);
extern void fn_8005BF30(void);
extern void fn_8005DEB8(void);
extern void fn_8005C188(void);
extern void fn_8005C328(void);
extern void fn_8005C480(void);
extern void fn_8005C73C(void);
extern void* memset(void*, int, unsigned long);
extern void fn_80046704(void);
extern void fn_800553FC(void);
extern void fn_80055558(void);
extern void fn_80055A38(void);
extern void fn_80055E94(void);
extern void fn_80055EB8(void);
extern void fn_80055F0C(void);
extern void fn_800565B0(void);
extern void fn_80056B6C(void);
extern int rand(void);
extern void fn_80057038(void);
extern void fn_800576B0(void);
extern void fn_80057BD0(void);
extern void fn_80057DFC(void);
extern void fn_800581B8(void);
extern void fn_80049464(void);
extern void fn_80041238(void);
extern void fn_80041664(void);
extern void fn_800544C4(void);
extern void fn_80045CD8(void);
extern void fn_800498F0(void);
extern void fn_8004281C(void);
extern void fn_800445D4(void);
extern void fn_80041E64(void);
extern void fn_80044178(void);
extern void fn_80043C24(void);
extern void fn_800405EC(void);
extern void fn_80042B10(void);
extern void fn_80049DC0(void);
extern void fn_8004DB90(void);
extern void fn_8004D378(void);
extern void fn_8004D828(void);
extern void fn_80040AA0(void);
extern void fn_8004A260(void);
extern void fn_80055058(void);
extern void fn_800102C8(void*, int, void*);
extern void fn_8004DE48(void);
extern void fn_8004A40C(void);
extern void fn_80044B24(void);
extern void fn_800541E0(void);
extern void fn_80050DB0(void);
extern void fn_8004E474(void);
extern void fn_8004B7C4(void);
extern void fn_8004A028(void);
extern void fn_800506B0(void);
extern void fn_8004FF8C(void);
extern void fn_80050B88(void);
extern s8 fn_80020E10(void*);
extern void fn_8004AD38(void);
extern void fn_8004AFD8(void);
extern void fn_8004C070(void);
extern s8 fn_8000FA30(u8);
extern void fn_8004C1E4(void);
extern int sprintf(char*, const char*, ...);
extern void fn_8000FC14(void);
extern void fn_8004E7F0(void);
extern void fn_800454A0(void);
extern void fn_8004EEF0(void);
extern void fn_80054B74(void);
extern void fn_80054DD8(void);
extern void fn_8004F868(void);

/* PROTOTYPES */
int fn_8003617C(ChunkHdr* p);
int fn_80036880(Handler* h, TaskArg* arg);
int fn_80036914(Handler* h, TaskArg* arg);
int fn_800369A4(Handler* h, TaskArg* arg);
int fn_80036A38(Handler* h, TaskArg* arg);
int fn_80036AE4(Handler* h, TaskArg* arg);
int fn_80036B88(Handler* h, TaskArg* arg);
int fn_80036C1C(Handler* h, TaskArg* arg);
int fn_80036CB0(Handler* h, TaskArg* arg);
int fn_80036D5C(Handler* h, TaskArg* arg);
int fn_80036E18(Handler* h, TaskArg* arg);
int fn_80036EC4(Handler* h, TaskArg* arg);
int fn_80036F70(Handler* h, TaskArg* arg);
int fn_8003701C(Handler* h, TaskArg* arg);
int fn_800370C8(Handler* h, TaskArg* arg);
int fn_8003716C(Handler* h, TaskArg* arg);
int fn_80037250(Handler* h, TaskArg* arg);
void fn_800372E0(void);
void fn_800372E4(void);
void fn_800372E8(void);
void fn_800372EC(void);
void fn_800372F0(void);
void fn_800372F4(void);
void fn_800372F8(void);
void fn_800372FC(void);
void fn_80037300(void);
void fn_80037304(void);
void fn_80037308(void);
void fn_8003730C(void);
void fn_80037310(void);
void fn_80037314(void);
void fn_80037318(void);
void fn_8003731C(void);
void fn_80037320(void);
void fn_80037324(void);
void fn_80037328(void);
int fn_800377FC(ChunkHdr* m);
void fn_80037AF0(Node* node);
void fn_80037EB4(void);
int fn_80038078(Handler* h, TaskArg* arg);
int fn_80038140(Handler* h, TaskArg* arg);
int fn_80038208(Handler* h, TaskArg* arg);
int fn_800382D0(Handler* h, TaskArg* arg);
int fn_80038398(Handler* h, TaskArg* arg);
int fn_80038460(Handler* h, TaskArg* arg);
int fn_80038534(Handler* h, TaskArg* arg);
int fn_80038654(Handler* h, TaskArg* arg);
int fn_80038774(Handler* h, TaskArg* arg);
int fn_80038848(Handler* h, TaskArg* arg);
int fn_8003891C(Handler* h, TaskArg* arg);
int fn_800389F0(Handler* h, TaskArg* arg);
int fn_80038AC4(Handler* h, TaskArg* arg);
int fn_80038B98(Handler* h, TaskArg* arg);
int fn_80038CB8(Handler* h, TaskArg* arg);
int fn_80038D8C(Handler* h, TaskArg* arg);
int fn_80038EAC(Handler* h, TaskArg* arg);
int fn_80038F80(Handler* h, TaskArg* arg);
int fn_800390A0(Handler* h, TaskArg* arg);
int fn_80039174(Handler* h, TaskArg* arg);
int fn_80039280(Handler* h, TaskArg* arg);
int fn_800393AC(Handler* h, TaskArg* arg);
int fn_800394E4(Handler* h, TaskArg* arg);
int fn_80039604(Handler* h, TaskArg* arg);
int fn_800396D8(Handler* h, TaskArg* arg);
int fn_800397AC(Handler* h, TaskArg* arg);
int fn_80039880(Handler* h, TaskArg* arg);
int fn_80039954(Handler* h, TaskArg* arg);
int fn_80039A28(Handler* h, TaskArg* arg);
int fn_80039AFC(Handler* h, TaskArg* arg);
int fn_80039C38(Handler* h, TaskArg* arg);
int fn_80039D0C(Handler* h, TaskArg* arg);
int fn_80039DE0(Handler* h, TaskArg* arg);
int fn_80039EB4(Handler* h, TaskArg* arg);
int fn_80039F88(Handler* h, TaskArg* arg);
int fn_8003A070(Handler* h, TaskArg* arg);
int fn_8003A190(Handler* h, TaskArg* arg);
int fn_8003A264(Handler* h, TaskArg* arg);
int fn_8003A370(Handler* h, TaskArg* arg);
int fn_8003A75C(Handler* h, TaskArg* arg);
int fn_8003A830(Handler* h, TaskArg* arg);
int fn_8003A904(Handler* h, TaskArg* arg);
int fn_8003A9D8(Handler* h, TaskArg* arg);
int fn_8003AAAC(Handler* h, TaskArg* arg);
int fn_8003ABCC(Handler* h, TaskArg* arg);
int fn_8003AD14(Handler* h, TaskArg* arg);
int fn_8003AE54(Handler* h, TaskArg* arg);
int fn_8003AF7C(Handler* h, TaskArg* arg);
int fn_8003B09C(Handler* h, TaskArg* arg);
int fn_8003B1D8(Handler* h, TaskArg* arg);
int fn_8003B2E0(Handler* h, TaskArg* arg);
int fn_8003B464(Handler* h, TaskArg* arg);
int fn_8003B584(Handler* h, TaskArg* arg);
int fn_8003B708(Handler* h, TaskArg* arg);
int fn_8003B884(Handler* h, TaskArg* arg);
int fn_8003BA08(Handler* h, TaskArg* arg);
int fn_8003BB50(Handler* h, TaskArg* arg);
int fn_8003BC58(Handler* h, TaskArg* arg);
int fn_8003BD78(Handler* h, TaskArg* arg);
int fn_8003BE98(Handler* h, TaskArg* arg);
int fn_8003BF6C(Handler* h, TaskArg* arg);
int fn_8003BF74(Handler* h, TaskArg* arg);
int fn_8003C094(Handler* h, TaskArg* arg);
int fn_8003C1F0(Handler* h, TaskArg* arg);
int fn_8003C2D8(Handler* h, TaskArg* arg);
int fn_8003C400(Handler* h, TaskArg* arg);
int fn_8003C550(Handler* h, TaskArg* arg);
int fn_8003C690(Handler* h, TaskArg* arg);
int fn_8003C764(Handler* h, TaskArg* arg);
int fn_8003C838(Handler* h, TaskArg* arg);
int fn_8003C90C(Handler* h, TaskArg* arg);
int fn_8003C9E0(Handler* h, TaskArg* arg);
int fn_8003CB20(Handler* h, TaskArg* arg);
int fn_8003CC30(Handler* h, TaskArg* arg);
int fn_8003CD04(Handler* h, TaskArg* arg);
int fn_8003CDD8(Handler* h, TaskArg* arg);
int fn_8003CEAC(Handler* h, TaskArg* arg);
int fn_8003D040(Handler* h, TaskArg* arg);
int fn_8003D14C(Handler* h, TaskArg* arg);
int fn_8003D2E4(Handler* h, TaskArg* arg);
int fn_8003D520(Handler* h, TaskArg* arg);
int fn_8003D640(Handler* h, TaskArg* arg);
int fn_8003D780(Handler* h, TaskArg* arg);
int fn_8003D854(Handler* h, TaskArg* arg);
int fn_8003D928(Handler* h, TaskArg* arg);
int fn_8003D9FC(Handler* h, TaskArg* arg);
Node* fn_8003DAD0(void* fn);
Node* fn_8003DB34(void* fn);
int fn_8003DBAC(s32 n, char* buf);
int fn_8003DCF4(void* objp, void* cp);

/* Allocate a task node running `fn` (tasSetTask). fn_8003DAD0 is the same thing as a real
 * function (called by the 0x800368xx-0x8003716C handlers and by other files). */
static inline Node* TaskAlloc(void* fn)
{
    Node* node = fn_802268E8(lbl_803475A8, fn);
    if (node == 0) fn_801DBE1C("Error: tasSetTask");
    if ((u32)node & 0x1F) fn_801DBE1C("Error: tasSetTask align");
    return node;
}

/* TaskAlloc + count the live task (lbl_8030A10C.count); fn_8003DB34 as a function. */
static inline Node* TaskNew(void* fn)
{
    Node* node = TaskAlloc(fn);
    lbl_8030A10C.count++;
    return node;
}
extern int fn_8008F084(Handler* h, TaskArg* arg);
extern int fn_8008F138(Handler* h, TaskArg* arg);
extern int fn_8008F1F8(Handler* h, TaskArg* arg);
/* prototypes */
int fn_80036520(s32 p, void* v);
void fn_80036584(Node* n, s16 v);
s8 fn_800365FC(void);
void fn_80036630(void);
void fn_80036634(void);
void fn_80036638(void);
void fn_8003663C(void);
void fn_80036640(void);
void fn_80036644(void);
void fn_80036648(void);
void fn_8003664C(void);
void fn_80036650(void);
void fn_80036654(void);
void fn_80036658(void);
void fn_8003665C(void);
void fn_80036660(void);
void fn_80036664(void);
void fn_80036668(void);
void fn_8003666C(void);
void fn_80036670(void);
void fn_80036674(void);
void fn_80036678(void);
void fn_8003667C(void);
void fn_80036680(void);
void fn_80036684(void);
void fn_80036688(void);
void fn_8003668C(void);
void fn_80036690(void);
void fn_80036694(void);
void fn_80036698(void);
void fn_8003669C(void);
void fn_800366A0(void);
void fn_800366A4(void);
void fn_800366A8(void);
void fn_800366AC(void);
void fn_800366B0(void);
void fn_800366B4(void);
void fn_800366B8(void);
void fn_800366BC(void);
void fn_800366C0(void);
void fn_800366C4(void);
void fn_800366C8(void);
void fn_800366CC(void);
void fn_800366D0(void);
void fn_800366D4(void);
void fn_800366D8(void);
void fn_800366DC(void);
void fn_800366E0(void);
void fn_800366E4(void);
void fn_800366E8(void);
void fn_800366EC(void);
void fn_800366F0(void);
void fn_800366F4(void);
void fn_800366F8(void);
void fn_800366FC(void);
void fn_80036700(void);
void fn_80036704(void);
void fn_80036708(void);
void fn_8003670C(void);
void fn_80036710(void);
void fn_80036714(void);
void fn_80036718(void);
void fn_8003671C(void);
void fn_80036720(void);
void fn_80036724(void);
void fn_80036728(void);
void fn_8003672C(void);
void fn_80036730(void);
void fn_80036734(void);
void fn_80036738(void);
void fn_8003673C(void);
void fn_80036740(void);
void fn_80036744(void);
void fn_80036748(void);
void fn_8003674C(void);
void fn_80036750(void);
void fn_80036754(void);
void fn_80036758(void);
void fn_8003675C(void);
void fn_80036760(void);
void fn_80036764(void);
void fn_80036768(void);
void fn_8003676C(void);
void fn_80036770(void);
void fn_80036774(void);
void fn_80036778(void);
void fn_8003677C(void);
void fn_80036780(void);
void fn_80036784(void);
void fn_80036788(void);
void fn_8003678C(void);
void fn_80036790(void);
TaskFunc fn_80036794(u32 key, TaskEnt* tbl, s16 end);
int fn_800367E8(u32 key, void* x, void* y);
int fn_80036880(Handler* h, TaskArg* arg);
int fn_80036914(Handler* h, TaskArg* arg);
int fn_800369A4(Handler* h, TaskArg* arg);
int fn_80036A38(Handler* h, TaskArg* arg);
int fn_80036AE4(Handler* h, TaskArg* arg);
int fn_80036B88(Handler* h, TaskArg* arg);
int fn_80036C1C(Handler* h, TaskArg* arg);
int fn_80036CB0(Handler* h, TaskArg* arg);
int fn_80036D5C(Handler* h, TaskArg* arg);
int fn_80036E18(Handler* h, TaskArg* arg);
int fn_80036EC4(Handler* h, TaskArg* arg);
int fn_80036F70(Handler* h, TaskArg* arg);
int fn_8003701C(Handler* h, TaskArg* arg);
int fn_800370C8(Handler* h, TaskArg* arg);
int fn_8003716C(Handler* h, TaskArg* arg);
int fn_80037250(Handler* h, TaskArg* arg);
void fn_800372E0(void);
void fn_800372E4(void);
void fn_800372E8(void);
void fn_800372EC(void);
void fn_800372F0(void);
void fn_800372F4(void);
void fn_800372F8(void);
void fn_800372FC(void);
void fn_80037300(void);
void fn_80037304(void);
void fn_80037308(void);
void fn_8003730C(void);
void fn_80037310(void);
void fn_80037314(void);
void fn_80037318(void);
void fn_8003731C(void);
void fn_80037320(void);
void fn_80037324(void);
void fn_80037328(void);
int fn_8003732C(u32 key, void* a, void* b);
int fn_800377FC(ChunkHdr* m);
void fn_80037918(TaskObj* obj);
void fn_80037AF0(Node* node);
void fn_80037EB4(void);
int fn_80037FD8(Ent_80037FD8* e, u8* out);
void fn_8003801C(void);
int fn_80038078(Handler* h, TaskArg* arg);
int fn_80038140(Handler* h, TaskArg* arg);
int fn_80038208(Handler* h, TaskArg* arg);
int fn_800382D0(Handler* h, TaskArg* arg);
int fn_80038398(Handler* h, TaskArg* arg);
int fn_80038460(Handler* h, TaskArg* arg);
int fn_80038534(Handler* h, TaskArg* arg);
int fn_80038654(Handler* h, TaskArg* arg);
int fn_80038774(Handler* h, TaskArg* arg);
int fn_80038848(Handler* h, TaskArg* arg);
int fn_8003891C(Handler* h, TaskArg* arg);
int fn_800389F0(Handler* h, TaskArg* arg);
int fn_80038AC4(Handler* h, TaskArg* arg);
int fn_80038B98(Handler* h, TaskArg* arg);
int fn_80038CB8(Handler* h, TaskArg* arg);
int fn_80038D8C(Handler* h, TaskArg* arg);
int fn_80038EAC(Handler* h, TaskArg* arg);
int fn_80038F80(Handler* h, TaskArg* arg);
int fn_800390A0(Handler* h, TaskArg* arg);
int fn_80039174(Handler* h, TaskArg* arg);
int fn_80039280(Handler* h, TaskArg* arg);
int fn_800393AC(Handler* h, TaskArg* arg);
int fn_800394E4(Handler* h, TaskArg* arg);
int fn_80039604(Handler* h, TaskArg* arg);
int fn_800396D8(Handler* h, TaskArg* arg);
int fn_800397AC(Handler* h, TaskArg* arg);
int fn_80039880(Handler* h, TaskArg* arg);
int fn_80039954(Handler* h, TaskArg* arg);
int fn_80039A28(Handler* h, TaskArg* arg);
int fn_80039AFC(Handler* h, TaskArg* arg);
int fn_80039C38(Handler* h, TaskArg* arg);
int fn_80039D0C(Handler* h, TaskArg* arg);
int fn_80039DE0(Handler* h, TaskArg* arg);
int fn_80039EB4(Handler* h, TaskArg* arg);
int fn_80039F88(Handler* h, TaskArg* arg);
int fn_8003A070(Handler* h, TaskArg* arg);
int fn_8003A190(Handler* h, TaskArg* arg);
int fn_8003A264(Handler* h, TaskArg* arg);
int fn_8003A370(Handler* h, TaskArg* arg);
int fn_8003A75C(Handler* h, TaskArg* arg);
int fn_8003A830(Handler* h, TaskArg* arg);
int fn_8003A904(Handler* h, TaskArg* arg);
int fn_8003A9D8(Handler* h, TaskArg* arg);
int fn_8003AAAC(Handler* h, TaskArg* arg);
int fn_8003ABCC(Handler* h, TaskArg* arg);
int fn_8003AD14(Handler* h, TaskArg* arg);
int fn_8003AE54(Handler* h, TaskArg* arg);
int fn_8003AF7C(Handler* h, TaskArg* arg);
int fn_8003B09C(Handler* h, TaskArg* arg);
int fn_8003B1D8(Handler* h, TaskArg* arg);
int fn_8003B2E0(Handler* h, TaskArg* arg);
int fn_8003B464(Handler* h, TaskArg* arg);
int fn_8003B584(Handler* h, TaskArg* arg);
int fn_8003B708(Handler* h, TaskArg* arg);
int fn_8003B884(Handler* h, TaskArg* arg);
int fn_8003BA08(Handler* h, TaskArg* arg);
int fn_8003BB50(Handler* h, TaskArg* arg);
int fn_8003BC58(Handler* h, TaskArg* arg);
int fn_8003BD78(Handler* h, TaskArg* arg);
int fn_8003BE98(Handler* h, TaskArg* arg);
int fn_8003BF6C(Handler* h, TaskArg* arg);
int fn_8003BF74(Handler* h, TaskArg* arg);
int fn_8003C094(Handler* h, TaskArg* arg);
int fn_8003C1F0(Handler* h, TaskArg* arg);
int fn_8003C2D8(Handler* h, TaskArg* arg);
int fn_8003C400(Handler* h, TaskArg* arg);
int fn_8003C550(Handler* h, TaskArg* arg);
int fn_8003C690(Handler* h, TaskArg* arg);
int fn_8003C764(Handler* h, TaskArg* arg);
int fn_8003C838(Handler* h, TaskArg* arg);
int fn_8003C90C(Handler* h, TaskArg* arg);
int fn_8003C9E0(Handler* h, TaskArg* arg);
int fn_8003CB20(Handler* h, TaskArg* arg);
int fn_8003CC30(Handler* h, TaskArg* arg);
int fn_8003CD04(Handler* h, TaskArg* arg);
int fn_8003CDD8(Handler* h, TaskArg* arg);
int fn_8003CEAC(Handler* h, TaskArg* arg);
int fn_8003D040(Handler* h, TaskArg* arg);
int fn_8003D14C(Handler* h, TaskArg* arg);
int fn_8003D2E4(Handler* h, TaskArg* arg);
int fn_8003D520(Handler* h, TaskArg* arg);
int fn_8003D640(Handler* h, TaskArg* arg);
int fn_8003D780(Handler* h, TaskArg* arg);
int fn_8003D854(Handler* h, TaskArg* arg);
int fn_8003D928(Handler* h, TaskArg* arg);
int fn_8003D9FC(Handler* h, TaskArg* arg);
Node* fn_8003DAD0(void* fn);
Node* fn_8003DB34(void* fn);
int fn_8003DBAC(s32 n, char* buf);
int fn_8003DCF4(void* objp, void* cp);
int fn_8003DE8C(s16 type, s16 id, s16 wtype, s16 wid);
TaskEnt lbl_802DD238[] = {
    { 0x0, 3, "UPSMOKE", fn_8003677C, fn_8003B2E0 },
    { 0x1, 3, "UPCIRCLE", fn_80036770, fn_8003B584 },
    { 0x11, 3, "UPCIRCLEEX", fn_8003676C, fn_8003B708 },
    { 0x2, 3, "SPARC", fn_80036768, fn_8003BA08 },
    { 0x3, 3, "PUTMODEL", fn_80036744, fn_8003AF7C },
    { 0x4, 3, "SET COMMAND", fn_80036788, fn_8003B1D8 },
    { 0x5, 3, "PUTMODEL EX", fn_8003670C, fn_8003D640 },
    { 0x6, 3, "PUTITEM", fn_800366EC, fn_8003D2E4 },
    { 0x7, 3, "DAMAGE SET", fn_80036784, 0 },
    { 0x8, 3, "UPSMOKE EX", fn_80036774, fn_8003B464 },
    { 0x9, 3, "POLYBORD", fn_800366F8, fn_8003D14C },
    { 0xA, 3, "MOTION PAUSE", fn_800366F0, fn_8003D040 },
    { 0xB, 3, "COLISION BOX", fn_80036754, fn_8003C9E0 },
    { 0xC, 3, "MOVE MODEL", fn_80036710, fn_8003C550 },
    { 0xD, 3, "HIT WEAPON", fn_80036724, fn_8003C400 },
    { 0xE, 3, "FACECHANGE", fn_80036748, fn_8003C094 },
    { 0xF, 3, "STAGE FADE", fn_800366FC, fn_8003CB20 },
    { 0x10, 3, "WEAPON CONT", fn_80036764, fn_8003CEAC },
    { 0x12, 3, "FADE MODEL", fn_80036700, fn_8003AD14 },
    { 0x13, 3, "TARGET MODEL", fn_80036708, fn_8003ABCC },
    { 0x14, 3, "TARGET SPR", fn_80036704, fn_8003BF74 },
    { 0x15, 3, "FLAIREWING", fn_8003671C, fn_8003BF6C },
    { 0x16, 3, "CHARA COLOR", fn_800366F4, fn_8003BE98 },
    { 0x17, 3, "POLYWALL", fn_8003672C, fn_8003BD78 },
    { 0x18, 3, "TEXCHANGE", fn_80036780, fn_8003BC58 },
    { 0x19, 3, "PUTCOPYMODEL", fn_80036728, fn_8003BB50 },
    { 0x1A, 3, "SMOKE", fn_800366E8, fn_8003B884 },
    { 0x1B, 3, "TEXSCREEN", fn_80036730, fn_8003B09C },
    { 0x1C, 3, "THUNDER", fn_800366E4, fn_8003AAAC },
    { 0x1D, 3, "POINT LIGHT", fn_80036734, fn_8003D9FC },
    { 0x1E, 3, "STAGE LIGHT", fn_80036738, fn_8003D780 },
    { 0x1F, 3, "MOTION CAMERA", fn_8003673C, fn_8003D520 },
    { 0x20, 3, "CHARA FADE", fn_8003675C, fn_8003CD04 },
    { 0x21, 3, "RANBU HAICHI", fn_80036758, fn_8003CC30 },
    { 0x22, 3, "STAGE COLOR", fn_80036760, fn_8003CDD8 },
    { 0x23, 3, "ALLHIT", fn_80036750, fn_8003C90C },
    { 0x24, 3, "CALL EFFECT", fn_8003674C, fn_8003C838 },
    { 0x25, 3, "DRAQMA HAND", fn_80036720, fn_8003C2D8 },
    { 0x26, 3, "CHARA BREAK", fn_80036714, fn_8003C1F0 },
    { 0x27, 3, "SET PAUSE", fn_8003678C, fn_8003D928 },
    { 0x28, 3, "CHARASHADOW", fn_80036740, fn_8003AE54 },
    { 0x29, 3, "RANGEHIT", fn_80036718, fn_8003C764 },
    { 0x2A, 3, "SYSTEM CAMERA", fn_80036778, fn_8003C690 },
    { 0x2B, 3, "PAUSE RANGE", fn_800366E0, fn_8003A9D8 },
    { 0x2C, 3, "CHARA PRESS", fn_800366DC, fn_8003A904 },
    { 0x2D, 3, "MODEL BIND", fn_800366D8, fn_8003A830 },
    { 0x2E, 3, "ICON CONTROLL", fn_800366D4, fn_8003A75C },
    { 0x2F, 3, "UPSMOKE SP", fn_800366D0, fn_8003A370 },
    { 0x30, 3, "SCREENSHOT", fn_800366CC, fn_8003A264 },
    { 0x31, 3, "CONE COLISION", fn_800366C8, fn_8003A190 },
    { 0x32, 3, "EFFECT WAIT", fn_800366C4, 0 },
    { 0x33, 3, "PARTICLE SPR", fn_800366C0, fn_8003A070 },
    { 0x34, 3, "ZOOM SCREEN", fn_800366BC, fn_80039F88 },
    { 0x35, 3, "DEBUG FRAME", fn_800366B8, fn_80039EB4 },
    { 0x36, 3, "SE REQUEST", fn_800366B4, fn_80039DE0 },
    { 0x37, 3, "RANGE FADE", fn_800366B0, fn_80039D0C },
    { 0x38, 3, "OFFSET MOVE", fn_800366AC, fn_80039C38 },
    { 0x39, 3, "TEXSCREENEX", fn_800366A8, fn_80039AFC },
    { 0x3A, 3, "MAGIC HAICHI", fn_800366A4, fn_80039A28 },
    { 0x3B, 3, "STREAM SET", fn_800366A0, fn_80039954 },
    { 0x3C, 3, "DRAGONMOVE", fn_8003669C, fn_80039880 },
    { 0x3D, 3, "TOKUSHUTAIKI", fn_80036698, fn_800397AC },
    { 0x3E, 3, "CAMERA EFFECT", fn_80036694, fn_80039604 },
    { 0x3F, 3, "MOTION BIND", fn_80036690, fn_800394E4 },
    { 0x40, 3, "MOTION PAUSE2", fn_8003668C, fn_800393AC },
    { 0x41, 3, "MLDLINK SET", fn_80036688, 0 },
    { 0x42, 3, "SCREEN BULLER", fn_80036684, fn_80039280 },
    { 0x43, 3, "TEXCOPYMODEL", fn_80036680, fn_80039174 },
    { 0x44, 3, "ENVTEXFADE", fn_8003667C, fn_800390A0 },
    { 0x45, 3, "MOTION BIND+", fn_80036678, fn_80038F80 },
    { 0x46, 3, "SPARC MODEL", fn_80036674, fn_8003BA08 },
    { 0x47, 3, "CHARA UV", fn_80036670, fn_80038EAC },
    { 0x48, 3, "PUTMODEL SP", fn_80036744, fn_80038D8C },
    { 0x49, 3, "CALL CHARA", fn_8003666C, fn_80038CB8 },
    { 0x4A, 3, "UPSMOKE DX", fn_80036668, fn_80038B98 },
    { 0x4B, 3, "GATTAI HAICHI", fn_80036664, fn_80038AC4 },
    { 0x4C, 3, "PARTS SWITCH", fn_80036660, fn_800389F0 },
    { 0x4D, 3, "CREW WAZA", fn_8003665C, fn_8003891C },
    { 0x4E, 3, "MOTION LOAD", fn_80036658, 0 },
    { 0x4F, 3, "MAGIC HAICHI2", fn_80036654, fn_80038848 },
    { 0x50, 3, "SET PAUSE EX", fn_80036790, fn_8003D854 },
    { 0x51, 3, "STAGE LIGHT2", fn_80036650, fn_80038774 },
    { 0x52, 3, "DUPLIMOTION", fn_8003664C, fn_80038654 },
    { 0x53, 3, "PUTMODEL-", fn_80036648, fn_80038534 },
    { 0x54, 3, "HIGH SHD", fn_80036644, fn_80038460 },
    { 0x55, 3, "PUL PACK", fn_80036640, fn_800396D8 },
    { 0x56, 3, "SCREEN EFF", fn_8003663C, fn_80038398 },
    { 0x57, 3, "EXT CHARA", fn_80036638, fn_800382D0 },
    { 0x58, 3, "SYS CAMERA2", fn_80036634, fn_80038208 },
    { 0x59, 3, "ALL FADE OUT", fn_80036630, fn_80038140 },
    { 0x5A, 3, "REVIVE STOP", fn_80036630, fn_80038078 },
    { 0x5B, 3, "END CODE", 0, 0 },
};
TaskEnt lbl_802DE208[] = {
    { 0x0, 5, "(SAMPLE)", fn_80037328, fn_80037250 },
    { 0x1, 5, "SET POS(FP)", fn_80037324, fn_8003716C },
    { 0x2, 5, "BOUND(FP)", fn_80037320, fn_800370C8 },
    { 0x3, 5, "SET ANG1(FP)", fn_8003731C, fn_8003701C },
    { 0x4, 5, "SET ANG2(FP)", fn_80037318, fn_80036F70 },
    { 0x5, 5, "INIT POS(FP)", fn_80037314, fn_80036EC4 },
    { 0x6, 5, "PUB ANG(FP)", fn_80037310, fn_80036E18 },
    { 0x7, 5, "FP ATTACK(FP)", fn_8003730C, fn_80036D5C },
    { 0x8, 5, "FP DROP(FP)", fn_80037308, fn_80036CB0 },
    { 0x9, 5, "FP FLOAT(FP)", fn_80037304, fn_80036C1C },
    { 0xA, 5, "FP WAIT(FP)", fn_80037300, fn_80036B88 },
    { 0xB, 5, "FP DAMAGE(FP)", fn_800372FC, fn_80036AE4 },
    { 0xC, 5, "MOT PLAY(FP)", fn_800372F8, fn_80036A38 },
    { 0xD, 5, "INIT DIR(FP)", fn_800372F4, fn_800369A4 },
    { 0xE, 5, "MOVING FAR ATC", fn_800372F0, fn_8008F1F8 },
    { 0xF, 5, "FP FADE(FP)", fn_800372EC, fn_80036914 },
    { 0x10, 5, "PARTS BREAK", fn_800372E8, fn_8008F138 },
    { 0x11, 5, "DIE PATTERN", fn_800372E4, fn_8008F084 },
    { 0x12, 5, "NOMDAMAGE(FP)", fn_800372E0, fn_80036880 },
    { 0x13, 5, "END CODE", 0, 0 },
};


/* Inline copy of fn_80036794's table search (locals in a different order). */
inline TaskFunc TaskLookup(u32 key, TaskEnt* tbl, s16 end)
{
    s16 a;
    TaskEnt* e;
    s16 i = 0;
    e = tbl;
    for (;;) {
        a = e->a;
        if (end != a) {
            if (key == (u32)(e->b << 16 | a)) return tbl[i].fn;
            e++;
            i++;
            continue;
        }
        break;
    }
    return 0;
}
inline int TaskCall(u32 key, void* a, void* b)
{
    TaskFunc fn = fn_80036794(key, lbl_802DE208, 0x13);
    if (fn) return fn(a, b);
    return 0;
}
inline void ClearStats(void)
{
    lbl_8030A10C.x1c8 = 0;
    lbl_8030A10C.flags &= ~0x80;
    lbl_8030A10C.flags &= ~0x40;
    lbl_8030A10C.flags &= ~0x20;
    lbl_8030A10C.flags &= ~0x10;
}
inline void SavePartyPos(void)
{
    s16 i;
    TaskRes_80037918* r;
    for (i = 0; i < 12; i++) {
        if (lbl_80309E24[i]) {
            r = lbl_80309E24[i]->info->data;
            fn_80071CF0(&r->x13c, &lbl_803472EC->a[i]);
            fn_800614FC(&r->x148, &lbl_803472EC->b[i]);
        }
    }
}
inline int TargetMatch(s16 type, int wtype, s16 id, int wid)
{
    if (type == wtype) {
        switch (type) {
        case 0x18:
        case 0x1d:
        case 0x1e:
            if (wid == id) return 1;
            break;
        default:
            return 1;
        }
    }
    return 0;
}
int fn_8003DE8C(s16 type, s16 id, s16 wtype, s16 wid)
{
    return TargetMatch(type, wtype, id, wid);
}
int fn_8003DCF4(void* objp, void* cp)
{
    TaskTarget* obj = objp;
    TaskCond* c = cp;
    int result = 0;
    if (c->x6 == 0xb || c->x6 == 0x20) {
        if (obj->x2 != 2) return 0;
        result = TargetMatch(obj->type, c->x4a, obj->id, c->x4c);
        if (c->xec & 0x1000) result = TargetMatch(obj->type, 0x20, obj->id, c->x4c);
    }
    if (!(c->xec & 0x800)) {
        if (TargetMatch(c->x6, obj->type, c->x8, obj->id)) result = 1;
    }
    if (c->xec & 0x4000) result = TargetMatch(obj->type, c->x56, obj->id, c->x58);
    return result;
}
int fn_8003DBAC(s32 n, char* buf)
{
    char letters[4] = "ABG";
    if (n == 9999999) return 0;
    if (n >= 10000000) {
        s16 idx;
        n -= 10000000;
        idx = n / 1000;
        n = (s16)(n % 1000);
        if (idx >= 3) idx = 0;
        sprintf(buf, "M%c%03d.MLD", letters[idx], n);
    } else {
        s16 a = n / 100000;
        s16 b;
        s16 c;
        n = (s16)(n % 100000);
        b = n / 100;
        c = n % 100;
        sprintf(buf, "E%02d%03d%02d.MLD", a, b, c);
    }
    return 1;
}

Node* fn_8003DB34(void* fn)
{
    return TaskNew(fn);
}
Node* fn_8003DAD0(void* fn)
{
    return TaskAlloc(fn);
}
int fn_8003D9FC(Handler* h, TaskArg* arg)
{
    void* obj = h->obj;
    Node* node;
    Work_8003D9FC* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = TaskNew(fn_8004F868);
        fn_80061F58((u8*)node + 0x24, 0xac, 0);
        w = node->work;
        w->owner = obj;
        w->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_8003D928(Handler* h, TaskArg* arg)
{
    void* obj = h->obj;
    Node* node;
    Work_8003D928* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = TaskNew(fn_80054DD8);
        fn_80061F58((u8*)node + 0x24, 0x14, 0);
        w = node->work;
        w->owner = obj;
        w->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_8003D854(Handler* h, TaskArg* arg)
{
    void* obj = h->obj;
    Node* node;
    Work_8003D854* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = TaskNew(fn_80054B74);
        fn_80061F58((u8*)node + 0x24, 0x14, 0);
        w = node->work;
        w->owner = obj;
        w->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_8003D780(Handler* h, TaskArg* arg)
{
    void* obj = h->obj;
    Node* node;
    Work_8003D780* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = TaskNew(fn_8004EEF0);
        fn_80061F58((u8*)node + 0x24, 0xf0, 0);
        w = node->work;
        w->owner = obj;
        w->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_8003D640(Handler* h, TaskArg* arg)
{
    Obj_8003D640* obj = h->obj;
    Node* node;
    Work_8003D640* w;
    Sub_8003D640* s;
    Buf_8003D640 buf;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        fn_80036520(obj->src, &buf);
        node = TaskNew(fn_800454A0);
        fn_80061F58((u8*)node + 0x24, 0x58, 0);
        w = node->work;
        w->buf = buf;
        fn_80061F58(&w->sub, 0x1c4, 0);
        s = w->sub;
        s->copy = *obj;
        s->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_8003D520(Handler* h, TaskArg* arg)
{
    Obj_8003D520* obj = h->obj;
    Node* node;
    Work_8003D520* w;
    Sub_8003D520* s;
    Buf_8003D520 buf;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        fn_80036520(obj->src, &buf);
        node = TaskNew(fn_8004E7F0);
        fn_80061F58((u8*)node + 0x24, 0x58, 0);
        w = node->work;
        w->buf = buf;
        fn_80061F58(&w->sub, 0xc4, 0);
        s = w->sub;
        s->owner = obj;
        s->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_8003D2E4(Handler* h, TaskArg* arg)
{
    Node* node;
    Work_8003D2E4* w;
    Obj_8003D2E4* obj = h->obj;
    Sub_8003D2E4* s;
    u8* res = arg->res->x4c;
    s8 a, b;
    s32 id;
    char name[0x20];
    Buf_8003D2E4 buf;
    if (fn_8003DCF4(obj, res)) {
        a = fn_80020E10(arg->res->x10->xc);
        b = fn_8000FA30(*res);
        if (obj->src % 10 == 0) {
            sprintf(name, "E99%02d%02d0", a, b);
            fn_80046BB0(name, &id);
            fn_80036520(id, &buf);
        } else if (b == 0x10 || b == 0x11) {
            sprintf(name, "E99%02d%02d1", a, b);
            fn_80046BB0(name, &id);
            fn_80036520(id, &buf);
        } else {
            fn_80036520(obj->src, &buf);
        }
        node = TaskNew(fn_8000FC14);
        lbl_8030A10C.count--;
        fn_80061F58((u8*)node + 0x24, 0x58, 0);
        w = node->work;
        w->buf = buf;
        fn_80061F58(&w->sub, 0x50, 0);
        s = w->sub;
        s->copy = *obj;
        s->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_8003D14C(Handler* h, TaskArg* arg)
{
    Obj_8003D14C* obj = h->obj;
    u8* res = arg->res->x4c;
    Node* node;
    Work_8003D14C* w;
    Sub_8003D14C* s;
    Buf_8003D14C buf;
    if (fn_8003DCF4(obj, res)) {
        if ((obj->flags & 0x8000) && obj->x45 != 0xFF && obj->x45 != fn_8000FA30(*res)) return 0;
        if (obj->src) fn_80036520(obj->src, &buf); else memset(&buf, 0, sizeof(buf));
        node = TaskNew(fn_8004C1E4);
        fn_80061F58((u8*)node + 0x24, 0x58, 0);
        w = node->work;
        w->buf = buf;
        fn_80061F58(&w->sub, 0x70, 0);
        s = w->sub;
        s->copy = *obj;
        s->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_8003D040(Handler* h, TaskArg* arg)
{
    Obj_8003D040* obj = h->obj;
    Node* node;
    Work_8003D040* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = TaskNew(fn_8004C070);
        fn_80061F58((u8*)node + 0x24, 0x6c, 0);
        w = node->work;
        w->copy = *obj;
        w->arg = arg;
        w->copy.flags |= 0x2000;
    } else {
        return 0;
    }
    return 1;
}
int fn_8003CEAC(Handler* h, TaskArg* arg)
{
    Obj_8003CEAC* obj = h->obj;
    Node* node;
    Work_8003CEAC* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        if (fn_80020E10(arg->res->x10->xc) == 2) {
            node = TaskNew(fn_8004AD38);
        } else {
            node = TaskNew(fn_8004AFD8);
        }
        fn_80061F58((u8*)node + 0x24, 0x3c, 0);
        w = node->work;
        w->copy = *obj;
        w->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_8003CDD8(Handler* h, TaskArg* arg)
{
    void* obj = h->obj;
    Node* node;
    Work_8003CDD8* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = TaskNew(fn_80050B88);
        fn_80061F58((u8*)node + 0x24, 0x10, 0);
        w = node->work;
        w->owner = obj;
        w->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_8003CD04(Handler* h, TaskArg* arg)
{
    void* obj = h->obj;
    Node* node;
    Work_8003CD04* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = TaskNew(fn_8004FF8C);
        fn_80061F58((u8*)node + 0x24, 0x24, 0);
        w = node->work;
        w->owner = obj;
        w->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_8003CC30(Handler* h, TaskArg* arg)
{
    void* obj = h->obj;
    Node* node;
    Work_8003CC30* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = TaskNew(fn_800506B0);
        fn_80061F58((u8*)node + 0x24, 0x34, 0);
        w = node->work;
        w->owner = obj;
        w->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_8003CB20(Handler* h, TaskArg* arg)
{
    Obj_8003CB20* obj = h->obj;
    Node* node;
    Work_8003CB20* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = TaskNew(fn_8004A028);
        fn_80061F58((u8*)node + 0x24, 0x2c, 0);
        w = node->work;
        w->copy = *obj;
    } else {
        return 0;
    }
    return 1;
}
int fn_8003C9E0(Handler* h, TaskArg* arg)
{
    Obj_8003C9E0* obj = h->obj;
    Node* node;
    Work_8003C9E0* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = TaskNew(fn_8004B7C4);
        fn_80061F58((u8*)node + 0x24, 0x5c, 0);
        w = node->work;
        w->copy = *obj;
        w->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_8003C90C(Handler* h, TaskArg* arg)
{
    void* obj = h->obj;
    Node* node;
    Work_8003C90C* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = TaskNew(fn_8004E474);
        fn_80061F58((u8*)node + 0x24, 0x30, 0);
        w = node->work;
        w->owner = obj;
        w->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_8003C838(Handler* h, TaskArg* arg)
{
    void* obj = h->obj;
    Node* node;
    Work_8003C838* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = TaskNew(fn_80050DB0);
        fn_80061F58((u8*)node + 0x24, 0xc, 0);
        w = node->work;
        w->owner = obj;
        w->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_8003C764(Handler* h, TaskArg* arg)
{
    void* obj = h->obj;
    Node* node;
    Work_8003C764* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = TaskNew(fn_800541E0);
        fn_80061F58((u8*)node + 0x24, 0x24, 0);
        w = node->work;
        w->owner = obj;
        w->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_8003C690(Handler* h, TaskArg* arg)
{
    void* obj = h->obj;
    Node* node;
    Work_8003C690* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = TaskNew(fn_80051264);
        fn_80061F58((u8*)node + 0x24, 0x17c, 0);
        w = node->work;
        w->owner = obj;
        w->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_8003C550(Handler* h, TaskArg* arg)
{
    Obj_8003C550* obj = h->obj;
    Node* node;
    Work_8003C550* w;
    Sub_8003C550* s;
    Buf_8003C550 buf;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        fn_80036520(obj->src, &buf);
        node = TaskNew(fn_80044B24);
        fn_80061F58((u8*)node + 0x24, 0x58, 0);
        w = node->work;
        w->buf = buf;
        fn_80061F58(&w->sub, 0x1c0, 0);
        s = w->sub;
        s->copy = *obj;
        s->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_8003C400(Handler* h, TaskArg* arg)
{
    Obj_8003C400* obj = h->obj;
    Node* node;
    Work_8003C400* w;
    Sub_8003C400* s;
    Buf_8003C400* buf;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        fn_800102C8(arg, 1, &buf);
        node = TaskNew(fn_8004A40C);
        fn_80061F58((u8*)node + 0x24, 0x58, 0);
        w = node->work;
        w->buf = *buf;
        fn_80061F58(&w->sub, 0x1a0, 0);
        s = w->sub;
        s->copy = *obj;
        s->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_8003C2D8(Handler* h, TaskArg* arg)
{
    void* obj = h->obj;
    Node* node;
    Work_8003C2D8* w;
    Sub_8003C2D8* s;
    Buf_8003C2D8* buf;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        fn_800102C8(arg, 1, &buf);
        node = TaskNew(fn_8004DE48);
        fn_80061F58((u8*)node + 0x24, 0x58, 0);
        w = node->work;
        w->buf = *buf;
        fn_80061F58(&w->sub, 0x20, 0);
        s = w->sub;
        s->owner = obj;
        s->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_8003C1F0(Handler* h, TaskArg* arg)
{
    void* obj = h->obj;
    Node* node;
    Work_8003C1F0* w;
    Sub_8003C1F0* s;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = TaskNew(fn_80055058);
        fn_80061F58((u8*)node + 0x24, 0x58, 0);
        w = node->work;
        fn_80061F58(&w->sub, 0x18, 0);
        s = w->sub;
        s->owner = obj;
        s->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_8003C094(Handler* h, TaskArg* arg)
{
    Obj_8003C094* obj = h->obj;
    Node* node;
    Work_8003C094* w;
    Sub_8003C094* s;
    Buf_8003C094 buf;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        if (obj->src) fn_80036520(obj->src, &buf);
        node = TaskNew(fn_8004A260);
        fn_80061F58((u8*)node + 0x24, 0x58, 0);
        w = node->work;
        if (obj->src) w->buf = buf;
        fn_80061F58(&w->sub, 0x124, 0);
        s = w->sub;
        s->copy = *obj;
        s->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_8003BF74(Handler* h, TaskArg* arg)
{
    Obj_8003BF74* obj = h->obj;
    Node* node;
    Work_8003BF74* w;
    Sub_8003BF74* s;
    Buf_8003BF74 buf;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        fn_80036520(obj->src, &buf);
        node = TaskNew(fn_80040AA0);
        fn_80061F58((u8*)node + 0x24, 0x58, 0);
        w = node->work;
        w->buf = buf;
        fn_80061F58(&w->sub, 0x38, 0);
        s = w->sub;
        s->owner = obj;
        s->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_8003BF6C(Handler* h, TaskArg* arg)
{
    return 1;
}
int fn_8003BE98(Handler* h, TaskArg* arg)
{
    void* obj = h->obj;
    Node* node;
    Work_8003BE98* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = TaskNew(fn_8004D828);
        fn_80061F58((u8*)node + 0x24, 0x10, 0);
        w = node->work;
        w->owner = obj;
        w->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_8003BD78(Handler* h, TaskArg* arg)
{
    Obj_8003BD78* obj = h->obj;
    Node* node;
    Work_8003BD78* w;
    Sub_8003BD78* s;
    Buf_8003BD78 buf;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        fn_80036520(obj->src, &buf);
        node = TaskNew(fn_8004D378);
        fn_80061F58((u8*)node + 0x24, 0x58, 0);
        w = node->work;
        w->buf = buf;
        fn_80061F58(&w->sub, 0x54, 0);
        s = w->sub;
        s->owner = obj;
        s->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_8003BC58(Handler* h, TaskArg* arg)
{
    Obj_8003BC58* obj = h->obj;
    Node* node;
    Work_8003BC58* w;
    Sub_8003BC58* s;
    Buf_8003BC58 buf;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        fn_80036520(obj->src, &buf);
        node = TaskNew(fn_8004DB90);
        fn_80061F58((u8*)node + 0x24, 0x58, 0);
        w = node->work;
        w->buf = buf;
        fn_80061F58(&w->sub, 0x8, 0);
        s = w->sub;
        s->owner = obj;
        s->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_8003BB50(Handler* h, TaskArg* arg)
{
    s16 i;
    Obj_8003BB50* obj = h->obj;
    Node* node;
    Work_8003BB50* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        for (i = obj->start; i < obj->end; i++) {
            if (i % obj->mod == 0) {
                node = TaskNew(fn_80049DC0);
                fn_80061F58((u8*)node + 0x24, 0x64, 0);
                w = node->work;
                w->owner = obj;
                w->arg = arg;
                w->idx = i;
                w->next = w->idx + 1;
            }
        }
    } else {
        return 0;
    }
    return 1;
}
int fn_8003BA08(Handler* h, TaskArg* arg)
{
    Obj_8003BA08* obj = h->obj;
    Node* node;
    Work_8003BA08* w;
    Sub_8003BA08* s;
    Buf_8003BA08 buf;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        fn_80036520(obj->src, &buf);
        node = TaskNew(fn_80042B10);
        fn_80061F58((u8*)node + 0x24, 0x58, 0);
        w = node->work;
        w->buf = buf;
        fn_80061F58(&w->sub, 0x18c, 0);
        s = w->sub;
        s->copy = *obj;
        s->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_8003B884(Handler* h, TaskArg* arg)
{
    s16 i;
    Obj_8003B884* obj = h->obj;
    Node* node;
    Work_8003B884* w;
    Sub_8003B884* s;
    Buf_8003B884 buf;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        fn_80036520(obj->src, &buf);
        for (i = 0; i < obj->count; i++) {
            node = TaskNew(fn_800405EC);
            fn_80061F58((u8*)node + 0x24, 0x58, 0);
            w = node->work;
            w->buf = buf;
            fn_80061F58(&w->sub, 0x184, 0);
            s = w->sub;
            s->copy = *obj;
            s->arg = arg;
            s->x = obj->x + i * obj->step;
            s->y = obj->y + i * obj->step;
        }
    } else {
        return 0;
    }
    return 1;
}
int fn_8003B708(Handler* h, TaskArg* arg)
{
    s16 i;
    Obj_8003B708* obj = h->obj;
    Node* node;
    Work_8003B708* w;
    Sub_8003B708* s;
    Buf_8003B708 buf;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        fn_80036520(obj->src, &buf);
        for (i = 0; i < obj->count; i++) {
            node = TaskNew(fn_80043C24);
            fn_80061F58((u8*)node + 0x24, 0x58, 0);
            w = node->work;
            w->buf = buf;
            fn_80061F58(&w->sub, 0x7c, 0);
            s = w->sub;
            s->copy = *obj;
            s->copy.x += i * obj->step;
            s->copy.y += i * obj->step;
            s->arg = arg;
        }
    } else {
        return 0;
    }
    return 1;
}
int fn_8003B584(Handler* h, TaskArg* arg)
{
    s16 i;
    Obj_8003B584* obj = h->obj;
    Node* node;
    Work_8003B584* w;
    Sub_8003B584* s;
    Buf_8003B584 buf;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        fn_80036520(obj->src, &buf);
        for (i = 0; i < obj->count; i++) {
            node = TaskNew(fn_80044178);
            fn_80061F58((u8*)node + 0x24, 0x58, 0);
            w = node->work;
            w->buf = buf;
            fn_80061F58(&w->sub, 0x54, 0);
            s = w->sub;
            s->copy = *obj;
            s->copy.x += i * obj->step;
            s->copy.y += i * obj->step;
            s->arg = arg;
        }
    } else {
        return 0;
    }
    return 1;
}
int fn_8003B464(Handler* h, TaskArg* arg)
{
    Obj_8003B464* obj = h->obj;
    Node* node;
    Work_8003B464* w;
    Sub_8003B464* s;
    Buf_8003B464 buf;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        fn_80036520(obj->src, &buf);
        node = TaskNew(fn_80041E64);
        fn_80061F58((u8*)node + 0x24, 0x58, 0);
        w = node->work;
        w->buf = buf;
        fn_80061F58(&w->sub, 0x90, 0);
        s = w->sub;
        s->owner = obj;
        s->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_8003B2E0(Handler* h, TaskArg* arg)
{
    s16 i;
    Obj_8003B2E0* obj = h->obj;
    Node* node;
    Work_8003B2E0* w;
    Sub_8003B2E0* s;
    Buf_8003B2E0 buf;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        fn_80036520(obj->src, &buf);
        for (i = 0; i < obj->count; i++) {
            node = TaskNew(fn_800445D4);
            fn_80061F58((u8*)node + 0x24, 0x58, 0);
            w = node->work;
            w->buf = buf;
            fn_80061F58(&w->sub, 0x6c, 0);
            s = w->sub;
            s->copy = *obj;
            s->copy.x += i * obj->step;
            s->copy.y += i * obj->step;
            s->arg = arg;
        }
    } else {
        return 0;
    }
    return 1;
}
int fn_8003B1D8(Handler* h, TaskArg* arg)
{
    Obj_8003B1D8* obj = h->obj;
    Node* node;
    Work_8003B1D8* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = TaskNew(fn_8004281C);
        fn_80061F58((u8*)node + 0x24, 0x2c, 0);
        w = node->work;
        w->copy = *obj;
        w->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_8003B09C(Handler* h, TaskArg* arg)
{
    Obj_8003B09C* obj = h->obj;
    Node* node;
    Work_8003B09C* w;
    Sub_8003B09C* s;
    Buf_8003B09C buf;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        if (obj->src) fn_80036520(obj->src, &buf);
        else memset(&buf, 0, 0x4c);
        node = TaskNew(fn_800498F0);
        fn_80061F58((u8*)node + 0x24, 0x58, 0);
        w = node->work;
        w->buf = buf;
        fn_80061F58(&w->sub, 0x1c, 0);
        s = w->sub;
        s->owner = obj;
        s->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_8003AF7C(Handler* h, TaskArg* arg)
{
    Obj_8003AF7C* obj = h->obj;
    Node* node;
    Work_8003AF7C* w;
    Sub_8003AF7C* s;
    Buf_8003AF7C buf;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        fn_80036520(obj->src, &buf);
        node = TaskNew(fn_80045CD8);
        fn_80061F58((u8*)node + 0x24, 0x58, 0);
        w = node->work;
        w->buf = buf;
        fn_80061F58(&w->sub, 0x6c, 0);
        s = w->sub;
        s->owner = obj;
        s->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_8003AE54(Handler* h, TaskArg* arg)
{
    Obj_8003AE54* obj = h->obj;
    Node* node;
    Work_8003AE54* w;
    Sub_8003AE54* s;
    Buf_8003AE54 buf;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        fn_80036520(obj->src, &buf);
        node = TaskNew(fn_800544C4);
        lbl_8030A10C.count--;
        fn_80061F58((u8*)node + 0x24, 0x58, 0);
        w = node->work;
        w->buf = buf;
        fn_80061F58(&w->sub, 0x1c, 0);
        s = w->sub;
        s->owner = obj;
        s->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_8003AD14(Handler* h, TaskArg* arg)
{
    Obj_8003AD14* obj = h->obj;
    Node* node;
    Work_8003AD14* w;
    Sub_8003AD14* s;
    Buf_8003AD14 buf;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        fn_80036520(obj->src, &buf);
        node = TaskNew(fn_80041664);
        fn_80061F58((u8*)node + 0x24, 0x58, 0);
        w = node->work;
        w->buf = buf;
        fn_80061F58(&w->sub, 0xac, 0);
        s = w->sub;
        s->copy = *obj;
        s->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_8003ABCC(Handler* h, TaskArg* arg)
{
    Obj_8003ABCC* obj = h->obj;
    Node* node;
    Work_8003ABCC* w;
    Sub_8003ABCC* s;
    Buf_8003ABCC buf;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        fn_80036520(*(s32*)((u8*)obj + 8), &buf);
        node = TaskNew(fn_80041238);
        fn_80061F58((u8*)node + 0x24, 0x58, 0);
        w = node->work;
        w->buf = buf;
        fn_80061F58(&w->sub, 0x8c, 0);
        s = w->sub;
        s->copy = *obj;
        s->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_8003AAAC(Handler* h, TaskArg* arg)
{
    Obj_8003AAAC* obj = h->obj;
    Node* node;
    Work_8003AAAC* w;
    Sub_8003AAAC* s;
    Buf_8003AAAC buf;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        fn_80036520(obj->src, &buf);
        node = TaskNew(fn_80049464);
        fn_80061F58((u8*)node + 0x24, 0x58, 0);
        w = node->work;
        w->buf = buf;
        fn_80061F58(&w->sub, 0x40, 0);
        s = w->sub;
        s->owner = obj;
        s->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_8003A9D8(Handler* h, TaskArg* arg)
{
    void* obj = h->obj;
    Node* node;
    Work_8003A9D8* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = TaskNew(fn_800581B8);
        fn_80061F58((u8*)node + 0x24, 0x38, 0);
        w = node->work;
        w->owner = obj;
        w->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_8003A904(Handler* h, TaskArg* arg)
{
    void* obj = h->obj;
    Node* node;
    Work_8003A904* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = TaskNew(fn_80057DFC);
        fn_80061F58((u8*)node + 0x24, 0x4c, 0);
        w = node->work;
        w->owner = obj;
        w->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_8003A830(Handler* h, TaskArg* arg)
{
    void* obj = h->obj;
    Node* node;
    Work_8003A830* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = TaskNew(fn_80057BD0);
        fn_80061F58((u8*)node + 0x24, 0x2c, 0);
        w = node->work;
        w->owner = obj;
        w->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_8003A75C(Handler* h, TaskArg* arg)
{
    void* obj = h->obj;
    Node* node;
    Work_8003A75C* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = TaskNew(fn_800576B0);
        fn_80061F58((u8*)node + 0x24, 0xc, 0);
        w = node->work;
        w->owner = obj;
        w->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_8003A370(Handler* h, TaskArg* arg)
{
    Obj_8003A370* obj = h->obj;
    Node* node;
    Work_8003A370* w;
    Sub_8003A370* s;
    s16 i, j;
    s16 off;
    u8 kind;
    f32 dx, dy, spread, scale, angle;
    Buf_8003A370 buf;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        fn_80036520(obj->src, &buf);
        for (i = 0; i < obj->x146; i++) {
            if (obj->x16) off = rand() % obj->x16; else off = 0;
            dx = obj->x150 * (3.0517578125e-05f * rand());
            dy = obj->x154 * (3.0517578125e-05f * rand());
            spread = 3.0517578125e-05f * rand();
            scale = 3.0517578125e-05f * rand();
            angle = 3.0517578125e-05f * rand();
            if (scale < 0.8f) scale = 0.8f;
            if (obj->x40 == 8) kind = rand() % 4; else kind = obj->x40;
            angle = 360.0f * angle;
            for (j = 0; j < obj->x1e; j++) {
                node = TaskNew(fn_80057038);
                fn_80061F58((u8*)node + 0x24, 0x58, 0);
                w = node->work;
                w->buf = buf;
                fn_80061F58(&w->sub, 0x44, 0);
                s = w->sub;
                s->owner = obj;
                s->arg = arg;
                s->x2 = off + obj->x20 * j + obj->x14;
                s->x4 = off + obj->x20 * j + obj->x18;
                s->x8 = obj->x148 + dx;
                s->xc = obj->x14c + dy;
                s->x30 = obj->x158 - obj->x15c;
                if (s->x30 < 0.0f) s->x30 *= -1.0f;
                s->x30 *= spread;
                if (obj->x158 < obj->x15c) s->x30 += obj->x158; else s->x30 += obj->x15c;
                s->x34 = angle;
                s->x10 = kind;
                s->x14 = obj->x34 * scale;
                s->x18 = obj->x38 * scale;
                s->x1c = obj->x3c * scale;
            }
        }
    } else {
        return 0;
    }
    return 1;
}
int fn_8003A264(Handler* h, TaskArg* arg)
{
    Obj_8003A264* obj = h->obj;
    Node* node;
    Work_8003A264* w;
    Buf_8003A264 buf;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        fn_80036520(obj->src, &buf);
        node = TaskNew(fn_80056B6C);
        fn_80061F58((u8*)node + 0x24, 0x90, 0);
        w = node->work;
        w->buf = buf;
        w->owner = obj;
        w->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_8003A190(Handler* h, TaskArg* arg)
{
    void* obj = h->obj;
    Node* node;
    Work_8003A190* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = TaskNew(fn_800565B0);
        fn_80061F58((u8*)node + 0x24, 0x48, 0);
        w = node->work;
        w->owner = obj;
        w->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_8003A070(Handler* h, TaskArg* arg)
{
    Obj_8003A070* obj = h->obj;
    Node* node;
    Work_8003A070* w;
    Sub_8003A070* s;
    Buf_8003A070 buf;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        fn_80036520(obj->src, &buf);
        node = TaskNew(fn_80055F0C);
        fn_80061F58((u8*)node + 0x24, 0x58, 0);
        w = node->work;
        w->buf = buf;
        fn_80061F58(&w->sub, 0x30, 0);
        s = w->sub;
        s->owner = obj;
        s->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_80039F88(Handler* h, TaskArg* arg)
{
    void* obj = h->obj;
    Node* node;
    Work_80039F88* w;
    Sub_80039F88* s;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = TaskNew(fn_80055EB8);
        fn_80061F58((u8*)node + 0x24, 0x58, 0);
        w = node->work;
        fn_80061F58(&w->sub, 0x10, 0);
        s = w->sub;
        s->owner = obj;
        s->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_80039EB4(Handler* h, TaskArg* arg)
{
    void* obj = h->obj;
    Node* node;
    Work_80039EB4* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = TaskNew(fn_80055E94);
        fn_80061F58((u8*)node + 0x24, 0xc, 0);
        w = node->work;
        w->owner = obj;
        w->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_80039DE0(Handler* h, TaskArg* arg)
{
    void* obj = h->obj;
    Node* node;
    Work_80039DE0* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = TaskNew(fn_80055A38);
        fn_80061F58((u8*)node + 0x24, 0x10, 0);
        w = node->work;
        w->owner = obj;
        w->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_80039D0C(Handler* h, TaskArg* arg)
{
    void* obj = h->obj;
    Node* node;
    Work_80039D0C* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = TaskNew(fn_80055558);
        fn_80061F58((u8*)node + 0x24, 0x24, 0);
        w = node->work;
        w->owner = obj;
        w->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_80039C38(Handler* h, TaskArg* arg)
{
    void* obj = h->obj;
    Node* node;
    Work_80039C38* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = TaskNew(fn_800553FC);
        fn_80061F58((u8*)node + 0x24, 0x18, 0);
        w = node->work;
        w->owner = obj;
        w->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_80039AFC(Handler* h, TaskArg* arg)
{
    Obj_80039AFC* obj = h->obj;
    Node* node;
    Work_80039AFC* w;
    Sub_80039AFC* s;
    Buf_80039AFC buf;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        if (obj->src) fn_80036520(obj->src, &buf); else memset(&buf, 0, 0x4c);
        node = TaskNew(fn_80046704);
        fn_80061F58((u8*)node + 0x24, 0x58, 0);
        w = node->work;
        w->buf = buf;
        fn_80061F58(&w->sub, 0x18, 0);
        s = w->sub;
        s->owner = obj;
        s->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_80039A28(Handler* h, TaskArg* arg)
{
    void* obj = h->obj;
    Node* node;
    Work_80039A28* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = TaskNew(fn_8005C73C);
        fn_80061F58((u8*)node + 0x24, 0x94, 0);
        w = node->work;
        w->owner = obj;
        w->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_80039954(Handler* h, TaskArg* arg)
{
    void* obj = h->obj;
    Node* node;
    Work_80039954* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = TaskNew(fn_8005C480);
        fn_80061F58((u8*)node + 0x24, 0xc, 0);
        w = node->work;
        w->owner = obj;
        w->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_80039880(Handler* h, TaskArg* arg)
{
    void* obj = h->obj;
    Node* node;
    Work_80039880* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = TaskNew(fn_8005C328);
        fn_80061F58((u8*)node + 0x24, 0xc, 0);
        w = node->work;
        w->owner = obj;
        w->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_800397AC(Handler* h, TaskArg* arg)
{
    void* obj = h->obj;
    Node* node;
    Work_800397AC* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = TaskNew(fn_8005C188);
        fn_80061F58((u8*)node + 0x24, 0x10, 0);
        w = node->work;
        w->owner = obj;
        w->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_800396D8(Handler* h, TaskArg* arg)
{
    void* obj = h->obj;
    Node* node;
    Work_800396D8* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = TaskNew(fn_8005DEB8);
        fn_80061F58((u8*)node + 0x24, 0x3c, 0);
        w = node->work;
        w->owner = obj;
        w->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_80039604(Handler* h, TaskArg* arg)
{
    void* obj = h->obj;
    Node* node;
    Work_80039604* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = TaskNew(fn_8005BF30);
        fn_80061F58((u8*)node + 0x24, 0x28, 0);
        w = node->work;
        w->owner = obj;
        w->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_800394E4(Handler* h, TaskArg* arg)
{
    Obj_800394E4* obj = h->obj;
    Node* node;
    Work_800394E4* w;
    Sub_800394E4* s;
    Buf_800394E4 buf;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        fn_80036520(obj->src, &buf);
        node = TaskNew(fn_8005BBC4);
        fn_80061F58((u8*)node + 0x24, 0x58, 0);
        w = node->work;
        w->buf = buf;
        fn_80061F58(&w->sub, 0x3c, 0);
        s = w->sub;
        s->owner = obj;
        s->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_800393AC(Handler* h, TaskArg* arg)
{
    Obj_800393AC* obj = h->obj;
    Node* node;
    Work_800393AC* w;
    Buf_800393AC buf;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        fn_80036520(obj->src, &buf);
        node = TaskNew(fn_8005BAA0);
        fn_80061F58((u8*)node + 0x24, 0x6c, 0);
        w = node->work;
        w->buf = buf;
        w->copy = *obj;
        w->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_80039280(Handler* h, TaskArg* arg)
{
    Obj_80039280* obj = h->obj;
    Node* node;
    Work_80039280* w;
    Buf_80039280 buf;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        if (obj->src) fn_80036520(obj->src, &buf);
        node = TaskNew(fn_8005B648);
        fn_80061F58((u8*)node + 0x24, 0xb8, 0);
        w = node->work;
        if (obj->src) w->buf = buf; else w->buf.first = 0;
        w->owner = obj;
        w->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_80039174(Handler* h, TaskArg* arg)
{
    Obj_80039174* obj = h->obj;
    Node* node;
    Work_80039174* w;
    Buf_80039174 buf;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        fn_80036520(obj->src, &buf);
        node = TaskNew(fn_8005B2C8);
        fn_80061F58((u8*)node + 0x24, 0x64, 0);
        w = node->work;
        w->buf = buf;
        w->owner = obj;
        w->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_800390A0(Handler* h, TaskArg* arg)
{
    void* obj = h->obj;
    Node* node;
    Work_800390A0* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = TaskNew(fn_8005B094);
        fn_80061F58((u8*)node + 0x24, 0x58, 0);
        w = node->work;
        w->owner = obj;
        w->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_80038F80(Handler* h, TaskArg* arg)
{
    Obj_80038F80* obj = h->obj;
    Node* node;
    Work_80038F80* w;
    Sub_80038F80* s;
    Buf_80038F80 buf;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        fn_80036520(obj->src, &buf);
        node = TaskNew(fn_8005ACD4);
        fn_80061F58((u8*)node + 0x24, 0x58, 0);
        w = node->work;
        w->buf = buf;
        fn_80061F58(&w->sub, 0x3c, 0);
        s = w->sub;
        s->owner = obj;
        s->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_80038EAC(Handler* h, TaskArg* arg)
{
    void* obj = h->obj;
    Node* node;
    Work_80038EAC* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = TaskNew(fn_8005A694);
        fn_80061F58((u8*)node + 0x24, 0x10, 0);
        w = node->work;
        w->owner = obj;
        w->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_80038D8C(Handler* h, TaskArg* arg)
{
    Obj_80038D8C* obj = h->obj;
    Node* node;
    Work_80038D8C* w;
    Sub_80038D8C* s;
    Buf_80038D8C buf;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        fn_80036520(obj->src, &buf);
        node = TaskNew(fn_80059D6C);
        fn_80061F58((u8*)node + 0x24, 0x58, 0);
        w = node->work;
        w->buf = buf;
        fn_80061F58(&w->sub, 0x6c, 0);
        s = w->sub;
        s->owner = obj;
        s->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_80038CB8(Handler* h, TaskArg* arg)
{
    void* obj = h->obj;
    Node* node;
    Work_80038CB8* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = TaskNew(fn_80059788);
        fn_80061F58((u8*)node + 0x24, 0x24, 0);
        w = node->work;
        w->owner = obj;
        w->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_80038B98(Handler* h, TaskArg* arg)
{
    Obj_80038B98* obj = h->obj;
    Node* node;
    Work_80038B98* w;
    Sub_80038B98* s;
    Buf_80038B98 buf;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        fn_80036520(obj->src, &buf);
        node = TaskNew(fn_80058E20);
        fn_80061F58((u8*)node + 0x24, 0x58, 0);
        w = node->work;
        w->buf = buf;
        fn_80061F58(&w->sub, 0x14, 0);
        s = w->sub;
        s->owner = obj;
        s->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_80038AC4(Handler* h, TaskArg* arg)
{
    void* obj = h->obj;
    Node* node;
    Work_80038AC4* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = TaskNew(fn_800583D4);
        fn_80061F58((u8*)node + 0x24, 0x50, 0);
        w = node->work;
        w->owner = obj;
        w->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_800389F0(Handler* h, TaskArg* arg)
{
    void* obj = h->obj;
    Node* node;
    Work_800389F0* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = TaskNew(fn_8006065C);
        fn_80061F58((u8*)node + 0x24, 0x14, 0);
        w = node->work;
        w->owner = obj;
        w->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_8003891C(Handler* h, TaskArg* arg)
{
    void* obj = h->obj;
    Node* node;
    Work_8003891C* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = TaskNew(fn_80073164);
        fn_80061F58((u8*)node + 0x24, 0x38, 0);
        w = node->work;
        w->owner = obj;
        w->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_80038848(Handler* h, TaskArg* arg)
{
    void* obj = h->obj;
    Node* node;
    Work_80038848* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = TaskNew(fn_800601C0);
        fn_80061F58((u8*)node + 0x24, 0xa8, 0);
        w = node->work;
        w->owner = obj;
        w->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_80038774(Handler* h, TaskArg* arg)
{
    void* obj = h->obj;
    Node* node;
    Work_80038774* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = TaskNew(fn_8005F8D8);
        fn_80061F58((u8*)node + 0x24, 0xf4, 0);
        w = node->work;
        w->owner = obj;
        w->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_80038654(Handler* h, TaskArg* arg)
{
    Obj_80038654* obj = h->obj;
    Node* node;
    Work_80038654* w;
    Sub_80038654* s;
    Buf_80038654 buf;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        fn_80036520(obj->src, &buf);
        node = TaskNew(fn_8005F640);
        fn_80061F58((u8*)node + 0x24, 0x58, 0);
        w = node->work;
        w->buf = buf;
        fn_80061F58(&w->sub, 0x18, 0);
        s = w->sub;
        s->owner = obj;
        s->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_80038534(Handler* h, TaskArg* arg)
{
    Obj_80038534* obj = h->obj;
    Node* node;
    Work_80038534* w;
    Sub_80038534* s;
    Buf_80038534 buf;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        fn_80036520(obj->src, &buf);
        node = TaskNew(fn_8005E9D4);
        fn_80061F58((u8*)node + 0x24, 0x58, 0);
        w = node->work;
        w->buf = buf;
        fn_80061F58(&w->sub, 0x70, 0);
        s = w->sub;
        s->owner = obj;
        s->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_80038460(Handler* h, TaskArg* arg)
{
    void* obj = h->obj;
    Node* node;
    Work_80038460* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = TaskNew(fn_8005E42C);
        fn_80061F58((u8*)node + 0x24, 0x3c, 0);
        w = node->work;
        w->owner = obj;
        w->arg = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_80038398(Handler* h, TaskArg* arg)
{
    void* obj = h->obj;
    Node* node;
    Work_80038398* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = TaskNew(fn_8005DB1C);
        fn_80061F58((u8*)node + 0x24, 0x40, 0);
        w = node->work;
        w->owner = obj;
        w->arg = arg;
    }
    return 1;
}
int fn_800382D0(Handler* h, TaskArg* arg)
{
    void* obj = h->obj;
    Node* node;
    Work_800382D0* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = TaskNew(fn_8005D614);
        fn_80061F58((u8*)node + 0x24, 0x24, 0);
        w = node->work;
        w->owner = obj;
        w->arg = arg;
    }
    return 1;
}
int fn_80038208(Handler* h, TaskArg* arg)
{
    void* obj = h->obj;
    Node* node;
    Work_80038208* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = TaskNew(fn_8005CDF0);
        fn_80061F58((u8*)node + 0x24, 0xb8, 0);
        w = node->work;
        w->owner = obj;
        w->arg = arg;
    }
    return 1;
}
int fn_80038140(Handler* h, TaskArg* arg)
{
    void* obj = h->obj;
    Node* node;
    Work_80038140* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = TaskNew(fn_8005CCB0);
        fn_80061F58((u8*)node + 0x24, 0xc, 0);
        w = node->work;
        w->owner = obj;
        w->arg = arg;
    }
    return 1;
}
int fn_80038078(Handler* h, TaskArg* arg)
{
    void* obj = h->obj;
    Node* node;
    Work_80038078* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = TaskNew(fn_8005CBA4);
        fn_80061F58((u8*)node + 0x24, 0xc, 0);
        w = node->work;
        w->owner = obj;
        w->arg = arg;
    }
    return 1;
}
void fn_8003801C(void)
{
    f32 z = 0.0f;
    lbl_80309E5C.x14 = z;
    lbl_80309E5C.flags &= ~0x20000000;
    lbl_80309E5C.flags &= ~0x10000000;
    lbl_80309E5C.flags &= ~0x80000000;
    lbl_80309E5C.flags &= ~0x40000000;
    lbl_80309E5C.x10 = z;
    fn_8007E414(0);
}
int fn_80037FD8(Ent_80037FD8* e, u8* out)
{
    if ((e->flags & 0x2000) && (lbl_8030A10C.flags & 0x40) && (int)*out != 0xFA) {
        *out = 0xF9;
        return 1;
    }
    return 0;
}
void fn_80037EB4(void)
{
    s16 i;
    SaveHead* d = fn_8006B6F4(0);
    *d = lbl_803472EC->head;
    for (i = 0; i < 12; i++) {
        void* slot = lbl_80309E24[i];
        if (slot != 0) {
            u8* n = *(u8**)((u8*)slot + 0x24);
            Body_80037EB4* b = *(Body_80037EB4**)(n + 0x4C);
            b->flags &= 0x7FFFFFFF;
            b->x164 = 0.0f;
            b->x208 = 0.0f;
            b->x194 = 0;
            if (b->flags & 0x40000080) {
                u8* m = *(u8**)((u8*)slot + 0x24);
                fn_80071CF0(&lbl_803472EC->a[i], m + 0x1C);
                fn_800614FC(&lbl_803472EC->b[i], m + 0x28);
                b->flags &= ~0x40000080;
            }
        }
    }
    lbl_8030A10C.flags6c &= ~0x80000;
}
void fn_80037AF0(Node* node)
{
    Work_80037AF0* w = node->work;
    TaskRes_80037AF0* data = w->arg->info->data;

    switch (node->state) {
    case 0:
        if (w->count >= 5) node->state = 1;
        break;
    case 1:
        if ((lbl_80311A60.pad->x8 & 0x1000) || w->count == lbl_8030A10C.x1ca) {
            lbl_8030A10C.flags |= 0x80;
            lbl_8030A10C.x1c8 = w->count;
            node->state = 2;
        } else if (!fn_8001BCC8(data->x0, w->arg) || (lbl_8030A10C.flags & 0x10) ||
                   data->x68 > 2.0f * (((f32)data->x5c->x4 - 1.0f) / 3.0f)) {
            node->state = 7;
        }
        break;
    case 2:
        if (lbl_8030A10C.flags & 0x10) {
            lbl_8030A10C.flags &= ~0x80;
            lbl_8030A10C.flags &= ~0x40;
            lbl_8030A10C.flags &= ~0x20;
            lbl_8030A10C.flags &= ~0x10;
            lbl_8030A10C.x1c8 = 0;
            node->state = 7;
        } else {
            node->state = 3;
            fn_801CBC10();
            fn_801CBBAC(10.0f);
            lbl_80347508 = 1;
            lbl_80347510 = 0.0f;
        }
        break;
    case 3:
        if (w->timer > 10) {
            if (lbl_80347508 == 0) {
                w->timer = 0;
                node->state = 4;
                lbl_8030A10C.flags |= 0x40;
                data->x68 = (f32)data->x5c->x4 - 1.0f;
                fn_80028E0C();
                switch (fn_80028B90()) {
                case 3:
                    fn_80028DE4();
                    break;
                }
            }
        } else {
            w->timer++;
        }
        break;
    case 4:
        if (w->timer > 3) {
            fn_80037EB4();
            node->state = 5;
            lbl_80309EC8.x48 |= 0x20000000;
            fn_801CBB9C(20.0f);
            lbl_80347508 = 1;
        } else {
            w->timer++;
        }
        fn_80033888(0, 0, 0x50, 4, 0xff, 8.0f, -1.0f);
        break;
    case 5:
        if (lbl_80347508 == 0) {
            fn_801CBBF8();
            lbl_8030A10C.flags |= 0x20;
            node->state = 6;
        }
        break;
    case 6:
        if (fn_8006D1C4() && lbl_8034733C != 4) {
            lbl_80309EC8.x48 &= ~0x20000000;
            if (!fn_8001BCC8(data->x0, ((Work_80037AF0*)node->work)->arg) || !(lbl_8030A10C.flags & 0x80) ||
                lbl_8034733C == 3 || lbl_8034733C == 7 || lbl_8034733C == 1) {
                node->state = 7;
                ClearStats();
            }
        }
        break;
    case 7:
        node->flags |= 0x40;
        return;
    }
    w->count++;
}
void fn_80037918(TaskObj* obj)
{
    Node* node;
    TaskRes_80037918* data;

    data = obj->info->data;

    if (fn_80014C90(data->x0, 0x400000)) {
        ClearStats();
    } else if (data->x6 == 0x18) {
        switch (data->x8) {
        case 0x24: case 0x25: case 0x26: case 0x27: case 0x28: case 0x29:
        case 0x2a: case 0x2b: case 0x2c: case 0x2d: case 0x2e: case 0x2f:
        case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35:
        case 0x36: case 0x37: case 0x38: case 0x39: case 0x3a: case 0x3b:
            ClearStats();
            node = fn_802268E8(lbl_803475A8, fn_80037AF0);
            fn_80061F58(&node->work, 0xc, 0);
            ((Work_80037918*)node->work)->arg = obj;
            if (lbl_803472EC) fn_801E17E0(lbl_803472EC);
            fn_80061F58(&lbl_803472EC, 0x184, 0);
            lbl_803472EC->head = *fn_8006B6F4(0);
            SavePartyPos();
            break;
        }
    }
}
int fn_800377FC(ChunkHdr* m)
{
    int size;
    switch ((m->type << 16) | m->id) {
    case 0x50000: size = 0x24; break;
    case 0x50001: size = 0x3C; break;
    case 0x50002: size = 0x18; break;
    case 0x50003: size = 0x3C; break;
    case 0x50004: size = 0x3C; break;
    case 0x50005: size = 0x3C; break;
    case 0x50006: size = 0x3C; break;
    case 0x50007: size = 0x24; break;
    case 0x50008: size = 0x18; break;
    case 0x50009: size = 0x14; break;
    case 0x5000A: size = 0x10; break;
    case 0x5000B: size = 0x14; break;
    case 0x5000C: size = 0x18; break;
    case 0x5000D: size = 0x10; break;
    case 0x5000E: size = 0x24; break;
    case 0x5000F: size = 0x18; break;
    case 0x50010: size = 0x20; break;
    case 0x50011: size = 0x20; break;
    case 0x50012: size = 0x10; break;
    default: return 0;
    }
    fn_80061F58(&m->data, size, 0);
    m->size = size;
    return 1;
}
int fn_8003732C(u32 key, void* a, void* b)
{
    int ret = 0;
    switch (key) {
    case 0x50000:
        ret = TaskCall(key, a, b);
        break;
    case 0x50001:
        ret = TaskCall(key, a, b);
        break;
    case 0x50002:
        ret = TaskCall(key, a, b);
        break;
    case 0x50003:
        ret = TaskCall(key, a, b);
        break;
    case 0x50004:
        ret = TaskCall(key, a, b);
        break;
    case 0x50005:
        ret = TaskCall(key, a, b);
        break;
    case 0x50006:
        ret = TaskCall(key, a, b);
        break;
    case 0x50007:
        ret = TaskCall(key, a, b);
        break;
    case 0x50008:
        ret = TaskCall(key, a, b);
        break;
    case 0x50009:
        ret = TaskCall(key, a, b);
        break;
    case 0x5000A:
        ret = TaskCall(key, a, b);
        break;
    case 0x5000B:
        ret = TaskCall(key, a, b);
        break;
    case 0x5000C:
        ret = TaskCall(key, a, b);
        break;
    case 0x5000D:
        ret = TaskCall(key, a, b);
        break;
    case 0x5000E:
        ret = TaskCall(key, a, b);
        break;
    case 0x5000F:
        ret = TaskCall(key, a, b);
        break;
    case 0x50010:
        ret = TaskCall(key, a, b);
        break;
    case 0x50011:
        ret = TaskCall(key, a, b);
        break;
    case 0x50012:
        ret = TaskCall(key, a, b);
        break;
    }
    return ret;
}
void fn_80037328(void) {}
void fn_80037324(void) {}
void fn_80037320(void) {}
void fn_8003731C(void) {}
void fn_80037318(void) {}
void fn_80037314(void) {}
void fn_80037310(void) {}
void fn_8003730C(void) {}
void fn_80037308(void) {}
void fn_80037304(void) {}
void fn_80037300(void) {}
void fn_800372FC(void) {}
void fn_800372F8(void) {}
void fn_800372F4(void) {}
void fn_800372F0(void) {}
void fn_800372EC(void) {}
void fn_800372E8(void) {}
void fn_800372E4(void) {}
void fn_800372E0(void) {}
int fn_80037250(Handler* h, TaskArg* arg)
{
    void* o = h->obj;
    if (fn_8003DCF4(o, arg->res->x4c)) {
        Node* node = fn_8003DB34(fn_80051264);
        W_80037250* w;
        fn_80061F58((u8*)node + 0x24, 0x17c, 0);
        w = node->work;
        w->x178 = o;
        w->x74 = arg;
    } else {
        return 0;
    }
    return 1;
}
int fn_8003716C(Handler* h, TaskArg* arg)
{
    O_8003716C* o = h->obj;
    if (fn_8003DCF4(o, arg->res->x4c)) {
        Node* node = fn_8003DAD0(fn_800651D0);
        W_8003716C* w;
        fn_80061F58((u8*)node + 0x24, 0x98, 0);
        w = node->work;
        w->owner = arg;
        w->f[1] = o->f[3];
        w->f[8] = o->f[8];
        w->f[14] = o->f[11];
        w->f[2] = o->f[4];
        w->f[9] = o->f[9];
        w->f[15] = o->f[12];
        w->f[3] = o->f[5];
        w->f[10] = o->f[10];
        w->f[16] = o->f[13];
        w->f[7] = o->f[6];
        w->id = o->id;
    } else {
        return 0;
    }
    return 1;
}
int fn_800370C8(Handler* h, TaskArg* arg)
{
    O_800370C8* o = h->obj;
    if (fn_8003DCF4(o, arg->res->x4c)) {
        Node* node = fn_8003DAD0(fn_80064FE0);
        W_800370C8* w;
        fn_80061F58((u8*)node + 0x24, 0x98, 0);
        w = node->work;
        w->owner = arg;
        w->f[24] = o->f[3];
        w->f[25] = o->f[4];
        w->id = o->id;
    } else {
        return 0;
    }
    return 1;
}
int fn_8003701C(Handler* h, TaskArg* arg)
{
    O_8003701C* o = h->obj;
    if (fn_8003DCF4(o, arg->res->x4c)) {
        Node* node = fn_8003DAD0(fn_80064E38);
        W_8003701C* w;
        fn_80061F58((u8*)node + 0x24, 0x98, 0);
        w = node->work;
        w->owner = arg;
        w->f[14] = o->f[11];
        w->f[15] = o->f[12];
        w->f[16] = o->f[13];
        w->id = o->id;
    } else {
        return 0;
    }
    return 1;
}
int fn_80036F70(Handler* h, TaskArg* arg)
{
    O_80036F70* o = h->obj;
    if (fn_8003DCF4(o, arg->res->x4c)) {
        Node* node = fn_8003DAD0(fn_80064CA4);
        W_80036F70* w;
        fn_80061F58((u8*)node + 0x24, 0x98, 0);
        w = node->work;
        w->owner = arg;
        w->f[14] = o->f[11];
        w->f[15] = o->f[12];
        w->f[16] = o->f[13];
        w->id = o->id;
    } else {
        return 0;
    }
    return 1;
}
int fn_80036EC4(Handler* h, TaskArg* arg)
{
    O_80036EC4* o = h->obj;
    if (fn_8003DCF4(o, arg->res->x4c)) {
        Node* node = fn_8003DAD0(fn_80064C00);
        W_80036EC4* w;
        fn_80061F58((u8*)node + 0x24, 0x98, 0);
        w = node->work;
        w->owner = arg;
        w->f[4] = o->f[3];
        w->f[5] = o->f[4];
        w->f[6] = o->f[5];
        w->id = o->id;
    } else {
        return 0;
    }
    return 1;
}
int fn_80036E18(Handler* h, TaskArg* arg)
{
    O_80036E18* o = h->obj;
    if (fn_8003DCF4(o, arg->res->x4c)) {
        Node* node = fn_8003DAD0(fn_80064AC8);
        W_80036E18* w;
        fn_80061F58((u8*)node + 0x24, 0x98, 0);
        w = node->work;
        w->owner = arg;
        w->f[8] = o->f[8];
        w->f[9] = o->f[9];
        w->f[10] = o->f[10];
        w->id = o->id;
    } else {
        return 0;
    }
    return 1;
}
int fn_80036D5C(Handler* h, TaskArg* arg)
{
    O_80036D5C* o = h->obj;
    if (fn_8003DCF4(o, arg->res->x4c)) {
        Node* node = fn_8003DAD0(fn_800631B0);
        W_80036D5C* w;
        fn_80061F58((u8*)node + 0x24, 0xa4, 0);
        w = node->work;
        w->owner = arg;
        w->s84 = o->s18;
        w->s82 = o->s16x;
        w->s80 = o->s14;
        w->f74 = o->f10;
        w->f78 = o->f1c;
        w->s9e = o->s20;
    } else {
        return 0;
    }
    return 1;
}
int fn_80036CB0(Handler* h, TaskArg* arg)
{
    O1_80036CB0* o = h->obj;
    if (fn_8003DCF4(o, arg->res->x4c)) {
        Node* node = fn_8003DAD0(fn_80062F70);
        W1_80036CB0* w;
        fn_80061F58((u8*)node + 0x24, 0x18, 0);
        w = node->work;
        w->owner = arg;
        w->a = o->a;
        w->b = o->b;
        w->c = o->c;
        w->d = o->s;
    } else {
        return 0;
    }
    return 1;
}
int fn_80036C1C(Handler* h, TaskArg* arg)
{
    s16* obj = h->obj;
    Node* node;
    Work_80036C1C* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = fn_8003DAD0(fn_80062E94);
        fn_80061F58((u8*)node + 0x24, 0xc, 0);
        w = node->work;
        w->arg = arg;
        w->b = obj[8];
    } else {
        return 0;
    }
    return 1;
}
int fn_80036B88(Handler* h, TaskArg* arg)
{
    s16* obj = h->obj;
    Node* node;
    Work_80036B88* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = fn_8003DAD0(fn_80062674);
        fn_80061F58((u8*)node + 0x24, 8, 0);
        w = node->work;
        w->arg = arg;
        w->a = obj[0];
    } else {
        return 0;
    }
    return 1;
}
int fn_80036AE4(Handler* h, TaskArg* arg)
{
    s16* obj = h->obj;
    Node* node;
    Work_80036AE4* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = fn_8003DAD0(fn_800624FC);
        fn_80061F58((u8*)node + 0x24, 0x14, 0);
        w = node->work;
        w->arg = arg;
        w->c = obj[0];
        w->d = obj[8];
        w->e = obj[9];
    } else {
        return 0;
    }
    return 1;
}
int fn_80036A38(Handler* h, TaskArg* arg)
{
    s16* obj = h->obj;
    Node* node;
    Work_80036A38* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = fn_8003DAD0(fn_80062318);
        fn_80061F58((u8*)node + 0x24, 0x14, 0);
        w = node->work;
        w->arg = arg;
        w->a = obj[0];
        w->b = obj[8];
        w->c = obj[9];
        w->d = obj[10];
    } else {
        return 0;
    }
    return 1;
}
int fn_800369A4(Handler* h, TaskArg* arg)
{
    s16* obj = h->obj;
    Node* node;
    Work_800369A4* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = fn_8003DAD0(fn_8006228C);
        fn_80061F58((u8*)node + 0x24, 8, 0);
        w = node->work;
        w->arg = arg;
        w->a = obj[0];
    } else {
        return 0;
    }
    return 1;
}
int fn_80036914(Handler* h, TaskArg* arg)
{
    void* obj = h->obj;
    Node* node;
    Work_80036914* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = fn_8003DB34(fn_80061FCC);
        fn_80061F58((u8*)node + 0x24, 0x10, 0);
        w = node->work;
        w->arg = arg;
        w->obj = obj;
    } else {
        return 0;
    }
    return 1;
}
int fn_80036880(Handler* h, TaskArg* arg)
{
    s16* obj = h->obj;
    Node* node;
    Work_80036880* w;
    if (fn_8003DCF4(obj, arg->res->x4c)) {
        node = fn_8003DAD0(fn_80062444);
        fn_80061F58((u8*)node + 0x24, 8, 0);
        w = node->work;
        w->arg = arg;
        w->id = obj[0];
    } else {
        return 0;
    }
    return 1;
}

int fn_800367E8(u32 key, void* x, void* y)
{
    int ret = 0;
    TaskFunc fn = TaskLookup(key, lbl_802DD238, 0x5b);
    if (fn) ret = fn(x, y);
    return ret;
}
TaskFunc fn_80036794(u32 key, TaskEnt* tbl, s16 end)
{
    TaskEnt* e;
    s16 a;
    s16 i = 0;
    e = tbl;
    for (;;) {
        a = e->a;
        if (end != a) {
            if (key == (u32)(e->b << 16 | a)) return tbl[i].fn;
            e++;
            i++;
            continue;
        }
        break;
    }
    return 0;
}
void fn_80036790(void) {}
void fn_8003678C(void) {}
void fn_80036788(void) {}
void fn_80036784(void) {}
void fn_80036780(void) {}
void fn_8003677C(void) {}
void fn_80036778(void) {}
void fn_80036774(void) {}
void fn_80036770(void) {}
void fn_8003676C(void) {}
void fn_80036768(void) {}
void fn_80036764(void) {}
void fn_80036760(void) {}
void fn_8003675C(void) {}
void fn_80036758(void) {}
void fn_80036754(void) {}
void fn_80036750(void) {}
void fn_8003674C(void) {}
void fn_80036748(void) {}
void fn_80036744(void) {}
void fn_80036740(void) {}
void fn_8003673C(void) {}
void fn_80036738(void) {}
void fn_80036734(void) {}
void fn_80036730(void) {}
void fn_8003672C(void) {}
void fn_80036728(void) {}
void fn_80036724(void) {}
void fn_80036720(void) {}
void fn_8003671C(void) {}
void fn_80036718(void) {}
void fn_80036714(void) {}
void fn_80036710(void) {}
void fn_8003670C(void) {}
void fn_80036708(void) {}
void fn_80036704(void) {}
void fn_80036700(void) {}
void fn_800366FC(void) {}
void fn_800366F8(void) {}
void fn_800366F4(void) {}
void fn_800366F0(void) {}
void fn_800366EC(void) {}
void fn_800366E8(void) {}
void fn_800366E4(void) {}
void fn_800366E0(void) {}
void fn_800366DC(void) {}
void fn_800366D8(void) {}
void fn_800366D4(void) {}
void fn_800366D0(void) {}
void fn_800366CC(void) {}
void fn_800366C8(void) {}
void fn_800366C4(void) {}
void fn_800366C0(void) {}
void fn_800366BC(void) {}
void fn_800366B8(void) {}
void fn_800366B4(void) {}
void fn_800366B0(void) {}
void fn_800366AC(void) {}
void fn_800366A8(void) {}
void fn_800366A4(void) {}
void fn_800366A0(void) {}
void fn_8003669C(void) {}
void fn_80036698(void) {}
void fn_80036694(void) {}
void fn_80036690(void) {}
void fn_8003668C(void) {}
void fn_80036688(void) {}
void fn_80036684(void) {}
void fn_80036680(void) {}
void fn_8003667C(void) {}
void fn_80036678(void) {}
void fn_80036674(void) {}
void fn_80036670(void) {}
void fn_8003666C(void) {}
void fn_80036668(void) {}
void fn_80036664(void) {}
void fn_80036660(void) {}
void fn_8003665C(void) {}
void fn_80036658(void) {}
void fn_80036654(void) {}
void fn_80036650(void) {}
void fn_8003664C(void) {}
void fn_80036648(void) {}
void fn_80036644(void) {}
void fn_80036640(void) {}
void fn_8003663C(void) {}
void fn_80036638(void) {}
void fn_80036634(void) {}
void fn_80036630(void) {}
s8 fn_800365FC(void)
{
    s8 i = 0;
    while (i < 14) {
        if (lbl_80309E24[i] == 0) return i;
        i++;
    }
    return i;
}
void fn_80036584(Node* n, s16 v)
{
    Data_80036584* d = n->work;
    Obj_80036584* o = d->obj;
    fn_80073FB8(d->sub->x2c, o->x154, d->x14, v);
    if (v == -1) o->flags &= ~0x2000000;
    else o->flags |= 0x2000000;
}
int fn_80036520(s32 p, void* v)
{
    u8 a[0x20];
    u8 b[0x20];
    if (p == 0) p = 0;
    fn_8003DBAC(p, (char*)a);
    fn_8006C8DC(b, a);
    fn_80074E2C(b, a, v, 0, 1);
    return 1;
}
