/*
*   @file  H264_ILClien_DynamicSettings.c
*   This file contains the structures and macros that are used in the Application which tests the OpenMAX component
*
*  @path \WTSD_DucatiMMSW\omx\khronos1.1\omx_h264_dec\test
*
*  @rev 1.0
*/

/****************************************************************
 * INCLUDE FILES
 ****************************************************************/
/**----- system and platform files ----------------------------**/

/**-------program files ----------------------------------------**/
#include "H264_ILClient.h"

H264E_TestCaseParamsDynamic H264_TestCaseDynTable[1]= {
{
	{
		{2,20,-1},
		{20,30,0}
		
	},
	{
		{0,20,-1},
		{128000,50000,0}
		
	},
	{
		{0,-1},
		{2},
		{0},
		{0},
		{0},
		{0}
		
	},	
	{
		{5,20,-1},
		{1,1}
	},
	{
		{0,-1},
		{25},
		{51},
		{0},
		{25},
		{51},
		{0},
		{4},
		{51},
		{0}
	},
	{
		{0,-1},
		{10}
	},
	{
		{-1},
		{0}
	},
	{
		{0,-1},
		{0},
		{0}
	},
	
	{
		{-1},
		{0}
	}
	
}

};







