#include"../inc/sort.h"

void selection_sort(void *tabElems, size_t numElems, size_t sizeElem, int (*compare)(const void *, const void *)){
    size_t Offset, Index, selectedIndex;
    void *selectedElem = NULL, *tempElem = NULL;
    for(Offset = 0; Offset < numElems-1 ; Offset++){
        memcpy(selectedElem, (char*)tabElems + Offset * sizeElem, sizeElem);
        selectedIndex = Offset;
        for(Index = Offset + 1; Index < numElems; Index++){
            if(compare((char*)tabElems + Index * sizeElem, selectedElem) < 0){
                memcpy(selectedElem,(char*)tabElems + Index * sizeElem, sizeElem);
                selectedIndex = Index;
            }
        }
        if(selectedIndex != Offset){
            memcpy(tempElem, (char*)tabElems + Offset * sizeElem, sizeElem);
            memcpy((char*)tabElems + Offset * sizeElem, selectedElem, sizeElem);
            memcpy((char*)tabElems + selectedIndex * sizeElem, tempElem, sizeElem);
        }
    }
}

void insertion_sort(void *tabElems, size_t numElems, size_t sizeElem, int (*compare)(const void *, const void *)){

}

void bubble_sort(void *tabElems, size_t numElems, size_t sizeElem, int (*compare)(const void *, const void *)){

}

void merge_sort(void *tabElems, size_t numElems, size_t sizeElem, int (*compare)(const void *, const void *)){

}

void quick_sort(void *tabElems, size_t numElems, size_t sizeElem, int (*compare)(const void *, const void *)){

}

bool is_sorted(void *tabElems, size_t numElems, size_t sizeElem, int (*compare)(const void *, const void *)){
    return 0;
}

bool swap(void *pa, void *pb, size_t sizeElem){
    return 0;
}
