/** @file sort.c
*   @brief Ficher source contenant les fonctions de tri pour des tableaux génériques.
*/

#include <sort.h>

#ifdef DEBUG
#include <array.h>
#include <element.h>
#endif

void selection_sort(void *tabElems, size_t numElems, size_t sizeElem, int (*compare)(const void *, const void *)){
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
        }
    }
    free(selectedElem);
}

void insertion_sort(void *tabElems, size_t numElems, size_t sizeElem, int (*compare)(const void *, const void *)){
    size_t Index, backIndex;
    void *elementToInsert = malloc(sizeElem);
    for(Index = 1; Index < numElems; Index++){
        if(compare((char*)tabElems + (Index - 1) * sizeElem , (char*)tabElems + Index * sizeElem) > 0){
            memcpy(elementToInsert, (char*)tabElems + Index * sizeElem, sizeElem);
            for(backIndex = Index; backIndex > 0 && compare((char*)tabElems + (backIndex - 1) * sizeElem, elementToInsert) > 0; backIndex--){
                memcpy((char*)tabElems + backIndex * sizeElem, (char*)tabElems + (backIndex - 1) * sizeElem, sizeElem);
            }
            memcpy((char*)tabElems + backIndex * sizeElem, elementToInsert, sizeElem);
        }
    }
    free(elementToInsert);
}

void bubble_sort(void *tabElems, size_t numElems, size_t sizeElem, int (*compare)(const void *, const void *)){
    bool sortDone = 0;
    size_t Index, subSize;
    for(subSize = numElems; subSize > 0 && !sortDone; subSize--){
        sortDone = 1;
        for(Index = 1; Index < subSize; Index++){
            if(compare((char*)tabElems + (Index - 1)* sizeElem, (char*)tabElems + Index * sizeElem) > 0){
                sortDone = 0;
                swap((char*)tabElems + (Index - 1)* sizeElem, (char*)tabElems + Index * sizeElem, sizeElem);
            }
        }
    }
}

void merge_sort(void *tabElems, size_t numElems, size_t sizeElem, int (*compare)(const void *, const void *)){
    if (1 < numElems && numElems <= MIN_SORT){
        insertion_sort((char *)tabElems, numElems, sizeElem, compare);
        return ;
    }
    size_t rightSize = numElems / 2, leftSize = numElems - rightSize;
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
}

// BUG /!\ fonction instable.
void quick_sort(void *tabElems, size_t numElems, size_t sizeElem, int (*compare)(const void *, const void *)){
    if (numElems <= MIN_SORT){
        if(numElems > 1) insertion_sort(tabElems, numElems, sizeElem, compare);
        return ;
    }
    //char *newTab = (char *)tabElems;
    void *pivot = (char *)tabElems + (numElems - 1) * sizeElem;
    size_t leftIndex = 0, rightIndex = numElems - 2;
    // swap((char *)tabElems + ((numElems-1)/2) * sizeElem, pivot, sizeElem);
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
    memcpy((char *)tabElems + (numElems-1) * sizeElem, (char *)tabElems + leftIndex * sizeElem, sizeElem);
    memcpy((char *)tabElems + leftIndex * sizeElem, pivot, sizeElem);
    if (leftIndex > 1)
        quick_sort(tabElems, leftIndex, sizeElem, compare);
    if (numElems > leftIndex + 2)
        quick_sort((char *)tabElems + (leftIndex + 1) * sizeElem, numElems - leftIndex - 1, sizeElem, compare);
}

bool is_sorted(void *tabElems, size_t numElems, size_t sizeElem, int (*compare)(const void *, const void *)){
    bool sorted = 1;
    size_t Index;
    for (Index = 0; Index < numElems - 1 && sorted; Index++) {
        if (compare((char*)tabElems + Index * sizeElem, (char*)tabElems + (Index + 1) * sizeElem) > 0) {
            sorted = 0;
        }
    }
    return sorted;
}

bool swap(void *pa, void *pb, size_t sizeElem){
    void* tmp = malloc(sizeElem);
    bool test1=0, test2=0, test3=0;
    test1 = memcpy(tmp,pb,sizeElem);
    test2 = memcpy(pb,pa,sizeElem);
    test3 = memcpy(pa,tmp,sizeElem);
    free(tmp);
    return test1 & test2 & test3;
}

double eval_sort(const void *inTab, size_t numElems, size_t sizeElem, int(*compare)(const void *, const void *), void(*fsort)(void *, size_t, size_t, int(*compare)(const void *, const void *))){
    clock_t start, end;
    double total;
    size_t i;
    void *tabElems = malloc(numElems * sizeElem);
    if(!tabElems) return 0;
    for(i=0; i<numElems; i++)
        memcpy((char*)tabElems + i * sizeElem, (char*)inTab + i * sizeElem, sizeElem);
    start = clock();
    fsort(tabElems, numElems, sizeElem, compare);
    end = clock();
    total = ((double)end - (double)start)/(double)CLOCKS_PER_SEC;
    if(!is_sorted(tabElems, numElems, sizeElem, compare)) total = 0;
    free(tabElems);
    return total;
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
    printf("numElems %lu\n",(size_t)ARRAY_SIZE);
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
    #ifdef SELECTION
    double sortTime = eval_sort(tabElems,ARRAY_SIZE,sizeof(TElement),TElement_Compare, selection_sort);
    #elif INSERTION
    double sortTime = eval_sort(tabElems,ARRAY_SIZE,sizeof(TElement),TElement_Compare, insertion_sort);
    #elif BUBBLE
    double sortTime = eval_sort(tabElems,ARRAY_SIZE,sizeof(TElement),TElement_Compare, bubble_sort);
    #elif MERGE
    double sortTime = eval_sort(tabElems,ARRAY_SIZE,sizeof(TElement),TElement_Compare, merge_sort);
    #elif QUICK
    double sortTime = eval_sort(tabElems,ARRAY_SIZE,sizeof(TElement),TElement_Compare, quick_sort);
    #endif
    printf("sortTime = %lf\n", sortTime);
    return 0;
}
#endif
