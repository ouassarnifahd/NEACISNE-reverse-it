/*
* file firlib\src\fir_sp_r4.c
* brief FIR filtering function in radix 4 canonical C (single precision IEEE754)
* warning radix 4 input and coefficients arrays sizes
* author
* date
*/

#include "firlib.h"

/*
* FIR filtering function in radix 4 canonical C (single precision IEEE754)
* warning radix 4 input and coefficients arrays sizes
*/
void fir_sp_r4 (const float * restrict xk, 	\
				const float * restrict a,	\
				float * restrict yk, 		\
				int na,						\
				int nyk){
	int i, j;
//	float acc1, acc2, acc3, acc4;
//	float a0, a1, a2, a3;
//	float xk0, xk1, xk2, xk3, xk4, xk5, xk6;
	
	/* input array loop */
	for (i=0; i<nyk; i+=4) {
		/* user code */
		
		/* FIR filter algorithm - dot product */
		for (j=0; j<na; j+=4){
			/* user code */
		}
		
		/* user code */
	}
}
