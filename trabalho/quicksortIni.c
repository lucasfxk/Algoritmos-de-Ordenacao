#include <stdio.h>
#include <stdlib.h>
#include "quicksortIni.h"

void quicksort(int *vetor,int inicio, int fim, int *comparacao,int *trocas){
    if((fim-inicio)>=1){
        int i=fim,j=fim+1,aux=0,pivo=vetor[inicio];
        for(;i>=inicio;i--){
            (*comparacao)++;
            if(vetor[i]>=pivo){
                j--;
                if(i < j){
                    (*trocas)++;
                    aux = vetor[i];
                    vetor[i] = vetor[j];
                    vetor[j] = aux;
                }
            }
        }
        quicksort(vetor,inicio,j-1,comparacao,trocas);
        quicksort(vetor,j+1,fim,comparacao,trocas);
    }
}


void ordenarQuickSortIni(int *vetor, int tamanho, int *contador, int *trocas){
    //Ordenação
    quicksort(vetor,0,tamanho-1,contador,trocas);
}


