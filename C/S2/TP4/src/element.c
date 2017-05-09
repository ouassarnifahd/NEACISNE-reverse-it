#include "../inc/element.h"

void TElement_Display(const void *pElement){
    printf(FORMAT, *(PTElement)pElement);
}

int TElement_Compare(const void *p1,const void *p2){
    return (*(PTElement)p1 > *(PTElement)p2)? +1 :
           (*(PTElement)p1 < *(PTElement)p2)? -1 : 0;
}

void TElement_Random(void *pVal, const void *pMin, const void *pMax){
    srand(time(NULL));
    #if defined ELEM_SHORT || defined ELEM_LONG
    *(PTElement)pVal = *(PTElement)pMin + rand()%(*(PTElement)pMin - *(PTElement)pMax);
    #elif ELEM_REAL
    *(PTElement)pVal = *(PTElement)pMin + (rand()/(double)RAND_MAX) * (*(PTElement)pMin - *(PTElement)pMax);
    #endif
}

#ifdef DEBUG
int main(int argc, char const *argv[]) {
    /* code */
    return 0;
}
#endif
