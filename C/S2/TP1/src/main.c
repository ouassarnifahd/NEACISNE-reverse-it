#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/** @file main.c
*   @brief Definition de la fonction main contenant une interface utilisateur pour gerer les piles.
*/

#include "../inc/pile.h"
#include "../inc/Elements/element.h"

int main(int argc, char const *argv[]){
	int TaillePile,choix;
	TElement pop, Elt;
	printf("Creation d'une pile de nombres %s: \n", (char*)TYPE);
	printf("Entrer la taille pour commencer: ");
	scanf("%d",&TaillePile);
	PTPile invPile=NULL;
	PTPile mainPILE=TPile_Creer(TaillePile);
	printf("Faites votre choix:");
	while(1){
		printf("\n");
		printf("\t1 : Empiler un nouveau element\n");
		printf("\t2 : Depiler un element de la pile\n");
		printf("\t3 : Inverser la pile\n");
		printf("\t4 : Effacer le contenu de la pile\n");
		printf("\t0 : Quitter\n");
		printf("\n\tChoix: ");
		scanf("%d", &choix);
		switch(choix){
			case 1:
				printf("\t  Entrer l'element: ");
				SCAN(Elt);
				mainPILE=TPile_Empiler(mainPILE,Elt);
				break;
			case 2:
				if(TPile_Depiler(mainPILE,&pop)){
					printf("\t  Element ");
					TElement_Afficher(pop);
					printf(" depile avec succes!\n");
				} else printf("\t  Erreur: la pile est vide!\n");
				break;
			case 3:
				invPile=TPile_Creer(mainPILE->TailleMax);
				while(!TPile_EstVide(mainPILE)){
					TPile_Depiler(mainPILE,&pop);
					invPile=TPile_Empiler(invPile,pop);
				}
				mainPILE=invPile;
				printf("\t  Pile inversee avec succes!\n");
				break;
			case 4:
				printf("\t  Pile remise a zero!\n");
				TPile_Effacer(mainPILE);
				break;
			case 0:
				printf("\t  Destruction de la pile\n");
				TPile_Detruire(mainPILE);
				return EXIT_SUCCESS;
			default:
				printf("\t  Ce choix n'est pas valide\n");
		}
		printf("\n");
		TPile_Afficher(mainPILE);
	}
}
