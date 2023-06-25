/**
 * @file ex_2.c
 * @author Ludovic Capelli (l.capelli@epcc.ed.ac.uk)
 * @brief This application is meant to show the total number of threads, but it
 * always prints 1, despite having 4 threads.
 * @copyright Copyright (c) 2023
 **/
#include <epccutil.h>

int main(int argc, char* argv[])
{
    omp_set_num_threads(4);
    int num_threads = omp_get_num_threads();
    #pragma omp parallel
    {
        EPCC_printf("Present.\n");

        // A barrier just for a cleaner output
        #pragma omp barrier

        #pragma omp single
        {
            printf("We are %d threads.\n", num_threads);
        }
    }
    return EXIT_SUCCESS;
}
