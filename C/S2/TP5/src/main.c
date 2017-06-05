/** @file main.h
*   @brief Ficher source de la fonction main.
*/

#include <element.h>
#include <array.h>
#include <sort.h>

#define COMMAND_LEN 1024

char* gplot(char* filename, double xvals[NUM_EVAL], double yvals[NUM_EVAL]){
    FILE * graph = fopen(filename,"w");
    int i;
    for (i=0; i < NUM_EVAL; i++)
        fprintf(graph, "%lf %lf \n", xvals[i], yvals[i]);
    fclose(graph);
    return filename;
}

void printnplot(const void *tabElems, char* tabtype){
    printf("Pour des donnees %s\n", tabtype);
    printf("Taille  Selection\tInsertion\tTri bulles\tTri fusion\tTri rapide\tqsort du C\n");
    size_t index = 0;
    double size[NUM_EVAL];
    size[0] = 100;
    double selectionTime[NUM_EVAL], insertionTime[NUM_EVAL], bubbleTime[NUM_EVAL], mergeTime[NUM_EVAL], quickTime[NUM_EVAL], qsortTime[NUM_EVAL];
    while(size[index] <= ARRAY_SIZE) {
        selectionTime[index] = eval_sort(tabElems, size[index], sizeof(TElement), TElement_Compare, selection_sort);
        insertionTime[index] = eval_sort(tabElems, size[index], sizeof(TElement), TElement_Compare, insertion_sort);
        bubbleTime[index] = eval_sort(tabElems, size[index], sizeof(TElement), TElement_Compare, bubble_sort);
        mergeTime[index] = eval_sort(tabElems, size[index], sizeof(TElement), TElement_Compare, merge_sort);
        quickTime[index] = 0;//eval_sort(tabElems, size[index], sizeof(TElement), TElement_Compare, quick_sort);
        qsortTime[index] = eval_sort(tabElems, size[index], sizeof(TElement), TElement_Compare, qsort);
        printf(" %5.0lf  %lfs\t%lfs\t%lfs\t%lfs\t%lfs\t%lfs\n", size[index], selectionTime[index], insertionTime[index], bubbleTime[index], mergeTime[index], quickTime[index], qsortTime[index]);
        size[index + 1] = size[index] * 2;
        index++;
    }
    char command[COMMAND_LEN];
    int indexWrite = snprintf(command, COMMAND_LEN, "gnuplot -p -e \"set title 'Donees %s'; set grid; set xlabel 'Taille'; set ylabel 'Temps (s)'; set logscale xy;", tabtype);
    indexWrite += snprintf(command + indexWrite, COMMAND_LEN - indexWrite," plot '%s' using 1:2 title 'Selection' with lines", gplot("selection.plt", size, selectionTime));
    indexWrite += snprintf(command + indexWrite, COMMAND_LEN - indexWrite,", '%s' using 1:2 title 'Insertion' with lines", gplot("insertion.plt", size, insertionTime));
    indexWrite += snprintf(command + indexWrite, COMMAND_LEN - indexWrite,", '%s' using 1:2 title 'Tri bulles' with lines", gplot("bubble.plt", size, bubbleTime));
    indexWrite += snprintf(command + indexWrite, COMMAND_LEN - indexWrite,", '%s' using 1:2 title 'Tri fusion' with lines", gplot("merge.plt", size, mergeTime));
    indexWrite += snprintf(command + indexWrite, COMMAND_LEN - indexWrite,", '%s' using 1:2 title 'Tri rapide' with lines", gplot("quick.plt", size, quickTime));
    indexWrite += snprintf(command + indexWrite, COMMAND_LEN - indexWrite,", '%s' using 1:2 title 'qsort du C' with lines\" && rm *.plt", gplot("qsort.plt", size, qsortTime));
    printf("Ploting this result with GNUPLOT.\n");
    system(command);
}

int TElement_Compare2(const void *p1, const void *p2){
    return (*(PTElement)p1 > *(PTElement)p2)? -1 :
           (*(PTElement)p1 < *(PTElement)p2)? +1 : 0;
}

int main(int argc, char const *argv[]){
    #ifdef ELEM_SHORT
    TElement ElementMin = SHRT_MIN, ElementMax = SHRT_MAX;
    srand(time(NULL));
    #elif ELEM_LONG
    TElement ElementMin = LONG_MIN, ElementMax = LONG_MAX;
    srand(time(NULL));
    #elif ELEM_REAL
    TElement ElementMin = -DBL_MAX, ElementMax = DBL_MAX;
    srand48(time(NULL));
    #endif
    PTElement inTab = initRandomTab(ARRAY_SIZE, &ElementMin, &ElementMax, sizeof(TElement), TElement_Random);
    printnplot(inTab,"aleatoires");
    qsort(inTab,ARRAY_SIZE,sizeElem,TElement_Compare);
    printnplot(inTab,"triees");
    qsort(inTab,ARRAY_SIZE,sizeElem,TElement_Compare2);
    printnplot(inTab,"inversees");
    free(inTab);
}
