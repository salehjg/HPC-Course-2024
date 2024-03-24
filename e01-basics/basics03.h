//
// Created by saleh on 3/24/24.
//

#pragma once

#include <iostream>
#include <omp.h>

using namespace std;

void RunBasics03() {
    {
        // Reduction Operator
        int a = 0;
#pragma omp parallel for reduction (+:a)
        for (int i = 0; i < 100; i++) {
            // `i` is private to each thread in the group.
            // `a` is shared for the threads in the group, since it is the default for omp parallel for
            a += i;
        }
        cout << "Reduced value is " << a << endl;
    }
}