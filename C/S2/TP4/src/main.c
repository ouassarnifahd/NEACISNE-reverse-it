#include "../inc/element.h"
#include "../inc/array.h"
#include "../inc/sort.h"

int main(int argc, char const *argv[]){
    #ifdef ELEM_SHORT
    TElement ElementMin = SHRT_MIN, ElementMax = SHRT_MAX;
    srand(time(NULL));
    #elif ELEM_LONG
    TElement ElementMin = LONG_MIN, ElementMax = LONG_MAX;
    srand(time(NULL));
    #elif ELEM_REAL
    TElement ElementMin = -DBL_MAX, ElementMax = DBL_MAX;
    srand48(time(NULL));
    #endif
    printf("Initialisation du tableau aléatoire entre ");
    TElement_Display(&ElementMin);
    printf(" et ");
    TElement_Display(&ElementMax);
    printf(":\n");
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
