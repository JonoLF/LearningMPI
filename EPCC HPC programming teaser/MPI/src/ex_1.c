/**
 * @file ex_1.c
 * @brief The objective is to write an application using 4 MPI processes,
 * and print "Hello world from MPI process <my_rank>, we are <# MPI processes>
 * MPI processes.".
 **/
#include <mpi.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int my_rank; // To define
    int mpi_process_count; // To define
    int ierr;
    ierr = MPI_Init(&argc, &argv);
    ierr = MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    ierr = MPI_Comm_size(MPI_COMM_WORLD, &mpi_process_count);
    MPI_Finalize();
    printf("Hello world from MPI process %d (we are %d MPI processes).\n", my_rank, mpi_process_count);
    return 0;
}
