#include <stdio.h>
#include <stdlib.h>
#include "heapsort.h"

void criarHeap(int v[], int ini, int fim, long long int *contador, long long int *trocas){
    int pronto, filhoMaior, auxiliar;

    pronto=0;
    while((ini*2<=fim)&&(pronto==0)){
        (*contador)++;
        if(ini*2==fim){
            filhoMaior=ini*2;
        }
        else if(v[ini*2]>v[ini*2+1]){
            filhoMaior=ini*2;
        }
        else{
            filhoMaior=ini*2+1;
        }

        (*contador)++;
        if(v[ini]<v[filhoMaior]){

            (*trocas)++;
            auxiliar=v[ini];
            v[ini]=v[filhoMaior];
            v[filhoMaior]=auxiliar;
            ini=filhoMaior;
        }
        else{
            pronto=1;
        }
    }
}

void ordenarHeapsort(int n, int vet[], long long int *contador, long long int *trocas){
    int i, aux;

    //Constrói a max-heap
    for(i=(n/2);i>=0;i--){
        criarHeap(vet,i,n-1,contador,trocas);
    }

    //Ordenação
    //Extrai o maior elemento do heap e reorganiza
    for(i=n-1;i>=1;i--){
        (*trocas)++;
        aux=vet[0];
        vet[0]=vet[i];
        vet[i]=aux;
        criarHeap(vet,0,i-1,contador,trocas);
    }
}





