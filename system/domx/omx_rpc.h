/*=========================================================================
 *             Texas Instruments OMAP(TM) Platform Software
 *  (c) Copyright Texas Instruments, Incorporated.  All Rights Reserved.
 *
 *  Use of this software is controlled by the terms and conditions found
 *  in the license agreement under which this software has been supplied.
 * ==========================================================================*/

/**
 *  @file  omx_rpc.h
 *  @brief This file contains methods that provides the functionality for
 *         the OpenMAX1.1 DOMX Framework RPC.
 *
 *  @path \WTSD_DucatiMMSW\framework\domx\omx_rpc\ 
 *
 *  @rev 1.0
 */

/*==============================================================
 *! Revision History
 *! ============================
 *! 19-August-2009 B Ravi Kiran ravi.kiran@ti.com: Initial Version
 *================================================================*/
 
 
#ifndef OMXRPC_H
#define OMXRPC_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/******************************************************************
 *   INCLUDE FILES
 ******************************************************************/
#include <stdio.h>
#ifndef LINUX_TRACE
#  include <timm_osal_error.h>
#  include <timm_osal_osal.h>
#  include <timm_osal_trace.h>
#  define DOMX_DEBUG(ARGS,...)  TIMM_OSAL_TraceExt(TIMM_OSAL_TRACEGRP_DOMX,ARGS,##__VA_ARGS__)
#else
#  define DOMX_DEBUG(ARGS,...) printf(ARGS,##__VA_ARGS__)
#endif
#include <OMX_Types.h>

//#define BUF_HEAP
//#define BUF_HEAP_UB

#define TILER_BUFF

extern OMX_U8 CHIRON_IPC_FLAG;
 
 /*******************************************************************************
* Enumerated Types
*******************************************************************************/
/** 
  *  @brief           Status of the RPC Stub, Util calls. 
  */

typedef enum RPC_OMX_ERRORTYPE{
	RPC_OMX_ErrorNone=0,

	/* OMX Error Mapped */
	RPC_OMX_ErrorInsufficientResources=0x81000,
	RPC_OMX_ErrorUndefined = 0x81001,
	RPC_OMX_ErrorBadParameter=0x81005,
	RPC_OMX_ErrorHardware = 0x81009,
	RPC_OMX_ErrorUnsupportedIndex=0x8101A,
	RPC_OMX_ErrorTimeout = 0x81011,
	/* END OF OMX Error */

	/* RPC Specific Error - to depricate */
	RPC_OMX_ErrorUnknown=0x70000,
	RPC_OMX_ErrorProccesorInit=0x70001,
	RPC_OMX_InvalidRPCCmd = 0x70002,
	RPC_OMX_ErrorHLOS=0x70003,
	RPC_OMX_ErrorInvalidMsg = 0x70004,

	/* RCM Specific */
	RPC_OMX_RCM_ErrorExecFail = 0x70005,
	RPC_OMX_RCM_ErrorExecDpcFail = 0x70006,
	RPC_OMX_RCM_ErrorTimeout = 0x70007,
	RPC_OMX_RCM_ServerFail = 0x70008,
	RPC_OMX_RCM_ClientFail = 0x70009,
	

	
}RPC_OMX_ERRORTYPE;

 
 /****************************************************************
 * PUBLIC DECLARATIONS Defined here, used elsewhere

 ****************************************************************/
 
 

/* ===========================================================================*/
/**
 * @name RPC_InstanceInit() 
 * @brief RPC instance init is used to bring up a instance of a client - this should be ideally invokable from any core
 *        For this the parameters it would require are
 *        Heap ID - this needs to be configured at startup (CFG) and indicates the heaps available for a RCM client to pick from 
 *        Server - this contains the RCM server name that the client should connect to 
 *        rcmHndl - Contains the Client once the call is completed
 *        rcmParams - 
 *        These values can be picked up from the RPC handle. But an unique identifier is required -Server
 * @param cComponentName  : Pointer to the Components Name that is requires the RCM client to be initialized
 * @return RPC_OMX_ErrorNone = Successful 
 * @sa TBD
 *
 */
/* ===========================================================================*/
RPC_OMX_ERRORTYPE RPC_InstanceInit(OMX_STRING ServerName);

/* ===========================================================================*/
/**
 * @name RPC_ModInit() 
 * @brief This function Creates the Default RCM servers on current processor       
 * @param Void 
 * @return RPC_OMX_ErrorNone = Successful 
 * @sa TBD
 *
 */
 /* ===========================================================================*/
RPC_OMX_ERRORTYPE RPC_ModInit(void);


	
/* ===========================================================================*/
/**
 * @name RPC_InstanceDeInit() 
 * @brief This function Removes or deinitializes RCM client instances. This also manages the number of active users    
 *        of a given RCM client
 * @param cComponentName  : Pointer to the Components Name that is active user of the RCM client to be deinitialized
 * @return RPC_OMX_ErrorNone = Successful 
 * @sa TBD
 *
 */
/* ===========================================================================*/
RPC_OMX_ERRORTYPE RPC_InstanceDeInit(void);




/* ===========================================================================*/
/**
 * @name RPC_ModDeInit() 
 * @brief This function Removes or deinitializes RCM client instances. This also manages the number of active users    
 *        of a given RCM client
 * @param cComponentName  : Pointer to the Components Name that is active user of the RCM client to be deinitialized
 * @return RPC_OMX_ErrorNone = Successful 
 * @sa TBD
 *
 */
 /* ===========================================================================*/
RPC_OMX_ERRORTYPE RPC_ModDeInit(void);


#endif 

