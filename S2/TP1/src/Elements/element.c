#include<stdio.h>

#include"../../inc/Elements/element.h"

#ifdef _FLOAT_

void TElement_Afficher(TElement data){
    printf("%.2f", data);
}

#elif _INT_

void TElement_Afficher(TElement data){
    printf("%d", data);
}

#endif
