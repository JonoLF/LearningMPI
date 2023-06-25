/**
 * @file ex_2.c
 * @author Ludovic Capelli (l.capelli@epcc.ed.ac.uk)
 * @brief This application runs with 8 MPI processes. All MPI processes that
 * have a rank that is an even number calculate the sum of their rank, likewise
 * for MPI processes that have a rank that is an odd number. With 8 MPI
 * processes, we should get the reduced values 0 + 2 + 4 + 6 = 12, and 1 + 3 + 5
 * + 7 = 16 respectively. However it is not what we obtain, why?
 * @copyright Copyright (c) 2023
 **/
#include <epccutil.h>

int main(int argc, char* argv[])
{
    MPI_Init(&argc, &argv);
    int comm_size;
    MPI_Comm_size(MPI_COMM_WORLD, &comm_size);
    if(comm_size != 8)
    {
        printf("This application is meant to be run with 8 MPI processes, not %d.\n", comm_size);
        MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);
    }
    int my_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    if(my_rank % 2 == 0)
    {
        int result_for_even_ranks = 0;
        MPI_Allreduce(&my_rank, &result_for_even_ranks, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
        EPCC_printf("Value for even ranks = %d\n", result_for_even_ranks);
    }
    else
    {
        int result_for_odd_ranks = 0;
        MPI_Allreduce(&my_rank, &result_for_odd_ranks, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
        EPCC_printf("Value for odd ranks = %d\n", result_for_odd_ranks);
    }
    MPI_Finalize();
    return EXIT_SUCCESS;
}
