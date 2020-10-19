#include "hash.h"
#include <stdlib.h>
#include <string.h>

static int hashCode(Hash hash, char str[]) {
    int n = strlen(str);
    int i, w=1, h=0;
    for(i=0; i<n; i++) {
        h += (str[i] * w) % hash.size;
        w = (w << 1) % hash.size;
    }
    return h;
}

void hashInit(Hash *hash, int size) {
    Hash new;
    new.arr = (char**) malloc(size * sizeof(char*));
    new.size = size;
    int i=0;
    for(i=0; i<size; i++) new.arr[i] = NULL;
    *hash = new;
}

void hashDelete(Hash *hash) {
    int i=0;
    for(i=0; i<hash->size; i++) {
        free(hash->arr[i]);
        hash->arr[i] = NULL;
    }
}

int hashFind(Hash hash, char str[]) {
    int h = hashCode(hash, str);
    int i=0, p;
    for(i=0; i < hash.size; i++) {
        p = (h+i)%hash.size;
        if(!hash.arr[p]) return 0;
        if(strcmp(hash.arr[p], str) == 0) return 1;
    }
    return 0;
}

void hashInsert(Hash *hash, char str[]) {
    int h = hashCode(*hash, str);
    int i=0;
    while(hash->arr[(h+i)%hash->size] != NULL && i<hash->size) i++;
    if(i >= hash->size) return;
    int pos = (h+i)%hash->size;
    int len = strlen(str);
    hash->arr[pos] = (char*) malloc((len+1) * sizeof(char));
    strcpy(hash->arr[pos], str);
}


