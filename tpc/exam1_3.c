#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float g(float x){
	return cos(2*x+0.5);
}

int main(void){
	int i;
	float x=2.;
	for(i=0; i<=10; i++){
		printf("g(%2.1f)=%f\n", x, g(x));
		x+=0.1;
	}
	return (EXIT_SUCCESS) ;
}
