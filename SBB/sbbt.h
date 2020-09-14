#ifndef __SBBT_H__
#define __SBBT_H__

#include <stdlib.h>

typedef struct sbbt_t * Sbbt;

void sbbt_init(Sbbt *root);
void sbbt_insert(Sbbt *root, int val);

Sbbt sbbt_get_left_node(Sbbt root);
Sbbt sbbt_get_right_node(Sbbt root);
int  sbbt_get_info(Sbbt root);

#endif
