#include <stdio.h>

void bienvenue(int an, int promo) {
	if (an+1==promo || an+2==promo || an+3==promo) {
		printf("Bienvenue à la promotion %d !\n", promo) ;
	}
	else {
		printf("Pb ?!") ;
	}
}
 
int main(int argc, char* argv[]) {
	int an, promo ; 
    printf("Donnez l'année de votre promo : ") ; 
    scanf("%d", &promo) ; 
    printf("Donnez l'année en cours : ") ;
    scanf("%d", &an) ; 
    bienvenue(an, promo) ;
	return 0;
}
