#ifndef GAME_SAVE_8030B7F4_H
#define GAME_SAVE_8030B7F4_H

#include "types.h"

/* lbl_8030B7F4: the 0x16A0-byte save/party data. Eight 0x5c-byte character records, the party
 * table, the inventory tables at 0x354..0xaac, the gold word and the option bytes. */
typedef struct SaveChar {
    char name[11];          /* 0x00 */
    u8 xb;                  /* 0x0b */
    u8 xc;
    s8 mp;                  /* 0x0d */
    s8 mpMax;
    s8 xf;                  /* 0x0f */
    s16 slot0;              /* 0x10 */
    s16 slot1;
    s16 slot2;
    u8 pad16[2];
    s16 hp;                 /* 0x18 */
    s16 hpMax;
    u8 pad1c[4];
    s16 x20;
    s16 x22;
    u8 pad24[4];
    f32 x28;
    u8 pad2c[0xe];
    s16 s3a;
    s16 s3c;
    s16 s3e;
    s16 s40;
    s16 s42;
    u8 pad44[0x18];
} SaveChar;
/* 0x5c */
typedef struct { s16 id; s8 cnt; u8 pad; } InvEnt;

/* The block at 0x1568 of the save data; the field names give the offset in SaveData. */
typedef struct Save1568 {
    s8 b1568;                   /* 0x00 */
    u8 x1569;                   /* 0x01 */
    char name[0x12];            /* 0x02: the ship's name */
    s32 x157c;                  /* 0x14 */
    s16 s1580[5];               /* 0x18 */
    s16 s158a[5];               /* 0x22 */
} Save1568;

typedef struct SaveData {
    SaveChar chr[8];            /* 0x000 */
    u8 pad2e0[0x328 - 0x2e0];
    s8 party[5];                /* 0x328 */
    u8 x32d;
    s8 x32e;
    s8 x32f;
    s8 x330;
    u8 pad331[0x344 - 0x331];
    s16 x344;
    s16 x346;
    s16 x348;                   /* clamped to 0..255 */
    u8 pad34a[2];
    s32 w34c;                   /* gold */
    s32 x350;
    InvEnt s354[0x50];
    InvEnt s494[0x50];
    InvEnt s5d4[0x50];
    InvEnt s714[0x50];
    InvEnt s854[0x50];
    InvEnt s994[0x1e];
    InvEnt sa0c[0x28];
    InvEnt saac[0x28];
    u8 xb4c;
    u8 xb4d;                /* proximity level of the nearest sparkle (0..4) */
    u8 padb4e[2];
    u8 xb50;
    u8 padb51[0x1568 - 0xb51];
    Save1568 x1568;             /* 0x1568 */
    u8 pad1594[0x16A0 - 0x1594];
} SaveData;

extern SaveData lbl_8030B7F4;

#endif
