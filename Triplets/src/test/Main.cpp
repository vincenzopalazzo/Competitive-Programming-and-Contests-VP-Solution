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
#include "../core/CountTriplets.hpp"

using namespace std;

void TEST_CASE_ONE_NAIVE()
{
    std::vector<int> inputs = {1, 2, 2, 4};
    auto result = count_triplets_naive<int, int>(inputs);
    cpstl::assert_equal("TEST_CASE_ONE", 4, result);
}

void TEST_CASE_TWO_NAIVE()
{
    std::vector<int> inputs = {3, 14, 10, 13, 19, 3, 13, 9, 10, 8, 17, 6, 9, 19, 8, 11, 5, 7, 2, 4};
    auto result = count_triplets_naive<int, int>(inputs);
    cpstl::assert_equal("TEST_CASE_TWO_NAIVE", 78, result);
}

void TEST_CASE_ONE_PRECOMPUTING()
{
    std::vector<int> inputs = {1, 2, 3, 4, 1};
    auto result = count_triplets_precomputing_bit<int, int>(inputs);
    cpstl::assert_equal("TEST_CASE_ONE_PRECOMPUTING", 4, result);
}

void TEST_CASE_TWO_PRECOMPUTING()
{
    std::vector<int> inputs = {3, 14, 10, 13, 19, 3, 13, 9,
                               10, 8, 17, 6, 9, 19, 8, 11, 5, 7, 2, 4};
    auto result = count_triplets_precomputing_segment_tree<int, int>(inputs);
    cpstl::assert_equal("TEST_CASE_TWO_PRECOMPUTING", 78, result);
}

void TEST_CASE_ONE_COMPUTING_OPTIMIZATION()
{
    std::vector<int> inputs = {1, 2, 3, 4, 1};
    auto result = count_triplets_precomputing_double_bit<int, int>(inputs);
    cpstl::assert_equal("TEST_CASE_ONE_COMPUTING_OPTIMIZATION", 4, result);
}

void TEST_CASE_TWO_COMPUTING_OPTIMIZATION()
{
    std::vector<int> inputs = {3, 14, 10, 13, 19, 3, 13, 9,
                               10, 8, 17, 6, 9, 19, 8, 11, 5, 7, 2, 4};
    auto result = count_triplets_precomputing_double_bit<int, int>(inputs);
    cpstl::assert_equal("TEST_CASE_TWO_COMPUTING_OPTIMIZATION", 78, result);
}

int main()
{
    TEST_CASE_ONE_NAIVE();
    TEST_CASE_TWO_NAIVE();
    TEST_CASE_ONE_PRECOMPUTING();
    TEST_CASE_TWO_PRECOMPUTING();
    TEST_CASE_ONE_COMPUTING_OPTIMIZATION();
    TEST_CASE_TWO_COMPUTING_OPTIMIZATION();
    return EXIT_SUCCESS;
}