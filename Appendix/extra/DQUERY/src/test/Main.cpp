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
#include "../core/DQueries.hpp"

using namespace std;

void TEST_CASE_ONE_MO_ALG()
{
    std::vector<int> inputs = {1, 1, 2, 1, 3};
    std::vector<Query<int>> queries;
    queries.emplace_back(1, 5, 0, inputs.size());
    queries.emplace_back(2, 4, 1, inputs.size());
    queries.emplace_back(3, 5, 2, inputs.size());
    auto result = count_distinct_item_mo<int, int>(inputs, queries);
    cpstl::assert_equal("TEST_CASE_ONE_MO_ALG", {3, 2, 3}, result);
    cpstl::cp_log(LOG, result);
}

/**
 * 10
8 3 2 9 3 4 8 8 12 4
20
2 8
3 4
3 9
2 7
9 10
8 8
2 2
10 10
8 9
6 10
4 8
3 8
4 6
2 9
4 5
8 10
3 8
8 9
4 8
10 10
 */
void TEST_CASE_TWO_MO_ALG()
{
    std::vector<int> inputs = {8, 3, 2, 9, 3, 4, 8, 8, 12, 4 };
    std::vector<Query<int>> queries = {
            {2, 8, 0, inputs.size()},
            {3, 4, 1, inputs.size()},
            {3, 9, 2, inputs.size()},
            {2, 7, 3, inputs.size()},
            {9, 10, 4, inputs.size()},
            {8, 8, 5, inputs.size()},
            {2, 2, 6, inputs.size()},
            {10, 10, 7, inputs.size()},
            {8, 9, 8, inputs.size()},
            {6, 10, 9, inputs.size()},
            {4, 8, 10, inputs.size()},
            {3, 8, 11, inputs.size()},
            {4, 6, 12, inputs.size()},
            {2, 9, 13, inputs.size()},
            {4, 5, 14, inputs.size()},
            {8, 10, 15, inputs.size()},
            {3, 8, 16, inputs.size()},
            {8, 9, 17, inputs.size()},
            {4, 8, 18, inputs.size()},
            {10, 10,19, inputs.size()},
    };
    auto result = count_distinct_item_mo<int32_t , int32_t>(inputs, queries);
    cpstl::assert_equal("TEST_CASE_ONE_MO_ALG",
                        {5, 2, 5, 5, 1, 1, 1, 1, 1,
                                    2, 4, 5, 3, 5, 2, 2, 5, 1,
                                     4, 1}, result);
    cpstl::cp_log(LOG, result);
}

int main()
{
    TEST_CASE_ONE_MO_ALG();
    TEST_CASE_TWO_MO_ALG();
    return EXIT_SUCCESS;
}