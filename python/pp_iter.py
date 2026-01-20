"""
Position Pro (PP) Algorithm
A high-performance permutation generation algorithm.

Copyright (c) 2026 Yusheng Hu. All rights reserved.
Author: Yusheng Hu
"""

import itertools
import time
import sys
import math

def pp_permutations(n):
    """
    Position Pro (PP) Algorithm - Iterator Implementation.
    
    Generates all permutations of n elements. This implementation is 
    specifically optimized for JIT compilers (e.g., PyPy).
    
    Args:
        n (int): Number of elements to permute.
        
    Yields:
        list: The current permutation (yields the same list object modified in-place).
    """
    # Initialize control and permutation arrays
    c = [0] * n
    d = list(range(n))
    
    # Cache values for performance
    n_m_1 = n - 1
    n_m_2 = n - 2
    i = 0
    inner_indices = list(range(n))

    while c[0] < 1:
        # Incremental synchronization phase
        while i < n_m_1:
            idx = i
            ci = c[idx]
            d[idx], d[ci] = d[ci], d[idx]
            i += 1
        
        # Core high-speed generation phase
        last_val = d[n_m_1]
        for ii in inner_indices:
            temp_val = d[ii]
            d[n_m_1] = temp_val
            d[ii] = n_m_1
            
            yield d
            
            d[ii] = temp_val
        d[n_m_1] = last_val
            
        # Carry logic for factorial progression
        d[c[n_m_2]], d[n_m_2] = d[n_m_2], d[c[n_m_2]]
        c[n_m_2] += 1
        
        curr_i = n_m_2
        while curr_i > 0 and c[curr_i] > curr_i:
            c[curr_i] = 0
            curr_i -= 1
            c[curr_i] += 1
            # State backtracking
            p_idx = c[curr_i] - 1
            d[p_idx], d[curr_i] = d[curr_i], d[p_idx]
        i = curr_i

def run_performance_benchmarks(start_n=10, end_n=12):
    """
    Runs performance benchmarks comparing PP Algorithm with itertools.permutations.
    Outputs results in Markdown table format for GitHub Action summaries.
    """
    print(f"| N | Total Permutations | Itertools (s) | Position Pro (s) | Speed-up |")
    print(f"| :--- | :--- | :--- | :--- | :--- |")
    
    for n in range(start_n, end_n + 1):
        # Benchmark itertools.permutations
        t0 = time.perf_counter()
        for _ in itertools.permutations(range(n)):
            pass
        t_std = time.perf_counter() - t0

        # Benchmark Position Pro algorithm
        t1 = time.perf_counter()
        for _ in pp_permutations(n):
            pass
        t_pp = time.perf_counter() - t1

        total = math.factorial(n)
        speed_up = t_std / t_pp
        print(f"| {n} | {total:,} | {t_std:.4f}s | {t_pp:.4f}s | **{speed_up:.2f}x** |")

if __name__ == "__main__":
    run_performance_benchmarks(10, 12)
