#include <stdio.h>
int main(int argc, char* argv[]) {
    int an, promo ; 
    printf("Donnez l'année de votre promo : ") ; 
    scanf("%d", &promo) ; 
    printf("Donnez l'année en cours : ") ;
    scanf("%d", &an) ; 
    bienvenue(an, promo) ;
}
