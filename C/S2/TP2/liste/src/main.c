/** @file main.c
*   @brief Ficher source de la fonction main.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../inc/Elements/element.h"
#include "../inc/liste.h"

int main(int argc, char const *argv[]){
	int choix,index;
	TElement newElt;
	printf("Creation d'une liste de %s: \n", (char*)TYPE);
	PTList mainliste = TList_New((int)sizeof(TElement));
	printf("Faites votre choix:");
	while(1){
		printf("\n");
		printf("\t1 : Ajouter un element en fin de liste\n");
		printf("\t2 : Inserer un element en début de liste\n");
		printf("\t3 : Inserer un element à la position courante\n");
		printf("\t4 : Modifier la position courante\n");
		printf("\t5 : Enlever l'element en fin de liste\n");
		printf("\t6 : Supprimer l'element en debut de liste\n");
		printf("\t7 : Supprimer l'element courant\n");
		printf("\t8 : Vider la liste\n");
		printf("\t0 : Quitter\n");
		printf("\n\tChoix: ");
		scanf("%d", &choix);
		switch(choix){
			case 1:
				do {
					printf("\t  Entrer l'element: ");
				} while(read_element(&newElt));
				mainliste->Current=TList_Add(mainliste,&newElt);
				//if(mainliste->IsEmpty(mainliste)) mainliste->Current=mainliste->Last;
				break;
			case 2:
				do {
					printf("\t  Entrer l'element: ");
				} while(read_element(&newElt));
				mainliste->First=TList_InsertFirst(mainliste,&newElt);
				break;
			case 3:
				do {
					printf("\t  Entrer l'element: ");
				} while(read_element(&newElt));
				//mainliste->Current=mainliste->Current->Next;
				TList_Insert(mainliste,&newElt);
				break;
			case 4:
				do {
					printf("\t  Entrer une nouvelle position: ");
				} while(!scanf("%d",&index));
				mainliste->Current=TList_GoTo(mainliste,index);
				break;
			case 5:
				if (TList_RemoveLast(mainliste)){
					printf("\t  Success!\n");
				} else {
					printf("\t  Erreur!\n");
				}
				break;
			case 6:
				if (TList_RemoveFirst(mainliste)){
					printf("\t  Success!\n");
				} else {
					printf("\t  Erreur!\n");
				}
				break;
			case 7:
				if (TList_RemoveCurrent(mainliste)){
					printf("\t  Success!\n");
				} else {
					printf("\t  Erreur!\n");
				}
				break;
			case 8:
				TList_Clear(mainliste);
				printf("\t  Liste vidée!\n");
				break;
			case 0:
				TList_Delete(mainliste);
				printf("\t  Destruction de la liste!\n");
				return EXIT_SUCCESS;
			default:
				printf("\t  Ce choix n'est pas valide!\n");
		}
		printf("\n");
		TList_Display(mainliste,display_element);
	}
}
