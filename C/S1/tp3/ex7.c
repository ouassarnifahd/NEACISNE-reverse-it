#include<stdio.h>
#include<stdlib.h> 

int main (void) {
    int j=3, p=1 ;
    while(j>0){
        p=p*10 ;
        j-- ;
    }
    printf ("p = %d \n", p) ;
    return (EXIT_SUCCESS) ;
}
