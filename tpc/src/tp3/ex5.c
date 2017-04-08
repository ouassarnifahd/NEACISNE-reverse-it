/**
 * @file tp3_5.c
 * @author : Philippe Lefebvre <philippe.lefebvre@ensicaen.fr>
 * @date : 2020/12/25
 * @brief : Programme mystérieux… 
 * @version : 1.0
**/

#include<stdio.h> 
#include<stdlib.h> 
int main (void) { 
    int nb=7531, i=0 ; 
    while ( nb>0 ) { 
        nb=nb/10 ; 
        i=i+1 ; 
    } 
    printf ("nombre de chiffres = %d\n", i) ; 
    return (EXIT_SUCCESS) ;
}
