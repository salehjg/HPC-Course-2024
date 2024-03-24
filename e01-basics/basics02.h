//
// Created by saleh on 3/24/24.
//

#pragma once

#include <iostream>
#include <omp.h>

using namespace std;

void RunBasics02() {
    {
        // Barriers could be defined explicitly as in:
        //      #pragma omp barrier
        // Implicit barriers are present for all of these at their end:
        //      #pragma omp for
        //      #pragma omp sections
        //      #pragma omp single
        // But #pragma omp master does NOT have the implicit barrier at its end!
        // omp master is like omp single, but the master thread (thread0) handles it, instead of an unknown thread.
        // So, by replacing #pragma omp single's with omp master, we can get some speed up.
        // When omp single finishes, all the other threads should be synced at its end.  This is not the case for omp master.

        /*
#pragma omp parallel
        {
            int id = omp_get_thread_num();
            int cnt = omp_get_num_threads();
#pragma omp single
            {
                cout << "This is thread " << id << " of " << cnt << endl;
            } // <-------------------------------------------------------------- THERE IS AN IMPLICIT BARRIER HERE
            cout << "Thread " << id << " is done." << endl;
        }
        */

        /*
#pragma omp parallel
        {
            int id = omp_get_thread_num();
            int cnt = omp_get_num_threads();
#pragma omp master
            {
                cout << "This is thread " << id << " of " << cnt << endl;
            } // <-------------------------------------------------------------- NO BARRIER HERE.
            cout << "Thread " << id << " is done." << endl;
        }
        */

        /*
        {
            /// TODO: What is `omp section` ?
        }
        */

        /*
        {
            // Variables could be private, threadprivate, shared.
            //  * private variables are not initialized.
            //      - firstprivate: init the private copy with the current value
            //      - lastprivate : copy the last value of the private copy into the previous region when done.
            //  * The default for `omp parallel` is shared.
            //  * The default for `omp task` is firstprivate.
            //  * Loop control variables are private (not initialized with the value from the parent region).
            //  * static variables are shared.
        }
        */

    }
}