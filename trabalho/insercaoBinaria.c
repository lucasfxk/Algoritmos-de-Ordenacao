#include <stdio.h>
#include <stdlib.h>
#include "insercaoBinaria.h"

void ordenarInsercaoBinaria(int tamanho, int *vetor, long long int *comparacoes, long long int *trocas){
    int aux=0,esq=0,dir=0,meio=0;

    //Ordenação
    for(int x=1;x<tamanho;x++){
        aux = vetor[x];
        esq = 0;
        dir = x;

        //Procura - de forma binária- a posição do valor i no vetor antecessor a ele
        while(esq<dir){
            meio = (esq+dir)/2;
            (*comparacoes)++;
            if(vetor[meio]<=aux){
                esq = meio+1;
            }else{
                dir = meio;
            }
        }

        //Transloca o valor i até a sua respectiva posição
        for(int y=x;y>esq;y--){
            vetor[y] = vetor[y-1];
            (*trocas)++;
        }
        vetor[dir] = aux;
    }
}
