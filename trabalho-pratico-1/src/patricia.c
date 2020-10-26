/*
  Grupo Divididos
  3869 - Fábio Trindade Ramos
  3872 - Dener Vieira Ribeiro
  2665 - Lucas Takeshi Moreira Chang
  3889 - Igor de Melo Alves
*/

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

static int insertI(Patricia *root, Word word, Benchmark *bench) {
    Patricia *it, ex, in;
    int dif = 0;
    int left=0;

    benchmarkSumComparations(bench,1);
    // Aloca o nó gerado
    if(*root == NULL) {
        benchmarkSumMemory(bench,sizeof(struct patricia_node) + wordGetLength(word) );
        *root = nodeAllocExt(word);
        return 1;
    }

    it = root;

    benchmarkSumComparations(bench,1);
    //Procura a palavra que possui maior prefixo comum com a palavra a ser inserida
    while((*it)->pos != LEAF) {
        benchmarkSumComparations(bench,2);
        if(wordGetCharAt(word, (*it)->pos) <= (*it)->c)
            it = &(*it)->left;
        else
            it = &(*it)->right;
    }

    benchmarkSumComparations(bench,1);
    //Procura a primeira letra diferente entre duas palavras
    while(  dif <= wordGetLength(word) &&
            dif <= wordGetLength((*it)->info) &&
            wordGetCharAt(word, dif) == wordGetCharAt((*it)->info, dif)){
              benchmarkSumComparations(bench,1);
              dif++;
            }

    benchmarkSumComparations(bench,1);
    //Verifica se as palavras são iguais
    if(dif > wordGetLength(word) || dif > wordGetLength((*it)->info)) return 0;


    benchmarkSumMemory(bench,sizeof(struct patricia_node) + wordGetLength(word) );
    ex = nodeAllocExt(word);

    benchmarkSumComparations(bench,1);
    //Verifica se insere a esquerda ou a direita do nó
    if(wordGetCharAt(word, dif) < wordGetCharAt((*it)->info, dif)) {
        left = 1;
        benchmarkSumMemory(bench,sizeof(struct patricia_node) + wordGetLength(word) );
        in = nodeAllocInt(dif, wordGetCharAt(word, dif), ex, NULL);
    } else {
        left = 0;
        benchmarkSumMemory(bench,sizeof(struct patricia_node) + wordGetLength(word) );
        in = nodeAllocInt(dif, wordGetCharAt((*it)->info, dif), NULL, ex);
    }


    it = root;

    benchmarkSumComparations(bench,1);
    //Procura onde o nó gerado deve ser inserido
    while((*it)->pos <= dif && (*it)->pos != LEAF) {
        benchmarkSumComparations(bench,2);
        if(wordGetCharAt(word, (*it)->pos) <= (*it)->c)
            it = &(*it)->left;
        else
            it = &(*it)->right;
    }

    benchmarkSumComparations(bench,1);
    //Insere na esquerda ou direita
    if(left) {
        in->right = *it;
    } else {
        in->left = *it;
    }

    *it = in;

    return 1;
}

static int findI(Patricia *root, Word word, Benchmark *bench) {
    if(*root == NULL) return 0;
    Patricia it = *root;
    while(it->pos != LEAF) {
        if(wordGetCharAt(word, it->pos) <= it->c) it = it->left;
        else it = it->right;
        
    }
    return wordEquals(it->info, word);
}

static void deleteI(Patricia *root) {
    if(*root == NULL) return;
    deleteI(&(*root)->left);
    deleteI(&(*root)->right);
    if((*root)->pos == LEAF) wordDelete(&(*root)->info);
    free(*root);
    *root = NULL;
}

void patriciaInit(Patricia *root) {
    *root = NULL;
}

int  patriciaInsert(Patricia *root, Word word, Benchmark *bench) {
    return insertI(root, word, bench);
}

int  patriciaFind(Patricia *root, Word word, Benchmark *bench) {
    return findI(root, word, bench);
}

void patriciaDelete(Patricia *root) {
    deleteI(root);
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
