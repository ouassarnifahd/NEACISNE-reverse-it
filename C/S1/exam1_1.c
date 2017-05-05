#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	int n=0, i, s=0;
	printf("Donner N>0: ");
    scanf("%d", &n);
    for(i=0; i<n; i++){
		s+=i*i;
	}
	printf("S=%d", s);
    return (EXIT_SUCCESS) ;
}
