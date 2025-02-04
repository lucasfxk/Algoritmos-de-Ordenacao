#include <stdio.h>
#include <stdlib.h>
#include "bolha.h"

void ordenarBolha(int n, int vet[], int *cont, int *troca){
    int i, j, troc;

    for(i=n-1;i>0;i--){
        for(j=0;j<i;j++){
            (*cont)++;
            if(vet[j]>vet[j+1]){
                (*troca)++;
                troc=vet[j+1];
                vet[j+1]=vet[j];
                vet[j]=troc;
            }
        }
    }
}



