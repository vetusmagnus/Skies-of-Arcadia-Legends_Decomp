#ifndef GAME_UTIL_H
#define GAME_UTIL_H

#include "types.h"

/* Memory helpers that work in the widest unit both pointers' alignment allows. */
s32 MemEqual(const void* a, const void* b, s32 size); /* 1 if equal */
void MemCopy(void* dst, const void* src, s32 size);

#endif
