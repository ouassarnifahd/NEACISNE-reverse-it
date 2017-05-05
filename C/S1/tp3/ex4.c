#include<stdio.h> 
#include<stdlib.h> 
int main ( void ) { 
    int n=-2,i,facto=1; 
    while(n<0){
		printf("Donner un nombre n>0 pour faire facto(n): ");
		scanf("%d", &n);
	}
    for (i=1; i<=n; i++){ 
        facto=facto*i ;
    } 
    printf ("facto=%d\n", facto) ; 
    return (EXIT_SUCCESS) ;
}
