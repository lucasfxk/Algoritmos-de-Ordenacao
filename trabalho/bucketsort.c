#include <stdio.h>
#include <stdlib.h>
#include "bucketsort.h"

void quicksortBalde(int *vetor,int inicio, int fim, long long int *comparacao, long long int *trocas){
    if(fim-inicio>=1){
        int l=inicio, r=fim, pivo=(inicio+fim)/2, aux=0;

        while(l <= r){
            while(vetor[l] < vetor[pivo]){
                l++;
                (*comparacao)++;
            }
            while(vetor[r] > vetor[pivo]){
                r--;
                (*comparacao)++;
            }
            if(l<=r){
                (*trocas)++;
                aux = vetor[r];
                vetor[r] = vetor[l];
                vetor[l] = aux;
                l++;
                r--;
            }
        }
        quicksortBalde(vetor,inicio,l-1,comparacao,trocas);
        quicksortBalde(vetor,l,fim,comparacao,trocas);
    }
}

int maior(int* vetor,int tamanho){
    int maximo = vetor[0];
    for(int x=1;x<tamanho;x++){
        if(vetor[x]>maximo){
            maximo = vetor[x];
        }
    }
    return maximo;
}

void ordenarBucketSort(int* vetor,int tamanho,long long int *comparacoes,long long int *trocas){
    int temp[tamanho],numBaldes=10,tabela[/**Quantidade de baldes:*/10]={0},tabelaIniFim[numBaldes][2],baldeIndex = 0,maximo = maior(vetor,tamanho);

    //Ordenação
    baldeIndex = (maximo / numBaldes)+1;
    for(int x=0;x<tamanho;x++){
            tabela[(int)(vetor[x]/baldeIndex)]++;
    }

    for(int x=1;x<numBaldes;x++){
        tabela[x] += tabela[x-1];
    }

    //Cria tabela inicio-fim dos baldes
    for(int x=0;x<numBaldes;x++){
        tabelaIniFim[x][1] = tabela[x];
    }

    tabelaIniFim[0][0] = 0;
    for(int x=1;x<numBaldes;x++){
        tabelaIniFim[x][0] = tabela[x-1];
    }

    //Insere os elementos em seus respectivos baldes(blocos do vetor temp)
    for(int x=tamanho-1;x>=0;x--){
        temp[tabela[(int)(vetor[x]/baldeIndex)]-1] = vetor[x];
        tabela[(int)(vetor[x]/baldeIndex)]--;
    }

    //Passando os valores para o vetor principal
    for(int x=0;x<tamanho;x++){
        (*trocas)++;
        vetor[x] = temp[x];
    }

    //Executa o quicksort nos baldes
    for(int x=0;x<numBaldes;x++){
        quicksortBalde(vetor,tabelaIniFim[x][0],tabelaIniFim[x][1]-1,comparacoes,trocas);
    }
}
