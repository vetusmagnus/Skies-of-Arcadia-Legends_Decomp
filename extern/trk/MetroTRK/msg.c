#include "PowerPC_EABI_Support/MetroTRK/trk.h"



DSError TRKMessageSend(MessageBuffer* msg)
{
	u8 sum = 0;
	u32 chk;
	u32 i;
	int j;
	int err;

	for (j = 0; j < msg->length; j++) {
		sum = (u8)(sum + msg->data[j]);
	}
	chk = (u8)(sum ^ 0xff);

	err = WriteUART1(0x7e);
	if (err == 0) {
		for (i = 0; i < msg->length; i++) {
			u8 c = msg->data[i];
			if (c == 0x7e || c == 0x7d) {
				err = WriteUART1(0x7d);
				c ^= 0x20;
				if (err != 0) {
					break;
				}
			}
			err = WriteUART1(c);
			if (err != 0) {
				break;
			}
		}
	}
	if (err == 0) {
		/* FCS bytes (8-bit FCS: one byte), escaped like the data */
		int k;
		for (k = 0; k < sizeof(sum); k++) {
			u8 c = chk;
			if ((u8)c == 0x7e || (u8)c == 0x7d) {
				err = WriteUART1(0x7d);
				c ^= 0x20;
				if (err != 0) {
					break;
				}
			}
			err = WriteUART1(c);
			if (err != 0) {
				break;
			}
		}
	}
	if (err == 0) {
		err = WriteUART1(0x7e);
	}
	if (err == 0) {
		err = WriteUARTFlush();
	}
	return err;
}
