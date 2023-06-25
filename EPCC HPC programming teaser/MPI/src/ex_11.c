/**
 * @file ex_11.c
 * @author Ludovic Capelli (l.capelli@epcc.ed.ac.uk)
 * @brief This application illustrates a situtation where there is a large
 * message to send, and a long, independent, computation to perform. The idea is
 * to overlap both. But how?
 * @copyright Copyright (c) 2023
 **/
#include <epccutil.h>

void some_function()
{
    double start = MPI_Wtime();
    while((MPI_Wtime() - start) < 1)
    {
    }
}

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
    EPCC_printf("I'm sending the value.\n");
    if(my_rank == 0)
    {
        int value = my_rank;
        // Imagine this is a 2GB message beyond the eager threshold.
        MPI_Send(&value, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        EPCC_printf("I start working on the function.\n");
        some_function();
    }
    else
    {
        int received;
        MPI_Recv(&received, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        EPCC_printf("Value received %d\n", received);
    }
    MPI_Finalize();
    return EXIT_SUCCESS;
}
