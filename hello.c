#include <stdio.h>
#include <string.h>
#include "mpi.h"
main(int argc, char *argv[])
{
        int ret, rank, size, i, tag;
        double time;
        MPI_Status status;
        char message[12];

        ret = MPI_Init(&argc, &argv);

        ret = MPI_Comm_rank(MPI_COMM_WORLD, &rank);
        ret = MPI_Comm_size(MPI_COMM_WORLD, &size);

        tag=100;
        if (rank == 2)
        {
                time = MPI_Wtime();
                strcpy(message,"Ola, Mundo!");

                for (i=0; i<size; i++)
                        ret = MPI_Send(message, 12, MPI_CHAR, i, tag, MPI_COMM_WORLD);
                time = MPI_Wtime() - time;        
        }
        else
                ret = MPI_Recv(message, 12, MPI_CHAR, 0, tag, MPI_COMM_WORLD, &status);
        printf("Mensagem do no %d : %s\n", rank, message);
        printf("Tempo decorrido no processo = %f\n",time); 
        ret = MPI_Finalize();
}