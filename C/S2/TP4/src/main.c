#include "../inc/element.h"
#include "../inc/array.h"
#include "../inc/sort.h"

int main(int argc, char const *argv[]){
    TElement min = MIN, max = MAX;
    #if defined ELEM_SHORT || defined ELEM_LONG
    srand(time(NULL));
    #elif ELEM_REAL
    srand48(time(NULL));
    #endif
    printf("Initialisation du tableau aléatoire:\n");
    PTElement tabElems = initRandomTab(ARRAY_SIZE,&min,&max,sizeof(TElement),TElement_Random);
    displayTab(tabElems,ARRAY_SIZE,sizeof(TElement),TElement_Display);
    #ifdef SELECTION
    printf("tri du tableau avec tri selection.\n");
    selection_sort(tabElems,ARRAY_SIZE,sizeof(TElement),TElement_Compare);
    #elif INSERTION
    printf("tri du tableau avec tri insertion.\n");
    insertion_sort(tabElems,ARRAY_SIZE,sizeof(TElement),TElement_Compare);
    #elif BUBBLE
    printf("tri du tableau avec tri bulles.\n");
    bubble_sort(tabElems,ARRAY_SIZE,sizeof(TElement),TElement_Compare);
    #elif MERGE
    printf("tri du tableau avec tri fusion.\n");
    merge_sort(tabElems,ARRAY_SIZE,sizeof(TElement),TElement_Compare);
    #elif QUICK
    printf("tri du tableau avec tri rapide.\n");
    quick_sort(tabElems,ARRAY_SIZE,sizeof(TElement),TElement_Compare);
    #endif
    printf("Affichage du tableau trié.\n");
    displayTab(tabElems,ARRAY_SIZE,sizeof(TElement),TElement_Display);
    free(tabElems);
}
