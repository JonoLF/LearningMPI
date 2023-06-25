/**
 * @file ex_4.c
 * @author Ludovic Capelli (l.capelli@epcc.ed.ac.uk)
 * @brief A variable is incremented 1000 times. This is parallelised across four
 * threads. However, the final value of the variable is not 1000 but 4000, why?
 * @copyright Copyright (c) 2023
 **/
#include <epccutil.h>

int main(int argc, char* argv[])
{
    omp_set_num_threads(4);
    int a = 0;
    EPCC_printf("Original value of a is %d\n", a);
    #pragma omp parallel default(none) reduction(+:a)
    {
        for(int i = 0; i < 1000; i++)
        {
            a++;
        }
    }
    EPCC_printf("The final value of a is %d\n", a);
    return EXIT_SUCCESS;
}
