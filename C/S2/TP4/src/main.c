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
    PTElement tabElts = initRandomTab(ARRAY_SIZE,&min,&max,sizeof(TElement),TElement_Random);
    displayTab(tabElts,ARRAY_SIZE,sizeof(TElement),TElement_Display);
    #ifdef SELECTION
    selection_sort(tabElts,ARRAY_SIZE,sizeof(TElement),TElement_Compare);
    #elif INSERTION
    insertion_sort(tabElts,ARRAY_SIZE,sizeof(TElement),TElement_Compare);
    #elif BUBBLE
    bubble_sort(tabElts,ARRAY_SIZE,sizeof(TElement),TElement_Compare);
    #elif MERGE
    merge_sort(tabElts,ARRAY_SIZE,sizeof(TElement),TElement_Compare);
    #elif QUICK
    quick_sort(tabElts,ARRAY_SIZE,sizeof(TElement),TElement_Compare);
    #endif
    displayTab(tabElts,ARRAY_SIZE,sizeof(TElement),TElement_Display);
}
