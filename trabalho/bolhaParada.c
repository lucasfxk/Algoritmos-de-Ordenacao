#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bolhaParada.h"

void ordenarBolhaParada(int n, int vet[], int *cont, int *troca){
    int i, j, troc;
    bool mudou = true;

    for(i=n-1;i>0;i--){
        while(mudou){
            mudou = false;
            for(j=0;j<i;j++){
                (*cont)++;
                if(vet[j]>vet[j+1]){
                    (*troca)++;
                    mudou = true;
                    troc=vet[j+1];
                    vet[j+1]=vet[j];
                    vet[j]=troc;
                }
            }
        }
    }
}
