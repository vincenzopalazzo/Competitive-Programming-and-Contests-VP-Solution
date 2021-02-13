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
#include <unordered_map>
#include <algorithm>
#include "InversionCounting.h"
#include "Order.h"
#include "FenwickTree.h"

using namespace std;
using namespace cpstl;

template <typename T, typename R>
R count_inversion_merge_sort(std::vector<T> &inputs)
{
    return merge_sort<T, R>(inputs, 0, inputs.size() - 1);
}

template <typename T>
void remapping_array(std::vector<T> &inputs)
{
    sort(inputs.begin(), inputs.end());
    unordered_map<T, T> remapping;
    T value = 1;
    for (auto input : inputs) {
        remapping[input] = value++;
    }
    for (int i = 0; i < inputs.size(); i++) {
        inputs[i] = remapping[inputs[i]];
    }
}

template<typename T>
T count_inversion_binary_index_tree(std::vector<T> &inputs)
{
    T inversion = 0;
    remapping_array(inputs);
    auto fenwich = cpstl::BTreeIndex<T>(inputs.size());
    for (int i = inputs.size() - 1; i >= 0; i--) {
        inversion += fenwich.sum(inputs[i] - 1);
        fenwich.update(1, inputs[i]);
    }
    return inversion;
}

template long count_inversion_merge_sort<int, long>(std::vector<int> &inputs);
template void remapping_array(std::vector<int> &inputs);
template int count_inversion_binary_index_tree(std::vector<int> &inputs);
