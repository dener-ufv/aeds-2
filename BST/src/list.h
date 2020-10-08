#ifndef __LIST_H__
#define __LIST_H__

#include "tree.h"
#include <stdlib.h>

typedef struct list_t {
    struct list_node_t *head, *tail;
    int size;
} List;

void list_init(List *list);
void list_push_front(List *list, TreePtr tree);
void list_push_back(List *list, TreePtr tree);
void list_pop_front(List *list);
void list_pop_back(List *list);

int list_get_size(List list);
TreePtr list_get_front(List list);
TreePtr list_get_back(List list);

#endif
