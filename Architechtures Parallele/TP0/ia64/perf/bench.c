/*
* file bench.c
* brief square matrices addition algorithms benchmarking
* cmd lines :

gcc -Wall -march=native -std=c11 -o3 bench.c ./mlib/madd.c ./mlib/madd_r4.c ./mlib/madd_sse_r4.c ./mlib/madd_avx_r8.c -o bench

./perf.sh bench

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "./mlib/mlib.h"

#define	SIZE	2048
#define	REP		10

/*
* main entry point
*/
int main(int argc, char **argv) {
	float *pMatrix_src1, *pMatrix_src2, *pMatrix_dst;
	unsigned int	i, j;

	// matrices dynamic allocations
	pMatrix_src1 	= (float *) malloc(sizeof(float)*SIZE*SIZE);
	pMatrix_src2 	= (float *) malloc(sizeof(float)*SIZE*SIZE);
	pMatrix_dst 	= (float *) malloc(sizeof(float)*SIZE*SIZE);

/*	pMatrix_src1 	= (float *) aligned_alloc(16,sizeof(float)*SIZE*SIZE);
	pMatrix_src2 	= (float *) aligned_alloc(16,sizeof(float)*SIZE*SIZE);
	pMatrix_dst 	= (float *) aligned_alloc(16,sizeof(float)*SIZE*SIZE);
*/

	// matrices initializations 
	srand(time(NULL));
	for(i=0; i<SIZE; i++){
		for(j=0; j<SIZE; j++){
			pMatrix_src1[SIZE*i + j] = (float) (rand() % 10);
			pMatrix_src2[SIZE*i + j] = (float) (rand() % 10);
		}
	}

	// matrices addition - REP is the number of algorithm iterations
	for(i=0; i<REP; i++){
		madd(pMatrix_src1, pMatrix_src2, pMatrix_dst, SIZE);
	}

	// matrix values display - only 1st column
	if ( argc == 2 ){
		if ( !strcmp(argv[1],"display") ){
			for(i=0; i<SIZE; i++){
				printf("%d : %.0f %.0f %.0f\n",	i, 						\
												pMatrix_src1[SIZE*i], 	\
												pMatrix_src2[SIZE*i],	\
												pMatrix_dst[SIZE*i]);
			}
		}
	}

	// memory release
	free(pMatrix_src1);
	free(pMatrix_src2);
	free(pMatrix_dst);

return 0;
}
