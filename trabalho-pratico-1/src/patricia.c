#include "includes/patricia.h"
#include <stdlib.h>
#include <string.h>

#define LEAF -1

struct patricia_node {
    Word info;
    int pos;
    char c;
    Patricia left, right;
};

static Patricia nodeAllocInt(int pos, int c, Patricia l, Patricia r) {
    Patricia new = (Patricia) malloc(sizeof *new);
    new->pos = pos;
    new->c = c;
    new->left = l;
    new->right = r;
    new->info = NULL;
    return new;
}

static Patricia nodeAllocExt(Word word) {
    Patricia new = (Patricia) malloc(sizeof *new);
    wordInit(&new->info);
    wordSetString(&new->info, wordGetString(word));
    new->pos = LEAF;
    new->left = NULL;
    new->right = NULL;
    return new;
}

static int insertI(Patricia *root, Word word, Benchmark *banch) {
    Patricia *it, ex, in;
    int dif = 0;
    int left=0;

    if(*root == NULL) {
        *root = nodeAllocExt(word);
        return 1;
    }

    it = root;
    while((*it)->pos != LEAF) {
        if(wordGetCharAt(word, (*it)->pos) <= (*it)->c)
            it = &(*it)->left;
        else
            it = &(*it)->right;
    }

    while(  dif <= wordGetLength(word) &&
            dif <= wordGetLength((*it)->info) &&
            wordGetCharAt(word, dif) == wordGetCharAt((*it)->info, dif)) 
                dif++;

    if(dif > wordGetLength(word) || dif > wordGetLength((*it)->info)) return 0;

    ex = nodeAllocExt(word);
    if(wordGetCharAt(word, dif) < wordGetCharAt((*it)->info, dif)) {
        left = 1;
        in = nodeAllocInt(dif, wordGetCharAt(word, dif), ex, NULL);
    } else {
        left = 0;
        in = nodeAllocInt(dif, wordGetCharAt((*it)->info, dif), NULL, ex);
    }

    it = root;
    while((*it)->pos <= dif && (*it)->pos != LEAF) {
        if(wordGetCharAt(word, (*it)->pos) <= (*it)->c)
            it = &(*it)->left;
        else
            it = &(*it)->right;
    }

    if(left) {
        in->right = *it;
    } else {
        in->left = *it;
    }

    *it = in;

    return 1;
}

void patriciaInit(Patricia *root) {
    *root = NULL;
}

int  patriciaInsert(Patricia *root, Word word, Benchmark *banch) {
    insertI(root, word, NULL);
}

int  patriciaFind(Patricia *root, Word word, Benchmark *banch) {
    // to be implemented
}

Patricia patriciaGetLeft(Patricia root) {
    return root->left;
}

Patricia patriciaGetRight(Patricia root) {
    return root->right;
}

int      patriciaIsLeaf(Patricia root) {
    return root->pos == LEAF;
}

Word     patriciaGetWord(Patricia root) {
    return root->info;
}
