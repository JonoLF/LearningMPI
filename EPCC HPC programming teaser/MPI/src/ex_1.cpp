#include <mpi.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char *argv[])
{
    int rank, size, ierr;
    ierr = MPI_Init(&argc, &argv); // Initialize MPI
    ierr = MPI_Comm_rank(MPI_COMM_WORLD, &rank); // Get current process id
    ierr = MPI_Comm_size(MPI_COMM_WORLD, &size); // Get number of processes
    MPI_Finalize(); // Finalize MPI
    printf("Hello world from process %d of %d\n", rank, size);
    return 0;
}