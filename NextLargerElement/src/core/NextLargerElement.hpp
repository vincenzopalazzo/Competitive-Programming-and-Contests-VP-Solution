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
#include <map>
#include <stack>

template <typename T>
std::vector<std::pair<int, T>> calc_next_larger_elem_stack(const std::vector<T> &inputs)
{
    std::stack<std::pair<int, T>> stack;
    std::vector<std::pair<int, T>> result;
    stack.emplace(0, inputs.at(0));
    for (int i = 1; i < inputs.size(); i++) {
        if (stack.empty()) {
            stack.emplace(i, inputs.at(i));
            continue;
        }
        int next = inputs.at(i);
        while (!stack.empty() && stack.top().second < next) {
            if (stack.top().second < next) {
                result.emplace_back(stack.top().first, next);
                stack.pop();
            }
        }
        stack.emplace(i, next);
    }

    while (!stack.empty()) {
        result.emplace_back(stack.top().first, -1);
        stack.pop();
    }
    return result;
}

template <typename T>
std::vector<T> calc_next_larger_elem_naive(const std::vector<T> &inputs)
{
    std::vector<T> result;
    result.reserve(inputs.size());

    for (int i = 0; i < inputs.size(); i++) {
        for (int j =  i + 1; j <= inputs.size(); j++) {
            if (j == inputs.size()) {
                result.push_back(-1);
                break;
            } else if (inputs.at(i) < inputs.at(j)) {
                result.push_back(inputs.at(j));
                break;
            }
        }
    }
    return result;
}