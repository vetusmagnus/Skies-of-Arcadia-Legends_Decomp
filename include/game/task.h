#ifndef GAME_TASK_H
#define GAME_TASK_H

#include "types.h"

/* The game's task system (0x40-byte tasks in a tree; see docs/ui.md). Only the fields the
 * decompiled code uses are named. */
typedef struct Task Task;
typedef void (*TaskFunc)(Task* task);

struct Task {
    TaskFunc func; /* 0x00 */
    Task* next;    /* 0x04 */
    Task* parent;  /* 0x08 */
    u8 pad0C[0x0C];
    u8 flags; /* 0x18: 0x40 delete, 0x10 deleted */
    u8 state; /* 0x19: 0 new, 0xFF dying */
    u8 pad1A[0x0A];
    void* work; /* 0x24 */
};

s32 TaskDelete(Task* task);

#endif
