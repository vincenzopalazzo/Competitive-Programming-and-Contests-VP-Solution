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
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
 * USA.
 */
#include "../core/VertexCover.hpp"
#include "TestTool.hpp"
#include <cstdlib>

using namespace std;

void TEST_CASE_ONE()
{
	std::vector<std::vector<int>> vertices(3);
	vertices[0].push_back(1);
	vertices[1].push_back(0);
	vertices[0].push_back(2);
	vertices[2].push_back(0);

	auto result = number_of_vertex_in_the_tree(vertices);
	cpstl::assert_equal("TEST_CASE_ONE", 1, result);
}

void TEST_CASE_TWO()
{
	std::vector<std::vector<int>> vertices(3);
	vertices[0].push_back(1);
	vertices[1].push_back(0);
	vertices[1].push_back(2);
	vertices[2].push_back(1);

	auto result = number_of_vertex_in_the_tree(vertices);
	cpstl::assert_equal("TEST_CASE_TWO", 1, result);
}

int main()
{
	TEST_CASE_ONE();
	TEST_CASE_TWO();
	return EXIT_SUCCESS;
}
