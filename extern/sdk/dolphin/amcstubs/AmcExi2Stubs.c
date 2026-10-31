#include <amcstubs/AmcExi2Stubs.h>

void EXI2_Init(volatile u8** inputPendingPtrRef, AmcEXICallback monitorCallback) {
}

void EXI2_EnableInterrupts(void) {
}

int EXI2_Poll(void) {
    return 0;
}

AmcExiError EXI2_ReadN(void* bytes, u32 length) {
    return AMC_EXI_NO_ERROR;
}

AmcExiError EXI2_WriteN(const void* bytes, u32 length) {
    return AMC_EXI_NO_ERROR;
}

void EXI2_Reserve(void) {
}

void EXI2_Unreserve(void) {
}

BOOL AMC_IsStub(void) {
    return TRUE;
}
