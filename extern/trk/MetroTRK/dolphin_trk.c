#include "PowerPC_EABI_Support/MetroTRK/trk.h"
#include "Dolphin/ar.h"

extern u8 _db_stack_addr[];
#define EXCEPTIONMASK_ADDR 0x80000044

extern void OSResetSystem(BOOL reset, u32 resetCode, BOOL forceMenu);

u32 lc_base;

/**
 * @note Address: 0x800C03EC
 * @note Size: 0x20
 */
void EnableMetroTRKInterrupts(void)
{
	EnableEXI2Interrupts();
}

/**
 * @note Address: 0x800C0394
 * @note Size: 0x58
 */
u32 TRKTargetTranslate(u32 val)
{
	if (val >= lc_base && val < lc_base + 0x4000) {
		if (((u32*)(&gTRKCPUState.Extended1))[36] & 3)
			return val;
	}

	return (val & 0x3FFFFFFF) | 0x80000000;
}

/**
 * @note Address: 0x800C021C
 * @note Size: 0x4C
 */
DSError TRKInitializeTarget()
{
	gTRKState.isStopped = TRUE;
	gTRKState.msr       = __TRK_get_MSR();
	lc_base             = 0xE0000000;
	return DS_NoError;
}

/**
 * @note Address: 0x800BFDD0
 * @note Size: 0x98
 */
ASM void InitMetroTRK(void)
{
#ifdef __MWERKS__ // clang-format off
	nofralloc
	addi r1, r1, -4
	stw r3, 0(r1)
	lis r3, gTRKCPUState@h
	ori r3, r3, gTRKCPUState@l
	stmw r0, ProcessorState_PPC.Default.GPR(r3) //Save the gprs
	lwz r4, 0(r1)
	addi r1, r1, 4
	stw r1, ProcessorState_PPC.Default.GPR[1](r3)
	stw r4, ProcessorState_PPC.Default.GPR[3](r3)
	mflr r4
	stw r4, ProcessorState_PPC.Default.LR(r3)
	stw r4, ProcessorState_PPC.Default.PC(r3)
	mfcr r4
	stw r4, ProcessorState_PPC.Default.CR(r3)
	//???
	mfmsr r4
	ori r3, r4, (1 << (31 - 16))
	xori r3, r3, (1 << (31 - 16))
	mtmsr r3
	mtsrr1 r4 //Copy msr to srr1
	//Save misc registers to gTRKCPUState
	bl TRKSaveExtended1Block
	lis r3, gTRKCPUState@h
	ori r3, r3, gTRKCPUState@l
	lmw r0, ProcessorState_PPC.Default.GPR(r3) //Restore the gprs
	//Reset IABR and DABR
	li r0, 0
	mtspr  0x3f2, r0
	mtspr  0x3f5, r0
	//Restore stack pointer
	lis r1, _db_stack_addr@h
	ori r1, r1, _db_stack_addr@l
	mr r3, r5
	bl InitMetroTRKCommTable //Initialize comm table
	/*
	If InitMetroTRKCommTable returned 1 (failure), an invalid hardware
	id or the id for GDEV was somehow passed. Since only BBA or NDEV
	are supported, we return early. Otherwise, we proceed with
	starting up TRK.
	*/
	cmpwi r3, 1
	bne initCommTableSuccess
	/*
	BUG: The code probably orginally reloaded gTRKCPUState here, but
	as is it will read the returned value of InitMetroTRKCommTable
	as a TRKCPUState struct pointer, causing the CPU to return to
	a garbage code address.
	*/
	lwz r4, ProcessorState_PPC.Default.LR(r3)
	mtlr r4
	lmw r0, ProcessorState_PPC.Default.GPR(r3) //Restore the gprs
	blr
initCommTableSuccess:
	b TRK_main //Jump to TRK_main
#endif // clang-format on
}
