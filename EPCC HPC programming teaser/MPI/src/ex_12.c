/**
 * @file ex_12.c
 * @author Ludovic Capelli (l.capelli@epcc.ed.ac.uk)
 * @brief This code uses persistent communications. However, this code does not
 * use them in a meaningful way. Why?
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
        MPI_Request req;
        for(int i = 0; i < 10; i++)
        {
            MPI_Ssend_init(&i, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &req);
            MPI_Start(&req);
            MPI_Wait(&req, MPI_STATUS_IGNORE);
        }
    }
    else
    {
        int received;
        for(int i = 0; i < 10; i++)
        {
            MPI_Recv(&received, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            EPCC_printf("Value received: %d\n", received);
        }
    }
    MPI_Finalize();
    return EXIT_SUCCESS;
}
