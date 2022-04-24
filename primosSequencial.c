#include <stdio.h>
#include <time.h>
#define Tamanho 100

int main(){
    int i, j, vetor = 0, numeroDivisao, percorreVetor=0, auxLinha , auxColuna;
    FILE *arq;
    int escreverArq;
    clock_t t;

    t = clock();
    
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
        // printf("\n vetor %d %d \n",i, primos[i][0]);
    }


    for (auxLinha=0; auxLinha<Tamanho; auxLinha++) {   
        
        if(primos[auxLinha][1]==0){
            numeroDivisao = primos[auxLinha][0];
            printf("\n %d \n", numeroDivisao);
            for (i=0; i <Tamanho ; i++){ 
                if(primos[i][0]%numeroDivisao==0 && numeroDivisao != primos[i][0]){
                    primos[i][1] = 1;
                }
            }
        }
        printf("\n%d | %d\n", primos[auxLinha][0], primos[auxLinha][1]);
    }

    
    arq = fopen("primos.txt", "wt");

    if (arq == NULL)
    {
        printf("Problemas na criacao do arquivo\n");
        return;
    }
    if(arq == NULL){
        printf("Erro na abertura do arquivo\n");
        return 1;
    }else{
        for (i = 0; i < Tamanho; i++){   
            if(primos[i][1] == 0){
            escreverArq = primos[i][0];
            fprintf(arq, "\n%d\n", escreverArq);
            }    
            
        }
    fclose(arq);

    } 
    t = clock() - t;
    double tempo = ((double)t)/CLOCKS_PER_SEC; 
    printf("levou %f segundos \n", tempo); 
}
    

