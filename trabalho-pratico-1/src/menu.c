#include "includes/menu.h"

int menu() {
    int Op,Arv;
    Patricia Ptree;
    Tst Ttree;
    Benchmark Pbench;
    Benchmark Tbench;
    Word NWord;
    benchmarkInit(&Tbench);
    benchmarkInit(&Pbench);
    wordInit(&NWord);
    do
    {   printf("\n---------------------- ESCOLHA A ARVORE ----------------------------\n");
        printf(" 1) Arvore PATRICIA\n 2) Arvore TRIE TST\n 0) Sair\n");
        printf("Opcao: ");
        scanf("%d",&Arv);

    // ARVORVE PATRICIA
        if(Arv == 1){
            patriciaInit(&Ptree);
            
            do
            {   printf("\n------------------------- ARVORE PATRICIA --------------------------\n");
                printf("\n---------------- Digite UM NUMERO da opcao desejada ----------------\n");
                printf(" 1) Inserir Palavra\n 2) Pesquisar Palavra\n 3) Exibir todas as palavras em ordem alfabética\n 4) Contar Palavras\n 0) Sair\n\n");
                printf("Opcao: ");
                scanf("%d",&Op);
                switch (Op)
                {
                case 1:
                    benchmarkStartTimer(&Pbench);
                    wordSetString(&NWord, ? );
                    patriciaInsert(&Ptree, NWord, &Pbench);

                    benchmarkStopTimer(&Pbench);
                    break;
                case 2:
                 patriciaFind(&Ptree, NWord, &Pbench);
                    break;
                case 3:
                patriciaPrintWords(Ptree);

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
        tstInit(&Ttree);
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
                benchmarkStartTimer(&Tbench);
                wordSetString(&NWord, ?);
                tstInsert(&Ttree,NWord, &Tbench);
    
                benchmarkStopTimer(&Tbench);
                


                break;
            case 2:

            tstFind(&Ttree,NWord, &Tbench);

                break;
            case 3:
                tstPrintWords(Ttree);

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












