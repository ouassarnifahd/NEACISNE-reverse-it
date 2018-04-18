/*
* file buserror.c
* brief défaut d'alignement et signal UNIX SIGBUS
* author hugo descoubes 
*/

#include <stdlib.h>

/*
* program entry point
*/
int main(int argc, char **argv) {
    int *pInt;
    char *pArea;
 
	// enable alignment checking
	#if defined(__GNUC__)
	# if defined(__i386__)
		// x86 architecture
		__asm__("pushf\norl $0x40000,(%esp)\npopf");
	# elif defined(__x86_64__) 
		 // x86_64 architecture
		__asm__("pushf\norl $0x40000,(%rsp)\npopf");
	# endif
	#endif
 
    // malloc() always provides aligned memory
    pArea = (char *) malloc(sizeof(int) + 1);
 
    // increment the pointer by value different of modulo sizeof(*pInt)
	// making it misaligned
    pInt = (int *) (pArea+=3);						// nok 
    //pInt = (int *) (pArea+=sizeof(*pInt));		// ok

    // unaligned access
    *pInt = 51;
 
    return 0;
}
