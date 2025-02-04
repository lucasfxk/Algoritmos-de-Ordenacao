#include <stdio.h>
#include <stdlib.h>
#include "insercaoBinaria.h"

void ordenarInsercaoBinaria(int tamanho, int *vetor, int *comparacoes, int *trocas){
    int aux=0,esq=0,dir=0,meio=0;

    //Ordenação
    for(int x=1;x<tamanho;x++){
        aux = vetor[x];
        esq = 0;
        dir = x;
        (*comparacoes)++;
        while(esq<dir){
            (*comparacoes)++;
            meio = (esq+dir)/2;
            if(vetor[meio]<=aux){
                esq = meio+1;
            }else{
                dir = meio;
            }
        }
        for(int y=x;y>esq;y--){
            vetor[y] = vetor[y-1];
            (*trocas)++;
        }
        vetor[dir] = aux;
    }
}
