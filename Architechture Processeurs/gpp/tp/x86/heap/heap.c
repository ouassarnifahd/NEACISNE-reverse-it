/*
* file heap.c
* brief programme d'analyse des mécanismes de gestion du tas
* author 
*/

#include <stdlib.h>

/*
* program entry point
*/
int main(void){
	char *pfoo;

	pfoo = (char *) malloc(100 * sizeof(char));

	*(pfoo + 7) = 1;

	free(pfoo);

return 0;
}

