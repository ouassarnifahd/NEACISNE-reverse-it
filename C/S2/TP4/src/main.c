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
    if (is_sorted(tabElems,ARRAY_SIZE,sizeof(TElement),TElement_Compare)) {
        printf("Le tableau est deja trié!\n");
        displayTab(tabElems,ARRAY_SIZE,sizeof(TElement),TElement_Display);
    } else {
        printf("Le tableau n'est pas trié!\n");
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
        if (is_sorted(tabElems,ARRAY_SIZE,sizeof(TElement),TElement_Compare)) {
            printf("Le tableau a été trié!\n");
        } else {
            printf("Le tableau n'a pas été trié!\n");
        }
        displayTab(tabElems,ARRAY_SIZE,sizeof(TElement),TElement_Display);
    }
    free(tabElems);
}
