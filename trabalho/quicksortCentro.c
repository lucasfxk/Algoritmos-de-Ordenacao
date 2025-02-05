#include <stdlib.h>
#include <stdio.h>
#include "quicksortCentro.h"

void quicksortCentro(int *vetor,int inicio, int fim, int *comparacao, int *trocas){
    if(fim-inicio>=1){
        int l=inicio, r=fim, pivo=(inicio+fim)/2, aux=0;

        while(l <= r){
            while(vetor[l] < vetor[pivo]){
                l++;
                (*comparacao)++;
            }
            while(vetor[r] > vetor[pivo]){
                r--;
                (*comparacao)++;
            }
            if(l<=r){
                (*trocas)++;
                aux = vetor[r];
                vetor[r] = vetor[l];
                vetor[l] = aux;
                l++;
                r--;
            }
        }
        quicksortCentro(vetor,inicio,l-1,comparacao,trocas);
        quicksortCentro(vetor,l,fim,comparacao,trocas);
    }
}

void ordenarQuickSortCentro(int* vetor,int tamanho, int *contador, int *trocas){

    //Ordenação
    quicksortCentro(vetor,0,tamanho-1,contador,trocas);
}
