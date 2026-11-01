/* Standalone test case for the Ninja "per-use copy" blocker (docs/ninja.md, FIFO writers).
 *
 * fn_8029681C draws a point list. The original hoists the FIFO address once and copies it for
 * the third store:
 *     lis r30, 0xcc01 ; mr r31, r30 ; ... stfs f0,-0x8000(r30) ; stfs f1,-0x8000(r30) ; stfs f2,-0x8000(r31)
 * Every compiler tried here keeps one register for all three stores. The test only needs a
 * compiler, no headers and no build. The signal is the number of distinct base registers in the
 * `stfs` lines (the original has 2):
 *
 *   build/tools/wibo build/compilers/GC/1.3.2/mwcceppc.exe -nodefaults -proc gekko -fp hardware \
 *       -Cpp_exceptions off -O4,p -inline auto -c docs/near/fifo_8029681C.c -o build/fifo.o
 *   build/binutils/powerpc-eabi-objdump -d build/fifo.o | grep stfs
 *
 * Apart from the address register this compiles to the original (the point-size scale is 12.0f,
 * the pool constant lbl_8034D270). With GC/1.3.2nj it matches; fn_8029681C is now in ninja.c.
 */
typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;
typedef float f32;
typedef struct { f32 x, y, z; } NJS_POINT3;
typedef union { u8 u8; u32 u32; f32 f32; } PPCWGPipe;
volatile PPCWGPipe GXWGFifo : 0xCC008000;
void GXSetPointSize(u8 size, s32 fmt);
void GXBegin(s32 prim, s32 fmt, unsigned short n);

static inline void GXPosition3f32(f32 x, f32 y, f32 z) {
    GXWGFifo.f32 = x;
    GXWGFifo.f32 = y;
    GXWGFifo.f32 = z;
}

void fn_8029681C(NJS_POINT3* p, s32 n, f32 size) {
    GXSetPointSize(size * 12.0f, 0);
    do {
        GXBegin(0xB8, 0, 1);
        GXPosition3f32(p->x, p->y, p->z);
        p++;
    } while (--n);
}
