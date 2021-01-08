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
#include <vector>
#include "TestTool.hpp"
#include "../core/RangeMinimumQuery.hpp"

using namespace std;

void TEST_CASE_ONE_SEGMENT_TREE()
{
    vector<int> inputs = {18, 17, 13, 19, 15, 11, 20};
    vector<Query<int>> queries;
    queries.emplace_back(false, 5, 7);
    queries.emplace_back(false, 1, 3);
    queries.emplace_back(true, 6, 12);
    queries.emplace_back(false, 5, 7);
    queries.emplace_back(false, 3, 4);
    queries.emplace_back(false, 1, 2);
    queries.emplace_back(false, 1, 7);
    queries.emplace_back(false, 7, 7);
    auto segment_tree = cpstl::SegmentTree<int>(inputs);
    auto result = range_minimum_query_segment_tree(segment_tree, queries);
    cpstl::assert_equal("TEST_CASE_ONE_SEGMENT_TREE", {11, 13, 12, 13, 17, 12, 20}, result);
    cpstl::cp_log(LOG, result);
}

void TEST_CASE_TWO_SEGMENT_TREE()
{
    vector<int> inputs = {1, 5, 2, 4, 3};
    vector<Query<int>> queries;
    queries.emplace_back(false, 1, 5);
    queries.emplace_back(false, 1, 3);
    queries.emplace_back(false, 3, 5);
    queries.emplace_back(true, 3, 6);
    queries.emplace_back(false, 1, 5);
    auto segment_tree = cpstl::SegmentTree<int>(inputs);
    auto result = range_minimum_query_segment_tree(segment_tree, queries);
    cpstl::assert_equal("TEST_CASE_TWO_SEGMENT_TREE", {1, 1, 2, 1}, result);
    cpstl::cp_log(LOG, result);
}

void TEST_CASE_ONE_LAZY_SEGMENT_TREE()
{
    vector<int> inputs = {18, 17, 13, 19, 15, 11, 20};
    vector<Query<int>> queries;
    queries.emplace_back(false, 5, 7);
    queries.emplace_back(false, 1, 3);
    queries.emplace_back(true, 6, 12);
    queries.emplace_back(false, 5, 7);
    queries.emplace_back(false, 3, 4);
    queries.emplace_back(false, 1, 2);
    queries.emplace_back(false, 1, 7);
    queries.emplace_back(false, 7, 7);
    auto segment_tree = cpstl::LazySegmentTree<int>(inputs);
    auto result = range_minimum_query_lazy_segment_tree(segment_tree, queries);
    cpstl::assert_equal("TEST_CASE_ONE_LAZY_SEGMENT_TREE", {11, 13, 12, 13, 17, 12, 20}, result);
    cpstl::cp_log(LOG, result);
}

void TEST_CASE_TWO_LAZY_SEGMENT_TREE()
{
    vector<int> inputs = {1, 5, 2, 4, 3};
    vector<Query<int>> queries;
    queries.emplace_back(false, 1, 5);
    queries.emplace_back(false, 1, 3);
    queries.emplace_back(false, 3, 5);
    queries.emplace_back(true, 3, 6);
    queries.emplace_back(false, 1, 5);
    auto segment_tree = cpstl::LazySegmentTree<int>(inputs);
    auto result = range_minimum_query_lazy_segment_tree(segment_tree, queries);
    cpstl::assert_equal("TEST_CASE_TWO_LAZY_SEGMENT_TREE", {1, 1, 2, 1}, result);
    cpstl::cp_log(LOG, result);
}

void TEST_CASE_ONE_NAIVE()
{
    vector<int> inputs = {18, 17, 13, 19, 15, 11, 20};
    vector<Query<int>> queries;
    queries.emplace_back(false, 4, 6);
    queries.emplace_back(false, 1, 3);
    auto result = range_minimum_query_naive(inputs, queries);
    cpstl::assert_equal("TEST_CASE_ONE_NAIVE", {11, 13}, result);
}

int main()
{
    TEST_CASE_ONE_NAIVE();
    TEST_CASE_ONE_SEGMENT_TREE();
    TEST_CASE_TWO_SEGMENT_TREE();
    TEST_CASE_ONE_LAZY_SEGMENT_TREE();
    TEST_CASE_TWO_LAZY_SEGMENT_TREE();
    return EXIT_SUCCESS;
}