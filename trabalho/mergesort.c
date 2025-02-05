#include <stdlib.h>
#include <stdio.h>
#include "mergesort.h"

void mergeSort(int *vetor, int inicio, int fim, int* comparacao, int* trocas){
    if((fim-inicio)>=1){
        int meio = ((fim + inicio + 1)/2);

        mergeSort(vetor,meio,fim,comparacao,trocas);
        mergeSort(vetor,inicio,meio-1,comparacao,trocas);

        int i = meio,tmp[fim-inicio+1],cont=0;//easter-egg gigatonico
        for(int x=inicio;x<=meio-1;x++){
            (*comparacao)++;//incrementa contador
            while(vetor[x]>=vetor[i]&&i<=fim){
                (*comparacao)++;//incrementa contador
                (*trocas)++;
                tmp[cont] = vetor[i];
                cont++;
                i++;
            }
            (*trocas)++;
            tmp[cont] = vetor[x];
            cont++;
        }

        //guarda no vetor temporario os valores restantes
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

void ordenarMergeSort(int *vetor, int tamanho, int *contador, int *trocas){

    //Ordenação
    mergeSort(vetor,0,tamanho-1,contador,trocas);
}
