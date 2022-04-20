#include <stdio.h>
#define Numero 3
#include <time.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <time.h>

 int main(){

    int vetorNumeros[Numero][Numero] = {{0}};
    int i ,numeroAleatorio, numeroAchado, j;
    clock_t t;
    t = clock();
    srand(time(NULL));
    
 
    for (i = 0; i <= Numero; i++){
       for(j = 0; j <= Numero; j++){
         numeroAleatorio = rand() % 5000000;
         vetorNumeros[i][j] = numeroAleatorio;
         printf("linha %d e coluna %d : %d\n",i,j, vetorNumeros[i][j]);      
       }
        
    }
    i = 0;
    j = 0;
    do{
        
         if(vetorNumeros[i][j] == numeroAchado){
            printf("Achei o do vetor e %d e o numeroAchado e %d \n",vetorNumeros[i][j], numeroAchado );
            numeroAchado= 0;
            i++;
            j++;
         }else{
            numeroAchado++;
         }     
    }while(i<=Numero&&j<= Numero);
   
   t = clock() - t;
   double tempo = ((double)t)/CLOCKS_PER_SEC; 
  
   printf("levou %f segundos \n", tempo);

 }