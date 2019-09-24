#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char **argv) {
    char commande[300] ; char * mot ; char argu[10][100] ; 
    int n=0 ; 
        printf("Entrez la commande > ");
        fgets (commande, 300, stdin) ;
        mot = strtok (commande, " ") ;
        strcpy(argu[n], mot) ;  
		printf("%d> %s\n",n, argu[n] );
        
        while ((mot = strtok (NULL, " ") )!=NULL) {
			n++ ;
			strcpy(argu[n], mot) ;        
			printf("%d> %s\n",n, argu[n] );
		}
	return(EXIT_SUCCESS) ;  
}

