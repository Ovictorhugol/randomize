#include <stdio.h>
#define Tamanho 1000
int main(){
    int i, j, vetor = 0, numeroDivisao, percorreVetor=0, auxLinha , auxColuna;;
    int primos[Tamanho][2]= {{0},{0}};

    for(i=0; i < Tamanho; i++){    
        vetor  += 1; 
        primos[i][1]= 0;// preenche o vetor de baixo com 0
        if(i==0){
            //preencher vetor de cima a partir do numero 2
            primos[i][0]= 2;
            vetor = 2;
        }
        primos[i][0]= vetor;
        printf("\n vetor %d %d \n",i, primos[i][0]);
    }
    for (auxLinha=0; auxLinha<Tamanho; auxLinha++) {      
        if(primos[auxLinha][1]==0){
            numeroDivisao = primos[auxLinha][0];
            for (i=0; i <Tamanho ; i++){ 
                if(primos[i][0]%numeroDivisao==0 && numeroDivisao != primos[i][0]){
                    primos[i][1] = 1;
                }
            }
        }
        printf("\n%d | %d\n", primos[auxLinha][0], primos[auxLinha][1]);
    }
} 
    

