/*
* file madd_r4.c
*/

#include "mlib.h"

/*
* square matrices addition
*/
void madd_r4(	float* restrict src1,
				float* restrict src2,
				float* restrict dst,
				unsigned int size) {

	register int i, j, idx;
	register float src10, src11, src12, src13;
	register float src20, src21, src22, src23;
	register float dst0, dst1, dst2, dst3;

	for(i=0; i<size; i++){
		for(j=0; j<size; j+=4){
			idx = size * i + j;
			

		}
	}
}
