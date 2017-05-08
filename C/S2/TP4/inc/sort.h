#ifndef _SORT_
#define _SORT_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void selection_sort(void *tabElems,
          size_t numElems,
          size_t sizeElem,
          int (*compare)(const void *, const void *));

void insertion_sort(void *tabElems,
          size_t numElems,
          size_t sizeElem,
          int (*compare)(const void *, const void *));

void bubble_sort(void *tabElems,
          size_t numElems,
          size_t sizeElem,
          int (*compare)(const void *, const void *));

void merge_sort(void *tabElems,
          size_t numElems,
          size_t sizeElem,
          int (*compare)(const void *, const void *));

void quick_sort(void *tabElems,
          size_t numElems,
          size_t sizeElem,
          int (*compare)(const void *, const void *));

bool is_sorted(void *tabElems,
               size_t numElems,
               size_t sizeElem,
               int (*compare)(const void *, const void *));

bool swap(void *pa,
          void *pb,
          size_t sizeElem);

#endif /* end of include guard : _SORT_ */
