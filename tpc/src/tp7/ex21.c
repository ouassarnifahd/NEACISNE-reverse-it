#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/** main program for debug purpose
@return : void
*/ 	
int main(int argc, char** argv) {
	int i;
	FILE *fpb, *fpa;

	fpb = fopen ("titi.bin","w");
	fpa = fopen ("titi.txt","w");
	for(i=45;i<55;i++){
		fwrite(&i,sizeof(int),1,fpb);
		fprintf(fpa,"%d ",i);
	}
	fclose(fpb);
	fclose(fpa);
	return (EXIT_SUCCESS) ;
}
