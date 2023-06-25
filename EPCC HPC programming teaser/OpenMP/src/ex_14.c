/**
 * @file ex_14.c
 * @author Ludovic Capelli (l.capelli@epcc.ed.ac.uk)
 * @brief This program gives the right value but, technically, it is still not
 * using OpenMP correctly, why?
 * @copyright Copyright (c) 2023
 **/
#include <epccutil.h>

int main(int argc, char* argv[])
{
    omp_set_num_threads(4);
    int a = 0;
    EPCC_printf("Original value of a is %d\n", a);
    #pragma omp parallel for default(none) shared(a) ordered
    for(int i = 0; i < 1000; i++)
    {
        a++;
    }
    EPCC_printf("The final value of a is %d\n", a);
    return EXIT_SUCCESS;
}
