/**
 * @file tp3_1.c
 * @author : Philippe Lefebvre <philippe.lefebvre@ensicaen.fr>
 * @date : 2020/12/25
 * @brief : Programme mystérieux… 
 * @version : 1.0
**/

#include<stdio.h> 
#include<stdlib.h> 
int main ( void ) { 
    int n,i,s=0; 
    printf("Donner un nombre n pour faire la somme de 0 a n: ");
    scanf("%d", &n);
    for (i=0; i<=n; i++){ 
        s=s+i ;
    } 
    printf ("s=%d\n", s) ; 
    return (EXIT_SUCCESS) ;
}
