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
#include "core/IlyaAndQueries.hpp"

using namespace std;

int main(){

    string input = "......";
    vector<pair<int, int>> queries;
    queries.emplace_back(3, 4);
    queries.emplace_back(2, 3);
    queries.emplace_back(1, 6);
    queries.emplace_back(2, 6);

    auto result = find_num_successor_elem(input, queries);
    for (auto elem : result) {
        printf("%d\n", elem);
    }

    struct sol::pair<int> tuples[4] =  {
            {3, 4},
            {2, 3},
            {1, 6},
            {2, 6},
    };
    int size = sizeof(tuples) / sizeof(tuples[0]);
    int *res = find_num_successor_elem_native(input, tuples, size);
    for (int i = 0; i < size; i++)
        printf("%d\n", res[i]);
    delete res;
    return EXIT_SUCCESS;
}