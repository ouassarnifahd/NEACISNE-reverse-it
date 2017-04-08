/*! 
 *  \brief     gdb test program
 *  \author    Philippe lefebvre
 *  \version   0.1
 *  \date      2020 
 *  \warning   Improper user input can crash the application
 *  \copyright GNU Public License.
 */

#include <stdio.h>
#include <stdlib.h>

#define TAB_LEN 5 

/** saisi à partir du clavier des entiers 
@param tableau : le tableau à remplir 
@param taille : la taille du tableau 
@return : rien 
*/ 
void saisir (int tableau[], int taille) { 
    int i ; 
    for (i = 0 ; i<taille ; i++ ) { 
        printf ("Entrer la valeur %d : ", i); 
        scanf ("%d", &tableau[i] ) ; 
    } 
    return ; 
} 

/** Affiche un tableau 1D
@param tableau : le tableau  
@param taille : la taille du tableau 
@return : rien 
*/ 
void afficher (int tableau[], int taille) { 
    int i ; 
    for (i = 0 ; i<taille ; i++ ) 
        printf ("valeur %d : %d\n", i, tableau[i] ) ; 
    return ; 
} 

/** main program for debug purpose
@param tableau : le tableau  
@param taille : la taille du tableau 
@return : rien 
*/ 	
int main(int argc, char** argv) {
	int tab[TAB_LEN] ; 
    saisir(tab, TAB_LEN) ; 
    afficher (tab, TAB_LEN) ; 
	return (EXIT_SUCCESS) ;
}
