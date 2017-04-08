#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

int main(void){
	int c , n ,k=0 ;
	double res , x, y ;
	srand(time(NULL)) ;
	//printf("Donner n: ") ;
	//scanf("%d", &c) ;
	c= 100000000 ;
	for (n=0; n<c; n++){
		x=2*((rand()/(double)RAND_MAX)-0.5);
		y=2*((rand()/(double)RAND_MAX)-0.5);
		//printf("%f, %f\n", x , y) ;
		if(x*x+y*y<1){
			k++ ; 
		}
	}
	res=4*k/(double)n ;
	printf("pi=%f", res) ;
    return (EXIT_SUCCESS) ;

}
