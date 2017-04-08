#include <stdio.h>
#include <stdlib.h>

int cherche(char *chaine, char *expre){
	int i, j, indice;
	for(i=0; expre[i]!='\0'; i++){
		j=0;
		if(chaine[j]!=expre[i+j]){
			continue;
		}	
		while(chaine[j]!='\0' && chaine[j]==expre[i+j]){
			indice=i;
			j++;
		}	
	}
	return indice;
}


int main(){
	char expression[]="La puissance des processeurs double tous les 18 mois", chaine[]="process";
	int ind=cherche(chaine,expression);
	printf("l'expression %s est a l'indice %d", chaine, ind);
	return 0;
}
