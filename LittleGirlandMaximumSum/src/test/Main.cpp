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
#include "../core/LittleGirlAndMaximumSum.hpp"

using namespace std;

void TEST_CASE_ONE_PREFIX_SUM()
{
    vector<int> inputs = {5, 3, 2};
    vector<pair<int, int>> queries;
    queries.emplace_back(1, 2);
    queries.emplace_back(2, 3);
    queries.emplace_back(1, 3);
    auto result = max_sum_of_queries(inputs, queries);
    cpstl::assert_equal("TEST_CASE_ONE_PREFIX_SUM", 25, result);
}

void TEST_CASE_ONE_FENWICK_TREE()
{
    vector<int> inputs = {5, 3, 2};
    vector<pair<int, int>> queries;
    queries.emplace_back(1, 2);
    queries.emplace_back(2, 3);
    queries.emplace_back(1, 3);
    auto result = max_sum_of_queries_fenwick_tree(inputs, queries);
    cpstl::assert_equal("TEST_CASE_ONE_FENWICK_TREE", 25, result);
}

int main()
{
    TEST_CASE_ONE_PREFIX_SUM();
    TEST_CASE_ONE_FENWICK_TREE();
    return EXIT_SUCCESS;
}