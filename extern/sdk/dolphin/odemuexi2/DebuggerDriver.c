#include <dolphin/os.h>
#include <dolphin/hw_regs.h>

typedef void (*MTRCallbackType)(int);
typedef void (*DBGCallbackType)(u32, OSContext*);

static MTRCallbackType MTRCallback;
static DBGCallbackType DBGCallback;
static u32 SendMailData;
static s32 RecvDataLeng;
static volatile u8* pEXIInputFlag;
static u8 EXIInputFlag;
static u8 SendCount = 0x80;

#define IS_TRUE(x)  ((x) != FALSE)
#define IS_FALSE(x) !IS_TRUE(x)
#define ROUND_UP(x, align) (((x) + (align)-1) & (-(align)))

static void DBGEXIInit(void) {
    __OSMaskInterrupts(0x18000);
    __EXIRegs[10] = 0;
}

static BOOL DBGEXISelect(u32 v) {
    u32 regs = __EXIRegs[10];
    regs &= 0x405;
    regs |= 0x80 | (v << 4);
    __EXIRegs[10] = regs;
    return TRUE;
}

static BOOL DBGEXIDeselect(void) {
    __EXIRegs[10] &= 0x405;
    return TRUE;
}

static BOOL DBGEXISync(void) {
    while (__EXIRegs[13] & 1) {
    }
    return TRUE;
}

static BOOL DBGEXIImm(void* buffer, s32 bytecounter, u32 write) {
    u8* tempPointer;
    u32 writeOutValue;
    int i;

    if (write) {
        writeOutValue = 0;
        for (i = 0; i < bytecounter; i++) {
            writeOutValue |= ((u8*)buffer)[i] << ((3 - i) << 3);
        }
        __EXIRegs[14] = writeOutValue;
    }

    __EXIRegs[13] = 1 | write << 2 | (bytecounter - 1) << 4;
    DBGEXISync();

    if (!write) {
        writeOutValue = __EXIRegs[14];
        tempPointer = buffer;
        for (i = 0; i < bytecounter; i++) {
            *tempPointer++ = writeOutValue >> ((3 - i) << 3);
        }
    }

    return TRUE;
}

static BOOL DBGWriteMailbox(u32 p1) {
    BOOL total = FALSE;
    u32 v;

    if (!DBGEXISelect(4)) {
        return FALSE;
    }
    v = (p1 & 0x1FFFFFFF) | 0xC0000000;
    total |= IS_FALSE(DBGEXIImm(&v, sizeof(v), 1));
    total |= IS_FALSE(DBGEXISync());
    total |= IS_FALSE(DBGEXIDeselect());

    return IS_FALSE(total);
}

static BOOL DBGReadMailbox(u32* p1) {
    BOOL total = FALSE;
    u32 v;

    if (!DBGEXISelect(4)) {
        return FALSE;
    }
    v = 0x60000000;
    total |= IS_FALSE(DBGEXIImm(&v, 2, 1));
    total |= IS_FALSE(DBGEXISync());
    total |= IS_FALSE(DBGEXIImm(p1, 4, 0));
    total |= IS_FALSE(DBGEXISync());
    total |= IS_FALSE(DBGEXIDeselect());

    return IS_FALSE(total);
}

static BOOL DBGRead(u32 count, u32* buffer, s32 param3) {
    BOOL total = FALSE;
    u32* buf_p = buffer;
    u32 v1;
    u32 v;

    if (!DBGEXISelect(4)) {
        return FALSE;
    }
    v1 = (count & 0x1FFFC) << 8 | 0x20000000;
    total |= IS_FALSE(DBGEXIImm(&v1, sizeof(v1), 1));
    total |= IS_FALSE(DBGEXISync());

    while (param3) {
        total |= IS_FALSE(DBGEXIImm(&v, sizeof(v), 0));
        total |= IS_FALSE(DBGEXISync());
        *buf_p++ = v;
        param3 -= 4;
        if (param3 < 0) {
            param3 = 0;
        }
    }

    total |= IS_FALSE(DBGEXIDeselect());
    return IS_FALSE(total);
}

static BOOL DBGWrite(u32 count, const void* buffer, s32 param3) {
    BOOL total = FALSE;
    const u32* buf_p = buffer;
    u32 v1;
    u32 v;

    if (!DBGEXISelect(4)) {
        return FALSE;
    }
    v1 = (count & 0x1FFFC) << 8 | 0xA0000000;
    total |= IS_FALSE(DBGEXIImm(&v1, sizeof(v1), 1));
    total |= IS_FALSE(DBGEXISync());

    while (param3) {
        v = *buf_p++;
        total |= IS_FALSE(DBGEXIImm(&v, sizeof(v), 1));
        total |= IS_FALSE(DBGEXISync());
        param3 -= 4;
        if (param3 < 0) {
            param3 = 0;
        }
    }

    total |= IS_FALSE(DBGEXIDeselect());
    return IS_FALSE(total);
}

static BOOL DBGReadStatus(u32* p1) {
    BOOL total = FALSE;
    u32 v;

    if (!DBGEXISelect(4)) {
        return FALSE;
    }
    v = 0x40000000;
    total |= IS_FALSE(DBGEXIImm(&v, 2, 1));
    total |= IS_FALSE(DBGEXISync());
    total |= IS_FALSE(DBGEXIImm(p1, 4, 0));
    total |= IS_FALSE(DBGEXISync());
    total |= IS_FALSE(DBGEXIDeselect());

    return IS_FALSE(total);
}

static void MWCallback(u32 a, OSContext* b) {
    EXIInputFlag = TRUE;
    if (MTRCallback) {
        MTRCallback(0);
    }
}

static void DBGHandler(__OSInterrupt a, OSContext* b) {
    __PIRegs[0] = 0x1000;
    if (DBGCallback) {
        DBGCallback(a, b);
    }
}

void DBInitComm(volatile u8** inputFlagPtr, MTRCallbackType callback) {
    BOOL interrupts = OSDisableInterrupts();

    pEXIInputFlag = &EXIInputFlag;
    *inputFlagPtr = pEXIInputFlag;
    MTRCallback = callback;
    DBGEXIInit();
    OSRestoreInterrupts(interrupts);
}

void DBInitInterrupts(void) {
    __OSMaskInterrupts(0x18000);
    __OSMaskInterrupts(0x40);
    DBGCallback = MWCallback;
    __OSSetInterruptHandler(0x19, DBGHandler);
    __OSUnmaskInterrupts(0x40);
}

static void CheckMailBox(void) {
    u32 v;

    DBGReadStatus(&v);
    if (v & 1) {
        DBGReadMailbox(&v);
        v &= 0x1FFFFFFF;
        if ((v & 0x1F000000) == 0x1F000000) {
            SendMailData = v;
            RecvDataLeng = v & 0x7FFF;
            EXIInputFlag = 1;
        }
    }
}

u32 DBQueryData(void) {
    BOOL interrupts;

    EXIInputFlag = 0;
    if (RecvDataLeng == 0) {
        interrupts = OSDisableInterrupts();
        CheckMailBox();
        OSRestoreInterrupts(interrupts);
    }
    return RecvDataLeng;
}

int DBRead(void* data, u32 size) {
    BOOL interrupts = OSDisableInterrupts();
    u32 v = (SendMailData & 0x10000) ? 0x1000 : 0;

    DBGRead(v + 0x1E000, data, ROUND_UP(size, 4));
    RecvDataLeng = 0;
    EXIInputFlag = 0;
    OSRestoreInterrupts(interrupts);
    return 0;
}

int DBWrite(const void* src, u32 size) {
    u32 v;
    u32 busyFlag;
    BOOL interrupts = OSDisableInterrupts();

    do {
        DBGReadStatus(&busyFlag);
    } while (busyFlag & 2);

    SendCount++;
    v = (SendCount & 1) ? 0x1000 : 0;

    while (!DBGWrite(v | 0x1C000, src, ROUND_UP(size, 4))) {
    }

    do {
        DBGReadStatus(&busyFlag);
    } while (busyFlag & 2);

    v = SendCount;
    while (!DBGWriteMailbox(0x1F000000 | v << 16 | size)) {
    }

    do {
        while (!DBGReadStatus(&busyFlag)) {
        }
    } while (busyFlag & 2);

    OSRestoreInterrupts(interrupts);
    return 0;
}

void DBOpen(void) {
}

void DBClose(void) {
}
