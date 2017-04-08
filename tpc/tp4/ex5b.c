#include <stdio.h> 
#include <stdlib.h> 

int main(void){ 
    int n ,i , Un=0, Un1=1, Un2 ;
    printf("Donner n: ") ;
    scanf("%d", &n) ;
    for(i=0; i<=n ; i++){
		Un2=Un1+Un ;
		printf("%d ", Un) ;
		Un=Un1 ;
		Un1=Un2 ;
	}
    return (EXIT_SUCCESS) ;
}
