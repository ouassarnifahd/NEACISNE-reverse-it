/*
* file madd_sse_r4.c
*/

#include "mlib.h"

/*
* square matrices addition
*/
void madd_sse_r4(	float* restrict src1, 	
					float* restrict src2,	 
					float* restrict dst,	 
					register unsigned int size) {

	register unsigned int i, j, idx;
	__m128 xmm128_src1, xmm128_src2, xmm128_dst;

	for(i=0; i<size; i++){
		for(j=0; j<size; j+=4){
			idx = size*i + j;			
			xmm128_src1 = _mm_load_ps(&src1[idx]);
			xmm128_src2 = _mm_load_ps(&src2[idx]);
			xmm128_dst = _mm_add_ps(xmm128_src1,xmm128_src2); 
			_mm_store_ps(&dst[idx],xmm128_dst);
		}
	}
}

