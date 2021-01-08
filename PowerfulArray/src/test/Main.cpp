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
#include "TestTool.hpp"
#include "../core/Solution.hpp"

using namespace std;

void TEST_CASE_ONE_MO_ALGORITHM()
{
    vector<int> inputs = {1, 2, 1};
    cpstl::cp_log(LOG, inputs);
    vector<Query> queries;
    queries.emplace_back(1, 2, inputs.size(), 0);
    queries.emplace_back(1, 3, inputs.size(), 1);
    auto result = powerful_array_mo_algorithms<int, int>(inputs, queries);
    cpstl::assert_equal("TEST_CASE_ONE", {3, 6}, result);
    cpstl::cp_log(LOG, result);
}

void TEST_CASE_TWO_MO_ALGORITHM()
{
    vector<int> inputs = {1, 1, 2, 2, 1, 3, 1, 1};
    cpstl::cp_log(LOG, inputs);
    vector<Query> queries;
    queries.emplace_back(2, 7, inputs.size(), 0);
    queries.emplace_back(1, 6, inputs.size(), 1);
    queries.emplace_back(2, 7, inputs.size(), 2);
    auto result = powerful_array_mo_algorithms<int, int>(inputs, queries);
    cpstl::assert_equal("TEST_CASE_ONE", {20, 20, 20}, result);
    cpstl::cp_log(LOG, result);
}

void TEST_CASE_THREE_MO_ALGORITHM()
{
    vector<int> inputs = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    cpstl::cp_log(LOG, inputs);
    vector<Query> queries;
    queries.emplace_back(4, 8, inputs.size(), 0);
    queries.emplace_back(1, 10, inputs.size(), 1);
    queries.emplace_back(3, 9, inputs.size(), 2);
    queries.emplace_back(2, 2, inputs.size(), 3);
    queries.emplace_back(5, 10, inputs.size(), 4);
    auto result = powerful_array_mo_algorithms<int, int>(inputs, queries);
    cpstl::assert_equal("TEST_CASE_ONE", {25, 55, 35, 9, 21}, result);
    cpstl::cp_log(LOG, result);
}

int main()
{
    TEST_CASE_ONE_MO_ALGORITHM();
    TEST_CASE_TWO_MO_ALGORITHM();
    TEST_CASE_THREE_MO_ALGORITHM();
    return EXIT_SUCCESS;
}