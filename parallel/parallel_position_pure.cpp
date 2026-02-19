/*
 * @file parallel_position_pure.cpp
 * @brief High-performance Permutation Generation Algorithm (parallel Implementation for 2 core)
 * * @copyright Copyright (c) 2024 [ Yusheng-Hu ]. All rights reserved.
 * @license This project is licensed under the MIT License - see the LICENSE file for details.
 * * Program Details:
 * - Implements an efficient iterative permutation generation logic.
 * - Features: Windows CPU Affinity binding, High-precision timing (QPC), 
 * and optimization-resistant checksums.
 * - Performance: Designed for minimal branch misprediction and low overhead.
 * * Environment:
 * - Platform: Windows (Requires <windows.h>)
 * - Compiler: GCC/MinGW (supports __builtin_LINE) or MSVC
 * * Usage:
 * - Input perm_size via command line argument
 */

#include <stdio.h>
#include <windows.h>
#include <process.h>
#include <chrono>

#define LittleNumber 5

struct CoreResult {
    alignas(64) unsigned long long chk;
    unsigned long long cnt;
    double dt;
};
CoreResult g_res[2];

struct ThreadArgs {
    int id;
    int perm_size;
};

unsigned __stdcall run_pp_fast(void* arg) {
    ThreadArgs* args = (ThreadArgs*)arg;
    int id = args->id;
    int perm_size = args->perm_size;
    SetThreadAffinityMask(GetCurrentThread(), (DWORD_PTR)1 << (id * 2));
    auto start_time = std::chrono::high_resolution_clock::now();
	
    int i = 0;
    int C[16] = {0};
    int D[16] = {0};
    for (int k = 0; k < perm_size; k++) D[k] = k;

    // Only 2 CPU core. If core count is 3, 6, etc., need special task allocation.
    C[1] = id;

    unsigned long long local_chk = 0;
    unsigned long long local_cnt = 0;

    while (C[1] == id) {
        for (; i < perm_size-1; ++i) {
            D[i] = D[C[i]];
            D[C[i]] = i;
        }
    
        for (int ii = 0; ii < perm_size; ii++)
        {
            D[perm_size-1] = D[ii];
            D[ii] = perm_size-1;
            local_chk += D[perm_size-1];
            local_cnt++;
            
            if (perm_size <= LittleNumber) {
                // Print D array
                printf("\n");
                for (int jj = 0; jj < perm_size; jj++) {
                    printf("%d,", D[jj]);
                }
            }
            D[ii] = D[perm_size-1];
        }
    
        D[C[perm_size - 2]] = D[perm_size - 2];
    
        C[perm_size - 2]++;
        for (i = perm_size - 2; (i > 0) && (C[i] > i); i--) {
            C[i] = 0;
            C[i - 1]++;
            D[C[i - 1] - 1] = D[i - 1];
        }
        }

    auto end_time = std::chrono::high_resolution_clock::now();
    g_res[id].dt = std::chrono::duration<double>(end_time - start_time).count();
    g_res[id].chk = local_chk;
    g_res[id].cnt = local_cnt;
    
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <n>\n", argv[0]);
        return 1;
    }
    int perm_size = atoi(argv[1]);
    if (perm_size <= 1) {
        printf("Error: n must be greater than 1.\n");
        return 1;
    }

    printf("N=%d PP Algorithm | Dual-Core Speed Mode\n", perm_size);
    unsigned long long total_perm = 1;
    for (int k = 2; k <= perm_size; k++) total_perm *= k;
    printf("Task: %llu permutations total.\n", total_perm);

    HANDLE h[2];
    ThreadArgs args[2] = {{0, perm_size}, {1, perm_size}};

    h[0] = (HANDLE)_beginthreadex(NULL, 0, run_pp_fast, &args[0], 0, NULL);
    h[1] = (HANDLE)_beginthreadex(NULL, 0, run_pp_fast, &args[1], 0, NULL);

    WaitForMultipleObjects(2, h, TRUE, INFINITE);

    printf("\n--- SPEED REPORT ---\n");
    for (int i = 0; i < 2; i++) {
        printf("Core %d: Time = %.4fs | Throughput = %.2f B/s\n", 
               i, g_res[i].dt, (double)g_res[i].cnt / g_res[i].dt / 1e9);
    }
    printf("--------------------------\n");
    printf("TOTAL COUNT:    %llu\n", g_res[0].cnt + g_res[1].cnt);

    CloseHandle(h[0]); CloseHandle(h[1]);
    return 0;
}
