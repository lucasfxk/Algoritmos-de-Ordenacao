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
#include "mergemod.h"
#include "radixsort.h"
#include "bucketsort.h"

int main()
{
    clock_t start, end;
    int contador;
    int trocas;
    int numeros, i;
    int caso;

    printf ("Quantos numeros voce gostaria de gerar? ");
    scanf ("%d", &numeros);

    int vetor[numeros];

    printf("Selecione a opcao desejada: \n");
    printf ("1-Gerar numeros em ordem aleatoria\n");
    printf ("2-Gerar numeros em ordem crescente\n");
    printf ("3-Gerar numeros em ordem decrescente\n");
    scanf("%d", &caso);

    while (caso<1 || caso>3){
        printf ("Opcao invalida! Escolha outro valor: ");
        scanf ("%d", &caso);
    }

    geradorSequencia(caso, numeros, vetor);

    int metodo;
    printf("Selecione o metodo de ordenacao desejado: \n");
    printf("1-Bolha\n");
    printf("2-Bolha com criterio de parada\n");
    printf("3-Insersao Direta\n");
    printf("4-Insercao Binaria\n");
    printf("5-ShellSort\n");
    printf("6-Selecao Direta\n");
    printf("7-HeapSort\n");
    printf("8-QuickSort\n");
    printf("9-MergeSort\n");
    printf("10-RadixSort\n");
    printf("11-BucketSort\n");
    scanf("%d",&metodo);

    while(metodo<1 || metodo>11){
        printf("Opcao Invalida! Digite novamente: \n");
        scanf("%d",&metodo);
    }

    switch(metodo){
        case 1:
            contador=0;
            trocas=0;
            printf("\n");
            printf("Ordenacao Bolha: \n");
            start = clock();
            ordenarBolha(numeros,vetor,&contador,&trocas);
            end = clock();

            break;

        case 2:
            contador=0;
            trocas=0;
            printf("\n");
            printf("Ordenacao Bolha com criterio de parada: \n");
            start = clock();
            ordenarBolhaParada(numeros,vetor,&contador,&trocas);
            end = clock();

            break;

        case 3:
            contador=0;
            trocas=0;
            printf("\n");
            printf("Ordenacao Insercao Direta: \n");
            start = clock();
            ordenarInsercaoDireta(numeros,vetor,&contador,&trocas);
            end = clock();

            break;

        case 4:
            contador=0;
            trocas=0;
            printf("\n");
            printf("Ordenacao Insersao Binaria: \n");
            start = clock();
            ordenarInsercaoBinaria(numeros,vetor,&contador,&trocas);
            end = clock();

            break;

        case 5:
            contador=0;
            trocas=0;
            printf("\n");
            printf("Ordenacao ShellSort: \n");
            start = clock();
            ordenarShellSort(numeros,vetor,&contador,&trocas);
            end = clock();

            break;

        case 6:
            contador=0;
            trocas=0;
            printf("\n");
            printf("Ordenacao Selecao Direta: \n");
            start = clock();
            ordenarSelecaoDireta(numeros,vetor,&contador,&trocas);
            end = clock();

            break;

        case 7:
            contador=0;
            trocas=0;
            printf("\n");
            printf("Ordenacao HeapSort: \n");
            start = clock();
            ordenarHeapsort(numeros,vetor,&contador,&trocas);
            end = clock();

            break;

        case 8:
            printf("\n");
            printf("Ordenacao QuickSort Inicio: \n");
            start = clock();
            ordenarQuickSortIni(vetor,0,numeros-1);
            end = clock();

            break;

        case 9:

        break;

        case 10:

        break;

        case 11:

        break;
    }

    for(i=0;i<numeros;i++){
        printf("%d\n", vetor[i]);
    }

    printf("TEMPO DE EXECUCAO: %.5f\n",((double) (end - start)) / CLOCKS_PER_SEC);
    printf("COMPARACOES: %d\n", contador);
    printf("TROCAS: %d\n,",trocas);

return 0;
}
