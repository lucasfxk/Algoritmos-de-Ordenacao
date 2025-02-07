#include <stdio.h>
#include <stdlib.h>
#include "quicksortIni.h"

void quicksortInicio(int *vetor,int inicio, int fim, long long int *comparacao,long long int *trocas){
    if((fim-inicio)>=1){
        int i=fim,j=fim+1,aux=0,pivo=vetor[inicio];

        /*Posiciona os valores menores que o pivo à sua esquerda e,
        à sua direita, os valores maiores*/
        for(;i>=inicio;i--){
            (*comparacao)++;
            if(vetor[i]>=pivo){
                j--;
                if(i < j){
                    (*trocas)++;
                    aux = vetor[i];
                    vetor[i] = vetor[j];
                    vetor[j] = aux;
                }
            }
        }

        //Executa recursivamente o vetor do lado esquerdo ao pivo
        quicksortInicio(vetor,inicio,j-1,comparacao,trocas);

        //Executa recursivamente o vetor do lado direito ao pivo
        quicksortInicio(vetor,j+1,fim,comparacao,trocas);
    }
}


void ordenarQuickSortIni(int *vetor, int tamanho, long long int *contador, long long int *trocas){
    //Ordenação
    quicksortInicio(vetor,0,tamanho-1,contador,trocas);
}


