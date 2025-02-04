#include <stdio.h>
#include <stdlib.h>
#include "selecaoDireta.h"

void ordenarSelecaoDireta(int n, int vet[], int *contador, int *trocas){
    int i, j, troca, posicao;

    for(i=0;i<n-1;i++){
        (*contador)++;
        troca=vet[i];
        posicao=i;
        for(j=i+1;j<n;j++){
            (*contador)++;
            if(troca>vet[j]){
                troca=vet[j];
                posicao=j;
            }
        }
        (*trocas)++;
        vet[posicao]=vet[i];
        vet[i]=troca;
    }
}
