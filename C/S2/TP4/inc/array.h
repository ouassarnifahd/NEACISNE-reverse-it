#ifndef _ARRAY_
#define _ARRAY_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ARRAY_SIZE 10

void displayTab(void *tabElems,
                size_t numElems,
                size_t sizeElem,
                void (*display)(const void *));

void* initRandomTab(size_t numElems,
                    const void *pMin,
                    const void *pMax,
                    size_t sizeElem,
                    void (*random)(void *, const void *, const void *));

#endif /* end of include guard : _ARRAY_ */
