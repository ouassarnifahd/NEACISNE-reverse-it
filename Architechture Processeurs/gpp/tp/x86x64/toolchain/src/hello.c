/*
* toolchain/src/hello.c
* fichier source d'analyse du processus de compilation
*/

#include <stdio.h>
#include <hello.h> 

/*
* program entry point
*/
int main(void){

	#if (MINIMAL == 0)
	printf("Hello World Bro's\n");
	#endif

return 0;
}

