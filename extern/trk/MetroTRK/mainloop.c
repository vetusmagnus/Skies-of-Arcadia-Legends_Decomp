#include "types.h"
#include "PowerPC_EABI_Support/MetroTRK/trk.h"

extern TRKEventQueue gTRKEventQueue;
extern TRKState gTRKState;

/**
 * @note Address: 0x800BB390
 * @note Size: 0xF8
 */
void TRKNubMainLoop(void)
{
	void* msg;
	TRKEvent event;
	BOOL isShutdownRequested;
	BOOL isNewInput;

	isShutdownRequested = FALSE;
	isNewInput          = FALSE;
	while (isShutdownRequested == FALSE) {
		if (TRKGetNextEvent(&event) != FALSE) {
			isNewInput = FALSE;

			switch (*(u8*)&event.eventType) {
			case NUBEVENT_Null:
				break;

			case NUBEVENT_Request:
				msg = TRKGetBuffer(event.msgBufID);
				TRKDispatchMessage(msg);
				break;

			case NUBEVENT_Shutdown:
				isShutdownRequested = TRUE;
				break;

			case NUBEVENT_Breakpoint:
			case NUBEVENT_Exception:
				TRKTargetInterrupt(&event);
				break;

			case NUBEVENT_Support:
				TRKTargetSupportRequest();
				break;
			}

			TRKDestructEvent(&event);
			continue;
		}

		if ((isNewInput == FALSE) || (*(u8*)gTRKInputPendingPtr != '\0')) {
			isNewInput = TRUE;
			TRKGetInput();
			continue;
		}

		if (TRKTargetStopped() == FALSE) {
			TRKTargetContinue();
		}
		isNewInput = FALSE;
	}
}
