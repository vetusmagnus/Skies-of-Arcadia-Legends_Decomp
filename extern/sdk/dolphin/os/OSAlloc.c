#include <dolphin/types.h>
#include <dolphin/os.h>
#include <string.h>

/* Skies' OSAlloc.c revision (0x80005600-0x80005D98, first .text unit, before game code).
 * Adds a best-fit mode to OSAllocFromHeap (flag owned by game code), a calloc wrapper and an
 * in-place shrink (OSResizeHeapBlock: names of these two are ours). */

#define ALIGNMENT 32u
#define MINOBJSIZE 64u
#define HEADERSIZE 32u

#define InRange(cell, arenaStart, arenaEnd) ((u32)(arenaStart) <= (u32)(cell)) && ((u32)(cell) < (u32)(arenaEnd))
#undef OFFSET
#define OFFSET(n, a) (((u32)(n)) & ((a) - 1))

#define ASSERTREPORT(line, cond)                                     \
    if (!(cond)) {                                                   \
        OSReport("OSCheckHeap: Failed " #cond " in %d", line);       \
        return -1;                                                   \
    }

typedef struct Cell Cell;
typedef struct HeapDesc HeapDesc;

struct Cell {
    Cell* prev;
    Cell* next;
    s32 size;
};

struct HeapDesc {
    s32 size;
    Cell* free;
    Cell* allocated;
};

extern u32 lbl_803476E4; /* best-fit switch, set by game code */

/* OSAlloc's statics sit after the game's zero-initialised .sbss (0x80347888), apart from the rest of
 * this object's data, so the build defines them with the surrounding small data. */
extern void* ArenaEnd;
extern void* ArenaStart;
extern int NumHeaps;
extern HeapDesc* HeapArray;
volatile int __OSCurrHeap = -1;

static inline Cell* DLAddFront(Cell* neighbor, Cell* cell) {
    cell->next = neighbor;
    cell->prev = NULL;
    if (neighbor != NULL) {
        neighbor->prev = cell;
    }
    return cell;
}

static inline Cell* DLExtract(Cell* list, Cell* cell) {
    if (cell->next != NULL) {
        cell->next->prev = cell->prev;
    }
    if (cell->prev == NULL) {
        list = cell->next;
    } else {
        cell->prev->next = cell->next;
    }
    return list;
}

static Cell* DLInsert(Cell* list, Cell* cell) {
    Cell* before;
    Cell* after;

    before = NULL;
    after = list;
    while (after != NULL) {
        if (cell <= after) {
            break;
        }
        before = after;
        after = after->next;
    }

    cell->next = after;
    cell->prev = before;
    if (after != NULL) {
        after->prev = cell;
        if ((u8*)cell + cell->size == (u8*)after) {
            cell->size += after->size;
            after = after->next;
            cell->next = after;
            if (after != NULL) {
                after->prev = cell;
            }
        }
    }

    if (before != NULL) {
        before->next = cell;
        if ((u8*)before + before->size == (u8*)cell) {
            before->size += cell->size;
            before->next = after;
            if (after != NULL) {
                after->prev = before;
            }
        }
        return list;
    }
    return cell;
}

void* OSAllocFromHeap(int heap, u32 size) {
    HeapDesc* hd;
    Cell* cell;
    s32 sizeAligned;
    u32 leftoverSpace;

    hd = &HeapArray[heap];
    sizeAligned = (size + HEADERSIZE + (ALIGNMENT - 1)) & ~(ALIGNMENT - 1);

    if (lbl_803476E4) {
        Cell* best = NULL;
        s32 bestSpace = 0x7FFFFFFF;

        for (cell = hd->free; cell != NULL; cell = cell->next) {
            if (sizeAligned <= cell->size) {
                s32 space = cell->size - sizeAligned;
                if (bestSpace > space) {
                    bestSpace = space;
                    best = cell;
                }
            }
        }
        cell = best;
    } else {
        for (cell = hd->free; cell != NULL; cell = cell->next) {
            if (sizeAligned <= cell->size) {
                break;
            }
        }
    }

    if (cell == NULL) {
        return NULL;
    }

    leftoverSpace = cell->size - sizeAligned;
    if (leftoverSpace < MINOBJSIZE + HEADERSIZE) {
        hd->free = DLExtract(hd->free, cell);
    } else {
        Cell* newCell;

        cell->size = sizeAligned;
        newCell = (void*)((u8*)cell + sizeAligned);
        newCell->size = leftoverSpace;
        newCell->prev = cell->prev;
        newCell->next = cell->next;
        if (newCell->next != NULL) {
            newCell->next->prev = newCell;
        }
        if (newCell->prev != NULL) {
            newCell->prev->next = newCell;
        } else {
            hd->free = newCell;
        }
    }

    hd->allocated = DLAddFront(hd->allocated, cell);
    return (u8*)cell + HEADERSIZE;
}

void* OSAllocFromHeapClear(int heap, u32 size) {
    void* ptr = OSAllocFromHeap(heap, size);
    if (ptr != NULL) {
        memset(ptr, 0, size);
    }
    return ptr;
}

void OSFreeToHeap(int heap, void* ptr) {
    Cell* cell;
    HeapDesc* hd;

    cell = (void*)((u8*)ptr - HEADERSIZE);
    hd = &HeapArray[heap];

    hd->allocated = DLExtract(hd->allocated, cell);
    hd->free = DLInsert(hd->free, cell);
}

void* OSResizeHeapBlock(int heap, void* ptr, u32 size) {
    HeapDesc* hd;
    Cell* cell;
    Cell* newCell;
    s32 sizeAligned;
    s32 leftoverSpace;

    hd = &HeapArray[heap];
    cell = (void*)((u8*)ptr - HEADERSIZE);
    sizeAligned = (size + HEADERSIZE + (ALIGNMENT - 1)) & ~(ALIGNMENT - 1);

    leftoverSpace = cell->size - sizeAligned;
    if (leftoverSpace < 0) {
        return NULL;
    }
    if (leftoverSpace < MINOBJSIZE + HEADERSIZE) {
        return ptr;
    }

    cell->size = sizeAligned;
    newCell = (void*)((u8*)cell + sizeAligned);
    newCell->size = leftoverSpace;
    hd->free = DLInsert(hd->free, newCell);
    return (u8*)cell + HEADERSIZE;
}

int OSSetCurrentHeap(int heap) {
    int old;

    old = __OSCurrHeap;
    __OSCurrHeap = heap;
    return old;
}

void* OSInitAlloc(void* arenaStart, void* arenaEnd, int maxHeaps) {
    u32 totalSize;
    int i;

    totalSize = maxHeaps * sizeof(HeapDesc);
    HeapArray = arenaStart;
    NumHeaps = maxHeaps;

    for (i = 0; i < NumHeaps; i++) {
        HeapDesc* hd;

        hd = &HeapArray[i];
        hd->size = -1;
        hd->free = hd->allocated = NULL;
    }

    __OSCurrHeap = -1;

    arenaStart = (u8*)HeapArray + totalSize;
    arenaStart = (void*)(((u32)arenaStart + (ALIGNMENT - 1)) & ~(ALIGNMENT - 1));
    ArenaStart = arenaStart;
    ArenaEnd = (void*)((u32)arenaEnd & ~(ALIGNMENT - 1));
    return arenaStart;
}

int OSCreateHeap(void* start, void* end) {
    int i;
    Cell* cell;

    cell = (void*)(((u32)start + (ALIGNMENT - 1)) & ~(ALIGNMENT - 1));
    end = (void*)((u32)end & ~(ALIGNMENT - 1));

    for (i = 0; i < NumHeaps; i++) {
        HeapDesc* hd;

        hd = &HeapArray[i];
        if (hd->size < 0) {
            hd->size = (u8*)end - (u8*)cell;
            cell->prev = NULL;
            cell->next = NULL;
            cell->size = hd->size;
            hd->free = cell;
            hd->allocated = NULL;
            return i;
        }
    }

    return -1;
}

void OSDestroyHeap(int heap) {
    HeapArray[heap].size = -1;
}

long OSCheckHeap(int heap) {
    HeapDesc* hd;
    Cell* cell;
    long total = 0;
    long free = 0;

    ASSERTREPORT(0x479, HeapArray);
    ASSERTREPORT(0x47A, 0 <= heap && heap < NumHeaps);

    hd = &HeapArray[heap];
    ASSERTREPORT(0x47D, 0 <= hd->size);

    ASSERTREPORT(0x47F, hd->allocated == NULL || hd->allocated->prev == NULL);

    for (cell = hd->allocated; cell; cell = cell->next) {
        ASSERTREPORT(0x482, InRange(cell, ArenaStart, ArenaEnd));
        ASSERTREPORT(0x483, OFFSET(cell, ALIGNMENT) == 0);
        ASSERTREPORT(0x484, cell->next == NULL || cell->next->prev == cell);
        ASSERTREPORT(0x485, MINOBJSIZE <= cell->size);
        ASSERTREPORT(0x486, OFFSET(cell->size, ALIGNMENT) == 0);

        total += cell->size;
        ASSERTREPORT(0x489, 0 < total && total <= hd->size);
    }

    ASSERTREPORT(0x491, hd->free == NULL || hd->free->prev == NULL);

    for (cell = hd->free; cell; cell = cell->next) {
        ASSERTREPORT(0x494, InRange(cell, ArenaStart, ArenaEnd));
        ASSERTREPORT(0x495, OFFSET(cell, ALIGNMENT) == 0);
        ASSERTREPORT(0x496, cell->next == NULL || cell->next->prev == cell);
        ASSERTREPORT(0x497, MINOBJSIZE <= cell->size);
        ASSERTREPORT(0x498, OFFSET(cell->size, ALIGNMENT) == 0);
        ASSERTREPORT(0x499, cell->next == NULL || (char*) cell + cell->size < (char*) cell->next);

        total += cell->size;
        free += cell->size - ALIGNMENT;
        ASSERTREPORT(0x49D, 0 < total && total <= hd->size);
    }

    ASSERTREPORT(0x4A4, total == hd->size);
    return free;
}

void OSDumpHeap(int heap) {
    HeapDesc* hd;
    Cell* cell;
    int i;

    OSReport("\nOSDumpHeap(%d):\n", heap);
    hd = &HeapArray[heap];
    if (hd->size < 0) {
        OSReport("--------Inactive\n");
        return;
    }

    OSReport("addr\tsize\t\tend\tprev\tnext\n");
    OSReport("--------Allocated\n");
    for (i = 0, cell = hd->allocated; cell; cell = cell->next, i++) {
        OSReport("%4d:\t%x\t%5d\t%x\t%x\t%x\n", i, cell, cell->size, (char*)cell + cell->size, cell->prev, cell->next);
    }
    OSReport("--------Free\n");
    for (i = 0, cell = hd->free; cell; cell = cell->next, i++) {
        OSReport("%4d:\t%x\t%5d\t%x\t%x\t%x\n", i, cell, cell->size, (char*)cell + cell->size, cell->prev, cell->next);
    }
}
