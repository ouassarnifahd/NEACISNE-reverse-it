/** @file main.h
*   @brief Ficher source de la fonction main.
*/

#include <element.h>
#include <array.h>
#include <sort.h>

int main(int argc, char const *argv[]){
    TElement ElementMin, ElementMax;
    if (argc == 3) {
        sscanf(argv[1],FORMATREAD,&ElementMin);
        sscanf(argv[2],FORMATREAD,&ElementMax);
    } else {
        printf("usage: %s min max\n\n", argv[0]);
        ElementMin = SHRT_MIN;
        ElementMax = SHRT_MAX;
    }
    #ifdef ELEM_SHORT
    srand(time(NULL));
    #elif ELEM_LONG
    srand(time(NULL));
    #elif ELEM_REAL
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
