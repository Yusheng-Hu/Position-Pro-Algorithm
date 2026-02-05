[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Language: C++](https://img.shields.io/badge/Language-C%2B%2B-red.svg)](#)
[![Complexity: O(n)](https://img.shields.io/badge/Complexity-O(n)-brightgreen.svg)](#)
[![DOI](https://zenodo.org/badge/DOI/10.5281/zenodo.18184520.svg)](https://doi.org/10.5281/zenodo.18184520)
![Permutation Generation](https://img.shields.io/badge/Field-Combinatorial_Algorithms-blue)
[![ORCID](https://img.shields.io/badge/ORCID-0009--0005--1980--5751-A6CE39?logo=orcid&logoColor=white)](https://orcid.org/0009-0005-1980-5751)
[![GitHub stars](https://img.shields.io/github/stars/Yusheng-Hu/Position-Pure-Algorithm?style=social)](https://github.com/Yusheng-Hu/Position-Pure-Algorithm)

---

# Position Pure Algorithm

Official implementation and interactive visualizations of the **Position Pure (PP)** linear-time unranking algorithm.

## 🚀 Live Demonstrations
* **[View Position Algorithm Animation](https://yusheng-hu.github.io/Position-Pure-Algorithm/Position.html)**
* **[View Position Pure (PP) Algorithm Animation](https://yusheng-hu.github.io/Position-Pure-Algorithm/PositionPure.html)**

## 📄 Academic Status
* **Preprint**: need long time.
* **Status**: $O(n)$ complexity achieved, improving upon the classic Myrvold-Ruskey logic.

## 💻 Source Code
The core C++ implementations of the algorithms can be found here:
* **[map_perm_algorithms.cpp](./map_perm_algorithms.cpp)**: Includes `Position_unrank`, `Position_rank`, `PositionPure_unrank`, and `PositionPure_rank`.
* **[permPure_full.cpp](./FullPermutation/permPure_full.cpp)**: Serves as a high-performance reference implementation for generating all permutations of a set using the **PositionPure** iterative algorithm. 

## 🛠️ Usage
These algorithms achieve $O(n)$ time complexity by optimizing the indexing logic $D[i]$, providing a more efficient alternative to the classic Myrvold-Ruskey method.

## 📚 Background & Acknowledgments
The **Position Pure (PP)** algorithm is built upon the foundational work of **Wendy Myrvold and Frank Ruskey**, specifically their $O(n)$ unranking algorithm (2001). 

While the MR algorithm uses a specific swap-based approach, the PP method introduces a more intuitive indexing logic $D[i]$ that simplifies the implementation and enhances understanding of the mapping process.


## 🚀 Liner rank unrank: Position Pure (PP) vs. Myrvold-Ruskey (MR) 
[//]: # (INDUSTRIAL_PERFORMANCE_BENCHMARK_DATA_SECTION_START_DO_NOT_REMOVE)

#### Last Automated Run: Thu Feb  5 15:43:16 UTC 2026 (Environment: AMD EPYC 7763 64-Core Processor)

**Ranking Performance (Permutation D → Factorial C)**
| N | Distribution | MR (ns/it) | PP (ns/it) | Speedup (MR/PP) |
|---|---|---|---|---|
| 1000 | Random | 907.5 | 698.2 | **1.30x** |
| 1000 | Sorted | 800.3 | 579.5 | **1.38x** |
| 1000 | Reverse | 821.9 | 702.2 | **1.17x** |
| 100000 | Random | 96548.0 | 84259.7 | **1.15x** |
| 100000 | Sorted | 79427.4 | 58142.8 | **1.37x** |
| 100000 | Reverse | 81439.3 | 71413.0 | **1.14x** |
| 1000000 | Random | 1280257.1 | 1187029.3 | **1.08x** |
| 1000000 | Sorted | 794585.1 | 581147.6 | **1.37x** |
| 1000000 | Reverse | 832901.1 | 731299.4 | **1.14x** |

**Unranking Performance (Factorial C → Permutation D)**
| N | Distribution | MR (ns/it) | PP (ns/it) | Speedup (MR/PP) |
|---|---|---|---|---|
| 1000 | Random | 1037.5 | 700.6 | **1.48x** |
| 1000 | Sorted | 827.3 | 576.6 | **1.43x** |
| 1000 | Reverse | 826.1 | 704.2 | **1.17x** |
| 100000 | Random | 95419.4 | 84027.2 | **1.14x** |
| 100000 | Sorted | 79848.1 | 58321.2 | **1.37x** |
| 100000 | Reverse | 83574.9 | 72003.7 | **1.16x** |
| 1000000 | Random | 1284205.1 | 1193530.1 | **1.08x** |
| 1000000 | Sorted | 794890.6 | 584277.0 | **1.36x** |
| 1000000 | Reverse | 848961.7 | 732082.6 | **1.16x** |

[//]: # (INDUSTRIAL_PERFORMANCE_BENCHMARK_DATA_SECTION_END_DO_NOT_REMOVE)




## 🚀 Full Permutation generation: Iterative Permutation Generation

The **PositionPure** algorithm is a high-performance, iterative approach to generating all permutations of a set. By utilizing an iterative state machine rather than traditional recursion, it significantly reduces function call overhead and optimizes CPU branch prediction efficiency.

### Key Features
* **Iterative State Machine**: Eliminates recursion depth limits and stack-related performance bottlenecks.
* **Hardware Affinity Binding**: Includes native Windows API support (`SetThreadAffinityMask`) to lock execution to a specific logical core, minimizing context-switching noise and cache misses.
* **High-Precision Benchmarking**: Performance is measured using the Windows High-Precision Event Timer (`QueryPerformanceCounter`) for nanosecond-level accuracy.
* 

## 🛠 Compilation Commands

The following commands compile both algorithms using the same aggressive optimization flags to ensure a fair performance comparison:

```bash
# Compile options
g++ -O3 -std=c++11 -march=native -flto -ffast-math -fomit-frame-pointer

```

[//]: # (UNIQUE_PP_ALGO_BENCHMARK_DATA_SECTION_START_DO_NOT_REMOVE)

#### Last Automated Run: Thu Feb  5 14:49:27 UTC 2026 (UTC)

| N | Heap Algorithm (s) | PP Algorithm (s) | Speedup (Heap/PP) |
|---|---|---|---|
| 9 | 0.005818 | 0.000662 | 8.78x |
| 10 | 0.059210 | 0.007390 | 8.01x |
| 11 | 0.655020 | 0.083340 | 7.85x |
| 12 | 7.787339 | 0.942191 | 8.26x |
| 13 | 103.183169 | 11.819807 | 8.72x |
| 14 | 1467.425878 | 167.218194 | 8.77x |

[//]: # (UNIQUE_PP_ALGO_BENCHMARK_DATA_SECTION_END_DO_NOT_REMOVE)

---

#### **Key Insights**
* **Significant Speedup:** `permPure_full` consistently outperforms Heap's Algorithm by a factor of approximately **7x**.
* **High Throughput:** For $n=13$, `permPure_full` processes over **6.2 billion permutations** in under 11 seconds, showcasing exceptional instruction-level efficiency.
* **Algorithmic Efficiency:** The performance gap highlights the superior memory access patterns and lower computational overhead inherent in the PositionPure algorithm.
* **Scalability:** As the permutation space grows factorially, the performance gap remains stable, demonstrating excellent algorithmic efficiency for large-scale generation.

---

### Comparison with Python's Built-in itertools

At the request of Reddit users and other community members, a performance comparison with Python’s built-in `itertools` was conducted. Results are based on the implementation in `Position-Pure-Algorithm/python/pp_iter.py`.

* **Runtime Environment**: The tests were performed using **PyPy3**. Since the standard `itertools` library is C-optimized, using PyPy3 helps bridge the low-level language gap, allowing for a more authentic comparison of algorithmic efficiency.
* **Results**: Benchmark tests show that this algorithm improves performance by at least **1.4x**, with potential gains reaching over **2x** compared to the standard library.
* **Future Plans**: For applications requiring even higher performance, a **C-compiled version** should be considered.

[//]: # (PYTHON_PP_ITER_BENCHMARK_START)

### 🐍 Position Pro Iterator Performance (PyPy)
| N | Total Permutations | Itertools (s) | Position Pro (s) | Speed-up |
| :--- | :--- | :--- | :--- | :--- |
| 10 | 3,628,800 | 0.1085s | 0.0703s | **1.54x** |
| 11 | 39,916,800 | 1.2236s | 0.5704s | **2.15x** |
| 12 | 479,001,600 | 14.9898s | 6.7809s | **2.21x** |

[//]: # (PYTHON_PP_ITER_BENCHMARK_END)

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

### 🚀 Evolution of Efficiency: Beyond Heap's Algorithm

The **Position-Pure Algorithm** and **Circle-Permutation-Algorithm** represent a paradigm shift in combinatorial generation by optimizing the fundamental cost of state transitions.

* **Heap's Algorithm (The Classical Baseline):** Long considered the gold standard due to its *swap-based* approach. While swaps were once thought to be the minimum-cost operation, they involve multiple memory accesses and conditional logic that limit peak performance.
* **Ives' Iterative Algorithm:** Improved upon Heap's by utilizing a *single-shift and single-assignment* pattern, reducing the overhead of element movement.
* **Position-Pure Algorithm (Our Work):** Achieves a new frontier by **eliminating conditional branching** and implementing a highly refined *shift-and-assign* strategy. 
    * **Scalability:** Optimized for large $N$.
    * **Concurrency:** Stateless design allows for massive **parallel execution**, a feat traditional recursive algorithms cannot achieve.
* **[Circle-Permutation-Algorithm](https://github.com/Yusheng-Hu/Circle-Permutation-Algorithm) (Upcoming):** Specifically engineered for circular symmetry. While it introduces controlled spatial overhead, it shatters traditional performance barriers by realizing an **O((n-1)!)** complexity framework.

# PositionPure: Exploring Analytical Permutations

> **"Full permutation generation is a well-studied field. However, providing efficient, random access to specific elements within massive permutations remains a compelling challenge—one where we are only just beginning to explore."**

Traditional approaches, such as the classic Myrvold-Ruskey algorithm, typically rely on sequential swapping processes. While highly efficient for full generation, these state-dependent models often require the entire permutation to reside in memory, which can be a constraint for large-scale distributed tasks.

**PositionPure (PP)** explores a different path by treating permutations as an **analytical mapping**. This project introduces an alternative framework designed to decouple individual elements from the sequential dependency chain, facilitating new approaches to large-scale computation:

---

## 📢 Important Update: From "Position Pro" to "Position Pure"

**Please note:** Starting from version **v1.1.1**, this algorithm has been officially renamed from **Position Pro** to **Position Pure (PP)**.

### Why the name change?
1. **Trademark Consideration:** We found that "Position Pro" is a registered trademark in several industrial and commercial sectors. To ensure the algorithm's academic independence and avoid legal confusion, we have transitioned to a unique name.
2. **Technical Essence (Why "Pure"?):** The name **"Pure"** more accurately describes the algorithm's technical implementation. In computer science, "pure" often implies a clean, branchless execution flow. 
3. **Core Feature - Branchless Logic:** Unlike the base version, **Position Pure (PP)** achieves its linear-time performance through direct element-wise shifting and replacement. **It eliminates conditional branching (no `if` statements in the core loop)**, leading to a "purer" and faster execution path on modern CPUs.
