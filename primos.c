#include <stdio.h>
#define Tamanho 29
int main(){
    int i, j, vetor = 0;
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
        for(j=0; j<2; j++){
            if(j==0){
               
            }
        }
        printf("%d\n", primos[i][0]);
        printf("%d\n", primos[i][1]);
    }


} 