#include "PowerPC_EABI_Support/MetroTRK/trk.h"

extern void TRKTargetAddExceptionInfo(MessageBuffer*);

DSError TRKDoNotifyStopped(u8 cmd)
{
	int reqIdx;
	int bufIdx;
	MessageBuffer* msg;
	DSError err;

	err = TRKGetFreeBuffer(&bufIdx, &msg);
	if (err == DS_NoError) {
		err = TRKAppendBuffer1_ui8(msg, cmd);
		if (err == DS_NoError) {
			if (cmd == DSMSG_NotifyStopped) {
				TRKTargetAddStopInfo(msg);
			} else {
				TRKTargetAddExceptionInfo(msg);
			}
		}
		err = TRKRequestSend(msg, &reqIdx, 2, 3, 1);
		if (err == DS_NoError) {
			TRKReleaseBuffer(reqIdx);
		}
		TRKReleaseBuffer(bufIdx);
	}
	return err;
}
