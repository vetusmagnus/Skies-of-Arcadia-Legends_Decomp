#ifndef GAME_CHUNKLIST_H
#define GAME_CHUNKLIST_H

#include "types.h"

/* A resource chunk list is an array of 16-byte headers ended by an entry with a negative id. */
typedef struct {
    s16 id;
    s16 type;
    s32 pad4;
    s32 size;
    void* data;
} ChunkHdr;

/* Object stats block (lbl_8030A10C): the chunk cache, the pending chunk list and task counters. */
typedef struct {
    u8 pad0[0x6C];
    u32 flags6c;            /* 0x6C */
    u8 pad70[0x100 - 0x70];
    ChunkHdr* pending;      /* 0x100 */
    u8 pad104[0x4];
    ChunkHdr* cache[12];    /* 0x108 */
    s32 cacheKey[12];       /* 0x138 */
    u8 pad168[0x1C4 - 0x168];
    s32 count;              /* 0x1C4 */
    s16 x1c8;               /* 0x1C8 */
    s16 x1ca;               /* 0x1CA */
    u32 flags;              /* 0x1CC */
} ObjStats;

extern ObjStats lbl_8030A10C;

#endif
