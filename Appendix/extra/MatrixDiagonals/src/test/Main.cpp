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
#include "../core/Solution.hpp"
#include "TestTool.hpp"
#include <cstdlib>

using namespace std;

void TEST_CASE_ONE()
{
	std::vector<std::vector<int>> matrix{
	    {1, 3, 4, 10}, {2, 5, 9, 11}, {6, 8, 12, 15}, {7, 13, 14, 16}};
	cpstl::assert_is_true("TEST_CASE_ONE_MX_NOT_EMPITY", !matrix.empty());
	auto diagonals = zig_zag_walk(matrix);
	cpstl::assert_is_true("TEST_CASE_ONE_RES_NOT_EMPITY",
			      !diagonals.empty());
	cpstl::assert_equal(
	    "TEST_CASE_ONE_RES",
	    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16}, diagonals);
}

int main()
{
	TEST_CASE_ONE();
	return EXIT_SUCCESS;
}
