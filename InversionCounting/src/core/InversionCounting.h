//
// Created by vincent on 9/14/20.
//
#ifndef SPYCBLOCK_SOLTEST_H
#define SPYCBLOCK_SOLTEST_H
#include <cstdlib>
#include <vector>

/**
 * Merge sort is an algorithm that make the sorting with the comparison
 * for this reason we can count the number of inversion that the algorithm
 * need to do before to run it.
 *
 * @tparam T
 * @param inputs
 * @return the numeber of inversion
 */
template <typename T, typename R>
R count_inversion_merge_sort(std::vector<T> &inputs);

/***
 * This function is a util function that help us to remap the inputs vectior with
 * and array from [1 - n]
 * @tparam T the type of number inside this solution
 * @param inputs the array that we need to remap
 */
template <typename T>
void remapping_array(std::vector<T> &inputs);

/**
 * Another solution is to use the binary index tree and to use a solution with
 * the following flow:
 * - Make an sort array
 * - Remap the value, the inputs in this problem can have negative element, and the BIT need only
 * integer number, for this reason we need to make a small remapping
 * The operation of remapping in this cases is does with the unordered map
 *
 * @tparam T
 * @param inputs
 * @return
 */
template<typename T>
T count_inversion_binary_index_tree(std::vector<T> &inputs);


#endif //SPYCBLOCK_SOLTEST_H
