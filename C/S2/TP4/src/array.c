#include "../inc/array.h"

void displayTab(void *tabElems, size_t numElems, size_t sizeElem, void (*display)(const void *)){
    while(numElems--){
        display(tabElems);
        tabElems = (char*)tabElems + sizeElem;
    }
}

void* initRandomTab(size_t numElems, const void *pMin, const void *pMax, size_t sizeElem, void (*random)(void *, const void *, const void *)){
    size_t i;
    void *randptr = NULL;
    void *arr = malloc(numElems * sizeElem);
    for(i=0; i<numElems; i++){
        random(randptr, pMin, pMax);
        memcpy((char*)arr + i * sizeElem, randptr, sizeElem);
    }
    return arr;
}
