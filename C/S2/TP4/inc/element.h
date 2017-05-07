#ifndef _ELEMENT_
#define _ELEMENT_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#ifdef ELEM_SHORT
    typedef short TElement;
    #define FORMAT "%hi"
#elif ELEM_LONG
    typedef long TElement;
    #define FORMAT "%li"
#elif ELEM_REAL
    typedef float TElement;
    #define FORMAT "%.2f"
#else
    typedef type TElement;
    #define FORMAT "%"
#endif

typedef TElement* PTElement;

void TElement_Display(const void *pElement);

int TElement_Compare(const void *p1, const void *p2);

void TElement_Random(void *pVal, const void *pMin, const void *pMax);

#endif /* end of include guard : _ELEMENT_ */
