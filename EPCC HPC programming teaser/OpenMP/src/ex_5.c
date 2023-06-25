/**
 * @file ex_5.c
 * @author Ludovic Capelli (l.capelli@epcc.ed.ac.uk)
 * @brief We want to calculate three separate fibonaccis in parallel, using
 * OpenMP sections. The actual implementation of the fibonacci function must
 * remain sequential.
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
        return fibonacci(n-1) + fibonacci(n-2);
    }
    return result;
}

int main(int argc, char* argv[])
{
    omp_set_num_threads(4);
    int n1 = 5;
    int n2 = 6;
    int n3 = 7;
    EPCC_printf("Fibonacci of %d = %d\n", n1, fibonacci(n1));
    EPCC_printf("Fibonacci of %d = %d\n", n1, fibonacci(n1));
    EPCC_printf("Fibonacci of %d = %d\n", n1, fibonacci(n1));
    return EXIT_SUCCESS;
}
