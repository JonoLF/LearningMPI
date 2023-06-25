/**
 * @file ex_3.c
 * @author Ludovic Capelli (l.capelli@epcc.ed.ac.uk)
 * @brief A variable is initialised to 123, each threads increments it and
 * prints the new value. However, it does not print the correct value, why?
 * @copyright Copyright (c) 2023
 **/
#include <epccutil.h>

int main(int argc, char* argv[])
{
    omp_set_num_threads(4);
    int a = 123;
    EPCC_printf("Original value of a is %d\n", a);
    #pragma omp parallel private(a)
    {
        a++;
        EPCC_printf("The new value of a is now %d\n", a);
    }
    return EXIT_SUCCESS;
}
