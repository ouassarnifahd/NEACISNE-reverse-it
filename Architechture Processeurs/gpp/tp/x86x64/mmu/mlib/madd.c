/*
* file madd.c
*/

#include "mlib.h"

/*
* square matrices addition
*/
void madd(	float* src1, 
			float* src2,
			float* dst, 
			unsigned int size) {

	int	i, j;

	for(i=0; i<size; i++){
		for(j=0; j<size; j++){
			dst[size*i + j] = src1[size*i + j] + src2[size*i + j];
		}
	}
}
