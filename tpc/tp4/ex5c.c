#include <stdio.h> 
#include <stdlib.h> 

int main(void){
	float Vn=1, Vn1=2 ; 
    int i=0, Un=0, Un1=1, Un2 ;
    while(abs(Vn1-Vn)>1e-16){
		Un2=Un1+Un ;
		Vn=Un1/(float)Un ;
		Vn1=Un2/(float)Un1 ;
		Un=Un1 ;
		Un1=Un2 ;
		printf("%f , %d", Vn, i) ;
		i++ ;
	}
    return (EXIT_SUCCESS) ;
}
