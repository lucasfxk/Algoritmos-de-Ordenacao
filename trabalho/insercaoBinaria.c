#include <stdio.h>
#include <stdlib.h>
#include "insercaoBinaria.h"

void ordenarInsercaoBinaria(int n, int vet[], int *contador, int *trocas){
    int i, j, troca,cont;
    int posicao,valor;

    for(i=0;i<n-1;i++){
        j=i+1;
        cont=0;
        (*contador)++;
        while(j<n){
            (*contador)++;
            if(vet[i]>vet[j]){
            (*trocas)++;
            troca=vet[j];
            vet[j]=vet[i];
            vet[i]=troca;

            if(i>0 && vet[i-1]>vet[i]){
                (*contador)++;
                posicao=buscaBinaria(vet,0,i-1,vet[i],contador);
                valor=vet[i];
                while(i!=posicao){
                    (*trocas)++;
                    vet[i]=vet[i-1];
                    i--;
                    cont++;
                }
                (*trocas)++;
                vet[posicao]=valor;
                i=i+cont;
            }
           }
        break;
        }
    }

}


int buscaBinaria(int vet[], int ini, int fim, int valor, int *contador){
    int meio;
    meio=(ini+fim)/2;
    if(valor==vet[meio]){
        (*contador)++;
        return meio;
    }
    else if(valor>vet[meio]&&valor<=vet[meio+1]){
        (*contador)=(*contador)+2;
        return meio+1;
    }
    else if(valor<vet[meio]&&valor>=vet[meio-1]){
        (*contador)=(*contador)+3;
        return meio;
    }
    else if(valor<vet[meio]){
        (*contador)=(*contador)+4;
        buscaBinaria(vet,ini,meio,valor,contador);
    }
    else if(valor>vet[meio]){
        (*contador)=(*contador)+5;
        buscaBinaria(vet,meio,fim,valor,contador);
    }
}



