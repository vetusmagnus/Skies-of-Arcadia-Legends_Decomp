#include <dolphin/os.h>
static int __heap_inited;
inline static void InitDefaultHeap(void) {
    void* arenaLo;
    void* arenaHi;
    arenaLo = OSGetArenaLo();
    arenaHi = OSGetArenaHi();
    arenaLo = OSInitAlloc(arenaLo, arenaHi, 1);
    OSSetArenaLo(arenaLo);
    arenaLo = (void*)(((u32)arenaLo + 31) & ~31);
    arenaHi = (void*)((u32)arenaHi & ~31);
    OSSetCurrentHeap(OSCreateHeap(arenaLo, arenaHi));
    OSSetArenaLo(arenaLo = arenaHi);
}
void __sys_free(void* ptr) {
    if (__heap_inited == 0) {
        InitDefaultHeap();
        __heap_inited = 1;
    }
    OSFreeToHeap(0, ptr);
}
