#ifndef __FIR_TEST_H
#define __FIR_TEST_H

/**
* @file test\h\firtest.h
* @brief performance test for FIR algorithms library
* @author hugo descoubes
* @date september 2015
*/

/* Application Binary Interface dependencies */
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

/* project specific dependencies */
#include <firlib.h>

/* project specific types */
typedef int Boolean;
typedef struct {
	char		error_status[4];	// string to specify validity of test (OK or NOK)
	uint64_t 	error_samples;		// number of false samples
	float 		error_percent;		// maximum percentage error
	float 		error_margin;		// maximum tolerated margin. Need to be initialized
} TestSystem_obj;					// conformity test object

/* Genuine Intel corei7 Haswell micro-architecture :
* L1D/L1P 32Kb per core
* L2 256Kb per core
* MSM SRAM 8Mb shared by cores
* DDR3 8Gb shared by cores (computer specific)
*
* Project specific :
* XK_LENGTH 		: length of input array in DDR
* AK_LENGTH 		: length of input array in DDR
* YK_LENGTH 		: length of output array in DDR
*/
//#define XK_LENGTH 2048		/* 8kb vector*/
#define XK_LENGTH 65536	/* 256kb vector*/
//#define XK_LENGTH 1048576	/* 4Mb vector*/
#define A_LENGTH 64
#define	YK_LENGTH XK_LENGTH - A_LENGTH + 1

/* misc parameters */
#define TRUE   		 		1
#define FALSE  		 		0
#define CPU_CLOCK_KHZ   		3600000.0
#define CPU_CLOCK_MS   		 	1.0 / CPU_CLOCK_KHZ
#define FIR_NB_MACS   		 	64.0 * (65536.0 - 64.0 + 1.0) /* FIR algorithm complexity - A_LENGTH * YK_LENGTH */

/* input, temporary and ouput vectors */
extern float xk_sp[XK_LENGTH];
extern float a_sp[A_LENGTH];
extern float yk_sp_cn[YK_LENGTH];
extern float yk_sp[YK_LENGTH];

/* API reference */

/**
 * @brief system/conformity test for outputs vectors of miscellaneous algorithms.
 * Sample by sample comparison with tolerated margin error
 * @param conformity statistics about vectors test
 * @param src1 bench vector
 * @param src2 vector under test
 * @param size size of inputs vectors
 * @return TRUE if sample by sample comparison is less important
 * than margin. Else return FALSE
 */
Boolean firtest_sys(TestSystem_obj *conformity,
					float *src1,
					float *src2,
					uint64_t size);


#endif /* __FIR_TEST_H */
