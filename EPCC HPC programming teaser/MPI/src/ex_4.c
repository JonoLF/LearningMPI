/**
 * @file ex_4.c
 * @author Ludovic Capelli (l.capelli@epcc.ed.ac.uk)
 * @brief How to receive a message whose size is unknown, without using a
 * separate send/recv to exchange the size?
 * @copyright Copyright (c) 2023
 **/
#include <epccutil.h>

int main(int argc, char* argv[])
{
    MPI_Init(&argc, &argv);
    int comm_size;
    MPI_Comm_size(MPI_COMM_WORLD, &comm_size);
    if(comm_size != 2)
    {
        printf("This application is meant to be run with 2 MPI processes, not %d.\n", comm_size);
        MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);
    }
    int my_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    if(my_rank == 0)
    {
        char sentence[] = "Welcome in the EPCC wee programming teaser!";
        MPI_Send(sentence, strlen(sentence), MPI_CHAR, 1, 0, MPI_COMM_WORLD);
    }
    else
    {
        char sentence[200];
        MPI_Recv(sentence, 200, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        EPCC_printf("Sentence received: %s.\n", sentence);
    }
    MPI_Finalize();
    return EXIT_SUCCESS;
}
