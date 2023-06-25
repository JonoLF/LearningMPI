/**
 * @file ex_15.c
 * @author Ludovic Capelli (l.capelli@epcc.ed.ac.uk)
 * @brief We ask for a dynamic scheduling. When a thread executes an iteration,
 * it lasts for 1 second, except if it thread 0, in which case it lasts 3
 * seconds. Since we use dynamic scheduling, threads 1, 2 and 3 should take the
 * upcoming iterations after they completed they first one. However, thread 0
 * still runs the first two iterations no matter what, as if it was still a 
 * static scheduling that was applied. Why?
 * @copyright Copyright (c) 2023
 **/
#include <epccutil.h>

int main(int argc, char* argv[])
{
    omp_set_num_threads(4);
    // Enable dynamic scheduling.
    omp_set_dynamic(1);
    #pragma omp parallel for default(none) schedule(runtime)
    for(int i = 0; i < 8; i++)
    {
        EPCC_printf("I got iteration %d.\n", i);
        double duration = 1;
        if(omp_get_thread_num() == 0)
        {
            duration = 3;
        }
        double start = omp_get_wtime();
        while((omp_get_wtime() - start) < duration)
        {

        }
    }
    return EXIT_SUCCESS;
}
