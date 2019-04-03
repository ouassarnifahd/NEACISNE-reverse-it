/*
* file firlib\src\fir_sp_sse_r4.c
* brief FIR filtering function in radix 4 vectorized C (single precision IEEE754)
* warning radix 4 input and coefficients arrays sizes, SSE4.1 extension support
* author
* date
*/

#include "firlib.h"

/*
* FIR filtering function in radix 4 vectorized C (single precision IEEE754)
* warning radix 4 input and coefficients arrays sizes, SSE4.1 extension support
*/
void fir_sp_sse_r4 (	const float * restrict xk, 	\
			const float * restrict a,	\
			float * restrict yk, 		\
			int na,				\
			int nyk){
	int i, j, idx;
	__m128 xmm128_xk0123, xmm128_xk1234, xmm128_xk2345, xmm128_xk3456;
	__m128 xmm128_a0123;
	__m128 xmm128_acc;
	xmm_t xmm128_dp0, xmm128_dp1, xmm128_dp2, xmm128_dp3;
	
	/* DEBUG section code for tests */
	//xmm_t debug;
	//debug.m128_vec = xmm128_<vector_under_test>;
	//printf("\nxmm xk0123 : %.6f %.6f %.6f %.6f", debug.m128_f32[0], debug.m128_f32[1], debug.m128_f32[2], debug.m128_f32[3]);
	
	/* input array loop */
	for (i=0; i<nyk; i+=4) {
		/*
		acc1 = 0;
		acc2 = 0;
		acc3 = 0;
		acc4 = 0;
		*/	
		
		/* user code */

		/* FIR filter algorithm - dot product */
		for (j=0; j<na; j+=4){
			/*
			xmm128_a0123 = [a0 a1 a2 a3]
			*/
			
			/* user code */			
			
			/*
			xmm128_xk0123 = [xk0 xk1 xk2 xk3]
			xmm128_xk1234 = [xk1 xk2 xk3 xk4]
			xmm128_xk2345 = [xk2 xk3 xk4 xk5]
			xmm128_xk3456 = [xk3 xk4 xk5 xk6]
			*/

			/* user code */	

			/*
			xmm128_dp0.m128_f32[0] = a0*xk0 + a1*xk1 + a2*xk2 + a3*xk3;
			xmm128_dp1.m128_f32[0] = a0*xk1 + a1*xk2 + a2*xk3 + a3*xk4;
			xmm128_dp2.m128_f32[0] = a0*xk2 + a1*xk3 + a2*xk4 + a3*xk5;
			xmm128_dp3.m128_f32[0] = a0*xk3 + a1*xk4 + a2*xk5 + a3*xk6;
			*/
			
			/* user code */	

			/*
			acc1 += xmm128_dp0.m128_f32[0];
			acc2 += xmm128_dp1.m128_f32[0];
			acc3 += xmm128_dp2.m128_f32[0];
			acc4 += xmm128_dp3.m128_f32[0];
			*/			
			
			/* user code */	
		}
		/*
		yk[i] 	= acc1;
		yk[i+1] = acc2;
		yk[i+2] = acc3;
		yk[i+3] = acc4;
		*/		
		
		/* user code */	
	}
}
