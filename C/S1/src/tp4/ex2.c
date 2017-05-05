/**
 * @file tp4_2.c
 * @author : Philippe Lefebvre <philippe.lefebvre@ensicaen.fr>
 * @date : 2020/12/25
 * @brief : Programme de démonstration sur la précision dy type float
 * @version : 1.0
**/

#include <stdio.h> 
#include <stdlib.h> 

int main(void){ 
    int n=0; 
    float epsilon=1.0; 
    double condition ; 
    do { 
        epsilon/=10.0; 
        n++; 
        condition = 1.0+epsilon ; 
    } while(condition!=1.0); 
    printf("epsilon = 10^-%d\n",n); 
    return (EXIT_SUCCESS) ;
}
