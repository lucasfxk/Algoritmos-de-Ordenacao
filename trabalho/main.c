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
#include "quicksortIni.h"
#include "mergesort.h"
#include "radixsort.h"
#include "bucketsort.h"
#include "geradorSequencia.h"

int main()
{
    FILE *file = fopen ("saida.txt", "w");

    if(file == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    clock_t start, end;
    int contador=0;
    int trocas=0;
    int numeros=0, i;
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
    printf("8-QuickSort (inicial)\n");
    printf("9-QuickSort (meio)\n");
    printf("10-QuickSort (mediana)\n");
    printf("11-MergeSort\n");
    printf("12-RadixSort\n");
    printf("13-BucketSort\n");
    printf("Escolha: ");
    scanf("%d",&metodo);

    while(metodo<1 || metodo>13){
        printf("Opcao Invalida!\nDigite novamente: ");
        scanf("%d",&metodo);
    }

    start = clock();//começa a contar o tempo
    switch(metodo){
        case 1:
            printf("\nOrdenacao Bolha: \n");
            ordenarBolha(numeros,vetor,&contador,&trocas);
            break;

        case 2:
            printf("\nOrdenacao Bolha com criterio de parada: \n");
            ordenarBolhaParada(numeros,vetor,&contador,&trocas);
            break;

        case 3:
            printf("\nOrdenacao Insercao Direta: \n");
            ordenarInsercaoDireta(numeros,vetor,&contador,&trocas);
            break;

        case 4:
            printf("\nOrdenacao Insersao Binaria: \n");
            ordenarInsercaoBinaria(numeros,vetor,&contador,&trocas);
            break;

        case 5:
            printf("\nOrdenacao ShellSort: \n");
            ordenarShellSort(numeros,vetor,&contador,&trocas);
            break;

        case 6:
            printf("\nOrdenacao Selecao Direta: \n");
            ordenarSelecaoDireta(numeros,vetor,&contador,&trocas);
            break;

        case 7:
            printf("\nOrdenacao HeapSort: \n");
            ordenarHeapsort(numeros,vetor,&contador,&trocas);
            break;

        case 8:
            printf("\nOrdenacao QuickSort Inicio: \n");
            ordenarQuickSortIni(vetor,numeros,&contador,&trocas);
            break;

        case 9:

            break;

        case 10:

            break;

        case 11:

            break;
        case 12:

            break;
        case 13:

            break;
    }
    end = clock();

    for(i=0;i<numeros;i++){
        fprintf(file, "%d\n", vetor[i]);
    }

    for(i=0;i<numeros;i++){
        printf("%d\n", vetor[i]);
    }

    printf("\n");
    printf("TEMPO DE EXECUCAO: %.5f\n",((double) (end - start)) / CLOCKS_PER_SEC);
    printf("COMPARACOES: %d\n", contador);
    printf("TROCAS: %d\n",trocas);


    fclose(file);


return 0;
}
