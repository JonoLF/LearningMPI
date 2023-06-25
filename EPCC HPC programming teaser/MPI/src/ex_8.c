/**
 * @file ex_8.c
 * @author Ludovic Capelli (l.capelli@epcc.ed.ac.uk)
 * @brief We calculate min and max reductions of certain values using two
 * separate reductions. Merge them so that a single reduction calculates both.
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
    int min;
    int max;
    int value = my_rank * 100;
    MPI_Reduce(&value, &min, 1, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);
    MPI_Reduce(&value, &max, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);
    if(my_rank == 0)
    {
        EPCC_printf("The min value is %d, the max value is %d.\n", min, max);
    }
    MPI_Finalize();
    return EXIT_SUCCESS;
}
