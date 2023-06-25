/**
 * @file ex_1.c
 * @author Ludovic Capelli (l.capelli@epcc.ed.ac.uk)
 * @brief The objective is to write an application using 4 MPI processes,
 * and print "Hello world from MPI process <my_rank>, we are <# MPI processes>
 * MPI processes.".
 * @copyright Copyright (c) 2023
 **/
#include <epccutil.h>

int main(int argc, char* argv[])
{
    int my_rank; // To define
    int mpi_process_count; // To define
    printf("Hello world from MPI process %d (we are %d MPI processes).\n", my_rank, mpi_process_count);
    return EXIT_SUCCESS;
}
