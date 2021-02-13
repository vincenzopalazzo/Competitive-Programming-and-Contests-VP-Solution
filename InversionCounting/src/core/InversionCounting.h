/**
 * Competitive-Programming-and-Contests-VP-Solution a collection of
 * code with an engineering approach to solve the problem.
 * https://github.com/vincenzopalazzo/Competitive-Programming-and-Contests-VP-Solution
 *
 * Copyright (C) 2020-2021  Vincenzo Palazzo vincenzopalazzodev@gmail.com
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
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