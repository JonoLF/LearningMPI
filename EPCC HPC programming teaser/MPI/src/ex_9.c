/**
 * @file ex_9.c
 * @author Ludovic Capelli (l.capelli@epcc.ed.ac.uk)
 * @brief Implement an MPI reduction operation that allows to calculate the
 * average of the values passed (you can assume they are all integers).
 * @copyright Copyright (c) 2023
 **/
#include <epccutil.h>

int main(int argc, char* argv[])
{
    MPI_Init(&argc, &argv);
    int comm_size;
    MPI_Comm_size(MPI_COMM_WORLD, &comm_size);
    if(comm_size != 4)
    {
        printf("This application is meant to be run with 4 MPI processes, not %d.\n", comm_size);
        MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);
    }
    int my_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    int value = my_rank * 100;
    // MPI_Reduce(&value, &avg, 1, MPI_INT, MPI_AVG, 0, MPI_COMM_WORLD);
    MPI_Finalize();
    return EXIT_SUCCESS;
}
