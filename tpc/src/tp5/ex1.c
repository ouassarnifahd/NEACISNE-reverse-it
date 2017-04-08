/*! 
 *  \brief     Daily Calorie Needs calculator
 *  \author    Philippe lefebvre
 *  \version   0.1
 *  \date      2020 
 *  \warning   Improper user input can crash the application
 *  \copyright GNU Public License.
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h> 

/**  Calcul la surface corporelle
  @param t : taille en m
  @param p : poids en kg
  @return la surface corporelle 
*/
float surfaceCorporelle (float p, float t) {
	// TODO
}

/**  Calcul le metabolisme de base
  @param sc : surface corporelle
  @param a : age
  @return le metabolisme de base 
*/
// TODO

/**  prise en compte du sexe dans le metabolisme de base
  @param mb : le métabolisme initial
  @param sexe : 0 si homme, 1 si femme
  @param alaitmt : 1 si alaitement, 0 sinon
  @return le metabolisme de base modifié 
*/
// TODO


/**  IHM de test 
  @return void
*/
void ihm () {
// TODO
}	
	
/**  main 
 * validation des fonctions 
  @return EXIT_SUCCESS whatever happens
*/		
int main(int argc, char** argv) {
	printf ("sc = %f\n", surfaceCorporelle (55, 1.7)) ; // doit retourner 1.440421
	printf ("mb = %f\n", metaBase (1.440421, 20)) ; // doit retourner 1209.953613
	printf ("mbs = %f\n", metaBaseSexe (1209.953613 , 1, 1 ) ) ;  // doit retourner 1688.958252
	return (EXIT_SUCCESS) ;
}
