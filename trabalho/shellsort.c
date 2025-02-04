#include <stdio.h>
#include <stdlib.h>
#include "shellsort.h"

//peguei o código da internet (Vídeo do professor Marcelo)

void ordenarShellSort(int n, int vet[], int *contador, int *trocas){
    int i, j, h, aux;
    h=1;
    while(h<n){
        (*contador)++;
        h=h*3+1;
    }
    while(h>1){
        (*contador)++;
        h=h/3;

        for(i=h;i<n;i++){
            (*contador)++;
            aux=vet[i];
            j=i-h;
            while(j>=0 && aux<vet[j]){
                    (*contador)++;
                    (*trocas)++;
                    vet[j+h]=vet[j];
                    j=j-h;
            }
            vet[j+h]=aux;
        }
    }
}

