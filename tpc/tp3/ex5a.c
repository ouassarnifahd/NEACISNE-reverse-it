#include<stdio.h> 
#include<stdlib.h> 
int main ( void ) { 
    int i,j,k=0,p,n;
    printf("Donner un nombre n>0: ");
    scanf("%d", &n);
    for(i=0; i<=n-1;i++){
		for(j=0; j<=i ;j++){
			p=k+j ;
			printf("%d", p);
		}
		printf("\n");
	}
    return (EXIT_SUCCESS) ;
}
