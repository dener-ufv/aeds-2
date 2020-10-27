/*
  Grupo Divididos
  3869 - Fábio Trindade Ramos
  3872 - Dener Vieira Ribeiro
  2665 - Lucas Takeshi Moreira Chang
  3889 - Igor de Melo Alves
*/

#include "includes/tst_if.h"
#include <stdio.h>

static void atravessaTST(Tst *t, char *buf, int profundidade);
static void ordemTST(Tst *t);



static void atravessaTST(Tst *t, char *buf, int profundidade)
{
    if (*t)
    {
        atravessaTST(&(*t)->Esq, buf, profundidade);// Visita filho à esquerda
        buf[profundidade] = (*t)->chave;// Salva caractere atual no índice correto (equivale à profundidade) do buffer

        if ((*t)->FimDeString == 1)// Verifica se é fim de string
        {
            buf[profundidade + 1] = '\0';
            printf("%s\n", buf);
        }

        atravessaTST(&(*t)->Meio, buf, profundidade + 1);// Visita filho do meio incrementando a profundidade
        atravessaTST(&(*t)->Dir, buf, profundidade);// Verifica filho à direita
    }
}

static void ordemTST(Tst *t)
{
    char buf[MAX_WORD_SIZE+1];
    atravessaTST(t, buf, 0);
}



void tstPrintWords(Tst root) {
    ordemTST(&root);
}
