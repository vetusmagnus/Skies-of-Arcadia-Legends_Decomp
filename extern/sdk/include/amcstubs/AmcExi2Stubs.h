#ifndef _DOLPHIN_AMCEXI2STUBS_H
#define _DOLPHIN_AMCEXI2STUBS_H

#include <dolphin/types.h>
#include <dolphin/os.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef __OSInterruptHandler AmcEXICallback;

typedef enum {
    AMC_EXI_NO_ERROR = 0,
    AMC_EXI_UNSELECTED
} AmcExiError;

void EXI2_Init(volatile u8** inputPendingPtrRef, AmcEXICallback monitorCallback);
void EXI2_EnableInterrupts(void);
int EXI2_Poll(void);
AmcExiError EXI2_ReadN(void* bytes, u32 length);
AmcExiError EXI2_WriteN(const void* bytes, u32 length);
void EXI2_Reserve(void);
void EXI2_Unreserve(void);
BOOL AMC_IsStub(void);

#ifdef __cplusplus
}
#endif

#endif
