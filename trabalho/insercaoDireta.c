#include <stdio.h>
#include <stdlib.h>
#include "insercaoDireta.h"

void ordenarInsercaoDireta(int n, int vet[], long long int *contador, long long int *trocas){
    int i, j, troca,cont;

    //Ordenação
    for(i=0;i<n-1;i++){
        j=i+1;
        cont=0;
        while(j<n){
            (*contador)++;
            if(vet[i]>vet[j]){
                (*trocas)++;
                troca=vet[j];
                vet[j]=vet[i];
                vet[i]=troca;

                //Ordena o valor i no vetor antecessor a ele
                while(i>0 && vet[i-1]>vet[i]){
                    cont++;
                    (*trocas)++;
                    (*contador)++;
                    troca=vet[i-1];
                    vet[i-1]=vet[i];
                    vet[i]=troca;
                    i--;
                }
            i=i+cont;
            }
        break;
        }
    }
}
