#include <stdlib.h>
#include <stdio.h>
#include "quicksortMediana.h"

int mediana(int* vetor,int inicio, int fim, int* comparacao,int *trocas){
    int meio = (inicio+fim)/2;
    int vet[] = {vetor[inicio],vetor[meio],vetor[fim]},aux=0;

    for(int x=1;x<3;x++){
        for(int y=x;(y-1>=0)&&(vet[y-1]>vet[y]);y--){
            (*trocas)++;
            aux = vet[y];
            vet[y] = vet[y-1];
            vet[y-1] = aux;
            (*comparacao)++;
        }
    }

    vetor[inicio] = vet[0];
    vetor[meio] = vet[1];
    vetor[fim] = vet[2];

    return meio;
}

void quicksort(int *vetor,int inicio, int fim, int *comparacao, int *trocas){
    if(fim-inicio>3){
        int l=inicio, r=fim, pivo=mediana(vetor,inicio,fim,comparacao,trocas), aux=0;

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
        quicksort(vetor,inicio,l-1,comparacao,trocas);
        quicksort(vetor,l,fim,comparacao,trocas);
    }
}

void ordenarQuickSortMediana(int* vetor,int tamanho,int *contador, int *trocas){

    //Ordenação
    quicksort(vetor,0,tamanho-1,contador,trocas);
}
