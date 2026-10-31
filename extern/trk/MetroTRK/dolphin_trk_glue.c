#include "PowerPC_EABI_Support/MetroTRK/trkenum.h"
#include "Dolphin/os.h"
#include "Dolphin/AmcExi2Stubs.h"
#include "Dolphin/db.h"

// This revision of the glue predates the udp/ddh/gdev driver tables: the table has seven entries and is filled
// with either the Dolphin debugger driver (DB*) or the AMC EXI2 stubs.
// The DB* and EXI2_* drivers have different return types, so the table uses its own signatures.
typedef void (*DBCommInitFunc)(vu8**, AmcEXICallback);
typedef void (*DBCommInitInterruptsFunc)(void);
typedef int (*DBCommPeekFunc)(void);
typedef int (*DBCommReadFunc)(void*, u32);
typedef int (*DBCommWriteFunc)(const void*, u32);
typedef void (*DBCommOpenFunc)(void);
typedef void (*DBCommCloseFunc)(void);

typedef struct DBCommTable {
	DBCommInitFunc initialize_func;
	DBCommInitInterruptsFunc init_interrupts_func;
	DBCommPeekFunc peek_func;
	DBCommReadFunc read_func;
	DBCommWriteFunc write_func;
	DBCommOpenFunc open_func;
	DBCommCloseFunc close_func;
} DBCommTable;

DBCommTable gDBCommTable = { 0, 0, 0, 0, 0, 0, 0 };

#define BUFF_LEN 0x110a

static u8 write_buf[0x110c];
static u8 read_buf[0x110c];
static int unk_c;
static int read_cnt;
static int read_pos;
static int write_pos;

extern void TRKInterruptHandler(void);
extern int Hu_IsStub(void);
extern void TRKLoadContext(OSContext* ctx, u32 r4);

void TRKEXICallBack(s16 r3, OSContext* ctx)
{
	OSEnableScheduler();
	TRKLoadContext(ctx, 0x500);
}

int InitMetroTRKCommTable(int hwId)
{
	int result;

	if (hwId == HARDWARE_GDEV) {
		OSReport("MetroTRK : Set to GDEV hardware\n");
		result = Hu_IsStub();
		gDBCommTable.initialize_func      = DBInitComm;
		gDBCommTable.init_interrupts_func = DBInitInterrupts;
		gDBCommTable.peek_func            = (DBCommPeekFunc)DBQueryData;
		gDBCommTable.read_func            = (DBCommReadFunc)DBRead;
		gDBCommTable.write_func           = (DBCommWriteFunc)DBWrite;
		gDBCommTable.open_func            = DBOpen;
		gDBCommTable.close_func           = DBClose;
	} else {
		OSReport("MetroTRK : Set to AMC DDH hardware\n");
		result = AMC_IsStub();
		gDBCommTable.initialize_func      = EXI2_Init;
		gDBCommTable.init_interrupts_func = EXI2_EnableInterrupts;
		gDBCommTable.peek_func            = EXI2_Poll;
		gDBCommTable.read_func            = (DBCommReadFunc)EXI2_ReadN;
		gDBCommTable.write_func           = (DBCommWriteFunc)EXI2_WriteN;
		gDBCommTable.open_func            = EXI2_Reserve;
		gDBCommTable.close_func           = EXI2_Unreserve;
	}

	return result;
}

DSError TRKInitializeIntDrivenUART(u32 a, u32 b, u32 c, void* inputPendingPtr)
{
	gDBCommTable.initialize_func(inputPendingPtr, TRKEXICallBack);
	return DS_NoError;
}

void EnableEXI2Interrupts(void)
{
	gDBCommTable.init_interrupts_func();
}

int WriteUARTFlush(void)
{
	int err;
	int done = 0;

	while (write_pos < 0x800) {
		write_buf[write_pos] = 0;
		write_pos++;
	}

	if (write_pos != 0) {
		err       = gDBCommTable.write_func(write_buf, write_pos);
		done      = (-err | err) >> 31;
		write_pos = 0;
	}

	return done;
}

int WriteUART1(u8 data)
{
	write_buf[write_pos++] = data;
	return 0;
}

int TRKReadUARTPoll(u8* data)
{
	int err = UART_NoData;
	int e;

	if (read_pos >= read_cnt) {
		read_pos = 0;
		e        = gDBCommTable.peek_func();
		read_cnt = e;

		if (e > 0) {
			if (e > BUFF_LEN) {
				read_cnt = BUFF_LEN;
			}

			e   = gDBCommTable.read_func(read_buf, read_cnt);
			e   = (-e | e) >> 31;
			err = e;

			if (e) {
				read_cnt = 0;
			}
		}
	}

	if (read_pos < read_cnt) {
		err   = 0;
		*data = read_buf[read_pos++];
	}

	return err;
}

void ReserveEXI2Port(void)
{
	gDBCommTable.open_func();
}

void UnreserveEXI2Port(void)
{
	gDBCommTable.close_func();
}

void TRK_board_display(char* str)
{
	OSReport(str);
}

void TRKUARTInterruptHandler(void)
{
}

asm void TRKLoadContext(OSContext* ctx, u32 r4)
{
#ifdef __MWERKS__ // clang-format off
	nofralloc
	lwz r0, OSContext.gpr[0](r3)
	lwz r1, OSContext.gpr[1](r3)
	lwz r2, OSContext.gpr[2](r3)
	lhz r5, OSContext.state(r3)
	rlwinm. r6, r5, 0, 0x1e, 0x1e
	beq L_802CC24C
	rlwinm r5, r5, 0, 0x1f, 0x1d
	sth r5, OSContext.state(r3)
	lmw r5, OSContext.gpr[5](r3)
	b L_802CC250
L_802CC24C:
	lmw r13, OSContext.gpr[13](r3)
L_802CC250:
	mr r31, r3
	mr r3, r4
	lwz r4, OSContext.cr(r31)
	mtcrf 0xff, r4
	lwz r4, OSContext.lr(r31)
	mtlr r4
	lwz r4, OSContext.ctr(r31)
	mtctr r4
	lwz r4, OSContext.xer(r31)
	mtxer r4
	mfmsr r4
	rlwinm r4, r4, 0, 0x11, 0xf //Turn off external exceptions
	rlwinm r4, r4, 0, 0x1f, 0x1d //Turn off recoverable exception flag
	mtmsr r4
	mtsprg 1, r2
	lwz r4, OSContext.gpr[3](r31)
	mtsprg 2, r4
	lwz r4, OSContext.gpr[4](r31)
	mtsprg 3, r4
	lwz r2, OSContext.srr0(r31)
	lwz r4, OSContext.srr1(r31)
	lwz r31, OSContext.gpr[31](r31)
	b TRKInterruptHandler
#endif // clang-format on
}
