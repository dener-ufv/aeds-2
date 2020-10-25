#include "includes/menu.h"

int menu() {
int Op,Arv;
do
{   printf("\n---------------------- ESCOLHA A ARVORE ----------------------------\n");
    printf(" 1) Arvore PATRICIA\n 2) Arvore TRIE TST\n 0) Sair\n");
    printf("Opcao: ");
    scanf("%d",&Arv);

  // ARVORVE PATRICIA
    if(Arv == 1){
        //patriciaInit(Patricia *root);
        do
        {   printf("\n------------------------- ARVORE PATRICIA --------------------------\n");
            printf("\n---------------- Digite UM NUMERO da opcao desejada ----------------\n");
            printf(" 1) Inserir Palavra\n 2) Pesquisar Palavra\n 3) Exibir todas as palavras em ordem alfabética\n 4) Contar Palavras\n 0) Sair\n\n");
            printf("Opcao: ");
            scanf("%d",&Op);
            switch (Op)
            {
            case 1:
               // patriciaInsert(Patricia *root, Word word, Benchmark *bench);

                break;
            case 2:
               // patriciaFind(Patricia *root, Word word, Benchmark *bench);

                break;
            case 3:
               //patriciaGetWord(Patricia root);

                break;
            case 4:

                break;

            case 0:
                printf("\n--------------------------------------------------------------------\n");
                break;
            default:
                printf("\n-------------------------- ERRO! ------------------------\n----------Somente os numeros mostrados no menu ----------\n");
                break;
            }

        }while ( Op != 0 );


// ARVORVE TRIE  TST
    }else if(Arv == 2){
        //tstInit(Tst *root);
        do
        {   
            printf("\n----------------------- ARVORE TRIE TST ----------------------------\n");
            printf("\n---------------- Digite UM NUMERO da opcao desejada ----------------\n");
            printf(" 1) Inserir Palavra\n 2) Pesquisar Palavra\n 3) Exibir todas as palavras em ordem alfabética\n 4) Contar Palavras\n 0) Sair\n\n");
            printf("Opcao: ");
            scanf("%d",&Op);
            switch (Op)
            {
            case 1:
               // tstInsert(Tst *root, Word word, Benchmark *bench);


                break;
            case 2:

              //  tstFind(Tst *root, Word word, Benchmark *bench);

                break;
            case 3:

                


                break;
            case 4:




                break;

            case 0:
                printf("\n--------------------------------------------------------------------\n");
                break;
            default:
                printf("\n-------------------------- ERRO! ------------------------\n----------Somente os numeros mostrados no menu ----------\n");
                break;
            }

        }while ( Op != 0 );
        
        }else if (Arv == 0) {
            printf("\n------------------------- FIM DO PROGRAMA ------------------------\n");
        }

    }while (Arv != 0);
    
}












