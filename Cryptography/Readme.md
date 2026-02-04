# PP_Cipher: In-place Stream Permutation Engine

## Overview
This project implements a high-performance, in-place data scrambling engine based on the **Position Pure (PP)** algorithm. The solution provides a linear-time $O(N)$ bijective mapping between a **Factoradic instruction stream** and the physical **permutation space**, enabling efficient data diffusion with minimal memory overhead.

## Decoupling Architecture
The scrambling process is strategically decoupled into two independent components: the **Instruction Set (C-Array)** and the **Mapping Engine (PP Logic)**.

### 1. The C-Array (Instruction Stream)
* **Role**: Represents the "coordinates" of a specific permutation within the Factoradic numbering system. 
* **Value**: By generating instructions ($C[i]$) dynamically, the complexity of selecting one of $N!$ possible permutations is reduced to a linear random-number generation task.
* **Flexibility**: Because the instruction generation is independent, the Pseudo-Random Number Generator (PRNG) can be swapped or upgraded without altering the core physical permutation logic.

### 2. The PP Logic (Position Mapping Engine)
* **Role**: Executes the physical movement of data based on the instruction stream.
* **Value**: The "Position Pure" logic proves that a perfect mapping from instructions to physical memory can be achieved in $O(N)$ time using simple assignments or swaps.
* **In-place Efficiency**: It eliminates the need to pre-calculate or store a full $O(N)$ Permutation Map (P-map), allowing for true streaming encryption.



## Randomness & Seed Integrity
The security and unpredictability of the cipher depend on the entropy of the **Seed**:
* **Deterministic Recovery**: For decryption to succeed, the same `uint32_t` seed must drive the `mt19937` engine to reproduce the exact same $C$ instruction sequence.
* **Entropy Sourcing**: To ensure high randomness, it is recommended to initialize the seed using hardware-based entropy (e.g., `std::random_device`), system timestamps, or environmental noise. This ensures seeds are uniformly distributed across the $2^{32}$ space, preventing permutation path prediction.

## Key Features
- **O(1) Auxiliary Space**: Encryption operates directly on the input buffer (In-place).
- **On-the-fly Processing**: No pre-calculated $O(N)$ mapping tables required during encryption.
- **Asymmetric Flow**: Forward-pass encryption ($0$ to $n-1$) and backward-pass decryption ($n-1$ down to $0$) ensure logical consistency.

## Usage (PP_Cipher.cpp)
### Compilation
Compile with high optimization for maximum throughput:
```bash
g++ -O3 PP_Cipher.cpp -o pp_cipher
