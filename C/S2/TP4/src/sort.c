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
    size_t Index, backIndex;
    void *elementToInsert = NULL;
    for(Index = 1; Index < numElems; Index++){
        if(compare((char*)tabElems + Index * sizeElem - 1, (char*)tabElems + Index * sizeElem + 1) > 0){
            memcpy(elementToInsert,(char*)tabElems + Index * sizeElem, sizeElem);
            for(backIndex = Index; backIndex > 0 && compare((char*)tabElems + Index * sizeElem - 1,elementToInsert) > 0; backIndex--){
                memcpy((char*)tabElems + backIndex * sizeElem,(char*)tabElems + backIndex * sizeElem - 1, sizeElem);
            }
            memcpy((char*)tabElems + backIndex * sizeElem,elementToInsert, sizeElem);
        }
    }
}

void bubble_sort(void *tabElems, size_t numElems, size_t sizeElem, int (*compare)(const void *, const void *)){
    bool sortDone = 0;
    size_t Index, subSize;
    for(subSize = numElems; subSize > 0 && !sortDone; subSize--){
        sortDone = 1;
        for(Index = 1; Index < subSize; Index++){
            if(compare((char*)tabElems + Index * sizeElem - 1, (char*)tabElems + Index * sizeElem) > 0){
                sortDone = 0;
                swap((char*)tabElems + Index * sizeElem - 1, (char*)tabElems + Index * sizeElem, sizeElem);
            }
        }
    }
}

void merge_recursive(void *tabLeft, void *tabRight, size_t numElems, size_t sizeElem, int (*compare)(const void *, const void *)){

}

void merge_sort(void *tabElems, size_t numElems, size_t sizeElem, int (*compare)(const void *, const void *)){

}

void quick_sort(void *tabElems, size_t numElems, size_t sizeElem, int (*compare)(const void *, const void *)){
    if(numElems <= sizeElem){

    }
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

#ifdef DEBUG
int main(int argc, char const *argv[]) {
    /* code */
    return 0;
}
#endif
