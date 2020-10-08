#ifndef __PATRICIA_H__
#define __PATRICIA_H__

#include "banckmark.h"

typedef struct patricia_node * Patricia;

void patriciaInit(Patricia *root);
int  patriciaInsert(Patricia *root, char str[], Banchmark *banch);
int  patriciaFind(Patricia *root, char str[], Banchmark *banch);

#endif
