/**
 * @file ex_10.c
 * @author Ludovic Capelli (l.capelli@epcc.ed.ac.uk)
 * @brief For 1 second, threads increment a variable, there are two approaches
 * available. The first approach is noticeably slower than the second approach,
 * why?
 * @copyright Copyright (c) 2023
 **/
#include <epccutil.h>

void first_approach()
{
    int n[4] = {0};
    #pragma omp parallel default(none) shared(n)
    {
        int my_thread_id = omp_get_thread_num();
        double start = omp_get_wtime();
        while((omp_get_wtime() - start) < 1.0)
        {
            n[my_thread_id]++;
        }
        EPCC_printf("My value = %d.\n", n[my_thread_id]);
    }
}

void second_approach()
{
    #pragma omp parallel default(none)
    {
        int my_n = 0;
        double start = omp_get_wtime();
        while((omp_get_wtime() - start) < 1.0)
        {
            my_n++;
        }
        EPCC_printf("My value = %d.\n", my_n);
    }
}

int main(int argc, char* argv[])
{
    omp_set_num_threads(4);
    first_approach();
    second_approach();
    return EXIT_SUCCESS;
}
