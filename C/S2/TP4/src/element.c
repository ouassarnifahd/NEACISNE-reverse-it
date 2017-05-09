#include "../inc/element.h"

void TElement_Display(const void *pElement){
    printf(FORMAT, *(PTElement)pElement);
}

int TElement_Compare(const void *p1,const void *p2){
    return (*(PTElement)p1 > *(PTElement)p2)? +1 :
           (*(PTElement)p1 < *(PTElement)p2)? -1 : 0;
}

void TElement_Random(void *pVal, const void *pMin, const void *pMax){
    #if defined ELEM_SHORT || defined ELEM_LONG
    *(PTElement)pVal = *(PTElement)pMin + rand() % (*(PTElement)pMax - *(PTElement)pMin);
    #elif ELEM_REAL
    *(PTElement)pVal = *(PTElement)pMin + /* FLOAT RANDOM IN [0,1] */ drand48() * (*(PTElement)pMax - *(PTElement)pMin);
    #endif
}

#ifdef DEBUG
int main(int argc, char const *argv[]) {
    TElement MyElementMin=0, MyElementMax=0, RandElement=0;
    if (argc == 3) {
        sscanf(argv[1],FORMATREAD,&MyElementMin);
        sscanf(argv[2],FORMATREAD,&MyElementMax);
    } else {
        printf("Missing arguments!\n");
        return 0;
    }
    printf("Elements: ");
    TElement_Display(&MyElementMin);
    printf(" ");
    TElement_Display(&MyElementMax);
    printf("\nComparaison: %d\n", TElement_Compare(&MyElementMin,&MyElementMax));
    if(TElement_Compare(&MyElementMin,&MyElementMax)>0){
        TElement tmp=MyElementMin;
        MyElementMin=MyElementMax;
        MyElementMax=tmp;
    }
    #if defined ELEM_SHORT || defined ELEM_LONG
    srand(time(NULL));
    #elif ELEM_REAL
    srand48(time(NULL)); // drand48(); FLOAT RANDOM in [0,1]
    #endif
    TElement_Random(&RandElement,&MyElementMin,&MyElementMax);
    printf("RandElement: ");
    TElement_Display(&RandElement);
    printf("\n");
    TElement_Random(&RandElement,&MyElementMin,&MyElementMax);
    printf("RandElement: ");
    TElement_Display(&RandElement);
    printf("\n");
    TElement_Random(&RandElement,&MyElementMin,&MyElementMax);
    printf("RandElement: ");
    TElement_Display(&RandElement);
    printf("\n");
    return 0;
}
#endif
