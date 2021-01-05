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
#include <string>
#include <vector>
#include "../test/Utils.hpp"
#include "FenwickTree.hpp"
#include "LazySegmentTree.hpp"

const cpstl::Log LOG(false);

template <typename T, typename R>
static R count_triplets_naive(std::vector<T> const &inputs)
{
    R counter = 0;
    for (std::size_t i = 0; i < inputs.size() - 2; i++)
        for (std::size_t j = i + 1; j < inputs.size() - 1; j++)
            for (std::size_t k = j + 1; k < inputs.size(); k++)
                if (inputs[i] < inputs[j] < inputs[k])
                    counter++;
    return counter;
}

/**
 * This helper method perform the precompute operation to receive
 * a fenwick tree where each element inside the array was count
 * to have track of the result
 * @tparam T type of the array element
 * @param inputs input array
 * @return fenwick tree with the with the precompute operation
 */
template <typename T>
static cpstl::BTreeIndex<T> precompute(std::vector<T> const &inputs)
{
    auto fenwick_tree = cpstl::BTreeIndex<T>(inputs.size());
    for (std::size_t i = 0; i < inputs.size(); i++)
        fenwick_tree.update(inputs[i], 1);
    return fenwick_tree;
}

template <typename T>
static cpstl::LazySegmentTree<T> precompute_segmet_tree(std::vector<T> const &inputs)
{
    auto segment_tree = cpstl::LazySegmentTree<T>(inputs.size() + 1);
    for (std::size_t i = 0; i < inputs.size(); i++)
        segment_tree.update(inputs[i], 1);
    return segment_tree;
}

template <typename T, typename R>
static R count_triplets_precomputing_bit(std::vector<T> const &inputs)
{
    auto fenwick_tree = precompute(inputs);
    R count = 0;
    for (std::size_t i = 0; i < inputs.size(); i++) {
        for (std::size_t j = i + 1; j < inputs.size(); j++){
            if (inputs[i] < inputs[j]) {
                count += (fenwick_tree.sum(inputs.size()) - fenwick_tree.sum(inputs[j]));
                fenwick_tree.update(inputs[j],  -1);
            }
        }
    }
    return count;
}

template <typename T, typename R>
static R count_triplets_precomputing_segment_tree(std::vector<T> const &inputs)
{
    auto segment_tree = precompute_segmet_tree(inputs);
    R count = 0;
    for (std::size_t i = 0; i < inputs.size(); i++) {
        for (std::size_t j = i + 1; j < inputs.size(); j++){
            if (inputs[i] < inputs[j]) {
                count += segment_tree.range_query(inputs[j], inputs.size() - 1);
                segment_tree.update_range(inputs[j], inputs.size() - 1, -1);
            }
        }
    }
    return count;
}

template <typename T, typename R>
static R count_triplets_precomputing_double_bit(std::vector<T> const &inputs)
{
    R count = 0;
    auto fenwick_greater = precompute(inputs);
    auto fenwick_smallest = cpstl::BTreeIndex<T>(inputs.size());
    for (std::size_t i = 0; i < inputs.size(); i++) {
        auto smallest_elements = fenwick_smallest.sum(inputs[i] - 1);
        auto greatest_elements = fenwick_greater.sum(inputs.size()) - fenwick_greater.sum(inputs[i]);
        count += (smallest_elements * greatest_elements);
        fenwick_smallest.update(inputs[i], 1);
        fenwick_greater.update(inputs[i], -1);
    }
    return count;
}

