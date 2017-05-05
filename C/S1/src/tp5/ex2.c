/*! 
 *  \brief     sort 3 integers
 *  \author    Philippe lefebvre
 *  \version   0.1
 *  \date      2020 
 *  \warning   Improper user input can crash the application
 *  \copyright GNU Public License.
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h> 
	
int main(int argc, char** argv) {
	int a=7, b=4, c=5  ;
    trier3Entiers (&a, &b, &c) ;
    afficher3entiers(a, b, c) ;
	return (EXIT_SUCCESS) ;
}
