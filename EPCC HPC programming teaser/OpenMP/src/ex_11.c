/**
 * @file ex_11.c
 * @author Ludovic Capelli (l.capelli@epcc.ed.ac.uk)
 * @brief For 1 second, a thread spawns tasks which increment a shared variable.
 * However the number of tasks spawned, and the number of increments performed
 * on the variable are not identical, why?
 * @copyright Copyright (c) 2023
 **/
#include <epccutil.h>

int main(int argc, char* argv[])
{
    omp_set_num_threads(4);
    int a = 0;
    #pragma omp parallel reduction(+:a)
    {
        #pragma omp single
        {
            int tasks_spawned = 0;
            double start = omp_get_wtime();
            while((omp_get_wtime() - start) < 1.0)
            {
                #pragma omp task shared(a)
                {
                    a++;
                }
                tasks_spawned++;
            }
            EPCC_printf("%d tasks spawned (i.e: number of increments performed)\n", tasks_spawned);
            #pragma omp taskwait
            EPCC_printf("Final value of a = %d\n", a);
        }
    }
    return EXIT_SUCCESS;
}
