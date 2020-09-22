#ifndef __TST_H__
#define __TST_H__

#include <stdlib.h>
#include <stdbool.h>

typedef struct tst_t * Tst;

void tst_init(Tst *root);
void tst_insert_string(Tst *root, char *str, int len);
char tst_get_char(Tst root);
int  tst_is_end_of_string(Tst root);
Tst  tst_get_left_node(Tst root);
Tst  tst_get_right_node(Tst root);
Tst  tst_get_middle_node(Tst root);

#endif
