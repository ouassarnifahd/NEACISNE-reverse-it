#include <stdio.h>
int main(int argc, char* argv[]) {
    int an ;   // declaration de la variable an
    printf("Donnez l'année de votre promo : ") ; // affiche un message
    scanf("%d", &an) ; // met ce que l'utilisateur a saisi dans la variable an
    if (an > 2019) {    // test si an est > à 2019
		printf("Non, cette promo n'est pas encore entrée ?! \n") ; 
    }
    else  // sinon, (remarquez pas d'accolade car une seule instruction)
        printf("Bienvenue à la promotion %d !\n", an) ;
}
