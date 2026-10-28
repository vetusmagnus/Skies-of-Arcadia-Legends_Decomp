/* gp_check.c (0x801D1AE8 - 0x801D24D0): the render mode for the TV format (fn_801D1C04), the copy
 * and viewport setup (fn_801D1B28), the frame flip (fn_801D1AE8), the FIFO limits (fn_801D1D2C), and
 * the graphics processor hang check: a pre-retrace callback (fn_801D1DE0) counts frames stuck at the
 * FIFO high watermark, fn_801D20D8 reports the GP state, fn_801D1ED4 reinitialises GX on a fresh FIFO
 * and fn_801D22CC waits for a draw-sync token, aborting the frame after two retraces.
 * The file name is the one fn_801D1C04 passes to fn_801DBA70.
 *
 * Built with -str reuse,readonly -inline noauto,deferred (configure.py): the functions are written
 * from the highest address down, so that the strings, the local array initialisers and the floats
 * land in the original order. fn_801D1AE8, fn_801D1B28 and fn_801D1D2C are called from other files
 * and also appear inlined in fn_801D1ED4 and fn_801D22CC, so their bodies are static inlines here.
 * The statics are declared in reverse because .sbss is laid out that way. See docs/compiler.md. */
#include "types.h"
#include <dolphin/os.h>
#include <dolphin/gx.h>
#include <dolphin/vi.h>

extern s32 lbl_803475AC;
extern GXRenderModeObj* lbl_803476C0;
extern void* lbl_803476AC;
extern void* lbl_803476B0;
extern void* lbl_803476B4;
extern GXRenderModeObj lbl_80313550;

extern void fn_801DBA70(const char* file, s32 line, const char* msg, ...);
extern void VIConfigure(const GXRenderModeObj* rm);
extern void* VIGetNextFrameBuffer(void);
extern void GXAbortFrame(void);
extern void fn_8024DF5C(u16 token);
extern u16 fn_8024E014(void);
extern void fn_8024E020(void);
extern f32 fn_8024EBE8(u16 efbHeight, u16 xfbHeight);
extern void fn_80252D88(u32* a, u32* b, u32* c, u32* d);
extern void GXSetGPMetric(s32 perf0, s32 perf1);
extern void GXClearGPMetric(void);

static u32 lbl_80347600;
static u32 lbl_803475FC;
static u32 lbl_803475F8;

GXRenderModeObj lbl_802F6518 = {
    4, 640, 480, 522, 40, 26, 640, 522, 1, 0, 0,
    { { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 },
      { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 } },
    { 8, 8, 10, 12, 10, 8, 8 },
};

void fn_801D1AE8(void);
void fn_801D1B28(void);
void fn_801D1C04(void);
void fn_801D1D2C(u32 hi, u32 lo);
void fn_801D1DE0(u32 retraceCount);
void fn_801D1ED4(void);
void fn_801D20D8(void);

/* Selects the GP metrics and writes the counter setup straight to the FIFO. */
static inline void GPMetricInit(void) {
    GXSetGPMetric(0x23, 0x16);
    GXWGFifo.u8 = 0x61;
    GXWGFifo.u32 = 0x2402C004;
    GXWGFifo.u8 = 0x61;
    GXWGFifo.u32 = 0x23000020;
    GXWGFifo.u8 = 0x10;
    GXWGFifo.u16 = 0;
    GXWGFifo.u16 = 0x1006;
    GXWGFifo.u32 = 0x84400;
}

static inline void GPSetFifoLimits(u32 hi, u32 lo) {
    GXFifoObj tmp;
    void* fb = VIGetNextFrameBuffer();
    GXFifoObj* cpu;
    fn_8024E020();
    cpu = GXGetCPUFifo();
    GXInitFifoBase(&tmp, fb, 0x10000);
    GXSetCPUFifo(&tmp);
    GXSetGPFifo(&tmp);
    GXInitFifoLimits(cpu, hi, lo);
    GXSetCPUFifo(cpu);
    GXSetGPFifo(cpu);
    if (lbl_803475AC != 0) {
        OSReport("INFOMATION: FIFO Limits Changed. ( High=0x%08X, Low=0x%08X )\n", hi, lo);
    }
}

static inline void GPSetRenderMode(void) {
    if (lbl_803476C0->field_rendering == 0) {
        GXSetViewport(0.0f, 0.0f, lbl_803476C0->fbWidth, lbl_803476C0->efbHeight, 0.0f, 1.0f);
    }
    GXSetScissor(0, 0, lbl_803476C0->fbWidth, lbl_803476C0->efbHeight);
    GXSetDispCopySrc(0, 0, lbl_803476C0->fbWidth, lbl_803476C0->efbHeight);
    GXSetDispCopyDst(lbl_803476C0->fbWidth, lbl_803476C0->xfbHeight);
    GXSetDispCopyYScale(fn_8024EBE8(lbl_803476C0->efbHeight, lbl_803476C0->xfbHeight));
    GXSetCopyFilter(lbl_803476C0->aa, lbl_803476C0->sample_pattern, GX_TRUE, lbl_803476C0->vfilter);
}

static inline void GPFlipFrame(void) {
    VISetNextFrameBuffer(lbl_803476AC);
    VIFlush();
    VIWaitForRetrace();
    if (lbl_803476C0->viTVmode & 1) {
        VIWaitForRetrace();
    }
}

void fn_801D2414(void) {
    VISetPreRetraceCallback(fn_801D1DE0);
    GPMetricInit();
    if (lbl_803475AC != 0) {
        OSReport("===================================\n");
        OSReport(" Graphics Processor Check Enable\n");
        OSReport("===================================\n");
    }
}

void fn_801D23E0(void) {
    fn_8024DF5C(0xFEEB);
    GXClearGPMetric();
    GXInvalidateVtxCache();
    GXInvalidateTexAll();
}

void fn_801D22CC(void) {
    BOOL aborted = FALSE;
    lbl_80347600 = 0;
    fn_8024DF5C(0xB00B);
    while (fn_8024E014() != 0xB00B && !aborted) {
        if (lbl_80347600 >= 2) {
            if (lbl_803475AC != 0) {
                OSReport("---------WARNING : ABORTING FRAME----------\n");
            }
            aborted = TRUE;
            fn_801D20D8();
            fn_801D1ED4();
            GPSetFifoLimits(0x3C000, 0x10000);
        }
    }
}

void fn_801D20D8(void) {
    OSCalendarTime cal;
    u32 a1, a0, a3, a2;
    u32 b1, b0, b3, b2;
    GXBool readIdle, cmdIdle, dummy;
    u32 sameB, sameA, diffHi, diffLo;
    fn_80252D88(&a0, &a1, &a2, &a3);
    fn_80252D88(&b0, &b1, &b2, &b3);
    sameB = (b1 - a1) == 0;
    sameA = (b0 - a0) == 0;
    diffHi = (b3 - a3) > 0;
    diffLo = (b2 - a2) > 0;
    GXGetGPStatus(&dummy, &dummy, &readIdle, &cmdIdle, &dummy);
    if (lbl_803475AC != 0) {
        OSTicksToCalendarTime(OSGetTime(), &cal);
        OSReport("Occurred Time ... %04.4d/%02.2d/%02.2d %02.2d:%02.2d:%02.2d\n",
                 cal.year, cal.mon + 1, cal.mday, cal.hour, cal.min, cal.sec);
        OSReport("GP status %d%d%d%d%d%d --> ", readIdle, cmdIdle, sameB, sameA, diffHi, diffLo);
        if (!sameA && diffHi) {
            OSReport("GP hang due to XF stall bug.\n");
        } else if (!sameB && sameA && diffHi) {
            OSReport("GP hang due to unterminated primitive.\n");
        } else if (!cmdIdle && sameB && sameA && diffHi) {
            OSReport("GP hang due to illegal instruction.\n");
        } else if (readIdle && cmdIdle && sameB && sameA && diffHi && diffLo) {
            OSReport("GP appears to be not hung (waiting for input).\n");
        } else {
            OSReport("GP is in unknown state.\n");
        }
    }
}

void fn_801D1ED4(void) {
    GXFifoObj fifo;
    GXFifoObj* cpu;
    void* base;
    u32 size;
    void* fb;
    fb = VIGetNextFrameBuffer();
    lbl_803476AC = (fb == lbl_803476B4) ? lbl_803476B4 : lbl_803476B0;
    cpu = GXGetCPUFifo();
    base = GXGetFifoBase(cpu);
    size = GXGetFifoSize(cpu);
    VIWaitForRetrace();
    GXAbortFrame();
    GXInitFifoBase(&fifo, fb, 0x10000);
    GXSetCPUFifo(&fifo);
    GXSetGPFifo(&fifo);
    fn_801D1C04();
    GXInit(base, size);
    GPSetRenderMode();
    GPFlipFrame();
    GPMetricInit();
    if (lbl_803475AC != 0) {
        OSReport("INFOMATION: Graphics Processor ReInit Complete.\n");
    }
}

void fn_801D1DE0(u32 retraceCount) {
    char name[] = "Hang AT High Watermark";
    GXBool hi, lo;
    u32 cnt;
    lbl_80347600++;
    GXGetGPStatus(&hi, &lo, &lo, &lo, &lo);
    cnt = GXGetOverflowCount();
    if (hi != 0 && cnt == lbl_803475FC) {
        lbl_803475F8++;
        if (lbl_803475F8 >= 2) {
            if (lbl_803475AC != 0) {
                OSReport("---------WARNING : %s ----------\n", name);
            }
            fn_801D20D8();
            for (;;) {}
        }
    } else {
        lbl_803475FC = cnt;
        lbl_803475F8 = 0;
    }
}

void fn_801D1D2C(u32 hi, u32 lo) {
    GPSetFifoLimits(hi, lo);
}

void fn_801D1C04(void) {
    const char* names[6] = { "NTSC", "PAL", "MPAL", "DEBUG", "DEBUG_PAL", "EURGB60" };
    u32 fmt = VIGetTvFormat();
    if (lbl_803475AC != 0) {
        OSReport("TV Format: %s\n", names[fmt]);
    }
    switch (fmt) {
    case 0:
        lbl_803476C0 = &GXNtsc480IntDf;
        break;
    case 2:
        lbl_803476C0 = &GXMpal480IntDf;
        break;
    case 1:
        lbl_803476C0 = &lbl_802F6518;
        break;
    default:
        lbl_803476C0 = 0;
        fn_801DBA70("gp_check.c", 0x28b, "Invalid TV Format.");
        break;
    }
    GXAdjustForOverscan(lbl_803476C0, &lbl_80313550, 0, 0);
    lbl_803476C0 = &lbl_80313550;
    VIConfigure(lbl_803476C0);
}

void fn_801D1B28(void) {
    GPSetRenderMode();
}

void fn_801D1AE8(void) {
    GPFlipFrame();
}
