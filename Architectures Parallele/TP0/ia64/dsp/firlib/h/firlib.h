#ifndef __FIR_LIB_H
#define __FIR_LIB_H

/**
* @file firlib\h\firlib.h
* @brief FIR filtering library for IA-64 architecture (Intel Architecture 64 bits)
* @author hugo descoubes
* @date september 2015
*/

#include <x86intrin.h>

/* project specific types */
union xmm_t { 
	__m128 m128_vec;	// full access to XMM vector 
	float m128_f32[4]; 	// access to XMM vector elements
} align16_xmm;
typedef union xmm_t xmm_t;

/**
 * @brief FIR filtering function in canonical C (single precision IEEE754)
 * @param xk input array pointer (nyk+na-1 elements)
 * @param a coefficients array pointer (na elements)
 * @param yk output array pointer (nyk elements)
 * @param na number of coefficients
 * @param nyk output array size
 */
void fir_sp(	const float * restrict xk, 	\
		const float * restrict a,	\
		float * restrict yk, 		\
		int na,				\
		int nyk);

/**
 * @brief FIR filtering function in radix 4 canonical C (single precision IEEE754)
 * @param xk input array pointer (nyk+na-1 elements)
 * @param a coefficients array pointer (na elements)
 * @param yk output array pointer (nyk elements)
 * @param na number of coefficients
 * @param nyk output array size
 */
void fir_sp_r4 ( const float * restrict xk, 	\
		const float * restrict a,	\
		float * restrict yk, 		\
		int na,				\
		int nyk);

/**
 * @brief FIR filtering function in radix 8 vectorized C (single precision IEEE754)
 * @warning radix 8 input and coefficients arrays sizes
 * SSE4.1 instructions set extensions support
 * @param xk input array pointer (nyk+na-1 elements)
 * @param a coefficients array pointer (na elements)
 * @param yk output array pointer (nyk elements)
 * @param na number of coefficients
 * @param nyk output array size
 */
void fir_sp_sse_r4 (	const float * restrict xk, 	\
			const float * restrict a,	\
			float * restrict yk, 		\
			int na,				\
			int nyk);

#endif /* __FIR_LIB_H */
