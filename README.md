[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Language: C++](https://img.shields.io/badge/Language-C%2B%2B-red.svg)](#)
[![Complexity: O(n)](https://img.shields.io/badge/Complexity-O(n)-brightgreen.svg)](#)
[![DOI](https://zenodo.org/badge/DOI/10.5281/zenodo.18184520.svg)](https://doi.org/10.5281/zenodo.18184520)
![Permutation Generation](https://img.shields.io/badge/Field-Combinatorial_Algorithms-blue)
[![ORCID](https://img.shields.io/badge/ORCID-0009--0005--1980--5751-A6CE39?logo=orcid&logoColor=white)](https://orcid.org/0009-0005-1980-5751)
[![GitHub stars](https://img.shields.io/github/stars/Yusheng-Hu/Position-Pure-Algorithm?style=social)](https://github.com/Yusheng-Hu/Position-Pure-Algorithm)

---

# Position Pure Algorithm

Official implementation and interactive visualizations of the **Position Pure (PP)** linear-time ranking/unranking algorithm.

### 🚀 Evolution of Efficiency: Beyond Heap's Algorithm

The **Position-Pure Algorithm** and **Circle-Permutation-Algorithm** represent a paradigm shift in combinatorial generation by optimizing the fundamental cost of state transitions.

* **Heap's Algorithm (The Classical Baseline):** Long considered the gold standard due to its *swap-based* approach. While swaps were once thought to be the minimum-cost operation, they involve multiple memory accesses and conditional logic that limit peak performance.
* **Ives' Iterative Algorithm:** Improved upon Heap's by utilizing a *single-shift and single-assignment* pattern, reducing the overhead of element movement.
* **Position-Pure Algorithm (Our Work):** Achieves a new frontier by **eliminating conditional branching** and implementing a highly refined *shift-and-assign* strategy. 
    * **Scalability:** Optimized for large $N$.
    * **Concurrency:** Stateless design allows for massive **parallel execution**, a feat traditional recursive algorithms cannot achieve.
* **[Circle-Permutation-Algorithm](https://github.com/Yusheng-Hu/Circle-Permutation-Algorithm) :** Specifically engineered for circular symmetry. While it introduces controlled spatial overhead, it shatters traditional performance barriers by realizing an **O((n-1)!)** complexity framework.

#### **Key Insights**
* **Significant Speedup:** `permPure_full` consistently outperforms Heap's Algorithm by a factor of approximately **7x**.
* **Algorithmic Efficiency:** The performance gap highlights the superior memory access patterns and lower computational overhead inherent in the PositionPure algorithm.
* **Scalability:** As the permutation space grows factorially, the performance gap remains stable, demonstrating excellent algorithmic efficiency for large-scale generation.

---


## 🚀 Live Demonstrations
* **[View Position Algorithm Animation](https://yusheng-hu.github.io/Position-Pure-Algorithm/Position.html)**
* **[View Position Pure (PP) Algorithm Animation](https://yusheng-hu.github.io/Position-Pure-Algorithm/PositionPure.html)**


## 🚀 Full Permutation generation: Iterative Permutation Generation

The **PositionPure** algorithm is a high-performance, iterative approach to generating all permutations of a set. By utilizing an iterative state machine rather than traditional recursion, it significantly reduces function call overhead and optimizes CPU branch prediction efficiency.

The algorithm utilizes an **iterative state machine** to eliminate recursion overhead and leverages **hardware affinity binding** via the Windows API to minimize context-switching noise, with performance verified to nanosecond-level accuracy through **high-precision benchmarking**.

[//]: # (UNIQUE_PP_ALGO_BENCHMARK_AMD_START)

**Last Run:** Mon Feb 23 01:07:38 2026 UTC / Mon Feb 23 09:07:38 2026 (UTC+8)
**Environment:** AMD EPYC 7763 64-Core Processor (GitHub Actions Runner)

| N | Heap (s) | PP (s) | Speedup |
|---|---|---|---|
| 9 | 0.005723 | 0.000921 | 6.21x |
| 10 | 0.058103 | 0.006318 | 9.19x |
| 11 | 0.645616 | 0.064239 | 10.05x |
| 12 | 7.830960 | 0.714405 | 10.96x |
| 13 | 103.608897 | 8.807087 | 11.76x |

[//]: # (UNIQUE_PP_ALGO_BENCHMARK_AMD_END)

[//]: # (UNIQUE_PP_ALGO_BENCHMARK_INTEL_START)

**Last Run:** Fri Feb 06 07:20:50 2026 UTC / Fri Feb 06 15:20:50 2026 (UTC+8)
**Environment:** Intel(R) Xeon(R) Platinum 8370C CPU @ 2.80GHz (GitHub Actions Runner)

| N | Heap (s) | PP (s) | Speedup |
|---|---|---|---|
| 9 | 0.006039 | 0.000871 | 6.93x |
| 10 | 0.059160 | 0.007174 | 8.24x |
| 11 | 0.657323 | 0.075407 | 8.71x |
| 12 | 7.809986 | 1.004821 | 7.77x |
| 13 | 103.446021 | 11.693761 | 8.84x |
| 14 | 1468.660328 | 162.986940 | 9.01x |

[//]: # (UNIQUE_PP_ALGO_BENCHMARK_INTEL_END)

---

## 🚀 Comparison with Python's Built-in itertools

At the request of Reddit users and other community members, a performance comparison with Python’s built-in `itertools` was conducted. Results are based on the implementation in `Position-Pure-Algorithm/python/pp_iter.py`.

* **Runtime Environment**: The tests were performed using **PyPy3**. Since the standard `itertools` library is C-optimized, using PyPy3 helps bridge the low-level language gap, allowing for a more authentic comparison of algorithmic efficiency.
* **Results**: Benchmark tests show that this algorithm improves performance by at least **1.4x**, with potential gains reaching over **2x** compared to the standard library.
* **Future Plans**: For applications requiring even higher performance, a **C-compiled version** should be considered.

### 🐍 Position Pure Iterator Performance (PyPy)

[//]: # (PYTHON_PP_ITER_BENCHMARK_AMD_START)

**Last Run:** Mon Feb 23 02:29:03 2026 UTC / Mon Feb 23 10:29:03 2026 (UTC+8)
**Environment:** AMD EPYC 7763 64-Core Processor (GitHub Actions Runner)

| N | Total Permutations | Itertools (s) | Position Pure (s) | Speed-up |
| :--- | :--- | :--- | :--- | :--- |
| 10 | 3,628,800 | 0.1086s | 0.0670s | **1.62x** |
| 11 | 39,916,800 | 1.2154s | 0.5796s | **2.10x** |
| 12 | 479,001,600 | 15.0008s | 6.6901s | **2.24x** |
| 13 | 6,227,020,800 | 201.1209s | 85.3449s | **2.36x** |
| 14 | 87,178,291,200 | 2891.3540s | 1550.1204s | **1.87x** |

[//]: # (PYTHON_PP_ITER_BENCHMARK_AMD_END)

[//]: # (PYTHON_PP_ITER_BENCHMARK_INTEL_START)

**Last Run:** Fri Feb 06 05:40:44 2026 UTC / Fri Feb 06 13:40:44 2026 (UTC+8)
**Environment:** Intel(R) Xeon(R) Platinum 8370C CPU @ 2.80GHz (GitHub Actions Runner)

| N | Total Permutations | Itertools (s) | Position Pure (s) | Speed-up |
| :--- | :--- | :--- | :--- | :--- |
| 10 | 3,628,800 | 0.1513s | 0.1334s | **1.13x** |
| 11 | 39,916,800 | 2.0003s | 1.0969s | **1.82x** |

[//]: # (PYTHON_PP_ITER_BENCHMARK_INTEL_END)

### ⚡ Dual-Core Parallel Performance (GitHub Actions)

[//]: # (DUAL_CORE_BENCHMARK_START)

**Last Run:** Mon Feb 23 01:08:12 UTC 2026 / Mon Feb 23 09:08:12 2026 (UTC+8)
**Environment:** AMD EPYC 7763 64-Core Processor                 (GitHub Actions Runner)

| N | Core ID | Execution Time | Throughput (G/s) | Total Count |
|---|---|---|---|---|
| 10 | Core 0 | 0.0049s | 0.37 | - |
| 10 | Core 1 | 0.0029s | 0.63 | 3628800 |
| 11 | Core 0 | 0.0508s | 0.39 | - |
| 11 | Core 1 | 0.0349s | 0.57 | 39916800 |
| 12 | Core 0 | 0.4550s | 0.53 | - |
| 12 | Core 1 | 0.4369s | 0.55 | 479001600 |
| 13 | Core 0 | 6.7469s | 0.46 | - |
| 13 | Core 1 | 6.3394s | 0.49 | 6227020800 |
| 14 | Core 0 | 75.7316s | 0.58 | - |
| 14 | Core 1 | 76.3378s | 0.57 | 87178291200 |

[//]: # (DUAL_CORE_BENCHMARK_END)


## 🚀 Liner rank unrank: Position Pure (PP) vs. Myrvold-Ruskey (MR) 

[//]: # (INDUSTRIAL_PERFORMANCE_BENCHMARK_DATA_SECTION_AMD_START)

**Last Run:** Sat Feb 21 13:35:00 2026 UTC / Sat Feb 21 21:35:00 2026 (UTC+8)
**Environment:** AMD EPYC 7763 64-Core Processor (GitHub Actions Runner)

| N | Dist | MR (ns/it) | PP (ns/it) | Speedup |
|---|---|---|---|---|
| 1000 | Random | 1057.0 | 633.4 | 1.67x |
| 1000 | Sorted | 676.9 | 637.7 | 1.06x |
| 1000 | Reverse | 873.1 | 728.2 | 1.20x |
| 100000 | Random | 114563.3 | 94561.8 | 1.21x |
| 100000 | Sorted | 67846.6 | 62763.3 | 1.08x |
| 100000 | Reverse | 80115.5 | 66770.6 | 1.20x |
| 1000000 | Random | 1568522.4 | 1247111.3 | 1.26x |
| 1000000 | Sorted | 699835.1 | 626860.0 | 1.12x |
| 1000000 | Reverse | 802942.6 | 669304.3 | 1.20x |

[//]: # (INDUSTRIAL_PERFORMANCE_BENCHMARK_DATA_SECTION_AMD_END)

[//]: # (INDUSTRIAL_PERFORMANCE_BENCHMARK_DATA_SECTION_INTEL_START)

**Last Run:** Sat Feb 21 13:32:53 2026 UTC / Sat Feb 21 21:32:53 2026 (UTC+8)
**Environment:** Intel(R) Xeon(R) Platinum 8370C CPU @ 2.80GHz (GitHub Actions Runner)

| N | Dist | MR (ns/it) | PP (ns/it) | Speedup |
|---|---|---|---|---|
| 1000 | Random | 697.2 | 578.0 | 1.21x |
| 1000 | Sorted | 651.1 | 476.6 | 1.37x |
| 1000 | Reverse | 666.3 | 574.2 | 1.16x |
| 100000 | Random | 109696.3 | 104611.9 | 1.05x |
| 100000 | Sorted | 63265.3 | 46876.3 | 1.35x |
| 100000 | Reverse | 69900.0 | 79963.0 | 0.87x |
| 1000000 | Random | 2331791.2 | 2143208.0 | 1.09x |
| 1000000 | Sorted | 712214.9 | 470972.9 | 1.51x |
| 1000000 | Reverse | 853533.5 | 870776.9 | 0.98x |

[//]: # (INDUSTRIAL_PERFORMANCE_BENCHMARK_DATA_SECTION_INTEL_END)


## 💻 Source Code
The core C++ implementations of the algorithms can be found here:
* **[map_perm_algorithms.cpp](./map_perm_algorithms.cpp)**: Includes `Position_unrank`, `Position_rank`, `PositionPure_unrank`, and `PositionPure_rank`.
* **[permPure_full.cpp](./FullPermutation/permPure_full.cpp)**: Serves as a high-performance reference implementation for generating all permutations of a set using the **PositionPure** iterative algorithm. 
## 🛠 Compilation Commands
The following commands compile both algorithms using the same aggressive optimization flags to ensure a fair performance comparison:
```bash
# Compile options
g++ -O3 -std=c++11 -march=native -ffast-math -fomit-frame-pointer
```
---

## 📖 Citation

If you use this algorithm or implementation in your research, please cite it as follows:

### APA Style
> HU, Y. (2026). Position Method: A Linear-Time Generation Algorithm for Permutations (Version v1.0.0). GitHub Repository. DOI: [10.5281/zenodo.18170157](https://doi.org/10.5281/zenodo.18170157)

### BibTeX
```bibtex
@software{hu_yusheng_2026_18170157,
  author       = {Hu, Yusheng},
  title        = {Position Method: A Linear-Time Generation Algorithm for Permutations},
  year         = 2026,
  publisher    = {Zenodo},
  version      = {v1.0.0},
  doi          = {10.5281/zenodo.18170157},
  url          = {[https://doi.org/10.5281/zenodo.18170157](https://doi.org/10.5281/zenodo.18170157)}
}

```

## 💡 Future Ideas & Extensions

### 1. Zero-Memory "Lazy" Permutation
Since we can determine any value at position `k` in O(N) time without generating the full array, we can implement a **Lazy-Loaded Permutation Object**. 
- **Use Case:** Accessing elements of a massive permutation (N > 10^6) that exceeds RAM capacity.
- **Concept:** Overload `operator[]` to call `PP_get_value_at_position(k)` on the fly.

### 2. SIMD-Accelerated Partial Search
The backward-tracing logic `if (C[i] == current_target_pos)` is highly vectorizable. 
- **Idea:** Use AVX-512 to scan 16 elements of `C` simultaneously.
- **Goal:** Achieve near O(1) perceived latency for individual element lookups.

### 3. Distributed Constrained Search
Leverage the independence of the `get_value` function to split a single permutation validation task across multiple CPU cores or network nodes without shared state.

## 💡 Why Position Pure?
The **Position Pure (PP)** algorithm provides a more intuitive $O(n)$ implementation compared to the classic Myrvold-Ruskey (MR) method:
* **Simpler Indexing**: Replaces the traditional swap-based unranking with a direct mapping logic.
* **Educational Value**: The provided visualizations make the complex mapping process easy to understand.

---

## 📄 Academic Status
* **Preprint**: need long time.
* **Status**: $O(n)$ complexity achieved, improving upon the classic Myrvold-Ruskey logic.

---


## 📢 Important Update: From "Position Pro" to "Position Pure"

**Please note:** Starting from version **v1.1.1**, this algorithm has been officially renamed from **Position Pro** to **Position Pure (PP)**.

### Why the name change?
1. **Trademark Consideration:** We found that "Position Pro" is a registered trademark in several industrial and commercial sectors. To ensure the algorithm's academic independence and avoid legal confusion, we have transitioned to a unique name.
2. **Technical Essence (Why "Pure"?):** The name **"Pure"** more accurately describes the algorithm's technical implementation. In computer science, "pure" often implies a clean, branchless execution flow. 
3. **Core Feature - Branchless Logic:** Unlike the base version, **Position Pure (PP)** achieves its linear-time performance through direct element-wise shifting and replacement. **It eliminates conditional branching (no `if` statements in the core loop)**, leading to a "purer" and faster execution path on modern CPUs.
