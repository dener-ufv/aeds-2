#include "list.h"

typedef struct list_node_t * Node;

struct list_node_t {
    TreePtr info;
    Node next, prev;
};

static Node node_new(TreePtr val, Node prev, Node next) {
    Node new = (Node) malloc(sizeof *new);
    new->info = val;
    new->prev = prev;
    new->next = next;
    return new;
} 

void list_init(List *list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void list_push_front(List *list, TreePtr tree) {
    Node new = node_new(tree, NULL, list->head);
    if(list->tail == NULL) list->tail = new;
    if(list->head) list->head->prev = new;
    list->head = new;
    list->size++;
}

void list_push_back(List *list, TreePtr tree) {
    Node new = node_new(tree, list->tail, NULL);
    if(list->head == NULL) list->head = new;
    if(list->tail) list->tail->next = new;
    list->tail = new;
    list->size++;
}

void list_pop_front(List *list) {
    if(list->head == NULL) return;
    Node rem = list->head;
    list->head = list->head->next;
    if(list->head) list->head->prev = NULL;
    else list->tail = NULL;
    free(rem);
    list->size--;
}

void list_pop_back(List *list) {
    if(list->tail == NULL) return;
    Node rem = list->tail;
    list->tail = list->tail->prev;
    if(list->tail) list->tail->next = NULL;
    else list->head = NULL;
    free(rem);
    list->size--;
}

int list_get_size(List list) {
    return list.size;
}

TreePtr list_get_front(List list) {
    return list.head->info;
}

TreePtr list_get_back(List list) {
    return list.tail->info;
}
