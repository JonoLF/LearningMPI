/**
 * @file ex_12.c
 * @author Ludovic Capelli (l.capelli@epcc.ed.ac.uk)
 * @brief We are trying to apply an OpenMP reduction to two integers. However,
 * they are part of a structure, and the compiler indicates the operation is not
 * available on a structure. Write your own OpenMP reduction operation so that
 * the reduction clause works on the structure two_ints.
 * @copyright Copyright (c) 2023
 **/
#include <epccutil.h>

struct two_ints
{
    int a;
    int b;
};

int main(int argc, char* argv[])
{
    omp_set_num_threads(4);
    struct two_ints ti;
    ti.a = 0;
    ti.b = 0;
    #pragma omp parallel for default(none) shared(ti) /*reduction(+:ti)*/
    for(int i = 0; i < 100; i++)
    {
        ti.a++;
        ti.b++;
    }
    EPCC_printf("Final value of ti.a = %d, ti.b = %d.\n", ti.a, ti.b);
    return EXIT_SUCCESS;
}
