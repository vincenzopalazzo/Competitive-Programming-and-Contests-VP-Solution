/**
 * Segment tree data structure implementation
 * Copyright (C) 2020  Vincenzo Palazzo vincenzopalazzodev@gmail.com
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
#include "../core/CircularRMQ.h"

using namespace std;

void TEST_CASE_ONE_SEGMENT_TREE()
{
    vector<int> inputs = {1, 2, 3, 4};
    cpstl::cp_log(LOG, inputs);
    vector<Query<int>> queries;
    queries.emplace_back(3, 0);
    auto update = Query<int>(3, 0, -1, true);
    queries.emplace_back(update);
    queries.emplace_back(0, 1);
    queries.emplace_back(2, 1);
    auto segment_tree = cpstl::SegmentTree<int>(inputs);
    auto result = calculate_minimum_rmq_query(segment_tree, queries);
    cpstl::cp_log(LOG, result);
    cpstl::assert_equal("TEST_CASE_ONE_SEGMENT_TREE", {1, 0, 0}, result);
}

void TEST_CASE_ONE_LAZY_SEGMENT_TREE()
{
    vector<int> inputs = {1, 2, 3, 4};
    cpstl::cp_log(LOG, inputs);
    vector<Query<int>> queries;
    queries.emplace_back(3, 0);
    auto update = Query<int>(3, 0, -1, true);
    queries.emplace_back(update);
    queries.emplace_back(0, 1);
    queries.emplace_back(2, 1);
    auto segment_tree = cpstl::LazySegmentTree<int>(inputs);
    auto result = calculate_minimum_rmq_query_lazy(segment_tree, queries);
    cpstl::assert_equal("TEST_CASE_ONE_LAZY_SEGMENT_TREE", {1, 0, 0}, result);
}

void TEST_CASE_TWO_LAZY_SEGMENT_TREE()
{
    ifstream input("/home/vincent/Github/Competitive-Programming-and-Contests-VP-Solution/CircularRMQ/src/test/files/input1.txt", std::ios_base::in);
    int N;
    input >> N;
    int range_query = 0;
    std::vector<int> inputs;
    inputs.reserve(N);
    for (std::size_t i = 0; i < N; i++) {
        int val;
        input >> val;
        inputs.push_back(val);
    }
    int m;
    input >> m;
    std::vector<Query<int>> queries;
    queries.reserve(m);
    for(std::size_t i = 1; i <= m; i++) {
        int x, y;
        input >> x;
        input >> y;

        int c;
        input >> c;
        if (c == 22) {
            range_query++;
            queries.emplace_back(x, y);
        } else {
            queries.emplace_back(x, y, c, true);
        }
    }
    auto segment_tree = cpstl::LazySegmentTree<int>(inputs);
    auto result = calculate_minimum_rmq_query_lazy(segment_tree, queries);
    ifstream result_input("/home/vincent/Github/Competitive-Programming-and-Contests-VP-Solution/CircularRMQ/src/test/files/result1.txt", std::ios_base::in);
    inputs.clear();
    inputs.reserve(N);
    for (std::size_t i = 0; i < range_query; i++) {
        int val;
        result_input >> val;
        inputs.push_back(val);
    }
    cpstl::assert_equal("TEST_CASE_TWO_LAZY_SEGMENT_TREE", inputs, result);
}

void TEST_CASE_THREE_LAZY_SEGMENT_TREE()
{
    ifstream input("/home/vincent/Github/Competitive-Programming-and-Contests-VP-Solution/CircularRMQ/src/test/files/input2.txt", std::ios_base::in);
    int N;
    input >> N;
    int range_query = 0;
    std::vector<int> inputs;
    inputs.reserve(N);
    for (std::size_t i = 0; i < N; i++) {
        int val;
        input >> val;
        inputs.push_back(val);
    }
    int m;
    input >> m;
    std::vector<Query<int>> queries;
    queries.reserve(m);
    for(std::size_t i = 1; i <= m; i++) {
        int x, y;
        input >> x;
        input >> y;

        int c;
        input >> c;
        if (c == 22) {
            range_query++;
            queries.emplace_back(x, y);
        } else {
            queries.emplace_back(x, y, c, true);
        }
    }
    auto segment_tree = cpstl::LazySegmentTree<int>(inputs);
    auto result = calculate_minimum_rmq_query_lazy(segment_tree, queries);
    ifstream result_input("/home/vincent/Github/Competitive-Programming-and-Contests-VP-Solution/CircularRMQ/src/test/files/result2.txt", std::ios_base::in);
    inputs.clear();
    inputs.reserve(N);
    for (std::size_t i = 0; i < range_query; i++) {
        int val;
        result_input >> val;
        inputs.push_back(val);
    }
    cpstl::assert_equal("TEST_CASE_THREE_LAZY_SEGMENT_TREE", inputs, result);
}


int main()
{
    TEST_CASE_ONE_SEGMENT_TREE();
    TEST_CASE_ONE_LAZY_SEGMENT_TREE();
    TEST_CASE_TWO_LAZY_SEGMENT_TREE();
    TEST_CASE_THREE_LAZY_SEGMENT_TREE();
    return EXIT_SUCCESS;
}