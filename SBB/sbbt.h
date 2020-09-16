#ifndef __SBBT_H__
#define __SBBT_H__

#include <stdlib.h>

typedef struct sbbt_t * Sbbt;

void sbbt_init(Sbbt *root);
void sbbt_insert(Sbbt *root, int val);
int  sbbt_find(Sbbt *root, int val);
void sbbt_remove(Sbbt *root, int val);

Sbbt sbbt_get_left_node(Sbbt root);
Sbbt sbbt_get_right_node(Sbbt root);
int  sbbt_get_info(Sbbt root);
int  sbbt_get_heigh(Sbbt root);

#endif
