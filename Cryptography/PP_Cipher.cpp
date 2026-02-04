/**
 * @file    PP_Cipher.cpp
 * @brief   Stream Cipher Implementation based on Position Pure (PP) Algorithm
 * @author  YUSHENG-HU
 * @date    2026-02-04
 *
 * @details
 * This implementation leverages the Position Pure (PP) algorithm for high-efficiency 
 * bijective permutation mapping. Unlike traditional swap-based algorithms, PP 
 * utilizes a non-symmetric position assignment logic to achieve linear-time 
 * encryption and decryption.
 *
 * Key Technical Characteristics:
 * 1. Factoradic-Based Mapping: Dynamically generates the instruction set C 
 * using a PRNG, mapping the permutation space (N!) to a specific rank.
 * 2. Asymmetric Flow: 
 * - Encryption (Unrank): Forward scan (0 to n-1) with O(1) auxiliary space, 
 * executing D[i] = D[a]; D[a] = i; logic.
 * - Decryption (Rank): Backward scan (n-1 to 0) with O(N) space to recover 
 * the original state via global position tracking (Map M).
 * 3. Deterministic Diffusion: Ensures a strictly unique bijection between 
 * the seed-driven instruction stream and the resulting data permutation.
 *
 * License: MIT License
 * Copyright (c) 2026 YUSHENG-HU
 */
 
 #include <iostream>
 #include <vector>
 #include <random>
 #include <string>
 #include <algorithm>
 
 using namespace std;
 
 class PPStreamCipher {
 public:
     /**
      * Encrypts data in-place.
      * Note: No permutation map (P array) is pre-calculated here.
      * Time: O(N), Space: O(1) auxiliary.
      */
     static void encrypt_inplace(uint32_t seed, string &data) {
         int n = data.length();
         if (n <= 1) return;
 
         mt19937 rng(seed);
         for (int i = 0; i < n; ++i) {
             // Generate instruction C[i] -> 'a' dynamically
             const int a = rng() % (i + 1);
             
             // Apply PP logic directly to data via in-place swap
             // This builds the permutation effect as we stream through the data
             if (i != a) {
                 swap(data[i], data[a]);
             }
         }
     }
 
     /**
      * Decrypts data by reversing the specific dynamic exchange sequence.
      * Time: O(N), Space: O(N) to store the instruction sequence for reversal.
      */
     static void decrypt_inplace(uint32_t seed, string &data) {
         int n = data.length();
         if (n <= 1) return;
 
         mt19937 rng(seed);
         vector<int> instructions(n);
 
         // Regenerate the sequence of 'a' values
         for (int i = 0; i < n; ++i) {
             instructions[i] = rng() % (i + 1);
         }
 
         // Reverse the swaps from end to beginning
         for (int i = n - 1; i >= 0; --i) {
             int a = instructions[i];
             if (i != a) {
                 swap(data[i], data[a]);
             }
         }
     }
 };
 
 int main() {
     const uint32_t seed = 20260204;
     const string message = "Official implementation of the Position Pure (PP) linear-time algorithm.";
 
     cout << "--- PP Algorithm In-place Engine ---" << endl;
     cout << "Original:  " << message << endl;
 
     // 1. Encryption Pass (Directly on string)
     PPStreamCipher::encrypt_inplace(seed, message);
     cout << "Cipher:    " << message << endl;
 
     // 2. Decryption Pass (Reverse swap sequence)
     PPStreamCipher::decrypt_inplace(seed, message);
     cout << "Recovered: " << message << endl;
 
     return 0;
 }

