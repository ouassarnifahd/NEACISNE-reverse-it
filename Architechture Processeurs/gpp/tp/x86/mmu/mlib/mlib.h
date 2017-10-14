#ifndef __MLIB_H
#define __MLIB_H

/**
* @file mlib.h
* @brief square matrices addition algorithms
*/

#include <x86intrin.h>

/**
* @brief addition of sqare matrices
* @param src1 source matrix pointer
* @param src2 source matrix pointer
* @param dst destination matrix pointer
* @param size size of sqare matrices
*/
void madd(	float* src1, 
			float* src2, 
			float* dst, 
			unsigned int size);

/**
* @brief addition of sqare matrices
* @warning radix 4 matrices sizes
* @param src1 source matrix pointer
* @param src2 source matrix pointer
* @param dst destination matrix pointer
* @param size size of sqare matrices
*/
void madd_r4(	float* src1, 
				float* src2, 
				float* dst, 
				unsigned int size);

/**
* @brief addition of sqare matrices
* @warning radix 4 matrices sizes and sse instruction set support 
* @param src1 source matrix pointer
* @param src2 source matrix pointer
* @param dst destination matrix pointer
* @param size size of sqare matrices
*/
void madd_sse_r4(	float* restrict src1, 	
					float* restrict src2,	 
					float* restrict dst,	 
					register unsigned int size);

/**
* @brief addition of sqare matrices
* @warning radix 8 matrices sizes and avx instruction set support 
* @param src1 source matrix pointer
* @param src2 source matrix pointer
* @param dst destination matrix pointer
* @param size size of sqare matrices
*/
void madd_avx_r8(	float* restrict src1, 	
					float* restrict src2,	 
					float* restrict dst,	 
					register unsigned int size);

#endif
