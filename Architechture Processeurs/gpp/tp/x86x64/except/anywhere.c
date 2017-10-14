/*
* file anywhere.c
* brief écriture n'importe où en mémoire et signal UNIX SIGSEGV
* gcc anywhere.c -o anywhere
* author hugo descoubes
*/

#include <stdio.h>

/*
* program entry point
*/
int main(int argc, char **argv) {
	volatile char* ptr;	// uninitialized pointer

	printf("current stack area = 0x%x\n", (unsigned int) &ptr);
	printf("ptr point anywhere = 0x%x\n", (unsigned int) ptr);

	*ptr = 'H';

return 0;
}
