#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "bolha.h"
#include "bolhaParada.h"
#include "insercaoDireta.h"
#include "insercaoBinaria.h"
#include "shellsort.h"
#include "selecaoDireta.h"
#include "heapsort.h"
#include "quicksort.h"

int main()
{
    clock_t start, end;
    int contador;
    int trocas;

    int caso;

    printf("Selecione a opcao desejada: \n");
    printf ("1-Gerar numeros em ordem aleatoria\n");
    printf ("2-Gerar numeros em ordem crescente\n");
    printf ("3-Gerar numeros em ordem decrescente\n");
    scanf("%d", &caso);

    while (caso<1 || caso>3){
        printf ("Opcao invalida! Escolha outro valor: ");
        scanf ("%d", &caso);
    }

    int numeros, i;

    printf ("Quantos numeros voce gostaria de gerar? ");
    scanf ("%d", &numeros);

    int vetor[numeros];


    switch(caso){
        case 1:
            /*for (i=0;i<numeros;i++){ //se eu fizer desse jeito vou ter os mesmos valores sempre
                vetor[i]=rand();
            }

            for (i=0;i<numeros;i++){
                printf ("%d\n", vetor[i]);
            }
            */

            srand(time(NULL)); //inicializa o gerador de números aleatórios de acordo com a hora atual. Cada execução gera valores diferentes

            for (i=0;i<numeros;i++){
                vetor[i]=rand();
            }

            for (i=0;i<numeros;i++){
                printf ("%d\n", vetor[i]);
            }
        break;

        case 2:
            for(i=0;i<numeros;i++){
                vetor[i]=i+1;
            }

            for (i=0;i<numeros;i++){
                printf ("%d\n", vetor[i]);
            }
        break;

        case 3:
            for(i=0;i<numeros;i++){
                vetor[i]=numeros-i;
            }

            for(i=0;i<numeros;i++){
                printf("%d\n", vetor[i]);
            }
        break;

    }

    //BOLHA
    /*contador=0;
    trocas=0;
    printf("\n");
    printf("Ordenacao Bolha: \n");
    start = clock();
    ordenarBolha(numeros,vetor,&contador,&trocas);
    end = clock();

    for(i=0;i<numeros;i++){
        printf("%d\n", vetor[i]);
    }

    printf("TEMPO DE EXECUCAO: %.5f\n",((double) (end - start)) / CLOCKS_PER_SEC);
    printf("COMPARACOES: %d\n", contador);
    printf("TROCAS: %d\n,",trocas);*/



    //BOLHA COM CRITÉRIO DE PARADA
    /*contador=0;
    trocas=0;
    printf("\n");
    printf("Ordenacao Bolha com criterio de parada: \n");
    start = clock();
    ordenarBolhaParada(numeros,vetor,&contador,&trocas);
    end = clock();

    for(i=0;i<numeros;i++){
        printf("%d\n",vetor[i]);
    }

    printf("TEMPO DE EXECUCAO: %.5f\n",((double) (end - start)) / CLOCKS_PER_SEC);
    printf("COMPARACOES: %d\n", contador);
    printf("TROCAS: %d\n,",trocas);*/


    //INSERÇÃO DIRETA
    /*contador=0;
    trocas=0;
    printf("\n");
    printf("Ordenacao Insercao Direta: \n");
    start = clock();
    ordenarInsercaoDireta(numeros,vetor,&contador,&trocas);
    end = clock();

    for(i=0;i<numeros;i++){
        printf("%d\n",vetor[i]);
    }

    printf("TEMPO DE EXECUCAO: %.5f\n",((double) (end - start)) / CLOCKS_PER_SEC);
    printf("COMPARACOES: %d\n", contador);
    printf("TROCAS: %d\n,",trocas);*/


    //INSERÇÃO BINÁRIA
    /*contador=0;
    trocas=0;
    printf("\n");
    printf("Ordenacao Insersao Binaria: \n");
    start = clock();
    ordenarInsercaoBinaria(numeros,vetor,&contador,&trocas);
    end = clock();

    for(i=0;i<numeros;i++){
        printf("%d\n",vetor[i]);
    }

    printf("TEMPO DE EXECUCAO: %.5f\n",((double) (end - start)) / CLOCKS_PER_SEC);
    printf("COMPARACOES: %d\n", contador);
    printf("TROCAS: %d\n,",trocas);*/


    //SHELLSORT
    /*contador=0;
    trocas=0;
    printf("\n");
    printf("Ordenacao ShellSort: \n");
    start = clock();
    ordenarShellSort(numeros,vetor,&contador,&trocas);
    end = clock();

    for(i=0;i<numeros;i++){
        printf("%d\n",vetor[i]);
    }

    printf("TEMPO DE EXECUCAO: %.5f\n",((double) (end - start)) / CLOCKS_PER_SEC);
    printf("COMPARACOES: %d\n", contador);
    printf("TROCAS: %d\n,",trocas);*/


    //SELECAO DIRETA
    /*contador=0;
    trocas=0;
    printf("\n");
    printf("Ordenacao Selecao Direta: \n");
    start = clock();
    ordenarSelecaoDireta(numeros,vetor,&contador,&trocas);
    end = clock();

    for(i=0;i<numeros;i++){
        printf("%d\n",vetor[i]);
    }

    printf("TEMPO DE EXECUCAO: %.5f\n",((double) (end - start)) / CLOCKS_PER_SEC);
    printf("COMPARACOES: %d\n", contador);
    printf("TROCAS: %d\n,",trocas);*/


    //HEAPSORT
    /*contador=0;
    trocas=0;
    printf("\n");
    printf("Ordenacao HeapSort: \n");
    start = clock();
    ordenarHeapsort(numeros,vetor,&contador,&trocas);
    end = clock();

    for(i=0;i<numeros;i++){
        printf("%d\n",vetor[i]);
    }

    printf("TEMPO DE EXECUCAO: %.5f\n",((double) (end - start)) / CLOCKS_PER_SEC);
    printf("COMPARACOES: %d\n", contador);
    printf("TROCAS: %d\n,",trocas);*/


    //QUICKSORT
    /*printf("\n");
    printf("Ordenacao QuickSort Inicio: \n");
    start = clock();
    ordenarQuickSortIni(vetor,0,numeros-1);
    end = clock();

    for(i=0;i<numeros;i++){
        printf("%d\n",vetor[i]);
    }

    printf("TEMPO DE EXECUCAO: %.5f\n",((double) (end - start)) / CLOCKS_PER_SEC);*/






return 0;
}
