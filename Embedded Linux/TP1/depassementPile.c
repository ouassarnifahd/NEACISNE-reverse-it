#include <stdio.h>
#include <unistd.h>

int premiereFois =1 ;

void fnRecursive() {
	long difference=0 ;
	static long premiereAd;
	if (premiereFois) {
		premiereAd=&difference ;
		premiereFois=0 ;
	}
	difference=premiereAd-(long )&difference ;
	printf("%ld\n",difference) ; 
	fnRecursive() ;
}

main () {

    
    fnRecursive();
}

