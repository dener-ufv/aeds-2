#ifndef __PATRICIA_H__
#define __PATRICIA_H__

#include <stdlib.h>
#include "int.h"

typedef struct patricia_t * Patricia;

void patricia_init(Patricia *root);
void patricia_insert(Patricia *root, int value);

Patricia patricia_get_left_node(Patricia root);
Patricia patricia_get_right_node(Patricia root);
int      patricia_get_info(Patricia root);
int      patricia_is_leaf_node(Patricia root);

#endif
