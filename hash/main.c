#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int main() {

    Hash map;
    hashInit(&map, 251);

    hashInsert(&map, "hello");
    hashInsert(&map, "world");

    char find[32];
    scanf("%s", find);

    printf("%s ", find);
    if(!hashFind(map, find)) {
        printf("NOT ");
    }
    printf("found in map\n");

    return 0;
}
