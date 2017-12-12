/*
* file heap.c
* brief programme d'analyse des m�canismes de gestion du tas
* author
*/

#include <stdlib.h>

void boo(int a, int b, int c, int d) {
	return;
}

/*
* program entry point
*/
int main(void){
	char *pfoo;

	pfoo = (char *) malloc(100 * sizeof(char));

	*(pfoo + 7) = 1;

	pfoo = (char *) realloc(pfoo, 120 * sizeof(char));

	pfoo[10] = 0x61;

	boo(1, 2, 3, 4);

	free(pfoo);

return 0;
}
