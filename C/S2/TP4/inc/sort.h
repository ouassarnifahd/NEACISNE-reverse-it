#ifndef _SORT_
#define _SORT_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#ifdef SELECTION

void sort(void *tabElems,
          size_t numElems,
          size_t sizeElem,
          int (*compare)(const void *, const void *));

#elif INSERTION

void sort(void *tabElems,
          size_t numElems,
          size_t sizeElem,
          int (*compare)(const void *, const void *));

#elif BUBBLES

void sort(void *tabElems,
          size_t numElems,
          size_t sizeElem,
          int (*compare)(const void *, const void *));

#elif MERGE

void sort(void *tabElems,
          size_t numElems,
          size_t sizeElem,
          int (*compare)(const void *, const void *));

#elif QUICK

void sort(void *tabElems,
          size_t numElems,
          size_t sizeElem,
          int (*compare)(const void *, const void *));

#endif

bool is_sorted(void *tabElems,
               size_t numElems,
               size_t sizeElem,
               int (*compare)(const void *, const void *));

bool swap(void *pa,
          void *pb,
          size_t sizeElem);

#endif /* end of include guard : _SORT_ */
