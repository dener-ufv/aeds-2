#ifndef __TRIE_H__
#define __TRIE_H__

#include <stdlib.h>
#include <stdbool.h>

typedef struct trie_t * Trie;

void trie_init(Trie *root);
void trie_insert_string(Trie *root, char *str, int len);
int  trie_is_end_of_string(Trie root);
Trie trie_get_ith_son(Trie root, int i);
int  trie_get_max_sons(void);

#endif
