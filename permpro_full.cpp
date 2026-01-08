/**
 * @file permpro_full.cpp
 * @brief High-performance Permutation Generation Algorithm (Iterative Implementation)
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
 * Adjust the 'PERM_SIZE' macro to change the permutation set size. 
 * Note: PERM_SIZE > 14 may require significant time.
 */
#include "stdio.h"
#include "time.h"
#include "windows.h" // Add Windows API header file
#ifndef PERM_SIZE
#define PERM_SIZE 12
#endif
#define LittleNumber 5

// #define DEBUG

#ifdef DEBUG
#define COUNT_PROCESS() ProcessCount[__builtin_LINE()]++
#else
#define COUNT_PROCESS() // Empty definition, no operation in non-DEBUG mode
#endif

int main() {
  
  // Bind to CPU core (core 3)
  DWORD_PTR mask = 8; // CPU mask for core 3 (1 << 3 = 8)
  HANDLE thread = GetCurrentThread();
  SetThreadAffinityMask(thread, mask);
  // Add checksum to prevent over-optimization
  unsigned long long checksum = 0;

  unsigned long long ProcessCount[200] = {0};
  int volatile i = 0;
  int j = 0;
  int C[PERM_SIZE] = {0}, D[PERM_SIZE] = {0}, M[PERM_SIZE] = {0};

  // High precision timer variables
  LARGE_INTEGER start, finish, frequency;
  double duration;

  // Get high precision timer frequency
  QueryPerformanceFrequency(&frequency);
  // Record start time
  QueryPerformanceCounter(&start);

  while (C[0] < 1) {
    COUNT_PROCESS();
    for (; i < PERM_SIZE-1; ++i) {
      COUNT_PROCESS();
      D[i] = D[C[i]];
      D[C[i]] = i;
    }

    for (int ii = 0; ii < PERM_SIZE; ii++)
    {
      COUNT_PROCESS();
      D[PERM_SIZE-1] = D[ii];
      D[ii] = PERM_SIZE-1;
      checksum += D[PERM_SIZE-1];

#if PERM_SIZE <= LittleNumber
      // Print D array
      printf("\n");
      for (int jj = 0; jj < PERM_SIZE; jj++) {
        printf("%d,", D[jj]);
      }
#endif
      D[ii] = D[PERM_SIZE-1];
    }

    D[C[PERM_SIZE - 2]] = D[PERM_SIZE - 2];

    C[PERM_SIZE - 2]++;
    for (i = PERM_SIZE - 2; (i > 0) && (C[i] > i); i--) {
      COUNT_PROCESS();
      C[i] = 0;
      C[i - 1]++;
      D[C[i - 1] - 1] = D[i - 1];
    }
  }

  // Record end time
  QueryPerformanceCounter(&finish);
  // Calculate duration (seconds) = (end count - start count) / frequency
  duration = (double)(finish.QuadPart - start.QuadPart) / frequency.QuadPart;
  printf("\npermpro_full\t%u\t%lf", PERM_SIZE, duration);

  // Prevent the compiler from optimizing too much
  printf("\nD[PERM_SIZE-1] = %d, checksum = %llu", D[PERM_SIZE-1], checksum);

#ifdef DEBUG
  unsigned long long perm = 1;
  unsigned long long PermValue[PERM_SIZE] = {0};
  unsigned long long SumPermValue[PERM_SIZE] = {0};
  PermValue[0] = 1;
  SumPermValue[0] = 0;
  for (i = 1; i <= PERM_SIZE; i++) {
    perm = perm * i;                              // Calculate factorial: perm = i!
    PermValue[i] = perm;                          // Store current factorial value
    SumPermValue[i] = SumPermValue[i - 1] + perm; // Calculate cumulative factorial sum
  }

  // Print i, permvalue, SumPermvalue
  for (i = 1; i <= PERM_SIZE; i++) {
    printf("\n%u !, %llu, sigma %llu", i, PermValue[i], SumPermValue[i]);
  }

  for (i = 0; i < 100; i++)
    if (ProcessCount[i] > 0)
      printf("\n [Line %u]%llu", i, ProcessCount[i]);
#endif

  return 0;
}