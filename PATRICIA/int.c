#include "int.h"


int *new_int(int value) {
    int *new = (int*) malloc(sizeof *new);
    *new = value;
    return new;
}
