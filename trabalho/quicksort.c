#include <stdio.h>
#include <stdlib.h>
#include "quicksort.h"

//peguei o código da internet (Vídeo o professor Marcelo)

void ordenarQuickSortIni(int vet[], int esquerda, int direita){
    int i, j, troca, pivo;

    i=esquerda;
    j=direita;
    pivo=vet[i];

    while(i<=j){
        while(vet[i]<pivo && i<direita){
            i++;
        }
        while(vet[j]>pivo && j>esquerda){
            j--;
        }

        if(i<=j){
            troca=vet[i];
            vet[i]=vet[j];
            vet[j]=troca;
            i++;
            j--;
        }
    }

    if(j>esquerda){
        ordenarQuickSortIni(vet,esquerda,j);
    }
    if(i<direita){
        ordenarQuickSortIni(vet,i,direita);
    }
}


void ordenarQuickSortCentro(int vet[], int esquerda, int direita){
    int i, j, troca, pivo;

    i=esquerda;
    j=direita;
    pivo=vet[j/2];

    while(i<=j){
        while(vet[i]<pivo && i<direita){
            i++;
        }
        while(vet[j]>pivo && j>esquerda){
            j--;
        }

        if(i<=j){
            troca=vet[i];
            vet[i]=vet[j];
            vet[j]=troca;
            i++;
            j--;
        }
    }

    if(j>esquerda){
        ordenarQuickSortIni(vet,esquerda,j);
    }
    if(i<direita){
        ordenarQuickSortIni(vet,i,direita);
    }
}


