#include "PowerPC_EABI_Support/MetroTRK/trk.h"

extern DSError TRKReadBuffer1_ui8(MessageBuffer* buffer, u8* data);
extern DSError TRKReadBuffer1_ui16(MessageBuffer* buffer, u16* data);
extern DSError TRKReadBuffer1_ui32(MessageBuffer* buffer, u32* data);
extern DSError TRKAppendBuffer1_ui16(MessageBuffer* buffer, const u16 data);
extern DSError TRKAppendBuffer(MessageBuffer* msg, const void* data, size_t length);
extern DSError TRKReadBuffer(MessageBuffer* msg, void* data, size_t length);

extern DSError TRKTargetAccessMemory(void* data, u32 start, size_t* length, BOOL userView, BOOL read);
extern DSError TRKTargetAccessDefault(u32 first, u32 last, MessageBuffer* b, size_t* length, BOOL read);
extern DSError TRKTargetAccessFP(u32 first, u32 last, MessageBuffer* b, size_t* length, BOOL read);
extern DSError TRKTargetAccessExtended1(u32 first, u32 last, MessageBuffer* b, size_t* length, BOOL read);
extern DSError TRKTargetAccessExtended2(u32 first, u32 last, MessageBuffer* b, size_t* length, BOOL read);
extern DSError TRKTargetVersions(void* versions);
extern DSError TRKTargetSupportMask(void* mask);
extern DSError TRKTargetCPUType(void* cpuType);
extern DSError TRKTargetStop(void);
extern u32 TRKTargetGetPC(void);
extern DSError TRKTargetSingleStep(int count, BOOL stepOver);
extern DSError TRKTargetStepOutOfRange(u32 start, u32 end, BOOL stepOver);
extern DSError TRKTargetFlushCache(u8 options, u32 start, u32 end);
extern void __TRK_reset(void);

static BOOL IsTRKConnected;

int GetTRKConnected(void)
{
	return IsTRKConnected;
}

void SetTRKConnected(int isConnected)
{
	IsTRKConnected = isConnected;
}

static inline DSError TRKSendACK(MessageBuffer* b)
{
	DSError err;
	int retry;

	retry = 3;
	do {
		err = TRKMessageSend(b);
		retry--;
		if (err == 0) {
			break;
		}
	} while (retry > 0);
	return err;
}

DSError TRKStandardACK(MessageBuffer* b, u8 commandID, u8 replyError)
{
	TRKResetBuffer(b, TRUE);
	TRKAppendBuffer1_ui8(b, commandID);
	TRKAppendBuffer1_ui8(b, replyError);
	return TRKSendACK(b);
}

DSError TRKDoUnsupported(MessageBuffer* b)
{
	return TRKStandardACK(b, DSMSG_ReplyACK, DSREPLY_UnsupportedCommandError);
}

DSError TRKDoConnect(MessageBuffer* b)
{
	IsTRKConnected = TRUE;
	return TRKStandardACK(b, DSMSG_ReplyACK, DSREPLY_NoError);
}

DSError TRKDoDisconnect(MessageBuffer* b)
{
	DSError err;
	TRKEvent event;

	IsTRKConnected = FALSE;
	err = TRKStandardACK(b, DSMSG_ReplyACK, DSREPLY_NoError);
	if (err == DS_NoError) {
		TRKConstructEvent(&event, 1);
		TRKPostEvent(&event);
	}
	return err;
}

DSError TRKDoReset(MessageBuffer* b)
{
	TRKStandardACK(b, DSMSG_ReplyACK, DSREPLY_NoError);
	__TRK_reset();
	return DS_NoError;
}

DSError TRKDoVersions(MessageBuffer* b)
{
	struct { u8 a, b, c, d; } versions;
	DSError err;

	if (b->length != 1) {
		return TRKStandardACK(b, DSMSG_ReplyACK, DSREPLY_PacketSizeError);
	}
	TRKResetBuffer(b, TRUE);
	TRKAppendBuffer1_ui8(b, DSMSG_ReplyACK);
	TRKAppendBuffer1_ui8(b, DSREPLY_NoError);
	err = TRKTargetVersions(&versions);
	if (err == DS_NoError) {
		err = TRKAppendBuffer1_ui8(b, versions.a);
	}
	if (err == DS_NoError) {
		err = TRKAppendBuffer1_ui8(b, versions.b);
	}
	if (err == DS_NoError) {
		err = TRKAppendBuffer1_ui8(b, versions.c);
	}
	if (err == DS_NoError) {
		err = TRKAppendBuffer1_ui8(b, versions.d);
	}
	if (err != DS_NoError) {
		return TRKStandardACK(b, DSMSG_ReplyACK, DSREPLY_CWDSError);
	}
	return TRKSendACK(b);
}

DSError TRKDoSupportMask(MessageBuffer* b)
{
	u8 mask[32];
	DSError err;

	if (b->length != 1) {
		return TRKStandardACK(b, DSMSG_ReplyACK, DSREPLY_PacketSizeError);
	}
	TRKResetBuffer(b, TRUE);
	TRKAppendBuffer1_ui8(b, DSMSG_ReplyACK);
	TRKAppendBuffer1_ui8(b, DSREPLY_NoError);
	err = TRKTargetSupportMask(mask);
	if (err == DS_NoError) {
		err = TRKAppendBuffer(b, mask, 32);
	}
	if (err == DS_NoError) {
		err = TRKAppendBuffer1_ui8(b, 2);
	}
	if (err != DS_NoError) {
		return TRKStandardACK(b, DSMSG_ReplyACK, DSREPLY_CWDSError);
	}
	return TRKSendACK(b);
}

DSError TRKDoCPUType(MessageBuffer* b)
{
	struct { u8 a, b, c, d, e, f, g; } cpu;
	DSError err;

	if (b->length != 1) {
		return TRKStandardACK(b, DSMSG_ReplyACK, DSREPLY_PacketSizeError);
	}
	TRKResetBuffer(b, TRUE);
	TRKAppendBuffer1_ui8(b, DSMSG_ReplyACK);
	TRKAppendBuffer1_ui8(b, DSREPLY_NoError);
	err = TRKTargetCPUType(&cpu);
	if (err == DS_NoError) {
		err = TRKAppendBuffer1_ui8(b, cpu.a);
	}
	if (err == DS_NoError) {
		err = TRKAppendBuffer1_ui8(b, cpu.b);
	}
	if (err == DS_NoError) {
		err = TRKAppendBuffer1_ui8(b, cpu.c);
	}
	if (err == DS_NoError) {
		err = TRKAppendBuffer1_ui8(b, cpu.d);
	}
	if (err == DS_NoError) {
		err = TRKAppendBuffer1_ui8(b, cpu.e);
	}
	if (err == DS_NoError) {
		err = TRKAppendBuffer1_ui8(b, cpu.f);
	}
	if (err == DS_NoError) {
		err = TRKAppendBuffer1_ui8(b, cpu.g);
	}
	if (err != DS_NoError) {
		return TRKStandardACK(b, DSMSG_ReplyACK, DSREPLY_CWDSError);
	}
	return TRKSendACK(b);
}

DSError TRKDoReadMemory(MessageBuffer* b)
{
	u8 buf[0x800];
	u32 start;
	size_t tempLength;
	u16 length;
	u8 cmd;
	u8 options;
	DSError err;
	int replyErr;

	if (b->length != 8) {
		return TRKStandardACK(b, DSMSG_ReplyACK, DSREPLY_PacketSizeError);
	}
	TRKSetBufferPosition(b, 0);
	err = TRKReadBuffer1_ui8(b, &cmd);
	if (err == DS_NoError) {
		err = TRKReadBuffer1_ui8(b, &options);
	}
	if (err == DS_NoError) {
		err = TRKReadBuffer1_ui16(b, &length);
	}
	if (err == DS_NoError) {
		err = TRKReadBuffer1_ui32(b, &start);
	}
	if (options & 2) {
		return TRKStandardACK(b, DSMSG_ReplyACK, DSREPLY_UnsupportedOptionError);
	}
	if (length > 0x800) {
		return TRKStandardACK(b, DSMSG_ReplyACK, DSREPLY_ParameterError);
	}
	TRKResetBuffer(b, TRUE);
	TRKAppendBuffer1_ui8(b, DSMSG_ReplyACK);
	TRKAppendBuffer1_ui8(b, DSREPLY_NoError);
	if (err == DS_NoError) {
		tempLength = length;
		err        = TRKTargetAccessMemory(buf, start, &tempLength, (options & 8) ? 0 : 1, TRUE);
		length     = tempLength;
		if (err == DS_NoError) {
			err = TRKAppendBuffer1_ui16(b, length);
		}
		if (err == DS_NoError) {
			err = TRKAppendBuffer(b, buf, tempLength);
		}
	}
	if (err != DS_NoError) {
		switch (err) {
		case DS_CWDSException:
			replyErr = DSREPLY_CWDSException;
			break;
		case DS_InvalidMemory:
			replyErr = DSREPLY_InvalidMemoryRange;
			break;
		case DS_InvalidProcessID:
			replyErr = DSREPLY_InvalidProcessID;
			break;
		case DS_InvalidThreadID:
			replyErr = DSREPLY_InvalidThreadID;
			break;
		case DS_OSError:
			replyErr = DSREPLY_OSError;
			break;
		default:
			replyErr = DSREPLY_CWDSError;
			break;
		}
		return TRKStandardACK(b, DSMSG_ReplyACK, replyErr);
	}
	return TRKSendACK(b);
}

DSError TRKDoWriteMemory(MessageBuffer* b)
{
	u8 buf[0x800];
	u32 start;
	size_t tempLength;
	u16 length;
	u8 cmd;
	u8 options;
	DSError err;
	int replyErr;

	if (b->length <= 8) {
		return TRKStandardACK(b, DSMSG_ReplyACK, DSREPLY_PacketSizeError);
	}
	TRKSetBufferPosition(b, 0);
	err = TRKReadBuffer1_ui8(b, &cmd);
	if (err == DS_NoError) {
		err = TRKReadBuffer1_ui8(b, &options);
	}
	if (err == DS_NoError) {
		err = TRKReadBuffer1_ui16(b, &length);
	}
	if (err == DS_NoError) {
		err = TRKReadBuffer1_ui32(b, &start);
	}
	if (options & 2) {
		return TRKStandardACK(b, DSMSG_ReplyACK, DSREPLY_UnsupportedOptionError);
	}
	if (b->length != length + 8 || length > 0x800) {
		return TRKStandardACK(b, DSMSG_ReplyACK, DSREPLY_ParameterError);
	}
	if (err == DS_NoError) {
		tempLength = length;
		err        = TRKReadBuffer(b, buf, length);
		if (err == DS_NoError) {
			err = TRKTargetAccessMemory(buf, start, &tempLength, (options & 8) ? 0 : 1, FALSE);
		}
		length = tempLength;
	}
	if (err == DS_NoError) {
		TRKResetBuffer(b, TRUE);
		TRKAppendBuffer1_ui8(b, DSMSG_ReplyACK);
		TRKAppendBuffer1_ui8(b, DSREPLY_NoError);
	}
	if (err == DS_NoError) {
		err = TRKAppendBuffer1_ui16(b, length);
	}
	if (err != DS_NoError) {
		switch (err) {
		case DS_CWDSException:
			replyErr = DSREPLY_CWDSException;
			break;
		case DS_InvalidMemory:
			replyErr = DSREPLY_InvalidMemoryRange;
			break;
		case DS_InvalidProcessID:
			replyErr = DSREPLY_InvalidProcessID;
			break;
		case DS_InvalidThreadID:
			replyErr = DSREPLY_InvalidThreadID;
			break;
		case DS_OSError:
			replyErr = DSREPLY_OSError;
			break;
		default:
			replyErr = DSREPLY_CWDSError;
			break;
		}
		return TRKStandardACK(b, DSMSG_ReplyACK, replyErr);
	}
	return TRKSendACK(b);
}

DSError TRKDoReadRegisters(MessageBuffer* b)
{
	size_t registersLength;
	u16 firstRegister;
	u16 lastRegister;
	u8 cmd;
	u8 options;
	DSError err;
	int replyError;

	if (b->length != 6) {
		return TRKStandardACK(b, DSMSG_ReplyACK, DSREPLY_PacketSizeError);
	}
	TRKSetBufferPosition(b, 0);
	err = TRKReadBuffer1_ui8(b, &cmd);
	if (err == DS_NoError) {
		err = TRKReadBuffer1_ui8(b, &options);
	}
	if (err == DS_NoError) {
		err = TRKReadBuffer1_ui16(b, &firstRegister);
	}
	if (err == DS_NoError) {
		err = TRKReadBuffer1_ui16(b, &lastRegister);
	}
	if (firstRegister > lastRegister) {
		return TRKStandardACK(b, DSMSG_ReplyACK, DSREPLY_InvalidRegisterRange);
	}
	if (err == DS_NoError) {
		TRKResetBuffer(b, TRUE);
		TRKAppendBuffer1_ui8(b, DSMSG_ReplyACK);
		TRKAppendBuffer1_ui8(b, DSREPLY_NoError);
	}
	switch (options & 7) {
	case 0:
		err = TRKTargetAccessDefault(firstRegister, lastRegister, b, &registersLength, TRUE);
		break;
	case 1:
		err = TRKTargetAccessFP(firstRegister, lastRegister, b, &registersLength, TRUE);
		break;
	case 2:
		err = TRKTargetAccessExtended1(firstRegister, lastRegister, b, &registersLength, TRUE);
		break;
	case 3:
		err = TRKTargetAccessExtended2(firstRegister, lastRegister, b, &registersLength, TRUE);
		break;
	default:
		err = DS_UnsupportedError;
		break;
	}
	if (err != DS_NoError) {
		switch (err) {
		case DS_UnsupportedError:
			replyError = DSREPLY_UnsupportedOptionError;
			break;
		case DS_InvalidRegister:
			replyError = DSREPLY_InvalidRegisterRange;
			break;
		case DS_CWDSException:
			replyError = DSREPLY_CWDSException;
			break;
		case DS_InvalidProcessID:
			replyError = DSREPLY_InvalidProcessID;
			break;
		case DS_InvalidThreadID:
			replyError = DSREPLY_InvalidThreadID;
			break;
		case DS_OSError:
			replyError = DSREPLY_OSError;
			break;
		default:
			replyError = DSREPLY_CWDSError;
			break;
		}
		return TRKStandardACK(b, DSMSG_ReplyACK, replyError);
	}
	return TRKSendACK(b);
}

DSError TRKDoWriteRegisters(MessageBuffer* b)
{
	size_t registersLength;
	u16 firstRegister;
	u16 lastRegister;
	u8 cmd;
	u8 options;
	DSError err;
	int replyError;

	if (b->length <= 6) {
		return TRKStandardACK(b, DSMSG_ReplyACK, DSREPLY_PacketSizeError);
	}
	TRKSetBufferPosition(b, 0);
	err = TRKReadBuffer1_ui8(b, &cmd);
	if (err == DS_NoError) {
		err = TRKReadBuffer1_ui8(b, &options);
	}
	if (err == DS_NoError) {
		err = TRKReadBuffer1_ui16(b, &firstRegister);
	}
	if (err == DS_NoError) {
		err = TRKReadBuffer1_ui16(b, &lastRegister);
	}
	if (firstRegister > lastRegister) {
		return TRKStandardACK(b, DSMSG_ReplyACK, DSREPLY_InvalidRegisterRange);
	}
	switch (options) {
	case 0:
		err = TRKTargetAccessDefault(firstRegister, lastRegister, b, &registersLength, FALSE);
		break;
	case 1:
		err = TRKTargetAccessFP(firstRegister, lastRegister, b, &registersLength, FALSE);
		break;
	case 2:
		err = TRKTargetAccessExtended1(firstRegister, lastRegister, b, &registersLength, FALSE);
		break;
	case 3:
		err = TRKTargetAccessExtended2(firstRegister, lastRegister, b, &registersLength, FALSE);
		break;
	default:
		err = DS_UnsupportedError;
		break;
	}
	if (err == DS_NoError) {
		TRKResetBuffer(b, TRUE);
		TRKAppendBuffer1_ui8(b, DSMSG_ReplyACK);
		TRKAppendBuffer1_ui8(b, DSREPLY_NoError);
	}
	if (err != DS_NoError) {
		switch (err) {
		case DS_UnsupportedError:
			replyError = DSREPLY_UnsupportedOptionError;
			break;
		case DS_InvalidRegister:
			replyError = DSREPLY_InvalidRegisterRange;
			break;
		case DS_MessageBufferReadError:
			replyError = DSREPLY_PacketSizeError;
			break;
		case DS_CWDSException:
			replyError = DSREPLY_CWDSException;
			break;
		case DS_InvalidProcessID:
			replyError = DSREPLY_InvalidProcessID;
			break;
		case DS_InvalidThreadID:
			replyError = DSREPLY_InvalidThreadID;
			break;
		case DS_OSError:
			replyError = DSREPLY_OSError;
			break;
		default:
			replyError = DSREPLY_CWDSError;
			break;
		}
		return TRKStandardACK(b, DSMSG_ReplyACK, replyError);
	}
	return TRKSendACK(b);
}

DSError TRKDoFlushCache(MessageBuffer* b)
{
	u32 start;
	u32 end;
	u8 cmd;
	u8 options;
	DSError err;
	int replyError;

	if (b->length != 10) {
		return TRKStandardACK(b, DSMSG_ReplyACK, DSREPLY_PacketSizeError);
	}
	TRKSetBufferPosition(b, 0);
	err = TRKReadBuffer1_ui8(b, &cmd);
	if (err == DS_NoError) {
		err = TRKReadBuffer1_ui8(b, &options);
	}
	if (err == DS_NoError) {
		err = TRKReadBuffer1_ui32(b, &start);
	}
	if (err == DS_NoError) {
		err = TRKReadBuffer1_ui32(b, &end);
	}
	if (start > end) {
		return TRKStandardACK(b, DSMSG_ReplyACK, DSREPLY_InvalidMemoryRange);
	}
	if (err == DS_NoError) {
		err = TRKTargetFlushCache(options, start, end);
	}
	if (err == DS_NoError) {
		TRKResetBuffer(b, TRUE);
		TRKAppendBuffer1_ui8(b, DSMSG_ReplyACK);
		TRKAppendBuffer1_ui8(b, DSREPLY_NoError);
	}
	if (err != DS_NoError) {
		switch (err) {
		case DS_UnsupportedError:
			replyError = DSREPLY_UnsupportedOptionError;
			break;
		default:
			replyError = DSREPLY_CWDSError;
			break;
		}
		return TRKStandardACK(b, DSMSG_ReplyACK, replyError);
	}
	return TRKSendACK(b);
}

DSError TRKDoContinue(MessageBuffer* b)
{
	DSError err;

	if (!TRKTargetStopped()) {
		return TRKStandardACK(b, DSMSG_ReplyACK, DSREPLY_NotStopped);
	}
	err = TRKStandardACK(b, DSMSG_ReplyACK, DSREPLY_NoError);
	if (err == DS_NoError) {
		err = TRKTargetContinue();
	}
	return err;
}

DSError TRKDoStep(MessageBuffer* b)
{
	DSError err;
	u8 cmd;
	u8 options;
	u8 count;
	u32 rangeStart;
	u32 rangeEnd;

	if (b->length < 3) {
		return TRKStandardACK(b, DSMSG_ReplyACK, DSREPLY_PacketSizeError);
	}
	TRKSetBufferPosition(b, 0);
	err = TRKReadBuffer1_ui8(b, &cmd);
	if (err == DS_NoError) {
		err = TRKReadBuffer1_ui8(b, &options);
	}
	switch (options) {
	case 0:
	case 0x10:
		if (err == DS_NoError) {
			err = TRKReadBuffer1_ui8(b, &count);
		}
		if (count >= 1) {
			break;
		}
		return TRKStandardACK(b, DSMSG_ReplyACK, DSREPLY_ParameterError);
	case 1:
	case 0x11:
		if (b->length != 10) {
			return TRKStandardACK(b, DSMSG_ReplyACK, DSREPLY_PacketSizeError);
		}
		if (err == DS_NoError) {
			err = TRKReadBuffer1_ui32(b, &rangeStart);
		}
		if (err == DS_NoError) {
			err = TRKReadBuffer1_ui32(b, &rangeEnd);
		}
		{
			u32 pc = TRKTargetGetPC();
			if (pc >= rangeStart && pc <= rangeEnd) {
				break;
			}
		}
		return TRKStandardACK(b, DSMSG_ReplyACK, DSREPLY_ParameterError);
	default:
		return TRKStandardACK(b, DSMSG_ReplyACK, DSREPLY_UnsupportedOptionError);
	}
	if (!TRKTargetStopped()) {
		return TRKStandardACK(b, DSMSG_ReplyACK, DSREPLY_NotStopped);
	}
	err = TRKStandardACK(b, DSMSG_ReplyACK, DSREPLY_NoError);
	if (err == DS_NoError) {
		switch (options) {
		case 0:
		case 0x10:
			err = TRKTargetSingleStep(count, options == 0x10);
			break;
		case 1:
		case 0x11:
			err = TRKTargetStepOutOfRange(rangeStart, rangeEnd, options == 0x11);
			break;
		}
	}
	return err;
}

DSError TRKDoStop(MessageBuffer* b)
{
	u8 reply;

	switch (TRKTargetStop()) {
	case DS_NoError:
		reply = DSREPLY_NoError;
		break;
	case DS_InvalidProcessID:
		reply = DSREPLY_InvalidProcessID;
		break;
	case DS_InvalidThreadID:
		reply = DSREPLY_InvalidThreadID;
		break;
	case DS_OSError:
		reply = DSREPLY_OSError;
		break;
	default:
		reply = DSREPLY_Error;
		break;
	}
	return TRKStandardACK(b, DSMSG_ReplyACK, reply);
}

DSError TRKDoSetOption(MessageBuffer* b)
{
	u8 cmd    = 0;
	u8 option = 0;
	u8 value  = 0;
	DSError err;

	TRKSetBufferPosition(b, 0);
	err = TRKReadBuffer1_ui8(b, &cmd);
	if (err == DS_NoError) {
		err = TRKReadBuffer1_ui8(b, &option);
	}
	if (err == DS_NoError) {
		err = TRKReadBuffer1_ui8(b, &value);
	}
	if (err != DS_NoError) {
		TRKStandardACK(b, DSMSG_ReplyACK, DSREPLY_Error);
	} else if (option == 1) {
		SetUseSerialIO(value);
	}
	return TRKStandardACK(b, DSMSG_ReplyACK, DSREPLY_NoError);
}
