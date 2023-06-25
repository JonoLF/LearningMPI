/**
 * @file ex_7.c
 * @author Ludovic Capelli (l.capelli@epcc.ed.ac.uk)
 * @brief How to order MPI processes so that each MPI process, in turn, prints
 * the given message?
 * @copyright Copyright (c) 2023
 **/
#include <epccutil.h>

int main(int argc, char* argv[])
{
    MPI_Init(&argc, &argv);
    EPCC_printf("My turn to print the message.\n");
    // [MPI process 0] My turn to print the message.
    // Then, [MPI process 1] My turn to print the message.
    // Then, [MPI process 2] My turn to print the message.
    // Then, [MPI process ...] My turn to print the message.
    // Then, [MPI process n-1] My turn to print the message.
    MPI_Finalize();
    return EXIT_SUCCESS;
}
