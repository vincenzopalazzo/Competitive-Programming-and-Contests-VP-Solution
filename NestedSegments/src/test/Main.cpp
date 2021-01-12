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
#include "../core/NestedSegments.hpp"

using namespace std;

void TEST_CASE_ONE_FENWICK()
{
    std::vector<Segment<int>> inputs;
    inputs.emplace_back(1, 8, 0);
    inputs.emplace_back(2, 3, 1);
    inputs.emplace_back(4, 7, 2);
    inputs.emplace_back(5, 6, 3);
    auto result = nested_segment_fenwick_tree<int, int>(inputs);
    cpstl::assert_equal("TEST_CASE_ONE_FENWICK", {3, 0, 1, 0}, result);
    cpstl::cp_log(LOG, result);
}

void TEST_CASE_TWO_FENWICK()
{
    std::vector<Segment<int>> inputs;
    inputs.emplace_back(3, 4, 0);
    inputs.emplace_back(1, 5, 1);
    inputs.emplace_back(2, 6, 2);
    auto result = nested_segment_fenwick_tree<int, int>(inputs);
    cpstl::assert_equal("TEST_CASE_TWO_FENWICK", {0, 1, 1}, result);
    cpstl::cp_log(LOG, result);
}

void TEST_CASE_THREE_FENWICK()
{
    std::vector<Segment<int64_t>> inputs;
    inputs.emplace_back(-1000000000, 1000000000, 0);
    auto result = nested_segment_fenwick_tree<int64_t, int64_t>(inputs);
    cpstl::assert_equal("TEST_CASE_THREE_FENWICK", {0}, result);
    cpstl::cp_log(LOG, result);
}

void TEST_CASE_FOUR_FENWICK()
{
    std::vector<Segment<long long>> inputs;
    inputs.emplace_back(-3, -1, 0);
    inputs.emplace_back(-10, 4, 1);
    inputs.emplace_back(0, 6, 2);
    inputs.emplace_back(-4, -2, 3);
    inputs.emplace_back(1, 3, 4);
    inputs.emplace_back(2, 9, 5);
    inputs.emplace_back(5, 10, 6);
    inputs.emplace_back(-7, -6, 7);
    inputs.emplace_back(-8, 8, 8);
    inputs.emplace_back(-9, 7, 9);
    auto result = nested_segment_fenwick_tree<long long, long long>(inputs);
    cpstl::assert_equal("TEST_CASE_FOUR_FENWICK", {0, 4, 1, 0, 0, 0, 0, 0, 5, 5}, result);
    cpstl::cp_log(LOG, result);
}

void TEST_CASE_ONE_LAZY_SEGMENT_TREE()
{
    std::vector<Segment<int>> inputs;
    inputs.emplace_back(1, 8, 0);
    inputs.emplace_back(2, 3, 1);
    inputs.emplace_back(4, 7, 2);
    inputs.emplace_back(5, 6, 3);
    auto result = nested_segment_lazy_segment_tree<int, int>(inputs);
    cpstl::assert_equal("TEST_CASE_ONE_LAZY_SEGMENT_TREE", {3, 0, 1, 0}, result);
    cpstl::cp_log(LOG, result);
}

void TEST_CASE_TWO_LAZY_SEGMENT_TREE()
{
    std::vector<Segment<int>> inputs;
    inputs.emplace_back(3, 4, 0);
    inputs.emplace_back(1, 5, 1);
    inputs.emplace_back(2, 6, 2);
    auto result = nested_segment_lazy_segment_tree<int, int>(inputs);
    cpstl::assert_equal("TEST_CASE_TWO_LAZY_SEGMENT_TREE", {0, 1, 1}, result);
    cpstl::cp_log(LOG, result);
}

void TEST_CASE_THREE_LAZY_SEGMENT_TREE()
{
    std::vector<Segment<int64_t>> inputs;
    inputs.emplace_back(-1000000000, 1000000000, 0);
    auto result = nested_segment_lazy_segment_tree<int64_t, int64_t>(inputs);
    cpstl::assert_equal("TEST_CASE_THREE_LAZY_SEGMENT_TREE", {0}, result);
    cpstl::cp_log(LOG, result);
}

void TEST_CASE_FOUR_LAZY_SEGMENT_TREE()
{
    std::vector<Segment<long long>> inputs;
    inputs.emplace_back(-3, -1, 0);
    inputs.emplace_back(-10, 4, 1);
    inputs.emplace_back(0, 6, 2);
    inputs.emplace_back(-4, -2, 3);
    inputs.emplace_back(1, 3, 4);
    inputs.emplace_back(2, 9, 5);
    inputs.emplace_back(5, 10, 6);
    inputs.emplace_back(-7, -6, 7);
    inputs.emplace_back(-8, 8, 8);
    inputs.emplace_back(-9, 7, 9);
    auto result = nested_segment_lazy_segment_tree<long long, long long>(inputs);
    cpstl::assert_equal("TEST_CASE_FOUR_LAZY_SEGMENT_TREE", {0, 4, 1, 0, 0, 0, 0, 0, 5, 5}, result);
    cpstl::cp_log(LOG, result);
}

void TEST_CASE_ONE_SEGMENT_TREE()
{
    std::vector<Segment<int>> inputs;
    inputs.emplace_back(1, 8, 0);
    inputs.emplace_back(2, 3, 1);
    inputs.emplace_back(4, 7, 2);
    inputs.emplace_back(5, 6, 3);
    auto result = nested_segment_segment_tree<int, int>(inputs);
    cpstl::assert_equal("TEST_CASE_ONE_SEGMENT_TREE", {3, 0, 1, 0}, result);
    cpstl::cp_log(LOG, result);
}

void TEST_CASE_TWO_SEGMENT_TREE()
{
    std::vector<Segment<int>> inputs;
    inputs.emplace_back(3, 4, 0);
    inputs.emplace_back(1, 5, 1);
    inputs.emplace_back(2, 6, 2);
    auto result = nested_segment_segment_tree<int, int>(inputs);
    cpstl::assert_equal("TEST_CASE_TWO_SEGMENT_TREE", {0, 1, 1}, result);
    cpstl::cp_log(LOG, result);
}

void TEST_CASE_THREE_SEGMENT_TREE()
{
    std::vector<Segment<int64_t>> inputs;
    inputs.emplace_back(-1000000000, 1000000000, 0);
    auto result = nested_segment_segment_tree<int64_t, int64_t>(inputs);
    cpstl::assert_equal("void TEST_CASE_THREE_SEGMENT_TREE", {0}, result);
    cpstl::cp_log(LOG, result);
}

void TEST_CASE_FOUR_SEGMENT_TREE()
{
    std::vector<Segment<long long>> inputs;
    inputs.emplace_back(-3, -1, 0);
    inputs.emplace_back(-10, 4, 1);
    inputs.emplace_back(0, 6, 2);
    inputs.emplace_back(-4, -2, 3);
    inputs.emplace_back(1, 3, 4);
    inputs.emplace_back(2, 9, 5);
    inputs.emplace_back(5, 10, 6);
    inputs.emplace_back(-7, -6, 7);
    inputs.emplace_back(-8, 8, 8);
    inputs.emplace_back(-9, 7, 9);
    auto result = nested_segment_segment_tree<long long, long long>(inputs);
    cpstl::assert_equal("TEST_CASE_FOUR_SEGMENT_TREE", {0, 4, 1, 0, 0, 0, 0, 0, 5, 5}, result);
    cpstl::cp_log(LOG, result);
}

int main()
{
    TEST_CASE_ONE_FENWICK();
    TEST_CASE_TWO_FENWICK();
    TEST_CASE_THREE_FENWICK();
    TEST_CASE_FOUR_FENWICK();
    TEST_CASE_ONE_LAZY_SEGMENT_TREE();
    TEST_CASE_TWO_LAZY_SEGMENT_TREE();
    TEST_CASE_THREE_LAZY_SEGMENT_TREE();
    TEST_CASE_FOUR_LAZY_SEGMENT_TREE();
    TEST_CASE_ONE_SEGMENT_TREE();
    TEST_CASE_TWO_SEGMENT_TREE();
    TEST_CASE_THREE_SEGMENT_TREE();
    TEST_CASE_FOUR_SEGMENT_TREE();
    return EXIT_SUCCESS;
}