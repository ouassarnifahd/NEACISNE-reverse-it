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
    PTElement inTab = initRandomTab(ARRAY_SIZE, &ElementMin, &ElementMax, sizeof(TElement), TElement_Random);
    printf("Taille  Selection\tInsertion\tTri bulles\tTri fusion\tTri rapide\tqsort du C\n");
    size_t size = 100;
    while(size <= ARRAY_SIZE) {
        double selectionTime = eval_sort(inTab, size, sizeof(TElement), TElement_Compare, selection_sort);
        double insertionTime = eval_sort(inTab, size, sizeof(TElement), TElement_Compare, insertion_sort);
        double bubbleTime = eval_sort(inTab, size, sizeof(TElement), TElement_Compare, bubble_sort);
        double mergeTime = eval_sort(inTab, size, sizeof(TElement), TElement_Compare, merge_sort);
        double quickTime = 0;//eval_sort(inTab, size, sizeof(TElement), TElement_Compare, quick_sort);
        double qsortTime = eval_sort(inTab, size, sizeof(TElement), TElement_Compare, qsort);
        printf(" %5zu  %2.6lf\t%2.6lf\t %2.6lf\t %2.6lf\t %2.6lf\t %2.6lf\n", size, selectionTime, insertionTime, bubbleTime, mergeTime, quickTime, qsortTime);
        size *= 2;
    }
    free(inTab);
}
