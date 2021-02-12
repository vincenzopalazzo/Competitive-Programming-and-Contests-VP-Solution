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
#include "../core/TreeAndQueries.hpp"

using namespace std;

void TEST_CASE_ONE() {
    std::vector<int> inputs = {1, 2, 2, 3, 3, 2, 3, 3};
    std::vector<std::vector<int>> edges(8);

    edges[0].push_back(1); // 1 -> 2
    edges[1].push_back(0); // 1 <- 2

    edges[0].push_back(4);
    edges[4].push_back(0);

    edges[1].push_back(2);
    edges[2].push_back(1);

    edges[1].push_back(3);
    edges[3].push_back(1);

    edges[4].push_back(5);
    edges[5].push_back(4);

    edges[4].push_back(6);
    edges[6].push_back(4);

    edges[4].push_back(7);
    edges[7].push_back(4);

    std::vector<Query<int, int>> queries;
    queries.emplace_back(1, 2, inputs.size(), 0);
    queries.emplace_back(1, 3, inputs.size(), 1);
    queries.emplace_back(1, 4, inputs.size(), 2);
    queries.emplace_back(2, 3, inputs.size(), 3);
    queries.emplace_back(5, 3, inputs.size(), 4);
    auto result = numbers_of_vertices_with_color<int, int>(inputs, edges, queries);
    cpstl::cp_log(LOG, result);
    cpstl::assert_equal("TEST_CASE_ONE", {2, 2, 1, 0, 1}, result);
}

int main() {
    TEST_CASE_ONE();
    return EXIT_SUCCESS;
}
