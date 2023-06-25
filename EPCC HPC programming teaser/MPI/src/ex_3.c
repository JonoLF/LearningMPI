/**
 * @file ex_3.c
 * @author Ludovic Capelli (l.capelli@epcc.ed.ac.uk)
 * @brief Even if this application may not crash on certain MPI implementations,
 * it remains that it this source code is not valid. Why?
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
        int buffer_size = 1 * sizeof(int);
        int* buffer = (int*)malloc(buffer_size);
        MPI_Buffer_attach(buffer, buffer_size);
        int value = 1234;
        MPI_Bsend(&value, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Buffer_detach(buffer, &buffer_size);
        free(buffer);
    }
    else
    {
        int value;
        MPI_Recv(&value, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        EPCC_printf("Value received = %d\n", value);
    }
    MPI_Finalize();
    return EXIT_SUCCESS;
}
