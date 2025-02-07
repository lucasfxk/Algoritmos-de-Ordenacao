#include <stdlib.h>
#include <stdio.h>
#include "quicksortCentro.h"

void quicksortCentro(int *vetor,int inicio, int fim, long long int *comparacao, long long int *trocas){
    if(fim-inicio>=1){
        int l=inicio, r=fim, pivo=(inicio+fim)/2, aux=0;

        /*Posiciona os valores menores que o pivo à sua esquerda e,
        à sua direita, os valores maiores*/
        while(l <= r){

            //Encontra um valor menor que o pivô no vetor à direita
            while(vetor[l] < vetor[pivo]){
                l++;
                (*comparacao)++;
            }

            //Encontra um valor maior que o pivô no vetor à esquerda
            while(vetor[r] > vetor[pivo]){
                r--;
                (*comparacao)++;
            }

            //Permuta os valores encontrados
            if(l<=r){
                (*trocas)++;
                aux = vetor[r];
                vetor[r] = vetor[l];
                vetor[l] = aux;
                l++;
                r--;
            }
        }

        //Executa recursivamente o vetor do lado esquerdo ao pivo
        quicksortCentro(vetor,inicio,l-1,comparacao,trocas);

        //Executa recursivamente o vetor do lado direito ao pivo
        quicksortCentro(vetor,l,fim,comparacao,trocas);
    }
}

void ordenarQuickSortCentro(int* vetor,int tamanho, long long int *contador, long long int *trocas){

    //Ordenação
    quicksortCentro(vetor,0,tamanho-1,contador,trocas);
}
