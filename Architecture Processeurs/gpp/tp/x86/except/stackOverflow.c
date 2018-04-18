/*
* file stackOverflow.c
* brief programme testant et pouvant modifier les limites de la pile
* author hugo descoubes
*/

/* include dependencies */
#include <stdio.h>
#include <stdint.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h> 

/* privates macros */
#define	ZERO		0
#define	ONE_MBYTES	1048576
#define	STACK_SIZE	ZERO*ONE_MBYTES

/* privates definitions */
typedef	long unsigned long	uInt64;	// unsigned int 64bits
typedef	unsigned char		uInt8;	// unsigned int 8bits

/* Privates prototypes */
void stackSizeAlloc( uInt64 stackSize );
void growStack( void );

/* privates declarations */
uintptr_t roughAddStk;

/*
* program entry point
*/
int main(int argc,char* argv[]){
	uInt8 tmp;
	roughAddStk = (uintptr_t) &tmp;

	// modification taille de la pile Thread courant
	stackSizeAlloc( STACK_SIZE );

	// allocations sur la pile jusqu'à débordement
	growStack();

return 0;
}

/*
 * void stackSizeAlloc( uInt64 stackSize )
 * brief fonction permettant de modifier la taille de la pile du thread courant
 * param stackSize taille de la pile en Mo
 * li	si stackSize = 0, garde taille par défaut allouée par le système (8Mo)
 */
void stackSizeAlloc( uInt64 stackSize ) {
	struct rlimit rl; 

	if ( stackSize == ZERO ) {
		printf("Stack Default Value\n"); 
		return;
	}

	// récupération taille limite pile thread courante
	getrlimit (RLIMIT_STACK, &rl); 
	printf("Current stack value is : %llu\n", (uInt64) rl.rlim_cur); 

	// MAJ taille de la pile thread courant
	rl.rlim_cur = stackSize; 
	setrlimit (RLIMIT_STACK, &rl); 
}

/*
 * void growStack( void )
 * brief allocation sur la pile jusqu'à débordement
 */
void growStack( void ) {
	uInt8 tmp;

	// affiche taille courante approximative de la pile
	printf("Current Stack Size = %llu bytes\n", \
			(uInt64) (roughAddStk - (uintptr_t) &tmp) );

return growStack();
}	
