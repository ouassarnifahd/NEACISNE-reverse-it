#include "../inc/sort.h"

#ifdef DEBUG
#include "../inc/array.h"
#include "../inc/element.h"

int swaps = 0;
#endif

void selection_sort(void *tabElems, size_t numElems, size_t sizeElem, int (*compare)(const void *, const void *)){
    #ifdef DEBUGED
    printf("BEGIN selection_sort: IN ");
    displayTab(tabElems, numElems, sizeElem, TElement_Display);
    #endif
    size_t Offset, Index, selectedIndex;
    void *selectedElem = malloc(sizeElem);
    for(Offset = 0; Offset < numElems-1 ; Offset++){
        memcpy(selectedElem, (char*)tabElems + Offset * sizeElem, sizeElem);
        selectedIndex = Offset;
        for(Index = Offset + 1; Index < numElems; Index++){
            if(compare((char*)tabElems + Index * sizeElem, selectedElem) < 0){
                memcpy(selectedElem, (char*)tabElems + Index * sizeElem, sizeElem);
                selectedIndex = Index;
            }
        }
        if(selectedIndex != Offset){
            swap((char*)tabElems + Offset * sizeElem, (char*)tabElems + selectedIndex * sizeElem, sizeElem);
            #ifdef DEBUGEG
            displayTab(tabElems, numElems, sizeElem, TElement_Display);
            #endif
        }
    }
    free(selectedElem);
    #ifdef DEBUGED
    printf("END selection_sort: OUT ");
    displayTab(tabElems, numElems, sizeElem, TElement_Display);
    #endif
}

void insertion_sort(void *tabElems, size_t numElems, size_t sizeElem, int (*compare)(const void *, const void *)){
    #ifdef DEBUGED
    printf("BEGIN insertion_sort: Size %zu \nIN  ", numElems);
    displayTab(tabElems, numElems, sizeElem, TElement_Display);
    #endif
    size_t Index, backIndex;
    void *elementToInsert = malloc(sizeElem);
    for(Index = 1; Index < numElems; Index++){
        if(compare((char*)tabElems + (Index - 1) * sizeElem , (char*)tabElems + Index * sizeElem) > 0){
            memcpy(elementToInsert, (char*)tabElems + Index * sizeElem, sizeElem);
            for(backIndex = Index; backIndex > 0 && compare((char*)tabElems + (backIndex - 1) * sizeElem, elementToInsert) > 0; backIndex--){
                memcpy((char*)tabElems + backIndex * sizeElem, (char*)tabElems + (backIndex - 1) * sizeElem, sizeElem);
                #ifdef DEBUGEG
                displayTab(tabElems, numElems, sizeElem, TElement_Display);
                #endif
            }
            memcpy((char*)tabElems + backIndex * sizeElem, elementToInsert, sizeElem);
        }
    }
    free(elementToInsert);
    #ifdef DEBUGED
    printf("insertion_sort: Size %zu \n", numElems);
    printf("OUT ");
    displayTab(tabElems, numElems, sizeElem, TElement_Display);
    #endif
}

void bubble_sort(void *tabElems, size_t numElems, size_t sizeElem, int (*compare)(const void *, const void *)){
    #ifdef DEBUGED
    printf("BEGIN bubble_sort: IN ");
    displayTab(tabElems, numElems, sizeElem, TElement_Display);
    #endif
    bool sortDone = 0;
    size_t Index, subSize;
    for(subSize = numElems; subSize > 0 && !sortDone; subSize--){
        sortDone = 1;
        for(Index = 1; Index < subSize; Index++){
            if(compare((char*)tabElems + (Index - 1)* sizeElem, (char*)tabElems + Index * sizeElem) > 0){
                sortDone = 0;
                swap((char*)tabElems + (Index - 1)* sizeElem, (char*)tabElems + Index * sizeElem, sizeElem);
                #ifdef DEBUGEG
                displayTab(tabElems, numElems, sizeElem, TElement_Display);
                #endif
            }
        }
    }
    #ifdef DEBUGED
    printf("END bubble_sort: OUT ");
    displayTab(tabElems, numElems, sizeElem, TElement_Display);
    #endif
}

void merge_sort(void *tabElems, size_t numElems, size_t sizeElem, int (*compare)(const void *, const void *)){
    if (1 < numElems && numElems <= MIN_SORT){
        insertion_sort((char *)tabElems, numElems, sizeElem, compare);
        return ;
    }
    size_t rightSize = numElems / 2, leftSize = numElems - rightSize;
    #ifdef DEBUGED
    printf("REC_BEGIN merge_sort: %zu = %zu + %zu \nIN  ", numElems, rightSize, leftSize);
    displayTab((char *)tabElems, numElems, sizeElem, TElement_Display);
    #endif
    if (leftSize > 1) merge_sort((char *)tabElems, leftSize, sizeElem, compare);
    if (rightSize > 1) merge_sort((char *)tabElems + leftSize * sizeElem, rightSize, sizeElem, compare);
    void *mergeTab = malloc(numElems * sizeElem);
    size_t Index, leftIndex = 0, rightIndex = 0;
    for (Index = 0; Index < numElems; Index++){
        if (compare((char *)tabElems + leftIndex * sizeElem, (char *)tabElems + (leftSize + rightIndex) * sizeElem) > 0)
            memcpy((char *)mergeTab + Index * sizeElem, (char *)tabElems + (leftSize + (rightIndex++)) * sizeElem, sizeElem);
        else
            memcpy((char *)mergeTab + Index * sizeElem, (char *)tabElems + (leftIndex++) * sizeElem, sizeElem);
        if (!(rightIndex - rightSize))
            while (leftIndex < leftSize)
                memcpy((char *)mergeTab + (++Index) * sizeElem, (char *)tabElems + (leftIndex++) * sizeElem, sizeElem);
        else if (!(leftIndex - leftSize))
            while (rightIndex < rightSize)
                memcpy((char *)mergeTab + (++Index) * sizeElem, (char *)tabElems + (leftSize + (rightIndex++)) * sizeElem, sizeElem);
    }
    for (Index = 0; Index < numElems; Index++)
        memcpy((char *)tabElems + Index * sizeElem, (char *)mergeTab + Index * sizeElem, sizeElem);
    free(mergeTab);
    #ifdef DEBUGED
    printf("REC_END merge_sort: %zu = %zu + %zu \nOUT ", numElems, rightSize, leftSize);
    displayTab((char *)tabElems, numElems, sizeElem, TElement_Display);
    #endif
}

// BUG /!\ fonction instable.
void quick_sort(void *tabElems, size_t numElems, size_t sizeElem, int (*compare)(const void *, const void *)){
    if (1 < numElems && numElems <= MIN_SORT){
        insertion_sort(tabElems, numElems, sizeElem, compare);
        return ;
    }
    //char *newTab = (char *)tabElems;
    void *pivot = (char *)tabElems + (numElems - 1) * sizeElem;
    size_t leftIndex = 0, rightIndex = numElems - 2;
    #ifdef DEBUG
    printf("REC_BEGIN quick_sort: Size %zu Pivot ", numElems);
    TElement_Display(pivot);
    printf("\nIN  ");
    displayTab(tabElems, numElems, sizeElem, TElement_Display);
    #endif
    while (leftIndex <= rightIndex){
        while (leftIndex <= rightIndex && compare((char *)tabElems + leftIndex * sizeElem, pivot) < 0)   leftIndex++;
        while (leftIndex <= rightIndex && compare((char *)tabElems + rightIndex * sizeElem, pivot) >= 0) rightIndex--;
        if (leftIndex < rightIndex)
            swap((char *)tabElems + (leftIndex++) * sizeElem, (char *)tabElems + (rightIndex--) * sizeElem, sizeElem);
    }
    swap((char *)tabElems + leftIndex * sizeElem, pivot, sizeElem);
    if (leftIndex > 1)
        quick_sort(tabElems, leftIndex, sizeElem, compare);
    if (numElems > leftIndex + 2)
        quick_sort((char *)tabElems + (leftIndex + 1) * sizeElem, numElems - leftIndex - 1, sizeElem, compare);
}

bool is_sorted(void *tabElems, size_t numElems, size_t sizeElem, int (*compare)(const void *, const void *)){
    bool sorted = 1;
    size_t Index;
    for (Index = 0; Index < numElems - 1 && sorted; Index++) {
        #ifdef DEBUGED
        TElement_Display((char*)tabElems + Index * sizeElem);
        printf(" & ");
        TElement_Display((char*)tabElems + (Index + 1) * sizeElem);
        printf(" = %d\n", compare((char*)tabElems + Index * sizeElem, (char*)tabElems + (Index + 1) * sizeElem));
        #endif
        if (compare((char*)tabElems + Index * sizeElem, (char*)tabElems + (Index + 1) * sizeElem) > 0) {
            sorted = 0;
        }
    }
    #ifdef DEBUG
    printf("Sorted ");
    if (sorted) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    #endif
    return sorted;
}

bool swap(void *pa, void *pb, size_t sizeElem){
    #ifdef DEBUGED
    printf("SWAP: ");
    TElement_Display(pa);
    printf(" <-> ");
    TElement_Display(pb);
    printf("\n");
    #endif
    void* tmp = malloc(sizeElem);
    bool test1=0, test2=0, test3=0;
    test1 = memcpy(tmp,pb,sizeElem);
    test2 = memcpy(pb,pa,sizeElem);
    test3 = memcpy(pa,tmp,sizeElem);
    free(tmp);
    #ifdef DEBUG
    test1 & test2 & test3 && ++swaps;
    #endif
    return test1 & test2 & test3;
}

#ifdef DEBUG
int main(int argc, char const *argv[]){
    TElement MyElementMin=0, MyElementMax=0;
    if (argc == 3) {
        sscanf(argv[1],FORMATREAD,&MyElementMin);
        sscanf(argv[2],FORMATREAD,&MyElementMax);
    } else {
        printf("Missing arguments!\n");
        return 0;
    }
    if(TElement_Compare(&MyElementMin,&MyElementMax)>0){
        TElement tmp=MyElementMin;
        MyElementMin=MyElementMax;
        MyElementMax=tmp;
    }
    printf("SizeElem %lu\n",sizeof(TElement));
    printf("Elements: Min=");
    TElement_Display(&MyElementMin);
    printf(" Max=");
    TElement_Display(&MyElementMax);
    printf("\n");
    #if defined ELEM_SHORT || defined ELEM_LONG
    srand(time(NULL));
    #elif ELEM_REAL
    srand48(time(NULL));
    #endif
    PTElement tabElems = initRandomTab(ARRAY_SIZE, &MyElementMin, &MyElementMax, sizeof(TElement), TElement_Random);
    printf("IN  ");
    displayTab(tabElems, ARRAY_SIZE, sizeof(TElement), TElement_Display);
    #ifdef SELECTION
    selection_sort(tabElems,ARRAY_SIZE,sizeof(TElement),TElement_Compare);
    printf("TOTAL SWAP: %d\n", swaps);
    #elif INSERTION
    insertion_sort(tabElems,ARRAY_SIZE,sizeof(TElement),TElement_Compare);
    #elif BUBBLE
    bubble_sort(tabElems,ARRAY_SIZE,sizeof(TElement),TElement_Compare);
    printf("TOTAL SWAP: %d\n", swaps);
    #elif MERGE
    merge_sort(tabElems,ARRAY_SIZE,sizeof(TElement),TElement_Compare);
    #elif QUICK
    quick_sort(tabElems,ARRAY_SIZE,sizeof(TElement),TElement_Compare);
    printf("TOTAL SWAP: %d\n", swaps);
    #endif
    printf("OUT ");
    displayTab(tabElems, ARRAY_SIZE, sizeof(TElement), TElement_Display);
    is_sorted(tabElems,ARRAY_SIZE,sizeof(TElement),TElement_Compare);
    return 0;
}
#endif
