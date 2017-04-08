#include <stdio.h> 
#include <stdlib.h> 


int fiboRec(int n){
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	else
		return fiboRec(n-1)+fiboRec(n-2);
}

int main(void){
	int n, fibo;
	printf("Donner un n>0: ");
	scanf("%d", &n);
	fibo=fiboRec(n);
	printf("fibo(%d)=%d", n, fibo);
	return (EXIT_SUCCESS) ;
}
