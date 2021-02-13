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
#include <cstdlib>
#include <vector>
#include "core/NextLargerElement.hpp"

int main(int argc, char* argv[]){
    std::vector<int64_t> inputs = {1, 3, 2, 4};
    std::cout << "---------- NAIVE SOL ---------" << std::endl;
    std::vector<int64_t> result = calc_next_larger_elem_naive(inputs);
    std::cout << "Input ";
    for (auto elem : inputs) {
        std::cout << elem << " ";
    }
    std::cout << "\n";
    std::cout << "Result ";
    for (auto elem : result) {
        std::cout << elem << " ";
    }
    std::cout << "\n";

    std::cout << "------------- STACK SOLUTION ---------------" << std::endl;
    std::cout << "Input ";
    for (auto elem : inputs) {
        std::cout << elem << " ";
    }
    std::cout << "\n";
    std::vector<std::pair<int, int64_t>> map = calc_next_larger_elem_stack(inputs);
    std::cout << "Result ";
    int64_t res[map.size()];
    for (auto elem : map) {
        res[elem.first] = elem.second;
    }
    for (int i = 0; i < map.size(); i++) {
        std::cout << res[i] << " ";
    }
    std::cout << "\n";
    return EXIT_SUCCESS;
}
