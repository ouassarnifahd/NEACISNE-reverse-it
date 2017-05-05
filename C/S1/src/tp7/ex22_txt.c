#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/** main program for debug purpose
@return : void
*/ 	
int main(int argc, char** argv) {
	int i;
    FILE *fpa ;

    fpa = fopen ("titi.txt","r");
    while ( fscanf(fpa,"%d", &i) >0 ) {
        printf ("%d ", i) ;
    }
    fclose(fpa);
	return (EXIT_SUCCESS) ;
}
