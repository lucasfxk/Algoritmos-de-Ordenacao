#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bolhaParada.h"

void ordenarBolhaParada(int n, int vet[], long long int *cont, long long int *troca){
    int j, troc;
    bool mudou = true;

    int ultimo=n-1;
    int novoultimo;

    //Verificação da quantidade de trocas (se não houve, então o algoritmo encerra)
    while(mudou){
            novoultimo=0;
            mudou = false;

            //Algoritmo padrão do Bolha
            for(j=0;j<ultimo;j++){
                (*cont)++;
                if(vet[j]>vet[j+1]){
                    (*troca)++;
                    mudou = true;
                    troc=vet[j+1];
                    vet[j+1]=vet[j];
                    vet[j]=troc;
                    novoultimo = j;
                }
            }
        ultimo = novoultimo;
    }
}
