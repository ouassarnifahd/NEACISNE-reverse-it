/** @file element.c
*   @brief Ficher source contenant les fonctions de l'elements.
*/
#include <stdio.h>
#include <stdbool.h>

#include"../../inc/Elements/element.h"

#ifdef _FLOAT_

void display_element(const void *pElement){
    float flottant= *(const float *)pElement;
    printf("%.2f", flottant);
}

bool read_element(const void *pElement){
    return !scanf("%f",(float *)pElement);
}

#elif _INT_

void display_element(const void *pElement){
    int entier= *(const int *)pElement;
    printf("%d", entier);
}

bool read_element(const void *pElement){
    return !scanf("%d",(int *)pElement);
}

#endif
