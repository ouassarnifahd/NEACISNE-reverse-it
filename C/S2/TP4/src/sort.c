#include"../inc/sort.h"

void selection_sort(void *tabElems, size_t numElems, size_t sizeElem, int (*compare)(const void *, const void *)){
    size_t Offset, Index, selectedIndex;
    void *selectedElem = NULL;
    for(Offset = 0; Offset < numElems-1 ; Offset++){
        memcpy(selectedElem, (char*)tabElems + Offset * sizeElem, sizeElem);
        selectedIndex = Offset;
        for(Index = Offset + 1; Index < numElems; Index++){
            if(compare((char*)tabElems + Index * sizeElem, selectedElem) < 0){
                memcpy(selectedElem,(char*)tabElems + Index * sizeElem, sizeElem);
                selectedIndex = Index;
            }
        }
        if(selectedIndex != Offset)
            swap((char*)tabElems + Offset * sizeElem,(char*)tabElems + selectedIndex * sizeElem,sizeElem);
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
    void* tmp = NULL;
    bool test1=0, test2=0, test3=0;
    test1 = memcpy(tmp,pb,sizeElem);
    test2 = memcpy(pb,pa,sizeElem);
    test3 = memcpy(pa,tmp,sizeElem);
    return test1 & test2 & test3;
}
