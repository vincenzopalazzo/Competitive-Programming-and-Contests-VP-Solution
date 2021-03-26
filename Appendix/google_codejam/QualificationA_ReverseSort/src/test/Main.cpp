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
#include "../core/ReverseSort.hpp"
#include <cstdlib>
#include "TestTool.hpp"

void TEST_CASE_ONE()
{
	std::vector<int> inputs = {4, 2, 1, 3};
	auto computation = revers_sort_computation(inputs);
  cpstl::cp_log(LOG, inputs);
	cpstl::assert_equal("TEST_CASE_ONE", 6, computation);
}

void TEST_CASE_TWO()
{
	std::vector<int> inputs = {7, 6, 5, 4, 3, 2, 1};
	auto computation = revers_sort_computation(inputs);
  cpstl::cp_log(LOG, inputs);
	cpstl::assert_equal("TEST_CASE_TWO", 12, computation);
}

void TEST_CASE_THREE()
{
	std::vector<int> inputs = {1, 2};
	auto computation = revers_sort_computation(inputs);
  cpstl::cp_log(LOG, inputs);
	cpstl::assert_equal("TEST_CASE_TWO", 1, computation);
}


int main()
{
	TEST_CASE_ONE();
  TEST_CASE_TWO();
  TEST_CASE_THREE();
	return EXIT_SUCCESS;
}
