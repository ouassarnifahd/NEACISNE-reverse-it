/**
 * @file tp3_7.c
 * @author : Philippe Lefebvre <philippe.lefebvre@ensicaen.fr>
 * @date : 2020/12/25
 * @brief : Programme mystérieux… 
 * @version : 1.0
**/

#include<stdio.h>
#include<stdlib.h> 

int main (void) {
    int j=3, p=1 ;
    do {
        p=p*10 ;
        j-- ;
    } while (j>0) ;
    printf ("p = %d \n", p) ;
    return (EXIT_SUCCESS) ;
}
