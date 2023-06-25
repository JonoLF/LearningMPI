/**
 * @file ex_1.c
 * @author Ludovic Capelli (l.capelli@epcc.ed.ac.uk)
 * @brief The objective is to write an application that uses multithreading via
 * OpenMP, and print "Hello world from thread <my_thread_id>, we are <# threads>
 * threads.".
 * @copyright Copyright (c) 2023
 **/
#include <epccutil.h>

int main(int argc, char* argv[])
{
    omp_set_num_threads(4);
    int my_thread_id; // To define
    int thread_count; // To define
    printf("Hello world from thread %d (we are %d thread).\n", my_thread_id, thread_count);
    return EXIT_SUCCESS;
}
