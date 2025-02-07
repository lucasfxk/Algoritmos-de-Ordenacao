#include <stdlib.h>
#include <stdio.h>
#include "quicksortMediana.h"

//Função para calcular a mediana do vetor e retornar o índice do valor da mediana
int mediana(int* vetor,int inicio, int fim, long long int* comparacao,long long int *trocas){
    int meio = (inicio+fim)/2;
    int vet[] = {vetor[inicio],vetor[meio],vetor[fim]},aux=0;

    for(int x=1;x<3;x++){
        for(int y=x;(y-1>=0)&&(vet[y-1]>vet[y]);y--){
            (*trocas)++;
            aux = vet[y];
            vet[y] = vet[y-1];
            vet[y-1] = aux;
            (*comparacao)++;
        }
    }

    vetor[inicio] = vet[0];
    vetor[meio] = vet[1];
    vetor[fim] = vet[2];

    return meio;
}

void quicksort(int *vetor,int inicio, int fim, long long int *comparacao, long long int *trocas){
    if(fim-inicio>3){
        int l=inicio, r=fim, pivo=mediana(vetor,inicio,fim,comparacao,trocas), aux=0;

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
        quicksort(vetor,inicio,l-1,comparacao,trocas);

        //Executa recursivamente o vetor do lado direito ao pivo
        quicksort(vetor,l,fim,comparacao,trocas);
    }
}

void ordenarQuickSortMediana(int* vetor,int tamanho,long long int *contador, long long int *trocas){

    //Ordenação
    quicksort(vetor,0,tamanho-1,contador,trocas);
}
