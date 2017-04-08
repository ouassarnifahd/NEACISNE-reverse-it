#include <stdio.h>
#include <stdlib.h>

void afficher3entiers(int va, int vb, int vc){
    printf("%d, %d, %d\n", va, vb, vc);
}

void trier3Entiers(int *pa, int *pb, int *pc){
    int tmp1, tmp2;
    if(*pb<=*pa){
        tmp1=*pa;
        *pa=*pb;
        *pb=tmp1;
        if(*pc<=*pa){
            tmp1=*pa;
            *pa=*pc;
            tmp2=*pb;
            *pb=tmp1;
            *pc=tmp2;
        }
        if(*pc<=*pb){
            tmp1=*pb;
            *pb=*pc;
            *pc=tmp1;
        }
    }
    if(*pc<=*pa){
        tmp1=*pa;
        *pa=*pc;
        *pc=tmp1;
        if(*pb<=*pa){
            tmp1=*pa;
            *pa=*pb;
            *pb=tmp1;
        }
        if(*pc<=*pb){
            tmp1=*pb;
            *pb=*pc;
            *pc=tmp1;
        }
    }
    if(*pa<=*pb){
        if(*pc<=*pb){
            tmp1=*pb;
            *pb=*pc;
            *pc=tmp1;
        }
        if(*pc<=*pa){
            *pa=tmp1;
            *pb=tmp2;
            *pa=*pc;
            *pb=tmp1;
            *pc=tmp2;
        }
    }
}

void demander3Entiers(int *pa, int *pb, int *pc) {
    printf("Entrer le 1er entier ");
    scanf("%d", pa);
    printf("Entrer le 2eme entier ");
    scanf("%d", pb);
    printf("Entrer le 3eme entier ");
    scanf("%d", pc);
}

int main(void){
    int a=7, b=4,c=5 ;
    demander3Entiers(&a, &b, &c);
    trier3Entiers (&a, &b, &c) ;
    afficher3entiers(a, b, c) ;
}
