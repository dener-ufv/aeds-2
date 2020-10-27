/*
  Grupo Divididos
  3869 - Fábio Trindade Ramos
  3872 - Dener Vieira Ribeiro
  2665 - Lucas Takeshi Moreira Chang
  3889 - Igor de Melo Alves
*/#include "includes/menu.h"
void menu() {
    int Op,Arv,contT, contP;
    Patricia Ptree;
    Tst Ttree;
    Benchmark Pbench;
    Benchmark Tbench;
    Word NWord;
    Word NWord1;
    benchmarkInit(&Tbench);
    benchmarkInit(&Pbench);
    benchmarkInitcompTST(&Tbench);
    benchmarkInitcompPat(&Pbench);
    wordInit(&NWord);
    wordInit(&NWord1);
    char NomeArq[32], Palavra[20],PalaPesq[20];
    do
    {   printf("\n---------------------- ESCOLHA A ARVORE ----------------------------\n");
        printf(" 1) Arvore PATRICIA\n 2) Arvore TRIE TST\n 0) Sair\n");
        printf("Opcao: ");
        scanf("%d",&Arv);

    // ARVORVE PATRICIA
        if(Arv == 1){
            patriciaInit(&Ptree);
            contP=0;
            do
            {   printf("\n\n\n------------------------- ARVORE PATRICIA --------------------------\n");
                printf("\n---------------- Digite UM NUMERO da opcao desejada ----------------\n");
                printf(" 1) Inserir Palavra\n 2) Pesquisar Palavra\n 3) Exibir todas as palavras em ordem alfabetica\n 4) Contar Palavras\n 0) Sair\n\n");
                printf("Opcao: ");
                scanf("%d",&Op);
                switch (Op)
                {
                case 1:
                    benchmarkStartTimer(&Pbench);
                    FILE *arq;
                    printf("\nDigite o nome do arquivo: ");
                    scanf("%s",NomeArq);
                    arq = fopen(NomeArq, "r");
                    if (arq == NULL)
                    {
                        printf("ERRO! O arquivo nao foi aberto!\n");
                    }
                    else
                    {
                        printf("O arquivo foi aberto com sucesso!\n");
                        while (fscanf(arq,"%s",Palavra)!= EOF )
                        {
                            contP++;
                            wordSetString(&NWord, Palavra );
                            patriciaInsert(&Ptree, NWord, &Pbench);
                        }
                    }
                    fclose(arq);
                    benchmarkStopTimer(&Pbench);
                    printf("Time: %lf\n",benchmarkGetTime(Pbench));
                    break;
                case 2:
                    benchmarkInitcompPat(&Pbench);
                    benchmarkStartTimer(&Pbench);
                    printf("\nDigite a palavra de pesquisa: ");
                    scanf("%s",PalaPesq);
                    wordSetString(&NWord1,PalaPesq);
                    if(patriciaFind(&Ptree, NWord1, &Pbench)== 1) printf("\nEncontrado a palavra: %s\n", PalaPesq);
                    else printf("\n Nao exite a palavra: %s\n",PalaPesq);
                    benchmarkStopTimer(&Pbench);
                    printf("Time: %lf\n",benchmarkGetTime(Pbench));
                    //printf("%d",patriciaFind(&Ptree, NWord1, &Pbench));
                    //printf("%d",&comp.compPesquiT);
                    break;
                case 3:
                    patriciaPrintWords(Ptree);
                    break;
                case 4:
                    printf("\n--------- Quantidade de palavras na arvore Patricia: %d ------------\n",contP);
                    printf("\n-------- Quantidade de comparacao na insercao Patricia: %d ----------\n",benchmarkGetComparations(Pbench));
                    printf("\n---------- Quantidade de comparacao na pesquisa Patricia: %d -------------\n",Pbench.compPat);

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
        contT=0;
        do
        {
            printf("\n\n\n----------------------- ARVORE TRIE TST ----------------------------\n");
            printf("\n---------------- Digite UM NUMERO da opcao desejada ----------------\n");
            printf(" 1) Inserir Palavra\n 2) Pesquisar Palavra\n 3) Exibir todas as palavras em ordem alfabetica\n 4) Contar Palavras\n 0) Sair\n\n");
            printf("Opcao: ");
            scanf("%d",&Op);
            switch (Op)
            {
            case 1:
                benchmarkStartTimer(&Tbench);
                FILE *arq;
                printf("\nDigite o nome do arquivo: ");
                scanf("%s",NomeArq);
                arq = fopen(NomeArq, "r");
                if (arq == NULL)
                {
                    printf("ERRO! O arquivo nao foi aberto!\n");
                }
                else
                {
                    printf("O arquivo foi aberto com sucesso!\n");
                    while (fscanf(arq,"%s",Palavra)!= EOF )
                    {
                        contT++;
                        wordSetString(&NWord, Palavra );
                        tstInsert(&Ttree,NWord, &Tbench);
                    }
                }
                fclose(arq);
                benchmarkStopTimer(&Tbench);
                printf("Time: %lf\n",benchmarkGetTime(Tbench));
                break;
            case 2:
                benchmarkInitcompTST(&Tbench);
                benchmarkStartTimer(&Tbench);
                printf("\nDigite a palavra de pesquisa: ");
                scanf("%s",PalaPesq);
                wordSetString(&NWord1,PalaPesq);
                if(tstFind(&Ttree,NWord1, &Tbench) == 1) printf("\nEncontrado a palavra: %s\n", PalaPesq);
                else printf("\n Nao exite a palavra: %s\n",PalaPesq);
                benchmarkStopTimer(&Tbench);
                printf("Time: %lf\n",benchmarkGetTime(Tbench));
                break;
            case 3:
                tstPrintWords(Ttree);

                break;
            case 4:
                printf("\n----------- Quantidade de palavras na arvore TST: %d ---------------\n",contT);
                printf("\n---------- Quantidade de comparacao na insercao TST: %d -------------\n",benchmarkGetComparations(Tbench));
                printf("\n---------- Quantidade de comparacao na pesquisa TST: %d -------------\n",Tbench.compTST);
                break;
            case 0:
                printf("\n--------------------------------------------------------------------\n");
                tstInit(&Ttree);
                break;
            default:
                printf("\n-------------------------- ERRO! ------------------------\n----------Somente os numeros mostrados no menu ----------\n");
                break;
            }

        }while ( Op != 0 );

        }else if (Arv == 0) {
            printf("\n------------------------- FIM DO PROGRAMA ------------------------\n\n\n");
        }

    }while (Arv != 0);

}
