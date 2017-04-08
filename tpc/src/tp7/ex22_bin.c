#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/** main program for debug purpose
@return : void
*/ 	
int main(int argc, char** argv) {
	int i;
	FILE *fpb ;

	fpb = fopen ("titi.bin","r");
	while ( fread(&i,sizeof(int),1,fpb) >0 ) {
		printf ("%d ", i) ;
	}
	fclose(fpb);
	return (EXIT_SUCCESS) ;
}
