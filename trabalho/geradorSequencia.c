#include <stdio.h>
#include <stdlib.h>

void geradorSequencia(int num, int numeros, int vetor[]){
    int i;

    if(num==1){
        /*for (i=0;i<numeros;i++){ //se eu fizer desse jeito vou ter os mesmos valores sempre
            vetor[i]=rand();
        }

        for (i=0;i<numeros;i++){
            printf ("%d\n", vetor[i]);
        }
        */

        srand(time(NULL)); //inicializa o gerador de n�meros aleat�rios de acordo com a hora atual. Cada execu��o gera valores diferentes

        for (i=0;i<numeros;i++){
            vetor[i]=rand();
        }
    }

    else if(num==2){
        for(i=0;i<numeros;i++){
            vetor[i]=i+1;
        }
    }

    else{
        for(i=0;i<numeros;i++){
            vetor[i]=numeros-i;
        }
    }
}
