#include <float.h>
#include <limits.h>

#include "../inc/element.h"
#include "../inc/array.h"
#include "../inc/sort.h"

int main(int argc, char const *argv[]){
    #ifdef ELEM_SHORT
    TElement min = SCHAR_MIN, max = SCHAR_MAX;
    #elif ELEM_LONG
    TElement min = LONG_MIN, max = LONG_MAX;
    #elif ELEM_REAL
    TElement min = FLT_MIN, max = FLT_MAX;
    #endif
    printf("Initialisation du tableau aléatoire:\n");
    PTElement tabElts = initRandomTab(ARRAY_SIZE,&min,&max,sizeof(TElement),TElement_Random);
    displayTab(tabElts,ARRAY_SIZE,sizeof(TElement),TElement_Display);
    #ifdef SELECTION
    printf("tri du tableau avec tri selection.\n");
    selection_sort(tabElts,ARRAY_SIZE,sizeof(TElement),TElement_Compare);
    #elif INSERTION
    printf("tri du tableau avec tri insertion.\n");
    insertion_sort(tabElts,ARRAY_SIZE,sizeof(TElement),TElement_Compare);
    #elif BUBBLE
    printf("tri du tableau avec tri bulles.\n");
    bubble_sort(tabElts,ARRAY_SIZE,sizeof(TElement),TElement_Compare);
    #elif MERGE
    printf("tri du tableau avec tri fusion.\n");
    merge_sort(tabElts,ARRAY_SIZE,sizeof(TElement),TElement_Compare);
    #elif QUICK
    printf("tri du tableau avec tri rapide.\n");
    quick_sort(tabElts,ARRAY_SIZE,sizeof(TElement),TElement_Compare);
    #endif
    printf("Affichage du tableau trié.\n");
    displayTab(tabElts,ARRAY_SIZE,sizeof(TElement),TElement_Display);
}
