/*
* file firlib\src\fir_sp.c
* brief FIR filtering function in canonical C (single precision IEEE754)
* author
* date
*/

#include "firlib.h"

/*
 * FIR filtering function in canonical C (single precision IEEE754)
 */
void fir_sp (	const float * restrict xk, 	\
				const float * restrict a,	\
				float * restrict yk, 		\
				int na,						\
				int nyk){
	int i, j;

	for (i=0; i<nyk; i++) {
		yk[i] = 0;

		/* FIR filter algorithm - dot product */
		for (j=0; j<na; j++){
			yk[i] += a[j]*xk[i+j];
		}
	}
}


