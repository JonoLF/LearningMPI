/**
 * @file ex_6.c
 * @author Ludovic Capelli (l.capelli@epcc.ed.ac.uk)
 * @brief The objective here is to parallelise this fibonacci implementation
 * using tasks. (For reference: fibonacci(30) = 832,040)
 * @copyright Copyright (c) 2023
 **/
#include <epccutil.h>

int fibonacci(int n)
{
    int result = 0;
    if(n < 2)
    {
        result = n;
    }
    else
    {
        result = fibonacci(n-1) + fibonacci(n-2);
    }
    return result;
}

int main(int argc, char* argv[])
{
    omp_set_num_threads(4);
    int n = 30;
    #pragma omp parallel
    {
        #pragma omp single
        {
            EPCC_printf("Fibonacci of %d = %d\n", n, fibonacci(n));
        }
    }
    return EXIT_SUCCESS;
}
