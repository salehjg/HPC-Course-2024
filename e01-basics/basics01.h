//
// Created by saleh on 3/24/24.
//

#pragma once

#include <iostream>
#include <omp.h>

using namespace std;

void RunBasics01() {

#pragma omp parallel
    {
        int id = omp_get_thread_num();
        int cnt = omp_get_num_threads();
#pragma omp critical (critical01)
        {
            cout << "This is thread " << id << " of " << cnt << endl;
        }

    }


    /*
    {
        // This will spawn a group (cpu core count) of threads, each one running a copy of the for loop for itself with 64 iterations.
#pragma omp parallel
        {
            for (int i=0; i < 64; i++){
                int id = omp_get_thread_num();
                int cnt = omp_get_num_threads();
#pragma omp critical (critical01)
                {
                    std::cout<<"This is iter " << i << " thread " << id << " of " << cnt << std::endl;
                }

            }
        }
    }
    */

    /*
    {
        // This one will create a group of threads, each one running only 2 iterations of the loop to parallelize the loop.
        // We can replace the fused directive into these successive ones:
        // #pragma omp parallel // for creating parallel region
        // #pragma omp for // for scheduling the iterations into the threads of the group.

#pragma omp parallel for // defaults to static scheduling with the default chunk size.

//#pragma omp parallel for schedule(static) // With this one, chunk size is defaulted to (#iters/#threads).
//#pragma omp parallel for schedule(static, 2) // With this one, thread0 gets iter0 and iter1. (2 is the chunk size)
//#pragma omp parallel for schedule(static, 1)  // With this one, thread0 gets iter0 and iter32 (round-robin scheduling)

//#pragma omp parallel for schedule(dynamic)  // if threads have different unbalanced workload, dynamic scheduling would be useful. With dynamic scheduling, a thread might get more than 2 iters while another getting only 1 iter.
//#pragma omp parallel for schedule(dynamic, 1)  // chunk size of 1 is the default.

//#pragma omp parallel for schedule(guided, 2) /// TODO: not sure about this one, read the docs.
        for (int i=0; i < 64; i++){
            int id = omp_get_thread_num();
            int cnt = omp_get_num_threads();
#pragma omp critical (critical01)
            {
                std::cout<<"This is iter " << i << " thread " << id << " of " << cnt << std::endl;
            }
        }
    }
    */

    /*
    {
        // Critical regions are global to the program. If no unique name is provided, they will be serialized to an specific thread.
        // Make sure to provide a particular name for each critical region.
        // #pragma omp critical (THE_NAME)
    }
    */
}