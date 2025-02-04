#include <stdio.h>
#include <stdlib.h>
#include "heapsort.h"

//peguei o código da internet

void ordenarHeapsort(int n, int vet[], int *contador, int *trocas){
    int i, aux;

    for(i=(n/2);i>=0;i--){
        criarHeap(vet,i,n-1,contador,trocas);
    }

    for(i=n-1;i>=1;i--){
        (*trocas)++;
        aux=vet[0];
        vet[0]=vet[i];
        vet[i]=aux;
        criarHeap(vet,0,i-1,contador,trocas);
    }
}

void criarHeap(int v[], int ini, int fim, int *contador, int *trocas){
    int pronto, filhoMaior, auxiliar;

    pronto=0;
    while((ini*2<=fim)&&(pronto==0)){
        if(ini*2==fim){
            (*contador)++;
            filhoMaior=ini*2;
        }
        else if(v[ini*2]>v[ini*2+1]){
            (*contador)=(*contador)+2;
            filhoMaior=ini*2;
        }
        else{
            (*contador)=(*contador)+3;
            filhoMaior=ini*2+1;
        }

        if(v[ini]<v[filhoMaior]){
            (*contador)++;
            (*trocas)++;
            auxiliar=v[ini];
            v[ini]=v[filhoMaior];
            v[filhoMaior]=auxiliar;
            ini=filhoMaior;
        }
        else{
            (*contador)++;
            pronto=1;
        }
        (*contador)++;
    }
}



