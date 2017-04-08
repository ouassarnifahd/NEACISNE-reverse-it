#include<stdio.h>
#include<stdlib.h> 

int main (void) {
	int nb=7531, i=0, nb2=nb, c ;
    while(nb>0){
        nb=nb/2 ;
        i++ ;
    }
    int p=1, j=i-1 ;
    while(j>0){
        p=p*2 ;
        j-- ;
    }
    while(p>0){
        c=nb2/p ;
        printf("%d\n", c) ;
        nb2=nb2-c*p ;
        p=p/2 ;
    }
    return (EXIT_SUCCESS) ;
}
