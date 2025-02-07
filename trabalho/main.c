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
#include "quicksortCentro.h"
#include "mergesort.h"
#include "radixsort.h"
#include "bucketsort.h"
#include "geradorSequencia.h"

int main(){

    FILE *file = fopen ("saida.txt", "w");

    if(file == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    clock_t start, end;
    long long int contador=0;
    long long int trocas=0;
    int numeros=0, i;
    int caso=0;

    printf ("Quantos numeros voce gostaria de gerar?\n");
    scanf ("%d", &numeros);

    int vetor[numeros];

    printf("\nSelecione a opcao desejada: \n");
    printf ("1- Gerar numeros em ordem aleatoria\n");
    printf ("2- Gerar numeros em ordem crescente\n");
    printf ("3- Gerar numeros em ordem decrescente\n");
    scanf("%d", &caso);

    while (caso<1 || caso>3){
        printf ("Opcao invalida! Escolha outro valor: ");
        scanf ("%d", &caso);
    }

    geradorSequencia(caso, numeros, vetor);

    int metodo;
    printf("\nSelecione o metodo de ordenacao desejado: \n");
    printf("1- Bolha\n");
    printf("2- Bolha com criterio de parada\n");
    printf("3- Insersao Direta\n");
    printf("4- Insercao Binaria\n");
    printf("5- ShellSort\n");
    printf("6- Selecao Direta\n");
    printf("7- HeapSort\n");
    printf("8- QuickSort (inicial)\n");
    printf("9- QuickSort (meio)\n");
    printf("10- QuickSort (mediana)\n");
    printf("11- MergeSort\n");
    printf("12- RadixSort\n");
    printf("13- BucketSort\n");
    printf("Escolha: ");
    scanf("%d",&metodo);

    while(metodo<1 || metodo>13){
        printf("Opcao Invalida!\nDigite novamente: ");
        scanf("%d",&metodo);
    }

    start = clock();//começa a contagem de tempo
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
            printf("\nOrdenacao QuickSort Centro: \n");
            ordenarQuickSortIni(vetor,numeros,&contador,&trocas);
            break;

        case 10:
            printf("\nOrdenacao QuickSort Mediana: \n");
            ordenarQuickSortMediana(vetor,numeros,&contador,&trocas);
            break;

        case 11:
            printf("\nOrdenacao MergeSort: \n");
            ordenarMergeSort(vetor,numeros,&contador,&trocas);
            break;
        case 12:
            printf("\nOrdenacao RadixSort: \n");
            ordenarRadixSort(vetor,numeros,&contador,&trocas);
            break;
        case 13:
            printf("\nOrdenacao BucketSort: \n");
            ordenarBucketSort(vetor,numeros,&contador,&trocas);
            break;
    }
    end = clock();//encerra a contagem de tempo

    for(i=0;i<numeros;i++){
        fprintf(file, "%d\n", vetor[i]);
    }

    printf("\n");
    printf("TEMPO DE EXECUCAO: %.5f\n",((double) (end - start)) / CLOCKS_PER_SEC);
    printf("COMPARACOES: %lli\n", contador);
    printf("TROCAS: %lli\n",trocas);


    fclose(file);

    return 0;
}
