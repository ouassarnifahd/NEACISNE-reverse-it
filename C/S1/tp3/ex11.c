#include<stdio.h>
#include<stdlib.h> 

int main (void) {
	int b=16, nb=7531, i=0, nb2=nb, c ;
    while(nb>0){
        nb=nb/b ;
        i++ ;
    }
    int p=1, j=i-1 ;
    while(j>0){
        p=p*b ;
        j-- ;
    }
    while(p>0){
        c=nb2/p ;
        printf("%X", c) ;
        nb2=nb2-c*p ;
        p=p/b ;
    }
    return (EXIT_SUCCESS) ;
}
