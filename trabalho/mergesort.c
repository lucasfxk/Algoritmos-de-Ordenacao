#include <stdlib.h>
#include <stdio.h>
#include "mergesort.h"

void mergeSort(int *vetor, int inicio, int fim, long long int* comparacao, long long int* trocas){
    if((fim-inicio)>=1){
        int meio = ((fim + inicio + 1)/2);

        mergeSort(vetor,meio,fim,comparacao,trocas);
        mergeSort(vetor,inicio,meio-1,comparacao,trocas);

        int i = meio,tmp[fim-inicio+1],cont=0;

        for(int x=inicio;x<=meio-1;x++){
            (*comparacao)++;

            /*Posiciona os valores do vetor da direita
            que são menores que 'x' no vetor temporário*/
            while(vetor[x]>=vetor[i]&&i<=fim){
                (*comparacao)++;
                (*trocas)++;
                tmp[cont] = vetor[i];
                cont++;
                i++;
            }

            //Ao final posiciona o valor 'x' no vetor temporário
            (*trocas)++;
            tmp[cont] = vetor[x];
            cont++;
        }

        //guarda no vetor temporario os valores restantes do vetor da esquerda
        while(i<=fim){
            tmp[cont] = vetor[i];
            cont++;
            i++;
            (*trocas)++;
        }

        cont=0;

        //salva os valores no vetor
        for(int x=inicio;x<=fim;x++){
            vetor[x] = tmp[cont];
            cont++;
        }
    }
}

void ordenarMergeSort(int *vetor, int tamanho, long long int *contador, long long int *trocas){

    //Ordenação
    mergeSort(vetor,0,tamanho-1,contador,trocas);
}
