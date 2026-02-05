#ifndef MAP_PERM_ALGORITHMS_H
#define MAP_PERM_ALGORITHMS_H

#include <vector>

// Myrvold-Ruskey unrank algorithm
// Converts factorial number representation (C) to permutation (D)
void MyrvoldRuskey_unrank(const std::vector<int> &C, std::vector<int> &D);

// Myrvold-Ruskey rank algorithm
// Converts permutation (D) to factorial number representation (C)
void MyrvoldRuskey_rank(const std::vector<int> &D, std::vector<int> &C);

// Position Mapping unrank algorithm
// Converts factorial index array C to permutation D
void Position_unrank(const std::vector<int> &C, std::vector<int> &D);

// Position Mapping rank algorithm
// Converts permutation D to factorial index array C
void Position_rank(const std::vector<int> &D, std::vector<int> &C);

// PositionPure unrank algorithm
void PositionPure_unrank(const std::vector<int> &C, std::vector<int> &D);

// PositionPure rank algorithm
void PositionPure_rank(const std::vector<int> &D, std::vector<int> &C);

#endif // MAP_PERM_ALGORITHMS_H
