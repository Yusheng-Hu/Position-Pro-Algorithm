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

[//]: # (UNIQUE_PP_ALGO_BENCHMARK_DATA_SECTION_START_DO_NOT_REMOVE)

#### Last Run: Fri Feb 06 04:47:44 2026 UTC / Fri Feb 06 12:47:44 2026 (UTC+8)
**Env: AMD EPYC 7763 64-Core Processor**

| N | Heap (s) | PP (s) | Speedup |
|---|---|---|---|
| 9 | 0.005892 | 0.000991 | 5.94x |
| 10 | 0.058038 | 0.007160 | 8.10x |
| 11 | 0.641824 | 0.074509 | 8.61x |
| 12 | 7.825554 | 0.837134 | 9.34x |

[//]: # (UNIQUE_PP_ALGO_BENCHMARK_DATA_SECTION_END_DO_NOT_REMOVE)

---

## 🚀 Comparison with Python's Built-in itertools

At the request of Reddit users and other community members, a performance comparison with Python’s built-in `itertools` was conducted. Results are based on the implementation in `Position-Pure-Algorithm/python/pp_iter.py`.

* **Runtime Environment**: The tests were performed using **PyPy3**. Since the standard `itertools` library is C-optimized, using PyPy3 helps bridge the low-level language gap, allowing for a more authentic comparison of algorithmic efficiency.
* **Results**: Benchmark tests show that this algorithm improves performance by at least **1.4x**, with potential gains reaching over **2x** compared to the standard library.
* **Future Plans**: For applications requiring even higher performance, a **C-compiled version** should be considered.

[//]: # (PYTHON_PP_ITER_BENCHMARK_START)

### 🐍 Position Pure Iterator Performance (PyPy)

#### Last Automated Run: Fri Feb 06 04:43:06 2026 UTC / Fri Feb 06 12:43:06 2026 (UTC+8)
**Environment: AMD EPYC 7763 64-Core Processor**

| N | Total Permutations | Itertools (s) | Position Pure (s) | Speed-up |
|---|---|---|---|---|

[//]: # (PYTHON_PP_ITER_BENCHMARK_END)

## 🚀 Liner rank unrank: Position Pure (PP) vs. Myrvold-Ruskey (MR) 
[//]: # (INDUSTRIAL_PERFORMANCE_BENCHMARK_DATA_SECTION_START_DO_NOT_REMOVE)

#### Last Automated Run: Fri Feb 06 04:45:33 2026 UTC / Fri Feb 06 12:45:33 2026 (UTC+8)
**Environment: Intel(R) Xeon(R) Platinum 8370C CPU @ 2.80GHz**

**Ranking Performance (Permutation D → Factorial C)**
| N | Distribution | MR (ns/it) | PP (ns/it) | Speedup (MR/PP) |
|---|---|---|---|---|
| 1000 | Random | 700.8 | 572.0 | **1.23x** |
| 1000 | Sorted | 659.4 | 474.7 | **1.39x** |
| 1000 | Reverse | 670.1 | 574.1 | **1.17x** |
| 100000 | Random | 109546.4 | 104449.4 | **1.05x** |
| 100000 | Sorted | 63228.5 | 48455.7 | **1.30x** |
| 100000 | Reverse | 70022.0 | 80017.2 | **0.88x** |
| 1000000 | Random | 2356372.9 | 2161078.5 | **1.09x** |
| 1000000 | Sorted | 714874.3 | 471080.0 | **1.52x** |
| 1000000 | Reverse | 850264.4 | 875294.7 | **0.97x** |

**Unranking Performance (Factorial C → Permutation D)**
| N | Distribution | MR (ns/it) | PP (ns/it) | Speedup (MR/PP) |
|---|---|---|---|---|
| 1000 | Random | 709.0 | 574.3 | **1.23x** |
| 1000 | Sorted | 660.7 | 474.0 | **1.39x** |
| 1000 | Reverse | 670.8 | 571.2 | **1.17x** |
| 100000 | Random | 109497.7 | 104780.3 | **1.05x** |
| 100000 | Sorted | 63247.7 | 46809.4 | **1.35x** |
| 100000 | Reverse | 69806.2 | 80430.5 | **0.87x** |
| 1000000 | Random | 2189278.5 | 2012078.1 | **1.09x** |
| 1000000 | Sorted | 702255.1 | 470173.7 | **1.49x** |
| 1000000 | Reverse | 848589.7 | 868218.5 | **0.98x** |

[//]: # (INDUSTRIAL_PERFORMANCE_BENCHMARK_DATA_SECTION_END_DO_NOT_REMOVE)


## 💻 Source Code
The core C++ implementations of the algorithms can be found here:
* **[map_perm_algorithms.cpp](./map_perm_algorithms.cpp)**: Includes `Position_unrank`, `Position_rank`, `PositionPure_unrank`, and `PositionPure_rank`.
* **[permPure_full.cpp](./FullPermutation/permPure_full.cpp)**: Serves as a high-performance reference implementation for generating all permutations of a set using the **PositionPure** iterative algorithm. 
## 🛠 Compilation Commands
The following commands compile both algorithms using the same aggressive optimization flags to ensure a fair performance comparison:
```bash
# Compile options
g++ -O3 -std=c++11 -march=native -flto -ffast-math -fomit-frame-pointer
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
