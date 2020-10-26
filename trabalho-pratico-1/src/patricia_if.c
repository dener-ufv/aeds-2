/*
  Grupo Divididos
  3869 - Fábio Trindade Ramos
  3872 - Dener Vieira Ribeiro
  2665 - Lukas Takeshi Moreira Chang
  3889 - Igor de Melo Alves
*/

#include "includes/patricia_if.h"
#include <stdlib.h>
#include "includes/word_if.h"
#include <stdio.h>

void patriciaPrintWords(Patricia root) {
    if(root == NULL) return;
    patriciaPrintWords(patriciaGetLeft(root));
    if(patriciaIsLeaf(root)) {
        wordPrint(patriciaGetWord(root));
        printf("\n");
    }
    patriciaPrintWords(patriciaGetRight(root));
}
