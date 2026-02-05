/**
 * @file permpure_full.cpp
 * @brief High-performance Permutation Generation Algorithm (Iterative Implementation)
 * * @copyright Copyright (c) 2026 [ Yusheng-Hu ]. All rights reserved.
 * @license This project is licensed under the MIT License - see the LICENSE file for details.
 * * Program Details:
 * - Implements an efficient iterative permutation generation logic.
 * - Features: Cross-platform CPU Affinity binding, High-precision timing (std::chrono), 
 * and optimization-resistant checksums.
 * - Performance: Designed for minimal branch misprediction and low overhead.
 * * Environment:
 * - Platform: Windows / Linux (Auto-switching headers)
 * - Compiler: GCC/MinGW (supports __builtin_LINE) or MSVC
 */
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <vector>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <sched.h>
    #include <pthread.h>
#endif

const int LITTLE_NUMBER = 5;

// #define DEBUG

#ifdef DEBUG
#define COUNT_PURECESS() ProcessCount[__builtin_LINE()]++
#else
#define COUNT_PURECESS() 
#endif

int main(int argc, char* argv[]) {
    // --- Parse Command Line Argument ---
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <n>\n", argv[0]);
        return 1;
    }
    int perm_size = atoi(argv[1]);
    if (perm_size <= 1) {
        fprintf(stderr, "Error: n must be greater than 1.\n");
        return 1;
    }

    // --- Set CPU Affinity for Accurate Benchmarking ---
#ifdef _WIN32
    DWORD_PTR mask = 8; // CPU mask for core 3
    SetThreadAffinityMask(GetCurrentThread(), mask);
#else
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(1, &cpuset);
    sched_setaffinity(0, sizeof(cpu_set_t), &cpuset);
#endif

    unsigned long long checksum = 0;
    unsigned long long ProcessCount[200] = {0};
    int volatile i = 0;
    
    // Use std::vector for dynamic memory management
    std::vector<int> C(perm_size, 0);
    std::vector<int> D(perm_size, 0);
    // M array was initialized but not heavily used in the provided snippet, 
    // keeping it for consistency if needed.
    std::vector<int> M(perm_size, 0); 

    // --- High Precision Timing ---
    auto start = std::chrono::high_resolution_clock::now();

    // Main Algorithm Loop (PP Algorithm)
    while (C[0] < 1) {
        COUNT_PURECESS();
        for (; i < perm_size - 1; ++i) {
            COUNT_PURECESS();
            D[i] = D[C[i]];
            D[C[i]] = i;
        }

        for (int ii = 0; ii < perm_size; ii++) {
            COUNT_PURECESS();
            D[perm_size - 1] = D[ii];
            D[ii] = perm_size - 1;
            
            // Standardizing checksum to match the core logic
            checksum += D[perm_size - 1];

            // Reduced I/O overhead using LITTLE_NUMBER check
            if (perm_size <= LITTLE_NUMBER) {
                printf("\n");
                for (int jj = 0; jj < perm_size; jj++) {
                    printf("%d,", D[jj]);
                }
            }
            D[ii] = D[perm_size - 1];
        }

        D[C[perm_size - 2]] = D[perm_size - 2];

        C[perm_size - 2]++;
        for (i = perm_size - 2; (i > 0) && (C[i] > i); i--) {
            COUNT_PURECESS();
            C[i] = 0;
            C[i - 1]++;
            D[C[i - 1] - 1] = D[i - 1];
        }
    }

    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = finish - start;
    
    // Standardized output for easy parsing
    printf("\nREPORT_START");
    printf("\nALGORITHM: permpure_full");
    printf("\nN_VALUE: %d", perm_size);
    printf("\nEXECUTION_TIME: %lf", duration.count());
    printf("\nCHECKSUM: %llu", checksum);
    printf("\nREPORT_END\n");

#ifdef DEBUG
    // Debug info logic preserved for N
    unsigned long long perm = 1;
    std::vector<unsigned long long> PermValue(perm_size + 1, 0);
    std::vector<unsigned long long> SumPermValue(perm_size + 1, 0);
    PermValue[0] = 1;
    SumPermValue[0] = 0;
    for (int k = 1; k <= perm_size; k++) {
        perm = perm * k;
        PermValue[k] = perm;
        SumPermValue[k] = SumPermValue[k - 1] + perm;
    }
    for (int k = 1; k <= perm_size; k++) {
        printf("\n%u !, %llu, sigma %llu", k, PermValue[k], SumPermValue[k]);
    }
#endif

    return 0;
}