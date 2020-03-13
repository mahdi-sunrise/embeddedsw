/******************************************************************************
 *
 * Copyright (C) 2020 Xilinx, Inc.  All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 *
 *
 ******************************************************************************/

/*****************************************************************************/
/**
 *
 * @file xqspipsu_control.h
 * @addtogroup qspipsu_v1_11
 * @{
 * @details
 *
 * This is the header file for the implementation of QSPIPSU driver.
 * Generic QSPI interface allows for communication to any QSPI slave device.
 * GQSPI contains a GENFIFO into which the bus transfers required are to be
 * pushed with appropriate configuration. The controller provides TX and RX
 * FIFO's and a DMA to be used for RX transfers. The controller executes each
 * GENFIFO entry noting the configuration and places data on the bus as required
 *
 *
 * <pre>
 * MODIFICATION HISTORY:
 *
 * Ver   Who Date     Changes
 * ----- --- -------- -----------------------------------------------.
 * 1.11   akm  03/09/20 First release
 *
 * </pre>
 *
 ******************************************************************************/

#ifndef XQSPIPSU_CONTROL_H_		/* prevent circular inclusions */
#define XQSPIPSU_CONTROL_H_		/* by using protection macros */

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/

#include "xqspipsu.h"

/**************************** Type Definitions *******************************/

/***************** Macros (Inline Functions) Definitions *********************/

#if defined (ARMR5) || (__aarch64__)
#define TAPDLY_BYPASS_VALVE_40MHZ 0x01U
#define TAPDLY_BYPASS_VALVE_100MHZ 0x01U
#define USE_DLY_LPBK  0x01U
#define USE_DATA_DLY_ADJ 0x01U
#define DATA_DLY_ADJ_DLY 0X02U
#define LPBK_DLY_ADJ_DLY0 0X02U
#define LPBK_DLY_ADJ_DLY1 0X02U
#endif

/************************** Function Prototypes ******************************/
void XQspiPsu_GenFifoEntryData(XQspiPsu *InstancePtr, XQspiPsu_Msg *Msg);
u32 XQspiPsu_SetIOMode(XQspiPsu *InstancePtr, XQspiPsu_Msg *Msg);
void XQspiPsu_IORead(XQspiPsu *InstancePtr, XQspiPsu_Msg *Msg,
		u32 StatusReg);
void XQspiPsu_PollDataConfig(XQspiPsu *InstancePtr, XQspiPsu_Msg *FlashMsg);
void XQspiPsu_TXSetup(XQspiPsu *InstancePtr, XQspiPsu_Msg *Msg);
void XQspiPsu_SetupRxDma(const XQspiPsu *InstancePtr,
					XQspiPsu_Msg *Msg);
void XQspiPsu_Setup64BRxDma(const XQspiPsu *InstancePtr,
					XQspiPsu_Msg *Msg);
void XQspiPsu_RXSetup(XQspiPsu *InstancePtr, XQspiPsu_Msg *Msg);
void XQspiPsu_TXRXSetup(XQspiPsu *InstancePtr, XQspiPsu_Msg *Msg,
					u32 *GenFifoEntry);
void XQspiPsu_GenFifoEntryDataLen(XQspiPsu *InstancePtr, XQspiPsu_Msg *Msg,
		u32 *GenFifoEntry);
u32 XQspiPsu_CreatePollDataConfig(const XQspiPsu *InstancePtr,
		const XQspiPsu_Msg *FlashMsg);
u32 XQspiPsu_SelectSpiMode(u8 SpiMode);
void XQspiPsu_SetDefaultConfig(XQspiPsu *InstancePtr);
void StubStatusHandler(const void *CallBackRef, u32 StatusEvent,
				u32 ByteCount);
void XQspiPsu_FillTxFifo(XQspiPsu *InstancePtr, XQspiPsu_Msg *Msg, u32 Size);
void XQspiPsu_ReadRxFifo(XQspiPsu *InstancePtr,	XQspiPsu_Msg *Msg, s32 Size);

#if defined (ARMR5) || (__aarch64__)
s32 XQspipsu_Set_TapDelay(const XQspiPsu *InstancePtr, u32 TapdelayBypass,
						u32 LPBKDelay, u32 Datadelay);
s32 XQspipsu_Calculate_Tapdelay(const XQspiPsu *InstancePtr, u8 Prescaler);
#endif

#ifdef __cplusplus
}
#endif


#endif /* XQSPIPSU_CONTROL_H_ */
/** @} */
