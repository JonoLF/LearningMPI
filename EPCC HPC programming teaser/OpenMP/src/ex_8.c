/**
 * @file ex_8.c
 * @author Ludovic Capelli (l.capelli@epcc.ed.ac.uk)
 * @brief In this exercise there is a variable that is incremented, and
 * decremented in each iteration, for one second. To prevent concurrent accesses,
 * both the increment and decrement operations are placed in a critical
 * construct. However, the value obtained at the end, which should be zero, is
 * not correct, why?
 * @copyright Copyright (c) 2023
 **/
#include <epccutil.h>

int main(int argc, char* argv[])
{
    omp_set_num_threads(4);
    int a = 0;
    #pragma omp parallel default(none) shared(a)
    {
        double start = omp_get_wtime();
        while((omp_get_wtime() - start) < 1.0)
        {
            #pragma omp critical(increment)
            {
                a++;
            }
            #pragma omp critical(decrement)
            {
                a--;
            }
        }
        #pragma omp single
        {
            EPCC_printf("Final value = %d\n", a);
        }
    }
    return EXIT_SUCCESS;
}
