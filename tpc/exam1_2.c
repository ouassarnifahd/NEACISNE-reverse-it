#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void fonction(int *d, int *u, int n){
	*d=n/10;
	*u=n%10;
}

int main(void){
	int d, u, n;
	printf("Donner N>0: ");
    scanf("%d", &n);
	fonction(&d, &u, n);
	printf("N=%d=10*%d+%d", n, d, u);
    return (EXIT_SUCCESS) ;
}
