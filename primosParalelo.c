#include <stdio.h>
#include <time.h>
#define Tamanho 100000
#include "mpi.h"
main(int argc, char *argv[]){

    int ret, rank, size, tag;
    double time;
    MPI_Status status;
    int tamanhoVetor [12];
    int i, j, vetor = 0, numeroDivisao, percorreVetor=0, auxLinha , auxColuna, vetorPrimeiraMetade, vetorSegundaMetade;
    FILE *arq;
    int escreverArq;
    int primos[Tamanho][2]= {{0},{0}};
    

    ret = MPI_Init(&argc, &argv);
    ret = MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    ret = MPI_Comm_size(MPI_COMM_WORLD, &size);

    tag=100;

    


    
    if (rank == 0)
    {
            time = MPI_Wtime();
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
            vetorPrimeiraMetade = Tamanho / 2; 
            vetorSegundaMetade = Tamanho / 2;
            for (i=1; i<size; i++)
                    ret = MPI_Send(vetorPrimeiraMetade, 12, MPI_CHAR, i, tag, MPI_COMM_WORLD);
            time = MPI_Wtime() - time;        
    }
    else
            ret = MPI_Recv(message, 12, MPI_CHAR, 0, tag, MPI_COMM_WORLD, &status);
    printf("Mensagem do no %d : %s\n", rank, message);
    printf("Tempo decorrido no processo = %f\n",time); 
    ret = MPI_Finalize();

    clock_t t;
    t = clock();

    

    


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

    
    arq = fopen("primos.txt", "wt");

    if (arq == NULL)
    {
        printf("Problemas na CRIACAO do arquivo\n");
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
    

