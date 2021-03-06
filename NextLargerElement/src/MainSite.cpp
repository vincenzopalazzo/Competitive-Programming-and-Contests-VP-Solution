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
#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

std::vector<pair<int, int64_t>> calc_next_larger_elem_stack(std::vector<int64_t> const &inputs)
{
    std::stack<pair<int, int64_t>> stack;
    std::vector<pair<int, int64_t>> result;
    stack.emplace(0, inputs.at(0));
    for (int i = 1; i < inputs.size(); i++) {
        if (stack.empty()) {
            stack.emplace(i, inputs.at(i));
            continue;
        }
        int64_t next = inputs.at(i);
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

int main() {

    int num_test_cases = 0;
    std::cin >> num_test_cases;

    std::vector<int64_t> inputs;
    for (int i = 0; i < num_test_cases; ++i) {
        int n = 0;
        std::cin >> n;
        inputs.reserve(n);
        for (int j = 0; j < n; ++j) {
            int64_t x = 0;
            std::cin >> x;
            inputs.push_back(x);
        }
        std::vector<std::pair<int, int64_t>> map = calc_next_larger_elem_stack(inputs);

        int64_t res[map.size()];
        for (auto elem : map) {
            res[elem.first] = elem.second;
        }
        for (int j = 0; j < map.size(); j++) {
            std::cout << res[j] << " ";
        }
        std::cout << "\n";
        inputs.clear();
    }

    return 0;
}