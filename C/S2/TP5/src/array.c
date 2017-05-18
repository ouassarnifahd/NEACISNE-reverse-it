#include "../inc/array.h"

#ifdef DEBUG
#include "../inc/element.h"
#endif

void displayTab(void *tabElems, size_t numElems, size_t sizeElem, void (*display)(const void *)){
    printf("[ ");
    while(numElems--){
        display(tabElems);
        printf(" ");
        tabElems = (char*)tabElems + sizeElem;
    }
    printf("]\n");
}

void* initRandomTab(size_t numElems, const void *pMin, const void *pMax, size_t sizeElem, void (*random)(void *, const void *, const void *)){
    size_t i;
    #if defined ELEM_SHORT || defined ELEM_LONG
    srand(time(NULL));
    #elif ELEM_REAL
    srand48(time(NULL));
    #endif
    void *randptr = malloc(sizeElem);
    void *randarr = malloc(numElems * sizeElem);
    if(!randarr) return NULL;
    for(i=0; i<numElems; i++){
        random(randptr, pMin, pMax);
        memcpy((char*)randarr + i * sizeElem, randptr, sizeElem);
    }
    free(randptr);
    return randarr;
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
    printf("SizeElem: %lu\n",sizeof(TElement));
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
    PTElement tabElement = initRandomTab(ARRAY_SIZE, &MyElementMin, &MyElementMax, sizeof(TElement), TElement_Random);
    printf("RandomTab=");
    displayTab(tabElement, ARRAY_SIZE, sizeof(TElement), TElement_Display);
    return 0;
}
#endif
