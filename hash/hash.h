#ifndef __HASH_H__
#define __HASH_H__

typedef struct hash Hash;

struct hash {
    char **arr;
    int size;
};

void hashInit(Hash *hash, int size);
void hashDelete(Hash *hash);

int  hashFind(Hash hash, char str[]);
void hashInsert(Hash *hash, char str[]);

#endif
