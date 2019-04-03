#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/** main program for debug purpose
@return : void
*/ 	
int main(int argc, char** argv){
	char ch[]="déjà";
	printf("%s %d\n", ch,(int) strlen(ch));
	return (EXIT_SUCCESS);
}
