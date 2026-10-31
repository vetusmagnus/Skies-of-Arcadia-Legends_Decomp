#include "PowerPC_EABI_Support/MetroTRK/trk.h"


static TRKFramingState gTRKFramingState;
void* gTRKInputPendingPtr;


static inline void TRKDiscardFrame(void)
{
	if (gTRKFramingState.msgBufID != -1) {
		TRKReleaseBuffer(gTRKFramingState.msgBufID);
		gTRKFramingState.msgBufID = -1;
	}
	gTRKFramingState.buffer       = NULL;
	gTRKFramingState.receiveState = 0;
}

static inline BOOL TRKCheckFrame(void)
{
	MessageBuffer* b = gTRKFramingState.buffer;
	if (b->length < 2) {
		TRKStandardACK(b, 0xff, 2);
		TRKDiscardFrame();
		return FALSE;
	}
	b->position = 0;
	b->length--;
	return TRUE;
}

MessageBufferID TRKTestForPacket(void)
{
	s8 c;
	int err;
	int frameErr = 0;

	err = TRKReadUARTPoll(&c);
	while (err == 0 && frameErr == 0) {
		if (gTRKFramingState.receiveState != 2) {
			gTRKFramingState.isEscape = FALSE;
		}
		switch (gTRKFramingState.receiveState) {
		case 0:
			if (c == 0x7e) {
				frameErr = TRKGetFreeBuffer(&gTRKFramingState.msgBufID, &gTRKFramingState.buffer);
				gTRKFramingState.fcsType          = 0;
				gTRKFramingState.receiveState = 1;
			}
			break;
		case 1:
			if (c == 0x7e) {
				break;
			}
			gTRKFramingState.receiveState = 2;
			/* fallthrough */
		case 2:
			if (c == 0x7e) {
				BOOL ok;
				if (gTRKFramingState.isEscape) {
					TRKStandardACK(gTRKFramingState.buffer, 0xff, 4);
					if (gTRKFramingState.msgBufID != -1) {
						TRKReleaseBuffer(gTRKFramingState.msgBufID);
						gTRKFramingState.msgBufID = -1;
					}
					gTRKFramingState.buffer       = NULL;
					gTRKFramingState.receiveState = 0;
				} else {
					ok = TRKCheckFrame();
					if (ok) {
						int id                        = gTRKFramingState.msgBufID;
						gTRKFramingState.msgBufID     = -1;
						gTRKFramingState.buffer       = NULL;
						gTRKFramingState.receiveState = 0;
						return id;
					}
					gTRKFramingState.receiveState = 0;
				}
			} else {
				if (gTRKFramingState.isEscape) {
					c                         = c ^ 0x20;
					gTRKFramingState.isEscape = FALSE;
				} else if (c == 0x7d) {
					gTRKFramingState.isEscape = TRUE;
					break;
				}
				{
					frameErr = TRKAppendBuffer1_ui8(gTRKFramingState.buffer, c);
				}
				gTRKFramingState.fcsType += c;
			}
			break;
		case 3:
			if (c == 0x7e) {
				if (gTRKFramingState.msgBufID != -1) {
					TRKReleaseBuffer(gTRKFramingState.msgBufID);
					gTRKFramingState.msgBufID = -1;
				}
				gTRKFramingState.buffer       = NULL;
				gTRKFramingState.receiveState = 0;
			}
			break;
		}
		err = TRKReadUARTPoll(&c);
	}
	return -1;
}

void TRKGetInput(void)
{
	MessageBuffer* msg;
	u8 cmd;
	MessageBufferID id;
	TRKEvent event;
	id = TRKTestForPacket();
	if (id == -1) {
		return;
	}
	msg = TRKGetBuffer(id);
	TRKSetBufferPosition(msg, 0);
	TRKReadBuffer1_ui8(msg, &cmd);
	if (cmd < 0x80) {
		TRKConstructEvent(&event, 2);
		event.msgBufID            = id;
		gTRKFramingState.msgBufID = -1;
		TRKPostEvent(&event);
	} else {
		TRKReleaseBuffer(id);
	}
}

void TRKProcessInput(int bufferIdx)
{
	TRKEvent event;

	TRKConstructEvent(&event, NUBEVENT_Request);
	event.msgBufID            = bufferIdx;
	gTRKFramingState.msgBufID = -1;
	TRKPostEvent(&event);
}

DSError TRKInitializeSerialHandler()
{
	gTRKFramingState.msgBufID     = -1;
	gTRKFramingState.receiveState = 0;
	gTRKFramingState.isEscape     = FALSE;
	return DS_NoError;
}

DSError TRKTerminateSerialHandler(void)
{
	return DS_NoError;
}
