/**
 * @file ex_7.c
 * @author Ludovic Capelli (l.capelli@epcc.ed.ac.uk)
 * @brief The objective in this exercise is to somehow limit the number of tasks
 * that are generated during recursion.
 * @copyright Copyright (c) 2023
 **/
#include <epccutil.h>

int fibonacci(int n)
{
    if(n < 2)
    {
        return n;
    }
    else
    {
        int fib1;
        #pragma omp task default(none) shared(fib1) firstprivate(n)
        {
             fib1 = fibonacci(n-1);
        }
        int fib2;
        #pragma omp task default(none) shared(fib2) firstprivate(n)
        {
             fib2 = fibonacci(n-2);
        }
        #pragma omp taskwait
        return fib1 + fib2;
    }
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
