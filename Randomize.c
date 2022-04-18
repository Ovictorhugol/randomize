#include <stdio.h>
#define Numero 1000
#include <time.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <time.h>

 int main(){

    int vetorNumeros[Numero] = {{0}};
    int i ,numeroAleatorio, numeroAchado;
    clock_t t;
    t = clock();
    srand(time(NULL));
    
 
    for (i = 0; i <= Numero; i++){
       
        numeroAleatorio = rand() % 5000000;
        vetorNumeros[i] = numeroAleatorio;
        printf("posicao %d: %d\n",i, vetorNumeros[i]);
    }
    i = 0;
    
    do{
        
         if(vetorNumeros[i] == numeroAchado){
            printf("Achei o do vetor e %d e o numeroAchado e %d \n",vetorNumeros[i], numeroAchado );
            numeroAchado= 0;
            i++;
         }else{
            numeroAchado++;
         }     
    }while(i<=Numero);
   
   t = clock() - t;
   double tempo = ((double)t)/CLOCKS_PER_SEC; 
  
   printf("levou %f segundos \n", tempo);

 }