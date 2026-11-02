#ifndef GAME_UNIT_80005B50_H
#define GAME_UNIT_80005B50_H

#include "types.h"
#include "ninja.h"
#include "game/task.h"

/* Struct layouts shared by unit_80005B50.c and the units split from it, unit_80009800.c,
 * unit_8000A38C.c, unit_80011160.c and unit_80014784.c (docs/progress.md). */
typedef struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Vec3;
typedef struct Sub2_BB28 {
    u8 pad[0x4C];
    void* x4c;
    u32 x50;
} Sub2_BB28;
typedef struct Rec_BB28 {
    void* x0;
    u8 pad4[4];
    u32* x8;
    u32 xc;
    u8 pad10[6];
    s16 x16;
    s16 x18;
    u8 pad1a[0x40 - 0x1A];
    u32 x40;
    u8 pad44[0x4C - 0x44];
} Rec_BB28;
typedef struct Work_BB28 {
    Rec_BB28 r;
    Sub2_BB28* x4c;
    u8 pad50[8];
} Work_BB28;
typedef struct Ent_BB28 {
    Rec_BB28* recs;
    struct { u8 pad[8]; void* x8; }* x4;
    Work_BB28** ptrs;
    u8 xc;              /* 0x0c record count */
    u8 padd[3];
    void* x10;
} Ent_BB28;
typedef struct Entry16 {
    u8 pad[4];
    s8 x4;              /* 0x4: partner slot */
    u8 pad5[3];
    s8 mode;
    u8 b9;
    u8 pad2[6];
} Entry16;
/* The 0x70-byte objects lbl_80309EC8 keeps at 0x40/0x44 (fn_80014AB8); 0x20000000 in flags
 * releases one. */
/* The 0x38-byte block at SysObj 0x6c. */
typedef struct SysSub {
    u8 pad0[2];
    s16 x2;             /* 0x02 */
    u8 pad4[0x38 - 4];
} SysSub;
typedef struct SysObj {
    u8 pad0[0x3c];
    u32 x3c;            /* 0x3c */
    u8 pad40[0x50 - 0x40];
    Task* owner;        /* 0x50: the character it belongs to */
    u8 pad54[0x5a - 0x54];
    s16 x5a;            /* 0x5a */
    s16 x5c;            /* 0x5c */
    u8 pad5e[0x68 - 0x5e];
    u32 flags;          /* 0x68 */
    SysSub x6c;         /* 0x6c: cleared as a whole by fn_80061F58 */
} SysObj;
/* lbl_80309EC8 0x88..0x204, cleared as one block by fn_80014AB8. */
typedef struct SysMove {
    u8 pad0[0xC0 - 0x88];
    f32 xc0[3];
    u8 padcc[0x110 - 0xCC];
    f32 x110;
    u8 pad114[0x160 - 0x114];
    f32 x160;
    u8 pad164[0x19A - 0x164];
    s16 x19a;
    u8 pad19c[0x204 - 0x19C];
} SysMove;
/* lbl_80309EC8: the 0x244-byte battle/system block (memset in battle.c). */
typedef struct Sys_80309EC8 {
    u8 pad_0[0x40];
    SysObj* x40;
    SysObj* x44;
    u32 x48;
    NJS_POINT3 x4c;     /* 0x4c eye */
    NJS_POINT3 x58;     /* 0x58 target */
    s32 x64[3];         /* 0x64 angles */
    f32 va[3];
    f32 vb[3];
    SysMove mv;         /* 0x88 */
    s8 a[10];
    u8 pad20e[2];
    u32 w[10];
    s8 b[10];
    u8 pad242[2];
} Sys_80309EC8;
/* lbl_803097F0 (.bss, 0xD8 bytes): s16 header (x0 read as a state id in battle.c),
   then 12 per-character 16-byte entries from 0x18. */
typedef struct { f32 x0; f32 x4; f32 x8; f32 xc; } Ent;
typedef struct { s16 x0; u8 pad[0x16]; Ent ent[12]; } Tbl;
typedef struct {
    s8 id;
    u8 pad1[0x44 - 1];
    u32 x44;
    u8 pad48[0x50 - 0x48];
    u32 x50;
    u8 pad54[0x1dc - 0x54];
    void* x1dc;
} Unit_80016580;
typedef struct {
    u8 pad[0x4c];
    Unit_80016580* w;
} UW_80016580;
typedef struct Tk_80016580 {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    union {
        void* v;
        UW_80016580* uw;
    } work;
} Tk_80016580;
typedef struct B { u32 x0; u8 pad[0x24]; s32 x28; s32 x2c; s32 x30; } B;
typedef struct A { s32 x0; s32 x4; s32 x8; s32 xc; u8 pad[0xc]; B* x1c; } A;
/* One controller's state: x8 held buttons, xc newly pressed buttons. */
typedef struct Slot24 { u32 flags; u32 x4; u32 x8; u32 xc; u8 pad10[0x10]; u32 x20; } Slot24;
/* What a character record's x110 points at: the counter it applies (fn_80010584). */
typedef struct ChrAux {
    u8 pad0[0x58];
    s8 x58;        /* counter id */
    s8 x59;        /* stat index */
    s8 x5a;        /* threshold */
} ChrAux;
/* lbl_80309174: per-character battle state (0x20). */
typedef struct ChrStat {
    u8 pad[6];
    s16 x6;             /* 0x06 */
    u8 pad8;
    s8 x9;
    u8 pada[0xe - 0xa];
    s8 xe;              /* 0x0e */
    u8 padf[0x20 - 0xf];
} ChrStat;

#endif
