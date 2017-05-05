#include <stdio.h> 
#include <stdlib.h> 


double f(double x){
	return -1200.+x*(-598.+x*(3+x));
}

double dichoRec(double g, double d, double epsilon){
	double m;
	m=(g+d)/2.;
	if((d-g)<epsilon)
		return g;
	if(f(m)>0){
		return dichoRec(g,m,epsilon);
	}
	else{
		return dichoRec(m,d,epsilon);
	}
}


int main(void){ 
    double zero;
    zero=dichoRec(0,100,1e-9);
    printf("zero= %f", zero);
    return (EXIT_SUCCESS) ;
}
