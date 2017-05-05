/*! 
 *  \brief     skeleton for exercise 7.3
 *  \author    Philippe lefebvre
 *  \version   0.1
 *  \date      2020 
 *  \warning   Improper user input can crash the application
 *  \copyright GNU Public License.
 */

#include <stdio.h>
#include <stdlib.h>

/** main program for debug purpose
@return : void
*/ 	
int main(int argc, char** argv) {
	Fiche *pf ;
	int t[5] ;
	int idx ;
	Repertoire r ;
	t[0]= 2 ; t[1]= 31 ; t[2]= 45 ; t[3]= 27 ; t[4]=50 ;
	pf=creerFiche("Proackis", "John", t);
	afficherFiche( *pf ) ;
	r=creerRep(10) ;
	ajouterFiche( r, pf) ;
	afficherRep( r) ;
	pf=creerFiche("Pouzin", "Louis", t);
	ajouterFiche( r, pf) ;
	pf=creerFiche("Lee", "Edward", t);
	ajouterFiche( r, pf) ;
	afficherRep( r ) ;
	idx = rechercherFiche(r, "Pouzin", "Louis") ;
	supprimerFiche (r, idx) ;
	afficherRep( r ) ;
	return (EXIT_SUCCESS) ;
}
