#include <stdio.h>
#include <stdlib.h>
#include "shellsort.h"

void ordenarShellSort(int tamanho, int *vetor, long long int *comparacoes, long long int *trocas){
    int aux=0,gap=tamanho/2,i=0,j=0,cont=1;

    //Ordenação
    while(gap>0){

        //Ordena os valores de um sub-vetor
        for(int x=gap;x<tamanho;x++){
            j = x;
            i = j - gap;
            cont=1;
            while((i>=0)&&(cont>0)){
                cont=0;
                (*comparacoes)++;
                if(vetor[i]>vetor[j]){
                    (*trocas)++;
                    aux = vetor[j];
                    vetor[j] = vetor[i];
                    vetor[i] = aux;
                    cont++;
                }
                j = i;
                i = j - gap;
            }
        }

        //Reduz o tamanho do espaçamento entre os elementos
        gap = gap/2;
    }
}

