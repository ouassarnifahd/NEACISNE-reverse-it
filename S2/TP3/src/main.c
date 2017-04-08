#include"../inc/queue.h"

int main(int argc, char const *argv[]){
	int TailleFile,choix;
	TElement newElt=0;
	printf("Creation d'une file de %s: \n", (char*)TYPE);
	printf("Entrer la taille pour commencer: ");
	scanf("%d",&TailleFile);
	PTQueue mainFILE=TQueue_New(TailleFile);
	printf("Faites votre choix:");
	while(1){
		printf("\n");
		printf("\t1 : Ajouter un nouvel élément en queue de la file\n");
		printf("\t2 : Retirer le premier élément de la file\n");
		printf("\t3 : Vider complètement la file\n");
		printf("\t0 : Quitter\n");
		printf("\n\tChoix: ");
		scanf("%d", &choix);
		switch(choix){
			case 1:
				do{
					printf("\t  Entrer l'element: ");
				}while(read_element(&newElt));
				mainFILE->Enqueue(mainFILE,newElt);
				break;
			case 2:
				if(mainFILE->Dequeue(mainFILE,NULL)){
					printf("\t  Success!\n");
				} else {
					printf("\t  Erreur!\n");
				}
				break;
			case 3:
				mainFILE->Clear(mainFILE);
				printf("\t  File vidée!\n");
				break;
			case 0:
				mainFILE->Delete(mainFILE);
				printf("\t  Destruction de la file!\n");
				return EXIT_SUCCESS;
			default:
				printf("\t  Ce choix n'est pas valide!\n");
		}
		printf("\n");
		mainFILE->Display(mainFILE);
	}
}
