#include <stdio.h>
#include <stdbool.h>
#include "quicksort.h"

void partition(int *begin, int *end, int *i, int *j, int linf, int lsup, int *buffer) {
    int *rl = begin;
    int *rr = end-1;
    int *wl = begin;
    int *wr = end-1;
    int bsize = 0;
    int left = 0;
    while(true) {
        
    }
}

int main() {

    int n, i;
    int v[100];

    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%d", &v[i]);

    quickSort(v, v+n);

    for(i=0; i<n; i++) printf("%d ", v[i]);
    printf("\n");

    return 0;
}
