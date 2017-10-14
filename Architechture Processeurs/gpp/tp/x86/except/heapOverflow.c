/*
* file heapOverflow.c
* brief programme testant les limites du Tas
* ~3Go sur architecture 32bits
* author hugo descoubes
*/

/* include dependencies */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* privates macros */
#define	HUNDRED_MBYTES	100*1048576

/* privates definitions */
typedef	long unsigned long	uInt64;	// unsigned int 64bits

/*
* program entry point
*/
int main(int argc,char* argv[]){
	uInt64 maxMemMiB=0;
	void* memPointer = NULL;

	// allocations dynamiques dans le tas jusqu'à débordement
	do{
		// allocations/libérations dynamiques tranche par tranche
		if(memPointer != NULL){
			free(memPointer);
		}

		maxMemMiB += (uInt64) HUNDRED_MBYTES;
		memPointer = malloc(maxMemMiB);

	}while(memPointer != NULL);

	free(memPointer);
	printf(	"Taille approximative du Tas = %llu\n", maxMemMiB-HUNDRED_MBYTES);

return 0;
}
