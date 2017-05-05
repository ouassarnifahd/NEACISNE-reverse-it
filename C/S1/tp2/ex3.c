#include<stdio.h>
int main(int argc, char* argv[]) {
	int an, promo;
	printf("Donnez l'année de votre promo : ") ; 
    scanf("%d", &promo) ; 
    printf("Donnez l'année en cours : ") ;
    scanf("%d", &an) ;
	if (an+1==promo || an+2==promo || an+3==promo) {
		printf("Bienvenue à la promotion %d !\n", promo) ;
	}
	else {
		printf("Pb ?!") ;
	}
	return 0;
}
