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
#include "../core/FindKthZero.hpp"

using namespace std;

void TEST_CASE_ONE()
{
    vector<int> inputs = {1, 0, 3, 0, 5};
    vector<Query<int>> queries;
    queries.emplace_back( 2);
    queries.emplace_back(5,1);
    queries.emplace_back(1);
    queries.emplace_back(10, 3);
    queries.emplace_back(1);
    queries.emplace_back(0, 4);
    queries.emplace_back(2);
    auto result = find_number_of_zeros<int, int>(inputs, queries);
    cpstl::assert_equal("TEST_CASE_ONE", {3, 3, -1, -1}, result);
}

int main()
{
    TEST_CASE_ONE();
    return EXIT_SUCCESS;
}