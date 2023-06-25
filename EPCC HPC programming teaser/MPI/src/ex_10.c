/**
 * @file ex_10.c
 * @author Ludovic Capelli (l.capelli@epcc.ed.ac.uk)
 * @brief We have an array of 10 integers that we would like to split across two
 * MPI processes using an MPI_Scatter. How should we do it?
 * @copyright Copyright (c) 2023
 **/
#include <epccutil.h>

int main(int argc, char* argv[])
{
    MPI_Init(&argc, &argv);
    int my_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    int values[10] = {0, 500, 100, 600, 200, 700, 300, 800, 400, 900};
    // MPI_Scatter(?)
    MPI_Finalize();
    return EXIT_SUCCESS;
}
