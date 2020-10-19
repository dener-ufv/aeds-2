#include "quicksort.h"
#include <stdbool.h>

#include <stdio.h>

static void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

static int* partition(int *beg, int *end) {
    int pivot = *(beg + (end-beg)/2);
    int *l = beg;
    int *r = end-1;
    while(true) {
        while(*l < pivot) l++;
        while(*r > pivot) r--;
        if(l >= r) break;
        swap(l, r);
        l++;
        r--;
    }
    return r;
}

void quickSort(int *beg, int *end) {
    if(beg == end) return;
    int *mid = partition(beg, end);
    quickSort(beg, mid);
    quickSort(mid+1, end);
}
