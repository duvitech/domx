/* =============================================================================
 *             Texas Instruments OMAP(TM) Platform Software
 *  (c) Copyright Texas Instruments, Incorporated.  All Rights Reserved.
 *
 *  Use of this software is controlled by the terms and conditions found
 *  in the license agreement under which this software has been supplied.
 * =========================================================================== */
/**
 *
 * This File contains the test entry function for OMX Jpeg Decoder.
 *
 * @path
 *
 * @rev  0.1
 */
/* ----------------------------------------------------------------------------
 *!
 *! Revision History
 *! =============================================================
 *! Initial Version
 * ============================================================== */

#include <timm_osal_types.h>
#include <timm_osal_error.h>
#include <timm_osal_memory.h>
#include <timm_osal_semaphores.h>
#include <timm_osal_interfaces.h>
#include <timm_osal_trace.h>

/*PAK
#include <WTSD_DucatiMMSW/drivers/csl/iss/iss_common/iss_common.h>
#include <WTSD_DucatiMMSW/drivers/csl/iss/simcop/common/simcop_irq.h>
#include <WTSD_DucatiMMSW/framework/resource_manager/rm.h>*/


#include <stdio.h>
#include "omx_jpegd_test.h"
#include <omx_types.h>
#include <mmplatform.h>

#define OMX_PORT_DUCATI


#define OMX_LINUX_TILERTEST

#ifdef OMX_LINUX_TILERTEST
/*Tiler APIs*/
#include <memmgr/memmgr.h>
#include <mmplatform.h>

#endif

extern OMX_TEST_CASE_ENTRY OMX_JPEGDTestCaseTable[];
OMX_U32 OMX_Jpegd_MemStatPrint(void);


void main()
{
    OMX_TEST_CASE_ENTRY *testcaseEntry = NULL;
    OMX_U32 test_case, test_case_start, test_case_end, TraceGrp;
    OMX_U32 mem_size_start = 0, mem_size_end = 0;



       printf("\n In JPEG DECODER MAIN and Calling platform init\n");
        mmplatform_init(2);
        printf("\n Wait until RCM Server is created on other side. Press any key after that\n");
        getchar();


	TraceGrp = TIMM_OSAL_TRACEGRP_SYSTEM; //TIMM_OSAL_GetTraceGrp();
//	TIMM_OSAL_SetTraceGrp(TraceGrp|TIMM_OSAL_TRACEGRP_OMXIMGDEC);/*Enable OMX ImageDecoder traces*/
	TIMM_OSAL_TraceExt(TIMM_OSAL_TRACEGRP_OMXIMGDEC,"tracegroup=%x",TraceGrp);


	TIMM_OSAL_InfoExt(TIMM_OSAL_TRACEGRP_OMXIMGDEC," Select test case start ID (1-51):");
	fflush(stdout);
	scanf("%d", &test_case_start);


    if(test_case_start < 1 || test_case_start > 51)
    {
        TIMM_OSAL_ErrorExt(TIMM_OSAL_TRACEGRP_OMXIMGDEC," Invalid test ID selection.");
        goto EXIT;
    }



#if 0
    TIMM_OSAL_InfoExt(TIMM_OSAL_TRACEGRP_OMXIMGDEC," Select test case end ID (1-51):");
    scanf("%d", &test_case_end);

    if(test_case_end<test_case_start || test_case_start < 1 || test_case_end > 56)
    {
        TIMM_OSAL_ErrorExt(TIMM_OSAL_TRACEGRP_OMXIMGDEC," Invalid test ID range selection.");
        goto EXIT;
    }
#endif
    TIMM_OSAL_EnteringExt(TIMM_OSAL_TRACEGRP_OMXIMGDEC);
    TIMM_OSAL_InfoExt(TIMM_OSAL_TRACEGRP_OMXIMGDEC," JPEG Decoder Test case begin");
	printf("\n-----------------------------------------------");


    // Get Memory status before running the test case
    mem_size_start = OMX_Jpegd_MemStatPrint();

#ifdef MEMORY_DEBUG
    TIMM_OSAL_StartMemDebug();
#endif


test_case=(test_case_start-1);

//    for(test_case=(test_case_start-1); test_case<test_case_end; test_case++)
  //  {
        testcaseEntry = &OMX_JPEGDTestCaseTable[test_case];
        testcaseEntry->pTestProc(1,(TIMM_OSAL_U32*)&OMX_JPEGDTestCaseTable[test_case],NULL);
   // }



#ifdef MEMORY_DEBUG
    TIMM_OSAL_EndMemDebug();
#endif

    // Get Memory status after running the test case
    mem_size_end = OMX_Jpegd_MemStatPrint();
    if(mem_size_end != mem_size_start)
        TIMM_OSAL_ErrorExt(TIMM_OSAL_TRACEGRP_OMXIMGDEC," Memory leak detected. Bytes lost = %d", (mem_size_end - mem_size_start));
    TIMM_OSAL_InfoExt(TIMM_OSAL_TRACEGRP_OMXIMGDEC," JPEG Decoder Test End");

printf("\n -------------- JPEG Decoder Test End --------------------");
    printf("\nCalling platform deinit()\n");
    mmplatform_deinit();
    printf("\nPlatform deinitialized\n");


EXIT:
    return 0;
}


OMX_U32 OMX_Jpegd_MemStatPrint(void)
{

/*
Memory_Stats stats;
    OMX_U32 mem_count= 0, mem_size = 0;

    // Get Memory status before running the test case
    mem_count = TIMM_OSAL_GetMemCounter();
    mem_size = TIMM_OSAL_GetMemUsage();

    TIMM_OSAL_InfoExt(TIMM_OSAL_TRACEGRP_OMXIMGDEC," Value from GetMemCounter = %d", mem_count);
    TIMM_OSAL_InfoExt(TIMM_OSAL_TRACEGRP_OMXIMGDEC," Value from GetMemUsage = %d", mem_size);

    Memory_getStats(NULL, &stats);
    TIMM_OSAL_InfoExt(TIMM_OSAL_TRACEGRP_OMXIMGDEC," TotalSize = %d; TotalFreeSize = %d; LargetFreeSize = %d",
		stats.totalSize,stats.totalFreeSize,stats.largestFreeSize);


    return mem_size;*/
return 0;
}



































