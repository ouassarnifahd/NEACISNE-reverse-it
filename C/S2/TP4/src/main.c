#include "../inc/element.h"
#include "../inc/array.h"
#include "../inc/sort.h"

int main(int argc, char const *argv[]){
    TElement ElementMin = MIN_RAND, ElementMax = MAX_RAND;
    printf("Initialisation du tableau aléatoire:\n");
    #if defined ELEM_SHORT || defined ELEM_LONG
    srand(time(NULL));
    #elif ELEM_REAL
    srand48(time(NULL));
    #endif
    PTElement tabElems = initRandomTab(ARRAY_SIZE, &ElementMin, &ElementMax, sizeof(TElement), TElement_Random);
    displayTab(tabElems,ARRAY_SIZE,sizeof(TElement),TElement_Display);
    if (is_sorted(tabElems,ARRAY_SIZE,sizeof(TElement),TElement_Compare)) {
        printf("Le tableau est deja trié!\n");
    } else {
        printf("Le tableau n'est pas trié!\n");
        #ifdef SELECTION
        printf("Tri du tableau avec le tri selection.\n");
        selection_sort(tabElems,ARRAY_SIZE,sizeof(TElement),TElement_Compare);
        #elif INSERTION
        printf("Tri du tableau avec le tri insertion.\n");
        insertion_sort(tabElems,ARRAY_SIZE,sizeof(TElement),TElement_Compare);
        #elif BUBBLE
        printf("Tri du tableau avec le tri bulles.\n");
        bubble_sort(tabElems,ARRAY_SIZE,sizeof(TElement),TElement_Compare);
        #elif MERGE
        printf("Tri du tableau avec le tri fusion.\n");
        merge_sort(tabElems,ARRAY_SIZE,sizeof(TElement),TElement_Compare);
        #elif QUICK
        printf("Tri du tableau avec le tri rapide.\n");
        quick_sort(tabElems,ARRAY_SIZE,sizeof(TElement),TElement_Compare);
        #endif
        displayTab(tabElems,ARRAY_SIZE,sizeof(TElement),TElement_Display);
        if (is_sorted(tabElems,ARRAY_SIZE,sizeof(TElement),TElement_Compare)) {
            printf("Le tableau a été trié!\n");
        } else {
            printf("Le tableau n'a pas été trié!\n");
        }
    }
    free(tabElems);
}
