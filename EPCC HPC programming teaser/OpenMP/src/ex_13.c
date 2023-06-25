/**
 * @file ex_13.c
 * @author Ludovic Capelli (l.capelli@epcc.ed.ac.uk)
 * @brief There are two parallel constructs. Without merging them, and without
 * turning the variable a in an array, how can you ensure that each thread gets
 * to access its own previous value of a in the second parallel construct?
 * @copyright Copyright (c) 2023
 **/
#include <epccutil.h>

int a = 0;

int main(int argc, char* argv[])
{
    omp_set_num_threads(4);
    #pragma omp parallel default(none) shared(a)
    {
        int my_thread_id = omp_get_thread_num();
        a += my_thread_id * 100;
        EPCC_printf("Value of my a at the end of the 1st parallel construct = %d\n", a);
    }
    #pragma omp parallel default(none) shared(a)
    {
        EPCC_printf("Value of my a at the start of the 2nd parallel construct = %d\n", a);
    }
    return EXIT_SUCCESS;
}
