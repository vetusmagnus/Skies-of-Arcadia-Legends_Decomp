#include "PowerPC_EABI_Support/MetroTRK/trk.h"

extern DSError TRKReadBuffer1_ui8(MessageBuffer* buffer, u8* data);
extern DSError TRKReadBuffer1_ui16(MessageBuffer* buffer, u16* data);
extern DSError TRKReadBuffer1_ui32(MessageBuffer* buffer, u32* data);
extern DSError TRKReadBuffer_ui8(MessageBuffer* buffer, u8* data, int count);
extern DSError TRKAppendBuffer1_ui16(MessageBuffer* buffer, const u16 data);
extern DSError TRKAppendBuffer1_ui32(MessageBuffer* buffer, const u32 data);
extern DSError TRKAppendBuffer_ui8(MessageBuffer* buffer, const u8* data, int count);
extern MessageBufferID TRKTestForPacket(void);
extern void TRKProcessInput(int bufferIdx);
extern size_t strlen(const char*);

DSError TRKSuppAccessFile(u32 file_handle, u8* data, size_t* count, u8* io_result, BOOL need_reply, BOOL read)
{
	DSError error;
	MessageBuffer* replyBuffer;
	int replyBufferId;
	int bufferId;
	MessageBuffer* buffer;
	u32 length;
	u32 i;
	u8 replyIOResult;
	u16 replyLength;
	BOOL exit;

	if (data == NULL || *count == 0) {
		return DS_ParameterError;
	}

	exit       = FALSE;
	*io_result = 0;
	i          = 0;
	error      = DS_NoError;
	while (!exit && i < *count && error == DS_NoError && *io_result == 0) {
		if (*count - i <= 0x800) {
			length = *count - i;
		} else {
			length = 0x800;
		}

		error = TRKGetFreeBuffer(&bufferId, &buffer);
		if (error == DS_NoError) {
			error = TRKAppendBuffer1_ui8(buffer, read ? DSMSG_ReadFile : DSMSG_WriteFile);
		}
		if (error == DS_NoError) {
			error = TRKAppendBuffer1_ui32(buffer, file_handle);
		}
		if (error == DS_NoError) {
			error = TRKAppendBuffer1_ui16(buffer, length);
		}
		if (!read && error == DS_NoError) {
			error = TRKAppendBuffer_ui8(buffer, data + i, length);
		}

		if (error == DS_NoError) {
			if (need_reply) {
				replyLength   = 0;
				replyIOResult = 0;
				{
					BOOL b = read && file_handle == 0;
					error  = TRKRequestSend(buffer, &replyBufferId, read ? 5 : 5, 3, !b);
				}
				if (error == DS_NoError) {
					replyBuffer = TRKGetBuffer(replyBufferId);
					TRKSetBufferPosition(replyBuffer, 2);
				}
				if (error == DS_NoError) {
					error = TRKReadBuffer1_ui8(replyBuffer, &replyIOResult);
				}
				if (error == DS_NoError) {
					error = TRKReadBuffer1_ui16(replyBuffer, &replyLength);
				}
				if (read && error == DS_NoError) {
					if (replyBuffer->length != replyLength + 5) {
						replyLength = replyBuffer->length - 5;
						if (replyIOResult == 0) {
							replyIOResult = 1;
						}
					}
					if (replyLength <= length) {
						error = TRKReadBuffer_ui8(replyBuffer, data + i, replyLength);
					}
				}

				if (replyLength != length) {
					if (!read || replyLength >= length) {
						if (replyIOResult == 0) {
							replyIOResult = 1;
						}
					}
					length = replyLength;
					exit   = TRUE;
				}

				*io_result = replyIOResult;
				TRKReleaseBuffer(replyBufferId);
			} else {
				error = TRKMessageSend(buffer);
			}
		}

		TRKReleaseBuffer(bufferId);
		i += length;
	}

	*count = i;
	return error;
}

DSError TRKRequestSend(MessageBuffer* msgBuf, int* bufferId, u32 p1, u32 p2, int p3)
{
	int error = DS_NoError;
	MessageBuffer* buffer;
	u32 counter;
	int count;
	u8 msgCmd;
	u8 msgReplyError;
	BOOL badReply = TRUE;

	*bufferId = -1;

	for (count = p2 + 1; count != 0 && *bufferId == -1 && error == DS_NoError; count--) {
		error = TRKMessageSend(msgBuf);
		if (error == DS_NoError) {

			if (p3) {
				counter = 0;
			}

			while (TRUE) {
				do {
					*bufferId = TRKTestForPacket();
					if (*bufferId != -1)
						break;
				} while (!p3 || ++counter < 79999980);

				if (*bufferId == -1)
					break;

				badReply = 0;

				buffer = TRKGetBuffer(*bufferId);
				TRKSetBufferPosition(buffer, 0);
				error = TRKReadBuffer1_ui8(buffer, &msgCmd);
				if (error != DS_NoError)
					break;

				if (msgCmd >= DSMSG_ReplyACK)
					break;

				TRKProcessInput(*bufferId);
				*bufferId = -1;
			}

			if (*bufferId != -1) {
				if (buffer->length < p1) {
					badReply = TRUE;
				}
				if (error == DS_NoError && !badReply) {
					error = TRKReadBuffer1_ui8(buffer, &msgReplyError);
				}
				if (error == DS_NoError && !badReply) {
					if (msgCmd != DSMSG_ReplyACK || msgReplyError != DSREPLY_NoError) {
						badReply = TRUE;
					}
				}
				if (error != DS_NoError || badReply) {
					TRKReleaseBuffer(*bufferId);
					*bufferId = -1;
				}
			}
		}
	}

	if (*bufferId == -1) {
		error = DS_Error800;
	}

	return error;
}

DSError HandleOpenFileSupportRequest(const char* path, u8 replyError, u32* param_3, u8* ioResult)
{
	DSError error;
	int bufferId2;
	int bufferId1;
	MessageBuffer* tempBuffer;
	MessageBuffer* buffer;

	*param_3 = 0;
	error    = TRKGetFreeBuffer(&bufferId1, &buffer);
	if (error == DS_NoError) {
		error = TRKAppendBuffer1_ui8(buffer, DSMSG_OpenFile);
	}
	if (error == DS_NoError) {
		error = TRKAppendBuffer1_ui8(buffer, replyError);
	}
	if (error == DS_NoError) {
		error = TRKAppendBuffer1_ui16(buffer, strlen(path) + 1);
	}
	if (error == DS_NoError) {
		error = TRKAppendBuffer_ui8(buffer, (u8*)path, strlen(path) + 1);
	}

	if (error == DS_NoError) {
		*ioResult = 0;
		error     = TRKRequestSend(buffer, &bufferId2, 7, 3, 0);

		if (error == DS_NoError) {
			tempBuffer = TRKGetBuffer(bufferId2);
			TRKSetBufferPosition(tempBuffer, 2);
		}
		if (error == DS_NoError) {
			error = TRKReadBuffer1_ui8(tempBuffer, ioResult);
		}
		if (error == DS_NoError) {
			error = TRKReadBuffer1_ui32(tempBuffer, param_3);
		}
		TRKReleaseBuffer(bufferId2);
	}
	TRKReleaseBuffer(bufferId1);
	return error;
}

DSError HandleCloseFileSupportRequest(int replyError, u8* ioResult)
{
	DSError error;
	int replyBufferId;
	int bufferId;
	MessageBuffer* buffer1;
	MessageBuffer* buffer2;

	error = TRKGetFreeBuffer(&bufferId, &buffer1);
	if (error == DS_NoError) {
		error = TRKAppendBuffer1_ui8(buffer1, DSMSG_CloseFile);
	}
	if (error == DS_NoError) {
		error = TRKAppendBuffer1_ui32(buffer1, replyError);
	}

	if (error == DS_NoError) {
		*ioResult = 0;
		error     = TRKRequestSend(buffer1, &replyBufferId, 3, 3, 0);

		if (error == DS_NoError) {
			buffer2 = TRKGetBuffer(replyBufferId);
			TRKSetBufferPosition(buffer2, 2);
		}
		if (error == DS_NoError) {
			error = TRKReadBuffer1_ui8(buffer2, ioResult);
		}
		TRKReleaseBuffer(replyBufferId);
	}

	TRKReleaseBuffer(bufferId);
	return error;
}

DSError HandlePositionFileSupportRequest(int replyErr, u32* param_2, u8 param_3, u8* ioResult)
{
	DSError error;
	int bufferId2;
	int bufferId1;
	MessageBuffer* buffer1;
	MessageBuffer* buffer2;

	error = TRKGetFreeBuffer(&bufferId1, &buffer1);
	if (error == DS_NoError) {
		error = TRKAppendBuffer1_ui8(buffer1, DSMSG_PositionFile);
	}
	if (error == DS_NoError) {
		error = TRKAppendBuffer1_ui32(buffer1, replyErr);
	}
	if (error == DS_NoError) {
		error = TRKAppendBuffer1_ui32(buffer1, *param_2);
	}
	if (error == DS_NoError) {
		error = TRKAppendBuffer1_ui8(buffer1, param_3);
	}

	if (error == DS_NoError) {
		*ioResult = 0;
		error     = TRKRequestSend(buffer1, &bufferId2, 3, 3, 0);

		if (error == DS_NoError) {
			buffer2 = TRKGetBuffer(bufferId2);
			TRKSetBufferPosition(buffer2, 2);
		}
		if (error == DS_NoError) {
			error = TRKReadBuffer1_ui8(buffer2, ioResult);
		}
		if (error == DS_NoError) {
			error = TRKReadBuffer1_ui32(buffer2, param_2);
		} else {
			*param_2 = -1;
		}
		TRKReleaseBuffer(bufferId2);
	}

	TRKReleaseBuffer(bufferId1);
	return error;
}
