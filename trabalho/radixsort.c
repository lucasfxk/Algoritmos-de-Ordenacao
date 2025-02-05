#include <stdio.h>
#include <stdlib.h>
#include "radixsort.h"

int maximo(int* vetor,int tamanho,int *comparacao){
    int maior = vetor[0];
    for(int x=1;x<tamanho;x++){
        (*comparacao)++;
        if(vetor[x]>maior){
            maior = vetor[x];
        }
    }
    return maior;
}

void radixSort(int* vetor, int tamanho,int expo,int *comparacao,int *trocas){
    int tabelaSaltos[10] = {0},temp[tamanho];

    //incrementa a tabela de decimais
    for(int x=0;x<tamanho;x++){
        (*comparacao)++;
        tabelaSaltos[(vetor[x]/expo)%10]++;
    }

    //organiza os saltos
    for(int x=1;x<10;x++){
        tabelaSaltos[x] = tabelaSaltos[x] + tabelaSaltos[x-1];
    }

    //insere os valores no vetor temporário
    for(int x=tamanho-1;x>=0;x--){
        temp[tabelaSaltos[(vetor[x]/expo)%10]-1] = vetor[x];
        tabelaSaltos[(vetor[x]/expo)%10]--;
    }

    //passa os valores do vetor temporário para o vetor original
    for(int x=0;x<tamanho;x++){
        (*trocas)++;
        vetor[x] = temp[x];
    }
}

void ordenarRadixSort(int *vetor,int tamanho,int *contador,int *trocas){
    int m=0;

    //Ordenação
    m=maximo(vetor,tamanho,contador);
    for(int expo=1;(m/expo)>0;expo*=10){
        radixSort(vetor,tamanho,expo,contador,trocas);
    }
}
