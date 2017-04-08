/** @file element.c
*   @brief Ficher source contenant les fonctions de l'elements.
*/

#include"../../inc/Elements/element.h"

PTElement new_element(int sizeofElem){
    PTElement this = malloc(sizeof(TElement));
    if(!this) return NULL;
    this->pElement = malloc(sizeofElem);
    this->display = (void*) display_element;
    this->read  = (void*) read_element;
    return this;
}

#ifdef _FLOAT_

static void display_element(const void *pElement){
    float flottant= *(const float *)pElement;
    printf("%.2f", flottant);
}

static bool read_element(const void *pElement){
    return !scanf("%f",(float *)pElement);
}

#elif _INT_

static void display_element(const void *pElement){
    int entier= *(const int *)pElement;
    printf("%d", entier);
}

static bool read_element(const void *pElement){
    return !scanf("%d",(int *)pElement);
}

#endif
