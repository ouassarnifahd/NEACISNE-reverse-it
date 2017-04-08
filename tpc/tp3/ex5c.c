#include<stdio.h> 
#include<stdlib.h> 
int main ( void ) { 
    int i,j,k,l=0,n;
    printf("Donner un nombre n>0: ");
    scanf("%d", &n);
    for(i=0; i<=n-1;i++){
		l++;
		for(j=0; j<=n-(l+1) ;j++){
			printf(" ");
		}
		for(k=0; k<=i ;k++){
			printf("%d", k%10);
		}
		i++;
		printf("\n");
	}
    return (EXIT_SUCCESS) ;
}
