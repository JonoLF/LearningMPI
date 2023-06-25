// BEGIN: 7f3a5b1d7c3f
#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv); // Initialize MPI
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank); // Get current process id
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size); // Get number of processes
    printf("Hello, world from process %d of %d\n", world_rank, world_size);
    MPI_Finalize(); // Finalize MPI
    return 0;
}
// END: 7f3a5b1d7c3f