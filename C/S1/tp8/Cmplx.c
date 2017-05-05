#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct sComplexe {
    float Re;
    float Im;
} Complexe;

void affiCplx(Complexe z){
    printf("z = %.2f ", z.Re);
    if (z.Im==0) {
        printf("\n");
    }
    if (z.Im>0) {
        printf("+ i%.2f\n", z.Im);
    }
    if (z.Im<0) {
        printf("- i%.2f\n", fabsf(z.Im));
    }
}

char * writeCplx(Complexe z){
    char *rel;
    rel=(char*)malloc(30);
    if (z.Im>0) {
        sprintf(rel,"%.2f + i%.2f", z.Re, z.Im);
    }
    if (z.Im<0) {
        sprintf(rel,"%.2f - i%.2f", z.Re, fabsf(z.Im));
    }
    if (z.Im==0) {
        sprintf(rel,"%.2f", z.Re);
    }
    return rel;
}

Complexe readCplx(char *expcmplx){
    Complexe z;
    expcmplx=(char*)malloc(30);
    sscanf(expcmplx,"%f + i%f", &z.Re, &z.Im);
    return z;
}

Complexe addCplx(Complexe z1, Complexe z2){
    Complexe z;
    z.Re=z1.Re+z2.Re;
    z.Im=z1.Im+z2.Im;
    return z;
}

Complexe multCplx(Complexe z1, Complexe z2){
    Complexe z;
    z.Re=z1.Re*z2.Re-z1.Im*z2.Im;
    z.Im=z1.Im*z2.Re+z1.Re*z2.Im;
    return z;
}

Complexe divCplx(Complexe z1, Complexe z2){
    Complexe z;
    z.Re=(z1.Re*z2.Re+z1.Im*z2.Im)/(z2.Re*z2.Re+z2.Im*z2.Im);
    z.Im=(z1.Im*z2.Re-z1.Re*z2.Im)/(z2.Re*z2.Re+z2.Im*z2.Im);
    return z;
}

char add[100]="( 12 + i4 ) / ( 1 + i )";

int main(int argc, char *argv[]){
    Complexe A, B, add, mult, dv;
    printf("Entrer z1 : ");
    scanf("%f+i%f", &A.Re, &A.Im);
    printf("Entrer z2 : ");
    scanf("%f+i%f", &B.Re, &B.Im);
    printf("add = %s\n", writeCplx(addCplx(A,B)));
    printf("mult = %s\n", writeCplx(multCplx(A,B)));
    printf("div = %s\n", writeCplx(divCplx(A,B)));


}
