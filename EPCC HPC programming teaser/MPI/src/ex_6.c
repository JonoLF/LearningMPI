/**
 * @file ex_6.c
 * @author Ludovic Capelli (l.capelli@epcc.ed.ac.uk)
 * @brief The order of communication in this application (though correct) is
 * inefficient. Why? How to improve it (without actually changing the MPI_Ssend
 * routines called, just by reordering of communications.)
 * @copyright Copyright (c) 2023
 **/
#include <epccutil.h>

int main(int argc, char* argv[])
{
    MPI_Init(&argc, &argv);
    int comm_size;
    MPI_Comm_size(MPI_COMM_WORLD, &comm_size);
    if(comm_size != 10)
    {
        printf("This application is meant to be run with 10 MPI processes, not %d.\n", comm_size);
        MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);
    }
    int my_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    if(my_rank < comm_size - 1)
    {
        int value = my_rank * 200;
        MPI_Send(&value, 1, MPI_INT, (my_rank + 1) % comm_size, 0, MPI_COMM_WORLD);
    }
    if(my_rank > 0)
    {
        int value;
        MPI_Send(&value, 1, MPI_INT, (comm_size + my_rank - 1) % comm_size, 0, MPI_COMM_WORLD);
    }
    if(my_rank < comm_size - 1)
    {
        int value;
        MPI_Recv(&value, 1, MPI_INT, (my_rank + 1) % comm_size, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        EPCC_printf("Value received: %d.\n", value);
    }
    if(my_rank > 0)
    {
        int value;
        MPI_Recv(&value, 1, MPI_INT, (comm_size + my_rank - 1) % comm_size, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        EPCC_printf("Value received: %d.\n", value);
    }
    MPI_Finalize();
    return EXIT_SUCCESS;
}
