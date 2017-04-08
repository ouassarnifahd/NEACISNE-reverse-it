
/**
 * @file tp4_1.c
 * @author : Philippe Lefebvre <philippe.lefebvre@ensicaen.fr>
 * @date : 2020/12/25
 * @brief : Programme de démonstration sur les nombres flottants
 * @version : 1.0
**/

#include<stdio.h> 
#include<stdlib.h> 

int main (void) {
    float a=0.2, b=1e18, c=a/b, d= 3/7, e = 3/7. ;
    printf ("a = %f, b = %f, b = %e\n", a, b, b) ; 
    printf ("a/b = %e, 3/7 = %f, 3/7.0 = %f \n", c, d, e) ; 
    return (EXIT_SUCCESS) ;
}
