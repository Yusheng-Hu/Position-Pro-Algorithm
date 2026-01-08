/**
 * @file heap_perm.cpp
 * @brief Heap's Permutation Generation Algorithm (Iterative Implementation)
 * * Program Details:
 * - Implements Heap's algorithm for permutation generation in iterative form.
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
  int i, j;
  int D[PERM_SIZE]; // Permutation array
  int c[PERM_SIZE]; // Control array

  // Initialize permutation array
  for (i = 0; i < PERM_SIZE; i++) {
    D[i] = i;
    c[i] = 0;
  }

  // High precision timer variables
  LARGE_INTEGER start, finish, frequency;
  double duration;

  // Get high precision timer frequency
  QueryPerformanceFrequency(&frequency);
  // Record start time
  QueryPerformanceCounter(&start);

  // Heap's algorithm (iterative version)
  // Print and add initial permutation to checksum
#if PERM_SIZE <= LittleNumber
  // Print D array
  printf("\n");
  for (j = 0; j < PERM_SIZE; j++) {
    printf("%d,", D[j]);
  }
#endif
  for (i = 0; i < PERM_SIZE; i++) {
    checksum += D[i];
  }

  i = 1;
  while (i < PERM_SIZE) {
    COUNT_PROCESS();
    if (c[i] < i) {
      COUNT_PROCESS();
      if (i % 2 == 0) {
        // Swap 0 and i
        int temp = D[0];
        D[0] = D[i];
        D[i] = temp;
      } else {
        // Swap c[i] and i
        int temp = D[c[i]];
        D[c[i]] = D[i];
        D[i] = temp;
      }

      // Print and add current permutation to checksum
#if PERM_SIZE <= LittleNumber
      // Print D array
      printf("\n");
      for (j = 0; j < PERM_SIZE; j++) {
        printf("%d,", D[j]);
      }
#endif
      for (j = 0; j < PERM_SIZE; j++) {
        checksum += D[j];
      }

      c[i]++;
      i = 1;
    } else {
      COUNT_PROCESS();
      c[i] = 0;
      i++;
    }
  }

  // Record end time
  QueryPerformanceCounter(&finish);
  // Calculate duration (seconds) = (end count - start count) / frequency
  duration = (double)(finish.QuadPart - start.QuadPart) / frequency.QuadPart;
  printf("\nheap_perm\t%u\t%lf", PERM_SIZE, duration);

  // Prevent the compiler from optimizing too much
  printf("\nD[PERM_SIZE-1] = %d, checksum = %llu", D[PERM_SIZE-1], checksum);

#ifdef DEBUG
  unsigned long long perm = 1;
  unsigned long long PermValue[PERM_SIZE+1] = {0}; // Increase size to PERM_SIZE+1 to avoid overflow
  unsigned long long SumPermValue[PERM_SIZE+1] = {0};
  PermValue[0] = 1;
  SumPermValue[0] = 0;
  
  // Calculate factorials up to N!
  for (i = 1; i <= PERM_SIZE; i++) {
    perm = perm * i;                              // Calculate factorial: perm = i!
    PermValue[i] = perm;                          // Store current factorial value
    SumPermValue[i] = SumPermValue[i - 1] + perm; // Calculate cumulative factorial sum
  }

  // Print i, permvalue, SumPermvalue
  for (i = 1; i <= PERM_SIZE; i++) {
    printf("\n%u !, %llu, sigma %llu", i, PermValue[i], SumPermValue[i]);
  }

  // Print process count for lines that were actually executed
  for (i = 0; i < 200; i++) { // ProcessCount has size 200
    if (ProcessCount[i] > 0)
      printf("\n [Line %u]%llu", i, ProcessCount[i]);
  }
#endif

  return 0;
}