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
#include <vector>
#include <string>
#include <algorithm>

#include "Search.hpp"

template<typename T>
std::pair<T, int> calculate_number_of_tower(std::vector<T> &inputs)
{
    std::pair<T, int> result;
    int max_height = 1;
    int actual_max = 1;
    int number_tower = 0;

    std::sort(inputs.begin(), inputs.end()); // O(n log n)
    for (int i = 0; i < inputs.size(); i++) { // O(N)
        int pos = cpstl::Search<int, int>::binary_search(inputs, inputs.at(i), i + 1, inputs.size() - 1); // O(log n - i)
        if (pos != -1) {
            actual_max++;
        } else {
            if (actual_max > max_height) max_height = actual_max;
            actual_max = 1;
            number_tower++;
        }
    }

    result.first = max_height;
    result.second = number_tower;
    return result;
}