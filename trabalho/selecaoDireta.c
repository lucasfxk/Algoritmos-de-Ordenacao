#include <stdio.h>
#include <stdlib.h>
#include "selecaoDireta.h"

void ordenarSelecaoDireta(int n, int vet[], long long int *contador, long long int *trocas){
    int i, j, troca, posicao;

    //Começa a ordenação
    for(i=0;i<n-1;i++){
        troca=vet[i];
        posicao=i;

        //Procura valores em que 'troca' seja maior
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
