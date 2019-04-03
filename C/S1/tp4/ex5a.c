#include <stdio.h> 
#include <stdlib.h> 

int main(void){ 
    int i=0 , Un=0, Un1=1, Un2 ;
    while(Un>0){
		Un2=Un1+Un ;
		Un=Un1 ;
		Un1=Un2 ;
		i++ ;
	}
	printf("\nmax int est: fibo(%d)", i) ;
    return (EXIT_SUCCESS) ;
}
