#include "PowerPC_EABI_Support/MetroTRK/trk.h"

typedef DSError (*TRKDispatchFunc)(MessageBuffer*);


static u32 gTRKDispatchTableSize;

static TRKDispatchFunc gTRKDispatchTable[32] = {
	TRKDoUnsupported, TRKDoConnect,     TRKDoDisconnect,  TRKDoReset,         TRKDoVersions,    TRKDoSupportMask, TRKDoCPUType,
	TRKDoUnsupported, TRKDoUnsupported, TRKDoUnsupported, TRKDoUnsupported,   TRKDoUnsupported, TRKDoUnsupported, TRKDoUnsupported,
	TRKDoUnsupported, TRKDoUnsupported, TRKDoReadMemory,  TRKDoWriteMemory,   TRKDoReadRegisters, TRKDoWriteRegisters, TRKDoUnsupported,
	TRKDoUnsupported, TRKDoFlushCache,  TRKDoSetOption,   TRKDoContinue,      TRKDoStep,        TRKDoStop,        TRKDoUnsupported,
	TRKDoUnsupported, TRKDoUnsupported, TRKDoUnsupported, TRKDoUnsupported,
};

DSError TRKInitializeDispatcher(void)
{
	gTRKDispatchTableSize = 0x20;
	return DS_NoError;
}

DSError TRKDispatchMessage(MessageBuffer* msg)
{
	DSError err = DS_DispatchError;
	u8 cmd;

	TRKSetBufferPosition(msg, 0);
	TRKReadBuffer1_ui8(msg, &cmd);
	cmd &= 0xFF;
	if (cmd < gTRKDispatchTableSize) {
		err = gTRKDispatchTable[cmd](msg);
	}
	return err;
}
